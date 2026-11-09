// from server: 100% by auto
// roc 2009-06 00519a40  unit: G3D::VVector3::?$Table  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00519a40
//
// 00519a40  64a100000000         mov eax, dword ptr fs:[0]
// 00519a46  6aff                 push -1
// 00519a48  68b2db8500           push 0x85dbb2
// 00519a4d  50                   push eax
// 00519a4e  64892500000000       mov dword ptr fs:[0], esp
// 00519a55  83ec44               sub esp, 0x44
// 00519a58  57                   push edi
// 00519a59  8bf9                 mov edi, ecx
// 00519a5b  817f1c48922409       cmp dword ptr [edi + 0x1c], 0x9249248
// 00519a62  7259                 jb 0x519abd
// 00519a64  68c0c98a00           push 0x8ac9c0
// 00519a69  8d4c2408             lea ecx, [esp + 8]
// 00519a6d  ff15b4e48900         call dword ptr [0x89e4b4]
// 00519a73  8d4c2420             lea ecx, [esp + 0x20]
// 00519a77  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00519a7f  ff15b8e98900         call dword ptr [0x89e9b8]
// 00519a85  8d442404             lea eax, [esp + 4]
// 00519a89  50                   push eax
// 00519a8a  8d4c2430             lea ecx, [esp + 0x30]
// 00519a8e  c644245401           mov byte ptr [esp + 0x54], 1
// 00519a93  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 00519a9b  ff15b8e48900         call dword ptr [0x89e4b8]
// 00519aa1  6834929700           push 0x979234
// 00519aa6  8d4c2424             lea ecx, [esp + 0x24]
// 00519aaa  51                   push ecx
// 00519aab  c644245800           mov byte ptr [esp + 0x58], 0
// 00519ab0  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 00519ab8  e88dff1f00           call 0x719a4a
// 00519abd  8b542464             mov edx, dword ptr [esp + 0x64]
// 00519ac1  8b4718               mov eax, dword ptr [edi + 0x18]
// 00519ac4  53                   push ebx
// 00519ac5  55                   push ebp
// 00519ac6  56                   push esi
// 00519ac7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00519acb  6a00                 push 0
// 00519acd  52                   push edx
// 00519ace  50                   push eax
// 00519acf  56                   push esi
// 00519ad0  50                   push eax
// 00519ad1  e82af7ffff           call 0x519200
// 00519ad6  8be8                 mov ebp, eax
// 00519ad8  8b4718               mov eax, dword ptr [edi + 0x18]
// 00519adb  bb01000000           mov ebx, 1
// 00519ae0  015f1c               add dword ptr [edi + 0x1c], ebx
// 00519ae3  3bf0                 cmp esi, eax
// 00519ae5  7510                 jne 0x519af7
// 00519ae7  896804               mov dword ptr [eax + 4], ebp
// 00519aea  8b4718               mov eax, dword ptr [edi + 0x18]
// 00519aed  8928                 mov dword ptr [eax], ebp
// 00519aef  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00519af2  896908               mov dword ptr [ecx + 8], ebp
// 00519af5  eb22                 jmp 0x519b19
// 00519af7  807c246800           cmp byte ptr [esp + 0x68], 0
// 00519afc  740d                 je 0x519b0b
// 00519afe  892e                 mov dword ptr [esi], ebp
// 00519b00  8b4718               mov eax, dword ptr [edi + 0x18]
// 00519b03  3b30                 cmp esi, dword ptr [eax]
// 00519b05  7512                 jne 0x519b19
// 00519b07  8928                 mov dword ptr [eax], ebp
// 00519b09  eb0e                 jmp 0x519b19
// 00519b0b  896e08               mov dword ptr [esi + 8], ebp
// 00519b0e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00519b11  3b7008               cmp esi, dword ptr [eax + 8]
// 00519b14  7503                 jne 0x519b19
// 00519b16  896808               mov dword ptr [eax + 8], ebp
// 00519b19  8b5504               mov edx, dword ptr [ebp + 4]
// 00519b1c  807a2800             cmp byte ptr [edx + 0x28], 0
// 00519b20  8d4504               lea eax, [ebp + 4]
// 00519b23  8bf5                 mov esi, ebp
// 00519b25  0f85ea000000         jne 0x519c15
// 00519b2b  eb03                 jmp 0x519b30
// 00519b2d  8d4900               lea ecx, [ecx]
// 00519b30  8b08                 mov ecx, dword ptr [eax]
// 00519b32  8b5104               mov edx, dword ptr [ecx + 4]
// 00519b35  3b0a                 cmp ecx, dword ptr [edx]
// 00519b37  7551                 jne 0x519b8a
// 00519b39  8b5208               mov edx, dword ptr [edx + 8]
// 00519b3c  807a2800             cmp byte ptr [edx + 0x28], 0
// 00519b40  7519                 jne 0x519b5b
// 00519b42  885928               mov byte ptr [ecx + 0x28], bl
// 00519b45  885a28               mov byte ptr [edx + 0x28], bl
// 00519b48  8b10                 mov edx, dword ptr [eax]
// 00519b4a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00519b4d  c6412800             mov byte ptr [ecx + 0x28], 0
// 00519b51  8b10                 mov edx, dword ptr [eax]
// 00519b53  8b7204               mov esi, dword ptr [edx + 4]
// 00519b56  e9aa000000           jmp 0x519c05
// 00519b5b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00519b5e  750a                 jne 0x519b6a
// 00519b60  8bf1                 mov esi, ecx
// 00519b62  56                   push esi
// 00519b63  8bcf                 mov ecx, edi
// 00519b65  e866861c00           call 0x6e21d0
// 00519b6a  8b4604               mov eax, dword ptr [esi + 4]
// 00519b6d  885828               mov byte ptr [eax + 0x28], bl
// 00519b70  8b4e04               mov ecx, dword ptr [esi + 4]
// 00519b73  8b5104               mov edx, dword ptr [ecx + 4]
// 00519b76  c6422800             mov byte ptr [edx + 0x28], 0
// 00519b7a  8b4604               mov eax, dword ptr [esi + 4]
// 00519b7d  8b4804               mov ecx, dword ptr [eax + 4]
// 00519b80  51                   push ecx
// 00519b81  8bcf                 mov ecx, edi
// 00519b83  e868ceffff           call 0x5169f0
// 00519b88  eb7b                 jmp 0x519c05
// 00519b8a  8b12                 mov edx, dword ptr [edx]
// 00519b8c  807a2800             cmp byte ptr [edx + 0x28], 0
// 00519b90  7516                 jne 0x519ba8
// 00519b92  885928               mov byte ptr [ecx + 0x28], bl
// 00519b95  885a28               mov byte ptr [edx + 0x28], bl
// 00519b98  8b10                 mov edx, dword ptr [eax]
// 00519b9a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00519b9d  c6412800             mov byte ptr [ecx + 0x28], 0
// 00519ba1  8b10                 mov edx, dword ptr [eax]
// 00519ba3  8b7204               mov esi, dword ptr [edx + 4]
// 00519ba6  eb5d                 jmp 0x519c05
// 00519ba8  3b31                 cmp esi, dword ptr [ecx]
// 00519baa  750a                 jne 0x519bb6
// 00519bac  8bf1                 mov esi, ecx
// 00519bae  56                   push esi
// 00519baf  8bcf                 mov ecx, edi
// 00519bb1  e83aceffff           call 0x5169f0
// 00519bb6  8b4604               mov eax, dword ptr [esi + 4]
// 00519bb9  885828               mov byte ptr [eax + 0x28], bl
// 00519bbc  8b4e04               mov ecx, dword ptr [esi + 4]
// 00519bbf  8b5104               mov edx, dword ptr [ecx + 4]
// 00519bc2  c6422800             mov byte ptr [edx + 0x28], 0
// 00519bc6  8b4604               mov eax, dword ptr [esi + 4]
// 00519bc9  8b4004               mov eax, dword ptr [eax + 4]
// 00519bcc  8b4808               mov ecx, dword ptr [eax + 8]
// 00519bcf  8b11                 mov edx, dword ptr [ecx]
// 00519bd1  895008               mov dword ptr [eax + 8], edx
// 00519bd4  8b11                 mov edx, dword ptr [ecx]
// 00519bd6  807a2900             cmp byte ptr [edx + 0x29], 0
// 00519bda  7503                 jne 0x519bdf
// 00519bdc  894204               mov dword ptr [edx + 4], eax
// 00519bdf  8b5004               mov edx, dword ptr [eax + 4]
// 00519be2  895104               mov dword ptr [ecx + 4], edx
// 00519be5  8b5718               mov edx, dword ptr [edi + 0x18]
// 00519be8  3b4204               cmp eax, dword ptr [edx + 4]
// 00519beb  7505                 jne 0x519bf2
// 00519bed  894a04               mov dword ptr [edx + 4], ecx
// 00519bf0  eb0e                 jmp 0x519c00
// 00519bf2  8b5004               mov edx, dword ptr [eax + 4]
// 00519bf5  3b02                 cmp eax, dword ptr [edx]
// 00519bf7  7504                 jne 0x519bfd
// 00519bf9  890a                 mov dword ptr [edx], ecx
// 00519bfb  eb03                 jmp 0x519c00
// 00519bfd  894a08               mov dword ptr [edx + 8], ecx
// 00519c00  8901                 mov dword ptr [ecx], eax
// 00519c02  894804               mov dword ptr [eax + 4], ecx
// 00519c05  8b4e04               mov ecx, dword ptr [esi + 4]
// 00519c08  80792800             cmp byte ptr [ecx + 0x28], 0
// 00519c0c  8d4604               lea eax, [esi + 4]
// 00519c0f  0f841bffffff         je 0x519b30
// 00519c15  8b5718               mov edx, dword ptr [edi + 0x18]
// 00519c18  8b4204               mov eax, dword ptr [edx + 4]
// 00519c1b  885828               mov byte ptr [eax + 0x28], bl
// 00519c1e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00519c22  8b0f                 mov ecx, dword ptr [edi]
// 00519c24  5e                   pop esi
// 00519c25  896804               mov dword ptr [eax + 4], ebp
// 00519c28  5d                   pop ebp
// 00519c29  8908                 mov dword ptr [eax], ecx
// 00519c2b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00519c2f  5b                   pop ebx
// 00519c30  5f                   pop edi
// 00519c31  64890d00000000       mov dword ptr fs:[0], ecx
// 00519c38  83c450               add esp, 0x50
// 00519c3b  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
