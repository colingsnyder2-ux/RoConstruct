// from server: 100% by auto
// roc 2011-06 005442c0  unit: G3D::BinaryInput  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005442c0
//
// 005442c0  56                   push esi
// 005442c1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005442c5  57                   push edi
// 005442c6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005442ca  8bc6                 mov eax, esi
// 005442cc  8bcf                 mov ecx, edi
// 005442ce  85f6                 test esi, esi
// 005442d0  7610                 jbe 0x5442e2
// 005442d2  8b542414             mov edx, dword ptr [esp + 0x14]
// 005442d6  dd02                 fld qword ptr [edx]
// 005442d8  48                   dec eax
// 005442d9  dd19                 fstp qword ptr [ecx]
// 005442db  83c108               add ecx, 8
// 005442de  85c0                 test eax, eax
// 005442e0  77f4                 ja 0x5442d6
// 005442e2  8d04f7               lea eax, [edi + esi*8]
// 005442e5  5f                   pop edi
// 005442e6  5e                   pop esi
// 005442e7  c20c00               ret 0xc
// standard library vector<double> (function ?_Ufill@?$vector@NV?$allocator@N@std@@@std@@IAEPANPANIABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
