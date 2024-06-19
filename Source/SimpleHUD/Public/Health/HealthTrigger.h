#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthTrigger.generated.h"

UCLASS()
class SIMPLEHUD_API AHealthTrigger : public AActor
{
	GENERATED_BODY()

public:

    AHealthTrigger();

    UPROPERTY(EditAnywhere, Category = "Components")
    class UBoxComponent* TriggerBox;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    float HealthChangeAmount = 0.0f;

    void Initialize(class UHealthController* InHealthController, class UHealthModel* InHealthModel);

private:
    UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UPROPERTY()
    UHealthController* HealthController = nullptr;

    UPROPERTY()
    UHealthModel* HealthModel = nullptr;
};
