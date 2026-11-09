// from server: 100% by auto
// roc 2010-06 00704710  unit: RBX::Animator  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00704710
//
// 00704710  51                   push ecx
// 00704711  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00704715  8b542410             mov edx, dword ptr [esp + 0x10]
// 00704719  c6042400             mov byte ptr [esp], 0
// 0070471d  8b0424               mov eax, dword ptr [esp]
// 00704720  50                   push eax
// 00704721  8b442414             mov eax, dword ptr [esp + 0x14]
// 00704725  51                   push ecx
// 00704726  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0070472a  52                   push edx
// 0070472b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0070472f  50                   push eax
// 00704730  51                   push ecx
// 00704731  52                   push edx
// 00704732  e839f8ffff           call 0x703f70
// 00704737  83c41c               add esp, 0x1c
// 0070473a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
