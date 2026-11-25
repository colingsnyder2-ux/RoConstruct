// from server: 100% by Xemicl
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_xemicl_d5461d4c7bd4d1c0.cpp

// Candidate translation unit (score above; library headers required).
#include "util/object.h"
namespace RBX {
class Instance : public boost::enable_shared_from_this<Instance> {
public:
    virtual ~Instance();
    static void predelete(Instance*);
};
class Created_007789b0 : public Instance {
public:
    Created_007789b0();
    char pad[0xbc];
};
template boost::shared_ptr<Created_007789b0> Creatable<Instance>::create<Created_007789b0>();
}
