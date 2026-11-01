// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espclaude_6ac7ed7f42fe0d8a.cpp

// Candidate translation unit (score above; library headers required).
#include "util/object.h"
namespace RBX {
class Instance : public boost::enable_shared_from_this<Instance> {
public:
    virtual ~Instance();
    static void predelete(Instance*);
};
class ControllerService : public Instance {
public:
    ControllerService();
    char pad[0x84];
};
template boost::shared_ptr<ControllerService> Creatable<Instance>::create<ControllerService>();
}
