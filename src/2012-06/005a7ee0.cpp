// from server: 100% by auto
// roc 2012-06 005a7ee0  unit: RBX::Image  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a7ee0
//
// 005a7ee0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005a7ee4  ff25a425b200         jmp dword ptr [0xb225a4]
// standard library vector<string> (function ??$_Destroy@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
