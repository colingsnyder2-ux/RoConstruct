// from server: 100% by auto
// roc 2010-06 0053d400  unit: RBX::ImmediateMeshGenAdapter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0053d400
//
// 0053d400  51                   push ecx
// 0053d401  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0053d405  8b542410             mov edx, dword ptr [esp + 0x10]
// 0053d409  c6042400             mov byte ptr [esp], 0
// 0053d40d  8b0424               mov eax, dword ptr [esp]
// 0053d410  50                   push eax
// 0053d411  8b442414             mov eax, dword ptr [esp + 0x14]
// 0053d415  51                   push ecx
// 0053d416  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0053d41a  52                   push edx
// 0053d41b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0053d41f  50                   push eax
// 0053d420  51                   push ecx
// 0053d421  52                   push edx
// 0053d422  e8d9feffff           call 0x53d300
// 0053d427  83c41c               add esp, 0x1c
// 0053d42a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
