// from server: 100% by auto
// roc 2007-03 004cc600  unit: seg_004c0000  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004cc600
//
// 004cc600  64a100000000         mov eax, dword ptr fs:[0]
// 004cc606  6aff                 push -1
// 004cc608  68926f7500           push 0x756f92
// 004cc60d  50                   push eax
// 004cc60e  64892500000000       mov dword ptr fs:[0], esp
// 004cc615  83ec44               sub esp, 0x44
// 004cc618  57                   push edi
// 004cc619  8bf9                 mov edi, ecx
// 004cc61b  817f08cbcccc0c       cmp dword ptr [edi + 8], 0xccccccb
// 004cc622  7259                 jb 0x4cc67d
// 004cc624  68903f7800           push 0x783f90
// 004cc629  8d4c2408             lea ecx, [esp + 8]
// 004cc62d  ff1578e77700         call dword ptr [0x77e778]
// 004cc633  8d4c2420             lea ecx, [esp + 0x20]
// 004cc637  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004cc63f  ff1560e97700         call dword ptr [0x77e960]
// 004cc645  8d442404             lea eax, [esp + 4]
// 004cc649  50                   push eax
// 004cc64a  8d4c2430             lea ecx, [esp + 0x30]
// 004cc64e  c644245401           mov byte ptr [esp + 0x54], 1
// 004cc653  c7442424383e7800     mov dword ptr [esp + 0x24], 0x783e38
// 004cc65b  ff157ce77700         call dword ptr [0x77e77c]
// 004cc661  6870f78300           push 0x83f770
// 004cc666  8d4c2424             lea ecx, [esp + 0x24]
// 004cc66a  51                   push ecx
// 004cc66b  c644245800           mov byte ptr [esp + 0x58], 0
// 004cc670  c7442428443e7800     mov dword ptr [esp + 0x28], 0x783e44
// 004cc678  e8b1291500           call 0x61f02e
// 004cc67d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004cc681  8b4704               mov eax, dword ptr [edi + 4]
// 004cc684  53                   push ebx
// 004cc685  55                   push ebp
// 004cc686  56                   push esi
// 004cc687  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004cc68b  6a00                 push 0
// 004cc68d  52                   push edx
// 004cc68e  50                   push eax
// 004cc68f  56                   push esi
// 004cc690  50                   push eax
// 004cc691  e8bafeffff           call 0x4cc550
// 004cc696  8be8                 mov ebp, eax
// 004cc698  8b4704               mov eax, dword ptr [edi + 4]
// 004cc69b  bb01000000           mov ebx, 1
// 004cc6a0  015f08               add dword ptr [edi + 8], ebx
// 004cc6a3  3bf0                 cmp esi, eax
// 004cc6a5  7510                 jne 0x4cc6b7
// 004cc6a7  896804               mov dword ptr [eax + 4], ebp
// 004cc6aa  8b4704               mov eax, dword ptr [edi + 4]
// 004cc6ad  8928                 mov dword ptr [eax], ebp
// 004cc6af  8b4f04               mov ecx, dword ptr [edi + 4]
// 004cc6b2  896908               mov dword ptr [ecx + 8], ebp
// 004cc6b5  eb22                 jmp 0x4cc6d9
// 004cc6b7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004cc6bc  740d                 je 0x4cc6cb
// 004cc6be  892e                 mov dword ptr [esi], ebp
// 004cc6c0  8b4704               mov eax, dword ptr [edi + 4]
// 004cc6c3  3b30                 cmp esi, dword ptr [eax]
// 004cc6c5  7512                 jne 0x4cc6d9
// 004cc6c7  8928                 mov dword ptr [eax], ebp
// 004cc6c9  eb0e                 jmp 0x4cc6d9
// 004cc6cb  896e08               mov dword ptr [esi + 8], ebp
// 004cc6ce  8b4704               mov eax, dword ptr [edi + 4]
// 004cc6d1  3b7008               cmp esi, dword ptr [eax + 8]
// 004cc6d4  7503                 jne 0x4cc6d9
// 004cc6d6  896808               mov dword ptr [eax + 8], ebp
// 004cc6d9  8b5504               mov edx, dword ptr [ebp + 4]
// 004cc6dc  807a2000             cmp byte ptr [edx + 0x20], 0
// 004cc6e0  8d4504               lea eax, [ebp + 4]
// 004cc6e3  8bf5                 mov esi, ebp
// 004cc6e5  0f85ea000000         jne 0x4cc7d5
// 004cc6eb  eb03                 jmp 0x4cc6f0
// 004cc6ed  8d4900               lea ecx, [ecx]
// 004cc6f0  8b08                 mov ecx, dword ptr [eax]
// 004cc6f2  8b5104               mov edx, dword ptr [ecx + 4]
// 004cc6f5  3b0a                 cmp ecx, dword ptr [edx]
// 004cc6f7  7551                 jne 0x4cc74a
// 004cc6f9  8b5208               mov edx, dword ptr [edx + 8]
// 004cc6fc  807a2000             cmp byte ptr [edx + 0x20], 0
// 004cc700  7519                 jne 0x4cc71b
// 004cc702  885920               mov byte ptr [ecx + 0x20], bl
// 004cc705  885a20               mov byte ptr [edx + 0x20], bl
// 004cc708  8b10                 mov edx, dword ptr [eax]
// 004cc70a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004cc70d  c6412000             mov byte ptr [ecx + 0x20], 0
// 004cc711  8b10                 mov edx, dword ptr [eax]
// 004cc713  8b7204               mov esi, dword ptr [edx + 4]
// 004cc716  e9aa000000           jmp 0x4cc7c5
// 004cc71b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004cc71e  750a                 jne 0x4cc72a
// 004cc720  8bf1                 mov esi, ecx
// 004cc722  56                   push esi
// 004cc723  8bcf                 mov ecx, edi
// 004cc725  e8b65cffff           call 0x4c23e0
// 004cc72a  8b4604               mov eax, dword ptr [esi + 4]
// 004cc72d  885820               mov byte ptr [eax + 0x20], bl
// 004cc730  8b4e04               mov ecx, dword ptr [esi + 4]
// 004cc733  8b5104               mov edx, dword ptr [ecx + 4]
// 004cc736  c6422000             mov byte ptr [edx + 0x20], 0
// 004cc73a  8b4604               mov eax, dword ptr [esi + 4]
// 004cc73d  8b4804               mov ecx, dword ptr [eax + 4]
// 004cc740  51                   push ecx
// 004cc741  8bcf                 mov ecx, edi
// 004cc743  e838cff6ff           call 0x439680
// 004cc748  eb7b                 jmp 0x4cc7c5
// 004cc74a  8b12                 mov edx, dword ptr [edx]
// 004cc74c  807a2000             cmp byte ptr [edx + 0x20], 0
// 004cc750  7516                 jne 0x4cc768
// 004cc752  885920               mov byte ptr [ecx + 0x20], bl
// 004cc755  885a20               mov byte ptr [edx + 0x20], bl
// 004cc758  8b10                 mov edx, dword ptr [eax]
// 004cc75a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004cc75d  c6412000             mov byte ptr [ecx + 0x20], 0
// 004cc761  8b10                 mov edx, dword ptr [eax]
// 004cc763  8b7204               mov esi, dword ptr [edx + 4]
// 004cc766  eb5d                 jmp 0x4cc7c5
// 004cc768  3b31                 cmp esi, dword ptr [ecx]
// 004cc76a  750a                 jne 0x4cc776
// 004cc76c  8bf1                 mov esi, ecx
// 004cc76e  56                   push esi
// 004cc76f  8bcf                 mov ecx, edi
// 004cc771  e80acff6ff           call 0x439680
// 004cc776  8b4604               mov eax, dword ptr [esi + 4]
// 004cc779  885820               mov byte ptr [eax + 0x20], bl
// 004cc77c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004cc77f  8b5104               mov edx, dword ptr [ecx + 4]
// 004cc782  c6422000             mov byte ptr [edx + 0x20], 0
// 004cc786  8b4604               mov eax, dword ptr [esi + 4]
// 004cc789  8b4004               mov eax, dword ptr [eax + 4]
// 004cc78c  8b4808               mov ecx, dword ptr [eax + 8]
// 004cc78f  8b11                 mov edx, dword ptr [ecx]
// 004cc791  895008               mov dword ptr [eax + 8], edx
// 004cc794  8b11                 mov edx, dword ptr [ecx]
// 004cc796  807a2100             cmp byte ptr [edx + 0x21], 0
// 004cc79a  7503                 jne 0x4cc79f
// 004cc79c  894204               mov dword ptr [edx + 4], eax
// 004cc79f  8b5004               mov edx, dword ptr [eax + 4]
// 004cc7a2  895104               mov dword ptr [ecx + 4], edx
// 004cc7a5  8b5704               mov edx, dword ptr [edi + 4]
// 004cc7a8  3b4204               cmp eax, dword ptr [edx + 4]
// 004cc7ab  7505                 jne 0x4cc7b2
// 004cc7ad  894a04               mov dword ptr [edx + 4], ecx
// 004cc7b0  eb0e                 jmp 0x4cc7c0
// 004cc7b2  8b5004               mov edx, dword ptr [eax + 4]
// 004cc7b5  3b02                 cmp eax, dword ptr [edx]
// 004cc7b7  7504                 jne 0x4cc7bd
// 004cc7b9  890a                 mov dword ptr [edx], ecx
// 004cc7bb  eb03                 jmp 0x4cc7c0
// 004cc7bd  894a08               mov dword ptr [edx + 8], ecx
// 004cc7c0  8901                 mov dword ptr [ecx], eax
// 004cc7c2  894804               mov dword ptr [eax + 4], ecx
// 004cc7c5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004cc7c8  80792000             cmp byte ptr [ecx + 0x20], 0
// 004cc7cc  8d4604               lea eax, [esi + 4]
// 004cc7cf  0f841bffffff         je 0x4cc6f0
// 004cc7d5  8b5704               mov edx, dword ptr [edi + 4]
// 004cc7d8  8b4204               mov eax, dword ptr [edx + 4]
// 004cc7db  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004cc7df  885820               mov byte ptr [eax + 0x20], bl
// 004cc7e2  8b442464             mov eax, dword ptr [esp + 0x64]
// 004cc7e6  5e                   pop esi
// 004cc7e7  896804               mov dword ptr [eax + 4], ebp
// 004cc7ea  5d                   pop ebp
// 004cc7eb  8938                 mov dword ptr [eax], edi
// 004cc7ed  5b                   pop ebx
// 004cc7ee  5f                   pop edi
// 004cc7ef  64890d00000000       mov dword ptr fs:[0], ecx
// 004cc7f6  83c450               add esp, 0x50
// 004cc7f9  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
