// from server: 100% by auto
// roc 2010-06 0061b210  unit: RBX::Accoutrement  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0061b210
//
// 0061b210  64a100000000         mov eax, dword ptr fs:[0]
// 0061b216  6aff                 push -1
// 0061b218  68e22f9a00           push 0x9a2fe2
// 0061b21d  50                   push eax
// 0061b21e  64892500000000       mov dword ptr fs:[0], esp
// 0061b225  83ec44               sub esp, 0x44
// 0061b228  57                   push edi
// 0061b229  8bf9                 mov edi, ecx
// 0061b22b  817f1ccbcccc0c       cmp dword ptr [edi + 0x1c], 0xccccccb
// 0061b232  7259                 jb 0x61b28d
// 0061b234  68a800a000           push 0xa000a8
// 0061b239  8d4c2408             lea ecx, [esp + 8]
// 0061b23d  ff1510a49e00         call dword ptr [0x9ea410]
// 0061b243  8d4c2420             lea ecx, [esp + 0x20]
// 0061b247  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0061b24f  ff1518a99e00         call dword ptr [0x9ea918]
// 0061b255  8d442404             lea eax, [esp + 4]
// 0061b259  50                   push eax
// 0061b25a  8d4c2430             lea ecx, [esp + 0x30]
// 0061b25e  c644245401           mov byte ptr [esp + 0x54], 1
// 0061b263  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 0061b26b  ff150ca49e00         call dword ptr [0x9ea40c]
// 0061b271  68601bb000           push 0xb01b60
// 0061b276  8d4c2424             lea ecx, [esp + 0x24]
// 0061b27a  51                   push ecx
// 0061b27b  c644245800           mov byte ptr [esp + 0x58], 0
// 0061b280  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 0061b288  e825d71800           call 0x7a89b2
// 0061b28d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0061b291  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061b294  53                   push ebx
// 0061b295  55                   push ebp
// 0061b296  56                   push esi
// 0061b297  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0061b29b  6a00                 push 0
// 0061b29d  52                   push edx
// 0061b29e  50                   push eax
// 0061b29f  56                   push esi
// 0061b2a0  50                   push eax
// 0061b2a1  e8cafeffff           call 0x61b170
// 0061b2a6  8be8                 mov ebp, eax
// 0061b2a8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061b2ab  bb01000000           mov ebx, 1
// 0061b2b0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0061b2b3  3bf0                 cmp esi, eax
// 0061b2b5  7510                 jne 0x61b2c7
// 0061b2b7  896804               mov dword ptr [eax + 4], ebp
// 0061b2ba  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061b2bd  8928                 mov dword ptr [eax], ebp
// 0061b2bf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0061b2c2  896908               mov dword ptr [ecx + 8], ebp
// 0061b2c5  eb22                 jmp 0x61b2e9
// 0061b2c7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0061b2cc  740d                 je 0x61b2db
// 0061b2ce  892e                 mov dword ptr [esi], ebp
// 0061b2d0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061b2d3  3b30                 cmp esi, dword ptr [eax]
// 0061b2d5  7512                 jne 0x61b2e9
// 0061b2d7  8928                 mov dword ptr [eax], ebp
// 0061b2d9  eb0e                 jmp 0x61b2e9
// 0061b2db  896e08               mov dword ptr [esi + 8], ebp
// 0061b2de  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061b2e1  3b7008               cmp esi, dword ptr [eax + 8]
// 0061b2e4  7503                 jne 0x61b2e9
// 0061b2e6  896808               mov dword ptr [eax + 8], ebp
// 0061b2e9  8b5504               mov edx, dword ptr [ebp + 4]
// 0061b2ec  807a2000             cmp byte ptr [edx + 0x20], 0
// 0061b2f0  8d4504               lea eax, [ebp + 4]
// 0061b2f3  8bf5                 mov esi, ebp
// 0061b2f5  0f85ea000000         jne 0x61b3e5
// 0061b2fb  eb03                 jmp 0x61b300
// 0061b2fd  8d4900               lea ecx, [ecx]
// 0061b300  8b08                 mov ecx, dword ptr [eax]
// 0061b302  8b5104               mov edx, dword ptr [ecx + 4]
// 0061b305  3b0a                 cmp ecx, dword ptr [edx]
// 0061b307  7551                 jne 0x61b35a
// 0061b309  8b5208               mov edx, dword ptr [edx + 8]
// 0061b30c  807a2000             cmp byte ptr [edx + 0x20], 0
// 0061b310  7519                 jne 0x61b32b
// 0061b312  885920               mov byte ptr [ecx + 0x20], bl
// 0061b315  885a20               mov byte ptr [edx + 0x20], bl
// 0061b318  8b10                 mov edx, dword ptr [eax]
// 0061b31a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0061b31d  c6412000             mov byte ptr [ecx + 0x20], 0
// 0061b321  8b10                 mov edx, dword ptr [eax]
// 0061b323  8b7204               mov esi, dword ptr [edx + 4]
// 0061b326  e9aa000000           jmp 0x61b3d5
// 0061b32b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0061b32e  750a                 jne 0x61b33a
// 0061b330  8bf1                 mov esi, ecx
// 0061b332  56                   push esi
// 0061b333  8bcf                 mov ecx, edi
// 0061b335  e8761df1ff           call 0x52d0b0
// 0061b33a  8b4604               mov eax, dword ptr [esi + 4]
// 0061b33d  885820               mov byte ptr [eax + 0x20], bl
// 0061b340  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061b343  8b5104               mov edx, dword ptr [ecx + 4]
// 0061b346  c6422000             mov byte ptr [edx + 0x20], 0
// 0061b34a  8b4604               mov eax, dword ptr [esi + 4]
// 0061b34d  8b4804               mov ecx, dword ptr [eax + 4]
// 0061b350  51                   push ecx
// 0061b351  8bcf                 mov ecx, edi
// 0061b353  e848fdffff           call 0x61b0a0
// 0061b358  eb7b                 jmp 0x61b3d5
// 0061b35a  8b12                 mov edx, dword ptr [edx]
// 0061b35c  807a2000             cmp byte ptr [edx + 0x20], 0
// 0061b360  7516                 jne 0x61b378
// 0061b362  885920               mov byte ptr [ecx + 0x20], bl
// 0061b365  885a20               mov byte ptr [edx + 0x20], bl
// 0061b368  8b10                 mov edx, dword ptr [eax]
// 0061b36a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0061b36d  c6412000             mov byte ptr [ecx + 0x20], 0
// 0061b371  8b10                 mov edx, dword ptr [eax]
// 0061b373  8b7204               mov esi, dword ptr [edx + 4]
// 0061b376  eb5d                 jmp 0x61b3d5
// 0061b378  3b31                 cmp esi, dword ptr [ecx]
// 0061b37a  750a                 jne 0x61b386
// 0061b37c  8bf1                 mov esi, ecx
// 0061b37e  56                   push esi
// 0061b37f  8bcf                 mov ecx, edi
// 0061b381  e81afdffff           call 0x61b0a0
// 0061b386  8b4604               mov eax, dword ptr [esi + 4]
// 0061b389  885820               mov byte ptr [eax + 0x20], bl
// 0061b38c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061b38f  8b5104               mov edx, dword ptr [ecx + 4]
// 0061b392  c6422000             mov byte ptr [edx + 0x20], 0
// 0061b396  8b4604               mov eax, dword ptr [esi + 4]
// 0061b399  8b4004               mov eax, dword ptr [eax + 4]
// 0061b39c  8b4808               mov ecx, dword ptr [eax + 8]
// 0061b39f  8b11                 mov edx, dword ptr [ecx]
// 0061b3a1  895008               mov dword ptr [eax + 8], edx
// 0061b3a4  8b11                 mov edx, dword ptr [ecx]
// 0061b3a6  807a2100             cmp byte ptr [edx + 0x21], 0
// 0061b3aa  7503                 jne 0x61b3af
// 0061b3ac  894204               mov dword ptr [edx + 4], eax
// 0061b3af  8b5004               mov edx, dword ptr [eax + 4]
// 0061b3b2  895104               mov dword ptr [ecx + 4], edx
// 0061b3b5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0061b3b8  3b4204               cmp eax, dword ptr [edx + 4]
// 0061b3bb  7505                 jne 0x61b3c2
// 0061b3bd  894a04               mov dword ptr [edx + 4], ecx
// 0061b3c0  eb0e                 jmp 0x61b3d0
// 0061b3c2  8b5004               mov edx, dword ptr [eax + 4]
// 0061b3c5  3b02                 cmp eax, dword ptr [edx]
// 0061b3c7  7504                 jne 0x61b3cd
// 0061b3c9  890a                 mov dword ptr [edx], ecx
// 0061b3cb  eb03                 jmp 0x61b3d0
// 0061b3cd  894a08               mov dword ptr [edx + 8], ecx
// 0061b3d0  8901                 mov dword ptr [ecx], eax
// 0061b3d2  894804               mov dword ptr [eax + 4], ecx
// 0061b3d5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061b3d8  80792000             cmp byte ptr [ecx + 0x20], 0
// 0061b3dc  8d4604               lea eax, [esi + 4]
// 0061b3df  0f841bffffff         je 0x61b300
// 0061b3e5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0061b3e8  8b4204               mov eax, dword ptr [edx + 4]
// 0061b3eb  885820               mov byte ptr [eax + 0x20], bl
// 0061b3ee  8b442464             mov eax, dword ptr [esp + 0x64]
// 0061b3f2  8b0f                 mov ecx, dword ptr [edi]
// 0061b3f4  5e                   pop esi
// 0061b3f5  896804               mov dword ptr [eax + 4], ebp
// 0061b3f8  5d                   pop ebp
// 0061b3f9  8908                 mov dword ptr [eax], ecx
// 0061b3fb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0061b3ff  5b                   pop ebx
// 0061b400  5f                   pop edi
// 0061b401  64890d00000000       mov dword ptr fs:[0], ecx
// 0061b408  83c450               add esp, 0x50
// 0061b40b  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
