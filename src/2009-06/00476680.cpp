// from server: 100% by auto
// roc 2009-06 00476680  unit: Ogre::RbxMeshLoader  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00476680
//
// 00476680  8b442404             mov eax, dword ptr [esp + 4]
// 00476684  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00476688  3bc1                 cmp eax, ecx
// 0047668a  7410                 je 0x47669c
// 0047668c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00476690  d902                 fld dword ptr [edx]
// 00476692  83c004               add eax, 4
// 00476695  d958fc               fstp dword ptr [eax - 4]
// 00476698  3bc1                 cmp eax, ecx
// 0047669a  75f4                 jne 0x476690
// 0047669c  c3                   ret 
// standard library vector<float> (function ??$_Fill@PAMM@std@@YAXPAM0ABM@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
