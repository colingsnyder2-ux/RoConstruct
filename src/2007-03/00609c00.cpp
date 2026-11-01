// from server: 100% by auto
// roc 2007-03 00609c00  unit: seg_00600000  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00609c00
//
// 00609c00  64a100000000         mov eax, dword ptr fs:[0]
// 00609c06  6aff                 push -1
// 00609c08  68926f7500           push 0x756f92
// 00609c0d  50                   push eax
// 00609c0e  64892500000000       mov dword ptr fs:[0], esp
// 00609c15  83ec44               sub esp, 0x44
// 00609c18  57                   push edi
// 00609c19  8bf9                 mov edi, ecx
// 00609c1b  817f0865666606       cmp dword ptr [edi + 8], 0x6666665
// 00609c22  7259                 jb 0x609c7d
// 00609c24  68903f7800           push 0x783f90
// 00609c29  8d4c2408             lea ecx, [esp + 8]
// 00609c2d  ff1578e77700         call dword ptr [0x77e778]
// 00609c33  8d4c2420             lea ecx, [esp + 0x20]
// 00609c37  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00609c3f  ff1560e97700         call dword ptr [0x77e960]
// 00609c45  8d442404             lea eax, [esp + 4]
// 00609c49  50                   push eax
// 00609c4a  8d4c2430             lea ecx, [esp + 0x30]
// 00609c4e  c644245401           mov byte ptr [esp + 0x54], 1
// 00609c53  c7442424383e7800     mov dword ptr [esp + 0x24], 0x783e38
// 00609c5b  ff157ce77700         call dword ptr [0x77e77c]
// 00609c61  6870f78300           push 0x83f770
// 00609c66  8d4c2424             lea ecx, [esp + 0x24]
// 00609c6a  51                   push ecx
// 00609c6b  c644245800           mov byte ptr [esp + 0x58], 0
// 00609c70  c7442428443e7800     mov dword ptr [esp + 0x28], 0x783e44
// 00609c78  e8b1530100           call 0x61f02e
// 00609c7d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00609c81  8b4704               mov eax, dword ptr [edi + 4]
// 00609c84  53                   push ebx
// 00609c85  55                   push ebp
// 00609c86  56                   push esi
// 00609c87  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00609c8b  6a00                 push 0
// 00609c8d  52                   push edx
// 00609c8e  50                   push eax
// 00609c8f  56                   push esi
// 00609c90  50                   push eax
// 00609c91  e8faf9ffff           call 0x609690
// 00609c96  8be8                 mov ebp, eax
// 00609c98  8b4704               mov eax, dword ptr [edi + 4]
// 00609c9b  bb01000000           mov ebx, 1
// 00609ca0  015f08               add dword ptr [edi + 8], ebx
// 00609ca3  3bf0                 cmp esi, eax
// 00609ca5  7510                 jne 0x609cb7
// 00609ca7  896804               mov dword ptr [eax + 4], ebp
// 00609caa  8b4704               mov eax, dword ptr [edi + 4]
// 00609cad  8928                 mov dword ptr [eax], ebp
// 00609caf  8b4f04               mov ecx, dword ptr [edi + 4]
// 00609cb2  896908               mov dword ptr [ecx + 8], ebp
// 00609cb5  eb22                 jmp 0x609cd9
// 00609cb7  807c246800           cmp byte ptr [esp + 0x68], 0
// 00609cbc  740d                 je 0x609ccb
// 00609cbe  892e                 mov dword ptr [esi], ebp
// 00609cc0  8b4704               mov eax, dword ptr [edi + 4]
// 00609cc3  3b30                 cmp esi, dword ptr [eax]
// 00609cc5  7512                 jne 0x609cd9
// 00609cc7  8928                 mov dword ptr [eax], ebp
// 00609cc9  eb0e                 jmp 0x609cd9
// 00609ccb  896e08               mov dword ptr [esi + 8], ebp
// 00609cce  8b4704               mov eax, dword ptr [edi + 4]
// 00609cd1  3b7008               cmp esi, dword ptr [eax + 8]
// 00609cd4  7503                 jne 0x609cd9
// 00609cd6  896808               mov dword ptr [eax + 8], ebp
// 00609cd9  8b5504               mov edx, dword ptr [ebp + 4]
// 00609cdc  807a3400             cmp byte ptr [edx + 0x34], 0
// 00609ce0  8d4504               lea eax, [ebp + 4]
// 00609ce3  8bf5                 mov esi, ebp
// 00609ce5  0f85ea000000         jne 0x609dd5
// 00609ceb  eb03                 jmp 0x609cf0
// 00609ced  8d4900               lea ecx, [ecx]
// 00609cf0  8b08                 mov ecx, dword ptr [eax]
// 00609cf2  8b5104               mov edx, dword ptr [ecx + 4]
// 00609cf5  3b0a                 cmp ecx, dword ptr [edx]
// 00609cf7  7551                 jne 0x609d4a
// 00609cf9  8b5208               mov edx, dword ptr [edx + 8]
// 00609cfc  807a3400             cmp byte ptr [edx + 0x34], 0
// 00609d00  7519                 jne 0x609d1b
// 00609d02  885934               mov byte ptr [ecx + 0x34], bl
// 00609d05  885a34               mov byte ptr [edx + 0x34], bl
// 00609d08  8b10                 mov edx, dword ptr [eax]
// 00609d0a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00609d0d  c6413400             mov byte ptr [ecx + 0x34], 0
// 00609d11  8b10                 mov edx, dword ptr [eax]
// 00609d13  8b7204               mov esi, dword ptr [edx + 4]
// 00609d16  e9aa000000           jmp 0x609dc5
// 00609d1b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00609d1e  750a                 jne 0x609d2a
// 00609d20  8bf1                 mov esi, ecx
// 00609d22  56                   push esi
// 00609d23  8bcf                 mov ecx, edi
// 00609d25  e8d6e3ffff           call 0x608100
// 00609d2a  8b4604               mov eax, dword ptr [esi + 4]
// 00609d2d  885834               mov byte ptr [eax + 0x34], bl
// 00609d30  8b4e04               mov ecx, dword ptr [esi + 4]
// 00609d33  8b5104               mov edx, dword ptr [ecx + 4]
// 00609d36  c6423400             mov byte ptr [edx + 0x34], 0
// 00609d3a  8b4604               mov eax, dword ptr [esi + 4]
// 00609d3d  8b4804               mov ecx, dword ptr [eax + 4]
// 00609d40  51                   push ecx
// 00609d41  8bcf                 mov ecx, edi
// 00609d43  e81839ecff           call 0x4cd660
// 00609d48  eb7b                 jmp 0x609dc5
// 00609d4a  8b12                 mov edx, dword ptr [edx]
// 00609d4c  807a3400             cmp byte ptr [edx + 0x34], 0
// 00609d50  7516                 jne 0x609d68
// 00609d52  885934               mov byte ptr [ecx + 0x34], bl
// 00609d55  885a34               mov byte ptr [edx + 0x34], bl
// 00609d58  8b10                 mov edx, dword ptr [eax]
// 00609d5a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00609d5d  c6413400             mov byte ptr [ecx + 0x34], 0
// 00609d61  8b10                 mov edx, dword ptr [eax]
// 00609d63  8b7204               mov esi, dword ptr [edx + 4]
// 00609d66  eb5d                 jmp 0x609dc5
// 00609d68  3b31                 cmp esi, dword ptr [ecx]
// 00609d6a  750a                 jne 0x609d76
// 00609d6c  8bf1                 mov esi, ecx
// 00609d6e  56                   push esi
// 00609d6f  8bcf                 mov ecx, edi
// 00609d71  e8ea38ecff           call 0x4cd660
// 00609d76  8b4604               mov eax, dword ptr [esi + 4]
// 00609d79  885834               mov byte ptr [eax + 0x34], bl
// 00609d7c  8b4e04               mov ecx, dword ptr [esi + 4]
// 00609d7f  8b5104               mov edx, dword ptr [ecx + 4]
// 00609d82  c6423400             mov byte ptr [edx + 0x34], 0
// 00609d86  8b4604               mov eax, dword ptr [esi + 4]
// 00609d89  8b4004               mov eax, dword ptr [eax + 4]
// 00609d8c  8b4808               mov ecx, dword ptr [eax + 8]
// 00609d8f  8b11                 mov edx, dword ptr [ecx]
// 00609d91  895008               mov dword ptr [eax + 8], edx
// 00609d94  8b11                 mov edx, dword ptr [ecx]
// 00609d96  807a3500             cmp byte ptr [edx + 0x35], 0
// 00609d9a  7503                 jne 0x609d9f
// 00609d9c  894204               mov dword ptr [edx + 4], eax
// 00609d9f  8b5004               mov edx, dword ptr [eax + 4]
// 00609da2  895104               mov dword ptr [ecx + 4], edx
// 00609da5  8b5704               mov edx, dword ptr [edi + 4]
// 00609da8  3b4204               cmp eax, dword ptr [edx + 4]
// 00609dab  7505                 jne 0x609db2
// 00609dad  894a04               mov dword ptr [edx + 4], ecx
// 00609db0  eb0e                 jmp 0x609dc0
// 00609db2  8b5004               mov edx, dword ptr [eax + 4]
// 00609db5  3b02                 cmp eax, dword ptr [edx]
// 00609db7  7504                 jne 0x609dbd
// 00609db9  890a                 mov dword ptr [edx], ecx
// 00609dbb  eb03                 jmp 0x609dc0
// 00609dbd  894a08               mov dword ptr [edx + 8], ecx
// 00609dc0  8901                 mov dword ptr [ecx], eax
// 00609dc2  894804               mov dword ptr [eax + 4], ecx
// 00609dc5  8b4e04               mov ecx, dword ptr [esi + 4]
// 00609dc8  80793400             cmp byte ptr [ecx + 0x34], 0
// 00609dcc  8d4604               lea eax, [esi + 4]
// 00609dcf  0f841bffffff         je 0x609cf0
// 00609dd5  8b5704               mov edx, dword ptr [edi + 4]
// 00609dd8  8b4204               mov eax, dword ptr [edx + 4]
// 00609ddb  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 00609ddf  885834               mov byte ptr [eax + 0x34], bl
// 00609de2  8b442464             mov eax, dword ptr [esp + 0x64]
// 00609de6  5e                   pop esi
// 00609de7  896804               mov dword ptr [eax + 4], ebp
// 00609dea  5d                   pop ebp
// 00609deb  8938                 mov dword ptr [eax], edi
// 00609ded  5b                   pop ebx
// 00609dee  5f                   pop edi
// 00609def  64890d00000000       mov dword ptr fs:[0], ecx
// 00609df6  83c450               add esp, 0x50
// 00609df9  c21000               ret 0x10
// standard library map_int<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
