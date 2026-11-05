// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_try_ffd5d9229ca1a018.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
using namespace Ogre;
#include <map>
typedef std::map<const Light*, Vector4> LightPositionMap;
extern LightPositionMap* lightPositions;
bool forgetLightPosition(const Light* light)
{
    if (!lightPositions)
        return false;
    LightPositionMap::iterator it = lightPositions->find(light);
    if (it != lightPositions->end())
    {
        lightPositions->erase(it);
        return true;
    }
    return false;
}
