// from server: 100% by auto
// roc 2008-06 004c71b0  unit: RBX::VInstance::?$Association::Item  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c71b0
//
// 004c71b0  8b442404             mov eax, dword ptr [esp + 4]
// 004c71b4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004c71b8  3bc1                 cmp eax, ecx
// 004c71ba  7410                 je 0x4c71cc
// 004c71bc  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004c71c0  d902                 fld dword ptr [edx]
// 004c71c2  83c004               add eax, 4
// 004c71c5  d958fc               fstp dword ptr [eax - 4]
// 004c71c8  3bc1                 cmp eax, ecx
// 004c71ca  75f4                 jne 0x4c71c0
// 004c71cc  c3                   ret 
// standard library vector<float> (function ??$_Fill@PAMM@std@@YAXPAM0ABM@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
