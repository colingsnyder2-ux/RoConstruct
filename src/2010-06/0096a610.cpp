// from server: 100% by auto
// roc 2010-06 0096a610  unit: Ogre::RbxSceneUpdater  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096a610
//
// 0096a610  51                   push ecx
// 0096a611  8b542410             mov edx, dword ptr [esp + 0x10]
// 0096a615  c6042400             mov byte ptr [esp], 0
// 0096a619  8b0424               mov eax, dword ptr [esp]
// 0096a61c  50                   push eax
// 0096a61d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0096a621  52                   push edx
// 0096a622  8b542410             mov edx, dword ptr [esp + 0x10]
// 0096a626  83c108               add ecx, 8
// 0096a629  51                   push ecx
// 0096a62a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0096a62e  50                   push eax
// 0096a62f  51                   push ecx
// 0096a630  52                   push edx
// 0096a631  e86afeffff           call 0x96a4a0
// 0096a636  83c41c               add esp, 0x1c
// 0096a639  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
