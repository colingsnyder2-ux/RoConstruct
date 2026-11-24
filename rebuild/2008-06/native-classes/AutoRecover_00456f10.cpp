// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no Script.h found; Script is declared locally as an Instance subclass.
// INFERRED: the weak_this hookup at +0xe4 comes from Instance's enable_shared_from_this base.
#include <boost/shared_ptr.hpp>
#include "v8tree/Instance.h"

namespace RBX {
class Script : public Instance {};
}

template boost::shared_ptr<RBX::Script>::shared_ptr<RBX::Script, RBX::Creatable<RBX::Instance>::Deleter>(
    RBX::Script*, RBX::Creatable<RBX::Instance>::Deleter);
