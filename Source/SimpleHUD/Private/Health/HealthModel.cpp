#include "Health/HealthModel.h"


UHealthModel::UHealthModel()
{
    Health = MaxHealth;
}

void UHealthModel::SetHealth(float NewHealth)
{
    if(FMath::Abs(Health - NewHealth) >= FLT_EPSILON)
    {
        Health = NewHealth;
        OnHealthChanged.Broadcast();
    }
}

float UHealthModel::GetHealth() const
{
    return Health;
}

float UHealthModel::GetMinHealth() const
{
    return MinHealth;
}

float UHealthModel::GetMaxHealth() const
{
    return MaxHealth;
}
