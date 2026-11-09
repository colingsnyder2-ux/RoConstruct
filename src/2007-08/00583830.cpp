// from server: 100% by auto
// roc 2007-08 00583830  unit: RBX::VHat::?$FactoryProduct  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00583830
//
// 00583830  64a100000000         mov eax, dword ptr fs:[0]
// 00583836  6aff                 push -1
// 00583838  68b2417500           push 0x7541b2
// 0058383d  50                   push eax
// 0058383e  64892500000000       mov dword ptr fs:[0], esp
// 00583845  83ec44               sub esp, 0x44
// 00583848  57                   push edi
// 00583849  8bf9                 mov edi, ecx
// 0058384b  817f08feffff07       cmp dword ptr [edi + 8], 0x7fffffe
// 00583852  7259                 jb 0x5838ad
// 00583854  68904f7800           push 0x784f90
// 00583859  8d4c2408             lea ecx, [esp + 8]
// 0058385d  ff1598e67700         call dword ptr [0x77e698]
// 00583863  8d4c2420             lea ecx, [esp + 0x20]
// 00583867  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0058386f  ff15f8e67700         call dword ptr [0x77e6f8]
// 00583875  8d442404             lea eax, [esp + 4]
// 00583879  50                   push eax
// 0058387a  8d4c2430             lea ecx, [esp + 0x30]
// 0058387e  c644245401           mov byte ptr [esp + 0x54], 1
// 00583883  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 0058388b  ff159ce67700         call dword ptr [0x77e69c]
// 00583891  6878f78300           push 0x83f778
// 00583896  8d4c2424             lea ecx, [esp + 0x24]
// 0058389a  51                   push ecx
// 0058389b  c644245800           mov byte ptr [esp + 0x58], 0
// 005838a0  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 005838a8  e8f1d20a00           call 0x630b9e
// 005838ad  8b542464             mov edx, dword ptr [esp + 0x64]
// 005838b1  8b4704               mov eax, dword ptr [edi + 4]
// 005838b4  53                   push ebx
// 005838b5  55                   push ebp
// 005838b6  56                   push esi
// 005838b7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005838bb  6a00                 push 0
// 005838bd  52                   push edx
// 005838be  50                   push eax
// 005838bf  56                   push esi
// 005838c0  50                   push eax
// 005838c1  e84afcffff           call 0x583510
// 005838c6  8be8                 mov ebp, eax
// 005838c8  8b4704               mov eax, dword ptr [edi + 4]
// 005838cb  bb01000000           mov ebx, 1
// 005838d0  015f08               add dword ptr [edi + 8], ebx
// 005838d3  3bf0                 cmp esi, eax
// 005838d5  7510                 jne 0x5838e7
// 005838d7  896804               mov dword ptr [eax + 4], ebp
// 005838da  8b4704               mov eax, dword ptr [edi + 4]
// 005838dd  8928                 mov dword ptr [eax], ebp
// 005838df  8b4f04               mov ecx, dword ptr [edi + 4]
// 005838e2  896908               mov dword ptr [ecx + 8], ebp
// 005838e5  eb22                 jmp 0x583909
// 005838e7  807c246800           cmp byte ptr [esp + 0x68], 0
// 005838ec  740d                 je 0x5838fb
// 005838ee  892e                 mov dword ptr [esi], ebp
// 005838f0  8b4704               mov eax, dword ptr [edi + 4]
// 005838f3  3b30                 cmp esi, dword ptr [eax]
// 005838f5  7512                 jne 0x583909
// 005838f7  8928                 mov dword ptr [eax], ebp
// 005838f9  eb0e                 jmp 0x583909
// 005838fb  896e08               mov dword ptr [esi + 8], ebp
// 005838fe  8b4704               mov eax, dword ptr [edi + 4]
// 00583901  3b7008               cmp esi, dword ptr [eax + 8]
// 00583904  7503                 jne 0x583909
// 00583906  896808               mov dword ptr [eax + 8], ebp
// 00583909  8b5504               mov edx, dword ptr [ebp + 4]
// 0058390c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00583910  8d4504               lea eax, [ebp + 4]
// 00583913  8bf5                 mov esi, ebp
// 00583915  0f85ea000000         jne 0x583a05
// 0058391b  eb03                 jmp 0x583920
// 0058391d  8d4900               lea ecx, [ecx]
// 00583920  8b08                 mov ecx, dword ptr [eax]
// 00583922  8b5104               mov edx, dword ptr [ecx + 4]
// 00583925  3b0a                 cmp ecx, dword ptr [edx]
// 00583927  7551                 jne 0x58397a
// 00583929  8b5208               mov edx, dword ptr [edx + 8]
// 0058392c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00583930  7519                 jne 0x58394b
// 00583932  88592c               mov byte ptr [ecx + 0x2c], bl
// 00583935  885a2c               mov byte ptr [edx + 0x2c], bl
// 00583938  8b10                 mov edx, dword ptr [eax]
// 0058393a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0058393d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 00583941  8b10                 mov edx, dword ptr [eax]
// 00583943  8b7204               mov esi, dword ptr [edx + 4]
// 00583946  e9aa000000           jmp 0x5839f5
// 0058394b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0058394e  750a                 jne 0x58395a
// 00583950  8bf1                 mov esi, ecx
// 00583952  56                   push esi
// 00583953  8bcf                 mov ecx, edi
// 00583955  e836d6f1ff           call 0x4a0f90
// 0058395a  8b4604               mov eax, dword ptr [esi + 4]
// 0058395d  88582c               mov byte ptr [eax + 0x2c], bl
// 00583960  8b4e04               mov ecx, dword ptr [esi + 4]
// 00583963  8b5104               mov edx, dword ptr [ecx + 4]
// 00583966  c6422c00             mov byte ptr [edx + 0x2c], 0
// 0058396a  8b4604               mov eax, dword ptr [esi + 4]
// 0058396d  8b4804               mov ecx, dword ptr [eax + 4]
// 00583970  51                   push ecx
// 00583971  8bcf                 mov ecx, edi
// 00583973  e868d5f1ff           call 0x4a0ee0
// 00583978  eb7b                 jmp 0x5839f5
// 0058397a  8b12                 mov edx, dword ptr [edx]
// 0058397c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00583980  7516                 jne 0x583998
// 00583982  88592c               mov byte ptr [ecx + 0x2c], bl
// 00583985  885a2c               mov byte ptr [edx + 0x2c], bl
// 00583988  8b10                 mov edx, dword ptr [eax]
// 0058398a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0058398d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 00583991  8b10                 mov edx, dword ptr [eax]
// 00583993  8b7204               mov esi, dword ptr [edx + 4]
// 00583996  eb5d                 jmp 0x5839f5
// 00583998  3b31                 cmp esi, dword ptr [ecx]
// 0058399a  750a                 jne 0x5839a6
// 0058399c  8bf1                 mov esi, ecx
// 0058399e  56                   push esi
// 0058399f  8bcf                 mov ecx, edi
// 005839a1  e83ad5f1ff           call 0x4a0ee0
// 005839a6  8b4604               mov eax, dword ptr [esi + 4]
// 005839a9  88582c               mov byte ptr [eax + 0x2c], bl
// 005839ac  8b4e04               mov ecx, dword ptr [esi + 4]
// 005839af  8b5104               mov edx, dword ptr [ecx + 4]
// 005839b2  c6422c00             mov byte ptr [edx + 0x2c], 0
// 005839b6  8b4604               mov eax, dword ptr [esi + 4]
// 005839b9  8b4004               mov eax, dword ptr [eax + 4]
// 005839bc  8b4808               mov ecx, dword ptr [eax + 8]
// 005839bf  8b11                 mov edx, dword ptr [ecx]
// 005839c1  895008               mov dword ptr [eax + 8], edx
// 005839c4  8b11                 mov edx, dword ptr [ecx]
// 005839c6  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 005839ca  7503                 jne 0x5839cf
// 005839cc  894204               mov dword ptr [edx + 4], eax
// 005839cf  8b5004               mov edx, dword ptr [eax + 4]
// 005839d2  895104               mov dword ptr [ecx + 4], edx
// 005839d5  8b5704               mov edx, dword ptr [edi + 4]
// 005839d8  3b4204               cmp eax, dword ptr [edx + 4]
// 005839db  7505                 jne 0x5839e2
// 005839dd  894a04               mov dword ptr [edx + 4], ecx
// 005839e0  eb0e                 jmp 0x5839f0
// 005839e2  8b5004               mov edx, dword ptr [eax + 4]
// 005839e5  3b02                 cmp eax, dword ptr [edx]
// 005839e7  7504                 jne 0x5839ed
// 005839e9  890a                 mov dword ptr [edx], ecx
// 005839eb  eb03                 jmp 0x5839f0
// 005839ed  894a08               mov dword ptr [edx + 8], ecx
// 005839f0  8901                 mov dword ptr [ecx], eax
// 005839f2  894804               mov dword ptr [eax + 4], ecx
// 005839f5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005839f8  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 005839fc  8d4604               lea eax, [esi + 4]
// 005839ff  0f841bffffff         je 0x583920
// 00583a05  8b5704               mov edx, dword ptr [edi + 4]
// 00583a08  8b4204               mov eax, dword ptr [edx + 4]
// 00583a0b  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 00583a0f  88582c               mov byte ptr [eax + 0x2c], bl
// 00583a12  8b442464             mov eax, dword ptr [esp + 0x64]
// 00583a16  5e                   pop esi
// 00583a17  896804               mov dword ptr [eax + 4], ebp
// 00583a1a  5d                   pop ebp
// 00583a1b  8938                 mov dword ptr [eax], edi
// 00583a1d  5b                   pop ebx
// 00583a1e  5f                   pop edi
// 00583a1f  64890d00000000       mov dword ptr fs:[0], ecx
// 00583a26  83c450               add esp, 0x50
// 00583a29  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
