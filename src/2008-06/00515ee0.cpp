// from server: 100% by auto
// roc 2008-06 00515ee0  unit: G3D::BinaryInput  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00515ee0
//
// 00515ee0  53                   push ebx
// 00515ee1  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00515ee7  56                   push esi
// 00515ee8  8b31                 mov esi, dword ptr [ecx]
// 00515eea  57                   push edi
// 00515eeb  8b7904               mov edi, dword ptr [ecx + 4]
// 00515eee  85f6                 test esi, esi
// 00515ef0  7517                 jne 0x515f09
// 00515ef2  ffd3                 call ebx
// 00515ef4  33c0                 xor eax, eax
// 00515ef6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00515efa  03f9                 add edi, ecx
// 00515efc  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00515eff  7713                 ja 0x515f14
// 00515f01  85f6                 test esi, esi
// 00515f03  7408                 je 0x515f0d
// 00515f05  8b06                 mov eax, dword ptr [esi]
// 00515f07  eb06                 jmp 0x515f0f
// 00515f09  8b06                 mov eax, dword ptr [esi]
// 00515f0b  ebe9                 jmp 0x515ef6
// 00515f0d  33c0                 xor eax, eax
// 00515f0f  3b780c               cmp edi, dword ptr [eax + 0xc]
// 00515f12  7302                 jae 0x515f16
// 00515f14  ffd3                 call ebx
// 00515f16  8b442410             mov eax, dword ptr [esp + 0x10]
// 00515f1a  897804               mov dword ptr [eax + 4], edi
// 00515f1d  5f                   pop edi
// 00515f1e  8930                 mov dword ptr [eax], esi
// 00515f20  5e                   pop esi
// 00515f21  5b                   pop ebx
// 00515f22  c20800               ret 8
// standard library vector<char> (function ??H?$_Vector_const_iterator@DV?$allocator@D@std@@@std@@QBE?AV01@H@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
