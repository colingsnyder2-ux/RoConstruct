// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: RBX::SleepStage::sub_0064c230 (placeholder name for 0064c230 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "v8world/SleepStage2008.h"

void RBX::SleepStage::sub_0064c230(const std::vector<Joint*>& joints, Sim::EdgeState newState)
{
	for (size_t i = 0; i < joints.size(); ++i) {
		changeContactState(reinterpret_cast<Contact*>(joints[i]), newState);
	}
}
