// from server: 100% by auto
// roc 2010-06 008f6b40  unit: Ogre::RbxMeshPartAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f6b40
//
// 008f6b40  51                   push ecx
// 008f6b41  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f6b45  c6042400             mov byte ptr [esp], 0
// 008f6b49  8b0424               mov eax, dword ptr [esp]
// 008f6b4c  50                   push eax
// 008f6b4d  8b442414             mov eax, dword ptr [esp + 0x14]
// 008f6b51  52                   push edx
// 008f6b52  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f6b56  83c108               add ecx, 8
// 008f6b59  51                   push ecx
// 008f6b5a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008f6b5e  50                   push eax
// 008f6b5f  51                   push ecx
// 008f6b60  52                   push edx
// 008f6b61  e8dacaffff           call 0x8f3640
// 008f6b66  83c41c               add esp, 0x1c
// 008f6b69  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
