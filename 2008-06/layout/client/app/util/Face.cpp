#include "ViewNew/PBBMesh.h"
#include "ViewNew/QuadVolumeFace.h"
#include "ViewNew/BrickMesh.h"
#include <G3D/g3dmath.h>
#include <algorithm>

namespace RBX
{
	namespace ViewNew
	{
		class Face
		{
		protected:
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
			void operator()(G3D::Vector3& vertex, G3D::Vector3& normal, G3D::Vector2&, const G3D::Vector3& size, const G3D::Vector2int16&)
			{
				if (vertex.x > 0)
					vertex.x -= BrickMesh::bevel;
				else
					vertex.x += BrickMesh::bevel;
				if (vertex.y > 0)
					vertex.y -= BrickMesh::bevel;
				else
					vertex.y += BrickMesh::bevel;
				for (int i = 0; i < 2; ++i)
				{
					if (bulge[i])
						normal[i] = vertex[i] / size[i] * perturbation[i];
					else
						normal[i] = perturbation[i];
				}
			}
		};

		class Side : public Face
		{
		public:
			void operator()(G3D::Vector3& vertex, G3D::Vector3& normal, G3D::Vector2&, const G3D::Vector3& size, const G3D::Vector2int16&)
			{
				if (vertex.x > 0)
					vertex.x -= BrickMesh::bevel;
				else
					vertex.x += BrickMesh::bevel;
				vertex.z -= BrickMesh::bevel;
				for (int i = 0; i < 2; ++i)
				{
					if (bulge[i])
						normal[i] = vertex[i] / size[i] * perturbation[i];
					else
						normal[i] = perturbation[i];
				}
			}
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

#undef _RELEASEASSERT   // the 2008 Face bodies carry no release asserts (fuzzyContainsInExtrusion 00649830, cornersAligned 006498b0, getAxis)
#include "util/Face.h"
#include "util/Math.h"

namespace RBX
{
	const G3D::Vector3& Face::operator[](int i) const
	{
		return ((G3D::Vector3*)this)[i];
	}

	G3D::Vector3& Face::operator[](int i)
	{
		return ((G3D::Vector3*)this)[i];
	}

	void Face::snapToGrid(float grid)
	{
		for (int i = 0; i < 4; ++i)
		{
			G3D::Vector3& v = (*this)[i];
			v = Math::toGrid(v, grid);
		}
	}

	bool Face::overlapWithinPlanes(const Face& f0, const Face& f1, float tolerance)
	{
		for (int i = 0; i < 2; ++i)
		{
			const Face& face = i == 0 ? f0 : f1;
			const Face& otherFace = i == 0 ? f1 : f0;

			G3D::Plane p0(face.c0, face.c1, face.c3);

			G3D::Vector3 normal;
			float distance;
			p0.getEquation(normal, distance);

			Face overlapOn1 = otherFace.projectOverlapOnMe(face);

			for (int j = 0; j < 4; ++j)
			{
				if (fabs(overlapOn1[j].dot(normal) + distance) > tolerance)
					return false;
			}
		}

		return true;
	}

	bool Face::fuzzyContainsInExtrusion(const G3D::Vector3& point, float tolerance) const
	{
		RBXASSERT(tolerance >= 0.0);

		for (int i = 0; i < 4; ++i)
		{
			const G3D::Vector3& v1 = (*this)[i];
			const G3D::Vector3& v2 = (*this)[(i + 1) % 4];

			if ((v2 - v1).dot(point - v1) < -tolerance)
				return false;
		}

		return true;
	}

	void Face::minMax(const G3D::Vector3& point, const G3D::Vector3& normal, float& min, float& max) const
	{
		min = 1.0e10;
		max = -1.0e10;

		for (int i = 0; i < 4; ++i)
		{
			const G3D::Vector3& v = (*this)[i];
			float temp = (v - point).dot(normal);
			min = G3D::min(min, temp);
			max = G3D::max(max, temp);
		}
	}

	bool Face::hasOverlap(const Face& f0, const Face& f1, float byAtLeast)
	{
		for (int i = 0; i < 2; ++i)
		{
			G3D::Vector3 axis = f0.getAxis(i);

			float f0min, f0max, f1min, f1max;
			f0.minMax(f0.c0, axis, f0min, f0max);
			f1.minMax(f0.c0, axis, f1min, f1max);

			if (f1max - byAtLeast < f0min || f0max < f1min + byAtLeast)
				return false;
		}

		return true;
	}

	bool Face::cornersAligned(const Face& f0, const Face& f1, float tolerance)
	{
		RBXASSERT(tolerance > 0.0);

		float toleranceSquared = tolerance*tolerance;

		for (int i = 0; i < 4; ++i)
		{
			bool aligned = false;

			for (int j = 0; j < 4; ++j)
			{
				const G3D::Vector3& v1 = f0[i];
				const G3D::Vector3& v2 = f1[j];

				if ((v1 - v2).squaredMagnitude() < toleranceSquared)
				{
					aligned = true;
					break;
				}
			}

			if (!aligned)
				return false;
		}

		return true;
	}

	Face Face::projectOverlapOnMe(const Face& other) const
	{
		G3D::Vector3 normal = getU();
		G3D::Vector3 v2 = getV();

		float minL[2];
		float maxL[2];
		for (int i = 0; i < 2; ++i)
		{
			float f0min, f0max;
			this->minMax(this->c0, normal, f0min, f0max);

			float f1min, f1max;
			other.minMax(this->c0, normal, f1min, f1max);

			minL[i] = G3D::min(f0min, f1min);
			maxL[i] = G3D::max(f0max, f1max);
		}

		return Face(
			(normal * minL[1]) + (v2 * minL[1]) + this->c0,
			(normal * minL[1]) + (v2 * minL[0]) + this->c0,
			(normal * maxL[1]) + (v2 * minL[0]) + this->c0,
			(normal * maxL[1]) + (v2 * minL[1]) + this->c0);
	}

	Face Face::fromExtentsSide(const Extents& e, NormalId faceId)
	{
		Face face;
		e.getFaceCorners(faceId, face.c0, face.c1, face.c2, face.c3);
		return face;
	}

	Face Face::toWorldSpace(const G3D::CoordinateFrame& objectCoord) const
	{
		Face face;
		for (int i = 0; i < 4; ++i)
		{
			face[i] = objectCoord.pointToWorldSpace((*this)[i]);
		}
		return face;
	}

	Face Face::toObjectSpace(const G3D::CoordinateFrame& objectCoord) const
	{
		Face face;
		for (int i = 0; i < 4; ++i)
		{
			face[i] = objectCoord.pointToObjectSpace((*this)[i]);
		}
		return face;
	}
}

namespace RBX
{

}
