// from server: 100% by auto
// roc 2010-06 0087bba0  unit: CXTPPropertyGridInplaceEdit  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0087bba0
//
// 0087bba0  56                   push esi
// 0087bba1  8bf1                 mov esi, ecx
// 0087bba3  e808ffffff           call 0x87bab0
// 0087bba8  8bc6                 mov eax, esi
// 0087bbaa  5e                   pop esi
// 0087bbab  c3                   ret 
// standard library set<ptr> (function ??Econst_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEAAV012@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
