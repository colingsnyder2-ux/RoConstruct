// from server: 100% by auto
// roc 2009-12 0058b110  unit: RBX::BeveledBlockBuilder  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0058b110
//
// 0058b110  51                   push ecx
// 0058b111  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0058b115  8b542410             mov edx, dword ptr [esp + 0x10]
// 0058b119  c6042400             mov byte ptr [esp], 0
// 0058b11d  8b0424               mov eax, dword ptr [esp]
// 0058b120  50                   push eax
// 0058b121  8b442414             mov eax, dword ptr [esp + 0x14]
// 0058b125  51                   push ecx
// 0058b126  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0058b12a  52                   push edx
// 0058b12b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0058b12f  50                   push eax
// 0058b130  51                   push ecx
// 0058b131  52                   push edx
// 0058b132  e879feffff           call 0x58afb0
// 0058b137  83c41c               add esp, 0x1c
// 0058b13a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
