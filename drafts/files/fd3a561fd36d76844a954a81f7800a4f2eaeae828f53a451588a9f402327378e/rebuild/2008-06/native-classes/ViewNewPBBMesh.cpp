// 2008-06 native RBX::ViewNew::PBBBuilder / PBBMesh (inactive): the unit 004f1eb0..004f4e3f.
// The per-face grid instances (004f2110..004f44b0) and the surface ctor 004f4cb0 are not recovered here.
#include "ViewNew/PBBMesh.h"
#include "ViewNew/BrickMesh.h"
#include <G3D/g3dmath.h>
#include <algorithm>

namespace RBX
{
	namespace ViewNew
	{
		class Face
		{
			G3D::Vector2 perturbation;
			bool bulge[2];
		public:
			Face()                                                // 004f2030
			{
				perturbation.x = G3D::uniformRandom(-BrickMesh::normalPerturbation, BrickMesh::normalPerturbation);
				perturbation.y = G3D::uniformRandom(-BrickMesh::normalPerturbation, BrickMesh::normalPerturbation);
				bulge[0] = G3D::uniformRandom() > 0.5f;
				bulge[1] = G3D::uniformRandom() > 0.5f;
			}
			void operator()(G3D::Vector3&, G3D::Vector3&, G3D::Vector2&, const G3D::Vector3&, const G3D::Vector2int16&);
		};

		class Side : public Face
		{
		public:
			void operator()(G3D::Vector3&, G3D::Vector3&, G3D::Vector2&, const G3D::Vector3&, const G3D::Vector2int16&);
		};

		PBBBuilder::PBBBuilder(G3D::ReferenceCountedPointer<RenderBase::Mesh::Level>& level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes)
			: LevelBuilder(level, size, surfaceTypes)
		{
			strips.x = std::max<int>(1, size.x / 6.0f);
			strips.y = std::max<int>(1, size.y / 6.0f);
			strips.z = std::max<int>(1, size.z / 6.0f);
			strips.x = std::min<int>(4, strips.x);
			strips.y = std::min<int>(4, strips.y);
			strips.z = std::min<int>(4, strips.z);
		}

		void PBBBuilder::buildTop(Purpose purpose)
		{
			Face deform;
			buildFace<NORM_Y>(deform, G3D::Vector2int16(1, 1), purpose);
		}

		void PBBBuilder::buildBottom(Purpose purpose)
		{
			Face deform;
			buildFace<NORM_Y_NEG>(deform, G3D::Vector2int16(1, 1), purpose);
		}

		void PBBBuilder::buildLeft(Purpose purpose)
		{
			Side deform;
			buildFace<NORM_X_NEG>(deform, G3D::Vector2int16(1, 1), purpose);
		}

		void PBBBuilder::buildRight(Purpose purpose)
		{
			Side deform;
			buildFace<NORM_X>(deform, G3D::Vector2int16(1, 1), purpose);
		}

		void PBBBuilder::buildFront(Purpose purpose)
		{
			Side deform;
			buildFace<NORM_Z_NEG>(deform, G3D::Vector2int16(1, 1), purpose);
		}

		void PBBBuilder::buildBack(Purpose purpose)
		{
			Side deform;
			buildFace<NORM_Z>(deform, G3D::Vector2int16(1, 1), purpose);
		}

		PBBMesh::PBBMesh(const G3D::Vector3& size, NormalId decalFace)
		{
			G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level = new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS);
			levels.push_back(level);

			PBBBuilder builder(level, size, RenderSurfaceTypes());
			builder.buildFace(decalFace, LevelBuilder::Decal);
		}

		PBBMesh::PBBMesh(const G3D::Vector3& size, NormalId textureFace, const G3D::Vector2& studsPerTile)
		{
			G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level = new RenderBase::Mesh::Level(G3D::RenderDevice::QUADS);
			levels.push_back(level);

			PBBBuilder builder(level, size, RenderSurfaceTypes());
			builder.textureScale = mapToUvw_Legacy(size, textureFace).xy() * 2.0f / studsPerTile;
			builder.buildFace(textureFace, LevelBuilder::Decal);
		}
	}
}
