// from server: 100% by auto
// roc 2010-06 004eaaf0  unit: RBX::Network::Replicator::ChangePropertyItem  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004eaaf0
//
// 004eaaf0  64a100000000         mov eax, dword ptr fs:[0]
// 004eaaf6  6aff                 push -1
// 004eaaf8  68e22f9a00           push 0x9a2fe2
// 004eaafd  50                   push eax
// 004eaafe  64892500000000       mov dword ptr fs:[0], esp
// 004eab05  83ec44               sub esp, 0x44
// 004eab08  57                   push edi
// 004eab09  8bf9                 mov edi, ecx
// 004eab0b  817f1c65666606       cmp dword ptr [edi + 0x1c], 0x6666665
// 004eab12  7259                 jb 0x4eab6d
// 004eab14  68a800a000           push 0xa000a8
// 004eab19  8d4c2408             lea ecx, [esp + 8]
// 004eab1d  ff1510a49e00         call dword ptr [0x9ea410]
// 004eab23  8d4c2420             lea ecx, [esp + 0x20]
// 004eab27  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004eab2f  ff1518a99e00         call dword ptr [0x9ea918]
// 004eab35  8d442404             lea eax, [esp + 4]
// 004eab39  50                   push eax
// 004eab3a  8d4c2430             lea ecx, [esp + 0x30]
// 004eab3e  c644245401           mov byte ptr [esp + 0x54], 1
// 004eab43  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 004eab4b  ff150ca49e00         call dword ptr [0x9ea40c]
// 004eab51  68601bb000           push 0xb01b60
// 004eab56  8d4c2424             lea ecx, [esp + 0x24]
// 004eab5a  51                   push ecx
// 004eab5b  c644245800           mov byte ptr [esp + 0x58], 0
// 004eab60  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 004eab68  e845de2b00           call 0x7a89b2
// 004eab6d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004eab71  8b4718               mov eax, dword ptr [edi + 0x18]
// 004eab74  53                   push ebx
// 004eab75  55                   push ebp
// 004eab76  56                   push esi
// 004eab77  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004eab7b  6a00                 push 0
// 004eab7d  52                   push edx
// 004eab7e  50                   push eax
// 004eab7f  56                   push esi
// 004eab80  50                   push eax
// 004eab81  e81ae4ffff           call 0x4e8fa0
// 004eab86  8be8                 mov ebp, eax
// 004eab88  8b4718               mov eax, dword ptr [edi + 0x18]
// 004eab8b  bb01000000           mov ebx, 1
// 004eab90  015f1c               add dword ptr [edi + 0x1c], ebx
// 004eab93  3bf0                 cmp esi, eax
// 004eab95  7510                 jne 0x4eaba7
// 004eab97  896804               mov dword ptr [eax + 4], ebp
// 004eab9a  8b4718               mov eax, dword ptr [edi + 0x18]
// 004eab9d  8928                 mov dword ptr [eax], ebp
// 004eab9f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004eaba2  896908               mov dword ptr [ecx + 8], ebp
// 004eaba5  eb22                 jmp 0x4eabc9
// 004eaba7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004eabac  740d                 je 0x4eabbb
// 004eabae  892e                 mov dword ptr [esi], ebp
// 004eabb0  8b4718               mov eax, dword ptr [edi + 0x18]
// 004eabb3  3b30                 cmp esi, dword ptr [eax]
// 004eabb5  7512                 jne 0x4eabc9
// 004eabb7  8928                 mov dword ptr [eax], ebp
// 004eabb9  eb0e                 jmp 0x4eabc9
// 004eabbb  896e08               mov dword ptr [esi + 8], ebp
// 004eabbe  8b4718               mov eax, dword ptr [edi + 0x18]
// 004eabc1  3b7008               cmp esi, dword ptr [eax + 8]
// 004eabc4  7503                 jne 0x4eabc9
// 004eabc6  896808               mov dword ptr [eax + 8], ebp
// 004eabc9  8b5504               mov edx, dword ptr [ebp + 4]
// 004eabcc  807a3400             cmp byte ptr [edx + 0x34], 0
// 004eabd0  8d4504               lea eax, [ebp + 4]
// 004eabd3  8bf5                 mov esi, ebp
// 004eabd5  0f85ea000000         jne 0x4eacc5
// 004eabdb  eb03                 jmp 0x4eabe0
// 004eabdd  8d4900               lea ecx, [ecx]
// 004eabe0  8b08                 mov ecx, dword ptr [eax]
// 004eabe2  8b5104               mov edx, dword ptr [ecx + 4]
// 004eabe5  3b0a                 cmp ecx, dword ptr [edx]
// 004eabe7  7551                 jne 0x4eac3a
// 004eabe9  8b5208               mov edx, dword ptr [edx + 8]
// 004eabec  807a3400             cmp byte ptr [edx + 0x34], 0
// 004eabf0  7519                 jne 0x4eac0b
// 004eabf2  885934               mov byte ptr [ecx + 0x34], bl
// 004eabf5  885a34               mov byte ptr [edx + 0x34], bl
// 004eabf8  8b10                 mov edx, dword ptr [eax]
// 004eabfa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004eabfd  c6413400             mov byte ptr [ecx + 0x34], 0
// 004eac01  8b10                 mov edx, dword ptr [eax]
// 004eac03  8b7204               mov esi, dword ptr [edx + 4]
// 004eac06  e9aa000000           jmp 0x4eacb5
// 004eac0b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004eac0e  750a                 jne 0x4eac1a
// 004eac10  8bf1                 mov esi, ecx
// 004eac12  56                   push esi
// 004eac13  8bcf                 mov ecx, edi
// 004eac15  e896501500           call 0x63fcb0
// 004eac1a  8b4604               mov eax, dword ptr [esi + 4]
// 004eac1d  885834               mov byte ptr [eax + 0x34], bl
// 004eac20  8b4e04               mov ecx, dword ptr [esi + 4]
// 004eac23  8b5104               mov edx, dword ptr [ecx + 4]
// 004eac26  c6423400             mov byte ptr [edx + 0x34], 0
// 004eac2a  8b4604               mov eax, dword ptr [esi + 4]
// 004eac2d  8b4804               mov ecx, dword ptr [eax + 4]
// 004eac30  51                   push ecx
// 004eac31  8bcf                 mov ecx, edi
// 004eac33  e8c8501500           call 0x63fd00
// 004eac38  eb7b                 jmp 0x4eacb5
// 004eac3a  8b12                 mov edx, dword ptr [edx]
// 004eac3c  807a3400             cmp byte ptr [edx + 0x34], 0
// 004eac40  7516                 jne 0x4eac58
// 004eac42  885934               mov byte ptr [ecx + 0x34], bl
// 004eac45  885a34               mov byte ptr [edx + 0x34], bl
// 004eac48  8b10                 mov edx, dword ptr [eax]
// 004eac4a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004eac4d  c6413400             mov byte ptr [ecx + 0x34], 0
// 004eac51  8b10                 mov edx, dword ptr [eax]
// 004eac53  8b7204               mov esi, dword ptr [edx + 4]
// 004eac56  eb5d                 jmp 0x4eacb5
// 004eac58  3b31                 cmp esi, dword ptr [ecx]
// 004eac5a  750a                 jne 0x4eac66
// 004eac5c  8bf1                 mov esi, ecx
// 004eac5e  56                   push esi
// 004eac5f  8bcf                 mov ecx, edi
// 004eac61  e89a501500           call 0x63fd00
// 004eac66  8b4604               mov eax, dword ptr [esi + 4]
// 004eac69  885834               mov byte ptr [eax + 0x34], bl
// 004eac6c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004eac6f  8b5104               mov edx, dword ptr [ecx + 4]
// 004eac72  c6423400             mov byte ptr [edx + 0x34], 0
// 004eac76  8b4604               mov eax, dword ptr [esi + 4]
// 004eac79  8b4004               mov eax, dword ptr [eax + 4]
// 004eac7c  8b4808               mov ecx, dword ptr [eax + 8]
// 004eac7f  8b11                 mov edx, dword ptr [ecx]
// 004eac81  895008               mov dword ptr [eax + 8], edx
// 004eac84  8b11                 mov edx, dword ptr [ecx]
// 004eac86  807a3500             cmp byte ptr [edx + 0x35], 0
// 004eac8a  7503                 jne 0x4eac8f
// 004eac8c  894204               mov dword ptr [edx + 4], eax
// 004eac8f  8b5004               mov edx, dword ptr [eax + 4]
// 004eac92  895104               mov dword ptr [ecx + 4], edx
// 004eac95  8b5718               mov edx, dword ptr [edi + 0x18]
// 004eac98  3b4204               cmp eax, dword ptr [edx + 4]
// 004eac9b  7505                 jne 0x4eaca2
// 004eac9d  894a04               mov dword ptr [edx + 4], ecx
// 004eaca0  eb0e                 jmp 0x4eacb0
// 004eaca2  8b5004               mov edx, dword ptr [eax + 4]
// 004eaca5  3b02                 cmp eax, dword ptr [edx]
// 004eaca7  7504                 jne 0x4eacad
// 004eaca9  890a                 mov dword ptr [edx], ecx
// 004eacab  eb03                 jmp 0x4eacb0
// 004eacad  894a08               mov dword ptr [edx + 8], ecx
// 004eacb0  8901                 mov dword ptr [ecx], eax
// 004eacb2  894804               mov dword ptr [eax + 4], ecx
// 004eacb5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004eacb8  80793400             cmp byte ptr [ecx + 0x34], 0
// 004eacbc  8d4604               lea eax, [esi + 4]
// 004eacbf  0f841bffffff         je 0x4eabe0
// 004eacc5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004eacc8  8b4204               mov eax, dword ptr [edx + 4]
// 004eaccb  885834               mov byte ptr [eax + 0x34], bl
// 004eacce  8b442464             mov eax, dword ptr [esp + 0x64]
// 004eacd2  8b0f                 mov ecx, dword ptr [edi]
// 004eacd4  5e                   pop esi
// 004eacd5  896804               mov dword ptr [eax + 4], ebp
// 004eacd8  5d                   pop ebp
// 004eacd9  8908                 mov dword ptr [eax], ecx
// 004eacdb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004eacdf  5b                   pop ebx
// 004eace0  5f                   pop edi
// 004eace1  64890d00000000       mov dword ptr fs:[0], ecx
// 004eace8  83c450               add esp, 0x50
// 004eaceb  c21000               ret 0x10
// standard library map_int<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
