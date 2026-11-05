// from server: 100% by auto
// roc 2010-06 00525780  unit: RBX::Mesh::Level  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00525780
//
// 00525780  56                   push esi
// 00525781  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00525785  57                   push edi
// 00525786  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0052578a  8bc6                 mov eax, esi
// 0052578c  8bcf                 mov ecx, edi
// 0052578e  85f6                 test esi, esi
// 00525790  7610                 jbe 0x5257a2
// 00525792  8b542414             mov edx, dword ptr [esp + 0x14]
// 00525796  d902                 fld dword ptr [edx]
// 00525798  48                   dec eax
// 00525799  d919                 fstp dword ptr [ecx]
// 0052579b  83c104               add ecx, 4
// 0052579e  85c0                 test eax, eax
// 005257a0  77f4                 ja 0x525796
// 005257a2  8d04b7               lea eax, [edi + esi*4]
// 005257a5  5f                   pop edi
// 005257a6  5e                   pop esi
// 005257a7  c20c00               ret 0xc
// standard library vector<float> (function ?_Ufill@?$vector@MV?$allocator@M@std@@@std@@IAEPAMPAMIABM@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
