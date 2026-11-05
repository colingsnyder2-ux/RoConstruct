// from server: 100% by auto
// roc 2012-06 00630050  unit: G3D::BinaryInput  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00630050
//
// 00630050  56                   push esi
// 00630051  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00630055  57                   push edi
// 00630056  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0063005a  8bc6                 mov eax, esi
// 0063005c  8bcf                 mov ecx, edi
// 0063005e  85f6                 test esi, esi
// 00630060  7610                 jbe 0x630072
// 00630062  8b542414             mov edx, dword ptr [esp + 0x14]
// 00630066  dd02                 fld qword ptr [edx]
// 00630068  48                   dec eax
// 00630069  dd19                 fstp qword ptr [ecx]
// 0063006b  83c108               add ecx, 8
// 0063006e  85c0                 test eax, eax
// 00630070  77f4                 ja 0x630066
// 00630072  8d04f7               lea eax, [edi + esi*8]
// 00630075  5f                   pop edi
// 00630076  5e                   pop esi
// 00630077  c20c00               ret 0xc
// standard library vector<double> (function ?_Ufill@?$vector@NV?$allocator@N@std@@@std@@IAEPANPANIABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
