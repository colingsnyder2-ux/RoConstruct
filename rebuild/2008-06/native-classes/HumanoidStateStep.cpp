// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded /I{headers}/engine-world
// Inactive native HumanoidState step/transition (2008-06): 00645450, 006453a0.
#define NATIVE_HUMANOID2008_DONOR_CONNECTOR
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/GameSettings.h"
#include "humanoid/HumanoidState.h"
#include "humanoid/Humanoid2008.h"

namespace RBX {
namespace HUMAN {

// 006453a0 (cdecl): for each event id 0..16 pick the target state (7 when GameSettings funnyPhysics, else the table
// entry, 13 = none); if it differs and canTransition(event) holds, replace the state via the factory and run preStep.
void HumanoidState::transition(std::auto_ptr<HumanoidState>& state, float dt)
{
    int current = state->getStateType();
    for (int i = 0; i < 17; ++i)
    {
        int next;
        if (GameSettings::singleton().funnyPhysics)
            next = 7;
        else
        {
            next = transitionTable[current][i];
            if (next == 13)
                continue;
        }
        if (next != current && state->canTransition(i))
        {
            Humanoid* owner = state->humanoid;
            state.reset();
            HumanoidState* created = create(next, owner);
            state.reset(created);
            created->preStep(dt);
            return;
        }
    }
}

// 00645450 (cdecl)
void HumanoidState::stepState(std::auto_ptr<HumanoidState>& state, float dt, Controller* controller)
{
    state->preStep(dt);
    transition(state, dt);
    state->onStep(dt, controller);
}

}
}
