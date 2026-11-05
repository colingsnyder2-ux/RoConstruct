// from server: 100% by auto
// roc 2012-06 0062fec0  unit: G3D::BinaryInput  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062fec0
//
// 0062fec0  8b442408             mov eax, dword ptr [esp + 8]
// 0062fec4  8b542404             mov edx, dword ptr [esp + 4]
// 0062fec8  2bc2                 sub eax, edx
// 0062feca  56                   push esi
// 0062fecb  c1f803               sar eax, 3
// 0062fece  57                   push edi
// 0062fecf  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0062fed3  8d0cc500000000       lea ecx, [eax*8]
// 0062feda  8d3439               lea esi, [ecx + edi]
// 0062fedd  85c0                 test eax, eax
// 0062fedf  760d                 jbe 0x62feee
// 0062fee1  51                   push ecx
// 0062fee2  52                   push edx
// 0062fee3  51                   push ecx
// 0062fee4  57                   push edi
// 0062fee5  ff15c02ab200         call dword ptr [0xb22ac0]
// 0062feeb  83c410               add esp, 0x10
// 0062feee  5f                   pop edi
// 0062feef  8bc6                 mov eax, esi
// 0062fef1  5e                   pop esi
// 0062fef2  c20c00               ret 0xc
// standard library vector<double> (function ??$_Ucopy@PAN@?$vector@NV?$allocator@N@std@@@std@@IAEPANPAN00@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
