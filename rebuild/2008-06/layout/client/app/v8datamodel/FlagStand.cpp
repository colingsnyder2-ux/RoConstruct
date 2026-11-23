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

namespace RBX {
FlagStandService::~FlagStandService() {}
}

namespace RBX {
FlagStand* FlagStandService::FindStandWithFlag(Flag* f) {
 if (flagStands.empty()) return NULL;
 for (std::list<FlagStand*>::const_iterator iter=flagStands.begin();iter!=flagStands.end();iter++)
  if ((*iter)->GetFlag()==f) return *iter;
 return NULL;
}
}
