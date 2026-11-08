// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /U_RELEASEASSERT
// >>> native-status (generated) -- do not edit >>>
// SelectionLifetime | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src d12bf9f3 | roc native-status --write
#include "v8datamodel/Selection.h"
#include "util/Debug.h"
namespace RBX {
Selection::Selection() : selection(std::vector<boost::shared_ptr<Instance> >()) { setName("Selection"); }
Selection::~Selection() { RBXASSERT(size() == 0); }
template boost::shared_ptr<Selection> Creatable<Instance>::create<Selection>();
}
