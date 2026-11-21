// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// 2008-06 native RBX::FlagStandService::FindClosestEmptyStandForFlag 0062c2e0 (inactive), a row of the original
// FlagStand/FlagStandService unit (0062b8f0..0062cf40). FlagStand.cpp / FlagStandService.cpp belong to other
// contributors, so this row lives in its own unit (flags from native-classes/FlagStand.cpp).
// Identity: Flag::onServiceProvider 006194a0 calls 0062c2e0 on the FlagStandService after FindStandWithFlag 0062bfc0
// (see native-classes/FlagClone.cpp) and AffixFlag 0062bdc0s its result; it sits between FindStandWithFlag 0062bfc0
// and the FlagStand constructor 0062c9c0. Shape after the donor tools/openrbx v8datamodel/FlagStand.cpp
// FindClosestEmptyStandForFlag (list walk into a vector, rand() % size).
#include "v8datamodel/FlagStandService.h"
#include "v8datamodel/FlagStand.h"
#include "v8datamodel/Flag.h"
#include <vector>
#include <stdlib.h>

namespace RBX
{
	// 0062c2e0: flagStands +0x144 (list head), checked list iterators (_invalid_parameter_noinfo); per stand the
	// inline FlagStand teamColor +0x3fc against Flag::getTeamColor 00618380 and FlagStand::GetFlag 0062b900, then
	// vector<FlagStand*>::push_back 004213a0; rand() % size picks the result.
	FlagStand* FlagStandService::FindClosestEmptyStandForFlag(Flag* f)
	{
		if (flagStands.empty())
			return NULL;

		std::vector<FlagStand*> possibleLocations;

		for (std::list<FlagStand*>::const_iterator iter = flagStands.begin(); iter != flagStands.end(); ++iter)
		{
			// The original unit inlines FlagStand::getTeamColor 0062b8f0 (a by-value copy of +0x3fc read before the
			// Flag::getTeamColor call); this unit copies the field the same way.
			BrickColor standColor = (*iter)->teamColor;
			if (standColor == f->getTeamColor() && !(*iter)->GetFlag())
				possibleLocations.push_back(*iter);
		}

		if (possibleLocations.size() == 0)
			return NULL;

		int index = rand() % possibleLocations.size();

		return possibleLocations[index];
	}
}
