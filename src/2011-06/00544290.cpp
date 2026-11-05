// from server: 100% by auto
// roc 2011-06 00544290  unit: G3D::BinaryInput  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00544290
//
// 00544290  56                   push esi
// 00544291  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00544295  57                   push edi
// 00544296  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0054429a  8bc6                 mov eax, esi
// 0054429c  8bcf                 mov ecx, edi
// 0054429e  85f6                 test esi, esi
// 005442a0  7610                 jbe 0x5442b2
// 005442a2  8b542414             mov edx, dword ptr [esp + 0x14]
// 005442a6  d902                 fld dword ptr [edx]
// 005442a8  48                   dec eax
// 005442a9  d919                 fstp dword ptr [ecx]
// 005442ab  83c104               add ecx, 4
// 005442ae  85c0                 test eax, eax
// 005442b0  77f4                 ja 0x5442a6
// 005442b2  8d04b7               lea eax, [edi + esi*4]
// 005442b5  5f                   pop edi
// 005442b6  5e                   pop esi
// 005442b7  c20c00               ret 0xc
// standard library vector<float> (function ?_Ufill@?$vector@MV?$allocator@M@std@@@std@@IAEPAMPAMIABM@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
