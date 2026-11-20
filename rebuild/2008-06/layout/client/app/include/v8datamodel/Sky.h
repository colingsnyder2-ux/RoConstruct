#pragma once
#include "v8tree/Instance.h"
#include "util/TextureId.h"
#include <G3D/ReferenceCount.h>

namespace G3D
{
	class Sky;
}

namespace RBX
{
	extern char sSky[];   // INFERRED: ??__E?creator@?$FactoryProduct@...$1?sSky@...@3PADA (2008 binary) = char array

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

		static G3D::ReferenceCountedPointer<G3D::Sky> getG3DSky(Sky* sky);
	};
}
