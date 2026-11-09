// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_claudeB_touchext_682448307d062d42.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/Primitive.h"
#include "decomp.h"
#include "util/Extents.h"
#include "util/Vector3int32.h"
#include <G3D/Array.h>
#include <vector>
#include <cstddef>

namespace RBX {

struct ExBucket {
	void* head;
	int count;
};

struct ExBucketVector {
	ExBucket* first;
	ExBucket* last;
	ExBucket* end;

	unsigned int size() const { return last - first; }
};

struct ExLevel {
	int field0;
	int field4;
	int field8;
	ExBucketVector nodes;           // 0x0c
};

extern int exNumLevels;
int exToGrid(float, int);
void exOnGrid(int, int, G3D::Array<Primitive*>&);

// exe inlines Extents::overlapsOrTouches here
static inline bool exOverlapsOrTouches(const Extents& self, const Extents& other)
{
	const Vector3& low = self.min();
	const Vector3& high = self.max();

	if (!(low.x > other.max().x) && !(low.y > other.max().y) && !(low.z > other.max().z) && !(high.y < other.min().y) &&
		!(high.x < other.min().x) && !(high.z < other.min().z)) {
		return true;
	}

	return false;
}

class ExSpatialHash {
public:
	char pad[0x0c];
	ExLevel levels[4];              // 0x0c

	static void computeMinMax(int level, const Extents& extents, Vector3int32& min, Vector3int32& max);
	void getPrimitivesInGrid(int level, const Vector3int32& grid, G3D::Array<Primitive*>& found);
	void getPrimitivesTouchingExtents(const Extents& extents, const Primitive* ignore, G3D::Array<Primitive*>& answer);
};

__declspec(noinline) void ExSpatialHash::computeMinMax(int level, const Extents& extents, Vector3int32& min, Vector3int32& max)
{
	min.x = exToGrid(extents.min().x, level); min.y = exToGrid(extents.min().y, level); min.z = exToGrid(extents.min().z, level);
	max.x = exToGrid(extents.max().x, level); max.y = exToGrid(extents.max().y, level); max.z = exToGrid(extents.max().z, level);
}

__declspec(noinline) void ExSpatialHash::getPrimitivesInGrid(int level, const Vector3int32& grid, G3D::Array<Primitive*>& found)
{
	exOnGrid(level, grid.x ^ grid.y ^ grid.z, found);
}

void ExSpatialHash::getPrimitivesTouchingExtents(
	const Extents& extents,
	const Primitive* ignore,
	G3D::Array<Primitive*>& answer
)
{
	Vector3int32 min;
	Vector3int32 max;
	G3D::Array<Primitive*> foundThisGrid;

	for (int level = 0; level < exNumLevels; level++) {
		if (levels[level].nodes.size() != 0) {
			computeMinMax(level, extents, min, max);

			for (int i = min.x; i <= max.x; i++) {
				for (int j = min.y; j <= max.y; j++) {
					for (int k = min.z; k <= max.z; k++) {
						foundThisGrid.resize(0, false);

						getPrimitivesInGrid(level, Vector3int32(i, j, k), foundThisGrid);

						for (int index = 0; index < foundThisGrid.size(); index++) {
							Primitive* p = foundThisGrid[index];

							if (p != ignore && !answer.contains(p) && exOverlapsOrTouches(extents, p->getFastFuzzyExtents())) {
								answer.append(p);
							}
						}
					}
				}
			}
		}
	}
}

}
