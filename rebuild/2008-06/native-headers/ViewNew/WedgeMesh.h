#pragma once
// >>> native-status (generated) -- do not edit >>>
// WedgeMesh | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 0a181395 | roc native-status --write
// 2008-06 native RBX::ViewNew::WedgeBuilder / WedgeMesh (inactive).
//   WedgeBuilder  vtable 008270a8 .?AVWedgeBuilder@ViewNew@RBX@@ -> BevelMesh::Builder -> LevelBuilder (mdisp 0);
//                 slots 0 build 00501040 (BevelMesh::Builder), 1 buildTop 004f6ee0, 2 buildBottom 004f7d60,
//                 3 buildLeft 004f6f20, 4 buildRight 004f6e90, 5 buildFront 004f6f60, 6 buildBack 004f7d30.
//                 No fields of its own: the by-value copies in 004f7bd0 / 004f7c80 are 0x24 bytes (sub esp, 0x24;
//                 BevelMesh::Builder copy ctor 004f6e30, then vtable 008270a8). Header-inline ctor (WedgeMesh
//                 ctors: LevelBuilder ctor 00500d80, vtable 008270a8, bevel +0x20).
//   WedgeMesh     vtable 008270e8 -> BevelMesh -> RenderBase::Mesh, MeshFactory<WedgeMesh, 1>; one slot (??_G 004e54c0).
//                 ctors 004f7780 (size, surfaceTypes; bevel 0), 004f78d0 (size, decal face), 004f7a30 (size, texture
//                 face, studsPerTile); the last two use the unit constant bevel 0.065f (00827080). No meshKind store.
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
