// from server: 100% by auto
// roc 2008-06 00651b40  unit: RBX::ScoreHud  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00651b40
//
// 00651b40  64a100000000         mov eax, dword ptr fs:[0]
// 00651b46  6aff                 push -1
// 00651b48  6842e87d00           push 0x7de842
// 00651b4d  50                   push eax
// 00651b4e  64892500000000       mov dword ptr fs:[0], esp
// 00651b55  83ec44               sub esp, 0x44
// 00651b58  57                   push edi
// 00651b59  8bf9                 mov edi, ecx
// 00651b5b  817f1c48922409       cmp dword ptr [edi + 0x1c], 0x9249248
// 00651b62  7259                 jb 0x651bbd
// 00651b64  688cb28000           push 0x80b28c
// 00651b69  8d4c2408             lea ecx, [esp + 8]
// 00651b6d  ff1558248000         call dword ptr [0x802458]
// 00651b73  8d4c2420             lea ecx, [esp + 0x20]
// 00651b77  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00651b7f  ff1598288000         call dword ptr [0x802898]
// 00651b85  8d442404             lea eax, [esp + 4]
// 00651b89  50                   push eax
// 00651b8a  8d4c2430             lea ecx, [esp + 0x30]
// 00651b8e  c644245401           mov byte ptr [esp + 0x54], 1
// 00651b93  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 00651b9b  ff155c248000         call dword ptr [0x80245c]
// 00651ba1  68c00c8d00           push 0x8d0cc0
// 00651ba6  8d4c2424             lea ecx, [esp + 0x24]
// 00651baa  51                   push ecx
// 00651bab  c644245800           mov byte ptr [esp + 0x58], 0
// 00651bb0  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 00651bb8  e8cff90400           call 0x6a158c
// 00651bbd  8b542464             mov edx, dword ptr [esp + 0x64]
// 00651bc1  8b4718               mov eax, dword ptr [edi + 0x18]
// 00651bc4  53                   push ebx
// 00651bc5  55                   push ebp
// 00651bc6  56                   push esi
// 00651bc7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00651bcb  6a00                 push 0
// 00651bcd  52                   push edx
// 00651bce  50                   push eax
// 00651bcf  56                   push esi
// 00651bd0  50                   push eax
// 00651bd1  e85afbffff           call 0x651730
// 00651bd6  8be8                 mov ebp, eax
// 00651bd8  8b4718               mov eax, dword ptr [edi + 0x18]
// 00651bdb  bb01000000           mov ebx, 1
// 00651be0  015f1c               add dword ptr [edi + 0x1c], ebx
// 00651be3  3bf0                 cmp esi, eax
// 00651be5  7510                 jne 0x651bf7
// 00651be7  896804               mov dword ptr [eax + 4], ebp
// 00651bea  8b4718               mov eax, dword ptr [edi + 0x18]
// 00651bed  8928                 mov dword ptr [eax], ebp
// 00651bef  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00651bf2  896908               mov dword ptr [ecx + 8], ebp
// 00651bf5  eb22                 jmp 0x651c19
// 00651bf7  807c246800           cmp byte ptr [esp + 0x68], 0
// 00651bfc  740d                 je 0x651c0b
// 00651bfe  892e                 mov dword ptr [esi], ebp
// 00651c00  8b4718               mov eax, dword ptr [edi + 0x18]
// 00651c03  3b30                 cmp esi, dword ptr [eax]
// 00651c05  7512                 jne 0x651c19
// 00651c07  8928                 mov dword ptr [eax], ebp
// 00651c09  eb0e                 jmp 0x651c19
// 00651c0b  896e08               mov dword ptr [esi + 8], ebp
// 00651c0e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00651c11  3b7008               cmp esi, dword ptr [eax + 8]
// 00651c14  7503                 jne 0x651c19
// 00651c16  896808               mov dword ptr [eax + 8], ebp
// 00651c19  8b5504               mov edx, dword ptr [ebp + 4]
// 00651c1c  807a2800             cmp byte ptr [edx + 0x28], 0
// 00651c20  8d4504               lea eax, [ebp + 4]
// 00651c23  8bf5                 mov esi, ebp
// 00651c25  0f85ea000000         jne 0x651d15
// 00651c2b  eb03                 jmp 0x651c30
// 00651c2d  8d4900               lea ecx, [ecx]
// 00651c30  8b08                 mov ecx, dword ptr [eax]
// 00651c32  8b5104               mov edx, dword ptr [ecx + 4]
// 00651c35  3b0a                 cmp ecx, dword ptr [edx]
// 00651c37  7551                 jne 0x651c8a
// 00651c39  8b5208               mov edx, dword ptr [edx + 8]
// 00651c3c  807a2800             cmp byte ptr [edx + 0x28], 0
// 00651c40  7519                 jne 0x651c5b
// 00651c42  885928               mov byte ptr [ecx + 0x28], bl
// 00651c45  885a28               mov byte ptr [edx + 0x28], bl
// 00651c48  8b10                 mov edx, dword ptr [eax]
// 00651c4a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00651c4d  c6412800             mov byte ptr [ecx + 0x28], 0
// 00651c51  8b10                 mov edx, dword ptr [eax]
// 00651c53  8b7204               mov esi, dword ptr [edx + 4]
// 00651c56  e9aa000000           jmp 0x651d05
// 00651c5b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00651c5e  750a                 jne 0x651c6a
// 00651c60  8bf1                 mov esi, ecx
// 00651c62  56                   push esi
// 00651c63  8bcf                 mov ecx, edi
// 00651c65  e83659e8ff           call 0x4d75a0
// 00651c6a  8b4604               mov eax, dword ptr [esi + 4]
// 00651c6d  885828               mov byte ptr [eax + 0x28], bl
// 00651c70  8b4e04               mov ecx, dword ptr [esi + 4]
// 00651c73  8b5104               mov edx, dword ptr [ecx + 4]
// 00651c76  c6422800             mov byte ptr [edx + 0x28], 0
// 00651c7a  8b4604               mov eax, dword ptr [esi + 4]
// 00651c7d  8b4804               mov ecx, dword ptr [eax + 4]
// 00651c80  51                   push ecx
// 00651c81  8bcf                 mov ecx, edi
// 00651c83  e808fee4ff           call 0x4a1a90
// 00651c88  eb7b                 jmp 0x651d05
// 00651c8a  8b12                 mov edx, dword ptr [edx]
// 00651c8c  807a2800             cmp byte ptr [edx + 0x28], 0
// 00651c90  7516                 jne 0x651ca8
// 00651c92  885928               mov byte ptr [ecx + 0x28], bl
// 00651c95  885a28               mov byte ptr [edx + 0x28], bl
// 00651c98  8b10                 mov edx, dword ptr [eax]
// 00651c9a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00651c9d  c6412800             mov byte ptr [ecx + 0x28], 0
// 00651ca1  8b10                 mov edx, dword ptr [eax]
// 00651ca3  8b7204               mov esi, dword ptr [edx + 4]
// 00651ca6  eb5d                 jmp 0x651d05
// 00651ca8  3b31                 cmp esi, dword ptr [ecx]
// 00651caa  750a                 jne 0x651cb6
// 00651cac  8bf1                 mov esi, ecx
// 00651cae  56                   push esi
// 00651caf  8bcf                 mov ecx, edi
// 00651cb1  e8dafde4ff           call 0x4a1a90
// 00651cb6  8b4604               mov eax, dword ptr [esi + 4]
// 00651cb9  885828               mov byte ptr [eax + 0x28], bl
// 00651cbc  8b4e04               mov ecx, dword ptr [esi + 4]
// 00651cbf  8b5104               mov edx, dword ptr [ecx + 4]
// 00651cc2  c6422800             mov byte ptr [edx + 0x28], 0
// 00651cc6  8b4604               mov eax, dword ptr [esi + 4]
// 00651cc9  8b4004               mov eax, dword ptr [eax + 4]
// 00651ccc  8b4808               mov ecx, dword ptr [eax + 8]
// 00651ccf  8b11                 mov edx, dword ptr [ecx]
// 00651cd1  895008               mov dword ptr [eax + 8], edx
// 00651cd4  8b11                 mov edx, dword ptr [ecx]
// 00651cd6  807a2900             cmp byte ptr [edx + 0x29], 0
// 00651cda  7503                 jne 0x651cdf
// 00651cdc  894204               mov dword ptr [edx + 4], eax
// 00651cdf  8b5004               mov edx, dword ptr [eax + 4]
// 00651ce2  895104               mov dword ptr [ecx + 4], edx
// 00651ce5  8b5718               mov edx, dword ptr [edi + 0x18]
// 00651ce8  3b4204               cmp eax, dword ptr [edx + 4]
// 00651ceb  7505                 jne 0x651cf2
// 00651ced  894a04               mov dword ptr [edx + 4], ecx
// 00651cf0  eb0e                 jmp 0x651d00
// 00651cf2  8b5004               mov edx, dword ptr [eax + 4]
// 00651cf5  3b02                 cmp eax, dword ptr [edx]
// 00651cf7  7504                 jne 0x651cfd
// 00651cf9  890a                 mov dword ptr [edx], ecx
// 00651cfb  eb03                 jmp 0x651d00
// 00651cfd  894a08               mov dword ptr [edx + 8], ecx
// 00651d00  8901                 mov dword ptr [ecx], eax
// 00651d02  894804               mov dword ptr [eax + 4], ecx
// 00651d05  8b4e04               mov ecx, dword ptr [esi + 4]
// 00651d08  80792800             cmp byte ptr [ecx + 0x28], 0
// 00651d0c  8d4604               lea eax, [esi + 4]
// 00651d0f  0f841bffffff         je 0x651c30
// 00651d15  8b5718               mov edx, dword ptr [edi + 0x18]
// 00651d18  8b4204               mov eax, dword ptr [edx + 4]
// 00651d1b  885828               mov byte ptr [eax + 0x28], bl
// 00651d1e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00651d22  8b0f                 mov ecx, dword ptr [edi]
// 00651d24  5e                   pop esi
// 00651d25  896804               mov dword ptr [eax + 4], ebp
// 00651d28  5d                   pop ebp
// 00651d29  8908                 mov dword ptr [eax], ecx
// 00651d2b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00651d2f  5b                   pop ebx
// 00651d30  5f                   pop edi
// 00651d31  64890d00000000       mov dword ptr fs:[0], ecx
// 00651d38  83c450               add esp, 0x50
// 00651d3b  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
