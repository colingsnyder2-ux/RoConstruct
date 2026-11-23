// Inactive native 2008-06 recovery: the RBX::Extents unit 0060f3e0..0060fe95 (between DragUtilities getPrimitives 0060f3d0 and
// Dragger::toGrid 0060fea0). Out-of-line Extents members, in the order of the image:
//   closestFace 0060f3e0 (called from 0066c3ec), getCorner 0060f480, getFaceCorners 0060f4e0, separatedByMoreThan 0060f750, faceCenter 0060f7b0,
//   containedByFrustum 0060f820, vv 0060f8e0, express 0060f9b0, toWorldSpace 0060fc20, getPlane 0060fe40.
// Layout (low +0, high +0xc, 0x18) is the committed native util/Extents.h (read-only here). Math::inf is the donor
// util/Math.h function-local static (guard 0097b894, value 0097b890, initialized from the imported
// std::numeric_limits<float> infinity at 0080250c), read by express / toWorldSpace.
// Codegen analog: bodies follow the donor util/Extents.cpp shape; the recorder proves each against the bytes.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "util/Extents.h"
#include "util/Math.h"

namespace RBX
{
	NormalId Extents::closestFace(const G3D::Vector3& point)
	{
		NormalId faceId = NORM_X;

		float hy = fabs(point.y - this->high.y);
		float hz = fabs(point.z - this->high.z);
		float lx = fabs(point.x - this->low.x);
		float ly = fabs(point.y - this->low.y);
		float lz = fabs(point.z - this->low.z);

		float hx = fabs(point.x - this->high.x);
		if (hx > hy)
		{
			faceId = NORM_Y;
		}
		else
		{
			hy = hx;
		}

		if (hz < hy)
		{
			hy = hz;
			faceId = NORM_Z;
		}

		if (lx < hy)
		{
			hy = lx;
			faceId = NORM_X_NEG;
		}

		if (ly < hy)
		{
			hy = ly;
			faceId = NORM_Y_NEG;
		}

		if (lz < hy)
		{
			faceId = NORM_Z_NEG;
		}

		return faceId;
	}

	G3D::Vector3 Extents::getCorner(int i) const
	{
		return G3D::Vector3(
			this->low[0 + 3 * (i / 4)],
			this->low[1 + 3 * (i / 2 % 2)],
			this->low[2 + 3 * (i % 2)]
		);
	}

	void Extents::getFaceCorners(NormalId faceId, G3D::Vector3& v0, G3D::Vector3& v1, G3D::Vector3& v2, G3D::Vector3& v3) const
	{
		switch (faceId)
		{
		case NORM_X:
			v0 = getCorner(4);
			v1 = getCorner(6);
			v2 = getCorner(7);
			v3 = getCorner(5);
			break;
		case NORM_Y:
			v0 = getCorner(2);
			v1 = getCorner(3);
			v2 = getCorner(7);
			v3 = getCorner(6);
			break;
		case NORM_Z:
			v0 = getCorner(1);
			v1 = getCorner(5);
			v2 = getCorner(7);
			v3 = getCorner(3);
			break;
		case NORM_X_NEG:
			v0 = getCorner(0);
			v1 = getCorner(1);
			v2 = getCorner(3);
			v3 = getCorner(2);
			break;
		case NORM_Y_NEG:
			v0 = getCorner(0);
			v1 = getCorner(4);
			v2 = getCorner(5);
			v3 = getCorner(1);
			break;
		case NORM_Z_NEG:
			v0 = getCorner(0);
			v1 = getCorner(2);
			v2 = getCorner(6);
			v3 = getCorner(4);
			break;
		}
	}

	bool Extents::separatedByMoreThan(const Extents& other, float distance) const
	{
		G3D::Vector3 dv(distance, distance, distance);

		Extents thisExpanded(*this);
		thisExpanded.low -= dv;
		thisExpanded.high += dv;

		return !thisExpanded.overlapsOrTouches(other);
	}

	G3D::Vector3 Extents::faceCenter(NormalId faceId) const
	{
		G3D::Vector3 v = this->center();

		int i = faceId % 3;
		if (faceId < NORM_X_NEG)
		{
			v[i] = this->high[i];
		}
		else
		{
			v[i] = this->low[i];
		}

		return v;
	}

	bool Extents::containedByFrustum(const G3D::GCamera::Frustum& frustum) const
	{
		for (int i = 0; i < frustum.faceArray.size(); i++)
		{
			const G3D::Plane& plane = (frustum.faceArray.getCArray() + i)->plane;
			for (int j = 0; j < 8; j++)
			{
				G3D::Vector3 corner = getCorner(j);
				if (!plane.halfSpaceContains(corner))
				{
					return false;
				}
			}
		}

		return true;
	}

