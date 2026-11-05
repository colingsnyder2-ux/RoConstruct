// from server: 100% by auto
// roc 2012-06 00417a00  unit: boost::Vbad_weak_ptr::?$error_info_injector  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00417a00
//
// 00417a00  51                   push ecx
// 00417a01  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00417a05  8b542410             mov edx, dword ptr [esp + 0x10]
// 00417a09  c6042400             mov byte ptr [esp], 0
// 00417a0d  8b0424               mov eax, dword ptr [esp]
// 00417a10  50                   push eax
// 00417a11  8b442414             mov eax, dword ptr [esp + 0x14]
// 00417a15  51                   push ecx
// 00417a16  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00417a1a  52                   push edx
// 00417a1b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00417a1f  50                   push eax
// 00417a20  51                   push ecx
// 00417a21  52                   push edx
// 00417a22  e8d9670c00           call 0x4de200
// 00417a27  83c41c               add esp, 0x1c
// 00417a2a  c3                   ret 
// standard library vector<pod12> (function ??$_Unchecked_move_backward@PAUE@@PAU1@@stdext@@YAPAUE@@PAU1@00@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
