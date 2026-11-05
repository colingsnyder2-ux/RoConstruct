// from server: 100% by auto
// roc 2009-12 005f5970  unit: G3D::BinaryInput  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005f5970
//
// 005f5970  56                   push esi
// 005f5971  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005f5975  57                   push edi
// 005f5976  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005f597a  8bc6                 mov eax, esi
// 005f597c  8bcf                 mov ecx, edi
// 005f597e  85f6                 test esi, esi
// 005f5980  7610                 jbe 0x5f5992
// 005f5982  8b542414             mov edx, dword ptr [esp + 0x14]
// 005f5986  dd02                 fld qword ptr [edx]
// 005f5988  48                   dec eax
// 005f5989  dd19                 fstp qword ptr [ecx]
// 005f598b  83c108               add ecx, 8
// 005f598e  85c0                 test eax, eax
// 005f5990  77f4                 ja 0x5f5986
// 005f5992  8d04f7               lea eax, [edi + esi*8]
// 005f5995  5f                   pop edi
// 005f5996  5e                   pop esi
// 005f5997  c20c00               ret 0xc
// standard library vector<double> (function ?_Ufill@?$vector@NV?$allocator@N@std@@@std@@IAEPANPANIABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
