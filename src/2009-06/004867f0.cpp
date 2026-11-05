// from server: 100% by auto
// roc 2009-06 004867f0  unit: Ogre::RbxMeshPartAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004867f0
//
// 004867f0  51                   push ecx
// 004867f1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004867f5  c6042400             mov byte ptr [esp], 0
// 004867f9  8b0424               mov eax, dword ptr [esp]
// 004867fc  50                   push eax
// 004867fd  8b442414             mov eax, dword ptr [esp + 0x14]
// 00486801  52                   push edx
// 00486802  8b542410             mov edx, dword ptr [esp + 0x10]
// 00486806  83c108               add ecx, 8
// 00486809  51                   push ecx
// 0048680a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048680e  50                   push eax
// 0048680f  51                   push ecx
// 00486810  52                   push edx
// 00486811  e8fa47ffff           call 0x47b010
// 00486816  83c41c               add esp, 0x1c
// 00486819  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
