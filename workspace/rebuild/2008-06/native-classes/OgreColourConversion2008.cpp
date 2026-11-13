// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#undef OGRE_NONCLIENT_BUILD
#include <OgreColourValue.h>
#include <G3D/Color4.h>
namespace Ogre {
// INFERRED name: 2007 donor converts G3D colour for Ogre callers.
ColourValue toColourValue(const G3D::Color4& colour) { return ColourValue(colour.r, colour.g, colour.b, colour.a); }
}
