// from server: 100% by auto
// roc 2009-12 006ad320  unit: RBX::Accoutrement  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ad320
//
// 006ad320  64a100000000         mov eax, dword ptr fs:[0]
// 006ad326  6aff                 push -1
// 006ad328  6812699500           push 0x956912
// 006ad32d  50                   push eax
// 006ad32e  64892500000000       mov dword ptr fs:[0], esp
// 006ad335  83ec44               sub esp, 0x44
// 006ad338  57                   push edi
// 006ad339  8bf9                 mov edi, ecx
// 006ad33b  817f1cfeffff1f       cmp dword ptr [edi + 0x1c], 0x1ffffffe
// 006ad342  7259                 jb 0x6ad39d
// 006ad344  6800f59900           push 0x99f500
// 006ad349  8d4c2408             lea ecx, [esp + 8]
// 006ad34d  ff15f4b69800         call dword ptr [0x98b6f4]
// 006ad353  8d4c2420             lea ecx, [esp + 0x20]
// 006ad357  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006ad35f  ff1554b79800         call dword ptr [0x98b754]
// 006ad365  8d442404             lea eax, [esp + 4]
// 006ad369  50                   push eax
// 006ad36a  8d4c2430             lea ecx, [esp + 0x30]
// 006ad36e  c644245401           mov byte ptr [esp + 0x54], 1
// 006ad373  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 006ad37b  ff15f0b69800         call dword ptr [0x98b6f0]
// 006ad381  68e4efa800           push 0xa8efe4
// 006ad386  8d4c2424             lea ecx, [esp + 0x24]
// 006ad38a  51                   push ecx
// 006ad38b  c644245800           mov byte ptr [esp + 0x58], 0
// 006ad390  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 006ad398  e8db741400           call 0x7f4878
// 006ad39d  8b542464             mov edx, dword ptr [esp + 0x64]
// 006ad3a1  8b4718               mov eax, dword ptr [edi + 0x18]
// 006ad3a4  53                   push ebx
// 006ad3a5  55                   push ebp
// 006ad3a6  56                   push esi
// 006ad3a7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006ad3ab  6a00                 push 0
// 006ad3ad  52                   push edx
// 006ad3ae  50                   push eax
// 006ad3af  56                   push esi
// 006ad3b0  50                   push eax
// 006ad3b1  e81a6be8ff           call 0x533ed0
// 006ad3b6  8be8                 mov ebp, eax
// 006ad3b8  8b4718               mov eax, dword ptr [edi + 0x18]
// 006ad3bb  bb01000000           mov ebx, 1
// 006ad3c0  015f1c               add dword ptr [edi + 0x1c], ebx
// 006ad3c3  3bf0                 cmp esi, eax
// 006ad3c5  7510                 jne 0x6ad3d7
// 006ad3c7  896804               mov dword ptr [eax + 4], ebp
// 006ad3ca  8b4718               mov eax, dword ptr [edi + 0x18]
// 006ad3cd  8928                 mov dword ptr [eax], ebp
// 006ad3cf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006ad3d2  896908               mov dword ptr [ecx + 8], ebp
// 006ad3d5  eb22                 jmp 0x6ad3f9
// 006ad3d7  807c246800           cmp byte ptr [esp + 0x68], 0
// 006ad3dc  740d                 je 0x6ad3eb
// 006ad3de  892e                 mov dword ptr [esi], ebp
// 006ad3e0  8b4718               mov eax, dword ptr [edi + 0x18]
// 006ad3e3  3b30                 cmp esi, dword ptr [eax]
// 006ad3e5  7512                 jne 0x6ad3f9
// 006ad3e7  8928                 mov dword ptr [eax], ebp
// 006ad3e9  eb0e                 jmp 0x6ad3f9
// 006ad3eb  896e08               mov dword ptr [esi + 8], ebp
// 006ad3ee  8b4718               mov eax, dword ptr [edi + 0x18]
// 006ad3f1  3b7008               cmp esi, dword ptr [eax + 8]
// 006ad3f4  7503                 jne 0x6ad3f9
// 006ad3f6  896808               mov dword ptr [eax + 8], ebp
// 006ad3f9  8b5504               mov edx, dword ptr [ebp + 4]
// 006ad3fc  807a1400             cmp byte ptr [edx + 0x14], 0
// 006ad400  8d4504               lea eax, [ebp + 4]
// 006ad403  8bf5                 mov esi, ebp
// 006ad405  0f85ea000000         jne 0x6ad4f5
// 006ad40b  eb03                 jmp 0x6ad410
// 006ad40d  8d4900               lea ecx, [ecx]
// 006ad410  8b08                 mov ecx, dword ptr [eax]
// 006ad412  8b5104               mov edx, dword ptr [ecx + 4]
// 006ad415  3b0a                 cmp ecx, dword ptr [edx]
// 006ad417  7551                 jne 0x6ad46a
// 006ad419  8b5208               mov edx, dword ptr [edx + 8]
// 006ad41c  807a1400             cmp byte ptr [edx + 0x14], 0
// 006ad420  7519                 jne 0x6ad43b
// 006ad422  885914               mov byte ptr [ecx + 0x14], bl
// 006ad425  885a14               mov byte ptr [edx + 0x14], bl
// 006ad428  8b10                 mov edx, dword ptr [eax]
// 006ad42a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006ad42d  c6411400             mov byte ptr [ecx + 0x14], 0
// 006ad431  8b10                 mov edx, dword ptr [eax]
// 006ad433  8b7204               mov esi, dword ptr [edx + 4]
// 006ad436  e9aa000000           jmp 0x6ad4e5
// 006ad43b  3b7108               cmp esi, dword ptr [ecx + 8]
// 006ad43e  750a                 jne 0x6ad44a
// 006ad440  8bf1                 mov esi, ecx
// 006ad442  56                   push esi
// 006ad443  8bcf                 mov ecx, edi
// 006ad445  e8868d1300           call 0x7e61d0
// 006ad44a  8b4604               mov eax, dword ptr [esi + 4]
// 006ad44d  885814               mov byte ptr [eax + 0x14], bl
// 006ad450  8b4e04               mov ecx, dword ptr [esi + 4]
// 006ad453  8b5104               mov edx, dword ptr [ecx + 4]
// 006ad456  c6421400             mov byte ptr [edx + 0x14], 0
// 006ad45a  8b4604               mov eax, dword ptr [esi + 4]
// 006ad45d  8b4804               mov ecx, dword ptr [eax + 4]
// 006ad460  51                   push ecx
// 006ad461  8bcf                 mov ecx, edi
// 006ad463  e80879daff           call 0x454d70
// 006ad468  eb7b                 jmp 0x6ad4e5
// 006ad46a  8b12                 mov edx, dword ptr [edx]
// 006ad46c  807a1400             cmp byte ptr [edx + 0x14], 0
// 006ad470  7516                 jne 0x6ad488
// 006ad472  885914               mov byte ptr [ecx + 0x14], bl
// 006ad475  885a14               mov byte ptr [edx + 0x14], bl
// 006ad478  8b10                 mov edx, dword ptr [eax]
// 006ad47a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006ad47d  c6411400             mov byte ptr [ecx + 0x14], 0
// 006ad481  8b10                 mov edx, dword ptr [eax]
// 006ad483  8b7204               mov esi, dword ptr [edx + 4]
// 006ad486  eb5d                 jmp 0x6ad4e5
// 006ad488  3b31                 cmp esi, dword ptr [ecx]
// 006ad48a  750a                 jne 0x6ad496
// 006ad48c  8bf1                 mov esi, ecx
// 006ad48e  56                   push esi
// 006ad48f  8bcf                 mov ecx, edi
// 006ad491  e8da78daff           call 0x454d70
// 006ad496  8b4604               mov eax, dword ptr [esi + 4]
// 006ad499  885814               mov byte ptr [eax + 0x14], bl
// 006ad49c  8b4e04               mov ecx, dword ptr [esi + 4]
// 006ad49f  8b5104               mov edx, dword ptr [ecx + 4]
// 006ad4a2  c6421400             mov byte ptr [edx + 0x14], 0
// 006ad4a6  8b4604               mov eax, dword ptr [esi + 4]
// 006ad4a9  8b4004               mov eax, dword ptr [eax + 4]
// 006ad4ac  8b4808               mov ecx, dword ptr [eax + 8]
// 006ad4af  8b11                 mov edx, dword ptr [ecx]
// 006ad4b1  895008               mov dword ptr [eax + 8], edx
// 006ad4b4  8b11                 mov edx, dword ptr [ecx]
// 006ad4b6  807a1500             cmp byte ptr [edx + 0x15], 0
// 006ad4ba  7503                 jne 0x6ad4bf
// 006ad4bc  894204               mov dword ptr [edx + 4], eax
// 006ad4bf  8b5004               mov edx, dword ptr [eax + 4]
// 006ad4c2  895104               mov dword ptr [ecx + 4], edx
// 006ad4c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006ad4c8  3b4204               cmp eax, dword ptr [edx + 4]
// 006ad4cb  7505                 jne 0x6ad4d2
// 006ad4cd  894a04               mov dword ptr [edx + 4], ecx
// 006ad4d0  eb0e                 jmp 0x6ad4e0
// 006ad4d2  8b5004               mov edx, dword ptr [eax + 4]
// 006ad4d5  3b02                 cmp eax, dword ptr [edx]
// 006ad4d7  7504                 jne 0x6ad4dd
// 006ad4d9  890a                 mov dword ptr [edx], ecx
// 006ad4db  eb03                 jmp 0x6ad4e0
// 006ad4dd  894a08               mov dword ptr [edx + 8], ecx
// 006ad4e0  8901                 mov dword ptr [ecx], eax
// 006ad4e2  894804               mov dword ptr [eax + 4], ecx
// 006ad4e5  8b4e04               mov ecx, dword ptr [esi + 4]
// 006ad4e8  80791400             cmp byte ptr [ecx + 0x14], 0
// 006ad4ec  8d4604               lea eax, [esi + 4]
// 006ad4ef  0f841bffffff         je 0x6ad410
// 006ad4f5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006ad4f8  8b4204               mov eax, dword ptr [edx + 4]
// 006ad4fb  885814               mov byte ptr [eax + 0x14], bl
// 006ad4fe  8b442464             mov eax, dword ptr [esp + 0x64]
// 006ad502  8b0f                 mov ecx, dword ptr [edi]
// 006ad504  5e                   pop esi
// 006ad505  896804               mov dword ptr [eax + 4], ebp
// 006ad508  5d                   pop ebp
// 006ad509  8908                 mov dword ptr [eax], ecx
// 006ad50b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006ad50f  5b                   pop ebx
// 006ad510  5f                   pop edi
// 006ad511  64890d00000000       mov dword ptr fs:[0], ecx
// 006ad518  83c450               add esp, 0x50
// 006ad51b  c21000               ret 0x10
// standard library map_int<ptr> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
