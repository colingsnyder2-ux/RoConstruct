// from server: 100% by auto
// roc 2008-06 004a88e0  unit: RBX::VHint::?$FactoryProduct::Creator  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a88e0
//
// 004a88e0  64a100000000         mov eax, dword ptr fs:[0]
// 004a88e6  6aff                 push -1
// 004a88e8  6842e87d00           push 0x7de842
// 004a88ed  50                   push eax
// 004a88ee  64892500000000       mov dword ptr fs:[0], esp
// 004a88f5  83ec44               sub esp, 0x44
// 004a88f8  57                   push edi
// 004a88f9  8bf9                 mov edi, ecx
// 004a88fb  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 004a8902  7259                 jb 0x4a895d
// 004a8904  688cb28000           push 0x80b28c
// 004a8909  8d4c2408             lea ecx, [esp + 8]
// 004a890d  ff1558248000         call dword ptr [0x802458]
// 004a8913  8d4c2420             lea ecx, [esp + 0x20]
// 004a8917  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004a891f  ff1598288000         call dword ptr [0x802898]
// 004a8925  8d442404             lea eax, [esp + 4]
// 004a8929  50                   push eax
// 004a892a  8d4c2430             lea ecx, [esp + 0x30]
// 004a892e  c644245401           mov byte ptr [esp + 0x54], 1
// 004a8933  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 004a893b  ff155c248000         call dword ptr [0x80245c]
// 004a8941  68c00c8d00           push 0x8d0cc0
// 004a8946  8d4c2424             lea ecx, [esp + 0x24]
// 004a894a  51                   push ecx
// 004a894b  c644245800           mov byte ptr [esp + 0x58], 0
// 004a8950  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 004a8958  e82f8c1f00           call 0x6a158c
// 004a895d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004a8961  8b4718               mov eax, dword ptr [edi + 0x18]
// 004a8964  53                   push ebx
// 004a8965  55                   push ebp
// 004a8966  56                   push esi
// 004a8967  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004a896b  6a00                 push 0
// 004a896d  52                   push edx
// 004a896e  50                   push eax
// 004a896f  56                   push esi
// 004a8970  50                   push eax
// 004a8971  e8bafeffff           call 0x4a8830
// 004a8976  8be8                 mov ebp, eax
// 004a8978  8b4718               mov eax, dword ptr [edi + 0x18]
// 004a897b  bb01000000           mov ebx, 1
// 004a8980  015f1c               add dword ptr [edi + 0x1c], ebx
// 004a8983  3bf0                 cmp esi, eax
// 004a8985  7510                 jne 0x4a8997
// 004a8987  896804               mov dword ptr [eax + 4], ebp
// 004a898a  8b4718               mov eax, dword ptr [edi + 0x18]
// 004a898d  8928                 mov dword ptr [eax], ebp
// 004a898f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004a8992  896908               mov dword ptr [ecx + 8], ebp
// 004a8995  eb22                 jmp 0x4a89b9
// 004a8997  807c246800           cmp byte ptr [esp + 0x68], 0
// 004a899c  740d                 je 0x4a89ab
// 004a899e  892e                 mov dword ptr [esi], ebp
// 004a89a0  8b4718               mov eax, dword ptr [edi + 0x18]
// 004a89a3  3b30                 cmp esi, dword ptr [eax]
// 004a89a5  7512                 jne 0x4a89b9
// 004a89a7  8928                 mov dword ptr [eax], ebp
// 004a89a9  eb0e                 jmp 0x4a89b9
// 004a89ab  896e08               mov dword ptr [esi + 8], ebp
// 004a89ae  8b4718               mov eax, dword ptr [edi + 0x18]
// 004a89b1  3b7008               cmp esi, dword ptr [eax + 8]
// 004a89b4  7503                 jne 0x4a89b9
// 004a89b6  896808               mov dword ptr [eax + 8], ebp
// 004a89b9  8b5504               mov edx, dword ptr [ebp + 4]
// 004a89bc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004a89c0  8d4504               lea eax, [ebp + 4]
// 004a89c3  8bf5                 mov esi, ebp
// 004a89c5  0f85ea000000         jne 0x4a8ab5
// 004a89cb  eb03                 jmp 0x4a89d0
// 004a89cd  8d4900               lea ecx, [ecx]
// 004a89d0  8b08                 mov ecx, dword ptr [eax]
// 004a89d2  8b5104               mov edx, dword ptr [ecx + 4]
// 004a89d5  3b0a                 cmp ecx, dword ptr [edx]
// 004a89d7  7551                 jne 0x4a8a2a
// 004a89d9  8b5208               mov edx, dword ptr [edx + 8]
// 004a89dc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004a89e0  7519                 jne 0x4a89fb
// 004a89e2  88592c               mov byte ptr [ecx + 0x2c], bl
// 004a89e5  885a2c               mov byte ptr [edx + 0x2c], bl
// 004a89e8  8b10                 mov edx, dword ptr [eax]
// 004a89ea  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a89ed  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004a89f1  8b10                 mov edx, dword ptr [eax]
// 004a89f3  8b7204               mov esi, dword ptr [edx + 4]
// 004a89f6  e9aa000000           jmp 0x4a8aa5
// 004a89fb  3b7108               cmp esi, dword ptr [ecx + 8]
// 004a89fe  750a                 jne 0x4a8a0a
// 004a8a00  8bf1                 mov esi, ecx
// 004a8a02  56                   push esi
// 004a8a03  8bcf                 mov ecx, edi
// 004a8a05  e8f6541e00           call 0x68df00
// 004a8a0a  8b4604               mov eax, dword ptr [esi + 4]
// 004a8a0d  88582c               mov byte ptr [eax + 0x2c], bl
// 004a8a10  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a8a13  8b5104               mov edx, dword ptr [ecx + 4]
// 004a8a16  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004a8a1a  8b4604               mov eax, dword ptr [esi + 4]
// 004a8a1d  8b4804               mov ecx, dword ptr [eax + 4]
// 004a8a20  51                   push ecx
// 004a8a21  8bcf                 mov ecx, edi
// 004a8a23  e8a8451e00           call 0x68cfd0
// 004a8a28  eb7b                 jmp 0x4a8aa5
// 004a8a2a  8b12                 mov edx, dword ptr [edx]
// 004a8a2c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004a8a30  7516                 jne 0x4a8a48
// 004a8a32  88592c               mov byte ptr [ecx + 0x2c], bl
// 004a8a35  885a2c               mov byte ptr [edx + 0x2c], bl
// 004a8a38  8b10                 mov edx, dword ptr [eax]
// 004a8a3a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a8a3d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004a8a41  8b10                 mov edx, dword ptr [eax]
// 004a8a43  8b7204               mov esi, dword ptr [edx + 4]
// 004a8a46  eb5d                 jmp 0x4a8aa5
// 004a8a48  3b31                 cmp esi, dword ptr [ecx]
// 004a8a4a  750a                 jne 0x4a8a56
// 004a8a4c  8bf1                 mov esi, ecx
// 004a8a4e  56                   push esi
// 004a8a4f  8bcf                 mov ecx, edi
// 004a8a51  e87a451e00           call 0x68cfd0
// 004a8a56  8b4604               mov eax, dword ptr [esi + 4]
// 004a8a59  88582c               mov byte ptr [eax + 0x2c], bl
// 004a8a5c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a8a5f  8b5104               mov edx, dword ptr [ecx + 4]
// 004a8a62  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004a8a66  8b4604               mov eax, dword ptr [esi + 4]
// 004a8a69  8b4004               mov eax, dword ptr [eax + 4]
// 004a8a6c  8b4808               mov ecx, dword ptr [eax + 8]
// 004a8a6f  8b11                 mov edx, dword ptr [ecx]
// 004a8a71  895008               mov dword ptr [eax + 8], edx
// 004a8a74  8b11                 mov edx, dword ptr [ecx]
// 004a8a76  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 004a8a7a  7503                 jne 0x4a8a7f
// 004a8a7c  894204               mov dword ptr [edx + 4], eax
// 004a8a7f  8b5004               mov edx, dword ptr [eax + 4]
// 004a8a82  895104               mov dword ptr [ecx + 4], edx
// 004a8a85  8b5718               mov edx, dword ptr [edi + 0x18]
// 004a8a88  3b4204               cmp eax, dword ptr [edx + 4]
// 004a8a8b  7505                 jne 0x4a8a92
// 004a8a8d  894a04               mov dword ptr [edx + 4], ecx
// 004a8a90  eb0e                 jmp 0x4a8aa0
// 004a8a92  8b5004               mov edx, dword ptr [eax + 4]
// 004a8a95  3b02                 cmp eax, dword ptr [edx]
// 004a8a97  7504                 jne 0x4a8a9d
// 004a8a99  890a                 mov dword ptr [edx], ecx
// 004a8a9b  eb03                 jmp 0x4a8aa0
// 004a8a9d  894a08               mov dword ptr [edx + 8], ecx
// 004a8aa0  8901                 mov dword ptr [ecx], eax
// 004a8aa2  894804               mov dword ptr [eax + 4], ecx
// 004a8aa5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a8aa8  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 004a8aac  8d4604               lea eax, [esi + 4]
// 004a8aaf  0f841bffffff         je 0x4a89d0
// 004a8ab5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004a8ab8  8b4204               mov eax, dword ptr [edx + 4]
// 004a8abb  88582c               mov byte ptr [eax + 0x2c], bl
// 004a8abe  8b442464             mov eax, dword ptr [esp + 0x64]
// 004a8ac2  8b0f                 mov ecx, dword ptr [edi]
// 004a8ac4  5e                   pop esi
// 004a8ac5  896804               mov dword ptr [eax + 4], ebp
// 004a8ac8  5d                   pop ebp
// 004a8ac9  8908                 mov dword ptr [eax], ecx
// 004a8acb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004a8acf  5b                   pop ebx
// 004a8ad0  5f                   pop edi
// 004a8ad1  64890d00000000       mov dword ptr fs:[0], ecx
// 004a8ad8  83c450               add esp, 0x50
// 004a8adb  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
