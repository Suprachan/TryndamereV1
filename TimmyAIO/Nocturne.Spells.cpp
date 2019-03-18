#include "Nocturne.h"
#include "Nocturne.Spells.h"
#include "Nocturne.Menu.h"
#include "../../rift-sdk-extensions/Include/GameObjects.hpp"
#include "../../rift-sdk-extensions/Include/Geometry.hpp"

using namespace Tryndamere;

void Spells::SpellQUse(const OrbwalkingMode mode)
{
	if (::Menu::Get<bool>("UseQOnLowHealth") && TryndamereQ.IsReady())
	{
		auto target = pCore->TS->GetTarget();
		auto percentHealth = (Player.GetHealth().Current / target->GetHealth().Max) * 100;
		if (percentHealth < ::Menu::Get<float>("Menu.HealthQ"))
		{
			TryndamereQ.Cast();
		}
	}
}
//where is your menu ?
void Spells::SpellWUse(const OrbwalkingMode mode)
{
	if (mode == OrbwalkingMode::Combo && UseWInCombo)
	{
		if (TryndanmereW.IsReady() && !pSDK->EntityManager->GetEnemyHeroes(850.f).empty() && !pSDK->BuffManager->HasBuff(Player.NetworkID, "UseWInComb"))
		{
			TryndanmereW.Cast();
		}
	}
}

void Spells::SpellEUse(const OrbwalkingMode mode)
{
	if (mode == OrbwalkingMode::None)
	{
		if (TryndamereE.IsReady())
		{
			auto enemies = pSDK->EntityManager->GetEnemyHeroes(1050.f);
			for (auto &[netID, enemy] : enemies)
			{
				if (enemy != nullptr)
				{
					if (KillstealE && pCore->TS->IsValidTarget(enemy) && Player.Distance(enemy) > Player.GetTrueAttackRange(enemy))
					{
						auto enemyHealth = enemy->GetHealth().Current + enemy->GetHealth().PhysicalShield + 10.f;
						enemyHealth -= Tryndamere::SpinningSlash(enemy);

						if (enemyHealth <= 0.f)
						{
							auto pred{ enemy ? TryndamereE.GetPrediction(enemy) : nullptr };
							if (pred && pred->Hitchance >= HitChance(TryndamereEPredHitchance + 2) && pred->CastPosition.IsValid())
							{
								TryndamereE.Cast(&pred->CastPosition);
								break;
							}
						}
					}
				}
			}
		}
	}

	else if (mode == OrbwalkingMode::Combo)
	{
		if (TryndamereE.IsReady())
		{
			const auto target = pCore->TS->GetTarget(660.f);

			if (target != nullptr)
					{
						if (UseEOnOutOfRange && Player.Distance(target) > Player.GetTrueAttackRange(target))
						{
							auto pred{ target ? TryndamereE.GetPrediction(target) : nullptr };
							if (pred && pred->Hitchance >= HitChance(TryndamereEPredHitchance + 2) && pred->CastPosition.IsValid())
							{
								TryndamereE.Cast(&pred->CastPosition);
							}
						}
					}
				
			
		}
	}
}


void Spells::SpellRUse(const OrbwalkingMode mode)
{
	if (::Menu::Get<bool>("ComboR") && TryndamereR.IsReady())
	{
		if (!TryndamereQ.IsReady() && Player.GetHealthPercent() <= ::Menu::Get<float>("Menu.HealthR"))
		{
			TryndamereR.Cast();
		}
	}
}
