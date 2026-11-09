// from server: 100% by auto
// roc 2008-06 00670850  unit: Ogre::VRbxFont::?$SharedPtr  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00670850
//
// 00670850  64a100000000         mov eax, dword ptr fs:[0]
// 00670856  6aff                 push -1
// 00670858  6842e87d00           push 0x7de842
// 0067085d  50                   push eax
// 0067085e  64892500000000       mov dword ptr fs:[0], esp
// 00670865  83ec44               sub esp, 0x44
// 00670868  57                   push edi
// 00670869  8bf9                 mov edi, ecx
// 0067086b  817f1c65666606       cmp dword ptr [edi + 0x1c], 0x6666665
// 00670872  7259                 jb 0x6708cd
// 00670874  688cb28000           push 0x80b28c
// 00670879  8d4c2408             lea ecx, [esp + 8]
// 0067087d  ff1558248000         call dword ptr [0x802458]
// 00670883  8d4c2420             lea ecx, [esp + 0x20]
// 00670887  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0067088f  ff1598288000         call dword ptr [0x802898]
// 00670895  8d442404             lea eax, [esp + 4]
// 00670899  50                   push eax
// 0067089a  8d4c2430             lea ecx, [esp + 0x30]
// 0067089e  c644245401           mov byte ptr [esp + 0x54], 1
// 006708a3  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 006708ab  ff155c248000         call dword ptr [0x80245c]
// 006708b1  68c00c8d00           push 0x8d0cc0
// 006708b6  8d4c2424             lea ecx, [esp + 0x24]
// 006708ba  51                   push ecx
// 006708bb  c644245800           mov byte ptr [esp + 0x58], 0
// 006708c0  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 006708c8  e8bf0c0300           call 0x6a158c
// 006708cd  8b542464             mov edx, dword ptr [esp + 0x64]
// 006708d1  8b4718               mov eax, dword ptr [edi + 0x18]
// 006708d4  53                   push ebx
// 006708d5  55                   push ebp
// 006708d6  56                   push esi
// 006708d7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006708db  6a00                 push 0
// 006708dd  52                   push edx
// 006708de  50                   push eax
// 006708df  56                   push esi
// 006708e0  50                   push eax
// 006708e1  e89afeffff           call 0x670780
// 006708e6  8be8                 mov ebp, eax
// 006708e8  8b4718               mov eax, dword ptr [edi + 0x18]
// 006708eb  bb01000000           mov ebx, 1
// 006708f0  015f1c               add dword ptr [edi + 0x1c], ebx
// 006708f3  3bf0                 cmp esi, eax
// 006708f5  7510                 jne 0x670907
// 006708f7  896804               mov dword ptr [eax + 4], ebp
// 006708fa  8b4718               mov eax, dword ptr [edi + 0x18]
// 006708fd  8928                 mov dword ptr [eax], ebp
// 006708ff  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00670902  896908               mov dword ptr [ecx + 8], ebp
// 00670905  eb22                 jmp 0x670929
// 00670907  807c246800           cmp byte ptr [esp + 0x68], 0
// 0067090c  740d                 je 0x67091b
// 0067090e  892e                 mov dword ptr [esi], ebp
// 00670910  8b4718               mov eax, dword ptr [edi + 0x18]
// 00670913  3b30                 cmp esi, dword ptr [eax]
// 00670915  7512                 jne 0x670929
// 00670917  8928                 mov dword ptr [eax], ebp
// 00670919  eb0e                 jmp 0x670929
// 0067091b  896e08               mov dword ptr [esi + 8], ebp
// 0067091e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00670921  3b7008               cmp esi, dword ptr [eax + 8]
// 00670924  7503                 jne 0x670929
// 00670926  896808               mov dword ptr [eax + 8], ebp
// 00670929  8b5504               mov edx, dword ptr [ebp + 4]
// 0067092c  807a3400             cmp byte ptr [edx + 0x34], 0
// 00670930  8d4504               lea eax, [ebp + 4]
// 00670933  8bf5                 mov esi, ebp
// 00670935  0f85ea000000         jne 0x670a25
// 0067093b  eb03                 jmp 0x670940
// 0067093d  8d4900               lea ecx, [ecx]
// 00670940  8b08                 mov ecx, dword ptr [eax]
// 00670942  8b5104               mov edx, dword ptr [ecx + 4]
// 00670945  3b0a                 cmp ecx, dword ptr [edx]
// 00670947  7551                 jne 0x67099a
// 00670949  8b5208               mov edx, dword ptr [edx + 8]
// 0067094c  807a3400             cmp byte ptr [edx + 0x34], 0
// 00670950  7519                 jne 0x67096b
// 00670952  885934               mov byte ptr [ecx + 0x34], bl
// 00670955  885a34               mov byte ptr [edx + 0x34], bl
// 00670958  8b10                 mov edx, dword ptr [eax]
// 0067095a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0067095d  c6413400             mov byte ptr [ecx + 0x34], 0
// 00670961  8b10                 mov edx, dword ptr [eax]
// 00670963  8b7204               mov esi, dword ptr [edx + 4]
// 00670966  e9aa000000           jmp 0x670a15
// 0067096b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0067096e  750a                 jne 0x67097a
// 00670970  8bf1                 mov esi, ecx
// 00670972  56                   push esi
// 00670973  8bcf                 mov ecx, edi
// 00670975  e8a6bce6ff           call 0x4dc620
// 0067097a  8b4604               mov eax, dword ptr [esi + 4]
// 0067097d  885834               mov byte ptr [eax + 0x34], bl
// 00670980  8b4e04               mov ecx, dword ptr [esi + 4]
// 00670983  8b5104               mov edx, dword ptr [ecx + 4]
// 00670986  c6423400             mov byte ptr [edx + 0x34], 0
// 0067098a  8b4604               mov eax, dword ptr [esi + 4]
// 0067098d  8b4804               mov ecx, dword ptr [eax + 4]
// 00670990  51                   push ecx
// 00670991  8bcf                 mov ecx, edi
// 00670993  e84861f4ff           call 0x5b6ae0
// 00670998  eb7b                 jmp 0x670a15
// 0067099a  8b12                 mov edx, dword ptr [edx]
// 0067099c  807a3400             cmp byte ptr [edx + 0x34], 0
// 006709a0  7516                 jne 0x6709b8
// 006709a2  885934               mov byte ptr [ecx + 0x34], bl
// 006709a5  885a34               mov byte ptr [edx + 0x34], bl
// 006709a8  8b10                 mov edx, dword ptr [eax]
// 006709aa  8b4a04               mov ecx, dword ptr [edx + 4]
// 006709ad  c6413400             mov byte ptr [ecx + 0x34], 0
// 006709b1  8b10                 mov edx, dword ptr [eax]
// 006709b3  8b7204               mov esi, dword ptr [edx + 4]
// 006709b6  eb5d                 jmp 0x670a15
// 006709b8  3b31                 cmp esi, dword ptr [ecx]
// 006709ba  750a                 jne 0x6709c6
// 006709bc  8bf1                 mov esi, ecx
// 006709be  56                   push esi
// 006709bf  8bcf                 mov ecx, edi
// 006709c1  e81a61f4ff           call 0x5b6ae0
// 006709c6  8b4604               mov eax, dword ptr [esi + 4]
// 006709c9  885834               mov byte ptr [eax + 0x34], bl
// 006709cc  8b4e04               mov ecx, dword ptr [esi + 4]
// 006709cf  8b5104               mov edx, dword ptr [ecx + 4]
// 006709d2  c6423400             mov byte ptr [edx + 0x34], 0
// 006709d6  8b4604               mov eax, dword ptr [esi + 4]
// 006709d9  8b4004               mov eax, dword ptr [eax + 4]
// 006709dc  8b4808               mov ecx, dword ptr [eax + 8]
// 006709df  8b11                 mov edx, dword ptr [ecx]
// 006709e1  895008               mov dword ptr [eax + 8], edx
// 006709e4  8b11                 mov edx, dword ptr [ecx]
// 006709e6  807a3500             cmp byte ptr [edx + 0x35], 0
// 006709ea  7503                 jne 0x6709ef
// 006709ec  894204               mov dword ptr [edx + 4], eax
// 006709ef  8b5004               mov edx, dword ptr [eax + 4]
// 006709f2  895104               mov dword ptr [ecx + 4], edx
// 006709f5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006709f8  3b4204               cmp eax, dword ptr [edx + 4]
// 006709fb  7505                 jne 0x670a02
// 006709fd  894a04               mov dword ptr [edx + 4], ecx
// 00670a00  eb0e                 jmp 0x670a10
// 00670a02  8b5004               mov edx, dword ptr [eax + 4]
// 00670a05  3b02                 cmp eax, dword ptr [edx]
// 00670a07  7504                 jne 0x670a0d
// 00670a09  890a                 mov dword ptr [edx], ecx
// 00670a0b  eb03                 jmp 0x670a10
// 00670a0d  894a08               mov dword ptr [edx + 8], ecx
// 00670a10  8901                 mov dword ptr [ecx], eax
// 00670a12  894804               mov dword ptr [eax + 4], ecx
// 00670a15  8b4e04               mov ecx, dword ptr [esi + 4]
// 00670a18  80793400             cmp byte ptr [ecx + 0x34], 0
// 00670a1c  8d4604               lea eax, [esi + 4]
// 00670a1f  0f841bffffff         je 0x670940
// 00670a25  8b5718               mov edx, dword ptr [edi + 0x18]
// 00670a28  8b4204               mov eax, dword ptr [edx + 4]
// 00670a2b  885834               mov byte ptr [eax + 0x34], bl
// 00670a2e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00670a32  8b0f                 mov ecx, dword ptr [edi]
// 00670a34  5e                   pop esi
// 00670a35  896804               mov dword ptr [eax + 4], ebp
// 00670a38  5d                   pop ebp
// 00670a39  8908                 mov dword ptr [eax], ecx
// 00670a3b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00670a3f  5b                   pop ebx
// 00670a40  5f                   pop edi
// 00670a41  64890d00000000       mov dword ptr fs:[0], ecx
// 00670a48  83c450               add esp, 0x50
// 00670a4b  c21000               ret 0x10
// standard library map_int<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
