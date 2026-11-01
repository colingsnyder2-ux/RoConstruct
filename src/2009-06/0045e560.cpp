// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espclaude_90c9dcd5b0cc50ab.cpp

// Candidate translation unit (score above; library headers required).
#include "util/object.h"
namespace RBX {
class Instance : public boost::enable_shared_from_this<Instance> {
public:
    virtual ~Instance();
    static void predelete(Instance*);
};
class CRobloxWnd;
class Team : public Instance {
public:
    Team(CRobloxWnd* w);
    char pad[0xe8 - 0xc];
};
template boost::shared_ptr<Team> Creatable<Instance>::create<Team, CRobloxWnd*>(CRobloxWnd*);
}
