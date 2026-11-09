// from server: 100% by auto
// roc 2008-06 004dd2b0  unit: RBX::ViewNew::ViewG3D  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dd2b0
//
// 004dd2b0  8b442408             mov eax, dword ptr [esp + 8]
// 004dd2b4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004dd2b8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004dd2bc  2bc1                 sub eax, ecx
// 004dd2be  d1f8                 sar eax, 1
// 004dd2c0  8d0400               lea eax, [eax + eax]
// 004dd2c3  56                   push esi
// 004dd2c4  8d3410               lea esi, [eax + edx]
// 004dd2c7  740d                 je 0x4dd2d6
// 004dd2c9  50                   push eax
// 004dd2ca  51                   push ecx
// 004dd2cb  50                   push eax
// 004dd2cc  52                   push edx
// 004dd2cd  ff1550288000         call dword ptr [0x802850]
// 004dd2d3  83c410               add esp, 0x10
// 004dd2d6  8bc6                 mov eax, esi
// 004dd2d8  5e                   pop esi
// 004dd2d9  c20c00               ret 0xc
// standard library vector<short> (function ??$_Ucopy@PAF@?$vector@FV?$allocator@F@std@@@std@@IAEPAFPAF00@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
