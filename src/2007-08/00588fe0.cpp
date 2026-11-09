// from server: 100% by auto
// roc 2007-08 00588fe0  unit: VStockSound::?$FactoryProduct  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00588fe0
//
// 00588fe0  64a100000000         mov eax, dword ptr fs:[0]
// 00588fe6  6aff                 push -1
// 00588fe8  68b2417500           push 0x7541b2
// 00588fed  50                   push eax
// 00588fee  64892500000000       mov dword ptr fs:[0], esp
// 00588ff5  83ec44               sub esp, 0x44
// 00588ff8  57                   push edi
// 00588ff9  8bf9                 mov edi, ecx
// 00588ffb  817f0854555515       cmp dword ptr [edi + 8], 0x15555554
// 00589002  7259                 jb 0x58905d
// 00589004  68904f7800           push 0x784f90
// 00589009  8d4c2408             lea ecx, [esp + 8]
// 0058900d  ff1598e67700         call dword ptr [0x77e698]
// 00589013  8d4c2420             lea ecx, [esp + 0x20]
// 00589017  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0058901f  ff15f8e67700         call dword ptr [0x77e6f8]
// 00589025  8d442404             lea eax, [esp + 4]
// 00589029  50                   push eax
// 0058902a  8d4c2430             lea ecx, [esp + 0x30]
// 0058902e  c644245401           mov byte ptr [esp + 0x54], 1
// 00589033  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 0058903b  ff159ce67700         call dword ptr [0x77e69c]
// 00589041  6878f78300           push 0x83f778
// 00589046  8d4c2424             lea ecx, [esp + 0x24]
// 0058904a  51                   push ecx
// 0058904b  c644245800           mov byte ptr [esp + 0x58], 0
// 00589050  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 00589058  e8417b0a00           call 0x630b9e
// 0058905d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00589061  8b4704               mov eax, dword ptr [edi + 4]
// 00589064  53                   push ebx
// 00589065  55                   push ebp
// 00589066  56                   push esi
// 00589067  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0058906b  6a00                 push 0
// 0058906d  52                   push edx
// 0058906e  50                   push eax
// 0058906f  56                   push esi
// 00589070  50                   push eax
// 00589071  e8bafaf1ff           call 0x4a8b30
// 00589076  8be8                 mov ebp, eax
// 00589078  8b4704               mov eax, dword ptr [edi + 4]
// 0058907b  bb01000000           mov ebx, 1
// 00589080  015f08               add dword ptr [edi + 8], ebx
// 00589083  3bf0                 cmp esi, eax
// 00589085  7510                 jne 0x589097
// 00589087  896804               mov dword ptr [eax + 4], ebp
// 0058908a  8b4704               mov eax, dword ptr [edi + 4]
// 0058908d  8928                 mov dword ptr [eax], ebp
// 0058908f  8b4f04               mov ecx, dword ptr [edi + 4]
// 00589092  896908               mov dword ptr [ecx + 8], ebp
// 00589095  eb22                 jmp 0x5890b9
// 00589097  807c246800           cmp byte ptr [esp + 0x68], 0
// 0058909c  740d                 je 0x5890ab
// 0058909e  892e                 mov dword ptr [esi], ebp
// 005890a0  8b4704               mov eax, dword ptr [edi + 4]
// 005890a3  3b30                 cmp esi, dword ptr [eax]
// 005890a5  7512                 jne 0x5890b9
// 005890a7  8928                 mov dword ptr [eax], ebp
// 005890a9  eb0e                 jmp 0x5890b9
// 005890ab  896e08               mov dword ptr [esi + 8], ebp
// 005890ae  8b4704               mov eax, dword ptr [edi + 4]
// 005890b1  3b7008               cmp esi, dword ptr [eax + 8]
// 005890b4  7503                 jne 0x5890b9
// 005890b6  896808               mov dword ptr [eax + 8], ebp
// 005890b9  8b5504               mov edx, dword ptr [ebp + 4]
// 005890bc  807a1800             cmp byte ptr [edx + 0x18], 0
// 005890c0  8d4504               lea eax, [ebp + 4]
// 005890c3  8bf5                 mov esi, ebp
// 005890c5  0f85ea000000         jne 0x5891b5
// 005890cb  eb03                 jmp 0x5890d0
// 005890cd  8d4900               lea ecx, [ecx]
// 005890d0  8b08                 mov ecx, dword ptr [eax]
// 005890d2  8b5104               mov edx, dword ptr [ecx + 4]
// 005890d5  3b0a                 cmp ecx, dword ptr [edx]
// 005890d7  7551                 jne 0x58912a
// 005890d9  8b5208               mov edx, dword ptr [edx + 8]
// 005890dc  807a1800             cmp byte ptr [edx + 0x18], 0
// 005890e0  7519                 jne 0x5890fb
// 005890e2  885918               mov byte ptr [ecx + 0x18], bl
// 005890e5  885a18               mov byte ptr [edx + 0x18], bl
// 005890e8  8b10                 mov edx, dword ptr [eax]
// 005890ea  8b4a04               mov ecx, dword ptr [edx + 4]
// 005890ed  c6411800             mov byte ptr [ecx + 0x18], 0
// 005890f1  8b10                 mov edx, dword ptr [eax]
// 005890f3  8b7204               mov esi, dword ptr [edx + 4]
// 005890f6  e9aa000000           jmp 0x5891a5
// 005890fb  3b7108               cmp esi, dword ptr [ecx + 8]
// 005890fe  750a                 jne 0x58910a
// 00589100  8bf1                 mov esi, ecx
// 00589102  56                   push esi
// 00589103  8bcf                 mov ecx, edi
// 00589105  e8b6530500           call 0x5de4c0
// 0058910a  8b4604               mov eax, dword ptr [esi + 4]
// 0058910d  885818               mov byte ptr [eax + 0x18], bl
// 00589110  8b4e04               mov ecx, dword ptr [esi + 4]
// 00589113  8b5104               mov edx, dword ptr [ecx + 4]
// 00589116  c6421800             mov byte ptr [edx + 0x18], 0
// 0058911a  8b4604               mov eax, dword ptr [esi + 4]
// 0058911d  8b4804               mov ecx, dword ptr [eax + 4]
// 00589120  51                   push ecx
// 00589121  8bcf                 mov ecx, edi
// 00589123  e86863e8ff           call 0x40f490
// 00589128  eb7b                 jmp 0x5891a5
// 0058912a  8b12                 mov edx, dword ptr [edx]
// 0058912c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00589130  7516                 jne 0x589148
// 00589132  885918               mov byte ptr [ecx + 0x18], bl
// 00589135  885a18               mov byte ptr [edx + 0x18], bl
// 00589138  8b10                 mov edx, dword ptr [eax]
// 0058913a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0058913d  c6411800             mov byte ptr [ecx + 0x18], 0
// 00589141  8b10                 mov edx, dword ptr [eax]
// 00589143  8b7204               mov esi, dword ptr [edx + 4]
// 00589146  eb5d                 jmp 0x5891a5
// 00589148  3b31                 cmp esi, dword ptr [ecx]
// 0058914a  750a                 jne 0x589156
// 0058914c  8bf1                 mov esi, ecx
// 0058914e  56                   push esi
// 0058914f  8bcf                 mov ecx, edi
// 00589151  e83a63e8ff           call 0x40f490
// 00589156  8b4604               mov eax, dword ptr [esi + 4]
// 00589159  885818               mov byte ptr [eax + 0x18], bl
// 0058915c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0058915f  8b5104               mov edx, dword ptr [ecx + 4]
// 00589162  c6421800             mov byte ptr [edx + 0x18], 0
// 00589166  8b4604               mov eax, dword ptr [esi + 4]
// 00589169  8b4004               mov eax, dword ptr [eax + 4]
// 0058916c  8b4808               mov ecx, dword ptr [eax + 8]
// 0058916f  8b11                 mov edx, dword ptr [ecx]
// 00589171  895008               mov dword ptr [eax + 8], edx
// 00589174  8b11                 mov edx, dword ptr [ecx]
// 00589176  807a1900             cmp byte ptr [edx + 0x19], 0
// 0058917a  7503                 jne 0x58917f
// 0058917c  894204               mov dword ptr [edx + 4], eax
// 0058917f  8b5004               mov edx, dword ptr [eax + 4]
// 00589182  895104               mov dword ptr [ecx + 4], edx
// 00589185  8b5704               mov edx, dword ptr [edi + 4]
// 00589188  3b4204               cmp eax, dword ptr [edx + 4]
// 0058918b  7505                 jne 0x589192
// 0058918d  894a04               mov dword ptr [edx + 4], ecx
// 00589190  eb0e                 jmp 0x5891a0
// 00589192  8b5004               mov edx, dword ptr [eax + 4]
// 00589195  3b02                 cmp eax, dword ptr [edx]
// 00589197  7504                 jne 0x58919d
// 00589199  890a                 mov dword ptr [edx], ecx
// 0058919b  eb03                 jmp 0x5891a0
// 0058919d  894a08               mov dword ptr [edx + 8], ecx
// 005891a0  8901                 mov dword ptr [ecx], eax
// 005891a2  894804               mov dword ptr [eax + 4], ecx
// 005891a5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005891a8  80791800             cmp byte ptr [ecx + 0x18], 0
// 005891ac  8d4604               lea eax, [esi + 4]
// 005891af  0f841bffffff         je 0x5890d0
// 005891b5  8b5704               mov edx, dword ptr [edi + 4]
// 005891b8  8b4204               mov eax, dword ptr [edx + 4]
// 005891bb  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 005891bf  885818               mov byte ptr [eax + 0x18], bl
// 005891c2  8b442464             mov eax, dword ptr [esp + 0x64]
// 005891c6  5e                   pop esi
// 005891c7  896804               mov dword ptr [eax + 4], ebp
// 005891ca  5d                   pop ebp
// 005891cb  8938                 mov dword ptr [eax], edi
// 005891cd  5b                   pop ebx
// 005891ce  5f                   pop edi
// 005891cf  64890d00000000       mov dword ptr fs:[0], ecx
// 005891d6  83c450               add esp, 0x50
// 005891d9  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
