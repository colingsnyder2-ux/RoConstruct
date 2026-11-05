// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_rbx_adorn_state_ctor_5b7c48b8c5421fef.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>

// Re-emitted for server verification after a stale local C1088 temp-file failure.

namespace Ogre {

class RbxAdornState {
public:
    void* renderable;
    bool enabled;
    void* material;
    int operationType;
    ColourValue colour;
    Vector3 offset;

    RbxAdornState();
};

RbxAdornState::RbxAdornState()
{
    renderable = 0;
    enabled = false;
    material = 0;
    operationType = 2;
    colour = ColourValue(-1.0f, -1.0f, -1.0f, -1.0f);
    offset = Vector3(0.0f, 0.0f, 0.0f);
}

}
