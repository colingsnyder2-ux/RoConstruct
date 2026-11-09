// from server: 100% by auto
// roc 2011-06 007e7fb0  unit: RBX::AdvRotateTool  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007e7fb0
//
// 007e7fb0  51                   push ecx
// 007e7fb1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007e7fb5  8b542410             mov edx, dword ptr [esp + 0x10]
// 007e7fb9  c6042400             mov byte ptr [esp], 0
// 007e7fbd  8b0424               mov eax, dword ptr [esp]
// 007e7fc0  50                   push eax
// 007e7fc1  8b442414             mov eax, dword ptr [esp + 0x14]
// 007e7fc5  51                   push ecx
// 007e7fc6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007e7fca  52                   push edx
// 007e7fcb  8b542414             mov edx, dword ptr [esp + 0x14]
// 007e7fcf  50                   push eax
// 007e7fd0  51                   push ecx
// 007e7fd1  52                   push edx
// 007e7fd2  e8e9f8ffff           call 0x7e78c0
// 007e7fd7  83c41c               add esp, 0x1c
// 007e7fda  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
