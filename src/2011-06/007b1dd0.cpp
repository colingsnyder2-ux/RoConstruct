// from server: 100% by auto
// roc 2011-06 007b1dd0  unit: RBX::SleepStage  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007b1dd0
//
// 007b1dd0  56                   push esi
// 007b1dd1  8bf1                 mov esi, ecx
// 007b1dd3  e878dae8ff           call 0x63f850
// 007b1dd8  8bc6                 mov eax, esi
// 007b1dda  5e                   pop esi
// 007b1ddb  c3                   ret 
// standard library set<ptr> (function ??Econst_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEAAV012@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
