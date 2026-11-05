// from server: 100% by auto
// roc 2010-06 007a1dd0  unit: W4_D3DFORMAT::?$EnumDesc  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007a1dd0
//
// 007a1dd0  8b542404             mov edx, dword ptr [esp + 4]
// 007a1dd4  83ec10               sub esp, 0x10
// 007a1dd7  53                   push ebx
// 007a1dd8  55                   push ebp
// 007a1dd9  57                   push edi
// 007a1dda  8bf9                 mov edi, ecx
// 007a1ddc  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 007a1ddf  8b4104               mov eax, dword ptr [ecx + 4]
// 007a1de2  80781500             cmp byte ptr [eax + 0x15], 0
// 007a1de6  8bd9                 mov ebx, ecx
// 007a1de8  751a                 jne 0x7a1e04
// 007a1dea  8b0a                 mov ecx, dword ptr [edx]
// 007a1dec  8d642400             lea esp, [esp]
// 007a1df0  39480c               cmp dword ptr [eax + 0xc], ecx
// 007a1df3  7305                 jae 0x7a1dfa
// 007a1df5  8b4008               mov eax, dword ptr [eax + 8]
// 007a1df8  eb04                 jmp 0x7a1dfe
// 007a1dfa  8bd8                 mov ebx, eax
// 007a1dfc  8b00                 mov eax, dword ptr [eax]
// 007a1dfe  80781500             cmp byte ptr [eax + 0x15], 0
// 007a1e02  74ec                 je 0x7a1df0
// 007a1e04  8b4718               mov eax, dword ptr [edi + 0x18]
// 007a1e07  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 007a1e0d  56                   push esi
// 007a1e0e  8b37                 mov esi, dword ptr [edi]
// 007a1e10  89442414             mov dword ptr [esp + 0x14], eax
// 007a1e14  85f6                 test esi, esi
// 007a1e16  7404                 je 0x7a1e1c
// 007a1e18  3bf6                 cmp esi, esi
// 007a1e1a  740c                 je 0x7a1e28
// 007a1e1c  ffd5                 call ebp
// 007a1e1e  8b542424             mov edx, dword ptr [esp + 0x24]
// 007a1e22  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 007a1e28  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 007a1e2c  7407                 je 0x7a1e35
// 007a1e2e  8b0a                 mov ecx, dword ptr [edx]
// 007a1e30  3b4b0c               cmp ecx, dword ptr [ebx + 0xc]
// 007a1e33  7326                 jae 0x7a1e5b
// 007a1e35  8b12                 mov edx, dword ptr [edx]
// 007a1e37  8d442410             lea eax, [esp + 0x10]
// 007a1e3b  50                   push eax
// 007a1e3c  53                   push ebx
// 007a1e3d  56                   push esi
// 007a1e3e  8d4c2424             lea ecx, [esp + 0x24]
// 007a1e42  51                   push ecx
// 007a1e43  8bcf                 mov ecx, edi
// 007a1e45  89542420             mov dword ptr [esp + 0x20], edx
// 007a1e49  c744242400000000     mov dword ptr [esp + 0x24], 0
// 007a1e51  e89afdffff           call 0x7a1bf0
// 007a1e56  8b30                 mov esi, dword ptr [eax]
// 007a1e58  8b5804               mov ebx, dword ptr [eax + 4]
// 007a1e5b  85f6                 test esi, esi
// 007a1e5d  7516                 jne 0x7a1e75
// 007a1e5f  ffd5                 call ebp
// 007a1e61  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 007a1e64  5e                   pop esi
// 007a1e65  7502                 jne 0x7a1e69
// 007a1e67  ffd5                 call ebp
// 007a1e69  5f                   pop edi
// 007a1e6a  5d                   pop ebp
// 007a1e6b  8d4310               lea eax, [ebx + 0x10]
// 007a1e6e  5b                   pop ebx
// 007a1e6f  83c410               add esp, 0x10
// 007a1e72  c20400               ret 4
// 007a1e75  8b36                 mov esi, dword ptr [esi]
// 007a1e77  ebe8                 jmp 0x7a1e61
// standard library map_ptr<ptr> (function ??A?$map@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@@std@@QAEAAPAUT@@ABQAUK@@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
