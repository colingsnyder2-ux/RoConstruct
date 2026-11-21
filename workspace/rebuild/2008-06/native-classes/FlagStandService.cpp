#include "v8datamodel/FlagStandService.h"
#include "reflection/property.h"
namespace RBX {
FlagStandService::~FlagStandService() {}
}

#include "v8datamodel/FlagStand.h"
namespace RBX {
FlagStand* FlagStandService::FindStandWithFlag(Flag* f) {
 if (flagStands.empty()) return NULL;
 for (std::list<FlagStand*>::const_iterator iter=flagStands.begin();iter!=flagStands.end();iter++)
  if ((*iter)->GetFlag()==f) return *iter;
 return NULL;
}
}
