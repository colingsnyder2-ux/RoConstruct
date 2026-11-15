#pragma once
// 2008-06 native RBX::ViewNew::SphereBuilder / SphereMesh (inactive).
//   SphereBuilder  vtable 00827134 .?AVSphereBuilder@ViewNew@RBX@@ -> LevelBuilder (mdisp 0); slots 0 build 00500d30
//                  (inherited), 1 buildTop 004fcec0, 2 buildBottom 004fcf50, 3 buildLeft 004fcf20, 4 buildRight 004fce90,
//                  5 buildFront 004fcf80, 6 buildBack 004fcef0. elements +0x20 (int; 6 in every SphereMesh ctor);
//                  sizeof 0x24; header-inline ctor (00500d80 then vtable 00827134, +0x20).
//   SphereMesh     vtable 00827154 .?AVSphereMesh@ViewNew@RBX@@ -> RenderBase::Mesh, MeshFactory<SphereMesh, 1>;
//                  one slot (??_G 004e54c0, shared by every ViewNew mesh). ctors 004fcfb0 (diameter, surfaceTypes;
//                  meshKind 2), 004fd110 (size, decal face), 004fd270 (size, texture face, studsPerTile).
#include "ViewNew/QuadVolume.h"
#include "ViewNew/MeshFactory.h"

namespace RBX
{
	namespace ViewNew
	{
		class SphereBuilder : public LevelBuilder
		{
			friend struct ::NativeViewNewLayout;
		public:
			const int elements;                                   // +0x20
		public:
			SphereBuilder(G3D::ReferenceCountedPointer<RenderBase::Mesh::Level>& level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes, int elements)
				: LevelBuilder(level, size, surfaceTypes),
				  elements(elements)
			{
			}
		protected:
			virtual void buildRight(Purpose purpose);             // 004fce90
			virtual void buildTop(Purpose purpose);               // 004fcec0
			virtual void buildBack(Purpose purpose);              // 004fcef0
			virtual void buildLeft(Purpose purpose);              // 004fcf20
			virtual void buildBottom(Purpose purpose);            // 004fcf50
			virtual void buildFront(Purpose purpose);             // 004fcf80
		};

		class SphereMesh : public RenderBase::Mesh, public MeshFactory<SphereMesh, 1>
		{
		public:
			SphereMesh(const G3D::Vector3& diameter, RenderSurfaceTypes surfaceTypes);                       // 004fcfb0
			SphereMesh(const G3D::Vector3& size, NormalId decalFace);                                        // 004fd110
			SphereMesh(const G3D::Vector3& size, NormalId textureFace, const G3D::Vector2& studsPerTile);    // 004fd270
		};
	}
}
