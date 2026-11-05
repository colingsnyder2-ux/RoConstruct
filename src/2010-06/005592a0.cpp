// from server: 100% by auto
// roc 2010-06 005592a0  unit: G3D::BinaryInput  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005592a0
//
// 005592a0  56                   push esi
// 005592a1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005592a5  57                   push edi
// 005592a6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005592aa  8bc6                 mov eax, esi
// 005592ac  8bcf                 mov ecx, edi
// 005592ae  85f6                 test esi, esi
// 005592b0  7610                 jbe 0x5592c2
// 005592b2  8b542414             mov edx, dword ptr [esp + 0x14]
// 005592b6  dd02                 fld qword ptr [edx]
// 005592b8  48                   dec eax
// 005592b9  dd19                 fstp qword ptr [ecx]
// 005592bb  83c108               add ecx, 8
// 005592be  85c0                 test eax, eax
// 005592c0  77f4                 ja 0x5592b6
// 005592c2  8d04f7               lea eax, [edi + esi*8]
// 005592c5  5f                   pop edi
// 005592c6  5e                   pop esi
// 005592c7  c20c00               ret 0xc
// standard library vector<double> (function ?_Ufill@?$vector@NV?$allocator@N@std@@@std@@IAEPANPANIABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
