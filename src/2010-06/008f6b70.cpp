// from server: 100% by auto
// roc 2010-06 008f6b70  unit: Ogre::RbxMeshPartAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f6b70
//
// 008f6b70  51                   push ecx
// 008f6b71  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f6b75  c6042400             mov byte ptr [esp], 0
// 008f6b79  8b0424               mov eax, dword ptr [esp]
// 008f6b7c  50                   push eax
// 008f6b7d  8b442414             mov eax, dword ptr [esp + 0x14]
// 008f6b81  52                   push edx
// 008f6b82  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f6b86  83c108               add ecx, 8
// 008f6b89  51                   push ecx
// 008f6b8a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008f6b8e  50                   push eax
// 008f6b8f  51                   push ecx
// 008f6b90  52                   push edx
// 008f6b91  e88ad1ffff           call 0x8f3d20
// 008f6b96  83c41c               add esp, 0x1c
// 008f6b99  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
