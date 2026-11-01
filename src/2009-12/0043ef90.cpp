// from server: 100% by auto
// roc 2009-12 0043ef90  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0043ef90
//
// 0043ef90  64a100000000         mov eax, dword ptr fs:[0]
// 0043ef96  6aff                 push -1
// 0043ef98  6812699500           push 0x956912
// 0043ef9d  50                   push eax
// 0043ef9e  64892500000000       mov dword ptr fs:[0], esp
// 0043efa5  83ec44               sub esp, 0x44
// 0043efa8  57                   push edi
// 0043efa9  8bf9                 mov edi, ecx
// 0043efab  817f1c48922409       cmp dword ptr [edi + 0x1c], 0x9249248
// 0043efb2  7259                 jb 0x43f00d
// 0043efb4  6800f59900           push 0x99f500
// 0043efb9  8d4c2408             lea ecx, [esp + 8]
// 0043efbd  ff15f4b69800         call dword ptr [0x98b6f4]
// 0043efc3  8d4c2420             lea ecx, [esp + 0x20]
// 0043efc7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0043efcf  ff1554b79800         call dword ptr [0x98b754]
// 0043efd5  8d442404             lea eax, [esp + 4]
// 0043efd9  50                   push eax
// 0043efda  8d4c2430             lea ecx, [esp + 0x30]
// 0043efde  c644245401           mov byte ptr [esp + 0x54], 1
// 0043efe3  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 0043efeb  ff15f0b69800         call dword ptr [0x98b6f0]
// 0043eff1  68e4efa800           push 0xa8efe4
// 0043eff6  8d4c2424             lea ecx, [esp + 0x24]
// 0043effa  51                   push ecx
// 0043effb  c644245800           mov byte ptr [esp + 0x58], 0
// 0043f000  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 0043f008  e86b583b00           call 0x7f4878
// 0043f00d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0043f011  8b4718               mov eax, dword ptr [edi + 0x18]
// 0043f014  53                   push ebx
// 0043f015  55                   push ebp
// 0043f016  56                   push esi
// 0043f017  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0043f01b  6a00                 push 0
// 0043f01d  52                   push edx
// 0043f01e  50                   push eax
// 0043f01f  56                   push esi
// 0043f020  50                   push eax
// 0043f021  e83aa2ffff           call 0x439260
// 0043f026  8be8                 mov ebp, eax
// 0043f028  8b4718               mov eax, dword ptr [edi + 0x18]
// 0043f02b  bb01000000           mov ebx, 1
// 0043f030  015f1c               add dword ptr [edi + 0x1c], ebx
// 0043f033  3bf0                 cmp esi, eax
// 0043f035  7510                 jne 0x43f047
// 0043f037  896804               mov dword ptr [eax + 4], ebp
// 0043f03a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0043f03d  8928                 mov dword ptr [eax], ebp
// 0043f03f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0043f042  896908               mov dword ptr [ecx + 8], ebp
// 0043f045  eb22                 jmp 0x43f069
// 0043f047  807c246800           cmp byte ptr [esp + 0x68], 0
// 0043f04c  740d                 je 0x43f05b
// 0043f04e  892e                 mov dword ptr [esi], ebp
// 0043f050  8b4718               mov eax, dword ptr [edi + 0x18]
// 0043f053  3b30                 cmp esi, dword ptr [eax]
// 0043f055  7512                 jne 0x43f069
// 0043f057  8928                 mov dword ptr [eax], ebp
// 0043f059  eb0e                 jmp 0x43f069
// 0043f05b  896e08               mov dword ptr [esi + 8], ebp
// 0043f05e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0043f061  3b7008               cmp esi, dword ptr [eax + 8]
// 0043f064  7503                 jne 0x43f069
// 0043f066  896808               mov dword ptr [eax + 8], ebp
// 0043f069  8b5504               mov edx, dword ptr [ebp + 4]
// 0043f06c  807a2800             cmp byte ptr [edx + 0x28], 0
// 0043f070  8d4504               lea eax, [ebp + 4]
// 0043f073  8bf5                 mov esi, ebp
// 0043f075  0f85ea000000         jne 0x43f165
// 0043f07b  eb03                 jmp 0x43f080
// 0043f07d  8d4900               lea ecx, [ecx]
// 0043f080  8b08                 mov ecx, dword ptr [eax]
// 0043f082  8b5104               mov edx, dword ptr [ecx + 4]
// 0043f085  3b0a                 cmp ecx, dword ptr [edx]
// 0043f087  7551                 jne 0x43f0da
// 0043f089  8b5208               mov edx, dword ptr [edx + 8]
// 0043f08c  807a2800             cmp byte ptr [edx + 0x28], 0
// 0043f090  7519                 jne 0x43f0ab
// 0043f092  885928               mov byte ptr [ecx + 0x28], bl
// 0043f095  885a28               mov byte ptr [edx + 0x28], bl
// 0043f098  8b10                 mov edx, dword ptr [eax]
// 0043f09a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0043f09d  c6412800             mov byte ptr [ecx + 0x28], 0
// 0043f0a1  8b10                 mov edx, dword ptr [eax]
// 0043f0a3  8b7204               mov esi, dword ptr [edx + 4]
// 0043f0a6  e9aa000000           jmp 0x43f155
// 0043f0ab  3b7108               cmp esi, dword ptr [ecx + 8]
// 0043f0ae  750a                 jne 0x43f0ba
// 0043f0b0  8bf1                 mov esi, ecx
// 0043f0b2  56                   push esi
// 0043f0b3  8bcf                 mov ecx, edi
// 0043f0b5  e8c6e01800           call 0x5cd180
// 0043f0ba  8b4604               mov eax, dword ptr [esi + 4]
// 0043f0bd  885828               mov byte ptr [eax + 0x28], bl
// 0043f0c0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0043f0c3  8b5104               mov edx, dword ptr [ecx + 4]
// 0043f0c6  c6422800             mov byte ptr [edx + 0x28], 0
// 0043f0ca  8b4604               mov eax, dword ptr [esi + 4]
// 0043f0cd  8b4804               mov ecx, dword ptr [eax + 4]
// 0043f0d0  51                   push ecx
// 0043f0d1  8bcf                 mov ecx, edi
// 0043f0d3  e808d51800           call 0x5cc5e0
// 0043f0d8  eb7b                 jmp 0x43f155
// 0043f0da  8b12                 mov edx, dword ptr [edx]
// 0043f0dc  807a2800             cmp byte ptr [edx + 0x28], 0
// 0043f0e0  7516                 jne 0x43f0f8
// 0043f0e2  885928               mov byte ptr [ecx + 0x28], bl
// 0043f0e5  885a28               mov byte ptr [edx + 0x28], bl
// 0043f0e8  8b10                 mov edx, dword ptr [eax]
// 0043f0ea  8b4a04               mov ecx, dword ptr [edx + 4]
// 0043f0ed  c6412800             mov byte ptr [ecx + 0x28], 0
// 0043f0f1  8b10                 mov edx, dword ptr [eax]
// 0043f0f3  8b7204               mov esi, dword ptr [edx + 4]
// 0043f0f6  eb5d                 jmp 0x43f155
// 0043f0f8  3b31                 cmp esi, dword ptr [ecx]
// 0043f0fa  750a                 jne 0x43f106
// 0043f0fc  8bf1                 mov esi, ecx
// 0043f0fe  56                   push esi
// 0043f0ff  8bcf                 mov ecx, edi
// 0043f101  e8dad41800           call 0x5cc5e0
// 0043f106  8b4604               mov eax, dword ptr [esi + 4]
// 0043f109  885828               mov byte ptr [eax + 0x28], bl
// 0043f10c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0043f10f  8b5104               mov edx, dword ptr [ecx + 4]
// 0043f112  c6422800             mov byte ptr [edx + 0x28], 0
// 0043f116  8b4604               mov eax, dword ptr [esi + 4]
// 0043f119  8b4004               mov eax, dword ptr [eax + 4]
// 0043f11c  8b4808               mov ecx, dword ptr [eax + 8]
// 0043f11f  8b11                 mov edx, dword ptr [ecx]
// 0043f121  895008               mov dword ptr [eax + 8], edx
// 0043f124  8b11                 mov edx, dword ptr [ecx]
// 0043f126  807a2900             cmp byte ptr [edx + 0x29], 0
// 0043f12a  7503                 jne 0x43f12f
// 0043f12c  894204               mov dword ptr [edx + 4], eax
// 0043f12f  8b5004               mov edx, dword ptr [eax + 4]
// 0043f132  895104               mov dword ptr [ecx + 4], edx
// 0043f135  8b5718               mov edx, dword ptr [edi + 0x18]
// 0043f138  3b4204               cmp eax, dword ptr [edx + 4]
// 0043f13b  7505                 jne 0x43f142
// 0043f13d  894a04               mov dword ptr [edx + 4], ecx
// 0043f140  eb0e                 jmp 0x43f150
// 0043f142  8b5004               mov edx, dword ptr [eax + 4]
// 0043f145  3b02                 cmp eax, dword ptr [edx]
// 0043f147  7504                 jne 0x43f14d
// 0043f149  890a                 mov dword ptr [edx], ecx
// 0043f14b  eb03                 jmp 0x43f150
// 0043f14d  894a08               mov dword ptr [edx + 8], ecx
// 0043f150  8901                 mov dword ptr [ecx], eax
// 0043f152  894804               mov dword ptr [eax + 4], ecx
// 0043f155  8b4e04               mov ecx, dword ptr [esi + 4]
// 0043f158  80792800             cmp byte ptr [ecx + 0x28], 0
// 0043f15c  8d4604               lea eax, [esi + 4]
// 0043f15f  0f841bffffff         je 0x43f080
// 0043f165  8b5718               mov edx, dword ptr [edi + 0x18]
// 0043f168  8b4204               mov eax, dword ptr [edx + 4]
// 0043f16b  885828               mov byte ptr [eax + 0x28], bl
// 0043f16e  8b442464             mov eax, dword ptr [esp + 0x64]
// 0043f172  8b0f                 mov ecx, dword ptr [edi]
// 0043f174  5e                   pop esi
// 0043f175  896804               mov dword ptr [eax + 4], ebp
// 0043f178  5d                   pop ebp
// 0043f179  8908                 mov dword ptr [eax], ecx
// 0043f17b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0043f17f  5b                   pop ebx
// 0043f180  5f                   pop edi
// 0043f181  64890d00000000       mov dword ptr fs:[0], ecx
// 0043f188  83c450               add esp, 0x50
// 0043f18b  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
