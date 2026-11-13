#pragma once
// >>> native-status (generated) -- do not edit >>>
// CylinderMesh | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src aea632b4 | roc native-status --write
// 2008-06 native RBX::ViewNew::CylinderBuilder / CylinderAlongXMesh (inactive).
//   CylinderBuilder  vtable 00827164 .?AVCylinderBuilder@ViewNew@RBX@@ -> LevelBuilder (mdisp 0); slots 0 build 00500d30
//                    (inherited), 1 buildTop 004fd5c0, 2 buildBottom 004fd650, 3 buildLeft 004fd620, 4 buildRight 004fd590,
//                    5 buildFront 004fd680, 6 buildBack 004fd5f0. ctor 004fd430 out of line (ret 0x18): elements +0x20 =
//                    max(slices / 4, 1) (unsigned; shr 2 / jb); sizeof 0x24.
//   CylinderAlongXMesh  vtable 00827184 -> RenderBase::Mesh, MeshFactory<CylinderAlongXMesh, 1>; one slot (??_G 004e54c0).
//                    ctors 004fd6b0 (size, surfaceTypes), 004fd800 (size, decal face), 004fd960 (size, texture face,
//                    studsPerTile); each stores meshKind 3 and builds with 12 slices.
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
			CylinderBuilder(G3D::ReferenceCountedPointer<RenderBase::Mesh::Level>& level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes, size_t slices); // 004fd430
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
