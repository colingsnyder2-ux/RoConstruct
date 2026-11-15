// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /U_RELEASEASSERT
#include "v8datamodel/Selection.h"
#include "util/Debug.h"
namespace RBX {
// 00568180
Selection::Selection() : selection(std::vector<boost::shared_ptr<Instance> >()) { setName("Selection"); }
// 00566f00
Selection::~Selection() { RBXASSERT(size() == 0); }
// create<Selection> 00409620 is instantiated by its owner unit, AppUnit400_2008Creators.cpp.
}
