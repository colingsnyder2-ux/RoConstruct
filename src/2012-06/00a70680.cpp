// from server: 100% by auto
// roc 2012-06 00a70680  unit: PAVCXTPRibbonTabContextHeader::?$CArray  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a70680
//
// 00a70680  56                   push esi
// 00a70681  8bf1                 mov esi, ecx
// 00a70683  e898ffffff           call 0xa70620
// 00a70688  8bc6                 mov eax, esi
// 00a7068a  5e                   pop esi
// 00a7068b  c3                   ret 
// standard library set<ptr> (function ??Econst_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEAAV012@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
