// from server: 100% by auto
// roc 2010-06 0050aef0  unit: RBX::Network::NetworkOwnerJob  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0050aef0
//
// 0050aef0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0050aef4  ff25d4a69e00         jmp dword ptr [0x9ea6d4]
// standard library vector<string> (function ??$_Destroy@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
