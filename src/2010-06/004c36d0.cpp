// from server: 100% by auto
// roc 2010-06 004c36d0  unit: RBX::VInstance::?$NonFactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c36d0
//
// 004c36d0  64a100000000         mov eax, dword ptr fs:[0]
// 004c36d6  6aff                 push -1
// 004c36d8  68e22f9a00           push 0x9a2fe2
// 004c36dd  50                   push eax
// 004c36de  64892500000000       mov dword ptr fs:[0], esp
// 004c36e5  83ec44               sub esp, 0x44
// 004c36e8  57                   push edi
// 004c36e9  8bf9                 mov edi, ecx
// 004c36eb  817f1c48922409       cmp dword ptr [edi + 0x1c], 0x9249248
// 004c36f2  7259                 jb 0x4c374d
// 004c36f4  68a800a000           push 0xa000a8
// 004c36f9  8d4c2408             lea ecx, [esp + 8]
// 004c36fd  ff1510a49e00         call dword ptr [0x9ea410]
// 004c3703  8d4c2420             lea ecx, [esp + 0x20]
// 004c3707  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004c370f  ff1518a99e00         call dword ptr [0x9ea918]
// 004c3715  8d442404             lea eax, [esp + 4]
// 004c3719  50                   push eax
// 004c371a  8d4c2430             lea ecx, [esp + 0x30]
// 004c371e  c644245401           mov byte ptr [esp + 0x54], 1
// 004c3723  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 004c372b  ff150ca49e00         call dword ptr [0x9ea40c]
// 004c3731  68601bb000           push 0xb01b60
// 004c3736  8d4c2424             lea ecx, [esp + 0x24]
// 004c373a  51                   push ecx
// 004c373b  c644245800           mov byte ptr [esp + 0x58], 0
// 004c3740  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 004c3748  e865522e00           call 0x7a89b2
// 004c374d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004c3751  8b4718               mov eax, dword ptr [edi + 0x18]
// 004c3754  53                   push ebx
// 004c3755  55                   push ebp
// 004c3756  56                   push esi
// 004c3757  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004c375b  6a00                 push 0
// 004c375d  52                   push edx
// 004c375e  50                   push eax
// 004c375f  56                   push esi
// 004c3760  50                   push eax
// 004c3761  e84adfffff           call 0x4c16b0
// 004c3766  8be8                 mov ebp, eax
// 004c3768  8b4718               mov eax, dword ptr [edi + 0x18]
// 004c376b  bb01000000           mov ebx, 1
// 004c3770  015f1c               add dword ptr [edi + 0x1c], ebx
// 004c3773  3bf0                 cmp esi, eax
// 004c3775  7510                 jne 0x4c3787
// 004c3777  896804               mov dword ptr [eax + 4], ebp
// 004c377a  8b4718               mov eax, dword ptr [edi + 0x18]
// 004c377d  8928                 mov dword ptr [eax], ebp
// 004c377f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004c3782  896908               mov dword ptr [ecx + 8], ebp
// 004c3785  eb22                 jmp 0x4c37a9
// 004c3787  807c246800           cmp byte ptr [esp + 0x68], 0
// 004c378c  740d                 je 0x4c379b
// 004c378e  892e                 mov dword ptr [esi], ebp
// 004c3790  8b4718               mov eax, dword ptr [edi + 0x18]
// 004c3793  3b30                 cmp esi, dword ptr [eax]
// 004c3795  7512                 jne 0x4c37a9
// 004c3797  8928                 mov dword ptr [eax], ebp
// 004c3799  eb0e                 jmp 0x4c37a9
// 004c379b  896e08               mov dword ptr [esi + 8], ebp
// 004c379e  8b4718               mov eax, dword ptr [edi + 0x18]
// 004c37a1  3b7008               cmp esi, dword ptr [eax + 8]
// 004c37a4  7503                 jne 0x4c37a9
// 004c37a6  896808               mov dword ptr [eax + 8], ebp
// 004c37a9  8b5504               mov edx, dword ptr [ebp + 4]
// 004c37ac  807a2800             cmp byte ptr [edx + 0x28], 0
// 004c37b0  8d4504               lea eax, [ebp + 4]
// 004c37b3  8bf5                 mov esi, ebp
// 004c37b5  0f85ea000000         jne 0x4c38a5
// 004c37bb  eb03                 jmp 0x4c37c0
// 004c37bd  8d4900               lea ecx, [ecx]
// 004c37c0  8b08                 mov ecx, dword ptr [eax]
// 004c37c2  8b5104               mov edx, dword ptr [ecx + 4]
// 004c37c5  3b0a                 cmp ecx, dword ptr [edx]
// 004c37c7  7551                 jne 0x4c381a
// 004c37c9  8b5208               mov edx, dword ptr [edx + 8]
// 004c37cc  807a2800             cmp byte ptr [edx + 0x28], 0
// 004c37d0  7519                 jne 0x4c37eb
// 004c37d2  885928               mov byte ptr [ecx + 0x28], bl
// 004c37d5  885a28               mov byte ptr [edx + 0x28], bl
// 004c37d8  8b10                 mov edx, dword ptr [eax]
// 004c37da  8b4a04               mov ecx, dword ptr [edx + 4]
// 004c37dd  c6412800             mov byte ptr [ecx + 0x28], 0
// 004c37e1  8b10                 mov edx, dword ptr [eax]
// 004c37e3  8b7204               mov esi, dword ptr [edx + 4]
// 004c37e6  e9aa000000           jmp 0x4c3895
// 004c37eb  3b7108               cmp esi, dword ptr [ecx + 8]
// 004c37ee  750a                 jne 0x4c37fa
// 004c37f0  8bf1                 mov esi, ecx
// 004c37f2  56                   push esi
// 004c37f3  8bcf                 mov ecx, edi
// 004c37f5  e8d6370600           call 0x526fd0
// 004c37fa  8b4604               mov eax, dword ptr [esi + 4]
// 004c37fd  885828               mov byte ptr [eax + 0x28], bl
// 004c3800  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c3803  8b5104               mov edx, dword ptr [ecx + 4]
// 004c3806  c6422800             mov byte ptr [edx + 0x28], 0
// 004c380a  8b4604               mov eax, dword ptr [esi + 4]
// 004c380d  8b4804               mov ecx, dword ptr [eax + 4]
// 004c3810  51                   push ecx
// 004c3811  8bcf                 mov ecx, edi
// 004c3813  e858370600           call 0x526f70
// 004c3818  eb7b                 jmp 0x4c3895
// 004c381a  8b12                 mov edx, dword ptr [edx]
// 004c381c  807a2800             cmp byte ptr [edx + 0x28], 0
// 004c3820  7516                 jne 0x4c3838
// 004c3822  885928               mov byte ptr [ecx + 0x28], bl
// 004c3825  885a28               mov byte ptr [edx + 0x28], bl
// 004c3828  8b10                 mov edx, dword ptr [eax]
// 004c382a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004c382d  c6412800             mov byte ptr [ecx + 0x28], 0
// 004c3831  8b10                 mov edx, dword ptr [eax]
// 004c3833  8b7204               mov esi, dword ptr [edx + 4]
// 004c3836  eb5d                 jmp 0x4c3895
// 004c3838  3b31                 cmp esi, dword ptr [ecx]
// 004c383a  750a                 jne 0x4c3846
// 004c383c  8bf1                 mov esi, ecx
// 004c383e  56                   push esi
// 004c383f  8bcf                 mov ecx, edi
// 004c3841  e82a370600           call 0x526f70
// 004c3846  8b4604               mov eax, dword ptr [esi + 4]
// 004c3849  885828               mov byte ptr [eax + 0x28], bl
// 004c384c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c384f  8b5104               mov edx, dword ptr [ecx + 4]
// 004c3852  c6422800             mov byte ptr [edx + 0x28], 0
// 004c3856  8b4604               mov eax, dword ptr [esi + 4]
// 004c3859  8b4004               mov eax, dword ptr [eax + 4]
// 004c385c  8b4808               mov ecx, dword ptr [eax + 8]
// 004c385f  8b11                 mov edx, dword ptr [ecx]
// 004c3861  895008               mov dword ptr [eax + 8], edx
// 004c3864  8b11                 mov edx, dword ptr [ecx]
// 004c3866  807a2900             cmp byte ptr [edx + 0x29], 0
// 004c386a  7503                 jne 0x4c386f
// 004c386c  894204               mov dword ptr [edx + 4], eax
// 004c386f  8b5004               mov edx, dword ptr [eax + 4]
// 004c3872  895104               mov dword ptr [ecx + 4], edx
// 004c3875  8b5718               mov edx, dword ptr [edi + 0x18]
// 004c3878  3b4204               cmp eax, dword ptr [edx + 4]
// 004c387b  7505                 jne 0x4c3882
// 004c387d  894a04               mov dword ptr [edx + 4], ecx
// 004c3880  eb0e                 jmp 0x4c3890
// 004c3882  8b5004               mov edx, dword ptr [eax + 4]
// 004c3885  3b02                 cmp eax, dword ptr [edx]
// 004c3887  7504                 jne 0x4c388d
// 004c3889  890a                 mov dword ptr [edx], ecx
// 004c388b  eb03                 jmp 0x4c3890
// 004c388d  894a08               mov dword ptr [edx + 8], ecx
// 004c3890  8901                 mov dword ptr [ecx], eax
// 004c3892  894804               mov dword ptr [eax + 4], ecx
// 004c3895  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c3898  80792800             cmp byte ptr [ecx + 0x28], 0
// 004c389c  8d4604               lea eax, [esi + 4]
// 004c389f  0f841bffffff         je 0x4c37c0
// 004c38a5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004c38a8  8b4204               mov eax, dword ptr [edx + 4]
// 004c38ab  885828               mov byte ptr [eax + 0x28], bl
// 004c38ae  8b442464             mov eax, dword ptr [esp + 0x64]
// 004c38b2  8b0f                 mov ecx, dword ptr [edi]
// 004c38b4  5e                   pop esi
// 004c38b5  896804               mov dword ptr [eax + 4], ebp
// 004c38b8  5d                   pop ebp
// 004c38b9  8908                 mov dword ptr [eax], ecx
// 004c38bb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004c38bf  5b                   pop ebx
// 004c38c0  5f                   pop edi
// 004c38c1  64890d00000000       mov dword ptr fs:[0], ecx
// 004c38c8  83c450               add esp, 0x50
// 004c38cb  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
