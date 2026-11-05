// from server: 100% by EspClaude
// from server: 58% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lang: cpp
// roc-lib: openrbx-client roc_espclaude_4ede624406d70d8a.cpp

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

	void computeBallPlane(RBX::PairParams& _params);
};

void ExGeoPair::computeBallPlane(RBX::PairParams& _params)
{
	const G3D::Vector3& pos0 = this->body0->position.translation;
	const G3D::CoordinateFrame& coord1 = this->body1->position;
	G3D::Vector3 planePoint = coord1.pointToWorldSpace(*offset1);

	_params.normal = -Math::getWorldNormal(pairData.normalID1, coord1);

	G3D::Vector3 delta = planePoint - pos0;

	G3D::Vector3 toPlane = _params.normal * delta.dot(_params.normal);

	_params.position = pos0 + toPlane;
	_params.length = toPlane.magnitude() - pairData.radius0;
}

}
