#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UHealthWidget.generated.h"


UCLASS()
class SIMPLEHUD_API UUHealthWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Health")
    void Initialize(class UHealthModel* InHealthModel);


protected:
    UPROPERTY(meta = (BindWidget))
    class UProgressBar* mHealthBar;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* mHealthValueText;

    UPROPERTY(EditAnywhere)
    FString TextFormat = TEXT("{0}/{1}");

private:
    UFUNCTION()
    void OnHealthChanged();

    UPROPERTY()
    class UHealthModel* HealthModel;
};