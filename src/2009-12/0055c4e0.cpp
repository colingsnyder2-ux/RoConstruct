// from server: 100% by auto
// roc 2009-12 0055c4e0  unit: RBX::Network::NetworkOwnerJob  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0055c4e0
//
// 0055c4e0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0055c4e4  ff2528b59800         jmp dword ptr [0x98b528]
// standard library vector<string> (function ??$_Destroy@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
