// from server: 100% by auto
// roc 2009-06 00492b20  unit: Ogre::RbxMaterialAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00492b20
//
// 00492b20  51                   push ecx
// 00492b21  8b542410             mov edx, dword ptr [esp + 0x10]
// 00492b25  c6042400             mov byte ptr [esp], 0
// 00492b29  8b0424               mov eax, dword ptr [esp]
// 00492b2c  50                   push eax
// 00492b2d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00492b31  52                   push edx
// 00492b32  8b542410             mov edx, dword ptr [esp + 0x10]
// 00492b36  83c108               add ecx, 8
// 00492b39  51                   push ecx
// 00492b3a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00492b3e  50                   push eax
// 00492b3f  51                   push ecx
// 00492b40  52                   push edx
// 00492b41  e86a9bffff           call 0x48c6b0
// 00492b46  83c41c               add esp, 0x1c
// 00492b49  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
