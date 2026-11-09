// from server: 100% by auto
// roc 2007-08 0061f110  unit: RBX::ScoreHud  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061f110
//
// 0061f110  64a100000000         mov eax, dword ptr fs:[0]
// 0061f116  6aff                 push -1
// 0061f118  68b2417500           push 0x7541b2
// 0061f11d  50                   push eax
// 0061f11e  64892500000000       mov dword ptr fs:[0], esp
// 0061f125  83ec44               sub esp, 0x44
// 0061f128  57                   push edi
// 0061f129  8bf9                 mov edi, ecx
// 0061f12b  817f0865666606       cmp dword ptr [edi + 8], 0x6666665
// 0061f132  7259                 jb 0x61f18d
// 0061f134  68904f7800           push 0x784f90
// 0061f139  8d4c2408             lea ecx, [esp + 8]
// 0061f13d  ff1598e67700         call dword ptr [0x77e698]
// 0061f143  8d4c2420             lea ecx, [esp + 0x20]
// 0061f147  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0061f14f  ff15f8e67700         call dword ptr [0x77e6f8]
// 0061f155  8d442404             lea eax, [esp + 4]
// 0061f159  50                   push eax
// 0061f15a  8d4c2430             lea ecx, [esp + 0x30]
// 0061f15e  c644245401           mov byte ptr [esp + 0x54], 1
// 0061f163  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 0061f16b  ff159ce67700         call dword ptr [0x77e69c]
// 0061f171  6878f78300           push 0x83f778
// 0061f176  8d4c2424             lea ecx, [esp + 0x24]
// 0061f17a  51                   push ecx
// 0061f17b  c644245800           mov byte ptr [esp + 0x58], 0
// 0061f180  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 0061f188  e8111a0100           call 0x630b9e
// 0061f18d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0061f191  8b4704               mov eax, dword ptr [edi + 4]
// 0061f194  53                   push ebx
// 0061f195  55                   push ebp
// 0061f196  56                   push esi
// 0061f197  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0061f19b  6a00                 push 0
// 0061f19d  52                   push edx
// 0061f19e  50                   push eax
// 0061f19f  56                   push esi
// 0061f1a0  50                   push eax
// 0061f1a1  e80afaffff           call 0x61ebb0
// 0061f1a6  8be8                 mov ebp, eax
// 0061f1a8  8b4704               mov eax, dword ptr [edi + 4]
// 0061f1ab  bb01000000           mov ebx, 1
// 0061f1b0  015f08               add dword ptr [edi + 8], ebx
// 0061f1b3  3bf0                 cmp esi, eax
// 0061f1b5  7510                 jne 0x61f1c7
// 0061f1b7  896804               mov dword ptr [eax + 4], ebp
// 0061f1ba  8b4704               mov eax, dword ptr [edi + 4]
// 0061f1bd  8928                 mov dword ptr [eax], ebp
// 0061f1bf  8b4f04               mov ecx, dword ptr [edi + 4]
// 0061f1c2  896908               mov dword ptr [ecx + 8], ebp
// 0061f1c5  eb22                 jmp 0x61f1e9
// 0061f1c7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0061f1cc  740d                 je 0x61f1db
// 0061f1ce  892e                 mov dword ptr [esi], ebp
// 0061f1d0  8b4704               mov eax, dword ptr [edi + 4]
// 0061f1d3  3b30                 cmp esi, dword ptr [eax]
// 0061f1d5  7512                 jne 0x61f1e9
// 0061f1d7  8928                 mov dword ptr [eax], ebp
// 0061f1d9  eb0e                 jmp 0x61f1e9
// 0061f1db  896e08               mov dword ptr [esi + 8], ebp
// 0061f1de  8b4704               mov eax, dword ptr [edi + 4]
// 0061f1e1  3b7008               cmp esi, dword ptr [eax + 8]
// 0061f1e4  7503                 jne 0x61f1e9
// 0061f1e6  896808               mov dword ptr [eax + 8], ebp
// 0061f1e9  8b5504               mov edx, dword ptr [ebp + 4]
// 0061f1ec  807a3400             cmp byte ptr [edx + 0x34], 0
// 0061f1f0  8d4504               lea eax, [ebp + 4]
// 0061f1f3  8bf5                 mov esi, ebp
// 0061f1f5  0f85ea000000         jne 0x61f2e5
// 0061f1fb  eb03                 jmp 0x61f200
// 0061f1fd  8d4900               lea ecx, [ecx]
// 0061f200  8b08                 mov ecx, dword ptr [eax]
// 0061f202  8b5104               mov edx, dword ptr [ecx + 4]
// 0061f205  3b0a                 cmp ecx, dword ptr [edx]
// 0061f207  7551                 jne 0x61f25a
// 0061f209  8b5208               mov edx, dword ptr [edx + 8]
// 0061f20c  807a3400             cmp byte ptr [edx + 0x34], 0
// 0061f210  7519                 jne 0x61f22b
// 0061f212  885934               mov byte ptr [ecx + 0x34], bl
// 0061f215  885a34               mov byte ptr [edx + 0x34], bl
// 0061f218  8b10                 mov edx, dword ptr [eax]
// 0061f21a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0061f21d  c6413400             mov byte ptr [ecx + 0x34], 0
// 0061f221  8b10                 mov edx, dword ptr [eax]
// 0061f223  8b7204               mov esi, dword ptr [edx + 4]
// 0061f226  e9aa000000           jmp 0x61f2d5
// 0061f22b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0061f22e  750a                 jne 0x61f23a
// 0061f230  8bf1                 mov esi, ecx
// 0061f232  56                   push esi
// 0061f233  8bcf                 mov ecx, edi
// 0061f235  e8268df6ff           call 0x587f60
// 0061f23a  8b4604               mov eax, dword ptr [esi + 4]
// 0061f23d  885834               mov byte ptr [eax + 0x34], bl
// 0061f240  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061f243  8b5104               mov edx, dword ptr [ecx + 4]
// 0061f246  c6423400             mov byte ptr [edx + 0x34], 0
// 0061f24a  8b4604               mov eax, dword ptr [esi + 4]
// 0061f24d  8b4804               mov ecx, dword ptr [eax + 4]
// 0061f250  51                   push ecx
// 0061f251  8bcf                 mov ecx, edi
// 0061f253  e80888f6ff           call 0x587a60
// 0061f258  eb7b                 jmp 0x61f2d5
// 0061f25a  8b12                 mov edx, dword ptr [edx]
// 0061f25c  807a3400             cmp byte ptr [edx + 0x34], 0
// 0061f260  7516                 jne 0x61f278
// 0061f262  885934               mov byte ptr [ecx + 0x34], bl
// 0061f265  885a34               mov byte ptr [edx + 0x34], bl
// 0061f268  8b10                 mov edx, dword ptr [eax]
// 0061f26a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0061f26d  c6413400             mov byte ptr [ecx + 0x34], 0
// 0061f271  8b10                 mov edx, dword ptr [eax]
// 0061f273  8b7204               mov esi, dword ptr [edx + 4]
// 0061f276  eb5d                 jmp 0x61f2d5
// 0061f278  3b31                 cmp esi, dword ptr [ecx]
// 0061f27a  750a                 jne 0x61f286
// 0061f27c  8bf1                 mov esi, ecx
// 0061f27e  56                   push esi
// 0061f27f  8bcf                 mov ecx, edi
// 0061f281  e8da87f6ff           call 0x587a60
// 0061f286  8b4604               mov eax, dword ptr [esi + 4]
// 0061f289  885834               mov byte ptr [eax + 0x34], bl
// 0061f28c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061f28f  8b5104               mov edx, dword ptr [ecx + 4]
// 0061f292  c6423400             mov byte ptr [edx + 0x34], 0
// 0061f296  8b4604               mov eax, dword ptr [esi + 4]
// 0061f299  8b4004               mov eax, dword ptr [eax + 4]
// 0061f29c  8b4808               mov ecx, dword ptr [eax + 8]
// 0061f29f  8b11                 mov edx, dword ptr [ecx]
// 0061f2a1  895008               mov dword ptr [eax + 8], edx
// 0061f2a4  8b11                 mov edx, dword ptr [ecx]
// 0061f2a6  807a3500             cmp byte ptr [edx + 0x35], 0
// 0061f2aa  7503                 jne 0x61f2af
// 0061f2ac  894204               mov dword ptr [edx + 4], eax
// 0061f2af  8b5004               mov edx, dword ptr [eax + 4]
// 0061f2b2  895104               mov dword ptr [ecx + 4], edx
// 0061f2b5  8b5704               mov edx, dword ptr [edi + 4]
// 0061f2b8  3b4204               cmp eax, dword ptr [edx + 4]
// 0061f2bb  7505                 jne 0x61f2c2
// 0061f2bd  894a04               mov dword ptr [edx + 4], ecx
// 0061f2c0  eb0e                 jmp 0x61f2d0
// 0061f2c2  8b5004               mov edx, dword ptr [eax + 4]
// 0061f2c5  3b02                 cmp eax, dword ptr [edx]
// 0061f2c7  7504                 jne 0x61f2cd
// 0061f2c9  890a                 mov dword ptr [edx], ecx
// 0061f2cb  eb03                 jmp 0x61f2d0
// 0061f2cd  894a08               mov dword ptr [edx + 8], ecx
// 0061f2d0  8901                 mov dword ptr [ecx], eax
// 0061f2d2  894804               mov dword ptr [eax + 4], ecx
// 0061f2d5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061f2d8  80793400             cmp byte ptr [ecx + 0x34], 0
// 0061f2dc  8d4604               lea eax, [esi + 4]
// 0061f2df  0f841bffffff         je 0x61f200
// 0061f2e5  8b5704               mov edx, dword ptr [edi + 4]
// 0061f2e8  8b4204               mov eax, dword ptr [edx + 4]
// 0061f2eb  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0061f2ef  885834               mov byte ptr [eax + 0x34], bl
// 0061f2f2  8b442464             mov eax, dword ptr [esp + 0x64]
// 0061f2f6  5e                   pop esi
// 0061f2f7  896804               mov dword ptr [eax + 4], ebp
// 0061f2fa  5d                   pop ebp
// 0061f2fb  8938                 mov dword ptr [eax], edi
// 0061f2fd  5b                   pop ebx
// 0061f2fe  5f                   pop edi
// 0061f2ff  64890d00000000       mov dword ptr fs:[0], ecx
// 0061f306  83c450               add esp, 0x50
// 0061f309  c21000               ret 0x10
// standard library map_int<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
