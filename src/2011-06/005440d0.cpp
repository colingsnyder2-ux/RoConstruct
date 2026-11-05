// from server: 100% by auto
// roc 2011-06 005440d0  unit: G3D::BinaryInput  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005440d0
//
// 005440d0  8b442408             mov eax, dword ptr [esp + 8]
// 005440d4  8b542404             mov edx, dword ptr [esp + 4]
// 005440d8  2bc2                 sub eax, edx
// 005440da  56                   push esi
// 005440db  c1f803               sar eax, 3
// 005440de  57                   push edi
// 005440df  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005440e3  8d0cc500000000       lea ecx, [eax*8]
// 005440ea  8d3439               lea esi, [ecx + edi]
// 005440ed  85c0                 test eax, eax
// 005440ef  760d                 jbe 0x5440fe
// 005440f1  51                   push ecx
// 005440f2  52                   push edx
// 005440f3  51                   push ecx
// 005440f4  57                   push edi
// 005440f5  ff15fc09a400         call dword ptr [0xa409fc]
// 005440fb  83c410               add esp, 0x10
// 005440fe  5f                   pop edi
// 005440ff  8bc6                 mov eax, esi
// 00544101  5e                   pop esi
// 00544102  c20c00               ret 0xc
// standard library vector<double> (function ??$_Ucopy@PAN@?$vector@NV?$allocator@N@std@@@std@@IAEPANPAN00@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
