// from server: 100% by auto
// roc 2012-06 00a57b80  unit: CXTPPropertyGridInplaceEdit  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a57b80
//
// 00a57b80  56                   push esi
// 00a57b81  8bf1                 mov esi, ecx
// 00a57b83  e808ffffff           call 0xa57a90
// 00a57b88  8bc6                 mov eax, esi
// 00a57b8a  5e                   pop esi
// 00a57b8b  c3                   ret 
// standard library set<ptr> (function ??Econst_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEAAV012@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
