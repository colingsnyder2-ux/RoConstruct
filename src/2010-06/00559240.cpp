// from server: 100% by auto
// roc 2010-06 00559240  unit: G3D::BinaryInput  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559240
//
// 00559240  55                   push ebp
// 00559241  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00559245  57                   push edi
// 00559246  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0055924a  8bc7                 mov eax, edi
// 0055924c  8bcd                 mov ecx, ebp
// 0055924e  85ff                 test edi, edi
// 00559250  7610                 jbe 0x559262
// 00559252  56                   push esi
// 00559253  8b742418             mov esi, dword ptr [esp + 0x18]
// 00559257  8a16                 mov dl, byte ptr [esi]
// 00559259  8811                 mov byte ptr [ecx], dl
// 0055925b  48                   dec eax
// 0055925c  41                   inc ecx
// 0055925d  85c0                 test eax, eax
// 0055925f  77f6                 ja 0x559257
// 00559261  5e                   pop esi
// 00559262  8d042f               lea eax, [edi + ebp]
// 00559265  5f                   pop edi
// 00559266  5d                   pop ebp
// 00559267  c20c00               ret 0xc
// standard library vector<char> (function ?_Ufill@?$vector@DV?$allocator@D@std@@@std@@IAEPADPADIABD@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
