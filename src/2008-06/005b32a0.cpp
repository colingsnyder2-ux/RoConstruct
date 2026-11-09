// from server: 100% by auto
// roc 2008-06 005b32a0  unit: RBX::VHat::?$FactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b32a0
//
// 005b32a0  64a100000000         mov eax, dword ptr fs:[0]
// 005b32a6  6aff                 push -1
// 005b32a8  6842e87d00           push 0x7de842
// 005b32ad  50                   push eax
// 005b32ae  64892500000000       mov dword ptr fs:[0], esp
// 005b32b5  83ec44               sub esp, 0x44
// 005b32b8  57                   push edi
// 005b32b9  8bf9                 mov edi, ecx
// 005b32bb  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 005b32c2  7259                 jb 0x5b331d
// 005b32c4  688cb28000           push 0x80b28c
// 005b32c9  8d4c2408             lea ecx, [esp + 8]
// 005b32cd  ff1558248000         call dword ptr [0x802458]
// 005b32d3  8d4c2420             lea ecx, [esp + 0x20]
// 005b32d7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005b32df  ff1598288000         call dword ptr [0x802898]
// 005b32e5  8d442404             lea eax, [esp + 4]
// 005b32e9  50                   push eax
// 005b32ea  8d4c2430             lea ecx, [esp + 0x30]
// 005b32ee  c644245401           mov byte ptr [esp + 0x54], 1
// 005b32f3  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 005b32fb  ff155c248000         call dword ptr [0x80245c]
// 005b3301  68c00c8d00           push 0x8d0cc0
// 005b3306  8d4c2424             lea ecx, [esp + 0x24]
// 005b330a  51                   push ecx
// 005b330b  c644245800           mov byte ptr [esp + 0x58], 0
// 005b3310  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 005b3318  e86fe20e00           call 0x6a158c
// 005b331d  8b542464             mov edx, dword ptr [esp + 0x64]
// 005b3321  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b3324  53                   push ebx
// 005b3325  55                   push ebp
// 005b3326  56                   push esi
// 005b3327  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005b332b  6a00                 push 0
// 005b332d  52                   push edx
// 005b332e  50                   push eax
// 005b332f  56                   push esi
// 005b3330  50                   push eax
// 005b3331  e84afcffff           call 0x5b2f80
// 005b3336  8be8                 mov ebp, eax
// 005b3338  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b333b  bb01000000           mov ebx, 1
// 005b3340  015f1c               add dword ptr [edi + 0x1c], ebx
// 005b3343  3bf0                 cmp esi, eax
// 005b3345  7510                 jne 0x5b3357
// 005b3347  896804               mov dword ptr [eax + 4], ebp
// 005b334a  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b334d  8928                 mov dword ptr [eax], ebp
// 005b334f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005b3352  896908               mov dword ptr [ecx + 8], ebp
// 005b3355  eb22                 jmp 0x5b3379
// 005b3357  807c246800           cmp byte ptr [esp + 0x68], 0
// 005b335c  740d                 je 0x5b336b
// 005b335e  892e                 mov dword ptr [esi], ebp
// 005b3360  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b3363  3b30                 cmp esi, dword ptr [eax]
// 005b3365  7512                 jne 0x5b3379
// 005b3367  8928                 mov dword ptr [eax], ebp
// 005b3369  eb0e                 jmp 0x5b3379
// 005b336b  896e08               mov dword ptr [esi + 8], ebp
// 005b336e  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b3371  3b7008               cmp esi, dword ptr [eax + 8]
// 005b3374  7503                 jne 0x5b3379
// 005b3376  896808               mov dword ptr [eax + 8], ebp
// 005b3379  8b5504               mov edx, dword ptr [ebp + 4]
// 005b337c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 005b3380  8d4504               lea eax, [ebp + 4]
// 005b3383  8bf5                 mov esi, ebp
// 005b3385  0f85ea000000         jne 0x5b3475
// 005b338b  eb03                 jmp 0x5b3390
// 005b338d  8d4900               lea ecx, [ecx]
// 005b3390  8b08                 mov ecx, dword ptr [eax]
// 005b3392  8b5104               mov edx, dword ptr [ecx + 4]
// 005b3395  3b0a                 cmp ecx, dword ptr [edx]
// 005b3397  7551                 jne 0x5b33ea
// 005b3399  8b5208               mov edx, dword ptr [edx + 8]
// 005b339c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 005b33a0  7519                 jne 0x5b33bb
// 005b33a2  88592c               mov byte ptr [ecx + 0x2c], bl
// 005b33a5  885a2c               mov byte ptr [edx + 0x2c], bl
// 005b33a8  8b10                 mov edx, dword ptr [eax]
// 005b33aa  8b4a04               mov ecx, dword ptr [edx + 4]
// 005b33ad  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 005b33b1  8b10                 mov edx, dword ptr [eax]
// 005b33b3  8b7204               mov esi, dword ptr [edx + 4]
// 005b33b6  e9aa000000           jmp 0x5b3465
// 005b33bb  3b7108               cmp esi, dword ptr [ecx + 8]
// 005b33be  750a                 jne 0x5b33ca
// 005b33c0  8bf1                 mov esi, ecx
// 005b33c2  56                   push esi
// 005b33c3  8bcf                 mov ecx, edi
// 005b33c5  e836ab0d00           call 0x68df00
// 005b33ca  8b4604               mov eax, dword ptr [esi + 4]
// 005b33cd  88582c               mov byte ptr [eax + 0x2c], bl
// 005b33d0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b33d3  8b5104               mov edx, dword ptr [ecx + 4]
// 005b33d6  c6422c00             mov byte ptr [edx + 0x2c], 0
// 005b33da  8b4604               mov eax, dword ptr [esi + 4]
// 005b33dd  8b4804               mov ecx, dword ptr [eax + 4]
// 005b33e0  51                   push ecx
// 005b33e1  8bcf                 mov ecx, edi
// 005b33e3  e8e89b0d00           call 0x68cfd0
// 005b33e8  eb7b                 jmp 0x5b3465
// 005b33ea  8b12                 mov edx, dword ptr [edx]
// 005b33ec  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 005b33f0  7516                 jne 0x5b3408
// 005b33f2  88592c               mov byte ptr [ecx + 0x2c], bl
// 005b33f5  885a2c               mov byte ptr [edx + 0x2c], bl
// 005b33f8  8b10                 mov edx, dword ptr [eax]
// 005b33fa  8b4a04               mov ecx, dword ptr [edx + 4]
// 005b33fd  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 005b3401  8b10                 mov edx, dword ptr [eax]
// 005b3403  8b7204               mov esi, dword ptr [edx + 4]
// 005b3406  eb5d                 jmp 0x5b3465
// 005b3408  3b31                 cmp esi, dword ptr [ecx]
// 005b340a  750a                 jne 0x5b3416
// 005b340c  8bf1                 mov esi, ecx
// 005b340e  56                   push esi
// 005b340f  8bcf                 mov ecx, edi
// 005b3411  e8ba9b0d00           call 0x68cfd0
// 005b3416  8b4604               mov eax, dword ptr [esi + 4]
// 005b3419  88582c               mov byte ptr [eax + 0x2c], bl
// 005b341c  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b341f  8b5104               mov edx, dword ptr [ecx + 4]
// 005b3422  c6422c00             mov byte ptr [edx + 0x2c], 0
// 005b3426  8b4604               mov eax, dword ptr [esi + 4]
// 005b3429  8b4004               mov eax, dword ptr [eax + 4]
// 005b342c  8b4808               mov ecx, dword ptr [eax + 8]
// 005b342f  8b11                 mov edx, dword ptr [ecx]
// 005b3431  895008               mov dword ptr [eax + 8], edx
// 005b3434  8b11                 mov edx, dword ptr [ecx]
// 005b3436  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 005b343a  7503                 jne 0x5b343f
// 005b343c  894204               mov dword ptr [edx + 4], eax
// 005b343f  8b5004               mov edx, dword ptr [eax + 4]
// 005b3442  895104               mov dword ptr [ecx + 4], edx
// 005b3445  8b5718               mov edx, dword ptr [edi + 0x18]
// 005b3448  3b4204               cmp eax, dword ptr [edx + 4]
// 005b344b  7505                 jne 0x5b3452
// 005b344d  894a04               mov dword ptr [edx + 4], ecx
// 005b3450  eb0e                 jmp 0x5b3460
// 005b3452  8b5004               mov edx, dword ptr [eax + 4]
// 005b3455  3b02                 cmp eax, dword ptr [edx]
// 005b3457  7504                 jne 0x5b345d
// 005b3459  890a                 mov dword ptr [edx], ecx
// 005b345b  eb03                 jmp 0x5b3460
// 005b345d  894a08               mov dword ptr [edx + 8], ecx
// 005b3460  8901                 mov dword ptr [ecx], eax
// 005b3462  894804               mov dword ptr [eax + 4], ecx
// 005b3465  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b3468  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 005b346c  8d4604               lea eax, [esi + 4]
// 005b346f  0f841bffffff         je 0x5b3390
// 005b3475  8b5718               mov edx, dword ptr [edi + 0x18]
// 005b3478  8b4204               mov eax, dword ptr [edx + 4]
// 005b347b  88582c               mov byte ptr [eax + 0x2c], bl
// 005b347e  8b442464             mov eax, dword ptr [esp + 0x64]
// 005b3482  8b0f                 mov ecx, dword ptr [edi]
// 005b3484  5e                   pop esi
// 005b3485  896804               mov dword ptr [eax + 4], ebp
// 005b3488  5d                   pop ebp
// 005b3489  8908                 mov dword ptr [eax], ecx
// 005b348b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005b348f  5b                   pop ebx
// 005b3490  5f                   pop edi
// 005b3491  64890d00000000       mov dword ptr fs:[0], ecx
// 005b3498  83c450               add esp, 0x50
// 005b349b  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
