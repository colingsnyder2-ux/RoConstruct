// from server: 100% by auto
// roc 2009-12 004874f0  unit: Ogre::GfxClustererPart  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004874f0
//
// 004874f0  56                   push esi
// 004874f1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004874f5  57                   push edi
// 004874f6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004874fa  8bc6                 mov eax, esi
// 004874fc  8bcf                 mov ecx, edi
// 004874fe  85f6                 test esi, esi
// 00487500  7610                 jbe 0x487512
// 00487502  8b542414             mov edx, dword ptr [esp + 0x14]
// 00487506  d902                 fld dword ptr [edx]
// 00487508  48                   dec eax
// 00487509  d919                 fstp dword ptr [ecx]
// 0048750b  83c104               add ecx, 4
// 0048750e  85c0                 test eax, eax
// 00487510  77f4                 ja 0x487506
// 00487512  8d04b7               lea eax, [edi + esi*4]
// 00487515  5f                   pop edi
// 00487516  5e                   pop esi
// 00487517  c20c00               ret 0xc
// standard library vector<float> (function ?_Ufill@?$vector@MV?$allocator@M@std@@@std@@IAEPAMPAMIABM@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
