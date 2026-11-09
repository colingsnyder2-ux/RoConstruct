// from server: 100% by auto
// roc 2009-06 0047e420  unit: Ogre::RbxPart  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047e420
//
// 0047e420  51                   push ecx
// 0047e421  8b542410             mov edx, dword ptr [esp + 0x10]
// 0047e425  c6042400             mov byte ptr [esp], 0
// 0047e429  8b0424               mov eax, dword ptr [esp]
// 0047e42c  50                   push eax
// 0047e42d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0047e431  52                   push edx
// 0047e432  8b542410             mov edx, dword ptr [esp + 0x10]
// 0047e436  83c108               add ecx, 8
// 0047e439  51                   push ecx
// 0047e43a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0047e43e  50                   push eax
// 0047e43f  51                   push ecx
// 0047e440  52                   push edx
// 0047e441  e8faf8ffff           call 0x47dd40
// 0047e446  83c41c               add esp, 0x1c
// 0047e449  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
