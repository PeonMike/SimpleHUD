#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HealthModel.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthChanged);

UCLASS()
class SIMPLEHUD_API UHealthModel : public UObject
{
	GENERATED_BODY()

public:

    UHealthModel();

    UPROPERTY(BlueprintAssignable, Category = "Health")
    FOnHealthChanged OnHealthChanged;

    UFUNCTION(BlueprintCallable, Category = "Health")
    void SetHealth(float NewHealth);

    UFUNCTION(BlueprintCallable, Category = "Health")
    float GetHealth() const;

    UFUNCTION(BlueprintCallable, Category = "Health")
    float GetMinHealth() const;

    UFUNCTION(BlueprintCallable, Category = "Health")
    float GetMaxHealth() const;

private:
    UPROPERTY()
    float Health;

    UPROPERTY()
    float MinHealth = 0.0f;

    UPROPERTY()
    float MaxHealth = 100.0f;
};