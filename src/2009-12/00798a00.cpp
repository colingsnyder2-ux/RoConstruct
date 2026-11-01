// from server: 100% by auto
// roc 2009-12 00798a00  unit: lua_exception  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00798a00
//
// 00798a00  51                   push ecx
// 00798a01  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00798a05  8b542410             mov edx, dword ptr [esp + 0x10]
// 00798a09  c6042400             mov byte ptr [esp], 0
// 00798a0d  8b0424               mov eax, dword ptr [esp]
// 00798a10  50                   push eax
// 00798a11  8b442414             mov eax, dword ptr [esp + 0x14]
// 00798a15  51                   push ecx
// 00798a16  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00798a1a  52                   push edx
// 00798a1b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00798a1f  50                   push eax
// 00798a20  51                   push ecx
// 00798a21  52                   push edx
// 00798a22  e809fbffff           call 0x798530
// 00798a27  83c41c               add esp, 0x1c
// 00798a2a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
