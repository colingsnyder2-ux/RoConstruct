// from server: 100% by auto
// roc 2008-06 00423e30  unit: CSelectionTreeCtrl  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00423e30
//
// 00423e30  64a100000000         mov eax, dword ptr fs:[0]
// 00423e36  6aff                 push -1
// 00423e38  6842e87d00           push 0x7de842
// 00423e3d  50                   push eax
// 00423e3e  64892500000000       mov dword ptr fs:[0], esp
// 00423e45  83ec44               sub esp, 0x44
// 00423e48  57                   push edi
// 00423e49  8bf9                 mov edi, ecx
// 00423e4b  817f1cfeffff1f       cmp dword ptr [edi + 0x1c], 0x1ffffffe
// 00423e52  7259                 jb 0x423ead
// 00423e54  688cb28000           push 0x80b28c
// 00423e59  8d4c2408             lea ecx, [esp + 8]
// 00423e5d  ff1558248000         call dword ptr [0x802458]
// 00423e63  8d4c2420             lea ecx, [esp + 0x20]
// 00423e67  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00423e6f  ff1598288000         call dword ptr [0x802898]
// 00423e75  8d442404             lea eax, [esp + 4]
// 00423e79  50                   push eax
// 00423e7a  8d4c2430             lea ecx, [esp + 0x30]
// 00423e7e  c644245401           mov byte ptr [esp + 0x54], 1
// 00423e83  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 00423e8b  ff155c248000         call dword ptr [0x80245c]
// 00423e91  68c00c8d00           push 0x8d0cc0
// 00423e96  8d4c2424             lea ecx, [esp + 0x24]
// 00423e9a  51                   push ecx
// 00423e9b  c644245800           mov byte ptr [esp + 0x58], 0
// 00423ea0  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 00423ea8  e8dfd62700           call 0x6a158c
// 00423ead  8b542464             mov edx, dword ptr [esp + 0x64]
// 00423eb1  8b4718               mov eax, dword ptr [edi + 0x18]
// 00423eb4  53                   push ebx
// 00423eb5  55                   push ebp
// 00423eb6  56                   push esi
// 00423eb7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00423ebb  6a00                 push 0
// 00423ebd  52                   push edx
// 00423ebe  50                   push eax
// 00423ebf  56                   push esi
// 00423ec0  50                   push eax
// 00423ec1  e82afaffff           call 0x4238f0
// 00423ec6  8be8                 mov ebp, eax
// 00423ec8  8b4718               mov eax, dword ptr [edi + 0x18]
// 00423ecb  bb01000000           mov ebx, 1
// 00423ed0  015f1c               add dword ptr [edi + 0x1c], ebx
// 00423ed3  3bf0                 cmp esi, eax
// 00423ed5  7510                 jne 0x423ee7
// 00423ed7  896804               mov dword ptr [eax + 4], ebp
// 00423eda  8b4718               mov eax, dword ptr [edi + 0x18]
// 00423edd  8928                 mov dword ptr [eax], ebp
// 00423edf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00423ee2  896908               mov dword ptr [ecx + 8], ebp
// 00423ee5  eb22                 jmp 0x423f09
// 00423ee7  807c246800           cmp byte ptr [esp + 0x68], 0
// 00423eec  740d                 je 0x423efb
// 00423eee  892e                 mov dword ptr [esi], ebp
// 00423ef0  8b4718               mov eax, dword ptr [edi + 0x18]
// 00423ef3  3b30                 cmp esi, dword ptr [eax]
// 00423ef5  7512                 jne 0x423f09
// 00423ef7  8928                 mov dword ptr [eax], ebp
// 00423ef9  eb0e                 jmp 0x423f09
// 00423efb  896e08               mov dword ptr [esi + 8], ebp
// 00423efe  8b4718               mov eax, dword ptr [edi + 0x18]
// 00423f01  3b7008               cmp esi, dword ptr [eax + 8]
// 00423f04  7503                 jne 0x423f09
// 00423f06  896808               mov dword ptr [eax + 8], ebp
// 00423f09  8b5504               mov edx, dword ptr [ebp + 4]
// 00423f0c  807a1400             cmp byte ptr [edx + 0x14], 0
// 00423f10  8d4504               lea eax, [ebp + 4]
// 00423f13  8bf5                 mov esi, ebp
// 00423f15  0f85ea000000         jne 0x424005
// 00423f1b  eb03                 jmp 0x423f20
// 00423f1d  8d4900               lea ecx, [ecx]
// 00423f20  8b08                 mov ecx, dword ptr [eax]
// 00423f22  8b5104               mov edx, dword ptr [ecx + 4]
// 00423f25  3b0a                 cmp ecx, dword ptr [edx]
// 00423f27  7551                 jne 0x423f7a
// 00423f29  8b5208               mov edx, dword ptr [edx + 8]
// 00423f2c  807a1400             cmp byte ptr [edx + 0x14], 0
// 00423f30  7519                 jne 0x423f4b
// 00423f32  885914               mov byte ptr [ecx + 0x14], bl
// 00423f35  885a14               mov byte ptr [edx + 0x14], bl
// 00423f38  8b10                 mov edx, dword ptr [eax]
// 00423f3a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00423f3d  c6411400             mov byte ptr [ecx + 0x14], 0
// 00423f41  8b10                 mov edx, dword ptr [eax]
// 00423f43  8b7204               mov esi, dword ptr [edx + 4]
// 00423f46  e9aa000000           jmp 0x423ff5
// 00423f4b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00423f4e  750a                 jne 0x423f5a
// 00423f50  8bf1                 mov esi, ecx
// 00423f52  56                   push esi
// 00423f53  8bcf                 mov ecx, edi
// 00423f55  e846130200           call 0x4452a0
// 00423f5a  8b4604               mov eax, dword ptr [esi + 4]
// 00423f5d  885814               mov byte ptr [eax + 0x14], bl
// 00423f60  8b4e04               mov ecx, dword ptr [esi + 4]
// 00423f63  8b5104               mov edx, dword ptr [ecx + 4]
// 00423f66  c6421400             mov byte ptr [edx + 0x14], 0
// 00423f6a  8b4604               mov eax, dword ptr [esi + 4]
// 00423f6d  8b4804               mov ecx, dword ptr [eax + 4]
// 00423f70  51                   push ecx
// 00423f71  8bcf                 mov ecx, edi
// 00423f73  e8c82c1900           call 0x5b6c40
// 00423f78  eb7b                 jmp 0x423ff5
// 00423f7a  8b12                 mov edx, dword ptr [edx]
// 00423f7c  807a1400             cmp byte ptr [edx + 0x14], 0
// 00423f80  7516                 jne 0x423f98
// 00423f82  885914               mov byte ptr [ecx + 0x14], bl
// 00423f85  885a14               mov byte ptr [edx + 0x14], bl
// 00423f88  8b10                 mov edx, dword ptr [eax]
// 00423f8a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00423f8d  c6411400             mov byte ptr [ecx + 0x14], 0
// 00423f91  8b10                 mov edx, dword ptr [eax]
// 00423f93  8b7204               mov esi, dword ptr [edx + 4]
// 00423f96  eb5d                 jmp 0x423ff5
// 00423f98  3b31                 cmp esi, dword ptr [ecx]
// 00423f9a  750a                 jne 0x423fa6
// 00423f9c  8bf1                 mov esi, ecx
// 00423f9e  56                   push esi
// 00423f9f  8bcf                 mov ecx, edi
// 00423fa1  e89a2c1900           call 0x5b6c40
// 00423fa6  8b4604               mov eax, dword ptr [esi + 4]
// 00423fa9  885814               mov byte ptr [eax + 0x14], bl
// 00423fac  8b4e04               mov ecx, dword ptr [esi + 4]
// 00423faf  8b5104               mov edx, dword ptr [ecx + 4]
// 00423fb2  c6421400             mov byte ptr [edx + 0x14], 0
// 00423fb6  8b4604               mov eax, dword ptr [esi + 4]
// 00423fb9  8b4004               mov eax, dword ptr [eax + 4]
// 00423fbc  8b4808               mov ecx, dword ptr [eax + 8]
// 00423fbf  8b11                 mov edx, dword ptr [ecx]
// 00423fc1  895008               mov dword ptr [eax + 8], edx
// 00423fc4  8b11                 mov edx, dword ptr [ecx]
// 00423fc6  807a1500             cmp byte ptr [edx + 0x15], 0
// 00423fca  7503                 jne 0x423fcf
// 00423fcc  894204               mov dword ptr [edx + 4], eax
// 00423fcf  8b5004               mov edx, dword ptr [eax + 4]
// 00423fd2  895104               mov dword ptr [ecx + 4], edx
// 00423fd5  8b5718               mov edx, dword ptr [edi + 0x18]
// 00423fd8  3b4204               cmp eax, dword ptr [edx + 4]
// 00423fdb  7505                 jne 0x423fe2
// 00423fdd  894a04               mov dword ptr [edx + 4], ecx
// 00423fe0  eb0e                 jmp 0x423ff0
// 00423fe2  8b5004               mov edx, dword ptr [eax + 4]
// 00423fe5  3b02                 cmp eax, dword ptr [edx]
// 00423fe7  7504                 jne 0x423fed
// 00423fe9  890a                 mov dword ptr [edx], ecx
// 00423feb  eb03                 jmp 0x423ff0
// 00423fed  894a08               mov dword ptr [edx + 8], ecx
// 00423ff0  8901                 mov dword ptr [ecx], eax
// 00423ff2  894804               mov dword ptr [eax + 4], ecx
// 00423ff5  8b4e04               mov ecx, dword ptr [esi + 4]
// 00423ff8  80791400             cmp byte ptr [ecx + 0x14], 0
// 00423ffc  8d4604               lea eax, [esi + 4]
// 00423fff  0f841bffffff         je 0x423f20
// 00424005  8b5718               mov edx, dword ptr [edi + 0x18]
// 00424008  8b4204               mov eax, dword ptr [edx + 4]
// 0042400b  885814               mov byte ptr [eax + 0x14], bl
// 0042400e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00424012  8b0f                 mov ecx, dword ptr [edi]
// 00424014  5e                   pop esi
// 00424015  896804               mov dword ptr [eax + 4], ebp
// 00424018  5d                   pop ebp
// 00424019  8908                 mov dword ptr [eax], ecx
// 0042401b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0042401f  5b                   pop ebx
// 00424020  5f                   pop edi
// 00424021  64890d00000000       mov dword ptr fs:[0], ecx
// 00424028  83c450               add esp, 0x50
// 0042402b  c21000               ret 0x10
// standard library map_int<ptr> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
