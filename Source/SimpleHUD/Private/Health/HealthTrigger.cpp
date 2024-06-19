#include "Health/HealthTrigger.h"
#include "SHGameModeBase.h"
#include "Components/BoxComponent.h"
#include "Health/HealthController.h"
#include "Health/HealthModel.h"


AHealthTrigger::AHealthTrigger()
{

    PrimaryActorTick.bCanEverTick = false;

    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    RootComponent = TriggerBox;

    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AHealthTrigger::OnOverlapBegin);
}

void AHealthTrigger::Initialize(UHealthController* InHealthController, UHealthModel* InHealthModel)
{
    HealthController = InHealthController;
    HealthModel = InHealthModel;
}

void AHealthTrigger::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, 
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (!IsValid(OtherActor) || OtherActor == this)
    {
        return;
    }

    if (!IsValid(HealthController) || !IsValid(HealthModel))
    {
        return;
    }

    HealthController->ChangeHealth(HealthModel, HealthChangeAmount);
}