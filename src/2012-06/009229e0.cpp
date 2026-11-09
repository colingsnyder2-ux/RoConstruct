// from server: 100% by auto
// roc 2012-06 009229e0  unit: RBX::SleepStage  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009229e0
//
// 009229e0  56                   push esi
// 009229e1  8bf1                 mov esi, ecx
// 009229e3  e8e8efdfff           call 0x7219d0
// 009229e8  8bc6                 mov eax, esi
// 009229ea  5e                   pop esi
// 009229eb  c3                   ret 
// standard library set<ptr> (function ??Econst_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEAAV012@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
