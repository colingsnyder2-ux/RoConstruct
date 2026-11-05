// from server: 100% by auto
// roc 2011-06 00543530  unit: G3D::BinaryInput  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00543530
//
// 00543530  8b442404             mov eax, dword ptr [esp + 4]
// 00543534  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00543538  3bc1                 cmp eax, ecx
// 0054353a  7410                 je 0x54354c
// 0054353c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00543540  d902                 fld dword ptr [edx]
// 00543542  83c004               add eax, 4
// 00543545  d958fc               fstp dword ptr [eax - 4]
// 00543548  3bc1                 cmp eax, ecx
// 0054354a  75f4                 jne 0x543540
// 0054354c  c3                   ret 
// standard library vector<float> (function ??$_Fill@PAMM@std@@YAXPAM0ABM@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
