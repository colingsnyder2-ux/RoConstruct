// from server: 100% by auto
// roc 2008-06 00691d90  unit: Ogre::RbxSceneManager  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00691d90
//
// 00691d90  64a100000000         mov eax, dword ptr fs:[0]
// 00691d96  6aff                 push -1
// 00691d98  6842e87d00           push 0x7de842
// 00691d9d  50                   push eax
// 00691d9e  64892500000000       mov dword ptr fs:[0], esp
// 00691da5  83ec44               sub esp, 0x44
// 00691da8  57                   push edi
// 00691da9  8bf9                 mov edi, ecx
// 00691dab  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 00691db2  7259                 jb 0x691e0d
// 00691db4  688cb28000           push 0x80b28c
// 00691db9  8d4c2408             lea ecx, [esp + 8]
// 00691dbd  ff1558248000         call dword ptr [0x802458]
// 00691dc3  8d4c2420             lea ecx, [esp + 0x20]
// 00691dc7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00691dcf  ff1598288000         call dword ptr [0x802898]
// 00691dd5  8d442404             lea eax, [esp + 4]
// 00691dd9  50                   push eax
// 00691dda  8d4c2430             lea ecx, [esp + 0x30]
// 00691dde  c644245401           mov byte ptr [esp + 0x54], 1
// 00691de3  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 00691deb  ff155c248000         call dword ptr [0x80245c]
// 00691df1  68c00c8d00           push 0x8d0cc0
// 00691df6  8d4c2424             lea ecx, [esp + 0x24]
// 00691dfa  51                   push ecx
// 00691dfb  c644245800           mov byte ptr [esp + 0x58], 0
// 00691e00  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 00691e08  e87ff70000           call 0x6a158c
// 00691e0d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00691e11  8b4718               mov eax, dword ptr [edi + 0x18]
// 00691e14  53                   push ebx
// 00691e15  55                   push ebp
// 00691e16  56                   push esi
// 00691e17  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00691e1b  6a00                 push 0
// 00691e1d  52                   push edx
// 00691e1e  50                   push eax
// 00691e1f  56                   push esi
// 00691e20  50                   push eax
// 00691e21  e80ae2ffff           call 0x690030
// 00691e26  8be8                 mov ebp, eax
// 00691e28  8b4718               mov eax, dword ptr [edi + 0x18]
// 00691e2b  bb01000000           mov ebx, 1
// 00691e30  015f1c               add dword ptr [edi + 0x1c], ebx
// 00691e33  3bf0                 cmp esi, eax
// 00691e35  7510                 jne 0x691e47
// 00691e37  896804               mov dword ptr [eax + 4], ebp
// 00691e3a  8b4718               mov eax, dword ptr [edi + 0x18]
// 00691e3d  8928                 mov dword ptr [eax], ebp
// 00691e3f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00691e42  896908               mov dword ptr [ecx + 8], ebp
// 00691e45  eb22                 jmp 0x691e69
// 00691e47  807c246800           cmp byte ptr [esp + 0x68], 0
// 00691e4c  740d                 je 0x691e5b
// 00691e4e  892e                 mov dword ptr [esi], ebp
// 00691e50  8b4718               mov eax, dword ptr [edi + 0x18]
// 00691e53  3b30                 cmp esi, dword ptr [eax]
// 00691e55  7512                 jne 0x691e69
// 00691e57  8928                 mov dword ptr [eax], ebp
// 00691e59  eb0e                 jmp 0x691e69
// 00691e5b  896e08               mov dword ptr [esi + 8], ebp
// 00691e5e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00691e61  3b7008               cmp esi, dword ptr [eax + 8]
// 00691e64  7503                 jne 0x691e69
// 00691e66  896808               mov dword ptr [eax + 8], ebp
// 00691e69  8b5504               mov edx, dword ptr [ebp + 4]
// 00691e6c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00691e70  8d4504               lea eax, [ebp + 4]
// 00691e73  8bf5                 mov esi, ebp
// 00691e75  0f85ea000000         jne 0x691f65
// 00691e7b  eb03                 jmp 0x691e80
// 00691e7d  8d4900               lea ecx, [ecx]
// 00691e80  8b08                 mov ecx, dword ptr [eax]
// 00691e82  8b5104               mov edx, dword ptr [ecx + 4]
// 00691e85  3b0a                 cmp ecx, dword ptr [edx]
// 00691e87  7551                 jne 0x691eda
// 00691e89  8b5208               mov edx, dword ptr [edx + 8]
// 00691e8c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00691e90  7519                 jne 0x691eab
// 00691e92  88592c               mov byte ptr [ecx + 0x2c], bl
// 00691e95  885a2c               mov byte ptr [edx + 0x2c], bl
// 00691e98  8b10                 mov edx, dword ptr [eax]
// 00691e9a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00691e9d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 00691ea1  8b10                 mov edx, dword ptr [eax]
// 00691ea3  8b7204               mov esi, dword ptr [edx + 4]
// 00691ea6  e9aa000000           jmp 0x691f55
// 00691eab  3b7108               cmp esi, dword ptr [ecx + 8]
// 00691eae  750a                 jne 0x691eba
// 00691eb0  8bf1                 mov esi, ecx
// 00691eb2  56                   push esi
// 00691eb3  8bcf                 mov ecx, edi
// 00691eb5  e846c0ffff           call 0x68df00
// 00691eba  8b4604               mov eax, dword ptr [esi + 4]
// 00691ebd  88582c               mov byte ptr [eax + 0x2c], bl
// 00691ec0  8b4e04               mov ecx, dword ptr [esi + 4]
// 00691ec3  8b5104               mov edx, dword ptr [ecx + 4]
// 00691ec6  c6422c00             mov byte ptr [edx + 0x2c], 0
// 00691eca  8b4604               mov eax, dword ptr [esi + 4]
// 00691ecd  8b4804               mov ecx, dword ptr [eax + 4]
// 00691ed0  51                   push ecx
// 00691ed1  8bcf                 mov ecx, edi
// 00691ed3  e8f8b0ffff           call 0x68cfd0
// 00691ed8  eb7b                 jmp 0x691f55
// 00691eda  8b12                 mov edx, dword ptr [edx]
// 00691edc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00691ee0  7516                 jne 0x691ef8
// 00691ee2  88592c               mov byte ptr [ecx + 0x2c], bl
// 00691ee5  885a2c               mov byte ptr [edx + 0x2c], bl
// 00691ee8  8b10                 mov edx, dword ptr [eax]
// 00691eea  8b4a04               mov ecx, dword ptr [edx + 4]
// 00691eed  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 00691ef1  8b10                 mov edx, dword ptr [eax]
// 00691ef3  8b7204               mov esi, dword ptr [edx + 4]
// 00691ef6  eb5d                 jmp 0x691f55
// 00691ef8  3b31                 cmp esi, dword ptr [ecx]
// 00691efa  750a                 jne 0x691f06
// 00691efc  8bf1                 mov esi, ecx
// 00691efe  56                   push esi
// 00691eff  8bcf                 mov ecx, edi
// 00691f01  e8cab0ffff           call 0x68cfd0
// 00691f06  8b4604               mov eax, dword ptr [esi + 4]
// 00691f09  88582c               mov byte ptr [eax + 0x2c], bl
// 00691f0c  8b4e04               mov ecx, dword ptr [esi + 4]
// 00691f0f  8b5104               mov edx, dword ptr [ecx + 4]
// 00691f12  c6422c00             mov byte ptr [edx + 0x2c], 0
// 00691f16  8b4604               mov eax, dword ptr [esi + 4]
// 00691f19  8b4004               mov eax, dword ptr [eax + 4]
// 00691f1c  8b4808               mov ecx, dword ptr [eax + 8]
// 00691f1f  8b11                 mov edx, dword ptr [ecx]
// 00691f21  895008               mov dword ptr [eax + 8], edx
// 00691f24  8b11                 mov edx, dword ptr [ecx]
// 00691f26  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 00691f2a  7503                 jne 0x691f2f
// 00691f2c  894204               mov dword ptr [edx + 4], eax
// 00691f2f  8b5004               mov edx, dword ptr [eax + 4]
// 00691f32  895104               mov dword ptr [ecx + 4], edx
// 00691f35  8b5718               mov edx, dword ptr [edi + 0x18]
// 00691f38  3b4204               cmp eax, dword ptr [edx + 4]
// 00691f3b  7505                 jne 0x691f42
// 00691f3d  894a04               mov dword ptr [edx + 4], ecx
// 00691f40  eb0e                 jmp 0x691f50
// 00691f42  8b5004               mov edx, dword ptr [eax + 4]
// 00691f45  3b02                 cmp eax, dword ptr [edx]
// 00691f47  7504                 jne 0x691f4d
// 00691f49  890a                 mov dword ptr [edx], ecx
// 00691f4b  eb03                 jmp 0x691f50
// 00691f4d  894a08               mov dword ptr [edx + 8], ecx
// 00691f50  8901                 mov dword ptr [ecx], eax
// 00691f52  894804               mov dword ptr [eax + 4], ecx
// 00691f55  8b4e04               mov ecx, dword ptr [esi + 4]
// 00691f58  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 00691f5c  8d4604               lea eax, [esi + 4]
// 00691f5f  0f841bffffff         je 0x691e80
// 00691f65  8b5718               mov edx, dword ptr [edi + 0x18]
// 00691f68  8b4204               mov eax, dword ptr [edx + 4]
// 00691f6b  88582c               mov byte ptr [eax + 0x2c], bl
// 00691f6e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00691f72  8b0f                 mov ecx, dword ptr [edi]
// 00691f74  5e                   pop esi
// 00691f75  896804               mov dword ptr [eax + 4], ebp
// 00691f78  5d                   pop ebp
// 00691f79  8908                 mov dword ptr [eax], ecx
// 00691f7b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00691f7f  5b                   pop ebx
// 00691f80  5f                   pop edi
// 00691f81  64890d00000000       mov dword ptr fs:[0], ecx
// 00691f88  83c450               add esp, 0x50
// 00691f8b  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
