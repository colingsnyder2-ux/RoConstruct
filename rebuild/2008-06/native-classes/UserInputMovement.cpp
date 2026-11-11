// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// UserInputMovement | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 30d3c1e2 | roc native-status --write
#include "util/UserInputBase.h"
namespace RBX {
bool MovementKeys::any() const
{
    return up || down || left || right || w || s || a || d || space;
}
void UserInputBase::getMovementKeys(MovementKeys& keys) const
{
    keys.up = keyDown(SDLK_UP);
    keys.down = keyDown(SDLK_DOWN);
    keys.left = keyDown(SDLK_LEFT);
    keys.right = keyDown(SDLK_RIGHT);
    keys.w = keyDown(SDLK_w);
    keys.s = keyDown(SDLK_s);
    keys.a = keyDown(SDLK_a);
    keys.d = keyDown(SDLK_d);
    keys.space = keyDown(SDLK_SPACE);
}
}
