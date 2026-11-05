// from server: 100% by auto
// roc 2010-06 004e3200  unit: RBX::Network::IdSerializer  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e3200
//
// 004e3200  64a100000000         mov eax, dword ptr fs:[0]
// 004e3206  6aff                 push -1
// 004e3208  68e22f9a00           push 0x9a2fe2
// 004e320d  50                   push eax
// 004e320e  64892500000000       mov dword ptr fs:[0], esp
// 004e3215  83ec44               sub esp, 0x44
// 004e3218  57                   push edi
// 004e3219  8bf9                 mov edi, ecx
// 004e321b  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 004e3222  7259                 jb 0x4e327d
// 004e3224  68a800a000           push 0xa000a8
// 004e3229  8d4c2408             lea ecx, [esp + 8]
// 004e322d  ff1510a49e00         call dword ptr [0x9ea410]
// 004e3233  8d4c2420             lea ecx, [esp + 0x20]
// 004e3237  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004e323f  ff1518a99e00         call dword ptr [0x9ea918]
// 004e3245  8d442404             lea eax, [esp + 4]
// 004e3249  50                   push eax
// 004e324a  8d4c2430             lea ecx, [esp + 0x30]
// 004e324e  c644245401           mov byte ptr [esp + 0x54], 1
// 004e3253  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 004e325b  ff150ca49e00         call dword ptr [0x9ea40c]
// 004e3261  68601bb000           push 0xb01b60
// 004e3266  8d4c2424             lea ecx, [esp + 0x24]
// 004e326a  51                   push ecx
// 004e326b  c644245800           mov byte ptr [esp + 0x58], 0
// 004e3270  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 004e3278  e835572c00           call 0x7a89b2
// 004e327d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004e3281  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e3284  53                   push ebx
// 004e3285  55                   push ebp
// 004e3286  56                   push esi
// 004e3287  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004e328b  6a00                 push 0
// 004e328d  52                   push edx
// 004e328e  50                   push eax
// 004e328f  56                   push esi
// 004e3290  50                   push eax
// 004e3291  e86af2ffff           call 0x4e2500
// 004e3296  8be8                 mov ebp, eax
// 004e3298  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e329b  bb01000000           mov ebx, 1
// 004e32a0  015f1c               add dword ptr [edi + 0x1c], ebx
// 004e32a3  3bf0                 cmp esi, eax
// 004e32a5  7510                 jne 0x4e32b7
// 004e32a7  896804               mov dword ptr [eax + 4], ebp
// 004e32aa  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e32ad  8928                 mov dword ptr [eax], ebp
// 004e32af  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004e32b2  896908               mov dword ptr [ecx + 8], ebp
// 004e32b5  eb22                 jmp 0x4e32d9
// 004e32b7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004e32bc  740d                 je 0x4e32cb
// 004e32be  892e                 mov dword ptr [esi], ebp
// 004e32c0  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e32c3  3b30                 cmp esi, dword ptr [eax]
// 004e32c5  7512                 jne 0x4e32d9
// 004e32c7  8928                 mov dword ptr [eax], ebp
// 004e32c9  eb0e                 jmp 0x4e32d9
// 004e32cb  896e08               mov dword ptr [esi + 8], ebp
// 004e32ce  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e32d1  3b7008               cmp esi, dword ptr [eax + 8]
// 004e32d4  7503                 jne 0x4e32d9
// 004e32d6  896808               mov dword ptr [eax + 8], ebp
// 004e32d9  8b5504               mov edx, dword ptr [ebp + 4]
// 004e32dc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004e32e0  8d4504               lea eax, [ebp + 4]
// 004e32e3  8bf5                 mov esi, ebp
// 004e32e5  0f85ea000000         jne 0x4e33d5
// 004e32eb  eb03                 jmp 0x4e32f0
// 004e32ed  8d4900               lea ecx, [ecx]
// 004e32f0  8b08                 mov ecx, dword ptr [eax]
// 004e32f2  8b5104               mov edx, dword ptr [ecx + 4]
// 004e32f5  3b0a                 cmp ecx, dword ptr [edx]
// 004e32f7  7551                 jne 0x4e334a
// 004e32f9  8b5208               mov edx, dword ptr [edx + 8]
// 004e32fc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004e3300  7519                 jne 0x4e331b
// 004e3302  88592c               mov byte ptr [ecx + 0x2c], bl
// 004e3305  885a2c               mov byte ptr [edx + 0x2c], bl
// 004e3308  8b10                 mov edx, dword ptr [eax]
// 004e330a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004e330d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004e3311  8b10                 mov edx, dword ptr [eax]
// 004e3313  8b7204               mov esi, dword ptr [edx + 4]
// 004e3316  e9aa000000           jmp 0x4e33c5
// 004e331b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004e331e  750a                 jne 0x4e332a
// 004e3320  8bf1                 mov esi, ecx
// 004e3322  56                   push esi
// 004e3323  8bcf                 mov ecx, edi
// 004e3325  e8a6642500           call 0x7397d0
// 004e332a  8b4604               mov eax, dword ptr [esi + 4]
// 004e332d  88582c               mov byte ptr [eax + 0x2c], bl
// 004e3330  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e3333  8b5104               mov edx, dword ptr [ecx + 4]
// 004e3336  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004e333a  8b4604               mov eax, dword ptr [esi + 4]
// 004e333d  8b4804               mov ecx, dword ptr [eax + 4]
// 004e3340  51                   push ecx
// 004e3341  8bcf                 mov ecx, edi
// 004e3343  e878d74700           call 0x960ac0
// 004e3348  eb7b                 jmp 0x4e33c5
// 004e334a  8b12                 mov edx, dword ptr [edx]
// 004e334c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004e3350  7516                 jne 0x4e3368
// 004e3352  88592c               mov byte ptr [ecx + 0x2c], bl
// 004e3355  885a2c               mov byte ptr [edx + 0x2c], bl
// 004e3358  8b10                 mov edx, dword ptr [eax]
// 004e335a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004e335d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004e3361  8b10                 mov edx, dword ptr [eax]
// 004e3363  8b7204               mov esi, dword ptr [edx + 4]
// 004e3366  eb5d                 jmp 0x4e33c5
// 004e3368  3b31                 cmp esi, dword ptr [ecx]
// 004e336a  750a                 jne 0x4e3376
// 004e336c  8bf1                 mov esi, ecx
// 004e336e  56                   push esi
// 004e336f  8bcf                 mov ecx, edi
// 004e3371  e84ad74700           call 0x960ac0
// 004e3376  8b4604               mov eax, dword ptr [esi + 4]
// 004e3379  88582c               mov byte ptr [eax + 0x2c], bl
// 004e337c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e337f  8b5104               mov edx, dword ptr [ecx + 4]
// 004e3382  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004e3386  8b4604               mov eax, dword ptr [esi + 4]
// 004e3389  8b4004               mov eax, dword ptr [eax + 4]
// 004e338c  8b4808               mov ecx, dword ptr [eax + 8]
// 004e338f  8b11                 mov edx, dword ptr [ecx]
// 004e3391  895008               mov dword ptr [eax + 8], edx
// 004e3394  8b11                 mov edx, dword ptr [ecx]
// 004e3396  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 004e339a  7503                 jne 0x4e339f
// 004e339c  894204               mov dword ptr [edx + 4], eax
// 004e339f  8b5004               mov edx, dword ptr [eax + 4]
// 004e33a2  895104               mov dword ptr [ecx + 4], edx
// 004e33a5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004e33a8  3b4204               cmp eax, dword ptr [edx + 4]
// 004e33ab  7505                 jne 0x4e33b2
// 004e33ad  894a04               mov dword ptr [edx + 4], ecx
// 004e33b0  eb0e                 jmp 0x4e33c0
// 004e33b2  8b5004               mov edx, dword ptr [eax + 4]
// 004e33b5  3b02                 cmp eax, dword ptr [edx]
// 004e33b7  7504                 jne 0x4e33bd
// 004e33b9  890a                 mov dword ptr [edx], ecx
// 004e33bb  eb03                 jmp 0x4e33c0
// 004e33bd  894a08               mov dword ptr [edx + 8], ecx
// 004e33c0  8901                 mov dword ptr [ecx], eax
// 004e33c2  894804               mov dword ptr [eax + 4], ecx
// 004e33c5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e33c8  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 004e33cc  8d4604               lea eax, [esi + 4]
// 004e33cf  0f841bffffff         je 0x4e32f0
// 004e33d5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004e33d8  8b4204               mov eax, dword ptr [edx + 4]
// 004e33db  88582c               mov byte ptr [eax + 0x2c], bl
// 004e33de  8b442464             mov eax, dword ptr [esp + 0x64]
// 004e33e2  8b0f                 mov ecx, dword ptr [edi]
// 004e33e4  5e                   pop esi
// 004e33e5  896804               mov dword ptr [eax + 4], ebp
// 004e33e8  5d                   pop ebp
// 004e33e9  8908                 mov dword ptr [eax], ecx
// 004e33eb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004e33ef  5b                   pop ebx
// 004e33f0  5f                   pop edi
// 004e33f1  64890d00000000       mov dword ptr fs:[0], ecx
// 004e33f8  83c450               add esp, 0x50
// 004e33fb  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
