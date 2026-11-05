// from server: 100% by auto
// roc 2009-12 004b5340  unit: Ogre::RbxMaterialAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b5340
//
// 004b5340  51                   push ecx
// 004b5341  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b5345  c6042400             mov byte ptr [esp], 0
// 004b5349  8b0424               mov eax, dword ptr [esp]
// 004b534c  50                   push eax
// 004b534d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004b5351  52                   push edx
// 004b5352  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b5356  83c108               add ecx, 8
// 004b5359  51                   push ecx
// 004b535a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004b535e  50                   push eax
// 004b535f  51                   push ecx
// 004b5360  52                   push edx
// 004b5361  e85aeeffff           call 0x4b41c0
// 004b5366  83c41c               add esp, 0x1c
// 004b5369  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
