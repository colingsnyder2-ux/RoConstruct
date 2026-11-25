// from server: 100% by Xemicl
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_xemicl_b96ce69996944a6f.cpp

// Candidate translation unit (score above; library headers required).
#include "util/object.h"
namespace RBX {
class Instance : public boost::enable_shared_from_this<Instance> {
public:
    virtual ~Instance();
    static void predelete(Instance*);
};
class Created_006d5150 : public Instance {
public:
    Created_006d5150();
    char pad[0xbc];
};
template boost::shared_ptr<Created_006d5150> Creatable<Instance>::create<Created_006d5150>();
}
