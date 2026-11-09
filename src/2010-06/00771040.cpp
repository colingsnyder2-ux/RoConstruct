// from server: 100% by auto
// roc 2010-06 00771040  unit: RBX::ScoreHud  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00771040
//
// 00771040  51                   push ecx
// 00771041  8b542410             mov edx, dword ptr [esp + 0x10]
// 00771045  c6042400             mov byte ptr [esp], 0
// 00771049  8b0424               mov eax, dword ptr [esp]
// 0077104c  50                   push eax
// 0077104d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00771051  52                   push edx
// 00771052  8b542410             mov edx, dword ptr [esp + 0x10]
// 00771056  83c108               add ecx, 8
// 00771059  51                   push ecx
// 0077105a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0077105e  50                   push eax
// 0077105f  51                   push ecx
// 00771060  52                   push edx
// 00771061  e84af1ffff           call 0x7701b0
// 00771066  83c41c               add esp, 0x1c
// 00771069  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
