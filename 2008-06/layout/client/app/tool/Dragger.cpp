#include "tool/Dragger.h"
#include "v8world/ContactManager.h"
#include "util/Math.h"
#include "v8world/Primitive.h"

namespace RBX
{
	G3D::Vector3 Dragger::toGrid(const G3D::Vector3& v)
	{
		return Math::toGrid(v, dragSnap());
	}

	Extents Dragger::computeExtents(const G3D::Array<Primitive*>& primitives)
	{
		Extents result = Extents::negativeInfiniteExtents();
		for (int i = 0; i < primitives.size(); ++i)
		{
			Primitive* primitive = primitives[i];
			G3D::Vector3 half = primitive->getGeometry()->getGridSize() * 0.5f;
			Extents world = Extents(-half, half).toWorldSpace(primitive->getCoordinateFrame());
			result.unionWith(world);
		}
		return result;
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

template class G3D::Array<RBX::Primitive *>;

namespace RBX {
G3D::Vector3 Dragger::safeMoveAlongLine(const G3D::Array<Primitive*>& primitives,
    const G3D::Vector3& delta, ContactManager& contactManager) {
    if (primitives.size() == 0) return G3D::Vector3::zero();
    G3D::Vector3 result(G3D::Vector3::zero());
    if (delta != G3D::Vector3::zero())
        safePlaceAlongLine(primitives, G3D::Vector3::zero(), delta, result, contactManager);
    return result;
}
}

namespace RBX {
void Dragger::movePrimitivesGoal(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& goal, G3D::Vector3& previous) {
    G3D::Vector3 difference = goal - previous;
    G3D::Vector3 movement = Math::toGrid(difference, dragSnap());
    if (movement != G3D::Vector3::zero()) { movePrimitives(primitives, movement); previous = goal; }
}
void Dragger::safePlaceAlongLine(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& start,
    const G3D::Vector3& end, G3D::Vector3& result, ContactManager& manager) {
    movePrimitivesGoal(primitives, end, result);
    if (!intersectingWorldOrOthers(primitives, manager)) return;
    G3D::Vector3 average = (start + end) * 0.51f;
    G3D::Vector3 midpoint = Math::toGrid(average, dragSnap());
    movePrimitivesGoal(primitives, midpoint, result);
    bool intersecting = intersectingWorldOrOthers(primitives, manager);
    if (midpoint == end) {
        if (intersecting) movePrimitivesGoal(primitives, start, result);
    } else if (intersecting) safePlaceAlongLine(primitives, start, midpoint, result, manager);
    else safePlaceAlongLine(primitives, midpoint, end, result, manager);
}
}
