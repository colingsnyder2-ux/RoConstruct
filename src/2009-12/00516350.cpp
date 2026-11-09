// from server: 100% by auto
// roc 2009-12 00516350  unit: RBX::VInstance::?$NonFactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00516350
//
// 00516350  64a100000000         mov eax, dword ptr fs:[0]
// 00516356  6aff                 push -1
// 00516358  6812699500           push 0x956912
// 0051635d  50                   push eax
// 0051635e  64892500000000       mov dword ptr fs:[0], esp
// 00516365  83ec44               sub esp, 0x44
// 00516368  57                   push edi
// 00516369  8bf9                 mov edi, ecx
// 0051636b  817f1c48922409       cmp dword ptr [edi + 0x1c], 0x9249248
// 00516372  7259                 jb 0x5163cd
// 00516374  6800f59900           push 0x99f500
// 00516379  8d4c2408             lea ecx, [esp + 8]
// 0051637d  ff15f4b69800         call dword ptr [0x98b6f4]
// 00516383  8d4c2420             lea ecx, [esp + 0x20]
// 00516387  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0051638f  ff1554b79800         call dword ptr [0x98b754]
// 00516395  8d442404             lea eax, [esp + 4]
// 00516399  50                   push eax
// 0051639a  8d4c2430             lea ecx, [esp + 0x30]
// 0051639e  c644245401           mov byte ptr [esp + 0x54], 1
// 005163a3  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 005163ab  ff15f0b69800         call dword ptr [0x98b6f0]
// 005163b1  68e4efa800           push 0xa8efe4
// 005163b6  8d4c2424             lea ecx, [esp + 0x24]
// 005163ba  51                   push ecx
// 005163bb  c644245800           mov byte ptr [esp + 0x58], 0
// 005163c0  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 005163c8  e8abe42d00           call 0x7f4878
// 005163cd  8b542464             mov edx, dword ptr [esp + 0x64]
// 005163d1  8b4718               mov eax, dword ptr [edi + 0x18]
// 005163d4  53                   push ebx
// 005163d5  55                   push ebp
// 005163d6  56                   push esi
// 005163d7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005163db  6a00                 push 0
// 005163dd  52                   push edx
// 005163de  50                   push eax
// 005163df  56                   push esi
// 005163e0  50                   push eax
// 005163e1  e8eaf8f6ff           call 0x485cd0
// 005163e6  8be8                 mov ebp, eax
// 005163e8  8b4718               mov eax, dword ptr [edi + 0x18]
// 005163eb  bb01000000           mov ebx, 1
// 005163f0  015f1c               add dword ptr [edi + 0x1c], ebx
// 005163f3  3bf0                 cmp esi, eax
// 005163f5  7510                 jne 0x516407
// 005163f7  896804               mov dword ptr [eax + 4], ebp
// 005163fa  8b4718               mov eax, dword ptr [edi + 0x18]
// 005163fd  8928                 mov dword ptr [eax], ebp
// 005163ff  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00516402  896908               mov dword ptr [ecx + 8], ebp
// 00516405  eb22                 jmp 0x516429
// 00516407  807c246800           cmp byte ptr [esp + 0x68], 0
// 0051640c  740d                 je 0x51641b
// 0051640e  892e                 mov dword ptr [esi], ebp
// 00516410  8b4718               mov eax, dword ptr [edi + 0x18]
// 00516413  3b30                 cmp esi, dword ptr [eax]
// 00516415  7512                 jne 0x516429
// 00516417  8928                 mov dword ptr [eax], ebp
// 00516419  eb0e                 jmp 0x516429
// 0051641b  896e08               mov dword ptr [esi + 8], ebp
// 0051641e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00516421  3b7008               cmp esi, dword ptr [eax + 8]
// 00516424  7503                 jne 0x516429
// 00516426  896808               mov dword ptr [eax + 8], ebp
// 00516429  8b5504               mov edx, dword ptr [ebp + 4]
// 0051642c  807a2800             cmp byte ptr [edx + 0x28], 0
// 00516430  8d4504               lea eax, [ebp + 4]
// 00516433  8bf5                 mov esi, ebp
// 00516435  0f85ea000000         jne 0x516525
// 0051643b  eb03                 jmp 0x516440
// 0051643d  8d4900               lea ecx, [ecx]
// 00516440  8b08                 mov ecx, dword ptr [eax]
// 00516442  8b5104               mov edx, dword ptr [ecx + 4]
// 00516445  3b0a                 cmp ecx, dword ptr [edx]
// 00516447  7551                 jne 0x51649a
// 00516449  8b5208               mov edx, dword ptr [edx + 8]
// 0051644c  807a2800             cmp byte ptr [edx + 0x28], 0
// 00516450  7519                 jne 0x51646b
// 00516452  885928               mov byte ptr [ecx + 0x28], bl
// 00516455  885a28               mov byte ptr [edx + 0x28], bl
// 00516458  8b10                 mov edx, dword ptr [eax]
// 0051645a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0051645d  c6412800             mov byte ptr [ecx + 0x28], 0
// 00516461  8b10                 mov edx, dword ptr [eax]
// 00516463  8b7204               mov esi, dword ptr [edx + 4]
// 00516466  e9aa000000           jmp 0x516515
// 0051646b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0051646e  750a                 jne 0x51647a
// 00516470  8bf1                 mov esi, ecx
// 00516472  56                   push esi
// 00516473  8bcf                 mov ecx, edi
// 00516475  e8066d0b00           call 0x5cd180
// 0051647a  8b4604               mov eax, dword ptr [esi + 4]
// 0051647d  885828               mov byte ptr [eax + 0x28], bl
// 00516480  8b4e04               mov ecx, dword ptr [esi + 4]
// 00516483  8b5104               mov edx, dword ptr [ecx + 4]
// 00516486  c6422800             mov byte ptr [edx + 0x28], 0
// 0051648a  8b4604               mov eax, dword ptr [esi + 4]
// 0051648d  8b4804               mov ecx, dword ptr [eax + 4]
// 00516490  51                   push ecx
// 00516491  8bcf                 mov ecx, edi
// 00516493  e848610b00           call 0x5cc5e0
// 00516498  eb7b                 jmp 0x516515
// 0051649a  8b12                 mov edx, dword ptr [edx]
// 0051649c  807a2800             cmp byte ptr [edx + 0x28], 0
// 005164a0  7516                 jne 0x5164b8
// 005164a2  885928               mov byte ptr [ecx + 0x28], bl
// 005164a5  885a28               mov byte ptr [edx + 0x28], bl
// 005164a8  8b10                 mov edx, dword ptr [eax]
// 005164aa  8b4a04               mov ecx, dword ptr [edx + 4]
// 005164ad  c6412800             mov byte ptr [ecx + 0x28], 0
// 005164b1  8b10                 mov edx, dword ptr [eax]
// 005164b3  8b7204               mov esi, dword ptr [edx + 4]
// 005164b6  eb5d                 jmp 0x516515
// 005164b8  3b31                 cmp esi, dword ptr [ecx]
// 005164ba  750a                 jne 0x5164c6
// 005164bc  8bf1                 mov esi, ecx
// 005164be  56                   push esi
// 005164bf  8bcf                 mov ecx, edi
// 005164c1  e81a610b00           call 0x5cc5e0
// 005164c6  8b4604               mov eax, dword ptr [esi + 4]
// 005164c9  885828               mov byte ptr [eax + 0x28], bl
// 005164cc  8b4e04               mov ecx, dword ptr [esi + 4]
// 005164cf  8b5104               mov edx, dword ptr [ecx + 4]
// 005164d2  c6422800             mov byte ptr [edx + 0x28], 0
// 005164d6  8b4604               mov eax, dword ptr [esi + 4]
// 005164d9  8b4004               mov eax, dword ptr [eax + 4]
// 005164dc  8b4808               mov ecx, dword ptr [eax + 8]
// 005164df  8b11                 mov edx, dword ptr [ecx]
// 005164e1  895008               mov dword ptr [eax + 8], edx
// 005164e4  8b11                 mov edx, dword ptr [ecx]
// 005164e6  807a2900             cmp byte ptr [edx + 0x29], 0
// 005164ea  7503                 jne 0x5164ef
// 005164ec  894204               mov dword ptr [edx + 4], eax
// 005164ef  8b5004               mov edx, dword ptr [eax + 4]
// 005164f2  895104               mov dword ptr [ecx + 4], edx
// 005164f5  8b5718               mov edx, dword ptr [edi + 0x18]
// 005164f8  3b4204               cmp eax, dword ptr [edx + 4]
// 005164fb  7505                 jne 0x516502
// 005164fd  894a04               mov dword ptr [edx + 4], ecx
// 00516500  eb0e                 jmp 0x516510
// 00516502  8b5004               mov edx, dword ptr [eax + 4]
// 00516505  3b02                 cmp eax, dword ptr [edx]
// 00516507  7504                 jne 0x51650d
// 00516509  890a                 mov dword ptr [edx], ecx
// 0051650b  eb03                 jmp 0x516510
// 0051650d  894a08               mov dword ptr [edx + 8], ecx
// 00516510  8901                 mov dword ptr [ecx], eax
// 00516512  894804               mov dword ptr [eax + 4], ecx
// 00516515  8b4e04               mov ecx, dword ptr [esi + 4]
// 00516518  80792800             cmp byte ptr [ecx + 0x28], 0
// 0051651c  8d4604               lea eax, [esi + 4]
// 0051651f  0f841bffffff         je 0x516440
// 00516525  8b5718               mov edx, dword ptr [edi + 0x18]
// 00516528  8b4204               mov eax, dword ptr [edx + 4]
// 0051652b  885828               mov byte ptr [eax + 0x28], bl
// 0051652e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00516532  8b0f                 mov ecx, dword ptr [edi]
// 00516534  5e                   pop esi
// 00516535  896804               mov dword ptr [eax + 4], ebp
// 00516538  5d                   pop ebp
// 00516539  8908                 mov dword ptr [eax], ecx
// 0051653b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0051653f  5b                   pop ebx
// 00516540  5f                   pop edi
// 00516541  64890d00000000       mov dword ptr fs:[0], ecx
// 00516548  83c450               add esp, 0x50
// 0051654b  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
