// from server: 100% by auto
// roc 2009-12 00485f10  unit: Ogre::GfxClustererPart  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00485f10
//
// 00485f10  8b442404             mov eax, dword ptr [esp + 4]
// 00485f14  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00485f18  3bc1                 cmp eax, ecx
// 00485f1a  7410                 je 0x485f2c
// 00485f1c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00485f20  d902                 fld dword ptr [edx]
// 00485f22  83c004               add eax, 4
// 00485f25  d958fc               fstp dword ptr [eax - 4]
// 00485f28  3bc1                 cmp eax, ecx
// 00485f2a  75f4                 jne 0x485f20
// 00485f2c  c3                   ret 
// standard library vector<float> (function ??$_Fill@PAMM@std@@YAXPAM0ABM@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
