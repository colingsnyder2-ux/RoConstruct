// from server: 100% by auto
// roc 2011-06 0066d830  unit: RBX::P8PartInstance::?$GetSetImpl  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0066d830
//
// 0066d830  51                   push ecx
// 0066d831  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0066d835  8b542410             mov edx, dword ptr [esp + 0x10]
// 0066d839  c6042400             mov byte ptr [esp], 0
// 0066d83d  8b0424               mov eax, dword ptr [esp]
// 0066d840  50                   push eax
// 0066d841  8b442414             mov eax, dword ptr [esp + 0x14]
// 0066d845  51                   push ecx
// 0066d846  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0066d84a  52                   push edx
// 0066d84b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0066d84f  50                   push eax
// 0066d850  51                   push ecx
// 0066d851  52                   push edx
// 0066d852  e8d9951400           call 0x7b6e30
// 0066d857  83c41c               add esp, 0x1c
// 0066d85a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
