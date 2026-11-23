// =============================================================================
// FlagStand.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/FlagStand.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/FlagStandService.h"
#include "v8datamodel/FlagStand.h"
#include "v8datamodel/Flag.h"
#include <vector>
#include <stdlib.h>

namespace RBX
{
	FlagStand* FlagStandService::FindClosestEmptyStandForFlag(Flag* f)
	{
		if (flagStands.empty())
			return NULL;

		std::vector<FlagStand*> possibleLocations;

		for (std::list<FlagStand*>::const_iterator iter = flagStands.begin(); iter != flagStands.end(); ++iter)
		{
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

#include "reflection/property.h"

namespace RBX
{
FlagStandService::~FlagStandService() {}
}

namespace RBX
{
FlagStand* FlagStandService::FindStandWithFlag(Flag* f) {
 if (flagStands.empty()) return NULL;
 for (std::list<FlagStand*>::const_iterator iter=flagStands.begin();iter!=flagStands.end();iter++)
  if ((*iter)->GetFlag()==f) return *iter;
 return NULL;
}
}
