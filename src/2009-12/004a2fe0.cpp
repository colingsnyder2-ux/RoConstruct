// from server: 100% by auto
// roc 2009-12 004a2fe0  unit: Ogre::RbxMeshPartAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a2fe0
//
// 004a2fe0  51                   push ecx
// 004a2fe1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2fe5  c6042400             mov byte ptr [esp], 0
// 004a2fe9  8b0424               mov eax, dword ptr [esp]
// 004a2fec  50                   push eax
// 004a2fed  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a2ff1  52                   push edx
// 004a2ff2  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2ff6  83c108               add ecx, 8
// 004a2ff9  51                   push ecx
// 004a2ffa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004a2ffe  50                   push eax
// 004a2fff  51                   push ecx
// 004a3000  52                   push edx
// 004a3001  e87ac1ffff           call 0x49f180
// 004a3006  83c41c               add esp, 0x1c
// 004a3009  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
