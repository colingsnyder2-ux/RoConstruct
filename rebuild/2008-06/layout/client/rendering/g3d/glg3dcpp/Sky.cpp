// =============================================================================
// Sky.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/g3d/glg3dcpp/Sky.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/Sky.h"

namespace RBX
{
	char sSky[] = "Sky"; // 00955bd4 (classDescriptor 005eb290)

	// Template members the shared headers only declare (same definitions as Team.cpp / DecalBases.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	Reflection::BoundProp<TextureId, 1> Sky::prop_SkyUp("SkyboxUp", "Appearance", &Sky::skyUp, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<TextureId, 1> Sky::prop_SkyLf("SkyboxLf", "Appearance", &Sky::skyLf, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt("SkyboxRt", "Appearance", &Sky::skyRt, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<TextureId, 1> Sky::prop_SkyBk("SkyboxBk", "Appearance", &Sky::skyBk, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<TextureId, 1> Sky::prop_SkyFt("SkyboxFt", "Appearance", &Sky::skyFt, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<TextureId, 1> Sky::prop_SkyDn("SkyboxDn", "Appearance", &Sky::skyDn, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<int, 1> Sky::prop_StarCount("StarCount", "Appearance", &Sky::numStars, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<bool, 1> Sky::prop_CelestialBodiesShown(
		"CelestialBodiesShown",
		"Appearance",
		&Sky::drawCelestialBodies,
		Reflection::PropertyDescriptor::STANDARD);

#ifdef NATIVE_SKY_PENDING
	// Needs ContentId::fromAssets(const char*) (proposal for util/ContentProvider.h).
	Sky::Sky()
		: drawCelestialBodies(true),
		  numStars(3000)
	{
		setName("Sky");

		skyUp = ContentId::fromAssets("Sky\\null_plainsky512_up.jpg");
		skyLf = ContentId::fromAssets("Sky\\null_plainsky512_lf.jpg");
		skyRt = ContentId::fromAssets("Sky\\null_plainsky512_rt.jpg");
		skyBk = ContentId::fromAssets("Sky\\null_plainsky512_bk.jpg");
		skyFt = ContentId::fromAssets("Sky\\null_plainsky512_ft.jpg");
		skyDn = ContentId::fromAssets("Sky\\null_plainsky512_dn.jpg");
	}
#endif
}
