#pragma once
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
