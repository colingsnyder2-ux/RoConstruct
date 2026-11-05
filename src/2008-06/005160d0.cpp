// from server: 100% by auto
// roc 2008-06 005160d0  unit: G3D::BinaryInput  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005160d0
//
// 005160d0  55                   push ebp
// 005160d1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 005160d5  57                   push edi
// 005160d6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005160da  8bc7                 mov eax, edi
// 005160dc  8bcd                 mov ecx, ebp
// 005160de  85ff                 test edi, edi
// 005160e0  7610                 jbe 0x5160f2
// 005160e2  56                   push esi
// 005160e3  8b742418             mov esi, dword ptr [esp + 0x18]
// 005160e7  8a16                 mov dl, byte ptr [esi]
// 005160e9  8811                 mov byte ptr [ecx], dl
// 005160eb  48                   dec eax
// 005160ec  41                   inc ecx
// 005160ed  85c0                 test eax, eax
// 005160ef  77f6                 ja 0x5160e7
// 005160f1  5e                   pop esi
// 005160f2  8d042f               lea eax, [edi + ebp]
// 005160f5  5f                   pop edi
// 005160f6  5d                   pop ebp
// 005160f7  c20c00               ret 0xc
// standard library vector<char> (function ?_Ufill@?$vector@DV?$allocator@D@std@@@std@@IAEPADPADIABD@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
