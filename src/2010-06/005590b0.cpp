// from server: 100% by auto
// roc 2010-06 005590b0  unit: G3D::BinaryInput  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005590b0
//
// 005590b0  8b442408             mov eax, dword ptr [esp + 8]
// 005590b4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005590b8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005590bc  2bc1                 sub eax, ecx
// 005590be  d1f8                 sar eax, 1
// 005590c0  8d0400               lea eax, [eax + eax]
// 005590c3  56                   push esi
// 005590c4  8d3410               lea esi, [eax + edx]
// 005590c7  740d                 je 0x5590d6
// 005590c9  50                   push eax
// 005590ca  51                   push ecx
// 005590cb  50                   push eax
// 005590cc  52                   push edx
// 005590cd  ff1580a89e00         call dword ptr [0x9ea880]
// 005590d3  83c410               add esp, 0x10
// 005590d6  8bc6                 mov eax, esi
// 005590d8  5e                   pop esi
// 005590d9  c20c00               ret 0xc
// standard library vector<short> (function ??$_Ucopy@PAF@?$vector@FV?$allocator@F@std@@@std@@IAEPAFPAF00@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
