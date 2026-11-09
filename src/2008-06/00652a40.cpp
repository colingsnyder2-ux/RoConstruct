// from server: 100% by auto
// roc 2008-06 00652a40  unit: RBX::ScoreHud  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00652a40
//
// 00652a40  64a100000000         mov eax, dword ptr fs:[0]
// 00652a46  6aff                 push -1
// 00652a48  6842e87d00           push 0x7de842
// 00652a4d  50                   push eax
// 00652a4e  64892500000000       mov dword ptr fs:[0], esp
// 00652a55  83ec44               sub esp, 0x44
// 00652a58  57                   push edi
// 00652a59  8bf9                 mov edi, ecx
// 00652a5b  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 00652a62  7259                 jb 0x652abd
// 00652a64  688cb28000           push 0x80b28c
// 00652a69  8d4c2408             lea ecx, [esp + 8]
// 00652a6d  ff1558248000         call dword ptr [0x802458]
// 00652a73  8d4c2420             lea ecx, [esp + 0x20]
// 00652a77  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00652a7f  ff1598288000         call dword ptr [0x802898]
// 00652a85  8d442404             lea eax, [esp + 4]
// 00652a89  50                   push eax
// 00652a8a  8d4c2430             lea ecx, [esp + 0x30]
// 00652a8e  c644245401           mov byte ptr [esp + 0x54], 1
// 00652a93  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 00652a9b  ff155c248000         call dword ptr [0x80245c]
// 00652aa1  68c00c8d00           push 0x8d0cc0
// 00652aa6  8d4c2424             lea ecx, [esp + 0x24]
// 00652aaa  51                   push ecx
// 00652aab  c644245800           mov byte ptr [esp + 0x58], 0
// 00652ab0  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 00652ab8  e8cfea0400           call 0x6a158c
// 00652abd  8b542464             mov edx, dword ptr [esp + 0x64]
// 00652ac1  8b4718               mov eax, dword ptr [edi + 0x18]
// 00652ac4  53                   push ebx
// 00652ac5  55                   push ebp
// 00652ac6  56                   push esi
// 00652ac7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00652acb  6a00                 push 0
// 00652acd  52                   push edx
// 00652ace  50                   push eax
// 00652acf  56                   push esi
// 00652ad0  50                   push eax
// 00652ad1  e83af8ffff           call 0x652310
// 00652ad6  8be8                 mov ebp, eax
// 00652ad8  8b4718               mov eax, dword ptr [edi + 0x18]
// 00652adb  bb01000000           mov ebx, 1
// 00652ae0  015f1c               add dword ptr [edi + 0x1c], ebx
// 00652ae3  3bf0                 cmp esi, eax
// 00652ae5  7510                 jne 0x652af7
// 00652ae7  896804               mov dword ptr [eax + 4], ebp
// 00652aea  8b4718               mov eax, dword ptr [edi + 0x18]
// 00652aed  8928                 mov dword ptr [eax], ebp
// 00652aef  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00652af2  896908               mov dword ptr [ecx + 8], ebp
// 00652af5  eb22                 jmp 0x652b19
// 00652af7  807c246800           cmp byte ptr [esp + 0x68], 0
// 00652afc  740d                 je 0x652b0b
// 00652afe  892e                 mov dword ptr [esi], ebp
// 00652b00  8b4718               mov eax, dword ptr [edi + 0x18]
// 00652b03  3b30                 cmp esi, dword ptr [eax]
// 00652b05  7512                 jne 0x652b19
// 00652b07  8928                 mov dword ptr [eax], ebp
// 00652b09  eb0e                 jmp 0x652b19
// 00652b0b  896e08               mov dword ptr [esi + 8], ebp
// 00652b0e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00652b11  3b7008               cmp esi, dword ptr [eax + 8]
// 00652b14  7503                 jne 0x652b19
// 00652b16  896808               mov dword ptr [eax + 8], ebp
// 00652b19  8b5504               mov edx, dword ptr [ebp + 4]
// 00652b1c  807a3000             cmp byte ptr [edx + 0x30], 0
// 00652b20  8d4504               lea eax, [ebp + 4]
// 00652b23  8bf5                 mov esi, ebp
// 00652b25  0f85ea000000         jne 0x652c15
// 00652b2b  eb03                 jmp 0x652b30
// 00652b2d  8d4900               lea ecx, [ecx]
// 00652b30  8b08                 mov ecx, dword ptr [eax]
// 00652b32  8b5104               mov edx, dword ptr [ecx + 4]
// 00652b35  3b0a                 cmp ecx, dword ptr [edx]
// 00652b37  7551                 jne 0x652b8a
// 00652b39  8b5208               mov edx, dword ptr [edx + 8]
// 00652b3c  807a3000             cmp byte ptr [edx + 0x30], 0
// 00652b40  7519                 jne 0x652b5b
// 00652b42  885930               mov byte ptr [ecx + 0x30], bl
// 00652b45  885a30               mov byte ptr [edx + 0x30], bl
// 00652b48  8b10                 mov edx, dword ptr [eax]
// 00652b4a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00652b4d  c6413000             mov byte ptr [ecx + 0x30], 0
// 00652b51  8b10                 mov edx, dword ptr [eax]
// 00652b53  8b7204               mov esi, dword ptr [edx + 4]
// 00652b56  e9aa000000           jmp 0x652c05
// 00652b5b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00652b5e  750a                 jne 0x652b6a
// 00652b60  8bf1                 mov esi, ecx
// 00652b62  56                   push esi
// 00652b63  8bcf                 mov ecx, edi
// 00652b65  e8c6ecf3ff           call 0x591830
// 00652b6a  8b4604               mov eax, dword ptr [esi + 4]
// 00652b6d  885830               mov byte ptr [eax + 0x30], bl
// 00652b70  8b4e04               mov ecx, dword ptr [esi + 4]
// 00652b73  8b5104               mov edx, dword ptr [ecx + 4]
// 00652b76  c6423000             mov byte ptr [edx + 0x30], 0
// 00652b7a  8b4604               mov eax, dword ptr [esi + 4]
// 00652b7d  8b4804               mov ecx, dword ptr [eax + 4]
// 00652b80  51                   push ecx
// 00652b81  8bcf                 mov ecx, edi
// 00652b83  e888e2ffff           call 0x650e10
// 00652b88  eb7b                 jmp 0x652c05
// 00652b8a  8b12                 mov edx, dword ptr [edx]
// 00652b8c  807a3000             cmp byte ptr [edx + 0x30], 0
// 00652b90  7516                 jne 0x652ba8
// 00652b92  885930               mov byte ptr [ecx + 0x30], bl
// 00652b95  885a30               mov byte ptr [edx + 0x30], bl
// 00652b98  8b10                 mov edx, dword ptr [eax]
// 00652b9a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00652b9d  c6413000             mov byte ptr [ecx + 0x30], 0
// 00652ba1  8b10                 mov edx, dword ptr [eax]
// 00652ba3  8b7204               mov esi, dword ptr [edx + 4]
// 00652ba6  eb5d                 jmp 0x652c05
// 00652ba8  3b31                 cmp esi, dword ptr [ecx]
// 00652baa  750a                 jne 0x652bb6
// 00652bac  8bf1                 mov esi, ecx
// 00652bae  56                   push esi
// 00652baf  8bcf                 mov ecx, edi
// 00652bb1  e85ae2ffff           call 0x650e10
// 00652bb6  8b4604               mov eax, dword ptr [esi + 4]
// 00652bb9  885830               mov byte ptr [eax + 0x30], bl
// 00652bbc  8b4e04               mov ecx, dword ptr [esi + 4]
// 00652bbf  8b5104               mov edx, dword ptr [ecx + 4]
// 00652bc2  c6423000             mov byte ptr [edx + 0x30], 0
// 00652bc6  8b4604               mov eax, dword ptr [esi + 4]
// 00652bc9  8b4004               mov eax, dword ptr [eax + 4]
// 00652bcc  8b4808               mov ecx, dword ptr [eax + 8]
// 00652bcf  8b11                 mov edx, dword ptr [ecx]
// 00652bd1  895008               mov dword ptr [eax + 8], edx
// 00652bd4  8b11                 mov edx, dword ptr [ecx]
// 00652bd6  807a3100             cmp byte ptr [edx + 0x31], 0
// 00652bda  7503                 jne 0x652bdf
// 00652bdc  894204               mov dword ptr [edx + 4], eax
// 00652bdf  8b5004               mov edx, dword ptr [eax + 4]
// 00652be2  895104               mov dword ptr [ecx + 4], edx
// 00652be5  8b5718               mov edx, dword ptr [edi + 0x18]
// 00652be8  3b4204               cmp eax, dword ptr [edx + 4]
// 00652beb  7505                 jne 0x652bf2
// 00652bed  894a04               mov dword ptr [edx + 4], ecx
// 00652bf0  eb0e                 jmp 0x652c00
// 00652bf2  8b5004               mov edx, dword ptr [eax + 4]
// 00652bf5  3b02                 cmp eax, dword ptr [edx]
// 00652bf7  7504                 jne 0x652bfd
// 00652bf9  890a                 mov dword ptr [edx], ecx
// 00652bfb  eb03                 jmp 0x652c00
// 00652bfd  894a08               mov dword ptr [edx + 8], ecx
// 00652c00  8901                 mov dword ptr [ecx], eax
// 00652c02  894804               mov dword ptr [eax + 4], ecx
// 00652c05  8b4e04               mov ecx, dword ptr [esi + 4]
// 00652c08  80793000             cmp byte ptr [ecx + 0x30], 0
// 00652c0c  8d4604               lea eax, [esi + 4]
// 00652c0f  0f841bffffff         je 0x652b30
// 00652c15  8b5718               mov edx, dword ptr [edi + 0x18]
// 00652c18  8b4204               mov eax, dword ptr [edx + 4]
// 00652c1b  885830               mov byte ptr [eax + 0x30], bl
// 00652c1e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00652c22  8b0f                 mov ecx, dword ptr [edi]
// 00652c24  5e                   pop esi
// 00652c25  896804               mov dword ptr [eax + 4], ebp
// 00652c28  5d                   pop ebp
// 00652c29  8908                 mov dword ptr [eax], ecx
// 00652c2b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00652c2f  5b                   pop ebx
// 00652c30  5f                   pop edi
// 00652c31  64890d00000000       mov dword ptr fs:[0], ecx
// 00652c38  83c450               add esp, 0x50
// 00652c3b  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
