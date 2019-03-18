#include "Nocturne.h"
#include "Nocturne.Spells.h"	
#include "Nocturne.Modes.h"
#include "Nocturne.Menu.h"
#include "Manamanager.h"

using namespace Tryndamere;

void Modes::None()
{
	if (KillstealE)
		Spells::SpellEUse(OrbwalkingMode::None);
}

void Modes::Combo()
{
	if (UseQOnLowHealth)
		Spells::SpellQUse(OrbwalkingMode::Combo);

	if (UseWInCombo)
		Spells::SpellWUse(OrbwalkingMode::Combo);

	if (UseEInCombo)
		Spells::SpellEUse(OrbwalkingMode::Combo);

	if (UseROnLowHealth)
		Spells::SpellRUse(OrbwalkingMode::Combo);
}

void Modes::LastHit()
{
	Spells::SpellEUse(OrbwalkingMode::LastHit);

}

void Modes::Mixed()
{

	if (UseWInHarass)
		Spells::SpellWUse(OrbwalkingMode::Mixed);

	if (UseEInHarass)
		Spells::SpellEUse(OrbwalkingMode::Mixed);
}

void Modes::LaneClear() 
{
	if (UseQInLaneclear)
		Spells::SpellQUse(OrbwalkingMode::LaneClear);
	if  (UseEInLaneclear)
		Spells::SpellEUse(OrbwalkingMode::LaneClear);
}
//lul, you should take some C++ classes online or whatever :P . IEnjoy  its done im doing it in code academy xDD. good the code is done, im leaving :P /

void Modes::Flee()
{
	if (UseEInFlee)
		Spells::SpellEUse(OrbwalkingMode::Flee);
}

/*extern bool UseEInCombo;
extern bool UseQInLaneclear;
extern bool UseEInLaneclear;
*/