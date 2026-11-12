// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client App/v8world/ContactManager.cpp

// Candidate translation unit (score above; library headers required).
#include "decomp.h"
#include "util/HitTestFilter.h"
#include "v8world/Contact.h"
#include "v8world/SpatialHash.h"
#include "v8world/World.h"

#include <algorithm>
#include <set>

namespace RBX {

bool ContactManager::ignoreBool;

// FUNCTION: WEBSERVICE 0x101080d0
// FUNCTION: ROBLOX 0x0063e350
ContactManager::ContactManager(World* world) : spatialHash(new SpatialHash(world, this)), world(world)
{
}

// FUNCTION: WEBSERVICE 0x10108130
// FUNCTION: ROBLOX 0x0063e3b0
void ContactManager::getPrimitivesTouchingExtents(
	const Extents& extents, const Primitive* ignore, G3D::Array<Primitive*>& found
)
{
	spatialHash->getPrimitivesTouchingExtents(extents, ignore, found);
}

// FUNCTION: WEBSERVICE 0x10108140
// FUNCTION: ROBLOX 0x0063e3c0
void ContactManager::onReleasePair(Primitive* p0, Primitive* p1)
{
	Contact* contact = Primitive::getContact(p0, p1);

	world->destroyContact(contact);
}

// FUNCTION: WEBSERVICE 0x10108170
// FUNCTION: ROBLOX 0x0063e3f0
void ContactManager::onPrimitiveAdded(Primitive* p)
{
	spatialHash->onPrimitiveAdded(p);
}

// FUNCTION: WEBSERVICE 0x10108180
// FUNCTION: ROBLOX 0x0063e400
void ContactManager::onPrimitiveRemoved(Primitive* p)
{
	spatialHash->onPrimitiveRemoved(p);
}

// FUNCTION: WEBSERVICE 0x10108190
// FUNCTION: ROBLOX 0x0063e410
void ContactManager::onPrimitiveExtentsChanged(Primitive* p)
{
	spatialHash->onPrimitiveExtentsChanged(p);
}

// FUNCTION: WEBSERVICE 0x101081a0
// FUNCTION: ROBLOX 0x0063e420
void ContactManager::stepWorld()
{
	spatialHash->onAllPrimitivesMoved();
}

// FUNCTION: WEBSERVICE 0x101081b0
// FUNCTION: ROBLOX 0x0063e430 FOLDED
ContactManager::~ContactManager()
{
	delete spatialHash;
}

// FUNCTION: WEBSERVICE 0x101081d0
// FUNCTION: ROBLOX 0x0063e450
Primitive* ContactManager::getSlowHit(
	const G3D::Array<Primitive*>& primitives,
	const G3D::Ray& unitRay,
	const G3D::Array<const Primitive*>* ignorePrim,
	const HitTestFilter* filter,
	Vector3& hitPoint,
	float maxDistance,
	bool& inside,
	bool& stopped
) const
{
	float bestOffset = maxDistance;
	float stopOffset = maxDistance;
	Primitive* bestPrimitive = NULL;

	stopped = false;
	inside = false;

	for (int i = 0; i < primitives.size(); ++i) {
		Primitive* primitive = primitives[i];

		bool notIgnored;

		if (ignorePrim != NULL) {
			notIgnored = ignorePrim->find(primitive) == ignorePrim->end();
		}
		else {
			notIgnored = true;
		}

		HitTestFilter::Result result;

		if (filter != NULL) {
			result = filter->filterResult(primitive);
		}
		else {
			result = HitTestFilter::INCLUDE_PRIM;
		}

		if (notIgnored && result != HitTestFilter::IGNORE_PRIM) {
			Vector3 worldPos = primitive->getCoordinateFrame().translation;
			float radius = primitive->getRadius();

			float along = (worldPos - unitRay.origin).dot(unitRay.direction);

			if ((worldPos - (unitRay.origin + unitRay.direction * along)).magnitude() <= radius) {
				Vector3 thisHitPoint(0.0f, 0.0f, 0.0f);
				bool thisInside;

				if (primitive->hitTest(unitRay, thisHitPoint, thisInside)) {
					float distance = (thisHitPoint - unitRay.origin).dot(unitRay.direction);

					if (distance > 0.0f) {
						switch (result) {
						case HitTestFilter::STOP_TEST:
							if (distance < stopOffset) {
								stopped = true;
								stopOffset = distance;
							}
							break;

						case HitTestFilter::INCLUDE_PRIM:
							if (distance < bestOffset) {
								inside = thisInside;
								bestOffset = distance;
								hitPoint = thisHitPoint;
								bestPrimitive = primitive;
							}
							break;
						}
					}
				}
			}
		}
	}

	if (stopped && bestPrimitive != NULL && bestOffset < stopOffset) {
		stopped = false;
	}

	return bestPrimitive;
}

// FUNCTION: WEBSERVICE 0x10108620
// FUNCTION: ROBLOX 0x0063e910
bool ContactManager::intersectingOthers(Primitive* check, const std::set<Primitive*>& checkSet, float overlapIgnored)
{
	Contact* c = check->getFirstContact();

	while (c != NULL) {
		Primitive* other = c->otherPrimitive(check);

		if (checkSet.find(other) == checkSet.end() && c->computeIsColliding(overlapIgnored)) {
			return true;
		}

		c = check->getNextContact(c);
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x101086c0
// FUNCTION: ROBLOX 0x0063e9b0
Primitive* ContactManager::getFastHit(
	const G3D::Ray& worldRay,
	const G3D::Array<const Primitive*>* ignorePrim,
	const HitTestFilter* filter,
	Vector3& hitPointWorld,
	bool& inside,
	bool& stopped
) const
{
	G3D::Array<Primitive*> primitives;

	Vector3int32 grid = SpatialHash::realToHashGrid(worldRay.origin);

	float length = worldRay.direction.magnitude();
	float maxDistance = std::min(5000.0f, length);

	G3D::Ray unitRay = worldRay.unit();

	do {
		primitives.resize(0, false);
		spatialHash->getPrimitivesInGrid(grid, primitives);

		Primitive* hit =
			getSlowHit(primitives, unitRay, ignorePrim, filter, hitPointWorld, maxDistance, inside, stopped);

		if (hit != NULL) {
			Vector3 gridCenter((float) grid.x, (float) grid.y, (float) grid.z);
			Extents hashGrid = SpatialHash::hashGridToRealExtents(gridCenter);

			if (hashGrid.fuzzyContains(hitPointWorld, 0.001f)) {
				return hit;
			}
		}
	} while (spatialHash->getNextGrid(grid, unitRay, maxDistance));

	return NULL;
}

// FUNCTION: WEBSERVICE 0x10108890
// FUNCTION: ROBLOX 0x0063eb80
Primitive* ContactManager::getHit(
	const G3D::Ray& ray,
	const G3D::Array<const Primitive*>* ignore,
	const HitTestFilter* filter,
	Vector3& hitPoint,
	bool& hitSurface
) const
{
	world->update();

	bool blocked;
	Primitive* hit = getFastHit(ray, ignore, filter, hitPoint, hitSurface, blocked);

	if (blocked) {
		hit = NULL;
	}
	else if (hit != NULL) {
		return hit;
	}

	hitPoint = Vector3::zero();
	hitSurface = false;

	return hit;
}

// FUNCTION: WEBSERVICE 0x10108920
// FUNCTION: ROBLOX 0x0063ec10
Primitive* ContactManager::getHitLegacy(
	const G3D::Ray& originDirection,
	const Primitive* ignorePrim,
	const HitTestFilter* filter,
	Vector3& hitPointWorld,
	float& distanceToHit,
	const float& maxSearchDepth
) const
{
	G3D::Ray worldRay =
		G3D::Ray::fromOriginAndDirection(originDirection.origin, originDirection.direction * maxSearchDepth);

	G3D::Array<const Primitive*> ignorePrims;

	if (ignorePrim != NULL) {
		ignorePrims.append(ignorePrim);
	}

	Primitive* hit = getHit(worldRay, &ignorePrims, filter, hitPointWorld, ignoreBool);

	distanceToHit = hit != NULL ? (hitPointWorld - worldRay.origin).magnitude() : 0.0f;

	return hit;
}

// FUNCTION: WEBSERVICE 0x10108aa0
// FUNCTION: ROBLOX 0x0063ed90
Primitive* ContactManager::getHit(
	const G3D::Ray& ray,
	const std::vector<const Primitive*>* ignore,
	const HitTestFilter* filter,
	Vector3& hitPoint,
	bool& hitSurface
) const
{
	G3D::Array<const Primitive*> ignored;

	ignored = *ignore;

	return getHit(ray, &ignored, filter, hitPoint, hitSurface);
}

// FUNCTION: WEBSERVICE 0x10108b30
// FUNCTION: ROBLOX 0x0063ee20
Contact* ContactManager::createContact(Primitive* p0, Primitive* p1)
{
	if (p0->getPrimitiveType() > p1->getPrimitiveType()) {
		std::swap(p0, p1);
	}

	Geometry::GeometryType type0 = p0->getPrimitiveType();
	Geometry::GeometryType type1 = p1->getPrimitiveType();

	switch (type0) {

	case Geometry::GEOMETRY_BALL:

		switch (type1) {

		case Geometry::GEOMETRY_BALL:
			return new BallBallContact(p0, p1);

		case Geometry::GEOMETRY_BLOCK:
			return new BallBlockContact(p0, p1);
		}

	case Geometry::GEOMETRY_BLOCK:
		return new BlockBlockContact(p0, p1);
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x10108c60
// FUNCTION: ROBLOX 0x0063ef50
void ContactManager::onNewPair(Primitive* p0, Primitive* p1)
{
	Contact* contact = createContact(p0, p1);

	world->insertContact(contact);
}

// FUNCTION: WEBSERVICE 0x10108c90
// FUNCTION: ROBLOX 0x0063ef80
void ContactManager::onPrimitiveGeometryTypeChanged(Primitive* p)
{
	G3D::Array<Contact*> newContacts;

	Contact* c;

	while ((c = p->getFirstContact()) != NULL) {
		newContacts.append(createContact(c->getPrimitive(0), c->getPrimitive(1)));

		world->destroyContact(c);
	}

	for (int i = 0; i < newContacts.size(); i++) {
		world->insertContact(newContacts[i]);
	}
}

// FUNCTION: WEBSERVICE 0x10108ea0
// FUNCTION: ROBLOX 0x0063f190
bool ContactManager::intersectingOthers(const G3D::Array<Primitive*>& check, float overlapIgnored)
{
	std::set<Primitive*> checkSet(check.begin(), check.end());

	for (int i = 0; i < check.size(); i++) {
		if (intersectingOthers(check[i], checkSet, overlapIgnored)) {
			return true;
		}
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x10108fa0
// FUNCTION: ROBLOX 0x0063f290
bool ContactManager::intersectingOthers(Primitive* check, float overlapIgnored)
{
	std::set<Primitive*> checkSet;

	checkSet.insert(check);

	return intersectingOthers(check, checkSet, overlapIgnored);
}

} // namespace RBX
