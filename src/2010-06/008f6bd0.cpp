// from server: 100% by auto
// roc 2010-06 008f6bd0  unit: Ogre::RbxMeshPartAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f6bd0
//
// 008f6bd0  51                   push ecx
// 008f6bd1  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f6bd5  c6042400             mov byte ptr [esp], 0
// 008f6bd9  8b0424               mov eax, dword ptr [esp]
// 008f6bdc  50                   push eax
// 008f6bdd  8b442414             mov eax, dword ptr [esp + 0x14]
// 008f6be1  52                   push edx
// 008f6be2  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f6be6  83c108               add ecx, 8
// 008f6be9  51                   push ecx
// 008f6bea  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008f6bee  50                   push eax
// 008f6bef  51                   push ecx
// 008f6bf0  52                   push edx
// 008f6bf1  e8cae0ffff           call 0x8f4cc0
// 008f6bf6  83c41c               add esp, 0x1c
// 008f6bf9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
