// from server: 100% by auto
// roc 2009-06 0048a9d0  unit: Ogre::FileStreamDataStream  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048a9d0
//
// 0048a9d0  53                   push ebx
// 0048a9d1  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 0048a9d7  56                   push esi
// 0048a9d8  8b31                 mov esi, dword ptr [ecx]
// 0048a9da  57                   push edi
// 0048a9db  8b7904               mov edi, dword ptr [ecx + 4]
// 0048a9de  85f6                 test esi, esi
// 0048a9e0  7517                 jne 0x48a9f9
// 0048a9e2  ffd3                 call ebx
// 0048a9e4  33c0                 xor eax, eax
// 0048a9e6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0048a9ea  03f9                 add edi, ecx
// 0048a9ec  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0048a9ef  7713                 ja 0x48aa04
// 0048a9f1  85f6                 test esi, esi
// 0048a9f3  7408                 je 0x48a9fd
// 0048a9f5  8b06                 mov eax, dword ptr [esi]
// 0048a9f7  eb06                 jmp 0x48a9ff
// 0048a9f9  8b06                 mov eax, dword ptr [esi]
// 0048a9fb  ebe9                 jmp 0x48a9e6
// 0048a9fd  33c0                 xor eax, eax
// 0048a9ff  3b780c               cmp edi, dword ptr [eax + 0xc]
// 0048aa02  7302                 jae 0x48aa06
// 0048aa04  ffd3                 call ebx
// 0048aa06  8b442410             mov eax, dword ptr [esp + 0x10]
// 0048aa0a  897804               mov dword ptr [eax + 4], edi
// 0048aa0d  5f                   pop edi
// 0048aa0e  8930                 mov dword ptr [eax], esi
// 0048aa10  5e                   pop esi
// 0048aa11  5b                   pop ebx
// 0048aa12  c20800               ret 8
// standard library vector<char> (function ??H?$_Vector_const_iterator@DV?$allocator@D@std@@@std@@QBE?AV01@H@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
