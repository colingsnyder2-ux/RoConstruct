// from server: 100% by auto
// roc 2009-06 004dfa30  unit: RBX::Network::IdSerializer  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004dfa30
//
// 004dfa30  64a100000000         mov eax, dword ptr fs:[0]
// 004dfa36  6aff                 push -1
// 004dfa38  68b2db8500           push 0x85dbb2
// 004dfa3d  50                   push eax
// 004dfa3e  64892500000000       mov dword ptr fs:[0], esp
// 004dfa45  83ec44               sub esp, 0x44
// 004dfa48  57                   push edi
// 004dfa49  8bf9                 mov edi, ecx
// 004dfa4b  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 004dfa52  7259                 jb 0x4dfaad
// 004dfa54  68c0c98a00           push 0x8ac9c0
// 004dfa59  8d4c2408             lea ecx, [esp + 8]
// 004dfa5d  ff15b4e48900         call dword ptr [0x89e4b4]
// 004dfa63  8d4c2420             lea ecx, [esp + 0x20]
// 004dfa67  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004dfa6f  ff15b8e98900         call dword ptr [0x89e9b8]
// 004dfa75  8d442404             lea eax, [esp + 4]
// 004dfa79  50                   push eax
// 004dfa7a  8d4c2430             lea ecx, [esp + 0x30]
// 004dfa7e  c644245401           mov byte ptr [esp + 0x54], 1
// 004dfa83  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 004dfa8b  ff15b8e48900         call dword ptr [0x89e4b8]
// 004dfa91  6834929700           push 0x979234
// 004dfa96  8d4c2424             lea ecx, [esp + 0x24]
// 004dfa9a  51                   push ecx
// 004dfa9b  c644245800           mov byte ptr [esp + 0x58], 0
// 004dfaa0  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 004dfaa8  e89d9f2300           call 0x719a4a
// 004dfaad  8b542464             mov edx, dword ptr [esp + 0x64]
// 004dfab1  8b4718               mov eax, dword ptr [edi + 0x18]
// 004dfab4  53                   push ebx
// 004dfab5  55                   push ebp
// 004dfab6  56                   push esi
// 004dfab7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004dfabb  6a00                 push 0
// 004dfabd  52                   push edx
// 004dfabe  50                   push eax
// 004dfabf  56                   push esi
// 004dfac0  50                   push eax
// 004dfac1  e80afeffff           call 0x4df8d0
// 004dfac6  8be8                 mov ebp, eax
// 004dfac8  8b4718               mov eax, dword ptr [edi + 0x18]
// 004dfacb  bb01000000           mov ebx, 1
// 004dfad0  015f1c               add dword ptr [edi + 0x1c], ebx
// 004dfad3  3bf0                 cmp esi, eax
// 004dfad5  7510                 jne 0x4dfae7
// 004dfad7  896804               mov dword ptr [eax + 4], ebp
// 004dfada  8b4718               mov eax, dword ptr [edi + 0x18]
// 004dfadd  8928                 mov dword ptr [eax], ebp
// 004dfadf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004dfae2  896908               mov dword ptr [ecx + 8], ebp
// 004dfae5  eb22                 jmp 0x4dfb09
// 004dfae7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004dfaec  740d                 je 0x4dfafb
// 004dfaee  892e                 mov dword ptr [esi], ebp
// 004dfaf0  8b4718               mov eax, dword ptr [edi + 0x18]
// 004dfaf3  3b30                 cmp esi, dword ptr [eax]
// 004dfaf5  7512                 jne 0x4dfb09
// 004dfaf7  8928                 mov dword ptr [eax], ebp
// 004dfaf9  eb0e                 jmp 0x4dfb09
// 004dfafb  896e08               mov dword ptr [esi + 8], ebp
// 004dfafe  8b4718               mov eax, dword ptr [edi + 0x18]
// 004dfb01  3b7008               cmp esi, dword ptr [eax + 8]
// 004dfb04  7503                 jne 0x4dfb09
// 004dfb06  896808               mov dword ptr [eax + 8], ebp
// 004dfb09  8b5504               mov edx, dword ptr [ebp + 4]
// 004dfb0c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004dfb10  8d4504               lea eax, [ebp + 4]
// 004dfb13  8bf5                 mov esi, ebp
// 004dfb15  0f85ea000000         jne 0x4dfc05
// 004dfb1b  eb03                 jmp 0x4dfb20
// 004dfb1d  8d4900               lea ecx, [ecx]
// 004dfb20  8b08                 mov ecx, dword ptr [eax]
// 004dfb22  8b5104               mov edx, dword ptr [ecx + 4]
// 004dfb25  3b0a                 cmp ecx, dword ptr [edx]
// 004dfb27  7551                 jne 0x4dfb7a
// 004dfb29  8b5208               mov edx, dword ptr [edx + 8]
// 004dfb2c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004dfb30  7519                 jne 0x4dfb4b
// 004dfb32  88592c               mov byte ptr [ecx + 0x2c], bl
// 004dfb35  885a2c               mov byte ptr [edx + 0x2c], bl
// 004dfb38  8b10                 mov edx, dword ptr [eax]
// 004dfb3a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004dfb3d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004dfb41  8b10                 mov edx, dword ptr [eax]
// 004dfb43  8b7204               mov esi, dword ptr [edx + 4]
// 004dfb46  e9aa000000           jmp 0x4dfbf5
// 004dfb4b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004dfb4e  750a                 jne 0x4dfb5a
// 004dfb50  8bf1                 mov esi, ecx
// 004dfb52  56                   push esi
// 004dfb53  8bcf                 mov ecx, edi
// 004dfb55  e826ef1500           call 0x63ea80
// 004dfb5a  8b4604               mov eax, dword ptr [esi + 4]
// 004dfb5d  88582c               mov byte ptr [eax + 0x2c], bl
// 004dfb60  8b4e04               mov ecx, dword ptr [esi + 4]
// 004dfb63  8b5104               mov edx, dword ptr [ecx + 4]
// 004dfb66  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004dfb6a  8b4604               mov eax, dword ptr [esi + 4]
// 004dfb6d  8b4804               mov ecx, dword ptr [eax + 4]
// 004dfb70  51                   push ecx
// 004dfb71  8bcf                 mov ecx, edi
// 004dfb73  e888ceffff           call 0x4dca00
// 004dfb78  eb7b                 jmp 0x4dfbf5
// 004dfb7a  8b12                 mov edx, dword ptr [edx]
// 004dfb7c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004dfb80  7516                 jne 0x4dfb98
// 004dfb82  88592c               mov byte ptr [ecx + 0x2c], bl
// 004dfb85  885a2c               mov byte ptr [edx + 0x2c], bl
// 004dfb88  8b10                 mov edx, dword ptr [eax]
// 004dfb8a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004dfb8d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004dfb91  8b10                 mov edx, dword ptr [eax]
// 004dfb93  8b7204               mov esi, dword ptr [edx + 4]
// 004dfb96  eb5d                 jmp 0x4dfbf5
// 004dfb98  3b31                 cmp esi, dword ptr [ecx]
// 004dfb9a  750a                 jne 0x4dfba6
// 004dfb9c  8bf1                 mov esi, ecx
// 004dfb9e  56                   push esi
// 004dfb9f  8bcf                 mov ecx, edi
// 004dfba1  e85aceffff           call 0x4dca00
// 004dfba6  8b4604               mov eax, dword ptr [esi + 4]
// 004dfba9  88582c               mov byte ptr [eax + 0x2c], bl
// 004dfbac  8b4e04               mov ecx, dword ptr [esi + 4]
// 004dfbaf  8b5104               mov edx, dword ptr [ecx + 4]
// 004dfbb2  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004dfbb6  8b4604               mov eax, dword ptr [esi + 4]
// 004dfbb9  8b4004               mov eax, dword ptr [eax + 4]
// 004dfbbc  8b4808               mov ecx, dword ptr [eax + 8]
// 004dfbbf  8b11                 mov edx, dword ptr [ecx]
// 004dfbc1  895008               mov dword ptr [eax + 8], edx
// 004dfbc4  8b11                 mov edx, dword ptr [ecx]
// 004dfbc6  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 004dfbca  7503                 jne 0x4dfbcf
// 004dfbcc  894204               mov dword ptr [edx + 4], eax
// 004dfbcf  8b5004               mov edx, dword ptr [eax + 4]
// 004dfbd2  895104               mov dword ptr [ecx + 4], edx
// 004dfbd5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004dfbd8  3b4204               cmp eax, dword ptr [edx + 4]
// 004dfbdb  7505                 jne 0x4dfbe2
// 004dfbdd  894a04               mov dword ptr [edx + 4], ecx
// 004dfbe0  eb0e                 jmp 0x4dfbf0
// 004dfbe2  8b5004               mov edx, dword ptr [eax + 4]
// 004dfbe5  3b02                 cmp eax, dword ptr [edx]
// 004dfbe7  7504                 jne 0x4dfbed
// 004dfbe9  890a                 mov dword ptr [edx], ecx
// 004dfbeb  eb03                 jmp 0x4dfbf0
// 004dfbed  894a08               mov dword ptr [edx + 8], ecx
// 004dfbf0  8901                 mov dword ptr [ecx], eax
// 004dfbf2  894804               mov dword ptr [eax + 4], ecx
// 004dfbf5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004dfbf8  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 004dfbfc  8d4604               lea eax, [esi + 4]
// 004dfbff  0f841bffffff         je 0x4dfb20
// 004dfc05  8b5718               mov edx, dword ptr [edi + 0x18]
// 004dfc08  8b4204               mov eax, dword ptr [edx + 4]
// 004dfc0b  88582c               mov byte ptr [eax + 0x2c], bl
// 004dfc0e  8b442464             mov eax, dword ptr [esp + 0x64]
// 004dfc12  8b0f                 mov ecx, dword ptr [edi]
// 004dfc14  5e                   pop esi
// 004dfc15  896804               mov dword ptr [eax + 4], ebp
// 004dfc18  5d                   pop ebp
// 004dfc19  8908                 mov dword ptr [eax], ecx
// 004dfc1b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004dfc1f  5b                   pop ebx
// 004dfc20  5f                   pop edi
// 004dfc21  64890d00000000       mov dword ptr fs:[0], ecx
// 004dfc28  83c450               add esp, 0x50
// 004dfc2b  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
