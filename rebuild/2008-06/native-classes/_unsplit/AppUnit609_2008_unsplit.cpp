// UNSPLIT CANDIDATE (2026-11-08): combined AppUnit609 dragger+extents
// Originals preserved.

// ---- BEGIN AppUnit609_2008Dragger.cpp ----
// Inactive native 2008-06 recovery: rows of the RBX::Dragger unit 0060fea0..00610bee (after the Extents unit
// 0060f3e0..0060fe95; the Lua 5.1.1 library starts at luaL_where 00610bf0). Declarations are the donor
// tool/Dragger.h (read-only; no native header shadows it). Bodies written here:
//   toGrid 0060fea0, intersectingWorldOrOthers 00610130, movePrimitivesDelta 00610270, searchUpFine 00610310,
//   searchDownFine 006103a0, searchUpGross 00610440, searchDownGross 006104e0, safeMoveYDrop 00610830,
//   safeMoveNoDrop 00610930.
// Out-of-unit-recovered rows called here: movePrimitives 0060fef0 and computeExtents(Array) 00610070 (bound by the
// recorder at the original call sites). Step constants from .rdata: 0.1f 0081e704, -0.1f 00843764, 1.2f 00827278,
// -1.2f 00830b6c; the world floor -0.01f 00843760 and the overlap 0.01f 0082748c (intersectingWorldOrOthers).
// The 2008 search functions are not in the donor: their shapes are read from the bytes (one step, then repeat while
// the moved vector is finite and the intersection test keeps the same answer; a Gross search hands over to the
// Fine search in the opposite direction).
// Codegen analog: the recorder proves each body against the bytes; names follow the donor declarations.
// >>> native-status (generated) -- do not edit >>>
// AppUnit609_2008_unsplit | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src d2cea473 | roc native-status --write
#include "tool/Dragger.h"
#include "v8world/ContactManager.h"
#include "util/Math.h"

namespace RBX
{
	G3D::Vector3 Dragger::toGrid(const G3D::Vector3& v)
	{
		return Math::toGrid(v, dragSnap());
	}

	__declspec(noinline) bool Dragger::intersectingWorldOrOthers(const G3D::Array<Primitive*>& primitives, ContactManager& contactManager)
	{
		Extents group = computeExtents(primitives);
		return group.min().y < -0.01f || contactManager.intersectingOthers(primitives, 0.01f);
	}

	void Dragger::movePrimitivesDelta(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& delta, G3D::Vector3& movedSoFar)
	{
		movePrimitives(primitives, delta);
		movedSoFar = toGrid(movedSoFar + delta);
	}

	void Dragger::searchUpFine(const G3D::Array<Primitive*>& primitives, G3D::Vector3& movedSoFar, ContactManager& contactManager)
	{
		movePrimitivesDelta(primitives, G3D::Vector3(0.0f, 0.1f, 0.0f), movedSoFar);
		while (!Math::isNanInfDenormVector3(movedSoFar) && intersectingWorldOrOthers(primitives, contactManager))
		{
			movePrimitivesDelta(primitives, G3D::Vector3(0.0f, 0.1f, 0.0f), movedSoFar);
		}
	}

	void Dragger::searchDownFine(const G3D::Array<Primitive*>& primitives, G3D::Vector3& movedSoFar, ContactManager& contactManager)
	{
		movePrimitivesDelta(primitives, G3D::Vector3(0.0f, -0.1f, 0.0f), movedSoFar);
		while (!Math::isNanInfDenormVector3(movedSoFar))
		{
			if (intersectingWorldOrOthers(primitives, contactManager))
			{
				searchUpFine(primitives, movedSoFar, contactManager);
				return;
			}
			movePrimitivesDelta(primitives, G3D::Vector3(0.0f, -0.1f, 0.0f), movedSoFar);
		}
	}

	void Dragger::searchUpGross(const G3D::Array<Primitive*>& primitives, G3D::Vector3& movedSoFar, ContactManager& contactManager)
	{
		movePrimitivesDelta(primitives, G3D::Vector3(0.0f, 1.2f, 0.0f), movedSoFar);
		while (!Math::isNanInfDenormVector3(movedSoFar))
		{
			if (!intersectingWorldOrOthers(primitives, contactManager))
			{
				searchDownFine(primitives, movedSoFar, contactManager);
				return;
			}
			movePrimitivesDelta(primitives, G3D::Vector3(0.0f, 1.2f, 0.0f), movedSoFar);
		}
	}

	void Dragger::searchDownGross(const G3D::Array<Primitive*>& primitives, G3D::Vector3& movedSoFar, ContactManager& contactManager)
	{
		movePrimitivesDelta(primitives, G3D::Vector3(0.0f, -1.2f, 0.0f), movedSoFar);
		while (!Math::isNanInfDenormVector3(movedSoFar))
		{
			if (intersectingWorldOrOthers(primitives, contactManager))
			{
				searchUpFine(primitives, movedSoFar, contactManager);
				return;
			}
			movePrimitivesDelta(primitives, G3D::Vector3(0.0f, -1.2f, 0.0f), movedSoFar);
		}
	}

	G3D::Vector3 Dragger::safeMoveYDrop(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& tryMove, ContactManager& contactManager)
	{
		if (primitives.size() == 0)
		{
			return G3D::Vector3::zero();
		}

		G3D::Vector3 moved = tryMove - G3D::Vector3(0.0f, 1.2f, 0.0f);
		moved = Math::toGrid(moved, 0.1f);

		movePrimitives(primitives, moved);

		if (intersectingWorldOrOthers(primitives, contactManager))
			searchUpGross(primitives, moved, contactManager);
		else
			searchDownGross(primitives, moved, contactManager);

		return moved;
	}

	G3D::Vector3 Dragger::safeMoveNoDrop(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& tryMove, ContactManager& contactManager)
	{
		G3D::Vector3 movedSoFar(0.0f, 0.0f, 0.0f);

		if (primitives.size() == 0)
		{
			return G3D::Vector3::zero();
		}

		if (tryMove != G3D::Vector3::zero())
		{
			movePrimitives(primitives, tryMove);
			movedSoFar += tryMove;
		}

		if (intersectingWorldOrOthers(primitives, contactManager))
			searchUpGross(primitives, movedSoFar, contactManager);

		return movedSoFar;
	}
}
// ---- END AppUnit609_2008Dragger.cpp ----

// ---- BEGIN AppUnit609_2008Extents.cpp ----
// Inactive native 2008-06 recovery: the RBX::Extents unit 0060f3e0..0060fe95 (between DragUtilities getPrimitives 0060f3d0 and
// Dragger::toGrid 0060fea0). Out-of-line Extents members, in the order of the image:
//   closestFace 0060f3e0 (called from 0066c3ec), getCorner 0060f480, getFaceCorners 0060f4e0, separatedByMoreThan 0060f750, faceCenter 0060f7b0,
//   containedByFrustum 0060f820, vv 0060f8e0, express 0060f9b0, toWorldSpace 0060fc20, getPlane 0060fe40.
// Layout (low +0, high +0xc, 0x18) is the committed native util/Extents.h (read-only here). Math::inf is the donor
// util/Math.h function-local static (guard 0097b894, value 0097b890, initialized from the imported
// std::numeric_limits<float> infinity at 0080250c), read by express / toWorldSpace.
// Codegen analog: bodies follow the donor util/Extents.cpp shape; the recorder proves each against the bytes.
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
// ---- END AppUnit609_2008Extents.cpp ----

