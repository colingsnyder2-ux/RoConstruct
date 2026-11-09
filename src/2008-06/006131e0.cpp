// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client roc_claude_ballpoint_2a64f9d79fa7fcbd.cpp

// Candidate translation unit (score above; library headers required).
#include "v8kernel/Pair.h"
#include "decomp.h"
#include "util/Math.h"
#include "util/Velocity.h"
#include <cstddef>

namespace RBX {

struct ExBody {
	char pad[0x94];
	G3D::CoordinateFrame position;  // pv.position at 0x94
};

struct ExGeoPair {
	int field0;                     // 0x00
	const G3D::Vector3* offset0;    // 0x04
	const G3D::Vector3* offset1;    // 0x08
	ExBody* body0;                  // 0x0c
	ExBody* body1;                  // 0x10
	float edgeLength0;              // 0x14
	struct {
		union { NormalId normalID0; float radius0; };
		union { NormalId normalID1; float radiusSum; };
		union { NormalId planeID; int point0ID; };
	} pairData;                     // 0x18

	void computeBallPoint(RBX::PairParams& _params);
};

void ExGeoPair::computeBallPoint(RBX::PairParams& _params)
{
	const G3D::Vector3& pos0 = this->body0->position.translation;
	const G3D::CoordinateFrame& coord1 = this->body1->position;

	_params.position = coord1.pointToWorldSpace(*offset1);
	_params.normal = _params.position - pos0;
	_params.length = _params.normal.unitize() - pairData.radius0;
}

}
