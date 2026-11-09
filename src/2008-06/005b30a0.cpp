// from server: 100% by auto
// roc 2008-06 005b30a0  unit: RBX::VHat::?$FactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b30a0
//
// 005b30a0  64a100000000         mov eax, dword ptr fs:[0]
// 005b30a6  6aff                 push -1
// 005b30a8  6842e87d00           push 0x7de842
// 005b30ad  50                   push eax
// 005b30ae  64892500000000       mov dword ptr fs:[0], esp
// 005b30b5  83ec44               sub esp, 0x44
// 005b30b8  57                   push edi
// 005b30b9  8bf9                 mov edi, ecx
// 005b30bb  817f1ccbcccc0c       cmp dword ptr [edi + 0x1c], 0xccccccb
// 005b30c2  7259                 jb 0x5b311d
// 005b30c4  688cb28000           push 0x80b28c
// 005b30c9  8d4c2408             lea ecx, [esp + 8]
// 005b30cd  ff1558248000         call dword ptr [0x802458]
// 005b30d3  8d4c2420             lea ecx, [esp + 0x20]
// 005b30d7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005b30df  ff1598288000         call dword ptr [0x802898]
// 005b30e5  8d442404             lea eax, [esp + 4]
// 005b30e9  50                   push eax
// 005b30ea  8d4c2430             lea ecx, [esp + 0x30]
// 005b30ee  c644245401           mov byte ptr [esp + 0x54], 1
// 005b30f3  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 005b30fb  ff155c248000         call dword ptr [0x80245c]
// 005b3101  68c00c8d00           push 0x8d0cc0
// 005b3106  8d4c2424             lea ecx, [esp + 0x24]
// 005b310a  51                   push ecx
// 005b310b  c644245800           mov byte ptr [esp + 0x58], 0
// 005b3110  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 005b3118  e86fe40e00           call 0x6a158c
// 005b311d  8b542464             mov edx, dword ptr [esp + 0x64]
// 005b3121  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b3124  53                   push ebx
// 005b3125  55                   push ebp
// 005b3126  56                   push esi
// 005b3127  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005b312b  6a00                 push 0
// 005b312d  52                   push edx
// 005b312e  50                   push eax
// 005b312f  56                   push esi
// 005b3130  50                   push eax
// 005b3131  e8eafdffff           call 0x5b2f20
// 005b3136  8be8                 mov ebp, eax
// 005b3138  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b313b  bb01000000           mov ebx, 1
// 005b3140  015f1c               add dword ptr [edi + 0x1c], ebx
// 005b3143  3bf0                 cmp esi, eax
// 005b3145  7510                 jne 0x5b3157
// 005b3147  896804               mov dword ptr [eax + 4], ebp
// 005b314a  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b314d  8928                 mov dword ptr [eax], ebp
// 005b314f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005b3152  896908               mov dword ptr [ecx + 8], ebp
// 005b3155  eb22                 jmp 0x5b3179
// 005b3157  807c246800           cmp byte ptr [esp + 0x68], 0
// 005b315c  740d                 je 0x5b316b
// 005b315e  892e                 mov dword ptr [esi], ebp
// 005b3160  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b3163  3b30                 cmp esi, dword ptr [eax]
// 005b3165  7512                 jne 0x5b3179
// 005b3167  8928                 mov dword ptr [eax], ebp
// 005b3169  eb0e                 jmp 0x5b3179
// 005b316b  896e08               mov dword ptr [esi + 8], ebp
// 005b316e  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b3171  3b7008               cmp esi, dword ptr [eax + 8]
// 005b3174  7503                 jne 0x5b3179
// 005b3176  896808               mov dword ptr [eax + 8], ebp
// 005b3179  8b5504               mov edx, dword ptr [ebp + 4]
// 005b317c  807a2000             cmp byte ptr [edx + 0x20], 0
// 005b3180  8d4504               lea eax, [ebp + 4]
// 005b3183  8bf5                 mov esi, ebp
// 005b3185  0f85ea000000         jne 0x5b3275
// 005b318b  eb03                 jmp 0x5b3190
// 005b318d  8d4900               lea ecx, [ecx]
// 005b3190  8b08                 mov ecx, dword ptr [eax]
// 005b3192  8b5104               mov edx, dword ptr [ecx + 4]
// 005b3195  3b0a                 cmp ecx, dword ptr [edx]
// 005b3197  7551                 jne 0x5b31ea
// 005b3199  8b5208               mov edx, dword ptr [edx + 8]
// 005b319c  807a2000             cmp byte ptr [edx + 0x20], 0
// 005b31a0  7519                 jne 0x5b31bb
// 005b31a2  885920               mov byte ptr [ecx + 0x20], bl
// 005b31a5  885a20               mov byte ptr [edx + 0x20], bl
// 005b31a8  8b10                 mov edx, dword ptr [eax]
// 005b31aa  8b4a04               mov ecx, dword ptr [edx + 4]
// 005b31ad  c6412000             mov byte ptr [ecx + 0x20], 0
// 005b31b1  8b10                 mov edx, dword ptr [eax]
// 005b31b3  8b7204               mov esi, dword ptr [edx + 4]
// 005b31b6  e9aa000000           jmp 0x5b3265
// 005b31bb  3b7108               cmp esi, dword ptr [ecx + 8]
// 005b31be  750a                 jne 0x5b31ca
// 005b31c0  8bf1                 mov esi, ecx
// 005b31c2  56                   push esi
// 005b31c3  8bcf                 mov ecx, edi
// 005b31c5  e82644f2ff           call 0x4d75f0
// 005b31ca  8b4604               mov eax, dword ptr [esi + 4]
// 005b31cd  885820               mov byte ptr [eax + 0x20], bl
// 005b31d0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b31d3  8b5104               mov edx, dword ptr [ecx + 4]
// 005b31d6  c6422000             mov byte ptr [edx + 0x20], 0
// 005b31da  8b4604               mov eax, dword ptr [esi + 4]
// 005b31dd  8b4804               mov ecx, dword ptr [eax + 4]
// 005b31e0  51                   push ecx
// 005b31e1  8bcf                 mov ecx, edi
// 005b31e3  e8d8fcffff           call 0x5b2ec0
// 005b31e8  eb7b                 jmp 0x5b3265
// 005b31ea  8b12                 mov edx, dword ptr [edx]
// 005b31ec  807a2000             cmp byte ptr [edx + 0x20], 0
// 005b31f0  7516                 jne 0x5b3208
// 005b31f2  885920               mov byte ptr [ecx + 0x20], bl
// 005b31f5  885a20               mov byte ptr [edx + 0x20], bl
// 005b31f8  8b10                 mov edx, dword ptr [eax]
// 005b31fa  8b4a04               mov ecx, dword ptr [edx + 4]
// 005b31fd  c6412000             mov byte ptr [ecx + 0x20], 0
// 005b3201  8b10                 mov edx, dword ptr [eax]
// 005b3203  8b7204               mov esi, dword ptr [edx + 4]
// 005b3206  eb5d                 jmp 0x5b3265
// 005b3208  3b31                 cmp esi, dword ptr [ecx]
// 005b320a  750a                 jne 0x5b3216
// 005b320c  8bf1                 mov esi, ecx
// 005b320e  56                   push esi
// 005b320f  8bcf                 mov ecx, edi
// 005b3211  e8aafcffff           call 0x5b2ec0
// 005b3216  8b4604               mov eax, dword ptr [esi + 4]
// 005b3219  885820               mov byte ptr [eax + 0x20], bl
// 005b321c  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b321f  8b5104               mov edx, dword ptr [ecx + 4]
// 005b3222  c6422000             mov byte ptr [edx + 0x20], 0
// 005b3226  8b4604               mov eax, dword ptr [esi + 4]
// 005b3229  8b4004               mov eax, dword ptr [eax + 4]
// 005b322c  8b4808               mov ecx, dword ptr [eax + 8]
// 005b322f  8b11                 mov edx, dword ptr [ecx]
// 005b3231  895008               mov dword ptr [eax + 8], edx
// 005b3234  8b11                 mov edx, dword ptr [ecx]
// 005b3236  807a2100             cmp byte ptr [edx + 0x21], 0
// 005b323a  7503                 jne 0x5b323f
// 005b323c  894204               mov dword ptr [edx + 4], eax
// 005b323f  8b5004               mov edx, dword ptr [eax + 4]
// 005b3242  895104               mov dword ptr [ecx + 4], edx
// 005b3245  8b5718               mov edx, dword ptr [edi + 0x18]
// 005b3248  3b4204               cmp eax, dword ptr [edx + 4]
// 005b324b  7505                 jne 0x5b3252
// 005b324d  894a04               mov dword ptr [edx + 4], ecx
// 005b3250  eb0e                 jmp 0x5b3260
// 005b3252  8b5004               mov edx, dword ptr [eax + 4]
// 005b3255  3b02                 cmp eax, dword ptr [edx]
// 005b3257  7504                 jne 0x5b325d
// 005b3259  890a                 mov dword ptr [edx], ecx
// 005b325b  eb03                 jmp 0x5b3260
// 005b325d  894a08               mov dword ptr [edx + 8], ecx
// 005b3260  8901                 mov dword ptr [ecx], eax
// 005b3262  894804               mov dword ptr [eax + 4], ecx
// 005b3265  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b3268  80792000             cmp byte ptr [ecx + 0x20], 0
// 005b326c  8d4604               lea eax, [esi + 4]
// 005b326f  0f841bffffff         je 0x5b3190
// 005b3275  8b5718               mov edx, dword ptr [edi + 0x18]
// 005b3278  8b4204               mov eax, dword ptr [edx + 4]
// 005b327b  885820               mov byte ptr [eax + 0x20], bl
// 005b327e  8b442464             mov eax, dword ptr [esp + 0x64]
// 005b3282  8b0f                 mov ecx, dword ptr [edi]
// 005b3284  5e                   pop esi
// 005b3285  896804               mov dword ptr [eax + 4], ebp
// 005b3288  5d                   pop ebp
// 005b3289  8908                 mov dword ptr [eax], ecx
// 005b328b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005b328f  5b                   pop ebx
// 005b3290  5f                   pop edi
// 005b3291  64890d00000000       mov dword ptr fs:[0], ecx
// 005b3298  83c450               add esp, 0x50
// 005b329b  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
