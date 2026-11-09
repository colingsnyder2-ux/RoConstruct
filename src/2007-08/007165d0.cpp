// from server: 100% by auto
// roc 2007-08 007165d0  unit: PAVCXTPRibbonTabContextHeader::?$CArray  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 007165d0
//
// 007165d0  56                   push esi
// 007165d1  8bf1                 mov esi, ecx
// 007165d3  e898ffffff           call 0x716570
// 007165d8  8bc6                 mov eax, esi
// 007165da  5e                   pop esi
// 007165db  c3                   ret 
// standard library set<ptr> (function ??Econst_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEAAV012@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
