// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
ContactManager::ContactManager(World* world) : spatialHash(new SpatialHash(world, this)), world(world)
{
}

// FUNCTION: WEBSERVICE 0x10108130
void ContactManager::getPrimitivesTouchingExtents(
	const Extents& extents,
	const Primitive* ignore,
	G3D::Array<Primitive*>& found
)
{
	spatialHash->getPrimitivesTouchingExtents(extents, ignore, found);
}

// FUNCTION: WEBSERVICE 0x10108140
void ContactManager::onReleasePair(Primitive* p0, Primitive* p1)
{
	Contact* contact = Primitive::getContact(p0, p1);

	world->destroyContact(contact);
}

// FUNCTION: WEBSERVICE 0x10108170
void ContactManager::onPrimitiveAdded(Primitive* p)
{
	spatialHash->onPrimitiveAdded(p);
}

// FUNCTION: WEBSERVICE 0x10108180
void ContactManager::onPrimitiveRemoved(Primitive* p)
{
	spatialHash->onPrimitiveRemoved(p);
}

// FUNCTION: WEBSERVICE 0x10108190
void ContactManager::onPrimitiveExtentsChanged(Primitive* p)
{
	spatialHash->onPrimitiveExtentsChanged(p);
}

// FUNCTION: WEBSERVICE 0x101081a0
void ContactManager::stepWorld()
{
	spatialHash->onAllPrimitivesMoved();
}

// FUNCTION: WEBSERVICE 0x101081b0
ContactManager::~ContactManager()
{
	delete spatialHash;
}

// FUNCTION: WEBSERVICE 0x101081d0
Primitive* ContactManager::getSlowHit(
	const G3D::Array<Primitive*>& primitives,
	const G3D::Ray& unitRay,
	const G3D::Array<const Primitive*>* ignore,
	const HitTestFilter* filter,
	Vector3& hitPoint,
	float maxDistance,
	bool& hitSurface,
	bool& blocked
) const
{
	float closestHit = maxDistance;
	float closestBlock = maxDistance;
	Primitive* answer = NULL;

	blocked = false;
	hitSurface = false;

	for (int i = 0; i < primitives.size(); ++i) {
		Primitive* primitive = primitives[i];

		bool notIgnored;

		if (ignore != NULL) {
			notIgnored = ignore->find(primitive) == ignore->end();
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
			Vector3 center = primitive->getCoordinateFrame().translation;
			float radius = primitive->getRadius();

			float along = (center - unitRay.origin).dot(unitRay.direction);

			if ((center - (unitRay.origin + unitRay.direction * along)).magnitude() <= radius) {
				Vector3 surface(0.0f, 0.0f, 0.0f);
				bool inside;

				if (primitive->hitTest(unitRay, surface, inside)) {
					float distance = (surface - unitRay.origin).dot(unitRay.direction);

					if (distance > 0.0f) {
						switch (result) {
						case HitTestFilter::STOP_TEST:
							if (distance < closestBlock) {
								blocked = true;
								closestBlock = distance;
							}
							break;

						case HitTestFilter::INCLUDE_PRIM:
							if (distance < closestHit) {
								hitSurface = inside;
								closestHit = distance;
								hitPoint = surface;
								answer = primitive;
							}
							break;
						}
					}
				}
			}
		}
	}

	if (blocked && answer != NULL && closestHit < closestBlock) {
		blocked = false;
	}

	return answer;
}

// FUNCTION: WEBSERVICE 0x10108620
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
Primitive* ContactManager::getFastHit(
	const G3D::Ray& ray,
	const G3D::Array<const Primitive*>* ignore,
	const HitTestFilter* filter,
	Vector3& hitPoint,
	bool& hitSurface,
	bool& blocked
) const
{
	G3D::Array<Primitive*> found;

	Vector3int32 grid = SpatialHash::realToHashGrid(ray.origin);

	float length = ray.direction.magnitude();
	float maxDistance = std::min(5000.0f, length);

	G3D::Ray unitRay = ray.unit();

	do {
		found.resize(0, false);
		spatialHash->getPrimitivesInGrid(grid, found);

		Primitive* hit = getSlowHit(found, unitRay, ignore, filter, hitPoint, maxDistance, hitSurface, blocked);

		if (hit != NULL) {
			Vector3 gridCenter((float) grid.x, (float) grid.y, (float) grid.z);
			Extents extents = SpatialHash::hashGridToRealExtents(gridCenter);

			if (extents.fuzzyContains(hitPoint, 0.001f)) {
				return hit;
			}
		}
	} while (spatialHash->getNextGrid(grid, unitRay, maxDistance));

	return NULL;
}

// FUNCTION: WEBSERVICE 0x10108890
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
Primitive* ContactManager::getHitLegacy(
	const G3D::Ray& ray,
	const Primitive* ignore,
	const HitTestFilter* filter,
	Vector3& hitPoint,
	float& distance,
	const float& maxDistance
) const
{
	G3D::Ray scaled = G3D::Ray::fromOriginAndDirection(ray.origin, ray.direction * maxDistance);

	G3D::Array<const Primitive*> ignored;

	if (ignore != NULL) {
		ignored.append(ignore);
	}

	Primitive* hit = getHit(scaled, &ignored, filter, hitPoint, ignoreBool);

	distance = hit != NULL ? (hitPoint - scaled.origin).magnitude() : 0.0f;

	return hit;
}

// FUNCTION: WEBSERVICE 0x10108aa0
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
void ContactManager::onNewPair(Primitive* p0, Primitive* p1)
{
	Contact* contact = createContact(p0, p1);

	world->insertContact(contact);
}

// FUNCTION: WEBSERVICE 0x10108c90
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
bool ContactManager::intersectingOthers(Primitive* check, float overlapIgnored)
{
	std::set<Primitive*> checkSet;

	checkSet.insert(check);

	return intersectingOthers(check, checkSet, overlapIgnored);
}

} // namespace RBX
