// =============================================================================
// CylinderMesh.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rbxview/CylinderMesh.h
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
		class CylinderBuilder : public LevelBuilder
		{
			friend struct ::NativeViewNewLayout;
		public:
			const size_t elements;                                // +0x20
		public:
			CylinderBuilder(
				G3D::ReferenceCountedPointer<RenderBase::Mesh::Level>& level,
				G3D::Vector3 size,
				RenderSurfaceTypes surfaceTypes,
				size_t slices); // 004fd430
		protected:
			virtual void buildRight(Purpose purpose);             // 004fd590
			virtual void buildTop(Purpose purpose);               // 004fd5c0
			virtual void buildBack(Purpose purpose);              // 004fd5f0
			virtual void buildLeft(Purpose purpose);              // 004fd620
			virtual void buildBottom(Purpose purpose);            // 004fd650
			virtual void buildFront(Purpose purpose);             // 004fd680
		};

		class CylinderAlongXMesh : public RenderBase::Mesh, public MeshFactory<CylinderAlongXMesh, 1>
		{
		public:
			CylinderAlongXMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes);                     // 004fd6b0
			CylinderAlongXMesh(const G3D::Vector3& size, NormalId decalFace);                                  // 004fd800
			CylinderAlongXMesh(const G3D::Vector3& size, NormalId textureFace, const G3D::Vector2& studsPerTile); // 004fd960
		};
	}
}
