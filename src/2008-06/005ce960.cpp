// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/util/UserInputBase.cpp

// Candidate translation unit (score above; library headers required).
#include "util/UserInputBase.h"

namespace RBX {

// FUNCTION: WEBSERVICE 0x100d0ec0
void UserInputBase::getNavKeys(NavKeys& navKeys) const
{
	navKeys.forward_arrow = keyDown(SDLK_UP);
	navKeys.backward_arrow = keyDown(SDLK_DOWN);
	navKeys.left_arrow = keyDown(SDLK_LEFT);
	navKeys.right_arrow = keyDown(SDLK_RIGHT);
	navKeys.forward_asdw = keyDown(SDLK_w);
	navKeys.backward_asdw = keyDown(SDLK_s);
	navKeys.left_asdw = keyDown(SDLK_a);
	navKeys.right_asdw = keyDown(SDLK_d);
	navKeys.space = keyDown(SDLK_SPACE);
}

} // namespace RBX
