// from server: 100% by auto
// roc 2007-08 0062a030  unit: RBX::AssemblyStage  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0062a030
//
// 0062a030  64a100000000         mov eax, dword ptr fs:[0]
// 0062a036  6aff                 push -1
// 0062a038  68b2417500           push 0x7541b2
// 0062a03d  50                   push eax
// 0062a03e  64892500000000       mov dword ptr fs:[0], esp
// 0062a045  83ec44               sub esp, 0x44
// 0062a048  57                   push edi
// 0062a049  8bf9                 mov edi, ecx
// 0062a04b  817f0848922409       cmp dword ptr [edi + 8], 0x9249248
// 0062a052  7259                 jb 0x62a0ad
// 0062a054  68904f7800           push 0x784f90
// 0062a059  8d4c2408             lea ecx, [esp + 8]
// 0062a05d  ff1598e67700         call dword ptr [0x77e698]
// 0062a063  8d4c2420             lea ecx, [esp + 0x20]
// 0062a067  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0062a06f  ff15f8e67700         call dword ptr [0x77e6f8]
// 0062a075  8d442404             lea eax, [esp + 4]
// 0062a079  50                   push eax
// 0062a07a  8d4c2430             lea ecx, [esp + 0x30]
// 0062a07e  c644245401           mov byte ptr [esp + 0x54], 1
// 0062a083  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 0062a08b  ff159ce67700         call dword ptr [0x77e69c]
// 0062a091  6878f78300           push 0x83f778
// 0062a096  8d4c2424             lea ecx, [esp + 0x24]
// 0062a09a  51                   push ecx
// 0062a09b  c644245800           mov byte ptr [esp + 0x58], 0
// 0062a0a0  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 0062a0a8  e8f16a0000           call 0x630b9e
// 0062a0ad  8b542464             mov edx, dword ptr [esp + 0x64]
// 0062a0b1  8b4704               mov eax, dword ptr [edi + 4]
// 0062a0b4  53                   push ebx
// 0062a0b5  55                   push ebp
// 0062a0b6  56                   push esi
// 0062a0b7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0062a0bb  6a00                 push 0
// 0062a0bd  52                   push edx
// 0062a0be  50                   push eax
// 0062a0bf  56                   push esi
// 0062a0c0  50                   push eax
// 0062a0c1  e8cafeffff           call 0x629f90
// 0062a0c6  8be8                 mov ebp, eax
// 0062a0c8  8b4704               mov eax, dword ptr [edi + 4]
// 0062a0cb  bb01000000           mov ebx, 1
// 0062a0d0  015f08               add dword ptr [edi + 8], ebx
// 0062a0d3  3bf0                 cmp esi, eax
// 0062a0d5  7510                 jne 0x62a0e7
// 0062a0d7  896804               mov dword ptr [eax + 4], ebp
// 0062a0da  8b4704               mov eax, dword ptr [edi + 4]
// 0062a0dd  8928                 mov dword ptr [eax], ebp
// 0062a0df  8b4f04               mov ecx, dword ptr [edi + 4]
// 0062a0e2  896908               mov dword ptr [ecx + 8], ebp
// 0062a0e5  eb22                 jmp 0x62a109
// 0062a0e7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0062a0ec  740d                 je 0x62a0fb
// 0062a0ee  892e                 mov dword ptr [esi], ebp
// 0062a0f0  8b4704               mov eax, dword ptr [edi + 4]
// 0062a0f3  3b30                 cmp esi, dword ptr [eax]
// 0062a0f5  7512                 jne 0x62a109
// 0062a0f7  8928                 mov dword ptr [eax], ebp
// 0062a0f9  eb0e                 jmp 0x62a109
// 0062a0fb  896e08               mov dword ptr [esi + 8], ebp
// 0062a0fe  8b4704               mov eax, dword ptr [edi + 4]
// 0062a101  3b7008               cmp esi, dword ptr [eax + 8]
// 0062a104  7503                 jne 0x62a109
// 0062a106  896808               mov dword ptr [eax + 8], ebp
// 0062a109  8b5504               mov edx, dword ptr [ebp + 4]
// 0062a10c  807a2800             cmp byte ptr [edx + 0x28], 0
// 0062a110  8d4504               lea eax, [ebp + 4]
// 0062a113  8bf5                 mov esi, ebp
// 0062a115  0f85ea000000         jne 0x62a205
// 0062a11b  eb03                 jmp 0x62a120
// 0062a11d  8d4900               lea ecx, [ecx]
// 0062a120  8b08                 mov ecx, dword ptr [eax]
// 0062a122  8b5104               mov edx, dword ptr [ecx + 4]
// 0062a125  3b0a                 cmp ecx, dword ptr [edx]
// 0062a127  7551                 jne 0x62a17a
// 0062a129  8b5208               mov edx, dword ptr [edx + 8]
// 0062a12c  807a2800             cmp byte ptr [edx + 0x28], 0
// 0062a130  7519                 jne 0x62a14b
// 0062a132  885928               mov byte ptr [ecx + 0x28], bl
// 0062a135  885a28               mov byte ptr [edx + 0x28], bl
// 0062a138  8b10                 mov edx, dword ptr [eax]
// 0062a13a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0062a13d  c6412800             mov byte ptr [ecx + 0x28], 0
// 0062a141  8b10                 mov edx, dword ptr [eax]
// 0062a143  8b7204               mov esi, dword ptr [edx + 4]
// 0062a146  e9aa000000           jmp 0x62a1f5
// 0062a14b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0062a14e  750a                 jne 0x62a15a
// 0062a150  8bf1                 mov esi, ecx
// 0062a152  56                   push esi
// 0062a153  8bcf                 mov ecx, edi
// 0062a155  e83666eaff           call 0x4d0790
// 0062a15a  8b4604               mov eax, dword ptr [esi + 4]
// 0062a15d  885828               mov byte ptr [eax + 0x28], bl
// 0062a160  8b4e04               mov ecx, dword ptr [esi + 4]
// 0062a163  8b5104               mov edx, dword ptr [ecx + 4]
// 0062a166  c6422800             mov byte ptr [edx + 0x28], 0
// 0062a16a  8b4604               mov eax, dword ptr [esi + 4]
// 0062a16d  8b4804               mov ecx, dword ptr [eax + 4]
// 0062a170  51                   push ecx
// 0062a171  8bcf                 mov ecx, edi
// 0062a173  e81861eaff           call 0x4d0290
// 0062a178  eb7b                 jmp 0x62a1f5
// 0062a17a  8b12                 mov edx, dword ptr [edx]
// 0062a17c  807a2800             cmp byte ptr [edx + 0x28], 0
// 0062a180  7516                 jne 0x62a198
// 0062a182  885928               mov byte ptr [ecx + 0x28], bl
// 0062a185  885a28               mov byte ptr [edx + 0x28], bl
// 0062a188  8b10                 mov edx, dword ptr [eax]
// 0062a18a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0062a18d  c6412800             mov byte ptr [ecx + 0x28], 0
// 0062a191  8b10                 mov edx, dword ptr [eax]
// 0062a193  8b7204               mov esi, dword ptr [edx + 4]
// 0062a196  eb5d                 jmp 0x62a1f5
// 0062a198  3b31                 cmp esi, dword ptr [ecx]
// 0062a19a  750a                 jne 0x62a1a6
// 0062a19c  8bf1                 mov esi, ecx
// 0062a19e  56                   push esi
// 0062a19f  8bcf                 mov ecx, edi
// 0062a1a1  e8ea60eaff           call 0x4d0290
// 0062a1a6  8b4604               mov eax, dword ptr [esi + 4]
// 0062a1a9  885828               mov byte ptr [eax + 0x28], bl
// 0062a1ac  8b4e04               mov ecx, dword ptr [esi + 4]
// 0062a1af  8b5104               mov edx, dword ptr [ecx + 4]
// 0062a1b2  c6422800             mov byte ptr [edx + 0x28], 0
// 0062a1b6  8b4604               mov eax, dword ptr [esi + 4]
// 0062a1b9  8b4004               mov eax, dword ptr [eax + 4]
// 0062a1bc  8b4808               mov ecx, dword ptr [eax + 8]
// 0062a1bf  8b11                 mov edx, dword ptr [ecx]
// 0062a1c1  895008               mov dword ptr [eax + 8], edx
// 0062a1c4  8b11                 mov edx, dword ptr [ecx]
// 0062a1c6  807a2900             cmp byte ptr [edx + 0x29], 0
// 0062a1ca  7503                 jne 0x62a1cf
// 0062a1cc  894204               mov dword ptr [edx + 4], eax
// 0062a1cf  8b5004               mov edx, dword ptr [eax + 4]
// 0062a1d2  895104               mov dword ptr [ecx + 4], edx
// 0062a1d5  8b5704               mov edx, dword ptr [edi + 4]
// 0062a1d8  3b4204               cmp eax, dword ptr [edx + 4]
// 0062a1db  7505                 jne 0x62a1e2
// 0062a1dd  894a04               mov dword ptr [edx + 4], ecx
// 0062a1e0  eb0e                 jmp 0x62a1f0
// 0062a1e2  8b5004               mov edx, dword ptr [eax + 4]
// 0062a1e5  3b02                 cmp eax, dword ptr [edx]
// 0062a1e7  7504                 jne 0x62a1ed
// 0062a1e9  890a                 mov dword ptr [edx], ecx
// 0062a1eb  eb03                 jmp 0x62a1f0
// 0062a1ed  894a08               mov dword ptr [edx + 8], ecx
// 0062a1f0  8901                 mov dword ptr [ecx], eax
// 0062a1f2  894804               mov dword ptr [eax + 4], ecx
// 0062a1f5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0062a1f8  80792800             cmp byte ptr [ecx + 0x28], 0
// 0062a1fc  8d4604               lea eax, [esi + 4]
// 0062a1ff  0f841bffffff         je 0x62a120
// 0062a205  8b5704               mov edx, dword ptr [edi + 4]
// 0062a208  8b4204               mov eax, dword ptr [edx + 4]
// 0062a20b  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0062a20f  885828               mov byte ptr [eax + 0x28], bl
// 0062a212  8b442464             mov eax, dword ptr [esp + 0x64]
// 0062a216  5e                   pop esi
// 0062a217  896804               mov dword ptr [eax + 4], ebp
// 0062a21a  5d                   pop ebp
// 0062a21b  8938                 mov dword ptr [eax], edi
// 0062a21d  5b                   pop ebx
// 0062a21e  5f                   pop edi
// 0062a21f  64890d00000000       mov dword ptr fs:[0], ecx
// 0062a226  83c450               add esp, 0x50
// 0062a229  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
