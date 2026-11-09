// from server: 100% by auto
// roc 2008-06 007940e0  unit: PAVCXTPRibbonTabContextHeader::?$CArray  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007940e0
//
// 007940e0  56                   push esi
// 007940e1  8bf1                 mov esi, ecx
// 007940e3  e898ffffff           call 0x794080
// 007940e8  8bc6                 mov eax, esi
// 007940ea  5e                   pop esi
// 007940eb  c3                   ret 
// standard library set<ptr> (function ??Econst_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEAAV012@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
