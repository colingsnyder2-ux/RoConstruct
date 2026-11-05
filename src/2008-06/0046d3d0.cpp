// from server: 100% by auto
// roc 2008-06 0046d3d0  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046d3d0
//
// 0046d3d0  8b542404             mov edx, dword ptr [esp + 4]
// 0046d3d4  83ec10               sub esp, 0x10
// 0046d3d7  53                   push ebx
// 0046d3d8  55                   push ebp
// 0046d3d9  57                   push edi
// 0046d3da  8bf9                 mov edi, ecx
// 0046d3dc  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0046d3df  8b4104               mov eax, dword ptr [ecx + 4]
// 0046d3e2  80781500             cmp byte ptr [eax + 0x15], 0
// 0046d3e6  8bd9                 mov ebx, ecx
// 0046d3e8  751a                 jne 0x46d404
// 0046d3ea  8b0a                 mov ecx, dword ptr [edx]
// 0046d3ec  8d642400             lea esp, [esp]
// 0046d3f0  39480c               cmp dword ptr [eax + 0xc], ecx
// 0046d3f3  7d05                 jge 0x46d3fa
// 0046d3f5  8b4008               mov eax, dword ptr [eax + 8]
// 0046d3f8  eb04                 jmp 0x46d3fe
// 0046d3fa  8bd8                 mov ebx, eax
// 0046d3fc  8b00                 mov eax, dword ptr [eax]
// 0046d3fe  80781500             cmp byte ptr [eax + 0x15], 0
// 0046d402  74ec                 je 0x46d3f0
// 0046d404  8b4718               mov eax, dword ptr [edi + 0x18]
// 0046d407  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0046d40d  56                   push esi
// 0046d40e  8b37                 mov esi, dword ptr [edi]
// 0046d410  89442414             mov dword ptr [esp + 0x14], eax
// 0046d414  85f6                 test esi, esi
// 0046d416  7404                 je 0x46d41c
// 0046d418  3bf6                 cmp esi, esi
// 0046d41a  740c                 je 0x46d428
// 0046d41c  ffd5                 call ebp
// 0046d41e  8b542424             mov edx, dword ptr [esp + 0x24]
// 0046d422  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0046d428  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 0046d42c  7407                 je 0x46d435
// 0046d42e  8b0a                 mov ecx, dword ptr [edx]
// 0046d430  3b4b0c               cmp ecx, dword ptr [ebx + 0xc]
// 0046d433  7d26                 jge 0x46d45b
// 0046d435  8b12                 mov edx, dword ptr [edx]
// 0046d437  8d442410             lea eax, [esp + 0x10]
// 0046d43b  50                   push eax
// 0046d43c  53                   push ebx
// 0046d43d  56                   push esi
// 0046d43e  8d4c2424             lea ecx, [esp + 0x24]
// 0046d442  51                   push ecx
// 0046d443  8bcf                 mov ecx, edi
// 0046d445  89542420             mov dword ptr [esp + 0x20], edx
// 0046d449  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0046d451  e89afdffff           call 0x46d1f0
// 0046d456  8b30                 mov esi, dword ptr [eax]
// 0046d458  8b5804               mov ebx, dword ptr [eax + 4]
// 0046d45b  85f6                 test esi, esi
// 0046d45d  7516                 jne 0x46d475
// 0046d45f  ffd5                 call ebp
// 0046d461  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 0046d464  5e                   pop esi
// 0046d465  7502                 jne 0x46d469
// 0046d467  ffd5                 call ebp
// 0046d469  5f                   pop edi
// 0046d46a  5d                   pop ebp
// 0046d46b  8d4310               lea eax, [ebx + 0x10]
// 0046d46e  5b                   pop ebx
// 0046d46f  83c410               add esp, 0x10
// 0046d472  c20400               ret 4
// 0046d475  8b36                 mov esi, dword ptr [esi]
// 0046d477  ebe8                 jmp 0x46d461
// standard library map_int<ptr> (function ??A?$map@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@@std@@QAEAAPAUT@@ABH@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
