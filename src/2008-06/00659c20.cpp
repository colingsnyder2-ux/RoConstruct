// from server: 100% by EspClaude
// from server: 93% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espclaude_616ca69fe8f41437.cpp

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

// exe: grid size is an int global, not a float constant
extern int exHashGrid;

static inline float exHashGridSize() { return (float) exHashGrid; }

static inline Extents exHashGridToRealExtents(const Vector3& hashGrid)
{
	Vector3 high = hashGrid;
	high += Vector3(1.0f, 1.0f, 1.0f);
	return Extents(hashGrid * exHashGridSize(), high * exHashGridSize());
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

	float maxCheck = maxDistance + 2.0f * exHashGridSize();

	float maxDistanceSquared = maxCheck * maxCheck;

	for (int nz = 1; nz <= 3; nz++) {
		for (int i = low.x; i <= high.x; i++) {
			for (int j = low.y; j <= high.y; j++) {
				for (int k = low.z; k <= high.z; k++) {
					if (abs(i) + abs(j) + abs(k) == nz) {
						Vector3 offset((float) i, (float) j, (float) k);

						Extents box = exHashGridToRealExtents(gridF + offset);

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


}

