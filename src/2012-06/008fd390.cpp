// from server: 100% by auto
// roc 2012-06 008fd390  unit: RBX::VAnimationTrackState::?$EventDesc  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008fd390
//
// 008fd390  51                   push ecx
// 008fd391  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008fd395  8b542410             mov edx, dword ptr [esp + 0x10]
// 008fd399  c6042400             mov byte ptr [esp], 0
// 008fd39d  8b0424               mov eax, dword ptr [esp]
// 008fd3a0  50                   push eax
// 008fd3a1  8b442414             mov eax, dword ptr [esp + 0x14]
// 008fd3a5  51                   push ecx
// 008fd3a6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008fd3aa  52                   push edx
// 008fd3ab  8b542414             mov edx, dword ptr [esp + 0x14]
// 008fd3af  50                   push eax
// 008fd3b0  51                   push ecx
// 008fd3b1  52                   push edx
// 008fd3b2  e889fbffff           call 0x8fcf40
// 008fd3b7  83c41c               add esp, 0x1c
// 008fd3ba  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
