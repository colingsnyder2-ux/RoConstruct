// from server: 100% by auto
// roc 2011-06 008df880  unit: CXTPPropertyGridInplaceEdit  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008df880
//
// 008df880  56                   push esi
// 008df881  8bf1                 mov esi, ecx
// 008df883  e808ffffff           call 0x8df790
// 008df888  8bc6                 mov eax, esi
// 008df88a  5e                   pop esi
// 008df88b  c3                   ret 
// standard library set<ptr> (function ??Econst_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEAAV012@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
