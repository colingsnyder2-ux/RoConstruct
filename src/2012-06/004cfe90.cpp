// from server: 100% by auto
// roc 2012-06 004cfe90  unit: Ogre::GfxClustererPart  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004cfe90
//
// 004cfe90  56                   push esi
// 004cfe91  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004cfe95  57                   push edi
// 004cfe96  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004cfe9a  8bc6                 mov eax, esi
// 004cfe9c  8bcf                 mov ecx, edi
// 004cfe9e  85f6                 test esi, esi
// 004cfea0  7610                 jbe 0x4cfeb2
// 004cfea2  8b542414             mov edx, dword ptr [esp + 0x14]
// 004cfea6  d902                 fld dword ptr [edx]
// 004cfea8  48                   dec eax
// 004cfea9  d919                 fstp dword ptr [ecx]
// 004cfeab  83c104               add ecx, 4
// 004cfeae  85c0                 test eax, eax
// 004cfeb0  77f4                 ja 0x4cfea6
// 004cfeb2  8d04b7               lea eax, [edi + esi*4]
// 004cfeb5  5f                   pop edi
// 004cfeb6  5e                   pop esi
// 004cfeb7  c20c00               ret 0xc
// standard library vector<float> (function ?_Ufill@?$vector@MV?$allocator@M@std@@@std@@IAEPAMPAMIABM@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
