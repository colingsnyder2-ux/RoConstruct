// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/UserInputBase.h"
namespace RBX {
int MovementKeys::any() const
{
    if (up || down || left || right || w || s || a || d || space) return 1;
    return 0;
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
