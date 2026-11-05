// from server: 100% by auto
// roc 2010-06 0089f7f0  unit: PAVCXTPRibbonTabContextHeader::?$CArray  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089f7f0
//
// 0089f7f0  56                   push esi
// 0089f7f1  8bf1                 mov esi, ecx
// 0089f7f3  e898ffffff           call 0x89f790
// 0089f7f8  8bc6                 mov eax, esi
// 0089f7fa  5e                   pop esi
// 0089f7fb  c3                   ret 
// standard library set<ptr> (function ??Econst_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEAAV012@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
