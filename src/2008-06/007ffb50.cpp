// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Sky.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Sky.h"

#include "util/ContentProvider.h"

namespace RBX {

char sSky[] = "Sky";

using namespace Reflection;

BoundProp<TextureId, 1> Sky::prop_SkyUp("SkyboxUp", "Appearance", &RBX::Sky::skyUp);

BoundProp<TextureId, 1> Sky::prop_SkyLf("SkyboxLf", "Appearance", &RBX::Sky::skyLf);

BoundProp<TextureId, 1> Sky::prop_SkyRt("SkyboxRt", "Appearance", &RBX::Sky::skyRt);

BoundProp<TextureId, 1> Sky::prop_SkyBk("SkyboxBk", "Appearance", &RBX::Sky::skyBk);

BoundProp<TextureId, 1> Sky::prop_SkyFt("SkyboxFt", "Appearance", &RBX::Sky::skyFt);

BoundProp<TextureId, 1> Sky::prop_SkyDn("SkyboxDn", "Appearance", &RBX::Sky::skyDn);

BoundProp<bool, 1> Sky::prop_CelestialBodiesShown("CelestialBodiesShown", "Appearance", &RBX::Sky::drawCelestialBodies);

BoundProp<int, 1> Sky::prop_StarCount("StarCount", "Appearance", &RBX::Sky::numStars);

// STUB: WEBSERVICE 0x10094700
G3D::SkyRef Sky::getG3DSky(Sky* sky)
{
	STUB(0x10094700);
	return G3D::SkyRef();
}

// FUNCTION: WEBSERVICE 0x10095110
Sky::Sky() : drawCelestialBodies(true), numStars(3000)
{
	setName("Sky");

	skyUp = ContentId::fromAssets("Sky\\null_plainsky512_up.jpg");
	skyLf = ContentId::fromAssets("Sky\\null_plainsky512_lf.jpg");
	skyRt = ContentId::fromAssets("Sky\\null_plainsky512_rt.jpg");
	skyBk = ContentId::fromAssets("Sky\\null_plainsky512_bk.jpg");
	skyFt = ContentId::fromAssets("Sky\\null_plainsky512_ft.jpg");
	skyDn = ContentId::fromAssets("Sky\\null_plainsky512_dn.jpg");
}

} // namespace RBX
