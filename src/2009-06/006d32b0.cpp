// from server: 100% by auto
// roc 2009-06 006d32b0  unit: RBX::Block  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d32b0
//
// 006d32b0  64a100000000         mov eax, dword ptr fs:[0]
// 006d32b6  6aff                 push -1
// 006d32b8  68b2db8500           push 0x85dbb2
// 006d32bd  50                   push eax
// 006d32be  64892500000000       mov dword ptr fs:[0], esp
// 006d32c5  83ec44               sub esp, 0x44
// 006d32c8  57                   push edi
// 006d32c9  8bf9                 mov edi, ecx
// 006d32cb  817f1cfeffff0f       cmp dword ptr [edi + 0x1c], 0xffffffe
// 006d32d2  7259                 jb 0x6d332d
// 006d32d4  68c0c98a00           push 0x8ac9c0
// 006d32d9  8d4c2408             lea ecx, [esp + 8]
// 006d32dd  ff15b4e48900         call dword ptr [0x89e4b4]
// 006d32e3  8d4c2420             lea ecx, [esp + 0x20]
// 006d32e7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006d32ef  ff15b8e98900         call dword ptr [0x89e9b8]
// 006d32f5  8d442404             lea eax, [esp + 4]
// 006d32f9  50                   push eax
// 006d32fa  8d4c2430             lea ecx, [esp + 0x30]
// 006d32fe  c644245401           mov byte ptr [esp + 0x54], 1
// 006d3303  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 006d330b  ff15b8e48900         call dword ptr [0x89e4b8]
// 006d3311  6834929700           push 0x979234
// 006d3316  8d4c2424             lea ecx, [esp + 0x24]
// 006d331a  51                   push ecx
// 006d331b  c644245800           mov byte ptr [esp + 0x58], 0
// 006d3320  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 006d3328  e81d670400           call 0x719a4a
// 006d332d  8b542464             mov edx, dword ptr [esp + 0x64]
// 006d3331  8b4718               mov eax, dword ptr [edi + 0x18]
// 006d3334  53                   push ebx
// 006d3335  55                   push ebp
// 006d3336  56                   push esi
// 006d3337  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006d333b  6a00                 push 0
// 006d333d  52                   push edx
// 006d333e  50                   push eax
// 006d333f  56                   push esi
// 006d3340  50                   push eax
// 006d3341  e8dafeffff           call 0x6d3220
// 006d3346  8be8                 mov ebp, eax
// 006d3348  8b4718               mov eax, dword ptr [edi + 0x18]
// 006d334b  bb01000000           mov ebx, 1
// 006d3350  015f1c               add dword ptr [edi + 0x1c], ebx
// 006d3353  3bf0                 cmp esi, eax
// 006d3355  7510                 jne 0x6d3367
// 006d3357  896804               mov dword ptr [eax + 4], ebp
// 006d335a  8b4718               mov eax, dword ptr [edi + 0x18]
// 006d335d  8928                 mov dword ptr [eax], ebp
// 006d335f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006d3362  896908               mov dword ptr [ecx + 8], ebp
// 006d3365  eb22                 jmp 0x6d3389
// 006d3367  807c246800           cmp byte ptr [esp + 0x68], 0
// 006d336c  740d                 je 0x6d337b
// 006d336e  892e                 mov dword ptr [esi], ebp
// 006d3370  8b4718               mov eax, dword ptr [edi + 0x18]
// 006d3373  3b30                 cmp esi, dword ptr [eax]
// 006d3375  7512                 jne 0x6d3389
// 006d3377  8928                 mov dword ptr [eax], ebp
// 006d3379  eb0e                 jmp 0x6d3389
// 006d337b  896e08               mov dword ptr [esi + 8], ebp
// 006d337e  8b4718               mov eax, dword ptr [edi + 0x18]
// 006d3381  3b7008               cmp esi, dword ptr [eax + 8]
// 006d3384  7503                 jne 0x6d3389
// 006d3386  896808               mov dword ptr [eax + 8], ebp
// 006d3389  8b5504               mov edx, dword ptr [ebp + 4]
// 006d338c  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 006d3390  8d4504               lea eax, [ebp + 4]
// 006d3393  8bf5                 mov esi, ebp
// 006d3395  0f85ea000000         jne 0x6d3485
// 006d339b  eb03                 jmp 0x6d33a0
// 006d339d  8d4900               lea ecx, [ecx]
// 006d33a0  8b08                 mov ecx, dword ptr [eax]
// 006d33a2  8b5104               mov edx, dword ptr [ecx + 4]
// 006d33a5  3b0a                 cmp ecx, dword ptr [edx]
// 006d33a7  7551                 jne 0x6d33fa
// 006d33a9  8b5208               mov edx, dword ptr [edx + 8]
// 006d33ac  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 006d33b0  7519                 jne 0x6d33cb
// 006d33b2  88591c               mov byte ptr [ecx + 0x1c], bl
// 006d33b5  885a1c               mov byte ptr [edx + 0x1c], bl
// 006d33b8  8b10                 mov edx, dword ptr [eax]
// 006d33ba  8b4a04               mov ecx, dword ptr [edx + 4]
// 006d33bd  c6411c00             mov byte ptr [ecx + 0x1c], 0
// 006d33c1  8b10                 mov edx, dword ptr [eax]
// 006d33c3  8b7204               mov esi, dword ptr [edx + 4]
// 006d33c6  e9aa000000           jmp 0x6d3475
// 006d33cb  3b7108               cmp esi, dword ptr [ecx + 8]
// 006d33ce  750a                 jne 0x6d33da
// 006d33d0  8bf1                 mov esi, ecx
// 006d33d2  56                   push esi
// 006d33d3  8bcf                 mov ecx, edi
// 006d33d5  e8d6fbffff           call 0x6d2fb0
// 006d33da  8b4604               mov eax, dword ptr [esi + 4]
// 006d33dd  88581c               mov byte ptr [eax + 0x1c], bl
// 006d33e0  8b4e04               mov ecx, dword ptr [esi + 4]
// 006d33e3  8b5104               mov edx, dword ptr [ecx + 4]
// 006d33e6  c6421c00             mov byte ptr [edx + 0x1c], 0
// 006d33ea  8b4604               mov eax, dword ptr [esi + 4]
// 006d33ed  8b4804               mov ecx, dword ptr [eax + 4]
// 006d33f0  51                   push ecx
// 006d33f1  8bcf                 mov ecx, edi
// 006d33f3  e818f8ffff           call 0x6d2c10
// 006d33f8  eb7b                 jmp 0x6d3475
// 006d33fa  8b12                 mov edx, dword ptr [edx]
// 006d33fc  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 006d3400  7516                 jne 0x6d3418
// 006d3402  88591c               mov byte ptr [ecx + 0x1c], bl
// 006d3405  885a1c               mov byte ptr [edx + 0x1c], bl
// 006d3408  8b10                 mov edx, dword ptr [eax]
// 006d340a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006d340d  c6411c00             mov byte ptr [ecx + 0x1c], 0
// 006d3411  8b10                 mov edx, dword ptr [eax]
// 006d3413  8b7204               mov esi, dword ptr [edx + 4]
// 006d3416  eb5d                 jmp 0x6d3475
// 006d3418  3b31                 cmp esi, dword ptr [ecx]
// 006d341a  750a                 jne 0x6d3426
// 006d341c  8bf1                 mov esi, ecx
// 006d341e  56                   push esi
// 006d341f  8bcf                 mov ecx, edi
// 006d3421  e8eaf7ffff           call 0x6d2c10
// 006d3426  8b4604               mov eax, dword ptr [esi + 4]
// 006d3429  88581c               mov byte ptr [eax + 0x1c], bl
// 006d342c  8b4e04               mov ecx, dword ptr [esi + 4]
// 006d342f  8b5104               mov edx, dword ptr [ecx + 4]
// 006d3432  c6421c00             mov byte ptr [edx + 0x1c], 0
// 006d3436  8b4604               mov eax, dword ptr [esi + 4]
// 006d3439  8b4004               mov eax, dword ptr [eax + 4]
// 006d343c  8b4808               mov ecx, dword ptr [eax + 8]
// 006d343f  8b11                 mov edx, dword ptr [ecx]
// 006d3441  895008               mov dword ptr [eax + 8], edx
// 006d3444  8b11                 mov edx, dword ptr [ecx]
// 006d3446  807a1d00             cmp byte ptr [edx + 0x1d], 0
// 006d344a  7503                 jne 0x6d344f
// 006d344c  894204               mov dword ptr [edx + 4], eax
// 006d344f  8b5004               mov edx, dword ptr [eax + 4]
// 006d3452  895104               mov dword ptr [ecx + 4], edx
// 006d3455  8b5718               mov edx, dword ptr [edi + 0x18]
// 006d3458  3b4204               cmp eax, dword ptr [edx + 4]
// 006d345b  7505                 jne 0x6d3462
// 006d345d  894a04               mov dword ptr [edx + 4], ecx
// 006d3460  eb0e                 jmp 0x6d3470
// 006d3462  8b5004               mov edx, dword ptr [eax + 4]
// 006d3465  3b02                 cmp eax, dword ptr [edx]
// 006d3467  7504                 jne 0x6d346d
// 006d3469  890a                 mov dword ptr [edx], ecx
// 006d346b  eb03                 jmp 0x6d3470
// 006d346d  894a08               mov dword ptr [edx + 8], ecx
// 006d3470  8901                 mov dword ptr [ecx], eax
// 006d3472  894804               mov dword ptr [eax + 4], ecx
// 006d3475  8b4e04               mov ecx, dword ptr [esi + 4]
// 006d3478  80791c00             cmp byte ptr [ecx + 0x1c], 0
// 006d347c  8d4604               lea eax, [esi + 4]
// 006d347f  0f841bffffff         je 0x6d33a0
// 006d3485  8b5718               mov edx, dword ptr [edi + 0x18]
// 006d3488  8b4204               mov eax, dword ptr [edx + 4]
// 006d348b  88581c               mov byte ptr [eax + 0x1c], bl
// 006d348e  8b442464             mov eax, dword ptr [esp + 0x64]
// 006d3492  8b0f                 mov ecx, dword ptr [edi]
// 006d3494  5e                   pop esi
// 006d3495  896804               mov dword ptr [eax + 4], ebp
// 006d3498  5d                   pop ebp
// 006d3499  8908                 mov dword ptr [eax], ecx
// 006d349b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006d349f  5b                   pop ebx
// 006d34a0  5f                   pop edi
// 006d34a1  64890d00000000       mov dword ptr fs:[0], ecx
// 006d34a8  83c450               add esp, 0x50
// 006d34ab  c21000               ret 0x10
// standard library map_int<pod12> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod12>
struct E { int v[3]; };
#include <map>
template class std::map<int, E>;
