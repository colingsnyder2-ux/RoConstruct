#pragma once
// >>> native-status (generated) -- do not edit >>>
// Sky | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 24bc8105 | roc native-status --write
// 2008-06 native RBX::Sky (inactive). Shape after the donor tools/rbxgs Sky.h; every field, virtual and
// descriptor below is read from the 2008-06 binary:
//   RTTI       vtable 0083fc0c .?AVSky@RBX@@ -> DescribedCreatable<Sky, Instance, sSky> (21 bases, no other
//              base; name mangled $1?sSky@2@3PADA, a char array in .data at 00955bd4).
//   size       0x1f8: Creatable<Instance>::create<Sky> 004d8c90 allocates 0x1f8. Constructor 005eb640 builds six
//              TextureIds (std::string + mime Name*, 0x20 each) at +0x130/+0x150/+0x170/+0x190/+0x1b0/+0x1d0,
//              stores +0x1f0 (bool 1) and +0x1f4 (int 3000), then setName("Sky") and assigns the six
//              ContentId::fromAssets defaults; destructor 005ebae0 destroys the six strings in reverse.
//   vtable     no Instance virtual is overridden (askAddChild/askSetParent stay 0068e880).
//   descriptors (dynamic initializers 007f6e80..007f6fd0, all "Appearance" 008329ac, STANDARD):
//              prop_SkyUp 0097adac (+0x130), prop_SkyLf 0097ad3c (+0x150), prop_SkyRt 0097adc8 (+0x170),
//              prop_SkyBk 0097ad58 (+0x190), prop_SkyFt 0097ade4 (+0x1b0), prop_SkyDn 0097ad90 (+0x1d0),
//              prop_StarCount 0097ad74 (BoundProp<int>, +0x1f4), prop_CelestialBodiesShown 0097ad20
//              (BoundProp<bool>, +0x1f0).
#include "v8tree/Instance.h"
#include "util/TextureId.h"

namespace RBX
{
	extern const char sSky[];

	class Sky : public DescribedCreatable<Sky, Instance, sSky>
	{
	public:
		TextureId skyUp;               // +0x130
		TextureId skyLf;               // +0x150
		TextureId skyRt;               // +0x170
		TextureId skyBk;               // +0x190
		TextureId skyFt;               // +0x1b0
		TextureId skyDn;               // +0x1d0
		bool drawCelestialBodies;      // +0x1f0
		int numStars;                  // +0x1f4

	public:
		static Reflection::BoundProp<int, 1> prop_StarCount;
		static Reflection::BoundProp<TextureId, 1> prop_SkyUp;
		static Reflection::BoundProp<TextureId, 1> prop_SkyLf;
		static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
		static Reflection::BoundProp<TextureId, 1> prop_SkyBk;
		static Reflection::BoundProp<TextureId, 1> prop_SkyFt;
		static Reflection::BoundProp<TextureId, 1> prop_SkyDn;
		static Reflection::BoundProp<bool, 1> prop_CelestialBodiesShown;

	public:
		Sky();                         // 005eb640 (destructor 005ebae0, deleting 005ebb90)
	};
}
