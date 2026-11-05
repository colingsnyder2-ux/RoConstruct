// from server: 100% by auto
// roc 2011-06 008f8370  unit: PAVCXTPRibbonTabContextHeader::?$CArray  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f8370
//
// 008f8370  56                   push esi
// 008f8371  8bf1                 mov esi, ecx
// 008f8373  e898ffffff           call 0x8f8310
// 008f8378  8bc6                 mov eax, esi
// 008f837a  5e                   pop esi
// 008f837b  c3                   ret 
// standard library set<ptr> (function ??Econst_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEAAV012@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
