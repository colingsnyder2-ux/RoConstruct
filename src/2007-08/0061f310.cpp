// from server: 100% by auto
// roc 2007-08 0061f310  unit: RBX::ScoreHud  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061f310
//
// 0061f310  64a100000000         mov eax, dword ptr fs:[0]
// 0061f316  6aff                 push -1
// 0061f318  68b2417500           push 0x7541b2
// 0061f31d  50                   push eax
// 0061f31e  64892500000000       mov dword ptr fs:[0], esp
// 0061f325  83ec44               sub esp, 0x44
// 0061f328  57                   push edi
// 0061f329  8bf9                 mov edi, ecx
// 0061f32b  817f08feffff0f       cmp dword ptr [edi + 8], 0xffffffe
// 0061f332  7259                 jb 0x61f38d
// 0061f334  68904f7800           push 0x784f90
// 0061f339  8d4c2408             lea ecx, [esp + 8]
// 0061f33d  ff1598e67700         call dword ptr [0x77e698]
// 0061f343  8d4c2420             lea ecx, [esp + 0x20]
// 0061f347  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0061f34f  ff15f8e67700         call dword ptr [0x77e6f8]
// 0061f355  8d442404             lea eax, [esp + 4]
// 0061f359  50                   push eax
// 0061f35a  8d4c2430             lea ecx, [esp + 0x30]
// 0061f35e  c644245401           mov byte ptr [esp + 0x54], 1
// 0061f363  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 0061f36b  ff159ce67700         call dword ptr [0x77e69c]
// 0061f371  6878f78300           push 0x83f778
// 0061f376  8d4c2424             lea ecx, [esp + 0x24]
// 0061f37a  51                   push ecx
// 0061f37b  c644245800           mov byte ptr [esp + 0x58], 0
// 0061f380  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 0061f388  e811180100           call 0x630b9e
// 0061f38d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0061f391  8b4704               mov eax, dword ptr [edi + 4]
// 0061f394  53                   push ebx
// 0061f395  55                   push ebp
// 0061f396  56                   push esi
// 0061f397  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0061f39b  6a00                 push 0
// 0061f39d  52                   push edx
// 0061f39e  50                   push eax
// 0061f39f  56                   push esi
// 0061f3a0  50                   push eax
// 0061f3a1  e8aaf8ffff           call 0x61ec50
// 0061f3a6  8be8                 mov ebp, eax
// 0061f3a8  8b4704               mov eax, dword ptr [edi + 4]
// 0061f3ab  bb01000000           mov ebx, 1
// 0061f3b0  015f08               add dword ptr [edi + 8], ebx
// 0061f3b3  3bf0                 cmp esi, eax
// 0061f3b5  7510                 jne 0x61f3c7
// 0061f3b7  896804               mov dword ptr [eax + 4], ebp
// 0061f3ba  8b4704               mov eax, dword ptr [edi + 4]
// 0061f3bd  8928                 mov dword ptr [eax], ebp
// 0061f3bf  8b4f04               mov ecx, dword ptr [edi + 4]
// 0061f3c2  896908               mov dword ptr [ecx + 8], ebp
// 0061f3c5  eb22                 jmp 0x61f3e9
// 0061f3c7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0061f3cc  740d                 je 0x61f3db
// 0061f3ce  892e                 mov dword ptr [esi], ebp
// 0061f3d0  8b4704               mov eax, dword ptr [edi + 4]
// 0061f3d3  3b30                 cmp esi, dword ptr [eax]
// 0061f3d5  7512                 jne 0x61f3e9
// 0061f3d7  8928                 mov dword ptr [eax], ebp
// 0061f3d9  eb0e                 jmp 0x61f3e9
// 0061f3db  896e08               mov dword ptr [esi + 8], ebp
// 0061f3de  8b4704               mov eax, dword ptr [edi + 4]
// 0061f3e1  3b7008               cmp esi, dword ptr [eax + 8]
// 0061f3e4  7503                 jne 0x61f3e9
// 0061f3e6  896808               mov dword ptr [eax + 8], ebp
// 0061f3e9  8b5504               mov edx, dword ptr [ebp + 4]
// 0061f3ec  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 0061f3f0  8d4504               lea eax, [ebp + 4]
// 0061f3f3  8bf5                 mov esi, ebp
// 0061f3f5  0f85ea000000         jne 0x61f4e5
// 0061f3fb  eb03                 jmp 0x61f400
// 0061f3fd  8d4900               lea ecx, [ecx]
// 0061f400  8b08                 mov ecx, dword ptr [eax]
// 0061f402  8b5104               mov edx, dword ptr [ecx + 4]
// 0061f405  3b0a                 cmp ecx, dword ptr [edx]
// 0061f407  7551                 jne 0x61f45a
// 0061f409  8b5208               mov edx, dword ptr [edx + 8]
// 0061f40c  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 0061f410  7519                 jne 0x61f42b
// 0061f412  88591c               mov byte ptr [ecx + 0x1c], bl
// 0061f415  885a1c               mov byte ptr [edx + 0x1c], bl
// 0061f418  8b10                 mov edx, dword ptr [eax]
// 0061f41a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0061f41d  c6411c00             mov byte ptr [ecx + 0x1c], 0
// 0061f421  8b10                 mov edx, dword ptr [eax]
// 0061f423  8b7204               mov esi, dword ptr [edx + 4]
// 0061f426  e9aa000000           jmp 0x61f4d5
// 0061f42b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0061f42e  750a                 jne 0x61f43a
// 0061f430  8bf1                 mov esi, ecx
// 0061f432  56                   push esi
// 0061f433  8bcf                 mov ecx, edi
// 0061f435  e85602edff           call 0x4ef690
// 0061f43a  8b4604               mov eax, dword ptr [esi + 4]
// 0061f43d  88581c               mov byte ptr [eax + 0x1c], bl
// 0061f440  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061f443  8b5104               mov edx, dword ptr [ecx + 4]
// 0061f446  c6421c00             mov byte ptr [edx + 0x1c], 0
// 0061f44a  8b4604               mov eax, dword ptr [esi + 4]
// 0061f44d  8b4804               mov ecx, dword ptr [eax + 4]
// 0061f450  51                   push ecx
// 0061f451  8bcf                 mov ecx, edi
// 0061f453  e878e5ffff           call 0x61d9d0
// 0061f458  eb7b                 jmp 0x61f4d5
// 0061f45a  8b12                 mov edx, dword ptr [edx]
// 0061f45c  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 0061f460  7516                 jne 0x61f478
// 0061f462  88591c               mov byte ptr [ecx + 0x1c], bl
// 0061f465  885a1c               mov byte ptr [edx + 0x1c], bl
// 0061f468  8b10                 mov edx, dword ptr [eax]
// 0061f46a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0061f46d  c6411c00             mov byte ptr [ecx + 0x1c], 0
// 0061f471  8b10                 mov edx, dword ptr [eax]
// 0061f473  8b7204               mov esi, dword ptr [edx + 4]
// 0061f476  eb5d                 jmp 0x61f4d5
// 0061f478  3b31                 cmp esi, dword ptr [ecx]
// 0061f47a  750a                 jne 0x61f486
// 0061f47c  8bf1                 mov esi, ecx
// 0061f47e  56                   push esi
// 0061f47f  8bcf                 mov ecx, edi
// 0061f481  e84ae5ffff           call 0x61d9d0
// 0061f486  8b4604               mov eax, dword ptr [esi + 4]
// 0061f489  88581c               mov byte ptr [eax + 0x1c], bl
// 0061f48c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061f48f  8b5104               mov edx, dword ptr [ecx + 4]
// 0061f492  c6421c00             mov byte ptr [edx + 0x1c], 0
// 0061f496  8b4604               mov eax, dword ptr [esi + 4]
// 0061f499  8b4004               mov eax, dword ptr [eax + 4]
// 0061f49c  8b4808               mov ecx, dword ptr [eax + 8]
// 0061f49f  8b11                 mov edx, dword ptr [ecx]
// 0061f4a1  895008               mov dword ptr [eax + 8], edx
// 0061f4a4  8b11                 mov edx, dword ptr [ecx]
// 0061f4a6  807a1d00             cmp byte ptr [edx + 0x1d], 0
// 0061f4aa  7503                 jne 0x61f4af
// 0061f4ac  894204               mov dword ptr [edx + 4], eax
// 0061f4af  8b5004               mov edx, dword ptr [eax + 4]
// 0061f4b2  895104               mov dword ptr [ecx + 4], edx
// 0061f4b5  8b5704               mov edx, dword ptr [edi + 4]
// 0061f4b8  3b4204               cmp eax, dword ptr [edx + 4]
// 0061f4bb  7505                 jne 0x61f4c2
// 0061f4bd  894a04               mov dword ptr [edx + 4], ecx
// 0061f4c0  eb0e                 jmp 0x61f4d0
// 0061f4c2  8b5004               mov edx, dword ptr [eax + 4]
// 0061f4c5  3b02                 cmp eax, dword ptr [edx]
// 0061f4c7  7504                 jne 0x61f4cd
// 0061f4c9  890a                 mov dword ptr [edx], ecx
// 0061f4cb  eb03                 jmp 0x61f4d0
// 0061f4cd  894a08               mov dword ptr [edx + 8], ecx
// 0061f4d0  8901                 mov dword ptr [ecx], eax
// 0061f4d2  894804               mov dword ptr [eax + 4], ecx
// 0061f4d5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061f4d8  80791c00             cmp byte ptr [ecx + 0x1c], 0
// 0061f4dc  8d4604               lea eax, [esi + 4]
// 0061f4df  0f841bffffff         je 0x61f400
// 0061f4e5  8b5704               mov edx, dword ptr [edi + 4]
// 0061f4e8  8b4204               mov eax, dword ptr [edx + 4]
// 0061f4eb  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0061f4ef  88581c               mov byte ptr [eax + 0x1c], bl
// 0061f4f2  8b442464             mov eax, dword ptr [esp + 0x64]
// 0061f4f6  5e                   pop esi
// 0061f4f7  896804               mov dword ptr [eax + 4], ebp
// 0061f4fa  5d                   pop ebp
// 0061f4fb  8938                 mov dword ptr [eax], edi
// 0061f4fd  5b                   pop ebx
// 0061f4fe  5f                   pop edi
// 0061f4ff  64890d00000000       mov dword ptr fs:[0], ecx
// 0061f506  83c450               add esp, 0x50
// 0061f509  c21000               ret 0x10
// standard library map_int<pod12> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod12>
struct E { int v[3]; };
#include <map>
template class std::map<int, E>;
