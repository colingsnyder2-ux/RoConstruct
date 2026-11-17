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
