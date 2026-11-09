// from server: 100% by auto
// roc 2009-06 00574f40  unit: G3D::BinaryInput  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00574f40
//
// 00574f40  8b442408             mov eax, dword ptr [esp + 8]
// 00574f44  8b542404             mov edx, dword ptr [esp + 4]
// 00574f48  2bc2                 sub eax, edx
// 00574f4a  56                   push esi
// 00574f4b  c1f803               sar eax, 3
// 00574f4e  57                   push edi
// 00574f4f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00574f53  8d0cc500000000       lea ecx, [eax*8]
// 00574f5a  8d3439               lea esi, [ecx + edi]
// 00574f5d  85c0                 test eax, eax
// 00574f5f  760d                 jbe 0x574f6e
// 00574f61  51                   push ecx
// 00574f62  52                   push edx
// 00574f63  51                   push ecx
// 00574f64  57                   push edi
// 00574f65  ff155ce98900         call dword ptr [0x89e95c]
// 00574f6b  83c410               add esp, 0x10
// 00574f6e  5f                   pop edi
// 00574f6f  8bc6                 mov eax, esi
// 00574f71  5e                   pop esi
// 00574f72  c20c00               ret 0xc
// standard library vector<double> (function ??$_Ucopy@PAN@?$vector@NV?$allocator@N@std@@@std@@IAEPANPAN00@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
