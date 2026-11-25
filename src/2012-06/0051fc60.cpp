// from server: 100% by Xemicl
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_xemicl_dcd2e41034e32416.cpp

// Candidate translation unit (score above; library headers required).
#include "util/object.h"
namespace RBX {
class Instance : public boost::enable_shared_from_this<Instance> {
public:
    virtual ~Instance();
    static void predelete(Instance*);
};
class Created_0051fc60 : public Instance {
public:
    Created_0051fc60();
    char pad[0xb0];
};
template boost::shared_ptr<Created_0051fc60> Creatable<Instance>::create<Created_0051fc60>();
}
