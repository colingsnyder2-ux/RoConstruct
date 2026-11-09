// from server: 100% by EspClaude
// from server: 85% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client roc_espclaude_0b9d6cfe49b1f9cd.cpp

// Candidate translation unit (score above; library headers required).
#include "decomp.h"
#include "util/Math.h"
#include <G3D/g3dmath.h>
#include <cmath>
#include <cstddef>

namespace RBX {

struct ExGeometry {
	void* vtbl;
	G3D::Vector3 gridSize;          // 0x04
	const G3D::Vector3& getGridSize() const { return gridSize; }
};

struct ExPrimitive {
	char pad0[0x14];
	unsigned int sizeMultiplier;    // 0x14
	char pad1[0x9c - 0x18];
	ExGeometry* geometry;           // 0x9c
	ExGeometry* getGeometry() const { return geometry; }
	unsigned int getSizeMultiplier() const { return sizeMultiplier; }
};

float getPrimitiveSize(const ExPrimitive* p)
{
	const G3D::Vector3& size = p->getGeometry()->getGridSize();

	float area;
	float other;

	if (size.x < size.y) {
		if (size.x < size.z) {
			area = size.z * size.y;
			goto haveArea;
		}

		other = size.y;
	}
	else {
		other = size.y < size.z ? size.z : size.y;
	}

	area = other * size.x;

haveArea:;

	float gridArea = floor(area);

	return (float) (G3D::iRound(gridArea) * (unsigned __int64) p->getSizeMultiplier());
}

}
