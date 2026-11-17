// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: RBX::SleepStage::sub_0064b840 (placeholder name for 0064b840 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "v8world/SleepStage2008.h"

void RBX::SleepStage::sub_0064b840(const std::vector<Joint*>& joints, Sim::EdgeState state)
{
	for (size_t i = 0; i < joints.size(); ++i) {
		changeJointState(joints[i], state);
	}
}
