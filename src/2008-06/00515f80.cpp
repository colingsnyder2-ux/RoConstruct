// from server: 100% by auto
// roc 2008-06 00515f80  unit: G3D::BinaryInput  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00515f80
//
// 00515f80  8b442408             mov eax, dword ptr [esp + 8]
// 00515f84  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00515f88  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00515f8c  2bc1                 sub eax, ecx
// 00515f8e  56                   push esi
// 00515f8f  8d3410               lea esi, [eax + edx]
// 00515f92  740d                 je 0x515fa1
// 00515f94  50                   push eax
// 00515f95  51                   push ecx
// 00515f96  50                   push eax
// 00515f97  52                   push edx
// 00515f98  ff1550288000         call dword ptr [0x802850]
// 00515f9e  83c410               add esp, 0x10
// 00515fa1  8bc6                 mov eax, esi
// 00515fa3  5e                   pop esi
// 00515fa4  c20c00               ret 0xc
// standard library vector<char> (function ??$_Ucopy@PAD@?$vector@DV?$allocator@D@std@@@std@@IAEPADPAD00@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
