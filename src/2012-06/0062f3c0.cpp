// from server: 100% by auto
// roc 2012-06 0062f3c0  unit: G3D::BinaryInput  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062f3c0
//
// 0062f3c0  8b442404             mov eax, dword ptr [esp + 4]
// 0062f3c4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0062f3c8  3bc1                 cmp eax, ecx
// 0062f3ca  7410                 je 0x62f3dc
// 0062f3cc  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0062f3d0  dd02                 fld qword ptr [edx]
// 0062f3d2  83c008               add eax, 8
// 0062f3d5  dd58f8               fstp qword ptr [eax - 8]
// 0062f3d8  3bc1                 cmp eax, ecx
// 0062f3da  75f4                 jne 0x62f3d0
// 0062f3dc  c3                   ret 
// standard library vector<double> (function ??$_Fill@PANN@std@@YAXPAN0ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
