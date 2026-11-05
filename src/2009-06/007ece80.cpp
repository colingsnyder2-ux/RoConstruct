// from server: 100% by auto
// roc 2009-06 007ece80  unit: CXTPPropertyGridInplaceEdit  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ece80
//
// 007ece80  56                   push esi
// 007ece81  8bf1                 mov esi, ecx
// 007ece83  e808ffffff           call 0x7ecd90
// 007ece88  8bc6                 mov eax, esi
// 007ece8a  5e                   pop esi
// 007ece8b  c3                   ret 
// standard library set<ptr> (function ??Econst_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEAAV012@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
