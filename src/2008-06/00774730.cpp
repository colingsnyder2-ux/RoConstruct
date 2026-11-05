// from server: 100% by auto
// roc 2008-06 00774730  unit: CXTPPropertyGridInplaceEdit  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00774730
//
// 00774730  56                   push esi
// 00774731  8bf1                 mov esi, ecx
// 00774733  e808ffffff           call 0x774640
// 00774738  8bc6                 mov eax, esi
// 0077473a  5e                   pop esi
// 0077473b  c3                   ret 
// standard library set<ptr> (function ??Econst_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEAAV012@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
