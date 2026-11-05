// from server: 100% by auto
// roc 2009-12 00490a40  unit: Ogre::RbxEntity  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00490a40
//
// 00490a40  53                   push ebx
// 00490a41  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 00490a47  56                   push esi
// 00490a48  8b31                 mov esi, dword ptr [ecx]
// 00490a4a  57                   push edi
// 00490a4b  8b7904               mov edi, dword ptr [ecx + 4]
// 00490a4e  85f6                 test esi, esi
// 00490a50  7517                 jne 0x490a69
// 00490a52  ffd3                 call ebx
// 00490a54  33c0                 xor eax, eax
// 00490a56  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00490a5a  03f9                 add edi, ecx
// 00490a5c  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00490a5f  7713                 ja 0x490a74
// 00490a61  85f6                 test esi, esi
// 00490a63  7408                 je 0x490a6d
// 00490a65  8b06                 mov eax, dword ptr [esi]
// 00490a67  eb06                 jmp 0x490a6f
// 00490a69  8b06                 mov eax, dword ptr [esi]
// 00490a6b  ebe9                 jmp 0x490a56
// 00490a6d  33c0                 xor eax, eax
// 00490a6f  3b780c               cmp edi, dword ptr [eax + 0xc]
// 00490a72  7302                 jae 0x490a76
// 00490a74  ffd3                 call ebx
// 00490a76  8b442410             mov eax, dword ptr [esp + 0x10]
// 00490a7a  897804               mov dword ptr [eax + 4], edi
// 00490a7d  5f                   pop edi
// 00490a7e  8930                 mov dword ptr [eax], esi
// 00490a80  5e                   pop esi
// 00490a81  5b                   pop ebx
// 00490a82  c20800               ret 8
// standard library vector<char> (function ??H?$_Vector_const_iterator@DV?$allocator@D@std@@@std@@QBE?AV01@H@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
