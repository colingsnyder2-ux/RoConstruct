// from server: 100% by auto
// roc 2007-08 004f01f0  unit: RBX::Render::AggregatingSceneManager  size: 493 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004f01f0
//
// 004f01f0  6aff                 push -1
// 004f01f2  68293a7400           push 0x743a29
// 004f01f7  64a100000000         mov eax, dword ptr fs:[0]
// 004f01fd  50                   push eax
// 004f01fe  83ec44               sub esp, 0x44
// 004f0201  53                   push ebx
// 004f0202  55                   push ebp
// 004f0203  56                   push esi
// 004f0204  57                   push edi
// 004f0205  a188518b00           mov eax, dword ptr [0x8b5188]
// 004f020a  33c4                 xor eax, esp
// 004f020c  50                   push eax
// 004f020d  8d442458             lea eax, [esp + 0x58]
// 004f0211  64a300000000         mov dword ptr fs:[0], eax
// 004f0217  8bf9                 mov edi, ecx
// 004f0219  817f08feffff1f       cmp dword ptr [edi + 8], 0x1ffffffe
// 004f0220  723c                 jb 0x4f025e
// 004f0222  68904f7800           push 0x784f90
// 004f0227  8d4c2418             lea ecx, [esp + 0x18]
// 004f022b  ff1598e67700         call dword ptr [0x77e698]
// 004f0231  8d442414             lea eax, [esp + 0x14]
// 004f0235  50                   push eax
// 004f0236  8d4c2434             lea ecx, [esp + 0x34]
// 004f023a  c744246400000000     mov dword ptr [esp + 0x64], 0
// 004f0242  e87922f1ff           call 0x4024c0
// 004f0247  6878f78300           push 0x83f778
// 004f024c  8d4c2434             lea ecx, [esp + 0x34]
// 004f0250  51                   push ecx
// 004f0251  c74424386c4e7800     mov dword ptr [esp + 0x38], 0x784e6c
// 004f0259  e840091400           call 0x630b9e
// 004f025e  8b542474             mov edx, dword ptr [esp + 0x74]
// 004f0262  8b4704               mov eax, dword ptr [edi + 4]
// 004f0265  8b742470             mov esi, dword ptr [esp + 0x70]
// 004f0269  6a00                 push 0
// 004f026b  52                   push edx
// 004f026c  50                   push eax
// 004f026d  56                   push esi
// 004f026e  50                   push eax
// 004f026f  e84cfdffff           call 0x4effc0
// 004f0274  8be8                 mov ebp, eax
// 004f0276  8b4704               mov eax, dword ptr [edi + 4]
// 004f0279  bb01000000           mov ebx, 1
// 004f027e  015f08               add dword ptr [edi + 8], ebx
// 004f0281  3bf0                 cmp esi, eax
// 004f0283  7510                 jne 0x4f0295
// 004f0285  896804               mov dword ptr [eax + 4], ebp
// 004f0288  8b4704               mov eax, dword ptr [edi + 4]
// 004f028b  8928                 mov dword ptr [eax], ebp
// 004f028d  8b4f04               mov ecx, dword ptr [edi + 4]
// 004f0290  896908               mov dword ptr [ecx + 8], ebp
// 004f0293  eb22                 jmp 0x4f02b7
// 004f0295  807c246c00           cmp byte ptr [esp + 0x6c], 0
// 004f029a  740d                 je 0x4f02a9
// 004f029c  892e                 mov dword ptr [esi], ebp
// 004f029e  8b4704               mov eax, dword ptr [edi + 4]
// 004f02a1  3b30                 cmp esi, dword ptr [eax]
// 004f02a3  7512                 jne 0x4f02b7
// 004f02a5  8928                 mov dword ptr [eax], ebp
// 004f02a7  eb0e                 jmp 0x4f02b7
// 004f02a9  896e08               mov dword ptr [esi + 8], ebp
// 004f02ac  8b4704               mov eax, dword ptr [edi + 4]
// 004f02af  3b7008               cmp esi, dword ptr [eax + 8]
// 004f02b2  7503                 jne 0x4f02b7
// 004f02b4  896808               mov dword ptr [eax + 8], ebp
// 004f02b7  8b5504               mov edx, dword ptr [ebp + 4]
// 004f02ba  807a1400             cmp byte ptr [edx + 0x14], 0
// 004f02be  8d4504               lea eax, [ebp + 4]
// 004f02c1  8bf5                 mov esi, ebp
// 004f02c3  0f85ec000000         jne 0x4f03b5
// 004f02c9  8da42400000000       lea esp, [esp]
// 004f02d0  8b08                 mov ecx, dword ptr [eax]
// 004f02d2  8b5104               mov edx, dword ptr [ecx + 4]
// 004f02d5  3b0a                 cmp ecx, dword ptr [edx]
// 004f02d7  7551                 jne 0x4f032a
// 004f02d9  8b5208               mov edx, dword ptr [edx + 8]
// 004f02dc  807a1400             cmp byte ptr [edx + 0x14], 0
// 004f02e0  7519                 jne 0x4f02fb
// 004f02e2  885914               mov byte ptr [ecx + 0x14], bl
// 004f02e5  885a14               mov byte ptr [edx + 0x14], bl
// 004f02e8  8b10                 mov edx, dword ptr [eax]
// 004f02ea  8b4a04               mov ecx, dword ptr [edx + 4]
// 004f02ed  c6411400             mov byte ptr [ecx + 0x14], 0
// 004f02f1  8b10                 mov edx, dword ptr [eax]
// 004f02f3  8b7204               mov esi, dword ptr [edx + 4]
// 004f02f6  e9aa000000           jmp 0x4f03a5
// 004f02fb  3b7108               cmp esi, dword ptr [ecx + 8]
// 004f02fe  750a                 jne 0x4f030a
// 004f0300  8bf1                 mov esi, ecx
// 004f0302  56                   push esi
// 004f0303  8bcf                 mov ecx, edi
// 004f0305  e8d6d10700           call 0x56d4e0
// 004f030a  8b4604               mov eax, dword ptr [esi + 4]
// 004f030d  885814               mov byte ptr [eax + 0x14], bl
// 004f0310  8b4e04               mov ecx, dword ptr [esi + 4]
// 004f0313  8b5104               mov edx, dword ptr [ecx + 4]
// 004f0316  c6421400             mov byte ptr [edx + 0x14], 0
// 004f031a  8b4604               mov eax, dword ptr [esi + 4]
// 004f031d  8b4804               mov ecx, dword ptr [eax + 4]
// 004f0320  51                   push ecx
// 004f0321  8bcf                 mov ecx, edi
// 004f0323  e8f8471100           call 0x604b20
// 004f0328  eb7b                 jmp 0x4f03a5
// 004f032a  8b12                 mov edx, dword ptr [edx]
// 004f032c  807a1400             cmp byte ptr [edx + 0x14], 0
// 004f0330  7516                 jne 0x4f0348
// 004f0332  885914               mov byte ptr [ecx + 0x14], bl
// 004f0335  885a14               mov byte ptr [edx + 0x14], bl
// 004f0338  8b10                 mov edx, dword ptr [eax]
// 004f033a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004f033d  c6411400             mov byte ptr [ecx + 0x14], 0
// 004f0341  8b10                 mov edx, dword ptr [eax]
// 004f0343  8b7204               mov esi, dword ptr [edx + 4]
// 004f0346  eb5d                 jmp 0x4f03a5
// 004f0348  3b31                 cmp esi, dword ptr [ecx]
// 004f034a  750a                 jne 0x4f0356
// 004f034c  8bf1                 mov esi, ecx
// 004f034e  56                   push esi
// 004f034f  8bcf                 mov ecx, edi
// 004f0351  e8ca471100           call 0x604b20
// 004f0356  8b4604               mov eax, dword ptr [esi + 4]
// 004f0359  885814               mov byte ptr [eax + 0x14], bl
// 004f035c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004f035f  8b5104               mov edx, dword ptr [ecx + 4]
// 004f0362  c6421400             mov byte ptr [edx + 0x14], 0
// 004f0366  8b4604               mov eax, dword ptr [esi + 4]
// 004f0369  8b4004               mov eax, dword ptr [eax + 4]
// 004f036c  8b4808               mov ecx, dword ptr [eax + 8]
// 004f036f  8b11                 mov edx, dword ptr [ecx]
// 004f0371  895008               mov dword ptr [eax + 8], edx
// 004f0374  8b11                 mov edx, dword ptr [ecx]
// 004f0376  807a1500             cmp byte ptr [edx + 0x15], 0
// 004f037a  7503                 jne 0x4f037f
// 004f037c  894204               mov dword ptr [edx + 4], eax
// 004f037f  8b5004               mov edx, dword ptr [eax + 4]
// 004f0382  895104               mov dword ptr [ecx + 4], edx
// 004f0385  8b5704               mov edx, dword ptr [edi + 4]
// 004f0388  3b4204               cmp eax, dword ptr [edx + 4]
// 004f038b  7505                 jne 0x4f0392
// 004f038d  894a04               mov dword ptr [edx + 4], ecx
// 004f0390  eb0e                 jmp 0x4f03a0
// 004f0392  8b5004               mov edx, dword ptr [eax + 4]
// 004f0395  3b02                 cmp eax, dword ptr [edx]
// 004f0397  7504                 jne 0x4f039d
// 004f0399  890a                 mov dword ptr [edx], ecx
// 004f039b  eb03                 jmp 0x4f03a0
// 004f039d  894a08               mov dword ptr [edx + 8], ecx
// 004f03a0  8901                 mov dword ptr [ecx], eax
// 004f03a2  894804               mov dword ptr [eax + 4], ecx
// 004f03a5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004f03a8  80791400             cmp byte ptr [ecx + 0x14], 0
// 004f03ac  8d4604               lea eax, [esi + 4]
// 004f03af  0f841bffffff         je 0x4f02d0
// 004f03b5  8b5704               mov edx, dword ptr [edi + 4]
// 004f03b8  8b4204               mov eax, dword ptr [edx + 4]
// 004f03bb  885814               mov byte ptr [eax + 0x14], bl
// 004f03be  8b442468             mov eax, dword ptr [esp + 0x68]
// 004f03c2  896804               mov dword ptr [eax + 4], ebp
// 004f03c5  8938                 mov dword ptr [eax], edi
// 004f03c7  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 004f03cb  64890d00000000       mov dword ptr fs:[0], ecx
// 004f03d2  59                   pop ecx
// 004f03d3  5f                   pop edi
// 004f03d4  5e                   pop esi
// 004f03d5  5d                   pop ebp
// 004f03d6  5b                   pop ebx
// 004f03d7  83c450               add esp, 0x50
// 004f03da  c21000               ret 0x10
// standard library map_int<ptr> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
