// from server: 100% by auto
// roc 2008-06 00697ca0  unit: Ogre::RbxSceneManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00697ca0
//
// 00697ca0  51                   push ecx
// 00697ca1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00697ca5  c6042400             mov byte ptr [esp], 0
// 00697ca9  8b0424               mov eax, dword ptr [esp]
// 00697cac  50                   push eax
// 00697cad  8b442414             mov eax, dword ptr [esp + 0x14]
// 00697cb1  52                   push edx
// 00697cb2  8b542410             mov edx, dword ptr [esp + 0x10]
// 00697cb6  83c108               add ecx, 8
// 00697cb9  51                   push ecx
// 00697cba  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00697cbe  50                   push eax
// 00697cbf  51                   push ecx
// 00697cc0  52                   push edx
// 00697cc1  e88a66ffff           call 0x68e350
// 00697cc6  83c41c               add esp, 0x1c
// 00697cc9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
