#include "Health/UHealthWidget.h"
#include "Health/HealthModel.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Internationalization/Text.h"
#include "Internationalization/TextFormatter.h"

void UUHealthWidget::Initialize(UHealthModel* InHealthModel)
{
    if (IsValid(InHealthModel))
    {
        HealthModel = InHealthModel;
        HealthModel->OnHealthChanged.AddDynamic(this, &UUHealthWidget::OnHealthChanged);
        OnHealthChanged();
    }
}

void UUHealthWidget::OnHealthChanged()
{
    if (!IsValid(HealthModel))
    {
        ensureAlwaysMsgf(false, TEXT("Health Model is not valid"));
        return;
    }

    const float HealthPercent = HealthModel->GetHealth() * 0.01f;
    if (IsValid(mHealthBar))
    {
        mHealthBar->SetPercent(HealthPercent);
    }

    if (IsValid(mHealthValueText))
    {
        FText HealthValue = FText::Format(
            FText::FromString(TextFormat),
            FText::AsNumber(HealthModel->GetHealth()),
            FText::AsNumber(HealthModel->GetMaxHealth())
        );

        mHealthValueText->SetText(HealthValue);
    }
}
