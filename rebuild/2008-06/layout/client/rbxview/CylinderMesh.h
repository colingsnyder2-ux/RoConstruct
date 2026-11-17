#pragma once
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
