// from server: 100% by auto
// roc 2010-06 008e33d0  unit: RBX::RbxTextureProxy  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e33d0
//
// 008e33d0  64a100000000         mov eax, dword ptr fs:[0]
// 008e33d6  6aff                 push -1
// 008e33d8  68e22f9a00           push 0x9a2fe2
// 008e33dd  50                   push eax
// 008e33de  64892500000000       mov dword ptr fs:[0], esp
// 008e33e5  83ec44               sub esp, 0x44
// 008e33e8  57                   push edi
// 008e33e9  8bf9                 mov edi, ecx
// 008e33eb  817f1ccbcccc0c       cmp dword ptr [edi + 0x1c], 0xccccccb
// 008e33f2  7259                 jb 0x8e344d
// 008e33f4  68a800a000           push 0xa000a8
// 008e33f9  8d4c2408             lea ecx, [esp + 8]
// 008e33fd  ff1510a49e00         call dword ptr [0x9ea410]
// 008e3403  8d4c2420             lea ecx, [esp + 0x20]
// 008e3407  c744245000000000     mov dword ptr [esp + 0x50], 0
// 008e340f  ff1518a99e00         call dword ptr [0x9ea918]
// 008e3415  8d442404             lea eax, [esp + 4]
// 008e3419  50                   push eax
// 008e341a  8d4c2430             lea ecx, [esp + 0x30]
// 008e341e  c644245401           mov byte ptr [esp + 0x54], 1
// 008e3423  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 008e342b  ff150ca49e00         call dword ptr [0x9ea40c]
// 008e3431  68601bb000           push 0xb01b60
// 008e3436  8d4c2424             lea ecx, [esp + 0x24]
// 008e343a  51                   push ecx
// 008e343b  c644245800           mov byte ptr [esp + 0x58], 0
// 008e3440  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 008e3448  e86555ecff           call 0x7a89b2
// 008e344d  8b542464             mov edx, dword ptr [esp + 0x64]
// 008e3451  8b4718               mov eax, dword ptr [edi + 0x18]
// 008e3454  53                   push ebx
// 008e3455  55                   push ebp
// 008e3456  56                   push esi
// 008e3457  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 008e345b  6a00                 push 0
// 008e345d  52                   push edx
// 008e345e  50                   push eax
// 008e345f  56                   push esi
// 008e3460  50                   push eax
// 008e3461  e8cafeffff           call 0x8e3330
// 008e3466  8be8                 mov ebp, eax
// 008e3468  8b4718               mov eax, dword ptr [edi + 0x18]
// 008e346b  bb01000000           mov ebx, 1
// 008e3470  015f1c               add dword ptr [edi + 0x1c], ebx
// 008e3473  3bf0                 cmp esi, eax
// 008e3475  7510                 jne 0x8e3487
// 008e3477  896804               mov dword ptr [eax + 4], ebp
// 008e347a  8b4718               mov eax, dword ptr [edi + 0x18]
// 008e347d  8928                 mov dword ptr [eax], ebp
// 008e347f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 008e3482  896908               mov dword ptr [ecx + 8], ebp
// 008e3485  eb22                 jmp 0x8e34a9
// 008e3487  807c246800           cmp byte ptr [esp + 0x68], 0
// 008e348c  740d                 je 0x8e349b
// 008e348e  892e                 mov dword ptr [esi], ebp
// 008e3490  8b4718               mov eax, dword ptr [edi + 0x18]
// 008e3493  3b30                 cmp esi, dword ptr [eax]
// 008e3495  7512                 jne 0x8e34a9
// 008e3497  8928                 mov dword ptr [eax], ebp
// 008e3499  eb0e                 jmp 0x8e34a9
// 008e349b  896e08               mov dword ptr [esi + 8], ebp
// 008e349e  8b4718               mov eax, dword ptr [edi + 0x18]
// 008e34a1  3b7008               cmp esi, dword ptr [eax + 8]
// 008e34a4  7503                 jne 0x8e34a9
// 008e34a6  896808               mov dword ptr [eax + 8], ebp
// 008e34a9  8b5504               mov edx, dword ptr [ebp + 4]
// 008e34ac  807a2000             cmp byte ptr [edx + 0x20], 0
// 008e34b0  8d4504               lea eax, [ebp + 4]
// 008e34b3  8bf5                 mov esi, ebp
// 008e34b5  0f85ea000000         jne 0x8e35a5
// 008e34bb  eb03                 jmp 0x8e34c0
// 008e34bd  8d4900               lea ecx, [ecx]
// 008e34c0  8b08                 mov ecx, dword ptr [eax]
// 008e34c2  8b5104               mov edx, dword ptr [ecx + 4]
// 008e34c5  3b0a                 cmp ecx, dword ptr [edx]
// 008e34c7  7551                 jne 0x8e351a
// 008e34c9  8b5208               mov edx, dword ptr [edx + 8]
// 008e34cc  807a2000             cmp byte ptr [edx + 0x20], 0
// 008e34d0  7519                 jne 0x8e34eb
// 008e34d2  885920               mov byte ptr [ecx + 0x20], bl
// 008e34d5  885a20               mov byte ptr [edx + 0x20], bl
// 008e34d8  8b10                 mov edx, dword ptr [eax]
// 008e34da  8b4a04               mov ecx, dword ptr [edx + 4]
// 008e34dd  c6412000             mov byte ptr [ecx + 0x20], 0
// 008e34e1  8b10                 mov edx, dword ptr [eax]
// 008e34e3  8b7204               mov esi, dword ptr [edx + 4]
// 008e34e6  e9aa000000           jmp 0x8e3595
// 008e34eb  3b7108               cmp esi, dword ptr [ecx + 8]
// 008e34ee  750a                 jne 0x8e34fa
// 008e34f0  8bf1                 mov esi, ecx
// 008e34f2  56                   push esi
// 008e34f3  8bcf                 mov ecx, edi
// 008e34f5  e8b69bc4ff           call 0x52d0b0
// 008e34fa  8b4604               mov eax, dword ptr [esi + 4]
// 008e34fd  885820               mov byte ptr [eax + 0x20], bl
// 008e3500  8b4e04               mov ecx, dword ptr [esi + 4]
// 008e3503  8b5104               mov edx, dword ptr [ecx + 4]
// 008e3506  c6422000             mov byte ptr [edx + 0x20], 0
// 008e350a  8b4604               mov eax, dword ptr [esi + 4]
// 008e350d  8b4804               mov ecx, dword ptr [eax + 4]
// 008e3510  51                   push ecx
// 008e3511  8bcf                 mov ecx, edi
// 008e3513  e8887bd3ff           call 0x61b0a0
// 008e3518  eb7b                 jmp 0x8e3595
// 008e351a  8b12                 mov edx, dword ptr [edx]
// 008e351c  807a2000             cmp byte ptr [edx + 0x20], 0
// 008e3520  7516                 jne 0x8e3538
// 008e3522  885920               mov byte ptr [ecx + 0x20], bl
// 008e3525  885a20               mov byte ptr [edx + 0x20], bl
// 008e3528  8b10                 mov edx, dword ptr [eax]
// 008e352a  8b4a04               mov ecx, dword ptr [edx + 4]
// 008e352d  c6412000             mov byte ptr [ecx + 0x20], 0
// 008e3531  8b10                 mov edx, dword ptr [eax]
// 008e3533  8b7204               mov esi, dword ptr [edx + 4]
// 008e3536  eb5d                 jmp 0x8e3595
// 008e3538  3b31                 cmp esi, dword ptr [ecx]
// 008e353a  750a                 jne 0x8e3546
// 008e353c  8bf1                 mov esi, ecx
// 008e353e  56                   push esi
// 008e353f  8bcf                 mov ecx, edi
// 008e3541  e85a7bd3ff           call 0x61b0a0
// 008e3546  8b4604               mov eax, dword ptr [esi + 4]
// 008e3549  885820               mov byte ptr [eax + 0x20], bl
// 008e354c  8b4e04               mov ecx, dword ptr [esi + 4]
// 008e354f  8b5104               mov edx, dword ptr [ecx + 4]
// 008e3552  c6422000             mov byte ptr [edx + 0x20], 0
// 008e3556  8b4604               mov eax, dword ptr [esi + 4]
// 008e3559  8b4004               mov eax, dword ptr [eax + 4]
// 008e355c  8b4808               mov ecx, dword ptr [eax + 8]
// 008e355f  8b11                 mov edx, dword ptr [ecx]
// 008e3561  895008               mov dword ptr [eax + 8], edx
// 008e3564  8b11                 mov edx, dword ptr [ecx]
// 008e3566  807a2100             cmp byte ptr [edx + 0x21], 0
// 008e356a  7503                 jne 0x8e356f
// 008e356c  894204               mov dword ptr [edx + 4], eax
// 008e356f  8b5004               mov edx, dword ptr [eax + 4]
// 008e3572  895104               mov dword ptr [ecx + 4], edx
// 008e3575  8b5718               mov edx, dword ptr [edi + 0x18]
// 008e3578  3b4204               cmp eax, dword ptr [edx + 4]
// 008e357b  7505                 jne 0x8e3582
// 008e357d  894a04               mov dword ptr [edx + 4], ecx
// 008e3580  eb0e                 jmp 0x8e3590
// 008e3582  8b5004               mov edx, dword ptr [eax + 4]
// 008e3585  3b02                 cmp eax, dword ptr [edx]
// 008e3587  7504                 jne 0x8e358d
// 008e3589  890a                 mov dword ptr [edx], ecx
// 008e358b  eb03                 jmp 0x8e3590
// 008e358d  894a08               mov dword ptr [edx + 8], ecx
// 008e3590  8901                 mov dword ptr [ecx], eax
// 008e3592  894804               mov dword ptr [eax + 4], ecx
// 008e3595  8b4e04               mov ecx, dword ptr [esi + 4]
// 008e3598  80792000             cmp byte ptr [ecx + 0x20], 0
// 008e359c  8d4604               lea eax, [esi + 4]
// 008e359f  0f841bffffff         je 0x8e34c0
// 008e35a5  8b5718               mov edx, dword ptr [edi + 0x18]
// 008e35a8  8b4204               mov eax, dword ptr [edx + 4]
// 008e35ab  885820               mov byte ptr [eax + 0x20], bl
// 008e35ae  8b442464             mov eax, dword ptr [esp + 0x64]
// 008e35b2  8b0f                 mov ecx, dword ptr [edi]
// 008e35b4  5e                   pop esi
// 008e35b5  896804               mov dword ptr [eax + 4], ebp
// 008e35b8  5d                   pop ebp
// 008e35b9  8908                 mov dword ptr [eax], ecx
// 008e35bb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 008e35bf  5b                   pop ebx
// 008e35c0  5f                   pop edi
// 008e35c1  64890d00000000       mov dword ptr fs:[0], ecx
// 008e35c8  83c450               add esp, 0x50
// 008e35cb  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
