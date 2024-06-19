#include "Health/HealthController.h"
#include "Health/HealthModel.h"


UHealthController::UHealthController()
{
}

void UHealthController::ChangeHealth(UHealthModel* HealthModel, float Amount)
{
    if (IsValid(HealthModel))
    {
        const float NewHealth = HealthModel->GetHealth() + Amount;
        const float ClamptHealth = FMath::Clamp(NewHealth, HealthModel->GetMinHealth() , HealthModel->GetMaxHealth());
        HealthModel->SetHealth(ClamptHealth);
    }
}