// from server: 100% by auto
// roc 2007-08 00469590  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 493 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00469590
//
// 00469590  6aff                 push -1
// 00469592  68293a7400           push 0x743a29
// 00469597  64a100000000         mov eax, dword ptr fs:[0]
// 0046959d  50                   push eax
// 0046959e  83ec44               sub esp, 0x44
// 004695a1  53                   push ebx
// 004695a2  55                   push ebp
// 004695a3  56                   push esi
// 004695a4  57                   push edi
// 004695a5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004695aa  33c4                 xor eax, esp
// 004695ac  50                   push eax
// 004695ad  8d442458             lea eax, [esp + 0x58]
// 004695b1  64a300000000         mov dword ptr fs:[0], eax
// 004695b7  8bf9                 mov edi, ecx
// 004695b9  817f08feffff07       cmp dword ptr [edi + 8], 0x7fffffe
// 004695c0  723c                 jb 0x4695fe
// 004695c2  68904f7800           push 0x784f90
// 004695c7  8d4c2418             lea ecx, [esp + 0x18]
// 004695cb  ff1598e67700         call dword ptr [0x77e698]
// 004695d1  8d442414             lea eax, [esp + 0x14]
// 004695d5  50                   push eax
// 004695d6  8d4c2434             lea ecx, [esp + 0x34]
// 004695da  c744246400000000     mov dword ptr [esp + 0x64], 0
// 004695e2  e8d98ef9ff           call 0x4024c0
// 004695e7  6878f78300           push 0x83f778
// 004695ec  8d4c2434             lea ecx, [esp + 0x34]
// 004695f0  51                   push ecx
// 004695f1  c74424386c4e7800     mov dword ptr [esp + 0x38], 0x784e6c
// 004695f9  e8a0751c00           call 0x630b9e
// 004695fe  8b542474             mov edx, dword ptr [esp + 0x74]
// 00469602  8b4704               mov eax, dword ptr [edi + 4]
// 00469605  8b742470             mov esi, dword ptr [esp + 0x70]
// 00469609  6a00                 push 0
// 0046960b  52                   push edx
// 0046960c  50                   push eax
// 0046960d  56                   push esi
// 0046960e  50                   push eax
// 0046960f  e81cc0fdff           call 0x445630
// 00469614  8be8                 mov ebp, eax
// 00469616  8b4704               mov eax, dword ptr [edi + 4]
// 00469619  bb01000000           mov ebx, 1
// 0046961e  015f08               add dword ptr [edi + 8], ebx
// 00469621  3bf0                 cmp esi, eax
// 00469623  7510                 jne 0x469635
// 00469625  896804               mov dword ptr [eax + 4], ebp
// 00469628  8b4704               mov eax, dword ptr [edi + 4]
// 0046962b  8928                 mov dword ptr [eax], ebp
// 0046962d  8b4f04               mov ecx, dword ptr [edi + 4]
// 00469630  896908               mov dword ptr [ecx + 8], ebp
// 00469633  eb22                 jmp 0x469657
// 00469635  807c246c00           cmp byte ptr [esp + 0x6c], 0
// 0046963a  740d                 je 0x469649
// 0046963c  892e                 mov dword ptr [esi], ebp
// 0046963e  8b4704               mov eax, dword ptr [edi + 4]
// 00469641  3b30                 cmp esi, dword ptr [eax]
// 00469643  7512                 jne 0x469657
// 00469645  8928                 mov dword ptr [eax], ebp
// 00469647  eb0e                 jmp 0x469657
// 00469649  896e08               mov dword ptr [esi + 8], ebp
// 0046964c  8b4704               mov eax, dword ptr [edi + 4]
// 0046964f  3b7008               cmp esi, dword ptr [eax + 8]
// 00469652  7503                 jne 0x469657
// 00469654  896808               mov dword ptr [eax + 8], ebp
// 00469657  8b5504               mov edx, dword ptr [ebp + 4]
// 0046965a  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 0046965e  8d4504               lea eax, [ebp + 4]
// 00469661  8bf5                 mov esi, ebp
// 00469663  0f85ec000000         jne 0x469755
// 00469669  8da42400000000       lea esp, [esp]
// 00469670  8b08                 mov ecx, dword ptr [eax]
// 00469672  8b5104               mov edx, dword ptr [ecx + 4]
// 00469675  3b0a                 cmp ecx, dword ptr [edx]
// 00469677  7551                 jne 0x4696ca
// 00469679  8b5208               mov edx, dword ptr [edx + 8]
// 0046967c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00469680  7519                 jne 0x46969b
// 00469682  88592c               mov byte ptr [ecx + 0x2c], bl
// 00469685  885a2c               mov byte ptr [edx + 0x2c], bl
// 00469688  8b10                 mov edx, dword ptr [eax]
// 0046968a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0046968d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 00469691  8b10                 mov edx, dword ptr [eax]
// 00469693  8b7204               mov esi, dword ptr [edx + 4]
// 00469696  e9aa000000           jmp 0x469745
// 0046969b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0046969e  750a                 jne 0x4696aa
// 004696a0  8bf1                 mov esi, ecx
// 004696a2  56                   push esi
// 004696a3  8bcf                 mov ecx, edi
// 004696a5  e8e6780300           call 0x4a0f90
// 004696aa  8b4604               mov eax, dword ptr [esi + 4]
// 004696ad  88582c               mov byte ptr [eax + 0x2c], bl
// 004696b0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004696b3  8b5104               mov edx, dword ptr [ecx + 4]
// 004696b6  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004696ba  8b4604               mov eax, dword ptr [esi + 4]
// 004696bd  8b4804               mov ecx, dword ptr [eax + 4]
// 004696c0  51                   push ecx
// 004696c1  8bcf                 mov ecx, edi
// 004696c3  e818780300           call 0x4a0ee0
// 004696c8  eb7b                 jmp 0x469745
// 004696ca  8b12                 mov edx, dword ptr [edx]
// 004696cc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004696d0  7516                 jne 0x4696e8
// 004696d2  88592c               mov byte ptr [ecx + 0x2c], bl
// 004696d5  885a2c               mov byte ptr [edx + 0x2c], bl
// 004696d8  8b10                 mov edx, dword ptr [eax]
// 004696da  8b4a04               mov ecx, dword ptr [edx + 4]
// 004696dd  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004696e1  8b10                 mov edx, dword ptr [eax]
// 004696e3  8b7204               mov esi, dword ptr [edx + 4]
// 004696e6  eb5d                 jmp 0x469745
// 004696e8  3b31                 cmp esi, dword ptr [ecx]
// 004696ea  750a                 jne 0x4696f6
// 004696ec  8bf1                 mov esi, ecx
// 004696ee  56                   push esi
// 004696ef  8bcf                 mov ecx, edi
// 004696f1  e8ea770300           call 0x4a0ee0
// 004696f6  8b4604               mov eax, dword ptr [esi + 4]
// 004696f9  88582c               mov byte ptr [eax + 0x2c], bl
// 004696fc  8b4e04               mov ecx, dword ptr [esi + 4]
// 004696ff  8b5104               mov edx, dword ptr [ecx + 4]
// 00469702  c6422c00             mov byte ptr [edx + 0x2c], 0
// 00469706  8b4604               mov eax, dword ptr [esi + 4]
// 00469709  8b4004               mov eax, dword ptr [eax + 4]
// 0046970c  8b4808               mov ecx, dword ptr [eax + 8]
// 0046970f  8b11                 mov edx, dword ptr [ecx]
// 00469711  895008               mov dword ptr [eax + 8], edx
// 00469714  8b11                 mov edx, dword ptr [ecx]
// 00469716  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 0046971a  7503                 jne 0x46971f
// 0046971c  894204               mov dword ptr [edx + 4], eax
// 0046971f  8b5004               mov edx, dword ptr [eax + 4]
// 00469722  895104               mov dword ptr [ecx + 4], edx
// 00469725  8b5704               mov edx, dword ptr [edi + 4]
// 00469728  3b4204               cmp eax, dword ptr [edx + 4]
// 0046972b  7505                 jne 0x469732
// 0046972d  894a04               mov dword ptr [edx + 4], ecx
// 00469730  eb0e                 jmp 0x469740
// 00469732  8b5004               mov edx, dword ptr [eax + 4]
// 00469735  3b02                 cmp eax, dword ptr [edx]
// 00469737  7504                 jne 0x46973d
// 00469739  890a                 mov dword ptr [edx], ecx
// 0046973b  eb03                 jmp 0x469740
// 0046973d  894a08               mov dword ptr [edx + 8], ecx
// 00469740  8901                 mov dword ptr [ecx], eax
// 00469742  894804               mov dword ptr [eax + 4], ecx
// 00469745  8b4e04               mov ecx, dword ptr [esi + 4]
// 00469748  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 0046974c  8d4604               lea eax, [esi + 4]
// 0046974f  0f841bffffff         je 0x469670
// 00469755  8b5704               mov edx, dword ptr [edi + 4]
// 00469758  8b4204               mov eax, dword ptr [edx + 4]
// 0046975b  88582c               mov byte ptr [eax + 0x2c], bl
// 0046975e  8b442468             mov eax, dword ptr [esp + 0x68]
// 00469762  896804               mov dword ptr [eax + 4], ebp
// 00469765  8938                 mov dword ptr [eax], edi
// 00469767  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 0046976b  64890d00000000       mov dword ptr fs:[0], ecx
// 00469772  59                   pop ecx
// 00469773  5f                   pop edi
// 00469774  5e                   pop esi
// 00469775  5d                   pop ebp
// 00469776  5b                   pop ebx
// 00469777  83c450               add esp, 0x50
// 0046977a  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
