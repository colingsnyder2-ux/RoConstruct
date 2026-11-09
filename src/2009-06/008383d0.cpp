// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_try_5230e5fcf10842ad.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
using namespace Ogre;
#include <map>
typedef std::map<const Light*, Vector4> LightPositionMap;
void cacheLightPosition(LightPositionMap& positions, const Light* light, const Vector4& position)
{
    positions[light] = position;
}
