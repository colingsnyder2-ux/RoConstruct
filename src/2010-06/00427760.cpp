// from server: 100% by auto
// roc 2010-06 00427760  unit: std::D::DU?$char_traits::V?$basic_string::?$holder  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00427760
//
// 00427760  51                   push ecx
// 00427761  8b542410             mov edx, dword ptr [esp + 0x10]
// 00427765  c6042400             mov byte ptr [esp], 0
// 00427769  8b0424               mov eax, dword ptr [esp]
// 0042776c  50                   push eax
// 0042776d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00427771  52                   push edx
// 00427772  8b542410             mov edx, dword ptr [esp + 0x10]
// 00427776  83c108               add ecx, 8
// 00427779  51                   push ecx
// 0042777a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0042777e  50                   push eax
// 0042777f  51                   push ecx
// 00427780  52                   push edx
// 00427781  e89afaffff           call 0x427220
// 00427786  83c41c               add esp, 0x1c
// 00427789  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
