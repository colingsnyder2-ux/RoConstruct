// from server: 100% by auto
// roc 2010-06 008d3200  unit: Ogre::VisualEngine  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d3200
//
// 008d3200  51                   push ecx
// 008d3201  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d3205  c6042400             mov byte ptr [esp], 0
// 008d3209  8b0424               mov eax, dword ptr [esp]
// 008d320c  50                   push eax
// 008d320d  8b442414             mov eax, dword ptr [esp + 0x14]
// 008d3211  52                   push edx
// 008d3212  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d3216  83c108               add ecx, 8
// 008d3219  51                   push ecx
// 008d321a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008d321e  50                   push eax
// 008d321f  51                   push ecx
// 008d3220  52                   push edx
// 008d3221  e84af6ffff           call 0x8d2870
// 008d3226  83c41c               add esp, 0x1c
// 008d3229  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
