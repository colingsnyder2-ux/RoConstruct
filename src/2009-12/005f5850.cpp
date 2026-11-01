// from server: 100% by auto
// roc 2009-12 005f5850  unit: G3D::BinaryInput  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005f5850
//
// 005f5850  8b442404             mov eax, dword ptr [esp + 4]
// 005f5854  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005f5858  3bc1                 cmp eax, ecx
// 005f585a  7410                 je 0x5f586c
// 005f585c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005f5860  dd02                 fld qword ptr [edx]
// 005f5862  83c008               add eax, 8
// 005f5865  dd58f8               fstp qword ptr [eax - 8]
// 005f5868  3bc1                 cmp eax, ecx
// 005f586a  75f4                 jne 0x5f5860
// 005f586c  c3                   ret 
// standard library vector<double> (function ??$_Fill@PANN@std@@YAXPAN0ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
