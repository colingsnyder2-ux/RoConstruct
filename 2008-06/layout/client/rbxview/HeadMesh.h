// =============================================================================
// HeadMesh.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rbxview/HeadMesh.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "ViewNew/QuadVolume.h"
#include "ViewNew/MeshFactory.h"

namespace RBX
{
	namespace ViewNew
	{
		class HeadBuilder : public LevelBuilder
		{
			friend struct ::NativeViewNewLayout;
		public:
			const float bevel;                                    // +0x20
			const int elements;                                   // +0x24 (signed: the face slots compute (elements + 1) / 2 with cdq / sar)
		public:
			HeadBuilder(
				G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level,
				G3D::Vector3 size,
				RenderSurfaceTypes surfaceTypes,
				size_t elements,
				float bevel); // 004fdaf0
		protected:
			virtual void buildTop(Purpose purpose);               // 00500020
			virtual void buildBottom(Purpose purpose);            // 00500050
			virtual void buildLeft(Purpose purpose);              // 00500080
			virtual void buildRight(Purpose purpose);             // 005000c0
			virtual void buildFront(Purpose purpose);             // 00500100
			virtual void buildBack(Purpose purpose);              // 00500140
		};

		class HeadMesh : public RenderBase::Mesh, public MeshFactory<HeadMesh, 1>
		{
		public:
			HeadMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes);                      // 00500180
			HeadMesh(const G3D::Vector3& size, NormalId decalFace);                                   // 00500350
			HeadMesh(const G3D::Vector3& size, NormalId textureFace, const G3D::Vector2& studsPerTile); // 005004d0
		};
	}
}
