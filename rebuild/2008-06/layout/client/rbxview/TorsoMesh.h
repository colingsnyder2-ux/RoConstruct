// =============================================================================
// TorsoMesh.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rbxview/TorsoMesh.h
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
		class TorsoBuilder : public BevelMesh::Builder
		{
			friend struct ::NativeViewNewLayout;
		public:
			const float shoulderInset;                            // +0x24
		public:
			TorsoBuilder(G3D::ReferenceCountedPointer<RenderBase::Mesh::Level>& level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes, float bevel, float shoulderInset)
				: Builder(level, size, surfaceTypes, bevel),
				  shoulderInset(shoulderInset)
			{
			}
		protected:
			virtual void buildRight(Purpose purpose);             // 004fa050
			virtual void buildTop(Purpose purpose);               // 004fa090
			virtual void buildBack(Purpose purpose);              // 004fa0d0
			virtual void buildLeft(Purpose purpose);              // 004fa110
			virtual void buildBottom(Purpose purpose);            // 004faaf0
			virtual void buildFront(Purpose purpose);             // 004fa150
		};

		class TorsoMesh : public BevelMesh, public MeshFactory<TorsoMesh, 1>
		{
		public:
			TorsoMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes);                      // 004fa590
			TorsoMesh(const G3D::Vector3& size, NormalId decalFace);                                   // 004fa700
			TorsoMesh(const G3D::Vector3& size, NormalId textureFace, const G3D::Vector2& studsPerTile); // 004fa880
		};
	}
}
