// from server: 100% by Xemicl
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_xemicl_cb48d27de82a6287.cpp

// Candidate translation unit (score above; library headers required).
#include "util/object.h"
namespace RBX {
class Instance : public boost::enable_shared_from_this<Instance> {
public:
    virtual ~Instance();
    static void predelete(Instance*);
};
class Created_005259b0 : public Instance {
public:
    Created_005259b0();
    char pad[0xb14];
};
template boost::shared_ptr<Created_005259b0> Creatable<Instance>::create<Created_005259b0>();
}
