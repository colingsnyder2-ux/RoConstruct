// from server: 100% by auto
// roc 2012-06 004cd340  unit: Ogre::GfxClustererPart  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004cd340
//
// 004cd340  8b442404             mov eax, dword ptr [esp + 4]
// 004cd344  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004cd348  3bc1                 cmp eax, ecx
// 004cd34a  7410                 je 0x4cd35c
// 004cd34c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004cd350  d902                 fld dword ptr [edx]
// 004cd352  83c004               add eax, 4
// 004cd355  d958fc               fstp dword ptr [eax - 4]
// 004cd358  3bc1                 cmp eax, ecx
// 004cd35a  75f4                 jne 0x4cd350
// 004cd35c  c3                   ret 
// standard library vector<float> (function ??$_Fill@PAMM@std@@YAXPAM0ABM@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
