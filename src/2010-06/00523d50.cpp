// from server: 100% by auto
// roc 2010-06 00523d50  unit: RBX::MeshGen  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00523d50
//
// 00523d50  8b442404             mov eax, dword ptr [esp + 4]
// 00523d54  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00523d58  3bc1                 cmp eax, ecx
// 00523d5a  7410                 je 0x523d6c
// 00523d5c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00523d60  d902                 fld dword ptr [edx]
// 00523d62  83c004               add eax, 4
// 00523d65  d958fc               fstp dword ptr [eax - 4]
// 00523d68  3bc1                 cmp eax, ecx
// 00523d6a  75f4                 jne 0x523d60
// 00523d6c  c3                   ret 
// standard library vector<float> (function ??$_Fill@PAMM@std@@YAXPAM0ABM@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
