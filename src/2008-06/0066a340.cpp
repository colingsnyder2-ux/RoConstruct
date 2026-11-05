// from server: 100% by auto
// roc 2008-06 0066a340  unit: RBX::TreeStage  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066a340
//
// 0066a340  56                   push esi
// 0066a341  8bf1                 mov esi, ecx
// 0066a343  e828fdffff           call 0x66a070
// 0066a348  8bc6                 mov eax, esi
// 0066a34a  5e                   pop esi
// 0066a34b  c3                   ret 
// standard library set<ptr> (function ??Econst_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEAAV012@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
