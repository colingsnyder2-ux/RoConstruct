// from server: 100% by auto
// roc 2008-06 0046d1f0  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046d1f0
//
// 0046d1f0  83ec14               sub esp, 0x14
// 0046d1f3  56                   push esi
// 0046d1f4  8bf1                 mov esi, ecx
// 0046d1f6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0046d1fa  57                   push edi
// 0046d1fb  7521                 jne 0x46d21e
// 0046d1fd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0046d201  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0046d204  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0046d208  50                   push eax
// 0046d209  51                   push ecx
// 0046d20a  6a01                 push 1
// 0046d20c  57                   push edi
// 0046d20d  8bce                 mov ecx, esi
// 0046d20f  e8fcad1f00           call 0x668010
// 0046d214  8bc7                 mov eax, edi
// 0046d216  5f                   pop edi
// 0046d217  5e                   pop esi
// 0046d218  83c414               add esp, 0x14
// 0046d21b  c21000               ret 0x10
// 0046d21e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0046d222  8b5618               mov edx, dword ptr [esi + 0x18]
// 0046d225  8b3a                 mov edi, dword ptr [edx]
// 0046d227  8b06                 mov eax, dword ptr [esi]
// 0046d229  53                   push ebx
// 0046d22a  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0046d230  85c9                 test ecx, ecx
// 0046d232  7404                 je 0x46d238
// 0046d234  3bc8                 cmp ecx, eax
// 0046d236  7406                 je 0x46d23e
// 0046d238  ffd3                 call ebx
// 0046d23a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0046d23e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0046d242  3bc7                 cmp eax, edi
// 0046d244  752a                 jne 0x46d270
// 0046d246  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0046d24a  8b0f                 mov ecx, dword ptr [edi]
// 0046d24c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0046d24f  0f8d4b010000         jge 0x46d3a0
// 0046d255  57                   push edi
// 0046d256  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0046d25a  50                   push eax
// 0046d25b  6a01                 push 1
// 0046d25d  57                   push edi
// 0046d25e  8bce                 mov ecx, esi
// 0046d260  e8abad1f00           call 0x668010
// 0046d265  5b                   pop ebx
// 0046d266  8bc7                 mov eax, edi
// 0046d268  5f                   pop edi
// 0046d269  5e                   pop esi
// 0046d26a  83c414               add esp, 0x14
// 0046d26d  c21000               ret 0x10
// 0046d270  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0046d273  8b16                 mov edx, dword ptr [esi]
// 0046d275  85c9                 test ecx, ecx
// 0046d277  7404                 je 0x46d27d
// 0046d279  3bca                 cmp ecx, edx
// 0046d27b  740a                 je 0x46d287
// 0046d27d  ffd3                 call ebx
// 0046d27f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0046d283  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0046d287  3bc7                 cmp eax, edi
// 0046d289  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0046d28d  752c                 jne 0x46d2bb
// 0046d28f  8b5618               mov edx, dword ptr [esi + 0x18]
// 0046d292  8b4208               mov eax, dword ptr [edx + 8]
// 0046d295  8b480c               mov ecx, dword ptr [eax + 0xc]
// 0046d298  3b0f                 cmp ecx, dword ptr [edi]
// 0046d29a  0f8d00010000         jge 0x46d3a0
// 0046d2a0  57                   push edi
// 0046d2a1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0046d2a5  50                   push eax
// 0046d2a6  6a00                 push 0
// 0046d2a8  57                   push edi
// 0046d2a9  8bce                 mov ecx, esi
// 0046d2ab  e860ad1f00           call 0x668010
// 0046d2b0  5b                   pop ebx
// 0046d2b1  8bc7                 mov eax, edi
// 0046d2b3  5f                   pop edi
// 0046d2b4  5e                   pop esi
// 0046d2b5  83c414               add esp, 0x14
// 0046d2b8  c21000               ret 0x10
// 0046d2bb  8b17                 mov edx, dword ptr [edi]
// 0046d2bd  39500c               cmp dword ptr [eax + 0xc], edx
// 0046d2c0  7e63                 jle 0x46d325
// 0046d2c2  894c240c             mov dword ptr [esp + 0xc], ecx
// 0046d2c6  8d4c240c             lea ecx, [esp + 0xc]
// 0046d2ca  89442410             mov dword ptr [esp + 0x10], eax
// 0046d2ce  e8fdc81900           call 0x609bd0
// 0046d2d3  8b17                 mov edx, dword ptr [edi]
// 0046d2d5  8b442410             mov eax, dword ptr [esp + 0x10]
// 0046d2d9  39500c               cmp dword ptr [eax + 0xc], edx
// 0046d2dc  7d3c                 jge 0x46d31a
// 0046d2de  8b5008               mov edx, dword ptr [eax + 8]
// 0046d2e1  807a1500             cmp byte ptr [edx + 0x15], 0
// 0046d2e5  57                   push edi
// 0046d2e6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0046d2ea  8bce                 mov ecx, esi
// 0046d2ec  7414                 je 0x46d302
// 0046d2ee  50                   push eax
// 0046d2ef  6a00                 push 0
// 0046d2f1  57                   push edi
// 0046d2f2  e819ad1f00           call 0x668010
// 0046d2f7  5b                   pop ebx
// 0046d2f8  8bc7                 mov eax, edi
// 0046d2fa  5f                   pop edi
// 0046d2fb  5e                   pop esi
// 0046d2fc  83c414               add esp, 0x14
// 0046d2ff  c21000               ret 0x10
// 0046d302  8b442430             mov eax, dword ptr [esp + 0x30]
// 0046d306  50                   push eax
// 0046d307  6a01                 push 1
// 0046d309  57                   push edi
// 0046d30a  e801ad1f00           call 0x668010
// 0046d30f  5b                   pop ebx
// 0046d310  8bc7                 mov eax, edi
// 0046d312  5f                   pop edi
// 0046d313  5e                   pop esi
// 0046d314  83c414               add esp, 0x14
// 0046d317  c21000               ret 0x10
// 0046d31a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0046d31e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0046d322  39500c               cmp dword ptr [eax + 0xc], edx
// 0046d325  7d79                 jge 0x46d3a0
// 0046d327  8b16                 mov edx, dword ptr [esi]
// 0046d329  894c240c             mov dword ptr [esp + 0xc], ecx
// 0046d32d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0046d330  894c2418             mov dword ptr [esp + 0x18], ecx
// 0046d334  8d4c240c             lea ecx, [esp + 0xc]
// 0046d338  89442410             mov dword ptr [esp + 0x10], eax
// 0046d33c  89542414             mov dword ptr [esp + 0x14], edx
// 0046d340  e85b0c2200           call 0x68dfa0
// 0046d345  8d442414             lea eax, [esp + 0x14]
// 0046d349  50                   push eax
// 0046d34a  8d4c2410             lea ecx, [esp + 0x10]
// 0046d34e  e84df91700           call 0x5ecca0
// 0046d353  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0046d357  84c0                 test al, al
// 0046d359  7507                 jne 0x46d362
// 0046d35b  8b17                 mov edx, dword ptr [edi]
// 0046d35d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 0046d360  7d3e                 jge 0x46d3a0
// 0046d362  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0046d366  8b5008               mov edx, dword ptr [eax + 8]
// 0046d369  807a1500             cmp byte ptr [edx + 0x15], 0
// 0046d36d  57                   push edi
// 0046d36e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0046d372  7416                 je 0x46d38a
// 0046d374  50                   push eax
// 0046d375  6a00                 push 0
// 0046d377  57                   push edi
// 0046d378  8bce                 mov ecx, esi
// 0046d37a  e891ac1f00           call 0x668010
// 0046d37f  5b                   pop ebx
// 0046d380  8bc7                 mov eax, edi
// 0046d382  5f                   pop edi
// 0046d383  5e                   pop esi
// 0046d384  83c414               add esp, 0x14
// 0046d387  c21000               ret 0x10
// 0046d38a  51                   push ecx
// 0046d38b  6a01                 push 1
// 0046d38d  57                   push edi
// 0046d38e  8bce                 mov ecx, esi
// 0046d390  e87bac1f00           call 0x668010
// 0046d395  5b                   pop ebx
// 0046d396  8bc7                 mov eax, edi
// 0046d398  5f                   pop edi
// 0046d399  5e                   pop esi
// 0046d39a  83c414               add esp, 0x14
// 0046d39d  c21000               ret 0x10
// 0046d3a0  57                   push edi
// 0046d3a1  8d442418             lea eax, [esp + 0x18]
// 0046d3a5  50                   push eax
// 0046d3a6  8bce                 mov ecx, esi
// 0046d3a8  e8f3641400           call 0x5b38a0
// 0046d3ad  8b10                 mov edx, dword ptr [eax]
// 0046d3af  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0046d3b3  5b                   pop ebx
// 0046d3b4  8911                 mov dword ptr [ecx], edx
// 0046d3b6  8b4004               mov eax, dword ptr [eax + 4]
// 0046d3b9  5f                   pop edi
// 0046d3ba  894104               mov dword ptr [ecx + 4], eax
// 0046d3bd  8bc1                 mov eax, ecx
// 0046d3bf  5e                   pop esi
// 0046d3c0  83c414               add esp, 0x14
// 0046d3c3  c21000               ret 0x10
// standard library map_int<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
