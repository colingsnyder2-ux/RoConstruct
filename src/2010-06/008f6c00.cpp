// from server: 100% by auto
// roc 2010-06 008f6c00  unit: Ogre::RbxMeshPartAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f6c00
//
// 008f6c00  51                   push ecx
// 008f6c01  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f6c05  c6042400             mov byte ptr [esp], 0
// 008f6c09  8b0424               mov eax, dword ptr [esp]
// 008f6c0c  50                   push eax
// 008f6c0d  8b442414             mov eax, dword ptr [esp + 0x14]
// 008f6c11  52                   push edx
// 008f6c12  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f6c16  83c108               add ecx, 8
// 008f6c19  51                   push ecx
// 008f6c1a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008f6c1e  50                   push eax
// 008f6c1f  51                   push ecx
// 008f6c20  52                   push edx
// 008f6c21  e89ae8ffff           call 0x8f54c0
// 008f6c26  83c41c               add esp, 0x1c
// 008f6c29  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
