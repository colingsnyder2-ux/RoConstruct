// from server: 100% by auto
// roc 2011-06 005440a0  unit: G3D::BinaryInput  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005440a0
//
// 005440a0  8b442408             mov eax, dword ptr [esp + 8]
// 005440a4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005440a8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005440ac  2bc1                 sub eax, ecx
// 005440ae  d1f8                 sar eax, 1
// 005440b0  8d0400               lea eax, [eax + eax]
// 005440b3  56                   push esi
// 005440b4  8d3410               lea esi, [eax + edx]
// 005440b7  740d                 je 0x5440c6
// 005440b9  50                   push eax
// 005440ba  51                   push ecx
// 005440bb  50                   push eax
// 005440bc  52                   push edx
// 005440bd  ff15fc09a400         call dword ptr [0xa409fc]
// 005440c3  83c410               add esp, 0x10
// 005440c6  8bc6                 mov eax, esi
// 005440c8  5e                   pop esi
// 005440c9  c20c00               ret 0xc
// standard library vector<short> (function ??$_Ucopy@PAF@?$vector@FV?$allocator@F@std@@@std@@IAEPAFPAF00@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
