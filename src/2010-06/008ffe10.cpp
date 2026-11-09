// from server: 100% by auto
// roc 2010-06 008ffe10  unit: Ogre::RbxSceneUpdater  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008ffe10
//
// 008ffe10  51                   push ecx
// 008ffe11  8b542410             mov edx, dword ptr [esp + 0x10]
// 008ffe15  c6042400             mov byte ptr [esp], 0
// 008ffe19  8b0424               mov eax, dword ptr [esp]
// 008ffe1c  50                   push eax
// 008ffe1d  8b442414             mov eax, dword ptr [esp + 0x14]
// 008ffe21  52                   push edx
// 008ffe22  8b542410             mov edx, dword ptr [esp + 0x10]
// 008ffe26  83c108               add ecx, 8
// 008ffe29  51                   push ecx
// 008ffe2a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008ffe2e  50                   push eax
// 008ffe2f  51                   push ecx
// 008ffe30  52                   push edx
// 008ffe31  e82afbffff           call 0x8ff960
// 008ffe36  83c41c               add esp, 0x1c
// 008ffe39  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
