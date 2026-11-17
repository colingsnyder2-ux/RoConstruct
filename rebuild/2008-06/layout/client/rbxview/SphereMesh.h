#pragma once
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
