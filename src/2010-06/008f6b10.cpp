// from server: 100% by auto
// roc 2010-06 008f6b10  unit: Ogre::RbxMeshPartAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f6b10
//
// 008f6b10  51                   push ecx
// 008f6b11  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f6b15  c6042400             mov byte ptr [esp], 0
// 008f6b19  8b0424               mov eax, dword ptr [esp]
// 008f6b1c  50                   push eax
// 008f6b1d  8b442414             mov eax, dword ptr [esp + 0x14]
// 008f6b21  52                   push edx
// 008f6b22  8b542410             mov edx, dword ptr [esp + 0x10]
// 008f6b26  83c108               add ecx, 8
// 008f6b29  51                   push ecx
// 008f6b2a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008f6b2e  50                   push eax
// 008f6b2f  51                   push ecx
// 008f6b30  52                   push edx
// 008f6b31  e86ac3ffff           call 0x8f2ea0
// 008f6b36  83c41c               add esp, 0x1c
// 008f6b39  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
