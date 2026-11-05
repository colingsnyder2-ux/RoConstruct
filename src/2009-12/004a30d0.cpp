// from server: 100% by auto
// roc 2009-12 004a30d0  unit: Ogre::RbxMeshPartAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a30d0
//
// 004a30d0  51                   push ecx
// 004a30d1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a30d5  c6042400             mov byte ptr [esp], 0
// 004a30d9  8b0424               mov eax, dword ptr [esp]
// 004a30dc  50                   push eax
// 004a30dd  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a30e1  52                   push edx
// 004a30e2  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a30e6  83c108               add ecx, 8
// 004a30e9  51                   push ecx
// 004a30ea  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004a30ee  50                   push eax
// 004a30ef  51                   push ecx
// 004a30f0  52                   push edx
// 004a30f1  e86ae6ffff           call 0x4a1760
// 004a30f6  83c41c               add esp, 0x1c
// 004a30f9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
