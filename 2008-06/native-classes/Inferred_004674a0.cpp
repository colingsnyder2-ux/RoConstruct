// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: RBX::UserInputBase::sub_004674a0 (placeholder name for 004674a0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/UserInputBase.h"

bool RBX::UserInputBase::sub_004674a0()
{
    return keyDown(SDLK_w) ||
           keyDown(SDLK_s) ||
           keyDown(SDLK_a) ||
           keyDown(SDLK_d) ||
           keyDown(SDLK_UP) ||
           keyDown(SDLK_DOWN) ||
           keyDown(SDLK_LEFT) ||
           keyDown(SDLK_RIGHT);
}
