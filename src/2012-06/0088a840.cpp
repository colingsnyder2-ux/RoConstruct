// from server: 100% by Xemicl
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_xemicl_506d64c8cb36e4d8.cpp

// Candidate translation unit (score above; library headers required).
#include "util/object.h"
namespace RBX {
class Instance : public boost::enable_shared_from_this<Instance> {
public:
    virtual ~Instance();
    static void predelete(Instance*);
};
class Created_0088a840 : public Instance {
public:
    Created_0088a840();
    char pad[0x104];
};
template boost::shared_ptr<Created_0088a840> Creatable<Instance>::create<Created_0088a840>();
}
