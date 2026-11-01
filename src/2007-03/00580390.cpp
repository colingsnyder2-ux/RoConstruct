// from server: 100% by auto
// roc 2007-03 00580390  unit: seg_00580000  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00580390
//
// 00580390  64a100000000         mov eax, dword ptr fs:[0]
// 00580396  6aff                 push -1
// 00580398  68926f7500           push 0x756f92
// 0058039d  50                   push eax
// 0058039e  64892500000000       mov dword ptr fs:[0], esp
// 005803a5  83ec44               sub esp, 0x44
// 005803a8  57                   push edi
// 005803a9  8bf9                 mov edi, ecx
// 005803ab  817f08cbcccc0c       cmp dword ptr [edi + 8], 0xccccccb
// 005803b2  7259                 jb 0x58040d
// 005803b4  68903f7800           push 0x783f90
// 005803b9  8d4c2408             lea ecx, [esp + 8]
// 005803bd  ff1578e77700         call dword ptr [0x77e778]
// 005803c3  8d4c2420             lea ecx, [esp + 0x20]
// 005803c7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005803cf  ff1560e97700         call dword ptr [0x77e960]
// 005803d5  8d442404             lea eax, [esp + 4]
// 005803d9  50                   push eax
// 005803da  8d4c2430             lea ecx, [esp + 0x30]
// 005803de  c644245401           mov byte ptr [esp + 0x54], 1
// 005803e3  c7442424383e7800     mov dword ptr [esp + 0x24], 0x783e38
// 005803eb  ff157ce77700         call dword ptr [0x77e77c]
// 005803f1  6870f78300           push 0x83f770
// 005803f6  8d4c2424             lea ecx, [esp + 0x24]
// 005803fa  51                   push ecx
// 005803fb  c644245800           mov byte ptr [esp + 0x58], 0
// 00580400  c7442428443e7800     mov dword ptr [esp + 0x28], 0x783e44
// 00580408  e821ec0900           call 0x61f02e
// 0058040d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00580411  8b4704               mov eax, dword ptr [edi + 4]
// 00580414  53                   push ebx
// 00580415  55                   push ebp
// 00580416  56                   push esi
// 00580417  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0058041b  6a00                 push 0
// 0058041d  52                   push edx
// 0058041e  50                   push eax
// 0058041f  56                   push esi
// 00580420  50                   push eax
// 00580421  e82afeffff           call 0x580250
// 00580426  8be8                 mov ebp, eax
// 00580428  8b4704               mov eax, dword ptr [edi + 4]
// 0058042b  bb01000000           mov ebx, 1
// 00580430  015f08               add dword ptr [edi + 8], ebx
// 00580433  3bf0                 cmp esi, eax
// 00580435  7510                 jne 0x580447
// 00580437  896804               mov dword ptr [eax + 4], ebp
// 0058043a  8b4704               mov eax, dword ptr [edi + 4]
// 0058043d  8928                 mov dword ptr [eax], ebp
// 0058043f  8b4f04               mov ecx, dword ptr [edi + 4]
// 00580442  896908               mov dword ptr [ecx + 8], ebp
// 00580445  eb22                 jmp 0x580469
// 00580447  807c246800           cmp byte ptr [esp + 0x68], 0
// 0058044c  740d                 je 0x58045b
// 0058044e  892e                 mov dword ptr [esi], ebp
// 00580450  8b4704               mov eax, dword ptr [edi + 4]
// 00580453  3b30                 cmp esi, dword ptr [eax]
// 00580455  7512                 jne 0x580469
// 00580457  8928                 mov dword ptr [eax], ebp
// 00580459  eb0e                 jmp 0x580469
// 0058045b  896e08               mov dword ptr [esi + 8], ebp
// 0058045e  8b4704               mov eax, dword ptr [edi + 4]
// 00580461  3b7008               cmp esi, dword ptr [eax + 8]
// 00580464  7503                 jne 0x580469
// 00580466  896808               mov dword ptr [eax + 8], ebp
// 00580469  8b5504               mov edx, dword ptr [ebp + 4]
// 0058046c  807a2000             cmp byte ptr [edx + 0x20], 0
// 00580470  8d4504               lea eax, [ebp + 4]
// 00580473  8bf5                 mov esi, ebp
// 00580475  0f85ea000000         jne 0x580565
// 0058047b  eb03                 jmp 0x580480
// 0058047d  8d4900               lea ecx, [ecx]
// 00580480  8b08                 mov ecx, dword ptr [eax]
// 00580482  8b5104               mov edx, dword ptr [ecx + 4]
// 00580485  3b0a                 cmp ecx, dword ptr [edx]
// 00580487  7551                 jne 0x5804da
// 00580489  8b5208               mov edx, dword ptr [edx + 8]
// 0058048c  807a2000             cmp byte ptr [edx + 0x20], 0
// 00580490  7519                 jne 0x5804ab
// 00580492  885920               mov byte ptr [ecx + 0x20], bl
// 00580495  885a20               mov byte ptr [edx + 0x20], bl
// 00580498  8b10                 mov edx, dword ptr [eax]
// 0058049a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0058049d  c6412000             mov byte ptr [ecx + 0x20], 0
// 005804a1  8b10                 mov edx, dword ptr [eax]
// 005804a3  8b7204               mov esi, dword ptr [edx + 4]
// 005804a6  e9aa000000           jmp 0x580555
// 005804ab  3b7108               cmp esi, dword ptr [ecx + 8]
// 005804ae  750a                 jne 0x5804ba
// 005804b0  8bf1                 mov esi, ecx
// 005804b2  56                   push esi
// 005804b3  8bcf                 mov ecx, edi
// 005804b5  e8261ff4ff           call 0x4c23e0
// 005804ba  8b4604               mov eax, dword ptr [esi + 4]
// 005804bd  885820               mov byte ptr [eax + 0x20], bl
// 005804c0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005804c3  8b5104               mov edx, dword ptr [ecx + 4]
// 005804c6  c6422000             mov byte ptr [edx + 0x20], 0
// 005804ca  8b4604               mov eax, dword ptr [esi + 4]
// 005804cd  8b4804               mov ecx, dword ptr [eax + 4]
// 005804d0  51                   push ecx
// 005804d1  8bcf                 mov ecx, edi
// 005804d3  e8a891ebff           call 0x439680
// 005804d8  eb7b                 jmp 0x580555
// 005804da  8b12                 mov edx, dword ptr [edx]
// 005804dc  807a2000             cmp byte ptr [edx + 0x20], 0
// 005804e0  7516                 jne 0x5804f8
// 005804e2  885920               mov byte ptr [ecx + 0x20], bl
// 005804e5  885a20               mov byte ptr [edx + 0x20], bl
// 005804e8  8b10                 mov edx, dword ptr [eax]
// 005804ea  8b4a04               mov ecx, dword ptr [edx + 4]
// 005804ed  c6412000             mov byte ptr [ecx + 0x20], 0
// 005804f1  8b10                 mov edx, dword ptr [eax]
// 005804f3  8b7204               mov esi, dword ptr [edx + 4]
// 005804f6  eb5d                 jmp 0x580555
// 005804f8  3b31                 cmp esi, dword ptr [ecx]
// 005804fa  750a                 jne 0x580506
// 005804fc  8bf1                 mov esi, ecx
// 005804fe  56                   push esi
// 005804ff  8bcf                 mov ecx, edi
// 00580501  e87a91ebff           call 0x439680
// 00580506  8b4604               mov eax, dword ptr [esi + 4]
// 00580509  885820               mov byte ptr [eax + 0x20], bl
// 0058050c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0058050f  8b5104               mov edx, dword ptr [ecx + 4]
// 00580512  c6422000             mov byte ptr [edx + 0x20], 0
// 00580516  8b4604               mov eax, dword ptr [esi + 4]
// 00580519  8b4004               mov eax, dword ptr [eax + 4]
// 0058051c  8b4808               mov ecx, dword ptr [eax + 8]
// 0058051f  8b11                 mov edx, dword ptr [ecx]
// 00580521  895008               mov dword ptr [eax + 8], edx
// 00580524  8b11                 mov edx, dword ptr [ecx]
// 00580526  807a2100             cmp byte ptr [edx + 0x21], 0
// 0058052a  7503                 jne 0x58052f
// 0058052c  894204               mov dword ptr [edx + 4], eax
// 0058052f  8b5004               mov edx, dword ptr [eax + 4]
// 00580532  895104               mov dword ptr [ecx + 4], edx
// 00580535  8b5704               mov edx, dword ptr [edi + 4]
// 00580538  3b4204               cmp eax, dword ptr [edx + 4]
// 0058053b  7505                 jne 0x580542
// 0058053d  894a04               mov dword ptr [edx + 4], ecx
// 00580540  eb0e                 jmp 0x580550
// 00580542  8b5004               mov edx, dword ptr [eax + 4]
// 00580545  3b02                 cmp eax, dword ptr [edx]
// 00580547  7504                 jne 0x58054d
// 00580549  890a                 mov dword ptr [edx], ecx
// 0058054b  eb03                 jmp 0x580550
// 0058054d  894a08               mov dword ptr [edx + 8], ecx
// 00580550  8901                 mov dword ptr [ecx], eax
// 00580552  894804               mov dword ptr [eax + 4], ecx
// 00580555  8b4e04               mov ecx, dword ptr [esi + 4]
// 00580558  80792000             cmp byte ptr [ecx + 0x20], 0
// 0058055c  8d4604               lea eax, [esi + 4]
// 0058055f  0f841bffffff         je 0x580480
// 00580565  8b5704               mov edx, dword ptr [edi + 4]
// 00580568  8b4204               mov eax, dword ptr [edx + 4]
// 0058056b  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0058056f  885820               mov byte ptr [eax + 0x20], bl
// 00580572  8b442464             mov eax, dword ptr [esp + 0x64]
// 00580576  5e                   pop esi
// 00580577  896804               mov dword ptr [eax + 4], ebp
// 0058057a  5d                   pop ebp
// 0058057b  8938                 mov dword ptr [eax], edi
// 0058057d  5b                   pop ebx
// 0058057e  5f                   pop edi
// 0058057f  64890d00000000       mov dword ptr fs:[0], ecx
// 00580586  83c450               add esp, 0x50
// 00580589  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
