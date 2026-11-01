// from server: 100% by auto
// roc 2009-12 006f6c70  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f6c70
//
// 006f6c70  8b542404             mov edx, dword ptr [esp + 4]
// 006f6c74  83ec10               sub esp, 0x10
// 006f6c77  53                   push ebx
// 006f6c78  55                   push ebp
// 006f6c79  57                   push edi
// 006f6c7a  8bf9                 mov edi, ecx
// 006f6c7c  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006f6c7f  8b4104               mov eax, dword ptr [ecx + 4]
// 006f6c82  80781500             cmp byte ptr [eax + 0x15], 0
// 006f6c86  8bd9                 mov ebx, ecx
// 006f6c88  751a                 jne 0x6f6ca4
// 006f6c8a  8b0a                 mov ecx, dword ptr [edx]
// 006f6c8c  8d642400             lea esp, [esp]
// 006f6c90  39480c               cmp dword ptr [eax + 0xc], ecx
// 006f6c93  7d05                 jge 0x6f6c9a
// 006f6c95  8b4008               mov eax, dword ptr [eax + 8]
// 006f6c98  eb04                 jmp 0x6f6c9e
// 006f6c9a  8bd8                 mov ebx, eax
// 006f6c9c  8b00                 mov eax, dword ptr [eax]
// 006f6c9e  80781500             cmp byte ptr [eax + 0x15], 0
// 006f6ca2  74ec                 je 0x6f6c90
// 006f6ca4  8b4718               mov eax, dword ptr [edi + 0x18]
// 006f6ca7  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 006f6cad  56                   push esi
// 006f6cae  8b37                 mov esi, dword ptr [edi]
// 006f6cb0  89442414             mov dword ptr [esp + 0x14], eax
// 006f6cb4  85f6                 test esi, esi
// 006f6cb6  7404                 je 0x6f6cbc
// 006f6cb8  3bf6                 cmp esi, esi
// 006f6cba  740c                 je 0x6f6cc8
// 006f6cbc  ffd5                 call ebp
// 006f6cbe  8b542424             mov edx, dword ptr [esp + 0x24]
// 006f6cc2  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 006f6cc8  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 006f6ccc  7407                 je 0x6f6cd5
// 006f6cce  8b0a                 mov ecx, dword ptr [edx]
// 006f6cd0  3b4b0c               cmp ecx, dword ptr [ebx + 0xc]
// 006f6cd3  7d26                 jge 0x6f6cfb
// 006f6cd5  8b12                 mov edx, dword ptr [edx]
// 006f6cd7  8d442410             lea eax, [esp + 0x10]
// 006f6cdb  50                   push eax
// 006f6cdc  53                   push ebx
// 006f6cdd  56                   push esi
// 006f6cde  8d4c2424             lea ecx, [esp + 0x24]
// 006f6ce2  51                   push ecx
// 006f6ce3  8bcf                 mov ecx, edi
// 006f6ce5  89542420             mov dword ptr [esp + 0x20], edx
// 006f6ce9  c744242400000000     mov dword ptr [esp + 0x24], 0
// 006f6cf1  e88af6ffff           call 0x6f6380
// 006f6cf6  8b30                 mov esi, dword ptr [eax]
// 006f6cf8  8b5804               mov ebx, dword ptr [eax + 4]
// 006f6cfb  85f6                 test esi, esi
// 006f6cfd  7516                 jne 0x6f6d15
// 006f6cff  ffd5                 call ebp
// 006f6d01  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 006f6d04  5e                   pop esi
// 006f6d05  7502                 jne 0x6f6d09
// 006f6d07  ffd5                 call ebp
// 006f6d09  5f                   pop edi
// 006f6d0a  5d                   pop ebp
// 006f6d0b  8d4310               lea eax, [ebx + 0x10]
// 006f6d0e  5b                   pop ebx
// 006f6d0f  83c410               add esp, 0x10
// 006f6d12  c20400               ret 4
// 006f6d15  8b36                 mov esi, dword ptr [esi]
// 006f6d17  ebe8                 jmp 0x6f6d01
// standard library map_int<ptr> (function ??A?$map@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@@std@@QAEAAPAUT@@ABH@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
