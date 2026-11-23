// =============================================================================
// WedgeMesh.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rbxview/WedgeMesh.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "ViewNew/BevelMesh.h"
#include "ViewNew/MeshFactory.h"

namespace RBX
{
	namespace ViewNew
	{
		class WedgeBuilder : public BevelMesh::Builder
		{
		public:
			WedgeBuilder(G3D::ReferenceCountedPointer<RenderBase::Mesh::Level>& level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes, float bevel)
				: Builder(level, size, surfaceTypes, bevel)
			{
			}
		protected:
			virtual void buildRight(Purpose purpose);             // 004f6e90
			virtual void buildTop(Purpose purpose);               // 004f6ee0
			virtual void buildBack(Purpose purpose);              // 004f7d30
			virtual void buildLeft(Purpose purpose);              // 004f6f20
			virtual void buildBottom(Purpose purpose);            // 004f7d60
			virtual void buildFront(Purpose purpose);             // 004f6f60
		};

		class WedgeMesh : public BevelMesh, public MeshFactory<WedgeMesh, 1>
		{
		public:
			WedgeMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes);                      // 004f7780
			WedgeMesh(const G3D::Vector3& size, NormalId decalFace);                                   // 004f78d0
			WedgeMesh(const G3D::Vector3& size, NormalId textureFace, const G3D::Vector2& studsPerTile); // 004f7a30
		};
	}
}
