// from server: 100% by auto
// roc 2009-06 00492b50  unit: Ogre::RbxMaterialAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00492b50
//
// 00492b50  51                   push ecx
// 00492b51  8b542410             mov edx, dword ptr [esp + 0x10]
// 00492b55  c6042400             mov byte ptr [esp], 0
// 00492b59  8b0424               mov eax, dword ptr [esp]
// 00492b5c  50                   push eax
// 00492b5d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00492b61  52                   push edx
// 00492b62  8b542410             mov edx, dword ptr [esp + 0x10]
// 00492b66  83c108               add ecx, 8
// 00492b69  51                   push ecx
// 00492b6a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00492b6e  50                   push eax
// 00492b6f  51                   push ecx
// 00492b70  52                   push edx
// 00492b71  e88aeeffff           call 0x491a00
// 00492b76  83c41c               add esp, 0x1c
// 00492b79  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
