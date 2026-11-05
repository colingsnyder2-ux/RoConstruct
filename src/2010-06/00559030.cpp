// from server: 100% by auto
// roc 2010-06 00559030  unit: G3D::BinaryInput  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559030
//
// 00559030  8b442404             mov eax, dword ptr [esp + 4]
// 00559034  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00559038  3bc1                 cmp eax, ecx
// 0055903a  7410                 je 0x55904c
// 0055903c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00559040  dd02                 fld qword ptr [edx]
// 00559042  83c008               add eax, 8
// 00559045  dd58f8               fstp qword ptr [eax - 8]
// 00559048  3bc1                 cmp eax, ecx
// 0055904a  75f4                 jne 0x559040
// 0055904c  c3                   ret 
// standard library vector<double> (function ??$_Fill@PANN@std@@YAXPAN0ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
