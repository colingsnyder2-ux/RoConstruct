// from server: 100% by auto
// roc 2007-08 005df0c0  unit: RBX::VMotorFeature::?$FactoryProduct  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005df0c0
//
// 005df0c0  64a100000000         mov eax, dword ptr fs:[0]
// 005df0c6  6aff                 push -1
// 005df0c8  68b2417500           push 0x7541b2
// 005df0cd  50                   push eax
// 005df0ce  64892500000000       mov dword ptr fs:[0], esp
// 005df0d5  83ec44               sub esp, 0x44
// 005df0d8  57                   push edi
// 005df0d9  8bf9                 mov edi, ecx
// 005df0db  817f0854555515       cmp dword ptr [edi + 8], 0x15555554
// 005df0e2  7259                 jb 0x5df13d
// 005df0e4  68904f7800           push 0x784f90
// 005df0e9  8d4c2408             lea ecx, [esp + 8]
// 005df0ed  ff1598e67700         call dword ptr [0x77e698]
// 005df0f3  8d4c2420             lea ecx, [esp + 0x20]
// 005df0f7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005df0ff  ff15f8e67700         call dword ptr [0x77e6f8]
// 005df105  8d442404             lea eax, [esp + 4]
// 005df109  50                   push eax
// 005df10a  8d4c2430             lea ecx, [esp + 0x30]
// 005df10e  c644245401           mov byte ptr [esp + 0x54], 1
// 005df113  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 005df11b  ff159ce67700         call dword ptr [0x77e69c]
// 005df121  6878f78300           push 0x83f778
// 005df126  8d4c2424             lea ecx, [esp + 0x24]
// 005df12a  51                   push ecx
// 005df12b  c644245800           mov byte ptr [esp + 0x58], 0
// 005df130  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 005df138  e8611a0500           call 0x630b9e
// 005df13d  8b542464             mov edx, dword ptr [esp + 0x64]
// 005df141  8b4704               mov eax, dword ptr [edi + 4]
// 005df144  53                   push ebx
// 005df145  55                   push ebp
// 005df146  56                   push esi
// 005df147  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005df14b  6a00                 push 0
// 005df14d  52                   push edx
// 005df14e  50                   push eax
// 005df14f  56                   push esi
// 005df150  50                   push eax
// 005df151  e80afcffff           call 0x5ded60
// 005df156  8be8                 mov ebp, eax
// 005df158  8b4704               mov eax, dword ptr [edi + 4]
// 005df15b  bb01000000           mov ebx, 1
// 005df160  015f08               add dword ptr [edi + 8], ebx
// 005df163  3bf0                 cmp esi, eax
// 005df165  7510                 jne 0x5df177
// 005df167  896804               mov dword ptr [eax + 4], ebp
// 005df16a  8b4704               mov eax, dword ptr [edi + 4]
// 005df16d  8928                 mov dword ptr [eax], ebp
// 005df16f  8b4f04               mov ecx, dword ptr [edi + 4]
// 005df172  896908               mov dword ptr [ecx + 8], ebp
// 005df175  eb22                 jmp 0x5df199
// 005df177  807c246800           cmp byte ptr [esp + 0x68], 0
// 005df17c  740d                 je 0x5df18b
// 005df17e  892e                 mov dword ptr [esi], ebp
// 005df180  8b4704               mov eax, dword ptr [edi + 4]
// 005df183  3b30                 cmp esi, dword ptr [eax]
// 005df185  7512                 jne 0x5df199
// 005df187  8928                 mov dword ptr [eax], ebp
// 005df189  eb0e                 jmp 0x5df199
// 005df18b  896e08               mov dword ptr [esi + 8], ebp
// 005df18e  8b4704               mov eax, dword ptr [edi + 4]
// 005df191  3b7008               cmp esi, dword ptr [eax + 8]
// 005df194  7503                 jne 0x5df199
// 005df196  896808               mov dword ptr [eax + 8], ebp
// 005df199  8b5504               mov edx, dword ptr [ebp + 4]
// 005df19c  807a1800             cmp byte ptr [edx + 0x18], 0
// 005df1a0  8d4504               lea eax, [ebp + 4]
// 005df1a3  8bf5                 mov esi, ebp
// 005df1a5  0f85ea000000         jne 0x5df295
// 005df1ab  eb03                 jmp 0x5df1b0
// 005df1ad  8d4900               lea ecx, [ecx]
// 005df1b0  8b08                 mov ecx, dword ptr [eax]
// 005df1b2  8b5104               mov edx, dword ptr [ecx + 4]
// 005df1b5  3b0a                 cmp ecx, dword ptr [edx]
// 005df1b7  7551                 jne 0x5df20a
// 005df1b9  8b5208               mov edx, dword ptr [edx + 8]
// 005df1bc  807a1800             cmp byte ptr [edx + 0x18], 0
// 005df1c0  7519                 jne 0x5df1db
// 005df1c2  885918               mov byte ptr [ecx + 0x18], bl
// 005df1c5  885a18               mov byte ptr [edx + 0x18], bl
// 005df1c8  8b10                 mov edx, dword ptr [eax]
// 005df1ca  8b4a04               mov ecx, dword ptr [edx + 4]
// 005df1cd  c6411800             mov byte ptr [ecx + 0x18], 0
// 005df1d1  8b10                 mov edx, dword ptr [eax]
// 005df1d3  8b7204               mov esi, dword ptr [edx + 4]
// 005df1d6  e9aa000000           jmp 0x5df285
// 005df1db  3b7108               cmp esi, dword ptr [ecx + 8]
// 005df1de  750a                 jne 0x5df1ea
// 005df1e0  8bf1                 mov esi, ecx
// 005df1e2  56                   push esi
// 005df1e3  8bcf                 mov ecx, edi
// 005df1e5  e8d6f2ffff           call 0x5de4c0
// 005df1ea  8b4604               mov eax, dword ptr [esi + 4]
// 005df1ed  885818               mov byte ptr [eax + 0x18], bl
// 005df1f0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005df1f3  8b5104               mov edx, dword ptr [ecx + 4]
// 005df1f6  c6421800             mov byte ptr [edx + 0x18], 0
// 005df1fa  8b4604               mov eax, dword ptr [esi + 4]
// 005df1fd  8b4804               mov ecx, dword ptr [eax + 4]
// 005df200  51                   push ecx
// 005df201  8bcf                 mov ecx, edi
// 005df203  e88802e3ff           call 0x40f490
// 005df208  eb7b                 jmp 0x5df285
// 005df20a  8b12                 mov edx, dword ptr [edx]
// 005df20c  807a1800             cmp byte ptr [edx + 0x18], 0
// 005df210  7516                 jne 0x5df228
// 005df212  885918               mov byte ptr [ecx + 0x18], bl
// 005df215  885a18               mov byte ptr [edx + 0x18], bl
// 005df218  8b10                 mov edx, dword ptr [eax]
// 005df21a  8b4a04               mov ecx, dword ptr [edx + 4]
// 005df21d  c6411800             mov byte ptr [ecx + 0x18], 0
// 005df221  8b10                 mov edx, dword ptr [eax]
// 005df223  8b7204               mov esi, dword ptr [edx + 4]
// 005df226  eb5d                 jmp 0x5df285
// 005df228  3b31                 cmp esi, dword ptr [ecx]
// 005df22a  750a                 jne 0x5df236
// 005df22c  8bf1                 mov esi, ecx
// 005df22e  56                   push esi
// 005df22f  8bcf                 mov ecx, edi
// 005df231  e85a02e3ff           call 0x40f490
// 005df236  8b4604               mov eax, dword ptr [esi + 4]
// 005df239  885818               mov byte ptr [eax + 0x18], bl
// 005df23c  8b4e04               mov ecx, dword ptr [esi + 4]
// 005df23f  8b5104               mov edx, dword ptr [ecx + 4]
// 005df242  c6421800             mov byte ptr [edx + 0x18], 0
// 005df246  8b4604               mov eax, dword ptr [esi + 4]
// 005df249  8b4004               mov eax, dword ptr [eax + 4]
// 005df24c  8b4808               mov ecx, dword ptr [eax + 8]
// 005df24f  8b11                 mov edx, dword ptr [ecx]
// 005df251  895008               mov dword ptr [eax + 8], edx
// 005df254  8b11                 mov edx, dword ptr [ecx]
// 005df256  807a1900             cmp byte ptr [edx + 0x19], 0
// 005df25a  7503                 jne 0x5df25f
// 005df25c  894204               mov dword ptr [edx + 4], eax
// 005df25f  8b5004               mov edx, dword ptr [eax + 4]
// 005df262  895104               mov dword ptr [ecx + 4], edx
// 005df265  8b5704               mov edx, dword ptr [edi + 4]
// 005df268  3b4204               cmp eax, dword ptr [edx + 4]
// 005df26b  7505                 jne 0x5df272
// 005df26d  894a04               mov dword ptr [edx + 4], ecx
// 005df270  eb0e                 jmp 0x5df280
// 005df272  8b5004               mov edx, dword ptr [eax + 4]
// 005df275  3b02                 cmp eax, dword ptr [edx]
// 005df277  7504                 jne 0x5df27d
// 005df279  890a                 mov dword ptr [edx], ecx
// 005df27b  eb03                 jmp 0x5df280
// 005df27d  894a08               mov dword ptr [edx + 8], ecx
// 005df280  8901                 mov dword ptr [ecx], eax
// 005df282  894804               mov dword ptr [eax + 4], ecx
// 005df285  8b4e04               mov ecx, dword ptr [esi + 4]
// 005df288  80791800             cmp byte ptr [ecx + 0x18], 0
// 005df28c  8d4604               lea eax, [esi + 4]
// 005df28f  0f841bffffff         je 0x5df1b0
// 005df295  8b5704               mov edx, dword ptr [edi + 4]
// 005df298  8b4204               mov eax, dword ptr [edx + 4]
// 005df29b  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 005df29f  885818               mov byte ptr [eax + 0x18], bl
// 005df2a2  8b442464             mov eax, dword ptr [esp + 0x64]
// 005df2a6  5e                   pop esi
// 005df2a7  896804               mov dword ptr [eax + 4], ebp
// 005df2aa  5d                   pop ebp
// 005df2ab  8938                 mov dword ptr [eax], edi
// 005df2ad  5b                   pop ebx
// 005df2ae  5f                   pop edi
// 005df2af  64890d00000000       mov dword ptr fs:[0], ecx
// 005df2b6  83c450               add esp, 0x50
// 005df2b9  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
