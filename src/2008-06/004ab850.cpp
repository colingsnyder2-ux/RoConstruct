// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_rbxgs_connection_cleanup_ad778303b8a220fa.cpp

// Candidate translation unit (score above; library headers required).
#define private public
#include "util/IRenderable.h"
#undef private
#include "v8tree/Instance.h"
#include <boost/signals/connection.hpp>

struct ConnectionCleanup {
    char unused0[4];
    RBX::Instance* instance;
    char unused8[4];
    boost::signals::connection first;
    boost::signals::connection second;
    bool detachInstance;
};

void cleanupConnections(ConnectionCleanup* state)
{
    state->first.disconnect();
    state->second.disconnect();

    if (state->detachInstance)
        state->instance->setParent(NULL);
}
