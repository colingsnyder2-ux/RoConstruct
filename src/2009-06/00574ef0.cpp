// from server: 100% by auto
// roc 2009-06 00574ef0  unit: G3D::BinaryInput  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00574ef0
//
// 00574ef0  8b442404             mov eax, dword ptr [esp + 4]
// 00574ef4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00574ef8  3bc1                 cmp eax, ecx
// 00574efa  7410                 je 0x574f0c
// 00574efc  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00574f00  dd02                 fld qword ptr [edx]
// 00574f02  83c008               add eax, 8
// 00574f05  dd58f8               fstp qword ptr [eax - 8]
// 00574f08  3bc1                 cmp eax, ecx
// 00574f0a  75f4                 jne 0x574f00
// 00574f0c  c3                   ret 
// standard library vector<double> (function ??$_Fill@PANN@std@@YAXPAN0ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
