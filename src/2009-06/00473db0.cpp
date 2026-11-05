// from server: 100% by auto
// roc 2009-06 00473db0  unit: Ogre::VRbxSky::?$SharedPtr  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00473db0
//
// 00473db0  64a100000000         mov eax, dword ptr fs:[0]
// 00473db6  6aff                 push -1
// 00473db8  68b2db8500           push 0x85dbb2
// 00473dbd  50                   push eax
// 00473dbe  64892500000000       mov dword ptr fs:[0], esp
// 00473dc5  83ec44               sub esp, 0x44
// 00473dc8  57                   push edi
// 00473dc9  8bf9                 mov edi, ecx
// 00473dcb  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 00473dd2  7259                 jb 0x473e2d
// 00473dd4  68c0c98a00           push 0x8ac9c0
// 00473dd9  8d4c2408             lea ecx, [esp + 8]
// 00473ddd  ff15b4e48900         call dword ptr [0x89e4b4]
// 00473de3  8d4c2420             lea ecx, [esp + 0x20]
// 00473de7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00473def  ff15b8e98900         call dword ptr [0x89e9b8]
// 00473df5  8d442404             lea eax, [esp + 4]
// 00473df9  50                   push eax
// 00473dfa  8d4c2430             lea ecx, [esp + 0x30]
// 00473dfe  c644245401           mov byte ptr [esp + 0x54], 1
// 00473e03  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 00473e0b  ff15b8e48900         call dword ptr [0x89e4b8]
// 00473e11  6834929700           push 0x979234
// 00473e16  8d4c2424             lea ecx, [esp + 0x24]
// 00473e1a  51                   push ecx
// 00473e1b  c644245800           mov byte ptr [esp + 0x58], 0
// 00473e20  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 00473e28  e81d5c2a00           call 0x719a4a
// 00473e2d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00473e31  8b4718               mov eax, dword ptr [edi + 0x18]
// 00473e34  53                   push ebx
// 00473e35  55                   push ebp
// 00473e36  56                   push esi
// 00473e37  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00473e3b  6a00                 push 0
// 00473e3d  52                   push edx
// 00473e3e  50                   push eax
// 00473e3f  56                   push esi
// 00473e40  50                   push eax
// 00473e41  e8cafeffff           call 0x473d10
// 00473e46  8be8                 mov ebp, eax
// 00473e48  8b4718               mov eax, dword ptr [edi + 0x18]
// 00473e4b  bb01000000           mov ebx, 1
// 00473e50  015f1c               add dword ptr [edi + 0x1c], ebx
// 00473e53  3bf0                 cmp esi, eax
// 00473e55  7510                 jne 0x473e67
// 00473e57  896804               mov dword ptr [eax + 4], ebp
// 00473e5a  8b4718               mov eax, dword ptr [edi + 0x18]
// 00473e5d  8928                 mov dword ptr [eax], ebp
// 00473e5f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00473e62  896908               mov dword ptr [ecx + 8], ebp
// 00473e65  eb22                 jmp 0x473e89
// 00473e67  807c246800           cmp byte ptr [esp + 0x68], 0
// 00473e6c  740d                 je 0x473e7b
// 00473e6e  892e                 mov dword ptr [esi], ebp
// 00473e70  8b4718               mov eax, dword ptr [edi + 0x18]
// 00473e73  3b30                 cmp esi, dword ptr [eax]
// 00473e75  7512                 jne 0x473e89
// 00473e77  8928                 mov dword ptr [eax], ebp
// 00473e79  eb0e                 jmp 0x473e89
// 00473e7b  896e08               mov dword ptr [esi + 8], ebp
// 00473e7e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00473e81  3b7008               cmp esi, dword ptr [eax + 8]
// 00473e84  7503                 jne 0x473e89
// 00473e86  896808               mov dword ptr [eax + 8], ebp
// 00473e89  8b5504               mov edx, dword ptr [ebp + 4]
// 00473e8c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00473e90  8d4504               lea eax, [ebp + 4]
// 00473e93  8bf5                 mov esi, ebp
// 00473e95  0f85ea000000         jne 0x473f85
// 00473e9b  eb03                 jmp 0x473ea0
// 00473e9d  8d4900               lea ecx, [ecx]
// 00473ea0  8b08                 mov ecx, dword ptr [eax]
// 00473ea2  8b5104               mov edx, dword ptr [ecx + 4]
// 00473ea5  3b0a                 cmp ecx, dword ptr [edx]
// 00473ea7  7551                 jne 0x473efa
// 00473ea9  8b5208               mov edx, dword ptr [edx + 8]
// 00473eac  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00473eb0  7519                 jne 0x473ecb
// 00473eb2  88592c               mov byte ptr [ecx + 0x2c], bl
// 00473eb5  885a2c               mov byte ptr [edx + 0x2c], bl
// 00473eb8  8b10                 mov edx, dword ptr [eax]
// 00473eba  8b4a04               mov ecx, dword ptr [edx + 4]
// 00473ebd  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 00473ec1  8b10                 mov edx, dword ptr [eax]
// 00473ec3  8b7204               mov esi, dword ptr [edx + 4]
// 00473ec6  e9aa000000           jmp 0x473f75
// 00473ecb  3b7108               cmp esi, dword ptr [ecx + 8]
// 00473ece  750a                 jne 0x473eda
// 00473ed0  8bf1                 mov esi, ecx
// 00473ed2  56                   push esi
// 00473ed3  8bcf                 mov ecx, edi
// 00473ed5  e8a6ab1c00           call 0x63ea80
// 00473eda  8b4604               mov eax, dword ptr [esi + 4]
// 00473edd  88582c               mov byte ptr [eax + 0x2c], bl
// 00473ee0  8b4e04               mov ecx, dword ptr [esi + 4]
// 00473ee3  8b5104               mov edx, dword ptr [ecx + 4]
// 00473ee6  c6422c00             mov byte ptr [edx + 0x2c], 0
// 00473eea  8b4604               mov eax, dword ptr [esi + 4]
// 00473eed  8b4804               mov ecx, dword ptr [eax + 4]
// 00473ef0  51                   push ecx
// 00473ef1  8bcf                 mov ecx, edi
// 00473ef3  e8088b0600           call 0x4dca00
// 00473ef8  eb7b                 jmp 0x473f75
// 00473efa  8b12                 mov edx, dword ptr [edx]
// 00473efc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00473f00  7516                 jne 0x473f18
// 00473f02  88592c               mov byte ptr [ecx + 0x2c], bl
// 00473f05  885a2c               mov byte ptr [edx + 0x2c], bl
// 00473f08  8b10                 mov edx, dword ptr [eax]
// 00473f0a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00473f0d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 00473f11  8b10                 mov edx, dword ptr [eax]
// 00473f13  8b7204               mov esi, dword ptr [edx + 4]
// 00473f16  eb5d                 jmp 0x473f75
// 00473f18  3b31                 cmp esi, dword ptr [ecx]
// 00473f1a  750a                 jne 0x473f26
// 00473f1c  8bf1                 mov esi, ecx
// 00473f1e  56                   push esi
// 00473f1f  8bcf                 mov ecx, edi
// 00473f21  e8da8a0600           call 0x4dca00
// 00473f26  8b4604               mov eax, dword ptr [esi + 4]
// 00473f29  88582c               mov byte ptr [eax + 0x2c], bl
// 00473f2c  8b4e04               mov ecx, dword ptr [esi + 4]
// 00473f2f  8b5104               mov edx, dword ptr [ecx + 4]
// 00473f32  c6422c00             mov byte ptr [edx + 0x2c], 0
// 00473f36  8b4604               mov eax, dword ptr [esi + 4]
// 00473f39  8b4004               mov eax, dword ptr [eax + 4]
// 00473f3c  8b4808               mov ecx, dword ptr [eax + 8]
// 00473f3f  8b11                 mov edx, dword ptr [ecx]
// 00473f41  895008               mov dword ptr [eax + 8], edx
// 00473f44  8b11                 mov edx, dword ptr [ecx]
// 00473f46  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 00473f4a  7503                 jne 0x473f4f
// 00473f4c  894204               mov dword ptr [edx + 4], eax
// 00473f4f  8b5004               mov edx, dword ptr [eax + 4]
// 00473f52  895104               mov dword ptr [ecx + 4], edx
// 00473f55  8b5718               mov edx, dword ptr [edi + 0x18]
// 00473f58  3b4204               cmp eax, dword ptr [edx + 4]
// 00473f5b  7505                 jne 0x473f62
// 00473f5d  894a04               mov dword ptr [edx + 4], ecx
// 00473f60  eb0e                 jmp 0x473f70
// 00473f62  8b5004               mov edx, dword ptr [eax + 4]
// 00473f65  3b02                 cmp eax, dword ptr [edx]
// 00473f67  7504                 jne 0x473f6d
// 00473f69  890a                 mov dword ptr [edx], ecx
// 00473f6b  eb03                 jmp 0x473f70
// 00473f6d  894a08               mov dword ptr [edx + 8], ecx
// 00473f70  8901                 mov dword ptr [ecx], eax
// 00473f72  894804               mov dword ptr [eax + 4], ecx
// 00473f75  8b4e04               mov ecx, dword ptr [esi + 4]
// 00473f78  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 00473f7c  8d4604               lea eax, [esi + 4]
// 00473f7f  0f841bffffff         je 0x473ea0
// 00473f85  8b5718               mov edx, dword ptr [edi + 0x18]
// 00473f88  8b4204               mov eax, dword ptr [edx + 4]
// 00473f8b  88582c               mov byte ptr [eax + 0x2c], bl
// 00473f8e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00473f92  8b0f                 mov ecx, dword ptr [edi]
// 00473f94  5e                   pop esi
// 00473f95  896804               mov dword ptr [eax + 4], ebp
// 00473f98  5d                   pop ebp
// 00473f99  8908                 mov dword ptr [eax], ecx
// 00473f9b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00473f9f  5b                   pop ebx
// 00473fa0  5f                   pop edi
// 00473fa1  64890d00000000       mov dword ptr fs:[0], ecx
// 00473fa8  83c450               add esp, 0x50
// 00473fab  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
