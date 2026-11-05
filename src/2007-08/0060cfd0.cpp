// from server: 100% by auto
// roc 2007-08 0060cfd0  unit: RBX::Block  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0060cfd0
//
// 0060cfd0  64a100000000         mov eax, dword ptr fs:[0]
// 0060cfd6  6aff                 push -1
// 0060cfd8  68b2417500           push 0x7541b2
// 0060cfdd  50                   push eax
// 0060cfde  64892500000000       mov dword ptr fs:[0], esp
// 0060cfe5  83ec44               sub esp, 0x44
// 0060cfe8  57                   push edi
// 0060cfe9  8bf9                 mov edi, ecx
// 0060cfeb  817f08feffff0f       cmp dword ptr [edi + 8], 0xffffffe
// 0060cff2  7259                 jb 0x60d04d
// 0060cff4  68904f7800           push 0x784f90
// 0060cff9  8d4c2408             lea ecx, [esp + 8]
// 0060cffd  ff1598e67700         call dword ptr [0x77e698]
// 0060d003  8d4c2420             lea ecx, [esp + 0x20]
// 0060d007  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0060d00f  ff15f8e67700         call dword ptr [0x77e6f8]
// 0060d015  8d442404             lea eax, [esp + 4]
// 0060d019  50                   push eax
// 0060d01a  8d4c2430             lea ecx, [esp + 0x30]
// 0060d01e  c644245401           mov byte ptr [esp + 0x54], 1
// 0060d023  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 0060d02b  ff159ce67700         call dword ptr [0x77e69c]
// 0060d031  6878f78300           push 0x83f778
// 0060d036  8d4c2424             lea ecx, [esp + 0x24]
// 0060d03a  51                   push ecx
// 0060d03b  c644245800           mov byte ptr [esp + 0x58], 0
// 0060d040  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 0060d048  e8513b0200           call 0x630b9e
// 0060d04d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0060d051  8b4704               mov eax, dword ptr [edi + 4]
// 0060d054  53                   push ebx
// 0060d055  55                   push ebp
// 0060d056  56                   push esi
// 0060d057  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0060d05b  6a00                 push 0
// 0060d05d  52                   push edx
// 0060d05e  50                   push eax
// 0060d05f  56                   push esi
// 0060d060  50                   push eax
// 0060d061  e8dafeffff           call 0x60cf40
// 0060d066  8be8                 mov ebp, eax
// 0060d068  8b4704               mov eax, dword ptr [edi + 4]
// 0060d06b  bb01000000           mov ebx, 1
// 0060d070  015f08               add dword ptr [edi + 8], ebx
// 0060d073  3bf0                 cmp esi, eax
// 0060d075  7510                 jne 0x60d087
// 0060d077  896804               mov dword ptr [eax + 4], ebp
// 0060d07a  8b4704               mov eax, dword ptr [edi + 4]
// 0060d07d  8928                 mov dword ptr [eax], ebp
// 0060d07f  8b4f04               mov ecx, dword ptr [edi + 4]
// 0060d082  896908               mov dword ptr [ecx + 8], ebp
// 0060d085  eb22                 jmp 0x60d0a9
// 0060d087  807c246800           cmp byte ptr [esp + 0x68], 0
// 0060d08c  740d                 je 0x60d09b
// 0060d08e  892e                 mov dword ptr [esi], ebp
// 0060d090  8b4704               mov eax, dword ptr [edi + 4]
// 0060d093  3b30                 cmp esi, dword ptr [eax]
// 0060d095  7512                 jne 0x60d0a9
// 0060d097  8928                 mov dword ptr [eax], ebp
// 0060d099  eb0e                 jmp 0x60d0a9
// 0060d09b  896e08               mov dword ptr [esi + 8], ebp
// 0060d09e  8b4704               mov eax, dword ptr [edi + 4]
// 0060d0a1  3b7008               cmp esi, dword ptr [eax + 8]
// 0060d0a4  7503                 jne 0x60d0a9
// 0060d0a6  896808               mov dword ptr [eax + 8], ebp
// 0060d0a9  8b5504               mov edx, dword ptr [ebp + 4]
// 0060d0ac  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 0060d0b0  8d4504               lea eax, [ebp + 4]
// 0060d0b3  8bf5                 mov esi, ebp
// 0060d0b5  0f85ea000000         jne 0x60d1a5
// 0060d0bb  eb03                 jmp 0x60d0c0
// 0060d0bd  8d4900               lea ecx, [ecx]
// 0060d0c0  8b08                 mov ecx, dword ptr [eax]
// 0060d0c2  8b5104               mov edx, dword ptr [ecx + 4]
// 0060d0c5  3b0a                 cmp ecx, dword ptr [edx]
// 0060d0c7  7551                 jne 0x60d11a
// 0060d0c9  8b5208               mov edx, dword ptr [edx + 8]
// 0060d0cc  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 0060d0d0  7519                 jne 0x60d0eb
// 0060d0d2  88591c               mov byte ptr [ecx + 0x1c], bl
// 0060d0d5  885a1c               mov byte ptr [edx + 0x1c], bl
// 0060d0d8  8b10                 mov edx, dword ptr [eax]
// 0060d0da  8b4a04               mov ecx, dword ptr [edx + 4]
// 0060d0dd  c6411c00             mov byte ptr [ecx + 0x1c], 0
// 0060d0e1  8b10                 mov edx, dword ptr [eax]
// 0060d0e3  8b7204               mov esi, dword ptr [edx + 4]
// 0060d0e6  e9aa000000           jmp 0x60d195
// 0060d0eb  3b7108               cmp esi, dword ptr [ecx + 8]
// 0060d0ee  750a                 jne 0x60d0fa
// 0060d0f0  8bf1                 mov esi, ecx
// 0060d0f2  56                   push esi
// 0060d0f3  8bcf                 mov ecx, edi
// 0060d0f5  e89625eeff           call 0x4ef690
// 0060d0fa  8b4604               mov eax, dword ptr [esi + 4]
// 0060d0fd  88581c               mov byte ptr [eax + 0x1c], bl
// 0060d100  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060d103  8b5104               mov edx, dword ptr [ecx + 4]
// 0060d106  c6421c00             mov byte ptr [edx + 0x1c], 0
// 0060d10a  8b4604               mov eax, dword ptr [esi + 4]
// 0060d10d  8b4804               mov ecx, dword ptr [eax + 4]
// 0060d110  51                   push ecx
// 0060d111  8bcf                 mov ecx, edi
// 0060d113  e8b8080100           call 0x61d9d0
// 0060d118  eb7b                 jmp 0x60d195
// 0060d11a  8b12                 mov edx, dword ptr [edx]
// 0060d11c  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 0060d120  7516                 jne 0x60d138
// 0060d122  88591c               mov byte ptr [ecx + 0x1c], bl
// 0060d125  885a1c               mov byte ptr [edx + 0x1c], bl
// 0060d128  8b10                 mov edx, dword ptr [eax]
// 0060d12a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0060d12d  c6411c00             mov byte ptr [ecx + 0x1c], 0
// 0060d131  8b10                 mov edx, dword ptr [eax]
// 0060d133  8b7204               mov esi, dword ptr [edx + 4]
// 0060d136  eb5d                 jmp 0x60d195
// 0060d138  3b31                 cmp esi, dword ptr [ecx]
// 0060d13a  750a                 jne 0x60d146
// 0060d13c  8bf1                 mov esi, ecx
// 0060d13e  56                   push esi
// 0060d13f  8bcf                 mov ecx, edi
// 0060d141  e88a080100           call 0x61d9d0
// 0060d146  8b4604               mov eax, dword ptr [esi + 4]
// 0060d149  88581c               mov byte ptr [eax + 0x1c], bl
// 0060d14c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060d14f  8b5104               mov edx, dword ptr [ecx + 4]
// 0060d152  c6421c00             mov byte ptr [edx + 0x1c], 0
// 0060d156  8b4604               mov eax, dword ptr [esi + 4]
// 0060d159  8b4004               mov eax, dword ptr [eax + 4]
// 0060d15c  8b4808               mov ecx, dword ptr [eax + 8]
// 0060d15f  8b11                 mov edx, dword ptr [ecx]
// 0060d161  895008               mov dword ptr [eax + 8], edx
// 0060d164  8b11                 mov edx, dword ptr [ecx]
// 0060d166  807a1d00             cmp byte ptr [edx + 0x1d], 0
// 0060d16a  7503                 jne 0x60d16f
// 0060d16c  894204               mov dword ptr [edx + 4], eax
// 0060d16f  8b5004               mov edx, dword ptr [eax + 4]
// 0060d172  895104               mov dword ptr [ecx + 4], edx
// 0060d175  8b5704               mov edx, dword ptr [edi + 4]
// 0060d178  3b4204               cmp eax, dword ptr [edx + 4]
// 0060d17b  7505                 jne 0x60d182
// 0060d17d  894a04               mov dword ptr [edx + 4], ecx
// 0060d180  eb0e                 jmp 0x60d190
// 0060d182  8b5004               mov edx, dword ptr [eax + 4]
// 0060d185  3b02                 cmp eax, dword ptr [edx]
// 0060d187  7504                 jne 0x60d18d
// 0060d189  890a                 mov dword ptr [edx], ecx
// 0060d18b  eb03                 jmp 0x60d190
// 0060d18d  894a08               mov dword ptr [edx + 8], ecx
// 0060d190  8901                 mov dword ptr [ecx], eax
// 0060d192  894804               mov dword ptr [eax + 4], ecx
// 0060d195  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060d198  80791c00             cmp byte ptr [ecx + 0x1c], 0
// 0060d19c  8d4604               lea eax, [esi + 4]
// 0060d19f  0f841bffffff         je 0x60d0c0
// 0060d1a5  8b5704               mov edx, dword ptr [edi + 4]
// 0060d1a8  8b4204               mov eax, dword ptr [edx + 4]
// 0060d1ab  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0060d1af  88581c               mov byte ptr [eax + 0x1c], bl
// 0060d1b2  8b442464             mov eax, dword ptr [esp + 0x64]
// 0060d1b6  5e                   pop esi
// 0060d1b7  896804               mov dword ptr [eax + 4], ebp
// 0060d1ba  5d                   pop ebp
// 0060d1bb  8938                 mov dword ptr [eax], edi
// 0060d1bd  5b                   pop ebx
// 0060d1be  5f                   pop edi
// 0060d1bf  64890d00000000       mov dword ptr fs:[0], ecx
// 0060d1c6  83c450               add esp, 0x50
// 0060d1c9  c21000               ret 0x10
// standard library map_int<pod12> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod12>
struct E { int v[3]; };
#include <map>
template class std::map<int, E>;
