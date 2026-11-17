// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded /I{headers}/engine-world
#define NATIVE_HUMANOID2008_DONOR_CONNECTOR
#include "v8datamodel/PartInstance.h"
#include "humanoid/HumanoidState.h"
#include "humanoid/Humanoid2008.h"

namespace RBX {
namespace HUMAN {

// 00644670 (thiscall, ret 4): the 17 transition event ids. Case bodies are laid out in source order, not id order.
bool HumanoidState::canTransition(int event)
{
    switch (event)
    {
    case 0:  return humanoid->imDead;
    case 1:  return humanoid->getJump();
    case 4:  return humanoid->getSit();
    case 5:  return !humanoid->getSit();
    case 6:  return tipped();
    case 7:  return upright();
    case 8:  return floorFound;
    case 9:  return !floorFound;
    case 2:  return humanoid->getStrafe();
    case 3:  return !humanoid->getStrafe();
    case 11: return floorPart.get() != NULL;
    case 10: return floorPart.get() == NULL;
    case 12: return onFloorStep();
    case 13: return !onFloorStep();
    case 15: return value0c <= 0.0f;
    case 14: return flag11;
    case 16: return sub_00643eb0();
    default: return false;
    }
}

}
}
