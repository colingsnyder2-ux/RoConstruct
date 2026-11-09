// from server: 100% by auto
// roc 2008-06 00648490  unit: RBX::Block  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00648490
//
// 00648490  64a100000000         mov eax, dword ptr fs:[0]
// 00648496  6aff                 push -1
// 00648498  6842e87d00           push 0x7de842
// 0064849d  50                   push eax
// 0064849e  64892500000000       mov dword ptr fs:[0], esp
// 006484a5  83ec44               sub esp, 0x44
// 006484a8  57                   push edi
// 006484a9  8bf9                 mov edi, ecx
// 006484ab  817f1cfeffff0f       cmp dword ptr [edi + 0x1c], 0xffffffe
// 006484b2  7259                 jb 0x64850d
// 006484b4  688cb28000           push 0x80b28c
// 006484b9  8d4c2408             lea ecx, [esp + 8]
// 006484bd  ff1558248000         call dword ptr [0x802458]
// 006484c3  8d4c2420             lea ecx, [esp + 0x20]
// 006484c7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006484cf  ff1598288000         call dword ptr [0x802898]
// 006484d5  8d442404             lea eax, [esp + 4]
// 006484d9  50                   push eax
// 006484da  8d4c2430             lea ecx, [esp + 0x30]
// 006484de  c644245401           mov byte ptr [esp + 0x54], 1
// 006484e3  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 006484eb  ff155c248000         call dword ptr [0x80245c]
// 006484f1  68c00c8d00           push 0x8d0cc0
// 006484f6  8d4c2424             lea ecx, [esp + 0x24]
// 006484fa  51                   push ecx
// 006484fb  c644245800           mov byte ptr [esp + 0x58], 0
// 00648500  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 00648508  e87f900500           call 0x6a158c
// 0064850d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00648511  8b4718               mov eax, dword ptr [edi + 0x18]
// 00648514  53                   push ebx
// 00648515  55                   push ebp
// 00648516  56                   push esi
// 00648517  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0064851b  6a00                 push 0
// 0064851d  52                   push edx
// 0064851e  50                   push eax
// 0064851f  56                   push esi
// 00648520  50                   push eax
// 00648521  e8dafeffff           call 0x648400
// 00648526  8be8                 mov ebp, eax
// 00648528  8b4718               mov eax, dword ptr [edi + 0x18]
// 0064852b  bb01000000           mov ebx, 1
// 00648530  015f1c               add dword ptr [edi + 0x1c], ebx
// 00648533  3bf0                 cmp esi, eax
// 00648535  7510                 jne 0x648547
// 00648537  896804               mov dword ptr [eax + 4], ebp
// 0064853a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0064853d  8928                 mov dword ptr [eax], ebp
// 0064853f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00648542  896908               mov dword ptr [ecx + 8], ebp
// 00648545  eb22                 jmp 0x648569
// 00648547  807c246800           cmp byte ptr [esp + 0x68], 0
// 0064854c  740d                 je 0x64855b
// 0064854e  892e                 mov dword ptr [esi], ebp
// 00648550  8b4718               mov eax, dword ptr [edi + 0x18]
// 00648553  3b30                 cmp esi, dword ptr [eax]
// 00648555  7512                 jne 0x648569
// 00648557  8928                 mov dword ptr [eax], ebp
// 00648559  eb0e                 jmp 0x648569
// 0064855b  896e08               mov dword ptr [esi + 8], ebp
// 0064855e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00648561  3b7008               cmp esi, dword ptr [eax + 8]
// 00648564  7503                 jne 0x648569
// 00648566  896808               mov dword ptr [eax + 8], ebp
// 00648569  8b5504               mov edx, dword ptr [ebp + 4]
// 0064856c  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 00648570  8d4504               lea eax, [ebp + 4]
// 00648573  8bf5                 mov esi, ebp
// 00648575  0f85ea000000         jne 0x648665
// 0064857b  eb03                 jmp 0x648580
// 0064857d  8d4900               lea ecx, [ecx]
// 00648580  8b08                 mov ecx, dword ptr [eax]
// 00648582  8b5104               mov edx, dword ptr [ecx + 4]
// 00648585  3b0a                 cmp ecx, dword ptr [edx]
// 00648587  7551                 jne 0x6485da
// 00648589  8b5208               mov edx, dword ptr [edx + 8]
// 0064858c  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 00648590  7519                 jne 0x6485ab
// 00648592  88591c               mov byte ptr [ecx + 0x1c], bl
// 00648595  885a1c               mov byte ptr [edx + 0x1c], bl
// 00648598  8b10                 mov edx, dword ptr [eax]
// 0064859a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0064859d  c6411c00             mov byte ptr [ecx + 0x1c], 0
// 006485a1  8b10                 mov edx, dword ptr [eax]
// 006485a3  8b7204               mov esi, dword ptr [edx + 4]
// 006485a6  e9aa000000           jmp 0x648655
// 006485ab  3b7108               cmp esi, dword ptr [ecx + 8]
// 006485ae  750a                 jne 0x6485ba
// 006485b0  8bf1                 mov esi, ecx
// 006485b2  56                   push esi
// 006485b3  8bcf                 mov ecx, edi
// 006485b5  e8d6fbffff           call 0x648190
// 006485ba  8b4604               mov eax, dword ptr [esi + 4]
// 006485bd  88581c               mov byte ptr [eax + 0x1c], bl
// 006485c0  8b4e04               mov ecx, dword ptr [esi + 4]
// 006485c3  8b5104               mov edx, dword ptr [ecx + 4]
// 006485c6  c6421c00             mov byte ptr [edx + 0x1c], 0
// 006485ca  8b4604               mov eax, dword ptr [esi + 4]
// 006485cd  8b4804               mov ecx, dword ptr [eax + 4]
// 006485d0  51                   push ecx
// 006485d1  8bcf                 mov ecx, edi
// 006485d3  e818f8ffff           call 0x647df0
// 006485d8  eb7b                 jmp 0x648655
// 006485da  8b12                 mov edx, dword ptr [edx]
// 006485dc  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 006485e0  7516                 jne 0x6485f8
// 006485e2  88591c               mov byte ptr [ecx + 0x1c], bl
// 006485e5  885a1c               mov byte ptr [edx + 0x1c], bl
// 006485e8  8b10                 mov edx, dword ptr [eax]
// 006485ea  8b4a04               mov ecx, dword ptr [edx + 4]
// 006485ed  c6411c00             mov byte ptr [ecx + 0x1c], 0
// 006485f1  8b10                 mov edx, dword ptr [eax]
// 006485f3  8b7204               mov esi, dword ptr [edx + 4]
// 006485f6  eb5d                 jmp 0x648655
// 006485f8  3b31                 cmp esi, dword ptr [ecx]
// 006485fa  750a                 jne 0x648606
// 006485fc  8bf1                 mov esi, ecx
// 006485fe  56                   push esi
// 006485ff  8bcf                 mov ecx, edi
// 00648601  e8eaf7ffff           call 0x647df0
// 00648606  8b4604               mov eax, dword ptr [esi + 4]
// 00648609  88581c               mov byte ptr [eax + 0x1c], bl
// 0064860c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0064860f  8b5104               mov edx, dword ptr [ecx + 4]
// 00648612  c6421c00             mov byte ptr [edx + 0x1c], 0
// 00648616  8b4604               mov eax, dword ptr [esi + 4]
// 00648619  8b4004               mov eax, dword ptr [eax + 4]
// 0064861c  8b4808               mov ecx, dword ptr [eax + 8]
// 0064861f  8b11                 mov edx, dword ptr [ecx]
// 00648621  895008               mov dword ptr [eax + 8], edx
// 00648624  8b11                 mov edx, dword ptr [ecx]
// 00648626  807a1d00             cmp byte ptr [edx + 0x1d], 0
// 0064862a  7503                 jne 0x64862f
// 0064862c  894204               mov dword ptr [edx + 4], eax
// 0064862f  8b5004               mov edx, dword ptr [eax + 4]
// 00648632  895104               mov dword ptr [ecx + 4], edx
// 00648635  8b5718               mov edx, dword ptr [edi + 0x18]
// 00648638  3b4204               cmp eax, dword ptr [edx + 4]
// 0064863b  7505                 jne 0x648642
// 0064863d  894a04               mov dword ptr [edx + 4], ecx
// 00648640  eb0e                 jmp 0x648650
// 00648642  8b5004               mov edx, dword ptr [eax + 4]
// 00648645  3b02                 cmp eax, dword ptr [edx]
// 00648647  7504                 jne 0x64864d
// 00648649  890a                 mov dword ptr [edx], ecx
// 0064864b  eb03                 jmp 0x648650
// 0064864d  894a08               mov dword ptr [edx + 8], ecx
// 00648650  8901                 mov dword ptr [ecx], eax
// 00648652  894804               mov dword ptr [eax + 4], ecx
// 00648655  8b4e04               mov ecx, dword ptr [esi + 4]
// 00648658  80791c00             cmp byte ptr [ecx + 0x1c], 0
// 0064865c  8d4604               lea eax, [esi + 4]
// 0064865f  0f841bffffff         je 0x648580
// 00648665  8b5718               mov edx, dword ptr [edi + 0x18]
// 00648668  8b4204               mov eax, dword ptr [edx + 4]
// 0064866b  88581c               mov byte ptr [eax + 0x1c], bl
// 0064866e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00648672  8b0f                 mov ecx, dword ptr [edi]
// 00648674  5e                   pop esi
// 00648675  896804               mov dword ptr [eax + 4], ebp
// 00648678  5d                   pop ebp
// 00648679  8908                 mov dword ptr [eax], ecx
// 0064867b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0064867f  5b                   pop ebx
// 00648680  5f                   pop edi
// 00648681  64890d00000000       mov dword ptr fs:[0], ecx
// 00648688  83c450               add esp, 0x50
// 0064868b  c21000               ret 0x10
// standard library map_int<pod12> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod12>
struct E { int v[3]; };
#include <map>
template class std::map<int, E>;
