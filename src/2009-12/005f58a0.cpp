// from server: 100% by auto
// roc 2009-12 005f58a0  unit: G3D::BinaryInput  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005f58a0
//
// 005f58a0  8b442408             mov eax, dword ptr [esp + 8]
// 005f58a4  8b542404             mov edx, dword ptr [esp + 4]
// 005f58a8  2bc2                 sub eax, edx
// 005f58aa  56                   push esi
// 005f58ab  c1f803               sar eax, 3
// 005f58ae  57                   push edi
// 005f58af  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005f58b3  8d0cc500000000       lea ecx, [eax*8]
// 005f58ba  8d3439               lea esi, [ecx + edi]
// 005f58bd  85c0                 test eax, eax
// 005f58bf  760d                 jbe 0x5f58ce
// 005f58c1  51                   push ecx
// 005f58c2  52                   push edx
// 005f58c3  51                   push ecx
// 005f58c4  57                   push edi
// 005f58c5  ff15c0b79800         call dword ptr [0x98b7c0]
// 005f58cb  83c410               add esp, 0x10
// 005f58ce  5f                   pop edi
// 005f58cf  8bc6                 mov eax, esi
// 005f58d1  5e                   pop esi
// 005f58d2  c20c00               ret 0xc
// standard library vector<double> (function ??$_Ucopy@PAN@?$vector@NV?$allocator@N@std@@@std@@IAEPANPAN00@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
