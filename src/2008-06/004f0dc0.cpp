// from server: 100% by auto
// roc 2008-06 004f0dc0  unit: RBX::RenderBase::VMaterialBase::?$WeakReferenceCountedPointer  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004f0dc0
//
// 004f0dc0  64a100000000         mov eax, dword ptr fs:[0]
// 004f0dc6  6aff                 push -1
// 004f0dc8  6842e87d00           push 0x7de842
// 004f0dcd  50                   push eax
// 004f0dce  64892500000000       mov dword ptr fs:[0], esp
// 004f0dd5  83ec44               sub esp, 0x44
// 004f0dd8  57                   push edi
// 004f0dd9  8bf9                 mov edi, ecx
// 004f0ddb  817f1ccbcccc0c       cmp dword ptr [edi + 0x1c], 0xccccccb
// 004f0de2  7259                 jb 0x4f0e3d
// 004f0de4  688cb28000           push 0x80b28c
// 004f0de9  8d4c2408             lea ecx, [esp + 8]
// 004f0ded  ff1558248000         call dword ptr [0x802458]
// 004f0df3  8d4c2420             lea ecx, [esp + 0x20]
// 004f0df7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004f0dff  ff1598288000         call dword ptr [0x802898]
// 004f0e05  8d442404             lea eax, [esp + 4]
// 004f0e09  50                   push eax
// 004f0e0a  8d4c2430             lea ecx, [esp + 0x30]
// 004f0e0e  c644245401           mov byte ptr [esp + 0x54], 1
// 004f0e13  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 004f0e1b  ff155c248000         call dword ptr [0x80245c]
// 004f0e21  68c00c8d00           push 0x8d0cc0
// 004f0e26  8d4c2424             lea ecx, [esp + 0x24]
// 004f0e2a  51                   push ecx
// 004f0e2b  c644245800           mov byte ptr [esp + 0x58], 0
// 004f0e30  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 004f0e38  e84f071b00           call 0x6a158c
// 004f0e3d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004f0e41  8b4718               mov eax, dword ptr [edi + 0x18]
// 004f0e44  53                   push ebx
// 004f0e45  55                   push ebp
// 004f0e46  56                   push esi
// 004f0e47  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004f0e4b  6a00                 push 0
// 004f0e4d  52                   push edx
// 004f0e4e  50                   push eax
// 004f0e4f  56                   push esi
// 004f0e50  50                   push eax
// 004f0e51  e83afeffff           call 0x4f0c90
// 004f0e56  8be8                 mov ebp, eax
// 004f0e58  8b4718               mov eax, dword ptr [edi + 0x18]
// 004f0e5b  bb01000000           mov ebx, 1
// 004f0e60  015f1c               add dword ptr [edi + 0x1c], ebx
// 004f0e63  3bf0                 cmp esi, eax
// 004f0e65  7510                 jne 0x4f0e77
// 004f0e67  896804               mov dword ptr [eax + 4], ebp
// 004f0e6a  8b4718               mov eax, dword ptr [edi + 0x18]
// 004f0e6d  8928                 mov dword ptr [eax], ebp
// 004f0e6f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004f0e72  896908               mov dword ptr [ecx + 8], ebp
// 004f0e75  eb22                 jmp 0x4f0e99
// 004f0e77  807c246800           cmp byte ptr [esp + 0x68], 0
// 004f0e7c  740d                 je 0x4f0e8b
// 004f0e7e  892e                 mov dword ptr [esi], ebp
// 004f0e80  8b4718               mov eax, dword ptr [edi + 0x18]
// 004f0e83  3b30                 cmp esi, dword ptr [eax]
// 004f0e85  7512                 jne 0x4f0e99
// 004f0e87  8928                 mov dword ptr [eax], ebp
// 004f0e89  eb0e                 jmp 0x4f0e99
// 004f0e8b  896e08               mov dword ptr [esi + 8], ebp
// 004f0e8e  8b4718               mov eax, dword ptr [edi + 0x18]
// 004f0e91  3b7008               cmp esi, dword ptr [eax + 8]
// 004f0e94  7503                 jne 0x4f0e99
// 004f0e96  896808               mov dword ptr [eax + 8], ebp
// 004f0e99  8b5504               mov edx, dword ptr [ebp + 4]
// 004f0e9c  807a2000             cmp byte ptr [edx + 0x20], 0
// 004f0ea0  8d4504               lea eax, [ebp + 4]
// 004f0ea3  8bf5                 mov esi, ebp
// 004f0ea5  0f85ea000000         jne 0x4f0f95
// 004f0eab  eb03                 jmp 0x4f0eb0
// 004f0ead  8d4900               lea ecx, [ecx]
// 004f0eb0  8b08                 mov ecx, dword ptr [eax]
// 004f0eb2  8b5104               mov edx, dword ptr [ecx + 4]
// 004f0eb5  3b0a                 cmp ecx, dword ptr [edx]
// 004f0eb7  7551                 jne 0x4f0f0a
// 004f0eb9  8b5208               mov edx, dword ptr [edx + 8]
// 004f0ebc  807a2000             cmp byte ptr [edx + 0x20], 0
// 004f0ec0  7519                 jne 0x4f0edb
// 004f0ec2  885920               mov byte ptr [ecx + 0x20], bl
// 004f0ec5  885a20               mov byte ptr [edx + 0x20], bl
// 004f0ec8  8b10                 mov edx, dword ptr [eax]
// 004f0eca  8b4a04               mov ecx, dword ptr [edx + 4]
// 004f0ecd  c6412000             mov byte ptr [ecx + 0x20], 0
// 004f0ed1  8b10                 mov edx, dword ptr [eax]
// 004f0ed3  8b7204               mov esi, dword ptr [edx + 4]
// 004f0ed6  e9aa000000           jmp 0x4f0f85
// 004f0edb  3b7108               cmp esi, dword ptr [ecx + 8]
// 004f0ede  750a                 jne 0x4f0eea
// 004f0ee0  8bf1                 mov esi, ecx
// 004f0ee2  56                   push esi
// 004f0ee3  8bcf                 mov ecx, edi
// 004f0ee5  e80667feff           call 0x4d75f0
// 004f0eea  8b4604               mov eax, dword ptr [esi + 4]
// 004f0eed  885820               mov byte ptr [eax + 0x20], bl
// 004f0ef0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004f0ef3  8b5104               mov edx, dword ptr [ecx + 4]
// 004f0ef6  c6422000             mov byte ptr [edx + 0x20], 0
// 004f0efa  8b4604               mov eax, dword ptr [esi + 4]
// 004f0efd  8b4804               mov ecx, dword ptr [eax + 4]
// 004f0f00  51                   push ecx
// 004f0f01  8bcf                 mov ecx, edi
// 004f0f03  e8b81f0c00           call 0x5b2ec0
// 004f0f08  eb7b                 jmp 0x4f0f85
// 004f0f0a  8b12                 mov edx, dword ptr [edx]
// 004f0f0c  807a2000             cmp byte ptr [edx + 0x20], 0
// 004f0f10  7516                 jne 0x4f0f28
// 004f0f12  885920               mov byte ptr [ecx + 0x20], bl
// 004f0f15  885a20               mov byte ptr [edx + 0x20], bl
// 004f0f18  8b10                 mov edx, dword ptr [eax]
// 004f0f1a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004f0f1d  c6412000             mov byte ptr [ecx + 0x20], 0
// 004f0f21  8b10                 mov edx, dword ptr [eax]
// 004f0f23  8b7204               mov esi, dword ptr [edx + 4]
// 004f0f26  eb5d                 jmp 0x4f0f85
// 004f0f28  3b31                 cmp esi, dword ptr [ecx]
// 004f0f2a  750a                 jne 0x4f0f36
// 004f0f2c  8bf1                 mov esi, ecx
// 004f0f2e  56                   push esi
// 004f0f2f  8bcf                 mov ecx, edi
// 004f0f31  e88a1f0c00           call 0x5b2ec0
// 004f0f36  8b4604               mov eax, dword ptr [esi + 4]
// 004f0f39  885820               mov byte ptr [eax + 0x20], bl
// 004f0f3c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004f0f3f  8b5104               mov edx, dword ptr [ecx + 4]
// 004f0f42  c6422000             mov byte ptr [edx + 0x20], 0
// 004f0f46  8b4604               mov eax, dword ptr [esi + 4]
// 004f0f49  8b4004               mov eax, dword ptr [eax + 4]
// 004f0f4c  8b4808               mov ecx, dword ptr [eax + 8]
// 004f0f4f  8b11                 mov edx, dword ptr [ecx]
// 004f0f51  895008               mov dword ptr [eax + 8], edx
// 004f0f54  8b11                 mov edx, dword ptr [ecx]
// 004f0f56  807a2100             cmp byte ptr [edx + 0x21], 0
// 004f0f5a  7503                 jne 0x4f0f5f
// 004f0f5c  894204               mov dword ptr [edx + 4], eax
// 004f0f5f  8b5004               mov edx, dword ptr [eax + 4]
// 004f0f62  895104               mov dword ptr [ecx + 4], edx
// 004f0f65  8b5718               mov edx, dword ptr [edi + 0x18]
// 004f0f68  3b4204               cmp eax, dword ptr [edx + 4]
// 004f0f6b  7505                 jne 0x4f0f72
// 004f0f6d  894a04               mov dword ptr [edx + 4], ecx
// 004f0f70  eb0e                 jmp 0x4f0f80
// 004f0f72  8b5004               mov edx, dword ptr [eax + 4]
// 004f0f75  3b02                 cmp eax, dword ptr [edx]
// 004f0f77  7504                 jne 0x4f0f7d
// 004f0f79  890a                 mov dword ptr [edx], ecx
// 004f0f7b  eb03                 jmp 0x4f0f80
// 004f0f7d  894a08               mov dword ptr [edx + 8], ecx
// 004f0f80  8901                 mov dword ptr [ecx], eax
// 004f0f82  894804               mov dword ptr [eax + 4], ecx
// 004f0f85  8b4e04               mov ecx, dword ptr [esi + 4]
// 004f0f88  80792000             cmp byte ptr [ecx + 0x20], 0
// 004f0f8c  8d4604               lea eax, [esi + 4]
// 004f0f8f  0f841bffffff         je 0x4f0eb0
// 004f0f95  8b5718               mov edx, dword ptr [edi + 0x18]
// 004f0f98  8b4204               mov eax, dword ptr [edx + 4]
// 004f0f9b  885820               mov byte ptr [eax + 0x20], bl
// 004f0f9e  8b442464             mov eax, dword ptr [esp + 0x64]
// 004f0fa2  8b0f                 mov ecx, dword ptr [edi]
// 004f0fa4  5e                   pop esi
// 004f0fa5  896804               mov dword ptr [eax + 4], ebp
// 004f0fa8  5d                   pop ebp
// 004f0fa9  8908                 mov dword ptr [eax], ecx
// 004f0fab  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004f0faf  5b                   pop ebx
// 004f0fb0  5f                   pop edi
// 004f0fb1  64890d00000000       mov dword ptr fs:[0], ecx
// 004f0fb8  83c450               add esp, 0x50
// 004f0fbb  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
