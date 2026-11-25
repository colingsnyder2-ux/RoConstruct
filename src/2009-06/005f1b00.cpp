// from server: 100% by Xemicl
// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_xemicl_5044d21c10ef2fec.cpp

// Candidate translation unit (score above; library headers required).
#include "util/object.h"
namespace RBX {
class Instance : public boost::enable_shared_from_this<Instance> {
public:
    virtual ~Instance();
    static void predelete(Instance*);
};
class Team : public Instance {
public:
    Team();
    char pad[0x170];
};
template boost::shared_ptr<Team> Creatable<Instance>::create<Team>();
}
