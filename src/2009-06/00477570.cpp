// from server: 100% by auto
// roc 2009-06 00477570  unit: Ogre::RbxMeshLoader  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00477570
//
// 00477570  56                   push esi
// 00477571  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00477575  57                   push edi
// 00477576  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0047757a  8bc6                 mov eax, esi
// 0047757c  8bcf                 mov ecx, edi
// 0047757e  85f6                 test esi, esi
// 00477580  7610                 jbe 0x477592
// 00477582  8b542414             mov edx, dword ptr [esp + 0x14]
// 00477586  d902                 fld dword ptr [edx]
// 00477588  48                   dec eax
// 00477589  d919                 fstp dword ptr [ecx]
// 0047758b  83c104               add ecx, 4
// 0047758e  85c0                 test eax, eax
// 00477590  77f4                 ja 0x477586
// 00477592  8d04b7               lea eax, [edi + esi*4]
// 00477595  5f                   pop edi
// 00477596  5e                   pop esi
// 00477597  c20c00               ret 0xc
// standard library vector<float> (function ?_Ufill@?$vector@MV?$allocator@M@std@@@std@@IAEPAMPAMIABM@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
