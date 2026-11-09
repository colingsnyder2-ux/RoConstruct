// from server: 100% by auto
// roc 2009-06 0080feb0  unit: PAVCXTPRibbonTabContextHeader::?$CArray  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080feb0
//
// 0080feb0  56                   push esi
// 0080feb1  8bf1                 mov esi, ecx
// 0080feb3  e898ffffff           call 0x80fe50
// 0080feb8  8bc6                 mov eax, esi
// 0080feba  5e                   pop esi
// 0080febb  c3                   ret 
// standard library set<ptr> (function ??Econst_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEAAV012@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
