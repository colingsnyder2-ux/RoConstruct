// 2008-06 native RBX::ViewNew::SphereBuilder / SphereMesh (inactive): the unit 004fce90..004fd40f.
#include "ViewNew/SphereMesh.h"

namespace RBX
{
	namespace ViewNew
	{
		// 004fabb0 (the body the linker keeps is the identical TorsoMesh copy)
		static void SphereTransform(G3D::Vector3& vertex, G3D::Vector3& normal, G3D::Vector2& tex, const G3D::Vector3& radius, const G3D::Vector2int16& ivertex)
		{
			G3D::Vector3 newNormal = vertex.direction();
			normal = newNormal;
			vertex = newNormal * radius;
		}

		void SphereBuilder::buildRight(Purpose purpose)
		{
			int e = elements;
			buildFace<NORM_X>(&SphereTransform, G3D::Vector2int16(e, e), purpose);
		}

		void SphereBuilder::buildTop(Purpose purpose)
		{
			int e = elements;
			buildFace<NORM_Y>(&SphereTransform, G3D::Vector2int16(e, e), purpose);
		}

		void SphereBuilder::buildBack(Purpose purpose)
		{
			int e = elements;
			buildFace<NORM_Z>(&SphereTransform, G3D::Vector2int16(e, e), purpose);
		}

		void SphereBuilder::buildLeft(Purpose purpose)
		{
			int e = elements;
			buildFace<NORM_X_NEG>(&SphereTransform, G3D::Vector2int16(e, e), purpose);
		}

		void SphereBuilder::buildBottom(Purpose purpose)
		{
			int e = elements;
			buildFace<NORM_Y_NEG>(&SphereTransform, G3D::Vector2int16(e, e), purpose);
		}

		void SphereBuilder::buildFront(Purpose purpose)
		{
			int e = elements;
			buildFace<NORM_Z_NEG>(&SphereTransform, G3D::Vector2int16(e, e), purpose);
		}

		SphereMesh::SphereMesh(const G3D::Vector3& diameter, RenderSurfaceTypes surfaceTypes)
		{
			meshKind = 2;
			levels.push_back(new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS));

			SphereBuilder builder(levels.last(), diameter, surfaceTypes, 6);
			builder.build(LevelBuilder::Surface);
		}

		SphereMesh::SphereMesh(const G3D::Vector3& size, NormalId decalFace)
		{
			G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level = new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS);
			levels.push_back(level);

			SphereBuilder builder(level, size, RenderSurfaceTypes(), 6);
			builder.buildFace(decalFace, LevelBuilder::Decal);
		}

		SphereMesh::SphereMesh(const G3D::Vector3& size, NormalId textureFace, const G3D::Vector2& studsPerTile)
		{
			G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level = new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS);
			levels.push_back(level);

			SphereBuilder builder(level, size, RenderSurfaceTypes(), 6);
			builder.textureScale = mapToUvw_Legacy(size, textureFace).xy() * 2.0f / studsPerTile;

			builder.buildFace(textureFace, LevelBuilder::Decal);
		}
	}
}
