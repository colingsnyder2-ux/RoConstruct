// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espclaude_6c0177e4c2b4ca2b.cpp

// Candidate translation unit (score above; library headers required).
#include "util/object.h"
namespace RBX {
class Instance : public boost::enable_shared_from_this<Instance> {
public:
    virtual ~Instance();
    static void predelete(Instance*);
};
class DMBase { public: virtual ~DMBase(); char pad[0xf4]; };
class IDataState { public: virtual void setDirty(bool); };
class DataModel : public DMBase, public IDataState { };
class Child : public Instance {
public:
    Child(IDataState* state, bool flag = true);
    char pad[0x2a8 - 0xc];
};
template boost::shared_ptr<Child> Creatable<Instance>::create<Child, DataModel*>(DataModel*);
}
