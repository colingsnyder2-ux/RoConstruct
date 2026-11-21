// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00645450: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "humanoid/HumanoidState.h"
#include "util/Name.h"

namespace RBX {
namespace HUMAN {

void __cdecl HumanoidState::stepState(std::auto_ptr<HumanoidState>& state, float dt, Controller* controller)
{
	state->preStep(dt);
	transition(state, dt);
	state->onStep(dt, controller);
}

}
}
