// from server: 100% by auto
// roc 2009-12 004ac790  unit: Ogre::RbxSceneUpdater  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ac790
//
// 004ac790  51                   push ecx
// 004ac791  8b542410             mov edx, dword ptr [esp + 0x10]
// 004ac795  c6042400             mov byte ptr [esp], 0
// 004ac799  8b0424               mov eax, dword ptr [esp]
// 004ac79c  50                   push eax
// 004ac79d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004ac7a1  52                   push edx
// 004ac7a2  8b542410             mov edx, dword ptr [esp + 0x10]
// 004ac7a6  83c108               add ecx, 8
// 004ac7a9  51                   push ecx
// 004ac7aa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004ac7ae  50                   push eax
// 004ac7af  51                   push ecx
// 004ac7b0  52                   push edx
// 004ac7b1  e82afbffff           call 0x4ac2e0
// 004ac7b6  83c41c               add esp, 0x1c
// 004ac7b9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
