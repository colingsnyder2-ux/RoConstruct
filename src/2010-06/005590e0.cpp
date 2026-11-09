// from server: 100% by auto
// roc 2010-06 005590e0  unit: G3D::BinaryInput  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005590e0
//
// 005590e0  8b442408             mov eax, dword ptr [esp + 8]
// 005590e4  8b542404             mov edx, dword ptr [esp + 4]
// 005590e8  2bc2                 sub eax, edx
// 005590ea  56                   push esi
// 005590eb  c1f803               sar eax, 3
// 005590ee  57                   push edi
// 005590ef  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005590f3  8d0cc500000000       lea ecx, [eax*8]
// 005590fa  8d3439               lea esi, [ecx + edi]
// 005590fd  85c0                 test eax, eax
// 005590ff  760d                 jbe 0x55910e
// 00559101  51                   push ecx
// 00559102  52                   push edx
// 00559103  51                   push ecx
// 00559104  57                   push edi
// 00559105  ff1580a89e00         call dword ptr [0x9ea880]
// 0055910b  83c410               add esp, 0x10
// 0055910e  5f                   pop edi
// 0055910f  8bc6                 mov eax, esi
// 00559111  5e                   pop esi
// 00559112  c20c00               ret 0xc
// standard library vector<double> (function ??$_Ucopy@PAN@?$vector@NV?$allocator@N@std@@@std@@IAEPANPAN00@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
