// from server: 100% by auto
// roc 2011-06 00544230  unit: G3D::BinaryInput  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00544230
//
// 00544230  55                   push ebp
// 00544231  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00544235  57                   push edi
// 00544236  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0054423a  8bc7                 mov eax, edi
// 0054423c  8bcd                 mov ecx, ebp
// 0054423e  85ff                 test edi, edi
// 00544240  7610                 jbe 0x544252
// 00544242  56                   push esi
// 00544243  8b742418             mov esi, dword ptr [esp + 0x18]
// 00544247  8a16                 mov dl, byte ptr [esi]
// 00544249  8811                 mov byte ptr [ecx], dl
// 0054424b  48                   dec eax
// 0054424c  41                   inc ecx
// 0054424d  85c0                 test eax, eax
// 0054424f  77f6                 ja 0x544247
// 00544251  5e                   pop esi
// 00544252  8d042f               lea eax, [edi + ebp]
// 00544255  5f                   pop edi
// 00544256  5d                   pop ebp
// 00544257  c20c00               ret 0xc
// standard library vector<char> (function ?_Ufill@?$vector@DV?$allocator@D@std@@@std@@IAEPADPADIABD@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
