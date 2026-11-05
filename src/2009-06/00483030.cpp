// from server: 100% by auto
// roc 2009-06 00483030  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00483030
//
// 00483030  51                   push ecx
// 00483031  8b542410             mov edx, dword ptr [esp + 0x10]
// 00483035  c6042400             mov byte ptr [esp], 0
// 00483039  8b0424               mov eax, dword ptr [esp]
// 0048303c  50                   push eax
// 0048303d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00483041  52                   push edx
// 00483042  8b542410             mov edx, dword ptr [esp + 0x10]
// 00483046  83c108               add ecx, 8
// 00483049  51                   push ecx
// 0048304a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048304e  50                   push eax
// 0048304f  51                   push ecx
// 00483050  52                   push edx
// 00483051  e83afcffff           call 0x482c90
// 00483056  83c41c               add esp, 0x1c
// 00483059  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
