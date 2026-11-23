// =============================================================================
// Sky.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/Sky.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
