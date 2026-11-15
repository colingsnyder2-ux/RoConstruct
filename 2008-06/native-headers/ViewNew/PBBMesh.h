#pragma once
// 2008-06 native RBX::ViewNew::PBBBuilder / PBBMesh (inactive).
//   PBBBuilder  vtable 0082704c .?AVPBBBuilder@ViewNew@RBX@@ -> LevelBuilder (mdisp 0); slots 0 build 00500d30
//               (inherited), 1 buildTop 004f4790, 2 buildBottom 004f47f0, 3 buildLeft 004f4850, 4 buildRight 004f48b0,
//               5 buildFront 004f4910, 6 buildBack 004f4970. ctor 004f1eb0 out of line (ret 0x14: level&, Vector3 by
//               value, RenderSurfaceTypes): strips +0x20 / +0x22 / +0x24 (int16 each, zeroed first by the
//               Vector3int16 default ctor, then clamped to 1..4 of size / 6).
//   PBBMesh     vtable 00827070 -> RenderBase::Mesh, MeshFactory<PBBMesh, 4>; one slot (??_G 004e54c0).
//               ctors 004f49d0 (size, decal face), 004f4b20 (size, texture face, studsPerTile), 004f4cb0 (size,
//               surfaceTypes; also builds the shadow box 004e3570 when the shadows flag 0096de64 is set: body in
//               native-classes/ViewNewPartMesh2008PBB.cpp, pending the ViewBase::getShadowsEnabled() declaration).
#include "ViewNew/QuadVolume.h"
#include "ViewNew/MeshFactory.h"
#include <G3D/Vector3int16.h>

namespace RBX
{
	namespace ViewNew
	{
		class PBBBuilder : public LevelBuilder
		{
			friend struct ::NativeViewNewLayout;
		public:
			G3D::Vector3int16 strips;                             // +0x20
		public:
			PBBBuilder(G3D::ReferenceCountedPointer<RenderBase::Mesh::Level>& level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes); // 004f1eb0
		protected:
			virtual void buildTop(Purpose purpose);               // 004f4790
			virtual void buildBottom(Purpose purpose);            // 004f47f0
			virtual void buildLeft(Purpose purpose);              // 004f4850
			virtual void buildRight(Purpose purpose);             // 004f48b0
			virtual void buildFront(Purpose purpose);             // 004f4910
			virtual void buildBack(Purpose purpose);              // 004f4970
		};

		class PBBMesh : public RenderBase::Mesh, public MeshFactory<PBBMesh, 4>
		{
		public:
			PBBMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes);                       // 004f4cb0 (create 004edb20: new 0x8c, push surfaceTypes, push size)
			PBBMesh(const G3D::Vector3& size, NormalId decalFace);                                   // 004f49d0
			PBBMesh(const G3D::Vector3& size, NormalId textureFace, const G3D::Vector2& studsPerTile); // 004f4b20
		};
	}
}
