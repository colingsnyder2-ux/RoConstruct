// from server: 100% by auto
// roc 2009-06 0047bfd0  unit: Ogre::RbxSky  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047bfd0
//
// 0047bfd0  d9ee                 fldz 
// 0047bfd2  8b442404             mov eax, dword ptr [esp + 4]
// 0047bfd6  51                   push ecx
// 0047bfd7  d91c24               fstp dword ptr [esp]
// 0047bfda  50                   push eax
// 0047bfdb  e820ffffff           call 0x47bf00
// 0047bfe0  c20400               ret 4
// standard library vector<float> (function ?resize@?$vector@MV?$allocator@M@std@@@std@@QAEXI@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
