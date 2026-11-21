// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// std::map<RBX::InstanceHandle, int> members emitted by the CopyVerb unit (00413d70..00414370; the map is the
// clipboard/copy handle-index map, see ClipboardActions.cpp). Identity: registry decorated names.
//   00413d70 _Tree::erase(const_iterator) (765 B, ehhandler 007de842)   00414370 _Tree::_Erase (104 B)
// BLOCKED by core util/Handle.h: it declares `~InstanceHandle(void);` out of line (INFERRED header-gap row), while both
// bodies inline the shared_ptr release (lock xadd -1, vtable +4/+8). Measured with a scratch Handle.h without that
// line: 00413d70, 00414370, 007de842 and ~InstanceHandle / ~pair COMDAT 00600660 EXACT. Drop the guard once the
// util/Handle.h owner removes the declaration.
// Not instantiated here: the other copies (_Lbound 0057c270, insert 0057cc20 / 0057cb30) are COMDAT twins of
// 00496560 / 00498b20 / 00498300, already exact in GuidRegistryConstructor.cpp (registry twin naming).
#ifdef NATIVE_INSTANCEHANDLE_IMPLICIT_DTOR
#include <map>
#include "util/Handle.h"

template std::_Tree<std::_Tmap_traits<RBX::InstanceHandle,int,std::less<RBX::InstanceHandle>,std::allocator<std::pair<RBX::InstanceHandle const ,int> >,0> >::iterator std::_Tree<std::_Tmap_traits<RBX::InstanceHandle,int,std::less<RBX::InstanceHandle>,std::allocator<std::pair<RBX::InstanceHandle const ,int> >,0> >::erase(std::_Tree<std::_Tmap_traits<RBX::InstanceHandle,int,std::less<RBX::InstanceHandle>,std::allocator<std::pair<RBX::InstanceHandle const ,int> >,0> >::const_iterator); // 00413d70
template void std::_Tree<std::_Tmap_traits<RBX::InstanceHandle,int,std::less<RBX::InstanceHandle>,std::allocator<std::pair<RBX::InstanceHandle const ,int> >,0> >::_Erase(std::_Tree<std::_Tmap_traits<RBX::InstanceHandle,int,std::less<RBX::InstanceHandle>,std::allocator<std::pair<RBX::InstanceHandle const ,int> >,0> >::_Nodeptr); // 00414370
#endif
