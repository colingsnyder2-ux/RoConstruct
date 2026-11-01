// from server: 100% by auto
// roc 2009-12 00667ac0  unit: RBX::SimpleThrottlingArbiter  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00667ac0
//
// 00667ac0  64a100000000         mov eax, dword ptr fs:[0]
// 00667ac6  6aff                 push -1
// 00667ac8  6812699500           push 0x956912
// 00667acd  50                   push eax
// 00667ace  64892500000000       mov dword ptr fs:[0], esp
// 00667ad5  83ec44               sub esp, 0x44
// 00667ad8  57                   push edi
// 00667ad9  8bf9                 mov edi, ecx
// 00667adb  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 00667ae2  7259                 jb 0x667b3d
// 00667ae4  6800f59900           push 0x99f500
// 00667ae9  8d4c2408             lea ecx, [esp + 8]
// 00667aed  ff15f4b69800         call dword ptr [0x98b6f4]
// 00667af3  8d4c2420             lea ecx, [esp + 0x20]
// 00667af7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00667aff  ff1554b79800         call dword ptr [0x98b754]
// 00667b05  8d442404             lea eax, [esp + 4]
// 00667b09  50                   push eax
// 00667b0a  8d4c2430             lea ecx, [esp + 0x30]
// 00667b0e  c644245401           mov byte ptr [esp + 0x54], 1
// 00667b13  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 00667b1b  ff15f0b69800         call dword ptr [0x98b6f0]
// 00667b21  68e4efa800           push 0xa8efe4
// 00667b26  8d4c2424             lea ecx, [esp + 0x24]
// 00667b2a  51                   push ecx
// 00667b2b  c644245800           mov byte ptr [esp + 0x58], 0
// 00667b30  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 00667b38  e83bcd1800           call 0x7f4878
// 00667b3d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00667b41  8b4718               mov eax, dword ptr [edi + 0x18]
// 00667b44  53                   push ebx
// 00667b45  55                   push ebp
// 00667b46  56                   push esi
// 00667b47  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00667b4b  6a00                 push 0
// 00667b4d  52                   push edx
// 00667b4e  50                   push eax
// 00667b4f  56                   push esi
// 00667b50  50                   push eax
// 00667b51  e8ea2ee1ff           call 0x47aa40
// 00667b56  8be8                 mov ebp, eax
// 00667b58  8b4718               mov eax, dword ptr [edi + 0x18]
// 00667b5b  bb01000000           mov ebx, 1
// 00667b60  015f1c               add dword ptr [edi + 0x1c], ebx
// 00667b63  3bf0                 cmp esi, eax
// 00667b65  7510                 jne 0x667b77
// 00667b67  896804               mov dword ptr [eax + 4], ebp
// 00667b6a  8b4718               mov eax, dword ptr [edi + 0x18]
// 00667b6d  8928                 mov dword ptr [eax], ebp
// 00667b6f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00667b72  896908               mov dword ptr [ecx + 8], ebp
// 00667b75  eb22                 jmp 0x667b99
// 00667b77  807c246800           cmp byte ptr [esp + 0x68], 0
// 00667b7c  740d                 je 0x667b8b
// 00667b7e  892e                 mov dword ptr [esi], ebp
// 00667b80  8b4718               mov eax, dword ptr [edi + 0x18]
// 00667b83  3b30                 cmp esi, dword ptr [eax]
// 00667b85  7512                 jne 0x667b99
// 00667b87  8928                 mov dword ptr [eax], ebp
// 00667b89  eb0e                 jmp 0x667b99
// 00667b8b  896e08               mov dword ptr [esi + 8], ebp
// 00667b8e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00667b91  3b7008               cmp esi, dword ptr [eax + 8]
// 00667b94  7503                 jne 0x667b99
// 00667b96  896808               mov dword ptr [eax + 8], ebp
// 00667b99  8b5504               mov edx, dword ptr [ebp + 4]
// 00667b9c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00667ba0  8d4504               lea eax, [ebp + 4]
// 00667ba3  8bf5                 mov esi, ebp
// 00667ba5  0f85ea000000         jne 0x667c95
// 00667bab  eb03                 jmp 0x667bb0
// 00667bad  8d4900               lea ecx, [ecx]
// 00667bb0  8b08                 mov ecx, dword ptr [eax]
// 00667bb2  8b5104               mov edx, dword ptr [ecx + 4]
// 00667bb5  3b0a                 cmp ecx, dword ptr [edx]
// 00667bb7  7551                 jne 0x667c0a
// 00667bb9  8b5208               mov edx, dword ptr [edx + 8]
// 00667bbc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00667bc0  7519                 jne 0x667bdb
// 00667bc2  88592c               mov byte ptr [ecx + 0x2c], bl
// 00667bc5  885a2c               mov byte ptr [edx + 0x2c], bl
// 00667bc8  8b10                 mov edx, dword ptr [eax]
// 00667bca  8b4a04               mov ecx, dword ptr [edx + 4]
// 00667bcd  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 00667bd1  8b10                 mov edx, dword ptr [eax]
// 00667bd3  8b7204               mov esi, dword ptr [edx + 4]
// 00667bd6  e9aa000000           jmp 0x667c85
// 00667bdb  3b7108               cmp esi, dword ptr [ecx + 8]
// 00667bde  750a                 jne 0x667bea
// 00667be0  8bf1                 mov esi, ecx
// 00667be2  56                   push esi
// 00667be3  8bcf                 mov ecx, edi
// 00667be5  e8264ee8ff           call 0x4eca10
// 00667bea  8b4604               mov eax, dword ptr [esi + 4]
// 00667bed  88582c               mov byte ptr [eax + 0x2c], bl
// 00667bf0  8b4e04               mov ecx, dword ptr [esi + 4]
// 00667bf3  8b5104               mov edx, dword ptr [ecx + 4]
// 00667bf6  c6422c00             mov byte ptr [edx + 0x2c], 0
// 00667bfa  8b4604               mov eax, dword ptr [esi + 4]
// 00667bfd  8b4804               mov ecx, dword ptr [eax + 4]
// 00667c00  51                   push ecx
// 00667c01  8bcf                 mov ecx, edi
// 00667c03  e8b84ee8ff           call 0x4ecac0
// 00667c08  eb7b                 jmp 0x667c85
// 00667c0a  8b12                 mov edx, dword ptr [edx]
// 00667c0c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00667c10  7516                 jne 0x667c28
// 00667c12  88592c               mov byte ptr [ecx + 0x2c], bl
// 00667c15  885a2c               mov byte ptr [edx + 0x2c], bl
// 00667c18  8b10                 mov edx, dword ptr [eax]
// 00667c1a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00667c1d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 00667c21  8b10                 mov edx, dword ptr [eax]
// 00667c23  8b7204               mov esi, dword ptr [edx + 4]
// 00667c26  eb5d                 jmp 0x667c85
// 00667c28  3b31                 cmp esi, dword ptr [ecx]
// 00667c2a  750a                 jne 0x667c36
// 00667c2c  8bf1                 mov esi, ecx
// 00667c2e  56                   push esi
// 00667c2f  8bcf                 mov ecx, edi
// 00667c31  e88a4ee8ff           call 0x4ecac0
// 00667c36  8b4604               mov eax, dword ptr [esi + 4]
// 00667c39  88582c               mov byte ptr [eax + 0x2c], bl
// 00667c3c  8b4e04               mov ecx, dword ptr [esi + 4]
// 00667c3f  8b5104               mov edx, dword ptr [ecx + 4]
// 00667c42  c6422c00             mov byte ptr [edx + 0x2c], 0
// 00667c46  8b4604               mov eax, dword ptr [esi + 4]
// 00667c49  8b4004               mov eax, dword ptr [eax + 4]
// 00667c4c  8b4808               mov ecx, dword ptr [eax + 8]
// 00667c4f  8b11                 mov edx, dword ptr [ecx]
// 00667c51  895008               mov dword ptr [eax + 8], edx
// 00667c54  8b11                 mov edx, dword ptr [ecx]
// 00667c56  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 00667c5a  7503                 jne 0x667c5f
// 00667c5c  894204               mov dword ptr [edx + 4], eax
// 00667c5f  8b5004               mov edx, dword ptr [eax + 4]
// 00667c62  895104               mov dword ptr [ecx + 4], edx
// 00667c65  8b5718               mov edx, dword ptr [edi + 0x18]
// 00667c68  3b4204               cmp eax, dword ptr [edx + 4]
// 00667c6b  7505                 jne 0x667c72
// 00667c6d  894a04               mov dword ptr [edx + 4], ecx
// 00667c70  eb0e                 jmp 0x667c80
// 00667c72  8b5004               mov edx, dword ptr [eax + 4]
// 00667c75  3b02                 cmp eax, dword ptr [edx]
// 00667c77  7504                 jne 0x667c7d
// 00667c79  890a                 mov dword ptr [edx], ecx
// 00667c7b  eb03                 jmp 0x667c80
// 00667c7d  894a08               mov dword ptr [edx + 8], ecx
// 00667c80  8901                 mov dword ptr [ecx], eax
// 00667c82  894804               mov dword ptr [eax + 4], ecx
// 00667c85  8b4e04               mov ecx, dword ptr [esi + 4]
// 00667c88  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 00667c8c  8d4604               lea eax, [esi + 4]
// 00667c8f  0f841bffffff         je 0x667bb0
// 00667c95  8b5718               mov edx, dword ptr [edi + 0x18]
// 00667c98  8b4204               mov eax, dword ptr [edx + 4]
// 00667c9b  88582c               mov byte ptr [eax + 0x2c], bl
// 00667c9e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00667ca2  8b0f                 mov ecx, dword ptr [edi]
// 00667ca4  5e                   pop esi
// 00667ca5  896804               mov dword ptr [eax + 4], ebp
// 00667ca8  5d                   pop ebp
// 00667ca9  8908                 mov dword ptr [eax], ecx
// 00667cab  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00667caf  5b                   pop ebx
// 00667cb0  5f                   pop edi
// 00667cb1  64890d00000000       mov dword ptr fs:[0], ecx
// 00667cb8  83c450               add esp, 0x50
// 00667cbb  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
