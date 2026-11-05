// from server: 100% by auto
// roc 2007-08 00566680  unit: TextXmlWriter  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00566680
//
// 00566680  64a100000000         mov eax, dword ptr fs:[0]
// 00566686  6aff                 push -1
// 00566688  68b2417500           push 0x7541b2
// 0056668d  50                   push eax
// 0056668e  64892500000000       mov dword ptr fs:[0], esp
// 00566695  83ec44               sub esp, 0x44
// 00566698  57                   push edi
// 00566699  8bf9                 mov edi, ecx
// 0056669b  817f08feffff07       cmp dword ptr [edi + 8], 0x7fffffe
// 005666a2  7259                 jb 0x5666fd
// 005666a4  68904f7800           push 0x784f90
// 005666a9  8d4c2408             lea ecx, [esp + 8]
// 005666ad  ff1598e67700         call dword ptr [0x77e698]
// 005666b3  8d4c2420             lea ecx, [esp + 0x20]
// 005666b7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005666bf  ff15f8e67700         call dword ptr [0x77e6f8]
// 005666c5  8d442404             lea eax, [esp + 4]
// 005666c9  50                   push eax
// 005666ca  8d4c2430             lea ecx, [esp + 0x30]
// 005666ce  c644245401           mov byte ptr [esp + 0x54], 1
// 005666d3  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 005666db  ff159ce67700         call dword ptr [0x77e69c]
// 005666e1  6878f78300           push 0x83f778
// 005666e6  8d4c2424             lea ecx, [esp + 0x24]
// 005666ea  51                   push ecx
// 005666eb  c644245800           mov byte ptr [esp + 0x58], 0
// 005666f0  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 005666f8  e8a1a40c00           call 0x630b9e
// 005666fd  8b542464             mov edx, dword ptr [esp + 0x64]
// 00566701  8b4704               mov eax, dword ptr [edi + 4]
// 00566704  53                   push ebx
// 00566705  55                   push ebp
// 00566706  56                   push esi
// 00566707  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0056670b  6a00                 push 0
// 0056670d  52                   push edx
// 0056670e  50                   push eax
// 0056670f  56                   push esi
// 00566710  50                   push eax
// 00566711  e87a430700           call 0x5daa90
// 00566716  8be8                 mov ebp, eax
// 00566718  8b4704               mov eax, dword ptr [edi + 4]
// 0056671b  bb01000000           mov ebx, 1
// 00566720  015f08               add dword ptr [edi + 8], ebx
// 00566723  3bf0                 cmp esi, eax
// 00566725  7510                 jne 0x566737
// 00566727  896804               mov dword ptr [eax + 4], ebp
// 0056672a  8b4704               mov eax, dword ptr [edi + 4]
// 0056672d  8928                 mov dword ptr [eax], ebp
// 0056672f  8b4f04               mov ecx, dword ptr [edi + 4]
// 00566732  896908               mov dword ptr [ecx + 8], ebp
// 00566735  eb22                 jmp 0x566759
// 00566737  807c246800           cmp byte ptr [esp + 0x68], 0
// 0056673c  740d                 je 0x56674b
// 0056673e  892e                 mov dword ptr [esi], ebp
// 00566740  8b4704               mov eax, dword ptr [edi + 4]
// 00566743  3b30                 cmp esi, dword ptr [eax]
// 00566745  7512                 jne 0x566759
// 00566747  8928                 mov dword ptr [eax], ebp
// 00566749  eb0e                 jmp 0x566759
// 0056674b  896e08               mov dword ptr [esi + 8], ebp
// 0056674e  8b4704               mov eax, dword ptr [edi + 4]
// 00566751  3b7008               cmp esi, dword ptr [eax + 8]
// 00566754  7503                 jne 0x566759
// 00566756  896808               mov dword ptr [eax + 8], ebp
// 00566759  8b5504               mov edx, dword ptr [ebp + 4]
// 0056675c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00566760  8d4504               lea eax, [ebp + 4]
// 00566763  8bf5                 mov esi, ebp
// 00566765  0f85ea000000         jne 0x566855
// 0056676b  eb03                 jmp 0x566770
// 0056676d  8d4900               lea ecx, [ecx]
// 00566770  8b08                 mov ecx, dword ptr [eax]
// 00566772  8b5104               mov edx, dword ptr [ecx + 4]
// 00566775  3b0a                 cmp ecx, dword ptr [edx]
// 00566777  7551                 jne 0x5667ca
// 00566779  8b5208               mov edx, dword ptr [edx + 8]
// 0056677c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00566780  7519                 jne 0x56679b
// 00566782  88592c               mov byte ptr [ecx + 0x2c], bl
// 00566785  885a2c               mov byte ptr [edx + 0x2c], bl
// 00566788  8b10                 mov edx, dword ptr [eax]
// 0056678a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0056678d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 00566791  8b10                 mov edx, dword ptr [eax]
// 00566793  8b7204               mov esi, dword ptr [edx + 4]
// 00566796  e9aa000000           jmp 0x566845
// 0056679b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0056679e  750a                 jne 0x5667aa
// 005667a0  8bf1                 mov esi, ecx
// 005667a2  56                   push esi
// 005667a3  8bcf                 mov ecx, edi
// 005667a5  e8e6a7f3ff           call 0x4a0f90
// 005667aa  8b4604               mov eax, dword ptr [esi + 4]
// 005667ad  88582c               mov byte ptr [eax + 0x2c], bl
// 005667b0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005667b3  8b5104               mov edx, dword ptr [ecx + 4]
// 005667b6  c6422c00             mov byte ptr [edx + 0x2c], 0
// 005667ba  8b4604               mov eax, dword ptr [esi + 4]
// 005667bd  8b4804               mov ecx, dword ptr [eax + 4]
// 005667c0  51                   push ecx
// 005667c1  8bcf                 mov ecx, edi
// 005667c3  e818a7f3ff           call 0x4a0ee0
// 005667c8  eb7b                 jmp 0x566845
// 005667ca  8b12                 mov edx, dword ptr [edx]
// 005667cc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 005667d0  7516                 jne 0x5667e8
// 005667d2  88592c               mov byte ptr [ecx + 0x2c], bl
// 005667d5  885a2c               mov byte ptr [edx + 0x2c], bl
// 005667d8  8b10                 mov edx, dword ptr [eax]
// 005667da  8b4a04               mov ecx, dword ptr [edx + 4]
// 005667dd  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 005667e1  8b10                 mov edx, dword ptr [eax]
// 005667e3  8b7204               mov esi, dword ptr [edx + 4]
// 005667e6  eb5d                 jmp 0x566845
// 005667e8  3b31                 cmp esi, dword ptr [ecx]
// 005667ea  750a                 jne 0x5667f6
// 005667ec  8bf1                 mov esi, ecx
// 005667ee  56                   push esi
// 005667ef  8bcf                 mov ecx, edi
// 005667f1  e8eaa6f3ff           call 0x4a0ee0
// 005667f6  8b4604               mov eax, dword ptr [esi + 4]
// 005667f9  88582c               mov byte ptr [eax + 0x2c], bl
// 005667fc  8b4e04               mov ecx, dword ptr [esi + 4]
// 005667ff  8b5104               mov edx, dword ptr [ecx + 4]
// 00566802  c6422c00             mov byte ptr [edx + 0x2c], 0
// 00566806  8b4604               mov eax, dword ptr [esi + 4]
// 00566809  8b4004               mov eax, dword ptr [eax + 4]
// 0056680c  8b4808               mov ecx, dword ptr [eax + 8]
// 0056680f  8b11                 mov edx, dword ptr [ecx]
// 00566811  895008               mov dword ptr [eax + 8], edx
// 00566814  8b11                 mov edx, dword ptr [ecx]
// 00566816  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 0056681a  7503                 jne 0x56681f
// 0056681c  894204               mov dword ptr [edx + 4], eax
// 0056681f  8b5004               mov edx, dword ptr [eax + 4]
// 00566822  895104               mov dword ptr [ecx + 4], edx
// 00566825  8b5704               mov edx, dword ptr [edi + 4]
// 00566828  3b4204               cmp eax, dword ptr [edx + 4]
// 0056682b  7505                 jne 0x566832
// 0056682d  894a04               mov dword ptr [edx + 4], ecx
// 00566830  eb0e                 jmp 0x566840
// 00566832  8b5004               mov edx, dword ptr [eax + 4]
// 00566835  3b02                 cmp eax, dword ptr [edx]
// 00566837  7504                 jne 0x56683d
// 00566839  890a                 mov dword ptr [edx], ecx
// 0056683b  eb03                 jmp 0x566840
// 0056683d  894a08               mov dword ptr [edx + 8], ecx
// 00566840  8901                 mov dword ptr [ecx], eax
// 00566842  894804               mov dword ptr [eax + 4], ecx
// 00566845  8b4e04               mov ecx, dword ptr [esi + 4]
// 00566848  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 0056684c  8d4604               lea eax, [esi + 4]
// 0056684f  0f841bffffff         je 0x566770
// 00566855  8b5704               mov edx, dword ptr [edi + 4]
// 00566858  8b4204               mov eax, dword ptr [edx + 4]
// 0056685b  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0056685f  88582c               mov byte ptr [eax + 0x2c], bl
// 00566862  8b442464             mov eax, dword ptr [esp + 0x64]
// 00566866  5e                   pop esi
// 00566867  896804               mov dword ptr [eax + 4], ebp
// 0056686a  5d                   pop ebp
// 0056686b  8938                 mov dword ptr [eax], edi
// 0056686d  5b                   pop ebx
// 0056686e  5f                   pop edi
// 0056686f  64890d00000000       mov dword ptr fs:[0], ecx
// 00566876  83c450               add esp, 0x50
// 00566879  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
