// from server: 100% by auto
// roc 2011-06 006ebda0  unit: VWiniInetRequest_source::?$stream_buffer  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006ebda0
//
// 006ebda0  51                   push ecx
// 006ebda1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006ebda5  8b542410             mov edx, dword ptr [esp + 0x10]
// 006ebda9  c6042400             mov byte ptr [esp], 0
// 006ebdad  8b0424               mov eax, dword ptr [esp]
// 006ebdb0  50                   push eax
// 006ebdb1  8b442414             mov eax, dword ptr [esp + 0x14]
// 006ebdb5  51                   push ecx
// 006ebdb6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006ebdba  52                   push edx
// 006ebdbb  8b542414             mov edx, dword ptr [esp + 0x14]
// 006ebdbf  50                   push eax
// 006ebdc0  51                   push ecx
// 006ebdc1  52                   push edx
// 006ebdc2  e8b9f8ffff           call 0x6eb680
// 006ebdc7  83c41c               add esp, 0x1c
// 006ebdca  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
