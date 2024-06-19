#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SHGameModeBase.generated.h"


UCLASS()
class SIMPLEHUD_API ASHGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
    virtual void BeginPlay() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
    TSubclassOf<class UUserWidget> HealthViewClass;
};
