#include "SHGameModeBase.h"
#include "Health/HealthModel.h"
#include "Health/HealthController.h"
#include "Health/UHealthWidget.h"
#include "Health/HealthTrigger.h"
#include "EngineUtils.h"

void ASHGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    UHealthModel* HealthModel = NewObject<UHealthModel>();
    UHealthController* HealthController = NewObject<UHealthController>();

    if (IsValid(HealthViewClass))
    {
        UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), HealthViewClass);
        if (Widget)
        {
            UUHealthWidget* HealthView = Cast<UUHealthWidget>(Widget);
            if (HealthView)
            {
                HealthView->Initialize(HealthModel);
                HealthView->AddToViewport();
            }
        }
    }

    for (TActorIterator<AHealthTrigger> It(GetWorld()); It; ++It)
    {
        AHealthTrigger* HealthTrigger = *It;
        if (HealthTrigger)
        {
            HealthTrigger->Initialize(HealthController, HealthModel);
        }
    }
}