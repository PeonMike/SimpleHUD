#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HealthController.generated.h"

UCLASS()
class SIMPLEHUD_API UHealthController : public UObject
{
	GENERATED_BODY()
public:
    UHealthController();

    UFUNCTION(BlueprintCallable, Category = "Health")
    void ChangeHealth(class UHealthModel* HealthModel, float Amount);
};