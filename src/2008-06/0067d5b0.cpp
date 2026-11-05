// from server: 100% by auto
// roc 2008-06 0067d5b0  unit: Ogre::RbxEntity  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0067d5b0
//
// 0067d5b0  51                   push ecx
// 0067d5b1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0067d5b5  c6042400             mov byte ptr [esp], 0
// 0067d5b9  8b0424               mov eax, dword ptr [esp]
// 0067d5bc  50                   push eax
// 0067d5bd  8b442414             mov eax, dword ptr [esp + 0x14]
// 0067d5c1  52                   push edx
// 0067d5c2  8b542410             mov edx, dword ptr [esp + 0x10]
// 0067d5c6  83c108               add ecx, 8
// 0067d5c9  51                   push ecx
// 0067d5ca  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0067d5ce  50                   push eax
// 0067d5cf  51                   push ecx
// 0067d5d0  52                   push edx
// 0067d5d1  e88ac9fdff           call 0x659f60
// 0067d5d6  83c41c               add esp, 0x1c
// 0067d5d9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
