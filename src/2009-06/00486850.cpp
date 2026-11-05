// from server: 100% by auto
// roc 2009-06 00486850  unit: Ogre::RbxMeshPartAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00486850
//
// 00486850  51                   push ecx
// 00486851  8b542410             mov edx, dword ptr [esp + 0x10]
// 00486855  c6042400             mov byte ptr [esp], 0
// 00486859  8b0424               mov eax, dword ptr [esp]
// 0048685c  50                   push eax
// 0048685d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00486861  52                   push edx
// 00486862  8b542410             mov edx, dword ptr [esp + 0x10]
// 00486866  83c108               add ecx, 8
// 00486869  51                   push ecx
// 0048686a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048686e  50                   push eax
// 0048686f  51                   push ecx
// 00486870  52                   push edx
// 00486871  e85af6ffff           call 0x485ed0
// 00486876  83c41c               add esp, 0x1c
// 00486879  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
