// native-flags: /O2 /GS- /EHsc /MD /I{headers}/materialfactory-surfaces /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 2008-06 native RBX::ViewNew::MaterialFactory::getSurfacesTexture 004f0a20 (inactive), a row of the original
// MaterialFactory unit (ctor 004f0920 .. getMaterial 004f1c60). Identity: its only caller getMaterial 004f1c60
// passes the BrickColor::color3 005b6270 result by value (three fstp into `sub esp, 0xc`) with a hidden result and
// this = the factory; the body loads +0x4 (surfacesTexture, filled by the ctor from createPartTexture
// "textures\surfaces.png") and calls TextureProxyBase slot 7 shade(color, TextureProxyBaseRef()) into the result,
// then releases the null temporary. Donor: tools/openrbx Client/RbxView/MaterialFactory.cpp getSurfacesTexture.
// Flags from ViewRbxGfxConstructor2008.cpp (the MaterialFactory ctor 004f0920 unit); layout from the materialfactory-surfaces profile header.
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
#include "ViewNew/MaterialFactory2008.h"

namespace RBX { namespace ViewNew {
// 004f0a20. INFERRED: a named null base reference (the donor passes a temporary); with the temporary the load of
// +0x4 is scheduled before the EH-state store, the named local gives the original order.
G3D::ReferenceCountedPointer<TextureProxyBase> MaterialFactory::getSurfacesTexture(G3D::Color3 tint)
{
	TextureProxyBaseRef base;
	return surfacesTexture->shade(tint, base);
}
} }
