// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_rbxgs_check_disconnect_e8dc0a1db41bca06.cpp

// Candidate translation unit (score above; library headers required).
#define private public
#include "util/IRenderable.h"
#undef private
#include "v8tree/Instance.h"

namespace RBX {
namespace Network {

class Replicator : public RBX::Instance {
public:
    char fieldsBeforeDisconnected[0x2d4d - sizeof(RBX::Instance)];
    bool disconnected;
};

} // namespace Network
} // namespace RBX

void checkDisconnect(RBX::Instance* instance)
{
    RBX::Network::Replicator* repl =
        dynamic_cast<RBX::Network::Replicator*>(instance);

    if (repl && repl->disconnected)
        repl->setParent(NULL);
}
