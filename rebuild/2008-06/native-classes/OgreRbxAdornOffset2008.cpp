// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#undef OGRE_NONCLIENT_BUILD
#include "OgreRbx/RbxAdornState2008.h"
namespace Ogre {
// INFERRED name: original writes the quadric offset at +0x20.
void RbxAdornState::setOffset(const Vector3& value) { offset = value; }
}
