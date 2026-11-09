// from server: 100% by auto
// roc 2010-06 00659be0  unit: RBX::VKeyframeSequence::?$BoundFuncDesc  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00659be0
//
// 00659be0  51                   push ecx
// 00659be1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00659be5  c6042400             mov byte ptr [esp], 0
// 00659be9  8b0424               mov eax, dword ptr [esp]
// 00659bec  50                   push eax
// 00659bed  8b442414             mov eax, dword ptr [esp + 0x14]
// 00659bf1  52                   push edx
// 00659bf2  8b542410             mov edx, dword ptr [esp + 0x10]
// 00659bf6  83c108               add ecx, 8
// 00659bf9  51                   push ecx
// 00659bfa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00659bfe  50                   push eax
// 00659bff  51                   push ecx
// 00659c00  52                   push edx
// 00659c01  e82aebffff           call 0x658730
// 00659c06  83c41c               add esp, 0x1c
// 00659c09  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
