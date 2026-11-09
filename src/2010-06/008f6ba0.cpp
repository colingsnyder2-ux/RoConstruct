// from server: 100% by auto
// roc 2010-06 008f6ba0  unit: Ogre::RbxMeshPartAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f6ba0
//
// 008f6ba0  51                   push ecx
// 008f6ba1  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f6ba5  c6042400             mov byte ptr [esp], 0
// 008f6ba9  8b0424               mov eax, dword ptr [esp]
// 008f6bac  50                   push eax
// 008f6bad  8b442414             mov eax, dword ptr [esp + 0x14]
// 008f6bb1  52                   push edx
// 008f6bb2  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f6bb6  83c108               add ecx, 8
// 008f6bb9  51                   push ecx
// 008f6bba  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008f6bbe  50                   push eax
// 008f6bbf  51                   push ecx
// 008f6bc0  52                   push edx
// 008f6bc1  e8ead8ffff           call 0x8f44b0
// 008f6bc6  83c41c               add esp, 0x1c
// 008f6bc9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
