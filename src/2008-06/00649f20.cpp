// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_face_project_family_daa8904a9d319c98.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
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
			double distance;
			p0.getEquation(normal, distance);

			Face overlapOn1 = otherFace.projectOverlapOnMe(face);

			for (int j = 0; j < 4; ++j)
			{
				if (overlapOn1[j].dot(normal) > tolerance)
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

			float f0min, f0max;
			f0.minMax(f0.c0, axis, f0min, f0max);

			float f1min, f1max;
			f1.minMax(f0.c0, axis, f1min, f1max);

			if ((f0min - byAtLeast) < f1min || (f0max + byAtLeast) > f1max)
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
		const Face& f0 = (*this);
		const Face& f1 = other;

		//RBXASSERT(Face::hasOverlap(f0, f1, 1e-6f));
		G3D::Vector3 normal[2];
		float minL[2];
		float maxL[2];

		normal[0] = f0.getU();
		normal[1] = f0.getV();
		for (int i = 0; i < 2; ++i) {
			float f0min, f0max, f1min, f1max;
			f0.minMax(f0.c0, normal[i], f0min, f0max);
			f1.minMax(f0.c0, normal[i], f1min, f1max);
			minL[i] = std::max(f0min, f1min);
			maxL[i] = std::min(f0max, f1max);
		}
		return Face(	f0.c0 + (normal[0] * minL[0] + normal[1] * minL[1]),
						f0.c0 + (normal[0] * minL[0] + normal[1] * maxL[1]),
						f0.c0 + (normal[0] * maxL[0] + normal[1] * maxL[1]),
						f0.c0 + (normal[0] * maxL[0] + normal[1] * minL[1])		);
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
