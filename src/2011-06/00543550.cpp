// from server: 100% by auto
// roc 2011-06 00543550  unit: G3D::BinaryInput  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00543550
//
// 00543550  8b442404             mov eax, dword ptr [esp + 4]
// 00543554  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00543558  3bc1                 cmp eax, ecx
// 0054355a  7410                 je 0x54356c
// 0054355c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00543560  dd02                 fld qword ptr [edx]
// 00543562  83c008               add eax, 8
// 00543565  dd58f8               fstp qword ptr [eax - 8]
// 00543568  3bc1                 cmp eax, ecx
// 0054356a  75f4                 jne 0x543560
// 0054356c  c3                   ret 
// standard library vector<double> (function ??$_Fill@PANN@std@@YAXPAN0ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
