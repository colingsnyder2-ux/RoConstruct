#pragma once
// >>> native-status (generated) -- do not edit >>>
// HeadMesh | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src e75efeea | roc native-status --write
// 2008-06 native RBX::ViewNew::HeadBuilder / HeadMesh (inactive).
//   HeadBuilder  vtable 00827194 .?AVHeadBuilder@ViewNew@RBX@@ -> LevelBuilder (mdisp 0); slots 0 build 00500d30
//                (inherited), 1 buildTop 00500020, 2 buildBottom 00500050 (EndcapTransform), 3 buildLeft 00500080,
//                4 buildRight 005000c0, 5 buildFront 00500100, 6 buildBack 00500140 (CylinderTransform).
//                ctor 004fdaf0 out of line (ret 0x1c; level by value): LevelBuilder(level, Vector3(min(x, z), y,
//                min(x, z)), surfaceTypes), bevel +0x20 (float), elements +0x24; sizeof 0x28.
//   EndcapTransform  { const float bevel; } operator() 004fdcc0 (thiscall, ret 0x14).
//   CylinderTransform { const float bevel; const int halfVertexCount; } operator() 004fdbd0; the face slots pass
//                (elements + 1) / 2.
//   HeadMesh     vtable 008271b8 -> RenderBase::Mesh, MeshFactory<HeadMesh, 1>; one slot (??_G 004e54c0). ctors 00500180
//                (size, surfaceTypes), 00500350 (decal face), 005004d0 (texture face, studsPerTile): bevel =
//                min(size.x, size.z) * 0.25f (0083a3e4), 9 elements.
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
			HeadBuilder(G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes, size_t elements, float bevel); // 004fdaf0
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
