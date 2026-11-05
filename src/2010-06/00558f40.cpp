// from server: 100% by auto
// roc 2010-06 00558f40  unit: G3D::BinaryInput  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00558f40
//
// 00558f40  53                   push ebx
// 00558f41  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00558f47  56                   push esi
// 00558f48  8b31                 mov esi, dword ptr [ecx]
// 00558f4a  57                   push edi
// 00558f4b  8b7904               mov edi, dword ptr [ecx + 4]
// 00558f4e  85f6                 test esi, esi
// 00558f50  7517                 jne 0x558f69
// 00558f52  ffd3                 call ebx
// 00558f54  33c0                 xor eax, eax
// 00558f56  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00558f5a  03f9                 add edi, ecx
// 00558f5c  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00558f5f  7713                 ja 0x558f74
// 00558f61  85f6                 test esi, esi
// 00558f63  7408                 je 0x558f6d
// 00558f65  8b06                 mov eax, dword ptr [esi]
// 00558f67  eb06                 jmp 0x558f6f
// 00558f69  8b06                 mov eax, dword ptr [esi]
// 00558f6b  ebe9                 jmp 0x558f56
// 00558f6d  33c0                 xor eax, eax
// 00558f6f  3b780c               cmp edi, dword ptr [eax + 0xc]
// 00558f72  7302                 jae 0x558f76
// 00558f74  ffd3                 call ebx
// 00558f76  8b442410             mov eax, dword ptr [esp + 0x10]
// 00558f7a  897804               mov dword ptr [eax + 4], edi
// 00558f7d  5f                   pop edi
// 00558f7e  8930                 mov dword ptr [eax], esi
// 00558f80  5e                   pop esi
// 00558f81  5b                   pop ebx
// 00558f82  c20800               ret 8
// standard library vector<char> (function ??H?$_Vector_const_iterator@DV?$allocator@D@std@@@std@@QBE?AV01@H@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
