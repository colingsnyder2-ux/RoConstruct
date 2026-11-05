// from server: 100% by auto
// roc 2007-08 004f03e0  unit: RBX::Render::AggregatingSceneManager  size: 493 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004f03e0
//
// 004f03e0  6aff                 push -1
// 004f03e2  68293a7400           push 0x743a29
// 004f03e7  64a100000000         mov eax, dword ptr fs:[0]
// 004f03ed  50                   push eax
// 004f03ee  83ec44               sub esp, 0x44
// 004f03f1  53                   push ebx
// 004f03f2  55                   push ebp
// 004f03f3  56                   push esi
// 004f03f4  57                   push edi
// 004f03f5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004f03fa  33c4                 xor eax, esp
// 004f03fc  50                   push eax
// 004f03fd  8d442458             lea eax, [esp + 0x58]
// 004f0401  64a300000000         mov dword ptr fs:[0], eax
// 004f0407  8bf9                 mov edi, ecx
// 004f0409  817f08feffff0f       cmp dword ptr [edi + 8], 0xffffffe
// 004f0410  723c                 jb 0x4f044e
// 004f0412  68904f7800           push 0x784f90
// 004f0417  8d4c2418             lea ecx, [esp + 0x18]
// 004f041b  ff1598e67700         call dword ptr [0x77e698]
// 004f0421  8d442414             lea eax, [esp + 0x14]
// 004f0425  50                   push eax
// 004f0426  8d4c2434             lea ecx, [esp + 0x34]
// 004f042a  c744246400000000     mov dword ptr [esp + 0x64], 0
// 004f0432  e88920f1ff           call 0x4024c0
// 004f0437  6878f78300           push 0x83f778
// 004f043c  8d4c2434             lea ecx, [esp + 0x34]
// 004f0440  51                   push ecx
// 004f0441  c74424386c4e7800     mov dword ptr [esp + 0x38], 0x784e6c
// 004f0449  e850071400           call 0x630b9e
// 004f044e  8b542474             mov edx, dword ptr [esp + 0x74]
// 004f0452  8b4704               mov eax, dword ptr [edi + 4]
// 004f0455  8b742470             mov esi, dword ptr [esp + 0x70]
// 004f0459  6a00                 push 0
// 004f045b  52                   push edx
// 004f045c  50                   push eax
// 004f045d  56                   push esi
// 004f045e  50                   push eax
// 004f045f  e8fcfbffff           call 0x4f0060
// 004f0464  8be8                 mov ebp, eax
// 004f0466  8b4704               mov eax, dword ptr [edi + 4]
// 004f0469  bb01000000           mov ebx, 1
// 004f046e  015f08               add dword ptr [edi + 8], ebx
// 004f0471  3bf0                 cmp esi, eax
// 004f0473  7510                 jne 0x4f0485
// 004f0475  896804               mov dword ptr [eax + 4], ebp
// 004f0478  8b4704               mov eax, dword ptr [edi + 4]
// 004f047b  8928                 mov dword ptr [eax], ebp
// 004f047d  8b4f04               mov ecx, dword ptr [edi + 4]
// 004f0480  896908               mov dword ptr [ecx + 8], ebp
// 004f0483  eb22                 jmp 0x4f04a7
// 004f0485  807c246c00           cmp byte ptr [esp + 0x6c], 0
// 004f048a  740d                 je 0x4f0499
// 004f048c  892e                 mov dword ptr [esi], ebp
// 004f048e  8b4704               mov eax, dword ptr [edi + 4]
// 004f0491  3b30                 cmp esi, dword ptr [eax]
// 004f0493  7512                 jne 0x4f04a7
// 004f0495  8928                 mov dword ptr [eax], ebp
// 004f0497  eb0e                 jmp 0x4f04a7
// 004f0499  896e08               mov dword ptr [esi + 8], ebp
// 004f049c  8b4704               mov eax, dword ptr [edi + 4]
// 004f049f  3b7008               cmp esi, dword ptr [eax + 8]
// 004f04a2  7503                 jne 0x4f04a7
// 004f04a4  896808               mov dword ptr [eax + 8], ebp
// 004f04a7  8b5504               mov edx, dword ptr [ebp + 4]
// 004f04aa  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 004f04ae  8d4504               lea eax, [ebp + 4]
// 004f04b1  8bf5                 mov esi, ebp
// 004f04b3  0f85ec000000         jne 0x4f05a5
// 004f04b9  8da42400000000       lea esp, [esp]
// 004f04c0  8b08                 mov ecx, dword ptr [eax]
// 004f04c2  8b5104               mov edx, dword ptr [ecx + 4]
// 004f04c5  3b0a                 cmp ecx, dword ptr [edx]
// 004f04c7  7551                 jne 0x4f051a
// 004f04c9  8b5208               mov edx, dword ptr [edx + 8]
// 004f04cc  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 004f04d0  7519                 jne 0x4f04eb
// 004f04d2  88591c               mov byte ptr [ecx + 0x1c], bl
// 004f04d5  885a1c               mov byte ptr [edx + 0x1c], bl
// 004f04d8  8b10                 mov edx, dword ptr [eax]
// 004f04da  8b4a04               mov ecx, dword ptr [edx + 4]
// 004f04dd  c6411c00             mov byte ptr [ecx + 0x1c], 0
// 004f04e1  8b10                 mov edx, dword ptr [eax]
// 004f04e3  8b7204               mov esi, dword ptr [edx + 4]
// 004f04e6  e9aa000000           jmp 0x4f0595
// 004f04eb  3b7108               cmp esi, dword ptr [ecx + 8]
// 004f04ee  750a                 jne 0x4f04fa
// 004f04f0  8bf1                 mov esi, ecx
// 004f04f2  56                   push esi
// 004f04f3  8bcf                 mov ecx, edi
// 004f04f5  e896f1ffff           call 0x4ef690
// 004f04fa  8b4604               mov eax, dword ptr [esi + 4]
// 004f04fd  88581c               mov byte ptr [eax + 0x1c], bl
// 004f0500  8b4e04               mov ecx, dword ptr [esi + 4]
// 004f0503  8b5104               mov edx, dword ptr [ecx + 4]
// 004f0506  c6421c00             mov byte ptr [edx + 0x1c], 0
// 004f050a  8b4604               mov eax, dword ptr [esi + 4]
// 004f050d  8b4804               mov ecx, dword ptr [eax + 4]
// 004f0510  51                   push ecx
// 004f0511  8bcf                 mov ecx, edi
// 004f0513  e8b8d41200           call 0x61d9d0
// 004f0518  eb7b                 jmp 0x4f0595
// 004f051a  8b12                 mov edx, dword ptr [edx]
// 004f051c  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 004f0520  7516                 jne 0x4f0538
// 004f0522  88591c               mov byte ptr [ecx + 0x1c], bl
// 004f0525  885a1c               mov byte ptr [edx + 0x1c], bl
// 004f0528  8b10                 mov edx, dword ptr [eax]
// 004f052a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004f052d  c6411c00             mov byte ptr [ecx + 0x1c], 0
// 004f0531  8b10                 mov edx, dword ptr [eax]
// 004f0533  8b7204               mov esi, dword ptr [edx + 4]
// 004f0536  eb5d                 jmp 0x4f0595
// 004f0538  3b31                 cmp esi, dword ptr [ecx]
// 004f053a  750a                 jne 0x4f0546
// 004f053c  8bf1                 mov esi, ecx
// 004f053e  56                   push esi
// 004f053f  8bcf                 mov ecx, edi
// 004f0541  e88ad41200           call 0x61d9d0
// 004f0546  8b4604               mov eax, dword ptr [esi + 4]
// 004f0549  88581c               mov byte ptr [eax + 0x1c], bl
// 004f054c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004f054f  8b5104               mov edx, dword ptr [ecx + 4]
// 004f0552  c6421c00             mov byte ptr [edx + 0x1c], 0
// 004f0556  8b4604               mov eax, dword ptr [esi + 4]
// 004f0559  8b4004               mov eax, dword ptr [eax + 4]
// 004f055c  8b4808               mov ecx, dword ptr [eax + 8]
// 004f055f  8b11                 mov edx, dword ptr [ecx]
// 004f0561  895008               mov dword ptr [eax + 8], edx
// 004f0564  8b11                 mov edx, dword ptr [ecx]
// 004f0566  807a1d00             cmp byte ptr [edx + 0x1d], 0
// 004f056a  7503                 jne 0x4f056f
// 004f056c  894204               mov dword ptr [edx + 4], eax
// 004f056f  8b5004               mov edx, dword ptr [eax + 4]
// 004f0572  895104               mov dword ptr [ecx + 4], edx
// 004f0575  8b5704               mov edx, dword ptr [edi + 4]
// 004f0578  3b4204               cmp eax, dword ptr [edx + 4]
// 004f057b  7505                 jne 0x4f0582
// 004f057d  894a04               mov dword ptr [edx + 4], ecx
// 004f0580  eb0e                 jmp 0x4f0590
// 004f0582  8b5004               mov edx, dword ptr [eax + 4]
// 004f0585  3b02                 cmp eax, dword ptr [edx]
// 004f0587  7504                 jne 0x4f058d
// 004f0589  890a                 mov dword ptr [edx], ecx
// 004f058b  eb03                 jmp 0x4f0590
// 004f058d  894a08               mov dword ptr [edx + 8], ecx
// 004f0590  8901                 mov dword ptr [ecx], eax
// 004f0592  894804               mov dword ptr [eax + 4], ecx
// 004f0595  8b4e04               mov ecx, dword ptr [esi + 4]
// 004f0598  80791c00             cmp byte ptr [ecx + 0x1c], 0
// 004f059c  8d4604               lea eax, [esi + 4]
// 004f059f  0f841bffffff         je 0x4f04c0
// 004f05a5  8b5704               mov edx, dword ptr [edi + 4]
// 004f05a8  8b4204               mov eax, dword ptr [edx + 4]
// 004f05ab  88581c               mov byte ptr [eax + 0x1c], bl
// 004f05ae  8b442468             mov eax, dword ptr [esp + 0x68]
// 004f05b2  896804               mov dword ptr [eax + 4], ebp
// 004f05b5  8938                 mov dword ptr [eax], edi
// 004f05b7  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 004f05bb  64890d00000000       mov dword ptr fs:[0], ecx
// 004f05c2  59                   pop ecx
// 004f05c3  5f                   pop edi
// 004f05c4  5e                   pop esi
// 004f05c5  5d                   pop ebp
// 004f05c6  5b                   pop ebx
// 004f05c7  83c450               add esp, 0x50
// 004f05ca  c21000               ret 0x10
// standard library map_int<pod12> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod12>
struct E { int v[3]; };
#include <map>
template class std::map<int, E>;
