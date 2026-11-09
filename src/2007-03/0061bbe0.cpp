// from server: 30% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/SpatialHash.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/SpatialHash.h"

#include "decomp.h"
#include "v8world/Assembly2.h"
#include "v8world/Primitive.h"
#include "v8world/World.h"

#include <G3D/AABox.h>
#include <G3D/CollisionDetection.h>
#include <G3D/Ray.h>
#include <algorithm>
#include <cstdlib>

namespace RBX {

// FUNCTION: WEBSERVICE 0x101233c0
Vector3int32 SpatialHash::realToHashGrid(const Vector3& realPoint)
{
	Vector3 gridPoint = realPoint * hashGridRecip();

	return Vector3int32::floor(gridPoint);
}

// FUNCTION: WEBSERVICE 0x10123410
Extents SpatialHash::hashGridToRealExtents(const Vector3& hashGrid)
{
	return Extents(
		hashGrid * hashGridSize(),
		Vector3(hashGrid.x + 1.0f, hashGrid.y + 1.0f, hashGrid.z + 1.0f) * hashGridSize()
	);
}

// FUNCTION: WEBSERVICE 0x10123460
void SpatialHash::computeMinMax(const Extents& extents, Vector3int32& min, Vector3int32& max)
{
	min = realToHashGrid(extents.min());
	max = realToHashGrid(extents.max());
}

void SpatialHash::removeNodeFromPrimitive(SpatialNode* remove)
{
	SpatialNode* next = remove->nextPrimitiveLink;
	SpatialNode* prev = remove->prevPrimitiveLink;

	if (next != NULL) {
		next->prevPrimitiveLink = prev;
	}

	if (prev != NULL) {
		prev->nextPrimitiveLink = next;
	}
	else {
		remove->primitive->spatialNodes = next;
	}
}

// FUNCTION: WEBSERVICE 0x10123500
bool SpatialHash::getNextGrid(Vector3int32& grid, const G3D::Ray& unitRay, float maxDistance)
{
	Vector3int32 low;
	Vector3int32 high;

	for (int a = 0; a < 3; a++) {
		low[a] = unitRay.direction[a] < 0.0f ? -1 : 0;
		high[a] = unitRay.direction[a] > 0.0f ? 1 : 0;
	}

	Vector3 gridF = grid.toVector3();

	float maxCheck = maxDistance + 2.0f * hashGridSize();

	float maxDistanceSquared = maxCheck * maxCheck;

	for (int nz = 1; nz <= 3; nz++) {
		for (int i = low.x; i <= high.x; i++) {
			for (int j = low.y; j <= high.y; j++) {
				for (int k = low.z; k <= high.z; k++) {
					if (abs(i) + abs(j) + abs(k) == nz) {
						Vector3 offset((float) i, (float) j, (float) k);

						Extents box = hashGridToRealExtents(gridF + offset);

						G3D::AABox aaBox(box.min(), box.max());

						Vector3 location;

						if (G3D::CollisionDetection::collisionLocationForMovingPointFixedAABox(
								unitRay.origin,
								unitRay.direction,
								aaBox,
								location
							)) {
							if ((location - unitRay.origin).squaredLength() < maxDistanceSquared) {
								grid = Vector3int32::floor(gridF + offset);

								return true;
							}
						}
					}
				}
			}
		}
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x10123840
void SpatialHash::removeNodeFromHash(SpatialNode* remove)
{
	SpatialNode** link = &nodes[remove->hashId];

	while (*link != remove) {
		link = &(*link)->nextHashLink;
	}
	*link = remove->nextHashLink;
}

int SpatialHash::getHash(const Vector3int32& grid)
{
	return (grid.x * -2979 ^ grid.y * 16543 ^ grid.z * -73) & (numBuckets() - 1);
}

// FUNCTION: WEBSERVICE 0x10123890
SpatialNode* SpatialHash::findNode(Primitive* p, const Vector3int32& grid)
{
	int hash = getHash(grid);

	SpatialNode* node = nodes[hash];

	while (node->primitive != p || node->gridId != grid) {
		node = node->nextHashLink;
	}

	return node;
}

// FUNCTION: WEBSERVICE 0x10123910
bool SpatialHash::shareCommonGrid(Primitive* me, Primitive* other)
{
	for (SpatialNode* node = me->spatialNodes; node != NULL; node = node->nextPrimitiveLink) {
		for (SpatialNode* hashNode = nodes[node->hashId]; hashNode != NULL; hashNode = hashNode->nextHashLink) {
			if (hashNode->primitive == other && hashNode->gridId == node->gridId) {
				return true;
			}
		}
	}

	return false;
}

void SpatialHash::returnNode(SpatialNode* node)
{
	node->nextHashLink = extraNodes;
	nodesOut--;
	extraNodes = node;
}

// FUNCTION: WEBSERVICE 0x10123990
void SpatialHash::destroyNode(SpatialNode* destroy)
{
	removeNodeFromPrimitive(destroy);

	removeNodeFromHash(destroy);

	Vector3int32 destroyGrid = destroy->gridId;

	SpatialNode* node = nodes[destroy->hashId];

	while (node != NULL) {
		if (node->gridId == destroyGrid) {
			Primitive* me = destroy->primitive;
			Primitive* other = node->primitive;

			if (Primitive::getContact(me, other) != NULL) {
				if (!shareCommonGrid(me, other)) {
					contactManager->onReleasePair(me, other);
				}
			}
		}

		node = node->nextHashLink;
	}

	returnNode(destroy);
}

SpatialNode* SpatialHash::newNode()
{
	nodesOut++;

	if (extraNodes != NULL) {
		SpatialNode* node = extraNodes;

		extraNodes = node->nextHashLink;

		return node;
	}

	return new SpatialNode();
}

void SpatialHash::insertNodeToPrimitive(SpatialNode* node, Primitive* p, const Vector3int32& grid, int hash)
{
	node->primitive = p;
	node->gridId = grid;
	node->hashId = hash;

	SpatialNode* first = p->spatialNodes;

	p->spatialNodes = node;

	node->nextPrimitiveLink = first;
	node->prevPrimitiveLink = NULL;

	if (first != NULL) {
		first->prevPrimitiveLink = node;
	}
}

// FUNCTION: WEBSERVICE 0x10123a70
void SpatialHash::addNode(Primitive* p, const Vector3int32& grid)
{
	int hash = getHash(grid);

	SpatialNode* node = newNode();

	insertNodeToPrimitive(node, p, grid, hash);

	SpatialNode* other = nodes[hash];

	node->nextHashLink = other;
	nodes[hash] = node;

	int numNodes = 1;

	while (other != NULL) {
		Primitive* otherPrimitive = other->primitive;

		numNodes++;

		if (otherPrimitive != p && other->gridId == grid) {
			if (Primitive::getContact(p, otherPrimitive) == NULL) {
				contactManager->onNewPair(p, otherPrimitive);
			}
		}

		other = other->nextHashLink;
	}

	maxBucket = std::max(maxBucket, numNodes);
}

// FUNCTION: WEBSERVICE 0x10123bd0
void SpatialHash::onPrimitiveAdded(Primitive* p)
{
	Vector3int32 newMin;
	Vector3int32 newMax;

	const Extents& extents = p->getFastFuzzyExtents();

	computeMinMax(extents, newMin, newMax);

	p->oldSpatialMin = newMin;
	p->oldSpatialMax = newMax;

	for (int i = newMin.x; i <= newMax.x; i++) {
		for (int j = newMin.y; j <= newMax.y; j++) {
			for (int k = newMin.z; k <= newMax.z; k++) {
				addNode(p, Vector3int32(i, j, k));
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x10123cc0
void SpatialHash::changeMinMax(Primitive* p, const Extents& change, const Extents& oldBox, const Extents& newBox)
{
	Vector3int32 min = Vector3int32::floor(change.min());
	Vector3int32 max = Vector3int32::floor(change.max());

	for (int i = min.x; i <= max.x; i++) {
		for (int j = min.y; j <= max.y; j++) {
			for (int k = min.z; k <= max.z; k++) {
				bool inNew = newBox.contains(Vector3((float) i, (float) j, (float) k));
				bool inOld = oldBox.contains(Vector3((float) i, (float) j, (float) k));

				if (inNew) {
					if (!inOld) {
						addNode(p, Vector3int32(i, j, k));
					}
				}
				else if (inOld) {
					SpatialNode* node = findNode(p, Vector3int32(i, j, k));

					destroyNode(node);
				}
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x10123e20
void SpatialHash::primitiveExtentsChanged(Primitive* p)
{
	Vector3int32 newMin;
	Vector3int32 newMax;

	const Extents& extents = p->getFastFuzzyExtents();

	computeMinMax(extents, newMin, newMax);

	if (newMin != p->oldSpatialMin || newMax != p->oldSpatialMax) {
		Extents newBox(newMin, newMax);
		Extents oldBox(p->oldSpatialMin, p->oldSpatialMax);

		if (newBox.overlapsOrTouches(oldBox)) {
			Extents unionBox = newBox;
			unionBox.unionWith(oldBox);

			changeMinMax(p, unionBox, oldBox, newBox);
		}
		else {
			changeMinMax(p, oldBox, oldBox, newBox);
			changeMinMax(p, newBox, oldBox, newBox);
		}

		p->oldSpatialMin = newMin;
		p->oldSpatialMax = newMax;
	}
}

// FUNCTION: WEBSERVICE 0x10123fb0
void SpatialHash::onPrimitiveRemoved(Primitive* p)
{
	while (p->spatialNodes != NULL) {
		destroyNode(p->spatialNodes);
	}
}

// FUNCTION: WEBSERVICE 0x10123fe0
void SpatialHash::onPrimitiveExtentsChanged(Primitive* p)
{
	primitiveExtentsChanged(p);
}

// FUNCTION: WEBSERVICE 0x10123ff0
void SpatialHash::onAllPrimitivesMoved()
{
	const G3D::Array<Primitive*>& primitives = world->getPrimitives();

	for (int i = 0; i < primitives.size(); i++) {
		Primitive* p = primitives[i];

		Assembly* a = p->getAssembly();

		if (a->getSleepStatus() == Sim::AWAKE) {
			primitiveExtentsChanged(p);
		}
	}
}

// FUNCTION: WEBSERVICE 0x10124030
void SpatialHash::getPrimitivesInGrid(const Vector3int32& grid, G3D::Array<Primitive*>& found)
{
	int hash = getHash(grid);

	SpatialNode* node = nodes[hash];

	while (node != NULL) {
		if (node->gridId == grid) {
			found.append(node->primitive);
		}

		node = node->nextHashLink;
	}
}

// FUNCTION: WEBSERVICE 0x10124100
void SpatialHash::getPrimitivesTouchingExtents(
	const Extents& extents,
	const Primitive* ignore,
	G3D::Array<Primitive*>& answer
)
{
	Vector3int32 min;
	Vector3int32 max;

	computeMinMax(extents, min, max);

	G3D::Array<Primitive*> foundThisGrid;

	for (int i = min.x; i <= max.x; i++) {
		for (int j = min.y; j <= max.y; j++) {
			for (int k = min.z; k <= max.z; k++) {
				foundThisGrid.resize(0, false);

				getPrimitivesInGrid(Vector3int32(i, j, k), foundThisGrid);

				for (int index = 0; index < foundThisGrid.size(); index++) {
					Primitive* p = foundThisGrid[index];

					if (p != ignore && !answer.contains(p) && extents.overlapsOrTouches(p->getFastFuzzyExtents())) {
						answer.append(p);
					}
				}
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x101242e0
SpatialHash::~SpatialHash()
{
	for (unsigned int i = 0; i < numBuckets(); i++) {
		if (nodes[i] != NULL) {
			while (nodes[i] != NULL) {
				SpatialNode* temp = nodes[i];

				nodes[i] = nodes[i]->nextHashLink;

				delete temp;

				nodesOut--;
			}
		}
	}

	while (extraNodes != NULL) {
		SpatialNode* temp = extraNodes;

		extraNodes = temp->nextHashLink;

		delete temp;
	}
}

// FUNCTION: WEBSERVICE 0x10124480
SpatialHash::SpatialHash(World* world, ContactManager* contactManager)
	: world(world), contactManager(contactManager), extraNodes(NULL), nodesOut(0), maxBucket(0)
{
	std::vector<SpatialNode*> temp(numBuckets(), NULL);

	nodes.swap(temp);
}

} // namespace RBX
