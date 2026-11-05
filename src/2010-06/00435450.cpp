// from server: 100% by auto
// roc 2010-06 00435450  unit: CPropGrid::UpdateItemsJob  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00435450
//
// 00435450  64a100000000         mov eax, dword ptr fs:[0]
// 00435456  6aff                 push -1
// 00435458  68e22f9a00           push 0x9a2fe2
// 0043545d  50                   push eax
// 0043545e  64892500000000       mov dword ptr fs:[0], esp
// 00435465  83ec44               sub esp, 0x44
// 00435468  57                   push edi
// 00435469  8bf9                 mov edi, ecx
// 0043546b  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 00435472  7259                 jb 0x4354cd
// 00435474  68a800a000           push 0xa000a8
// 00435479  8d4c2408             lea ecx, [esp + 8]
// 0043547d  ff1510a49e00         call dword ptr [0x9ea410]
// 00435483  8d4c2420             lea ecx, [esp + 0x20]
// 00435487  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0043548f  ff1518a99e00         call dword ptr [0x9ea918]
// 00435495  8d442404             lea eax, [esp + 4]
// 00435499  50                   push eax
// 0043549a  8d4c2430             lea ecx, [esp + 0x30]
// 0043549e  c644245401           mov byte ptr [esp + 0x54], 1
// 004354a3  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 004354ab  ff150ca49e00         call dword ptr [0x9ea40c]
// 004354b1  68601bb000           push 0xb01b60
// 004354b6  8d4c2424             lea ecx, [esp + 0x24]
// 004354ba  51                   push ecx
// 004354bb  c644245800           mov byte ptr [esp + 0x58], 0
// 004354c0  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 004354c8  e8e5343700           call 0x7a89b2
// 004354cd  8b542464             mov edx, dword ptr [esp + 0x64]
// 004354d1  8b4718               mov eax, dword ptr [edi + 0x18]
// 004354d4  53                   push ebx
// 004354d5  55                   push ebp
// 004354d6  56                   push esi
// 004354d7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004354db  6a00                 push 0
// 004354dd  52                   push edx
// 004354de  50                   push eax
// 004354df  56                   push esi
// 004354e0  50                   push eax
// 004354e1  e8aafcffff           call 0x435190
// 004354e6  8be8                 mov ebp, eax
// 004354e8  8b4718               mov eax, dword ptr [edi + 0x18]
// 004354eb  bb01000000           mov ebx, 1
// 004354f0  015f1c               add dword ptr [edi + 0x1c], ebx
// 004354f3  3bf0                 cmp esi, eax
// 004354f5  7510                 jne 0x435507
// 004354f7  896804               mov dword ptr [eax + 4], ebp
// 004354fa  8b4718               mov eax, dword ptr [edi + 0x18]
// 004354fd  8928                 mov dword ptr [eax], ebp
// 004354ff  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00435502  896908               mov dword ptr [ecx + 8], ebp
// 00435505  eb22                 jmp 0x435529
// 00435507  807c246800           cmp byte ptr [esp + 0x68], 0
// 0043550c  740d                 je 0x43551b
// 0043550e  892e                 mov dword ptr [esi], ebp
// 00435510  8b4718               mov eax, dword ptr [edi + 0x18]
// 00435513  3b30                 cmp esi, dword ptr [eax]
// 00435515  7512                 jne 0x435529
// 00435517  8928                 mov dword ptr [eax], ebp
// 00435519  eb0e                 jmp 0x435529
// 0043551b  896e08               mov dword ptr [esi + 8], ebp
// 0043551e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00435521  3b7008               cmp esi, dword ptr [eax + 8]
// 00435524  7503                 jne 0x435529
// 00435526  896808               mov dword ptr [eax + 8], ebp
// 00435529  8b5504               mov edx, dword ptr [ebp + 4]
// 0043552c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00435530  8d4504               lea eax, [ebp + 4]
// 00435533  8bf5                 mov esi, ebp
// 00435535  0f85ea000000         jne 0x435625
// 0043553b  eb03                 jmp 0x435540
// 0043553d  8d4900               lea ecx, [ecx]
// 00435540  8b08                 mov ecx, dword ptr [eax]
// 00435542  8b5104               mov edx, dword ptr [ecx + 4]
// 00435545  3b0a                 cmp ecx, dword ptr [edx]
// 00435547  7551                 jne 0x43559a
// 00435549  8b5208               mov edx, dword ptr [edx + 8]
// 0043554c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00435550  7519                 jne 0x43556b
// 00435552  885918               mov byte ptr [ecx + 0x18], bl
// 00435555  885a18               mov byte ptr [edx + 0x18], bl
// 00435558  8b10                 mov edx, dword ptr [eax]
// 0043555a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0043555d  c6411800             mov byte ptr [ecx + 0x18], 0
// 00435561  8b10                 mov edx, dword ptr [eax]
// 00435563  8b7204               mov esi, dword ptr [edx + 4]
// 00435566  e9aa000000           jmp 0x435615
// 0043556b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0043556e  750a                 jne 0x43557a
// 00435570  8bf1                 mov esi, ecx
// 00435572  56                   push esi
// 00435573  8bcf                 mov ecx, edi
// 00435575  e866130b00           call 0x4e68e0
// 0043557a  8b4604               mov eax, dword ptr [esi + 4]
// 0043557d  885818               mov byte ptr [eax + 0x18], bl
// 00435580  8b4e04               mov ecx, dword ptr [esi + 4]
// 00435583  8b5104               mov edx, dword ptr [ecx + 4]
// 00435586  c6421800             mov byte ptr [edx + 0x18], 0
// 0043558a  8b4604               mov eax, dword ptr [esi + 4]
// 0043558d  8b4804               mov ecx, dword ptr [eax + 4]
// 00435590  51                   push ecx
// 00435591  8bcf                 mov ecx, edi
// 00435593  e818d01b00           call 0x5f25b0
// 00435598  eb7b                 jmp 0x435615
// 0043559a  8b12                 mov edx, dword ptr [edx]
// 0043559c  807a1800             cmp byte ptr [edx + 0x18], 0
// 004355a0  7516                 jne 0x4355b8
// 004355a2  885918               mov byte ptr [ecx + 0x18], bl
// 004355a5  885a18               mov byte ptr [edx + 0x18], bl
// 004355a8  8b10                 mov edx, dword ptr [eax]
// 004355aa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004355ad  c6411800             mov byte ptr [ecx + 0x18], 0
// 004355b1  8b10                 mov edx, dword ptr [eax]
// 004355b3  8b7204               mov esi, dword ptr [edx + 4]
// 004355b6  eb5d                 jmp 0x435615
// 004355b8  3b31                 cmp esi, dword ptr [ecx]
// 004355ba  750a                 jne 0x4355c6
// 004355bc  8bf1                 mov esi, ecx
// 004355be  56                   push esi
// 004355bf  8bcf                 mov ecx, edi
// 004355c1  e8eacf1b00           call 0x5f25b0
// 004355c6  8b4604               mov eax, dword ptr [esi + 4]
// 004355c9  885818               mov byte ptr [eax + 0x18], bl
// 004355cc  8b4e04               mov ecx, dword ptr [esi + 4]
// 004355cf  8b5104               mov edx, dword ptr [ecx + 4]
// 004355d2  c6421800             mov byte ptr [edx + 0x18], 0
// 004355d6  8b4604               mov eax, dword ptr [esi + 4]
// 004355d9  8b4004               mov eax, dword ptr [eax + 4]
// 004355dc  8b4808               mov ecx, dword ptr [eax + 8]
// 004355df  8b11                 mov edx, dword ptr [ecx]
// 004355e1  895008               mov dword ptr [eax + 8], edx
// 004355e4  8b11                 mov edx, dword ptr [ecx]
// 004355e6  807a1900             cmp byte ptr [edx + 0x19], 0
// 004355ea  7503                 jne 0x4355ef
// 004355ec  894204               mov dword ptr [edx + 4], eax
// 004355ef  8b5004               mov edx, dword ptr [eax + 4]
// 004355f2  895104               mov dword ptr [ecx + 4], edx
// 004355f5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004355f8  3b4204               cmp eax, dword ptr [edx + 4]
// 004355fb  7505                 jne 0x435602
// 004355fd  894a04               mov dword ptr [edx + 4], ecx
// 00435600  eb0e                 jmp 0x435610
// 00435602  8b5004               mov edx, dword ptr [eax + 4]
// 00435605  3b02                 cmp eax, dword ptr [edx]
// 00435607  7504                 jne 0x43560d
// 00435609  890a                 mov dword ptr [edx], ecx
// 0043560b  eb03                 jmp 0x435610
// 0043560d  894a08               mov dword ptr [edx + 8], ecx
// 00435610  8901                 mov dword ptr [ecx], eax
// 00435612  894804               mov dword ptr [eax + 4], ecx
// 00435615  8b4e04               mov ecx, dword ptr [esi + 4]
// 00435618  80791800             cmp byte ptr [ecx + 0x18], 0
// 0043561c  8d4604               lea eax, [esi + 4]
// 0043561f  0f841bffffff         je 0x435540
// 00435625  8b5718               mov edx, dword ptr [edi + 0x18]
// 00435628  8b4204               mov eax, dword ptr [edx + 4]
// 0043562b  885818               mov byte ptr [eax + 0x18], bl
// 0043562e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00435632  8b0f                 mov ecx, dword ptr [edi]
// 00435634  5e                   pop esi
// 00435635  896804               mov dword ptr [eax + 4], ebp
// 00435638  5d                   pop ebp
// 00435639  8908                 mov dword ptr [eax], ecx
// 0043563b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0043563f  5b                   pop ebx
// 00435640  5f                   pop edi
// 00435641  64890d00000000       mov dword ptr fs:[0], ecx
// 00435648  83c450               add esp, 0x50
// 0043564b  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
