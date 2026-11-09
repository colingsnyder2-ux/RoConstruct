// from server: 100% by auto
// roc 2007-08 00604e60  unit: RBX::SleepStage  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00604e60
//
// 00604e60  64a100000000         mov eax, dword ptr fs:[0]
// 00604e66  6aff                 push -1
// 00604e68  68b2417500           push 0x7541b2
// 00604e6d  50                   push eax
// 00604e6e  64892500000000       mov dword ptr fs:[0], esp
// 00604e75  83ec44               sub esp, 0x44
// 00604e78  57                   push edi
// 00604e79  8bf9                 mov edi, ecx
// 00604e7b  817f0854555515       cmp dword ptr [edi + 8], 0x15555554
// 00604e82  7259                 jb 0x604edd
// 00604e84  68904f7800           push 0x784f90
// 00604e89  8d4c2408             lea ecx, [esp + 8]
// 00604e8d  ff1598e67700         call dword ptr [0x77e698]
// 00604e93  8d4c2420             lea ecx, [esp + 0x20]
// 00604e97  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00604e9f  ff15f8e67700         call dword ptr [0x77e6f8]
// 00604ea5  8d442404             lea eax, [esp + 4]
// 00604ea9  50                   push eax
// 00604eaa  8d4c2430             lea ecx, [esp + 0x30]
// 00604eae  c644245401           mov byte ptr [esp + 0x54], 1
// 00604eb3  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 00604ebb  ff159ce67700         call dword ptr [0x77e69c]
// 00604ec1  6878f78300           push 0x83f778
// 00604ec6  8d4c2424             lea ecx, [esp + 0x24]
// 00604eca  51                   push ecx
// 00604ecb  c644245800           mov byte ptr [esp + 0x58], 0
// 00604ed0  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 00604ed8  e8c1bc0200           call 0x630b9e
// 00604edd  8b542464             mov edx, dword ptr [esp + 0x64]
// 00604ee1  8b4704               mov eax, dword ptr [edi + 4]
// 00604ee4  53                   push ebx
// 00604ee5  55                   push ebp
// 00604ee6  56                   push esi
// 00604ee7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00604eeb  6a00                 push 0
// 00604eed  52                   push edx
// 00604eee  50                   push eax
// 00604eef  56                   push esi
// 00604ef0  50                   push eax
// 00604ef1  e89afeffff           call 0x604d90
// 00604ef6  8be8                 mov ebp, eax
// 00604ef8  8b4704               mov eax, dword ptr [edi + 4]
// 00604efb  bb01000000           mov ebx, 1
// 00604f00  015f08               add dword ptr [edi + 8], ebx
// 00604f03  3bf0                 cmp esi, eax
// 00604f05  7510                 jne 0x604f17
// 00604f07  896804               mov dword ptr [eax + 4], ebp
// 00604f0a  8b4704               mov eax, dword ptr [edi + 4]
// 00604f0d  8928                 mov dword ptr [eax], ebp
// 00604f0f  8b4f04               mov ecx, dword ptr [edi + 4]
// 00604f12  896908               mov dword ptr [ecx + 8], ebp
// 00604f15  eb22                 jmp 0x604f39
// 00604f17  807c246800           cmp byte ptr [esp + 0x68], 0
// 00604f1c  740d                 je 0x604f2b
// 00604f1e  892e                 mov dword ptr [esi], ebp
// 00604f20  8b4704               mov eax, dword ptr [edi + 4]
// 00604f23  3b30                 cmp esi, dword ptr [eax]
// 00604f25  7512                 jne 0x604f39
// 00604f27  8928                 mov dword ptr [eax], ebp
// 00604f29  eb0e                 jmp 0x604f39
// 00604f2b  896e08               mov dword ptr [esi + 8], ebp
// 00604f2e  8b4704               mov eax, dword ptr [edi + 4]
// 00604f31  3b7008               cmp esi, dword ptr [eax + 8]
// 00604f34  7503                 jne 0x604f39
// 00604f36  896808               mov dword ptr [eax + 8], ebp
// 00604f39  8b5504               mov edx, dword ptr [ebp + 4]
// 00604f3c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00604f40  8d4504               lea eax, [ebp + 4]
// 00604f43  8bf5                 mov esi, ebp
// 00604f45  0f85ea000000         jne 0x605035
// 00604f4b  eb03                 jmp 0x604f50
// 00604f4d  8d4900               lea ecx, [ecx]
// 00604f50  8b08                 mov ecx, dword ptr [eax]
// 00604f52  8b5104               mov edx, dword ptr [ecx + 4]
// 00604f55  3b0a                 cmp ecx, dword ptr [edx]
// 00604f57  7551                 jne 0x604faa
// 00604f59  8b5208               mov edx, dword ptr [edx + 8]
// 00604f5c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00604f60  7519                 jne 0x604f7b
// 00604f62  885918               mov byte ptr [ecx + 0x18], bl
// 00604f65  885a18               mov byte ptr [edx + 0x18], bl
// 00604f68  8b10                 mov edx, dword ptr [eax]
// 00604f6a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00604f6d  c6411800             mov byte ptr [ecx + 0x18], 0
// 00604f71  8b10                 mov edx, dword ptr [eax]
// 00604f73  8b7204               mov esi, dword ptr [edx + 4]
// 00604f76  e9aa000000           jmp 0x605025
// 00604f7b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00604f7e  750a                 jne 0x604f8a
// 00604f80  8bf1                 mov esi, ecx
// 00604f82  56                   push esi
// 00604f83  8bcf                 mov ecx, edi
// 00604f85  e83695fdff           call 0x5de4c0
// 00604f8a  8b4604               mov eax, dword ptr [esi + 4]
// 00604f8d  885818               mov byte ptr [eax + 0x18], bl
// 00604f90  8b4e04               mov ecx, dword ptr [esi + 4]
// 00604f93  8b5104               mov edx, dword ptr [ecx + 4]
// 00604f96  c6421800             mov byte ptr [edx + 0x18], 0
// 00604f9a  8b4604               mov eax, dword ptr [esi + 4]
// 00604f9d  8b4804               mov ecx, dword ptr [eax + 4]
// 00604fa0  51                   push ecx
// 00604fa1  8bcf                 mov ecx, edi
// 00604fa3  e8e8a4e0ff           call 0x40f490
// 00604fa8  eb7b                 jmp 0x605025
// 00604faa  8b12                 mov edx, dword ptr [edx]
// 00604fac  807a1800             cmp byte ptr [edx + 0x18], 0
// 00604fb0  7516                 jne 0x604fc8
// 00604fb2  885918               mov byte ptr [ecx + 0x18], bl
// 00604fb5  885a18               mov byte ptr [edx + 0x18], bl
// 00604fb8  8b10                 mov edx, dword ptr [eax]
// 00604fba  8b4a04               mov ecx, dword ptr [edx + 4]
// 00604fbd  c6411800             mov byte ptr [ecx + 0x18], 0
// 00604fc1  8b10                 mov edx, dword ptr [eax]
// 00604fc3  8b7204               mov esi, dword ptr [edx + 4]
// 00604fc6  eb5d                 jmp 0x605025
// 00604fc8  3b31                 cmp esi, dword ptr [ecx]
// 00604fca  750a                 jne 0x604fd6
// 00604fcc  8bf1                 mov esi, ecx
// 00604fce  56                   push esi
// 00604fcf  8bcf                 mov ecx, edi
// 00604fd1  e8baa4e0ff           call 0x40f490
// 00604fd6  8b4604               mov eax, dword ptr [esi + 4]
// 00604fd9  885818               mov byte ptr [eax + 0x18], bl
// 00604fdc  8b4e04               mov ecx, dword ptr [esi + 4]
// 00604fdf  8b5104               mov edx, dword ptr [ecx + 4]
// 00604fe2  c6421800             mov byte ptr [edx + 0x18], 0
// 00604fe6  8b4604               mov eax, dword ptr [esi + 4]
// 00604fe9  8b4004               mov eax, dword ptr [eax + 4]
// 00604fec  8b4808               mov ecx, dword ptr [eax + 8]
// 00604fef  8b11                 mov edx, dword ptr [ecx]
// 00604ff1  895008               mov dword ptr [eax + 8], edx
// 00604ff4  8b11                 mov edx, dword ptr [ecx]
// 00604ff6  807a1900             cmp byte ptr [edx + 0x19], 0
// 00604ffa  7503                 jne 0x604fff
// 00604ffc  894204               mov dword ptr [edx + 4], eax
// 00604fff  8b5004               mov edx, dword ptr [eax + 4]
// 00605002  895104               mov dword ptr [ecx + 4], edx
// 00605005  8b5704               mov edx, dword ptr [edi + 4]
// 00605008  3b4204               cmp eax, dword ptr [edx + 4]
// 0060500b  7505                 jne 0x605012
// 0060500d  894a04               mov dword ptr [edx + 4], ecx
// 00605010  eb0e                 jmp 0x605020
// 00605012  8b5004               mov edx, dword ptr [eax + 4]
// 00605015  3b02                 cmp eax, dword ptr [edx]
// 00605017  7504                 jne 0x60501d
// 00605019  890a                 mov dword ptr [edx], ecx
// 0060501b  eb03                 jmp 0x605020
// 0060501d  894a08               mov dword ptr [edx + 8], ecx
// 00605020  8901                 mov dword ptr [ecx], eax
// 00605022  894804               mov dword ptr [eax + 4], ecx
// 00605025  8b4e04               mov ecx, dword ptr [esi + 4]
// 00605028  80791800             cmp byte ptr [ecx + 0x18], 0
// 0060502c  8d4604               lea eax, [esi + 4]
// 0060502f  0f841bffffff         je 0x604f50
// 00605035  8b5704               mov edx, dword ptr [edi + 4]
// 00605038  8b4204               mov eax, dword ptr [edx + 4]
// 0060503b  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0060503f  885818               mov byte ptr [eax + 0x18], bl
// 00605042  8b442464             mov eax, dword ptr [esp + 0x64]
// 00605046  5e                   pop esi
// 00605047  896804               mov dword ptr [eax + 4], ebp
// 0060504a  5d                   pop ebp
// 0060504b  8938                 mov dword ptr [eax], edi
// 0060504d  5b                   pop ebx
// 0060504e  5f                   pop edi
// 0060504f  64890d00000000       mov dword ptr fs:[0], ecx
// 00605056  83c450               add esp, 0x50
// 00605059  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
