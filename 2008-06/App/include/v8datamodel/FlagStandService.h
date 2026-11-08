#pragma once
// >>> native-status (generated) -- do not edit >>>
// FlagStandService | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src c04f93d8 | roc native-status --write
#include <list>
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
namespace RBX {
class Flag; class FlagStand;
extern const char sFlagStandService[];
class FlagStandService : public DescribedCreatable<FlagStandService, Instance, sFlagStandService>, public Service {
private:
 std::list<FlagStand*> flagStands;
public:
 FlagStandService();
 virtual ~FlagStandService();
 FlagStand* FindClosestEmptyStandForFlag(Flag*);
 FlagStand* FindStandWithFlag(Flag*);
 void RegisterFlagStand(FlagStand*);
 void UnregisterFlagStand(FlagStand*);
};
}
