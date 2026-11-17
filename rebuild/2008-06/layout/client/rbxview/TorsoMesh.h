#pragma once
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
