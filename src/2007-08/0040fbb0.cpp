// from server: 100% by auto
// roc 2007-08 0040fbb0  unit: CopyVerb  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040fbb0
//
// 0040fbb0  51                   push ecx
// 0040fbb1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040fbb5  8b542410             mov edx, dword ptr [esp + 0x10]
// 0040fbb9  c6042400             mov byte ptr [esp], 0
// 0040fbbd  8b0424               mov eax, dword ptr [esp]
// 0040fbc0  50                   push eax
// 0040fbc1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040fbc5  51                   push ecx
// 0040fbc6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0040fbca  52                   push edx
// 0040fbcb  8b542414             mov edx, dword ptr [esp + 0x14]
// 0040fbcf  50                   push eax
// 0040fbd0  51                   push ecx
// 0040fbd1  52                   push edx
// 0040fbd2  e8b9fbffff           call 0x40f790
// 0040fbd7  83c41c               add esp, 0x1c
// 0040fbda  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
