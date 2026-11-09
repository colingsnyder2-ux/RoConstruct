// from server: 100% by auto
// roc 2010-06 004e46f0  unit: RBX::Network::IdSerializer  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e46f0
//
// 004e46f0  64a100000000         mov eax, dword ptr fs:[0]
// 004e46f6  6aff                 push -1
// 004e46f8  68e22f9a00           push 0x9a2fe2
// 004e46fd  50                   push eax
// 004e46fe  64892500000000       mov dword ptr fs:[0], esp
// 004e4705  83ec44               sub esp, 0x44
// 004e4708  57                   push edi
// 004e4709  8bf9                 mov edi, ecx
// 004e470b  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 004e4712  7259                 jb 0x4e476d
// 004e4714  68a800a000           push 0xa000a8
// 004e4719  8d4c2408             lea ecx, [esp + 8]
// 004e471d  ff1510a49e00         call dword ptr [0x9ea410]
// 004e4723  8d4c2420             lea ecx, [esp + 0x20]
// 004e4727  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004e472f  ff1518a99e00         call dword ptr [0x9ea918]
// 004e4735  8d442404             lea eax, [esp + 4]
// 004e4739  50                   push eax
// 004e473a  8d4c2430             lea ecx, [esp + 0x30]
// 004e473e  c644245401           mov byte ptr [esp + 0x54], 1
// 004e4743  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 004e474b  ff150ca49e00         call dword ptr [0x9ea40c]
// 004e4751  68601bb000           push 0xb01b60
// 004e4756  8d4c2424             lea ecx, [esp + 0x24]
// 004e475a  51                   push ecx
// 004e475b  c644245800           mov byte ptr [esp + 0x58], 0
// 004e4760  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 004e4768  e845422c00           call 0x7a89b2
// 004e476d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004e4771  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e4774  53                   push ebx
// 004e4775  55                   push ebp
// 004e4776  56                   push esi
// 004e4777  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004e477b  6a00                 push 0
// 004e477d  52                   push edx
// 004e477e  50                   push eax
// 004e477f  56                   push esi
// 004e4780  50                   push eax
// 004e4781  e8aafdffff           call 0x4e4530
// 004e4786  8be8                 mov ebp, eax
// 004e4788  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e478b  bb01000000           mov ebx, 1
// 004e4790  015f1c               add dword ptr [edi + 0x1c], ebx
// 004e4793  3bf0                 cmp esi, eax
// 004e4795  7510                 jne 0x4e47a7
// 004e4797  896804               mov dword ptr [eax + 4], ebp
// 004e479a  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e479d  8928                 mov dword ptr [eax], ebp
// 004e479f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004e47a2  896908               mov dword ptr [ecx + 8], ebp
// 004e47a5  eb22                 jmp 0x4e47c9
// 004e47a7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004e47ac  740d                 je 0x4e47bb
// 004e47ae  892e                 mov dword ptr [esi], ebp
// 004e47b0  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e47b3  3b30                 cmp esi, dword ptr [eax]
// 004e47b5  7512                 jne 0x4e47c9
// 004e47b7  8928                 mov dword ptr [eax], ebp
// 004e47b9  eb0e                 jmp 0x4e47c9
// 004e47bb  896e08               mov dword ptr [esi + 8], ebp
// 004e47be  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e47c1  3b7008               cmp esi, dword ptr [eax + 8]
// 004e47c4  7503                 jne 0x4e47c9
// 004e47c6  896808               mov dword ptr [eax + 8], ebp
// 004e47c9  8b5504               mov edx, dword ptr [ebp + 4]
// 004e47cc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004e47d0  8d4504               lea eax, [ebp + 4]
// 004e47d3  8bf5                 mov esi, ebp
// 004e47d5  0f85ea000000         jne 0x4e48c5
// 004e47db  eb03                 jmp 0x4e47e0
// 004e47dd  8d4900               lea ecx, [ecx]
// 004e47e0  8b08                 mov ecx, dword ptr [eax]
// 004e47e2  8b5104               mov edx, dword ptr [ecx + 4]
// 004e47e5  3b0a                 cmp ecx, dword ptr [edx]
// 004e47e7  7551                 jne 0x4e483a
// 004e47e9  8b5208               mov edx, dword ptr [edx + 8]
// 004e47ec  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004e47f0  7519                 jne 0x4e480b
// 004e47f2  88592c               mov byte ptr [ecx + 0x2c], bl
// 004e47f5  885a2c               mov byte ptr [edx + 0x2c], bl
// 004e47f8  8b10                 mov edx, dword ptr [eax]
// 004e47fa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004e47fd  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004e4801  8b10                 mov edx, dword ptr [eax]
// 004e4803  8b7204               mov esi, dword ptr [edx + 4]
// 004e4806  e9aa000000           jmp 0x4e48b5
// 004e480b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004e480e  750a                 jne 0x4e481a
// 004e4810  8bf1                 mov esi, ecx
// 004e4812  56                   push esi
// 004e4813  8bcf                 mov ecx, edi
// 004e4815  e8b64f2500           call 0x7397d0
// 004e481a  8b4604               mov eax, dword ptr [esi + 4]
// 004e481d  88582c               mov byte ptr [eax + 0x2c], bl
// 004e4820  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e4823  8b5104               mov edx, dword ptr [ecx + 4]
// 004e4826  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004e482a  8b4604               mov eax, dword ptr [esi + 4]
// 004e482d  8b4804               mov ecx, dword ptr [eax + 4]
// 004e4830  51                   push ecx
// 004e4831  8bcf                 mov ecx, edi
// 004e4833  e888c24700           call 0x960ac0
// 004e4838  eb7b                 jmp 0x4e48b5
// 004e483a  8b12                 mov edx, dword ptr [edx]
// 004e483c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004e4840  7516                 jne 0x4e4858
// 004e4842  88592c               mov byte ptr [ecx + 0x2c], bl
// 004e4845  885a2c               mov byte ptr [edx + 0x2c], bl
// 004e4848  8b10                 mov edx, dword ptr [eax]
// 004e484a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004e484d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004e4851  8b10                 mov edx, dword ptr [eax]
// 004e4853  8b7204               mov esi, dword ptr [edx + 4]
// 004e4856  eb5d                 jmp 0x4e48b5
// 004e4858  3b31                 cmp esi, dword ptr [ecx]
// 004e485a  750a                 jne 0x4e4866
// 004e485c  8bf1                 mov esi, ecx
// 004e485e  56                   push esi
// 004e485f  8bcf                 mov ecx, edi
// 004e4861  e85ac24700           call 0x960ac0
// 004e4866  8b4604               mov eax, dword ptr [esi + 4]
// 004e4869  88582c               mov byte ptr [eax + 0x2c], bl
// 004e486c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e486f  8b5104               mov edx, dword ptr [ecx + 4]
// 004e4872  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004e4876  8b4604               mov eax, dword ptr [esi + 4]
// 004e4879  8b4004               mov eax, dword ptr [eax + 4]
// 004e487c  8b4808               mov ecx, dword ptr [eax + 8]
// 004e487f  8b11                 mov edx, dword ptr [ecx]
// 004e4881  895008               mov dword ptr [eax + 8], edx
// 004e4884  8b11                 mov edx, dword ptr [ecx]
// 004e4886  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 004e488a  7503                 jne 0x4e488f
// 004e488c  894204               mov dword ptr [edx + 4], eax
// 004e488f  8b5004               mov edx, dword ptr [eax + 4]
// 004e4892  895104               mov dword ptr [ecx + 4], edx
// 004e4895  8b5718               mov edx, dword ptr [edi + 0x18]
// 004e4898  3b4204               cmp eax, dword ptr [edx + 4]
// 004e489b  7505                 jne 0x4e48a2
// 004e489d  894a04               mov dword ptr [edx + 4], ecx
// 004e48a0  eb0e                 jmp 0x4e48b0
// 004e48a2  8b5004               mov edx, dword ptr [eax + 4]
// 004e48a5  3b02                 cmp eax, dword ptr [edx]
// 004e48a7  7504                 jne 0x4e48ad
// 004e48a9  890a                 mov dword ptr [edx], ecx
// 004e48ab  eb03                 jmp 0x4e48b0
// 004e48ad  894a08               mov dword ptr [edx + 8], ecx
// 004e48b0  8901                 mov dword ptr [ecx], eax
// 004e48b2  894804               mov dword ptr [eax + 4], ecx
// 004e48b5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e48b8  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 004e48bc  8d4604               lea eax, [esi + 4]
// 004e48bf  0f841bffffff         je 0x4e47e0
// 004e48c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004e48c8  8b4204               mov eax, dword ptr [edx + 4]
// 004e48cb  88582c               mov byte ptr [eax + 0x2c], bl
// 004e48ce  8b442464             mov eax, dword ptr [esp + 0x64]
// 004e48d2  8b0f                 mov ecx, dword ptr [edi]
// 004e48d4  5e                   pop esi
// 004e48d5  896804               mov dword ptr [eax + 4], ebp
// 004e48d8  5d                   pop ebp
// 004e48d9  8908                 mov dword ptr [eax], ecx
// 004e48db  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004e48df  5b                   pop ebx
// 004e48e0  5f                   pop edi
// 004e48e1  64890d00000000       mov dword ptr fs:[0], ecx
// 004e48e8  83c450               add esp, 0x50
// 004e48eb  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
