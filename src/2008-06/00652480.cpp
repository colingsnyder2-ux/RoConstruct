// from server: 100% by auto
// roc 2008-06 00652480  unit: RBX::ScoreHud  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00652480
//
// 00652480  51                   push ecx
// 00652481  8b542410             mov edx, dword ptr [esp + 0x10]
// 00652485  c6042400             mov byte ptr [esp], 0
// 00652489  8b0424               mov eax, dword ptr [esp]
// 0065248c  50                   push eax
// 0065248d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00652491  52                   push edx
// 00652492  8b542410             mov edx, dword ptr [esp + 0x10]
// 00652496  83c108               add ecx, 8
// 00652499  51                   push ecx
// 0065249a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0065249e  50                   push eax
// 0065249f  51                   push ecx
// 006524a0  52                   push edx
// 006524a1  e80af4ffff           call 0x6518b0
// 006524a6  83c41c               add esp, 0x1c
// 006524a9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
