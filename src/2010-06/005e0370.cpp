// from server: 100% by auto
// roc 2010-06 005e0370  unit: RBX::GlobalSettings  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005e0370
//
// 005e0370  64a100000000         mov eax, dword ptr fs:[0]
// 005e0376  6aff                 push -1
// 005e0378  68e22f9a00           push 0x9a2fe2
// 005e037d  50                   push eax
// 005e037e  64892500000000       mov dword ptr fs:[0], esp
// 005e0385  83ec44               sub esp, 0x44
// 005e0388  57                   push edi
// 005e0389  8bf9                 mov edi, ecx
// 005e038b  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 005e0392  7259                 jb 0x5e03ed
// 005e0394  68a800a000           push 0xa000a8
// 005e0399  8d4c2408             lea ecx, [esp + 8]
// 005e039d  ff1510a49e00         call dword ptr [0x9ea410]
// 005e03a3  8d4c2420             lea ecx, [esp + 0x20]
// 005e03a7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005e03af  ff1518a99e00         call dword ptr [0x9ea918]
// 005e03b5  8d442404             lea eax, [esp + 4]
// 005e03b9  50                   push eax
// 005e03ba  8d4c2430             lea ecx, [esp + 0x30]
// 005e03be  c644245401           mov byte ptr [esp + 0x54], 1
// 005e03c3  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 005e03cb  ff150ca49e00         call dword ptr [0x9ea40c]
// 005e03d1  68601bb000           push 0xb01b60
// 005e03d6  8d4c2424             lea ecx, [esp + 0x24]
// 005e03da  51                   push ecx
// 005e03db  c644245800           mov byte ptr [esp + 0x58], 0
// 005e03e0  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 005e03e8  e8c5851c00           call 0x7a89b2
// 005e03ed  8b542464             mov edx, dword ptr [esp + 0x64]
// 005e03f1  8b4718               mov eax, dword ptr [edi + 0x18]
// 005e03f4  53                   push ebx
// 005e03f5  55                   push ebp
// 005e03f6  56                   push esi
// 005e03f7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005e03fb  6a00                 push 0
// 005e03fd  52                   push edx
// 005e03fe  50                   push eax
// 005e03ff  56                   push esi
// 005e0400  50                   push eax
// 005e0401  e88afeffff           call 0x5e0290
// 005e0406  8be8                 mov ebp, eax
// 005e0408  8b4718               mov eax, dword ptr [edi + 0x18]
// 005e040b  bb01000000           mov ebx, 1
// 005e0410  015f1c               add dword ptr [edi + 0x1c], ebx
// 005e0413  3bf0                 cmp esi, eax
// 005e0415  7510                 jne 0x5e0427
// 005e0417  896804               mov dword ptr [eax + 4], ebp
// 005e041a  8b4718               mov eax, dword ptr [edi + 0x18]
// 005e041d  8928                 mov dword ptr [eax], ebp
// 005e041f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005e0422  896908               mov dword ptr [ecx + 8], ebp
// 005e0425  eb22                 jmp 0x5e0449
// 005e0427  807c246800           cmp byte ptr [esp + 0x68], 0
// 005e042c  740d                 je 0x5e043b
// 005e042e  892e                 mov dword ptr [esi], ebp
// 005e0430  8b4718               mov eax, dword ptr [edi + 0x18]
// 005e0433  3b30                 cmp esi, dword ptr [eax]
// 005e0435  7512                 jne 0x5e0449
// 005e0437  8928                 mov dword ptr [eax], ebp
// 005e0439  eb0e                 jmp 0x5e0449
// 005e043b  896e08               mov dword ptr [esi + 8], ebp
// 005e043e  8b4718               mov eax, dword ptr [edi + 0x18]
// 005e0441  3b7008               cmp esi, dword ptr [eax + 8]
// 005e0444  7503                 jne 0x5e0449
// 005e0446  896808               mov dword ptr [eax + 8], ebp
// 005e0449  8b5504               mov edx, dword ptr [ebp + 4]
// 005e044c  807a1800             cmp byte ptr [edx + 0x18], 0
// 005e0450  8d4504               lea eax, [ebp + 4]
// 005e0453  8bf5                 mov esi, ebp
// 005e0455  0f85ea000000         jne 0x5e0545
// 005e045b  eb03                 jmp 0x5e0460
// 005e045d  8d4900               lea ecx, [ecx]
// 005e0460  8b08                 mov ecx, dword ptr [eax]
// 005e0462  8b5104               mov edx, dword ptr [ecx + 4]
// 005e0465  3b0a                 cmp ecx, dword ptr [edx]
// 005e0467  7551                 jne 0x5e04ba
// 005e0469  8b5208               mov edx, dword ptr [edx + 8]
// 005e046c  807a1800             cmp byte ptr [edx + 0x18], 0
// 005e0470  7519                 jne 0x5e048b
// 005e0472  885918               mov byte ptr [ecx + 0x18], bl
// 005e0475  885a18               mov byte ptr [edx + 0x18], bl
// 005e0478  8b10                 mov edx, dword ptr [eax]
// 005e047a  8b4a04               mov ecx, dword ptr [edx + 4]
// 005e047d  c6411800             mov byte ptr [ecx + 0x18], 0
// 005e0481  8b10                 mov edx, dword ptr [eax]
// 005e0483  8b7204               mov esi, dword ptr [edx + 4]
// 005e0486  e9aa000000           jmp 0x5e0535
// 005e048b  3b7108               cmp esi, dword ptr [ecx + 8]
// 005e048e  750a                 jne 0x5e049a
// 005e0490  8bf1                 mov esi, ecx
// 005e0492  56                   push esi
// 005e0493  8bcf                 mov ecx, edi
// 005e0495  e84664f0ff           call 0x4e68e0
// 005e049a  8b4604               mov eax, dword ptr [esi + 4]
// 005e049d  885818               mov byte ptr [eax + 0x18], bl
// 005e04a0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e04a3  8b5104               mov edx, dword ptr [ecx + 4]
// 005e04a6  c6421800             mov byte ptr [edx + 0x18], 0
// 005e04aa  8b4604               mov eax, dword ptr [esi + 4]
// 005e04ad  8b4804               mov ecx, dword ptr [eax + 4]
// 005e04b0  51                   push ecx
// 005e04b1  8bcf                 mov ecx, edi
// 005e04b3  e8f8200100           call 0x5f25b0
// 005e04b8  eb7b                 jmp 0x5e0535
// 005e04ba  8b12                 mov edx, dword ptr [edx]
// 005e04bc  807a1800             cmp byte ptr [edx + 0x18], 0
// 005e04c0  7516                 jne 0x5e04d8
// 005e04c2  885918               mov byte ptr [ecx + 0x18], bl
// 005e04c5  885a18               mov byte ptr [edx + 0x18], bl
// 005e04c8  8b10                 mov edx, dword ptr [eax]
// 005e04ca  8b4a04               mov ecx, dword ptr [edx + 4]
// 005e04cd  c6411800             mov byte ptr [ecx + 0x18], 0
// 005e04d1  8b10                 mov edx, dword ptr [eax]
// 005e04d3  8b7204               mov esi, dword ptr [edx + 4]
// 005e04d6  eb5d                 jmp 0x5e0535
// 005e04d8  3b31                 cmp esi, dword ptr [ecx]
// 005e04da  750a                 jne 0x5e04e6
// 005e04dc  8bf1                 mov esi, ecx
// 005e04de  56                   push esi
// 005e04df  8bcf                 mov ecx, edi
// 005e04e1  e8ca200100           call 0x5f25b0
// 005e04e6  8b4604               mov eax, dword ptr [esi + 4]
// 005e04e9  885818               mov byte ptr [eax + 0x18], bl
// 005e04ec  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e04ef  8b5104               mov edx, dword ptr [ecx + 4]
// 005e04f2  c6421800             mov byte ptr [edx + 0x18], 0
// 005e04f6  8b4604               mov eax, dword ptr [esi + 4]
// 005e04f9  8b4004               mov eax, dword ptr [eax + 4]
// 005e04fc  8b4808               mov ecx, dword ptr [eax + 8]
// 005e04ff  8b11                 mov edx, dword ptr [ecx]
// 005e0501  895008               mov dword ptr [eax + 8], edx
// 005e0504  8b11                 mov edx, dword ptr [ecx]
// 005e0506  807a1900             cmp byte ptr [edx + 0x19], 0
// 005e050a  7503                 jne 0x5e050f
// 005e050c  894204               mov dword ptr [edx + 4], eax
// 005e050f  8b5004               mov edx, dword ptr [eax + 4]
// 005e0512  895104               mov dword ptr [ecx + 4], edx
// 005e0515  8b5718               mov edx, dword ptr [edi + 0x18]
// 005e0518  3b4204               cmp eax, dword ptr [edx + 4]
// 005e051b  7505                 jne 0x5e0522
// 005e051d  894a04               mov dword ptr [edx + 4], ecx
// 005e0520  eb0e                 jmp 0x5e0530
// 005e0522  8b5004               mov edx, dword ptr [eax + 4]
// 005e0525  3b02                 cmp eax, dword ptr [edx]
// 005e0527  7504                 jne 0x5e052d
// 005e0529  890a                 mov dword ptr [edx], ecx
// 005e052b  eb03                 jmp 0x5e0530
// 005e052d  894a08               mov dword ptr [edx + 8], ecx
// 005e0530  8901                 mov dword ptr [ecx], eax
// 005e0532  894804               mov dword ptr [eax + 4], ecx
// 005e0535  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e0538  80791800             cmp byte ptr [ecx + 0x18], 0
// 005e053c  8d4604               lea eax, [esi + 4]
// 005e053f  0f841bffffff         je 0x5e0460
// 005e0545  8b5718               mov edx, dword ptr [edi + 0x18]
// 005e0548  8b4204               mov eax, dword ptr [edx + 4]
// 005e054b  885818               mov byte ptr [eax + 0x18], bl
// 005e054e  8b442464             mov eax, dword ptr [esp + 0x64]
// 005e0552  8b0f                 mov ecx, dword ptr [edi]
// 005e0554  5e                   pop esi
// 005e0555  896804               mov dword ptr [eax + 4], ebp
// 005e0558  5d                   pop ebp
// 005e0559  8908                 mov dword ptr [eax], ecx
// 005e055b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005e055f  5b                   pop ebx
// 005e0560  5f                   pop edi
// 005e0561  64890d00000000       mov dword ptr fs:[0], ecx
// 005e0568  83c450               add esp, 0x50
// 005e056b  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
