// from server: 100% by auto
// roc 2012-06 00791480  unit: RBX::Soundscape::P8SoundChannel::?$GetSetImpl  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00791480
//
// 00791480  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00791484  ff253c26b200         jmp dword ptr [0xb2263c]
// standard library vector<string> (function ??$_Destroy@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
