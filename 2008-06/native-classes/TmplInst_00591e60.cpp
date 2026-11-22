// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// std::map<std::string, RBX::InstanceHandle> members of the ArchiveBinder::idMap instantiation (v8xml ArchiveBinder,
// 00591e60..00592fd0; caller ArchiveBinder::processID 005930c0 uses operator[]). Identity: registry decorated names.
//   00591e60 _Tree::erase(const_iterator) (724 B)   00592140 _Tree::_Erase (61 B, calls ~pair 00496740 out of line)
//   00592fd0 map::operator[] (233 B)
// BLOCKED by core util/Handle.h: it declares `~InstanceHandle(void);` out of line (INFERRED header-gap row), while the
// client inlines the shared_ptr release (lock xadd -1, vtable +4/+8) inside ~pair 00496740 and ~InstanceHandle
// COMDAT 00600660. Measured with a scratch Handle.h without that line: 00591e60, 00592140, 00592fd0 EXACT, plus
// ~pair 00496740, ~InstanceHandle 00600660 and EH funclets 007c6b40 / 007c6b49 / 007d1d30 / 007d1d38 / 007d1d40.
// With the current header all three are non-exact (control run). Drop the guard once the util/Handle.h owner
// removes the out-of-line ~InstanceHandle declaration.
// Not instantiated here: ~_Tree 005928c0 is byte-identical in 112 B, but the registry size 117 swallows the 5-byte
// ~map tail-jump thunk at 00592930 and the 112-B body is a COMDAT twin of 004146d0 / 004247c0 / ... (registry).
#ifdef NATIVE_INSTANCEHANDLE_IMPLICIT_DTOR
#include <map>
#include <string>
#include "util/Handle.h"

template std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,RBX::InstanceHandle,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,RBX::InstanceHandle> >,0> >::iterator std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,RBX::InstanceHandle,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,RBX::InstanceHandle> >,0> >::erase(std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,RBX::InstanceHandle,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,RBX::InstanceHandle> >,0> >::const_iterator); // 00591e60
template void std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,RBX::InstanceHandle,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,RBX::InstanceHandle> >,0> >::_Erase(std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,RBX::InstanceHandle,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,RBX::InstanceHandle> >,0> >::_Nodeptr); // 00592140
template RBX::InstanceHandle & std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,RBX::InstanceHandle,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,RBX::InstanceHandle> > >::operator[](const std::string &); // 00592fd0
#endif
