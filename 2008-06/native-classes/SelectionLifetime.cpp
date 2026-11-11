// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /U_RELEASEASSERT
// >>> native-status (generated) -- do not edit >>>
// SelectionLifetime | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | 1 referenced strings (not rechecked) | by auto (+1) (deepseek:deepseek-chat)
// <<< native-status | src d12bf9f3 | roc native-status --write
#include "v8datamodel/Selection.h"
#include "util/Debug.h"
namespace RBX {
Selection::Selection() : selection(std::vector<boost::shared_ptr<Instance> >()) { setName("Selection"); }
Selection::~Selection() { RBXASSERT(size() == 0); }
template boost::shared_ptr<Selection> Creatable<Instance>::create<Selection>();
}
