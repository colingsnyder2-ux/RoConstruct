// from server: 100% by Xemicl
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_xemicl_a3907b4b48a1fee3.cpp

// Candidate translation unit (score above; library headers required).
#include "util/object.h"
namespace RBX {
class Instance : public boost::enable_shared_from_this<Instance> {
public:
    virtual ~Instance();
    static void predelete(Instance*);
};
class Created_0057eb00 : public Instance {
public:
    Created_0057eb00();
    char pad[0xa0];
};
template boost::shared_ptr<Created_0057eb00> Creatable<Instance>::create<Created_0057eb00>();
}
