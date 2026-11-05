// from server: 100% by auto
// roc 2007-08 006f7140  unit: CXTPPropertyGridInplaceEdit  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006f7140
//
// 006f7140  56                   push esi
// 006f7141  8bf1                 mov esi, ecx
// 006f7143  e818ffffff           call 0x6f7060
// 006f7148  8bc6                 mov eax, esi
// 006f714a  5e                   pop esi
// 006f714b  c3                   ret 
// standard library set<ptr> (function ??Econst_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEAAV012@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
