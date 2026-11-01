// from server: 100% by auto
// roc 2009-12 004b09f0  unit: Ogre::RbxTextureCompositorSceneManager  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b09f0
//
// 004b09f0  64a100000000         mov eax, dword ptr fs:[0]
// 004b09f6  6aff                 push -1
// 004b09f8  6812699500           push 0x956912
// 004b09fd  50                   push eax
// 004b09fe  64892500000000       mov dword ptr fs:[0], esp
// 004b0a05  83ec44               sub esp, 0x44
// 004b0a08  57                   push edi
// 004b0a09  8bf9                 mov edi, ecx
// 004b0a0b  817f1c0a59c802       cmp dword ptr [edi + 0x1c], 0x2c8590a
// 004b0a12  7259                 jb 0x4b0a6d
// 004b0a14  6800f59900           push 0x99f500
// 004b0a19  8d4c2408             lea ecx, [esp + 8]
// 004b0a1d  ff15f4b69800         call dword ptr [0x98b6f4]
// 004b0a23  8d4c2420             lea ecx, [esp + 0x20]
// 004b0a27  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004b0a2f  ff1554b79800         call dword ptr [0x98b754]
// 004b0a35  8d442404             lea eax, [esp + 4]
// 004b0a39  50                   push eax
// 004b0a3a  8d4c2430             lea ecx, [esp + 0x30]
// 004b0a3e  c644245401           mov byte ptr [esp + 0x54], 1
// 004b0a43  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 004b0a4b  ff15f0b69800         call dword ptr [0x98b6f0]
// 004b0a51  68e4efa800           push 0xa8efe4
// 004b0a56  8d4c2424             lea ecx, [esp + 0x24]
// 004b0a5a  51                   push ecx
// 004b0a5b  c644245800           mov byte ptr [esp + 0x58], 0
// 004b0a60  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 004b0a68  e80b3e3400           call 0x7f4878
// 004b0a6d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004b0a71  8b4718               mov eax, dword ptr [edi + 0x18]
// 004b0a74  53                   push ebx
// 004b0a75  55                   push ebp
// 004b0a76  56                   push esi
// 004b0a77  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004b0a7b  6a00                 push 0
// 004b0a7d  52                   push edx
// 004b0a7e  50                   push eax
// 004b0a7f  56                   push esi
// 004b0a80  50                   push eax
// 004b0a81  e8fafbffff           call 0x4b0680
// 004b0a86  8be8                 mov ebp, eax
// 004b0a88  8b4718               mov eax, dword ptr [edi + 0x18]
// 004b0a8b  bb01000000           mov ebx, 1
// 004b0a90  015f1c               add dword ptr [edi + 0x1c], ebx
// 004b0a93  3bf0                 cmp esi, eax
// 004b0a95  7510                 jne 0x4b0aa7
// 004b0a97  896804               mov dword ptr [eax + 4], ebp
// 004b0a9a  8b4718               mov eax, dword ptr [edi + 0x18]
// 004b0a9d  8928                 mov dword ptr [eax], ebp
// 004b0a9f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004b0aa2  896908               mov dword ptr [ecx + 8], ebp
// 004b0aa5  eb22                 jmp 0x4b0ac9
// 004b0aa7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004b0aac  740d                 je 0x4b0abb
// 004b0aae  892e                 mov dword ptr [esi], ebp
// 004b0ab0  8b4718               mov eax, dword ptr [edi + 0x18]
// 004b0ab3  3b30                 cmp esi, dword ptr [eax]
// 004b0ab5  7512                 jne 0x4b0ac9
// 004b0ab7  8928                 mov dword ptr [eax], ebp
// 004b0ab9  eb0e                 jmp 0x4b0ac9
// 004b0abb  896e08               mov dword ptr [esi + 8], ebp
// 004b0abe  8b4718               mov eax, dword ptr [edi + 0x18]
// 004b0ac1  3b7008               cmp esi, dword ptr [eax + 8]
// 004b0ac4  7503                 jne 0x4b0ac9
// 004b0ac6  896808               mov dword ptr [eax + 8], ebp
// 004b0ac9  8b5504               mov edx, dword ptr [ebp + 4]
// 004b0acc  807a6800             cmp byte ptr [edx + 0x68], 0
// 004b0ad0  8d4504               lea eax, [ebp + 4]
// 004b0ad3  8bf5                 mov esi, ebp
// 004b0ad5  0f85ea000000         jne 0x4b0bc5
// 004b0adb  eb03                 jmp 0x4b0ae0
// 004b0add  8d4900               lea ecx, [ecx]
// 004b0ae0  8b08                 mov ecx, dword ptr [eax]
// 004b0ae2  8b5104               mov edx, dword ptr [ecx + 4]
// 004b0ae5  3b0a                 cmp ecx, dword ptr [edx]
// 004b0ae7  7551                 jne 0x4b0b3a
// 004b0ae9  8b5208               mov edx, dword ptr [edx + 8]
// 004b0aec  807a6800             cmp byte ptr [edx + 0x68], 0
// 004b0af0  7519                 jne 0x4b0b0b
// 004b0af2  885968               mov byte ptr [ecx + 0x68], bl
// 004b0af5  885a68               mov byte ptr [edx + 0x68], bl
// 004b0af8  8b10                 mov edx, dword ptr [eax]
// 004b0afa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004b0afd  c6416800             mov byte ptr [ecx + 0x68], 0
// 004b0b01  8b10                 mov edx, dword ptr [eax]
// 004b0b03  8b7204               mov esi, dword ptr [edx + 4]
// 004b0b06  e9aa000000           jmp 0x4b0bb5
// 004b0b0b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004b0b0e  750a                 jne 0x4b0b1a
// 004b0b10  8bf1                 mov esi, ecx
// 004b0b12  56                   push esi
// 004b0b13  8bcf                 mov ecx, edi
// 004b0b15  e8a6d8ffff           call 0x4ae3c0
// 004b0b1a  8b4604               mov eax, dword ptr [esi + 4]
// 004b0b1d  885868               mov byte ptr [eax + 0x68], bl
// 004b0b20  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b0b23  8b5104               mov edx, dword ptr [ecx + 4]
// 004b0b26  c6426800             mov byte ptr [edx + 0x68], 0
// 004b0b2a  8b4604               mov eax, dword ptr [esi + 4]
// 004b0b2d  8b4804               mov ecx, dword ptr [eax + 4]
// 004b0b30  51                   push ecx
// 004b0b31  8bcf                 mov ecx, edi
// 004b0b33  e898d5ffff           call 0x4ae0d0
// 004b0b38  eb7b                 jmp 0x4b0bb5
// 004b0b3a  8b12                 mov edx, dword ptr [edx]
// 004b0b3c  807a6800             cmp byte ptr [edx + 0x68], 0
// 004b0b40  7516                 jne 0x4b0b58
// 004b0b42  885968               mov byte ptr [ecx + 0x68], bl
// 004b0b45  885a68               mov byte ptr [edx + 0x68], bl
// 004b0b48  8b10                 mov edx, dword ptr [eax]
// 004b0b4a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004b0b4d  c6416800             mov byte ptr [ecx + 0x68], 0
// 004b0b51  8b10                 mov edx, dword ptr [eax]
// 004b0b53  8b7204               mov esi, dword ptr [edx + 4]
// 004b0b56  eb5d                 jmp 0x4b0bb5
// 004b0b58  3b31                 cmp esi, dword ptr [ecx]
// 004b0b5a  750a                 jne 0x4b0b66
// 004b0b5c  8bf1                 mov esi, ecx
// 004b0b5e  56                   push esi
// 004b0b5f  8bcf                 mov ecx, edi
// 004b0b61  e86ad5ffff           call 0x4ae0d0
// 004b0b66  8b4604               mov eax, dword ptr [esi + 4]
// 004b0b69  885868               mov byte ptr [eax + 0x68], bl
// 004b0b6c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b0b6f  8b5104               mov edx, dword ptr [ecx + 4]
// 004b0b72  c6426800             mov byte ptr [edx + 0x68], 0
// 004b0b76  8b4604               mov eax, dword ptr [esi + 4]
// 004b0b79  8b4004               mov eax, dword ptr [eax + 4]
// 004b0b7c  8b4808               mov ecx, dword ptr [eax + 8]
// 004b0b7f  8b11                 mov edx, dword ptr [ecx]
// 004b0b81  895008               mov dword ptr [eax + 8], edx
// 004b0b84  8b11                 mov edx, dword ptr [ecx]
// 004b0b86  807a6900             cmp byte ptr [edx + 0x69], 0
// 004b0b8a  7503                 jne 0x4b0b8f
// 004b0b8c  894204               mov dword ptr [edx + 4], eax
// 004b0b8f  8b5004               mov edx, dword ptr [eax + 4]
// 004b0b92  895104               mov dword ptr [ecx + 4], edx
// 004b0b95  8b5718               mov edx, dword ptr [edi + 0x18]
// 004b0b98  3b4204               cmp eax, dword ptr [edx + 4]
// 004b0b9b  7505                 jne 0x4b0ba2
// 004b0b9d  894a04               mov dword ptr [edx + 4], ecx
// 004b0ba0  eb0e                 jmp 0x4b0bb0
// 004b0ba2  8b5004               mov edx, dword ptr [eax + 4]
// 004b0ba5  3b02                 cmp eax, dword ptr [edx]
// 004b0ba7  7504                 jne 0x4b0bad
// 004b0ba9  890a                 mov dword ptr [edx], ecx
// 004b0bab  eb03                 jmp 0x4b0bb0
// 004b0bad  894a08               mov dword ptr [edx + 8], ecx
// 004b0bb0  8901                 mov dword ptr [ecx], eax
// 004b0bb2  894804               mov dword ptr [eax + 4], ecx
// 004b0bb5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b0bb8  80796800             cmp byte ptr [ecx + 0x68], 0
// 004b0bbc  8d4604               lea eax, [esi + 4]
// 004b0bbf  0f841bffffff         je 0x4b0ae0
// 004b0bc5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004b0bc8  8b4204               mov eax, dword ptr [edx + 4]
// 004b0bcb  885868               mov byte ptr [eax + 0x68], bl
// 004b0bce  8b442464             mov eax, dword ptr [esp + 0x64]
// 004b0bd2  8b0f                 mov ecx, dword ptr [edi]
// 004b0bd4  5e                   pop esi
// 004b0bd5  896804               mov dword ptr [eax + 4], ebp
// 004b0bd8  5d                   pop ebp
// 004b0bd9  8908                 mov dword ptr [eax], ecx
// 004b0bdb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004b0bdf  5b                   pop ebx
// 004b0be0  5f                   pop edi
// 004b0be1  64890d00000000       mov dword ptr fs:[0], ecx
// 004b0be8  83c450               add esp, 0x50
// 004b0beb  c21000               ret 0x10
// standard library map_str<pod64> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
