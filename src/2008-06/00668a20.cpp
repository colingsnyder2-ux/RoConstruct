// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_trial_91271c88c707ce57.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#include "util/RunningAverage.h"
namespace RBX {
void RunningAverageState::update(const G3D::CoordinateFrame& cofm, float radius)
{
	float weightNew = 1.0f - 0.75f;
	position = 0.75f * position + weightNew * cofm.translation;
	angles = (angles * 0.75f) + (Quaternion(cofm.rotation) * (weightNew * radius));
}
}
