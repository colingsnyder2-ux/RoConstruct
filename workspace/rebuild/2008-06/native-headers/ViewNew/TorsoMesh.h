#pragma once
// >>> native-status (generated) -- do not edit >>>
// TorsoMesh | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 568c47a7 | roc native-status --write
// 2008-06 native RBX::ViewNew::TorsoBuilder / TorsoMesh (inactive).
//   TorsoBuilder  vtable 00827100 .?AVTorsoBuilder@ViewNew@RBX@@ -> BevelMesh::Builder -> LevelBuilder (mdisp 0);
//                 slots 0 build 00501040 (BevelMesh::Builder), 1 buildTop 004fa090, 2 buildBottom 004faaf0,
//                 3 buildLeft 004fa110, 4 buildRight 004fa050, 5 buildFront 004fa150, 6 buildBack 004fa0d0.
//                 shoulderInset +0x24 (float; the face slots pass [this+0x20], [this+0x24]); sizeof 0x28 (the by-value
//                 copies in 004faaf0 / 004faa30: sub esp, 0x28; copy ctor 004f6e30, vtable 00827100, +0x24).
//   TorsoMesh     vtable 00827124 -> BevelMesh -> RenderBase::Mesh, MeshFactory<TorsoMesh, 1>; one slot (??_G 004e54c0).
//                 ctors 004fa590 (size, surfaceTypes; bevel 0), 004fa700 (size, decal face), 004fa880 (size, texture
//                 face, studsPerTile); shoulderInset = size.z * 0.3f, bevel 0.065f (unit constant 008270f8).
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