	Extents Extents::vv(const G3D::Vector3& v0, const G3D::Vector3& v1)
	{
		Extents result;

		result.low = v0.min(v1);
		result.high = v0.max(v1);

		return result;
	}

	// 0060f9b0 (parked, same size 617): the only divergence is the x87 operand order of row 1 of the inlined
	// myFrame.pointToWorldSpace (target r[1][1]*y + r[1][0]*x + r[1][2]*z at 0060fabb..0060facc, candidate
	// r[1][1]*y + r[1][2]*z + r[1][0]*x). Rejected variants (lf11): a named `corner = getCorner(i)` temporary (same
	// diff); the donor form `v1 = pointToWorldSpace(corner) - translation; inOther = v1 * rotation` (635 bytes, signed
	// getCorner division); a named `world = pointToWorldSpace(getCorner(i))` temporary (same diff).
	// Rejected (dm08, batch 23): `myFrame.rotation * getCorner(i) + myFrame.translation` (641 bytes: Matrix3::operator*
	// 00476580 is then called out of line instead of inlined).
	// Rejected (batch 39): the openrbx statement shape `for (...; ++i)` with `const G3D::Vector3 inOther` (same diff);
	// the exact sibling toWorldSpace 0060fc20 shape with named `corner`, `world` and `inOther` temporaries together
	// (same diff). Parked: x87 scheduling plateau (research/log.jsonl 2026-10-28), not a source-order difference.
	Extents Extents::express(const G3D::CoordinateFrame& myFrame, const G3D::CoordinateFrame& expressInFrame)
	{
		G3D::Vector3 minC(Math::inf(), Math::inf(), Math::inf());
		G3D::Vector3 maxC(-Math::inf(), -Math::inf(), -Math::inf());

		for (int i = 0; i < 8; i++)
		{
			G3D::Vector3 inOther = expressInFrame.pointToObjectSpace(myFrame.pointToWorldSpace(getCorner(i)));

			minC = minC.min(inOther);
			maxC = maxC.max(inOther);
		}

		return vv(minC, maxC);
	}

	Extents Extents::toWorldSpace(const G3D::CoordinateFrame& localCoord)
	{
		G3D::Vector3 minC(Math::inf(), Math::inf(), Math::inf());
		G3D::Vector3 maxC(-Math::inf(), -Math::inf(), -Math::inf());

		for (int i = 0; i < 8; i++)
		{
			G3D::Vector3 corner = getCorner(i);
			G3D::Vector3 world = localCoord.pointToWorldSpace(corner);

			minC = minC.min(world);
			maxC = maxC.max(world);
		}

		return vv(minC, maxC);
	}

	G3D::Plane Extents::getPlane(NormalId normalId) const
	{
		G3D::Vector3 point = faceCenter(normalId);
		G3D::Vector3 normal = normalIdToVector3(normalId);

		return G3D::Plane(normal, point);
	}
}

// 0060e970 (registry placeholder func_0060e970; only caller MegaDragger::hitObjectOrPlane 0060dec0 at 0060df3e): donor
// tools/rbxgs tool/DragUtilities.cpp DragUtilities::hitObjectOrPlane, declared by native tool/DragUtilities.h. A row of
// the DragUtilities unit just below this Extents unit (before anyPartAlive 0060ead0, DragUtilitiesAlive.cpp), landed here
// as assigned. Callees: MouseCommand::getSearchRay(const Ray&) 006158f0, ContactManager::getHit(Array) 0060d6e0 with the
// default `inside` = ContactManager::ignoreBool 0097beb8, Plane(unitY, zero) 005259e0 (the Plane temporary is the EH
// state), Math::intersectRayPlane 005df380, Dragger::toGrid 0060fea0. The 2008 body keeps the donor shape.
#include "tool/DragUtilities.h"
#include "tool/Dragger.h"
#include "v8datamodel/MouseCommand.h"
#include "v8world/ContactManager.h"
#include <G3D/Plane.h>

namespace RBX
{
	bool DragUtilities::hitObjectOrPlane(const ContactManager& contactManager, const G3D::Ray& unitSearchRay, const G3D::Array<Primitive*>* ignorePrims, G3D::Vector3& hit)
	{
		G3D::Ray ray = MouseCommand::getSearchRay(unitSearchRay);

		if (!contactManager.getHit(ray, toConstPrimitives(ignorePrims), NULL, hit))
		{
			if (!Math::intersectRayPlane(ray, G3D::Plane(G3D::Vector3::unitY(), G3D::Vector3::zero()), hit))
			{
				hit = G3D::Vector3::zero();
				return false;
			}
		}

		hit = Dragger::toGrid(hit);

		return true;
	}
}
