#pragma once
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
