// from server: 100% by auto
// roc 2007-08 0062ab90  unit: RBX::AssemblyStage  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0062ab90
//
// 0062ab90  56                   push esi
// 0062ab91  8bf1                 mov esi, ecx
// 0062ab93  e8e8fcffff           call 0x62a880
// 0062ab98  8bc6                 mov eax, esi
// 0062ab9a  5e                   pop esi
// 0062ab9b  c3                   ret 
// standard library set<ptr> (function ??Econst_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEAAV012@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
