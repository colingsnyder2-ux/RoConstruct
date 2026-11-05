// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /U_RELEASEASSERT
#include "v8datamodel/Selection.h"
#include "util/Debug.h"
namespace RBX {
Selection::Selection() : selection(std::vector<boost::shared_ptr<Instance> >()) { setName("Selection"); }
Selection::~Selection() { RBXASSERT(size() == 0); }
template boost::shared_ptr<Selection> Creatable<Instance>::create<Selection>();
}
