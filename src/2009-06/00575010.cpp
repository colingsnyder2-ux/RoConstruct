// from server: 100% by auto
// roc 2009-06 00575010  unit: G3D::BinaryInput  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00575010
//
// 00575010  56                   push esi
// 00575011  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00575015  57                   push edi
// 00575016  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0057501a  8bc6                 mov eax, esi
// 0057501c  8bcf                 mov ecx, edi
// 0057501e  85f6                 test esi, esi
// 00575020  7610                 jbe 0x575032
// 00575022  8b542414             mov edx, dword ptr [esp + 0x14]
// 00575026  dd02                 fld qword ptr [edx]
// 00575028  48                   dec eax
// 00575029  dd19                 fstp qword ptr [ecx]
// 0057502b  83c108               add ecx, 8
// 0057502e  85c0                 test eax, eax
// 00575030  77f4                 ja 0x575026
// 00575032  8d04f7               lea eax, [edi + esi*8]
// 00575035  5f                   pop edi
// 00575036  5e                   pop esi
// 00575037  c20c00               ret 0xc
// standard library vector<double> (function ?_Ufill@?$vector@NV?$allocator@N@std@@@std@@IAEPANPANIABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
