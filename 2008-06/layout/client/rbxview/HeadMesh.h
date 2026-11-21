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
