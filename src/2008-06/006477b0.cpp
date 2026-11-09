// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_trial_d69a357b3323d4b0.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/Block.h"
namespace RBX {
__declspec(noinline) G3D::Matrix3 Block::getMomentHollow(float mass) const
{
	G3D::Vector3 size = gridSize;

	float area = 2 * (size.x * size.y + size.y * size.z + size.z * size.x);
	G3D::Vector3 I;
	for (int i = 0; i < 3; i++) {
		int j = (i + 1) % 3;
		int k = (i + 2) % 3;
		float x = size[i];		// main axis;
		float y = size[j];
		float z = size[k];
		
		float Ix = (mass / (2.0f * area)) * (		(y*y*y*z/3.0f)
												+	(y*z*z*z/3.0f)
												+	(x*y*z*z)
												+	(x*y*y*y/3.0f)
												+	(x*y*y*z)
												+	(x*z*z*z/3.0f)	);
		I[i] = Ix;
	}
	return Math::fromDiagonal(I);
}

	
}