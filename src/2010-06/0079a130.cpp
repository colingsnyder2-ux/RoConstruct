// from server: 100% by auto
// roc 2010-06 0079a130  unit: RBX::VCEvent::?$sp_counted_impl_p  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0079a130
//
// 0079a130  64a100000000         mov eax, dword ptr fs:[0]
// 0079a136  6aff                 push -1
// 0079a138  68e22f9a00           push 0x9a2fe2
// 0079a13d  50                   push eax
// 0079a13e  64892500000000       mov dword ptr fs:[0], esp
// 0079a145  83ec44               sub esp, 0x44
// 0079a148  57                   push edi
// 0079a149  8bf9                 mov edi, ecx
// 0079a14b  817f1cfeffff1f       cmp dword ptr [edi + 0x1c], 0x1ffffffe
// 0079a152  7259                 jb 0x79a1ad
// 0079a154  68a800a000           push 0xa000a8
// 0079a159  8d4c2408             lea ecx, [esp + 8]
// 0079a15d  ff1510a49e00         call dword ptr [0x9ea410]
// 0079a163  8d4c2420             lea ecx, [esp + 0x20]
// 0079a167  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0079a16f  ff1518a99e00         call dword ptr [0x9ea918]
// 0079a175  8d442404             lea eax, [esp + 4]
// 0079a179  50                   push eax
// 0079a17a  8d4c2430             lea ecx, [esp + 0x30]
// 0079a17e  c644245401           mov byte ptr [esp + 0x54], 1
// 0079a183  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 0079a18b  ff150ca49e00         call dword ptr [0x9ea40c]
// 0079a191  68601bb000           push 0xb01b60
// 0079a196  8d4c2424             lea ecx, [esp + 0x24]
// 0079a19a  51                   push ecx
// 0079a19b  c644245800           mov byte ptr [esp + 0x58], 0
// 0079a1a0  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 0079a1a8  e805e80000           call 0x7a89b2
// 0079a1ad  8b542464             mov edx, dword ptr [esp + 0x64]
// 0079a1b1  8b4718               mov eax, dword ptr [edi + 0x18]
// 0079a1b4  53                   push ebx
// 0079a1b5  55                   push ebp
// 0079a1b6  56                   push esi
// 0079a1b7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0079a1bb  6a00                 push 0
// 0079a1bd  52                   push edx
// 0079a1be  50                   push eax
// 0079a1bf  56                   push esi
// 0079a1c0  50                   push eax
// 0079a1c1  e86a45c8ff           call 0x41e730
// 0079a1c6  8be8                 mov ebp, eax
// 0079a1c8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0079a1cb  bb01000000           mov ebx, 1
// 0079a1d0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0079a1d3  3bf0                 cmp esi, eax
// 0079a1d5  7510                 jne 0x79a1e7
// 0079a1d7  896804               mov dword ptr [eax + 4], ebp
// 0079a1da  8b4718               mov eax, dword ptr [edi + 0x18]
// 0079a1dd  8928                 mov dword ptr [eax], ebp
// 0079a1df  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0079a1e2  896908               mov dword ptr [ecx + 8], ebp
// 0079a1e5  eb22                 jmp 0x79a209
// 0079a1e7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0079a1ec  740d                 je 0x79a1fb
// 0079a1ee  892e                 mov dword ptr [esi], ebp
// 0079a1f0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0079a1f3  3b30                 cmp esi, dword ptr [eax]
// 0079a1f5  7512                 jne 0x79a209
// 0079a1f7  8928                 mov dword ptr [eax], ebp
// 0079a1f9  eb0e                 jmp 0x79a209
// 0079a1fb  896e08               mov dword ptr [esi + 8], ebp
// 0079a1fe  8b4718               mov eax, dword ptr [edi + 0x18]
// 0079a201  3b7008               cmp esi, dword ptr [eax + 8]
// 0079a204  7503                 jne 0x79a209
// 0079a206  896808               mov dword ptr [eax + 8], ebp
// 0079a209  8b5504               mov edx, dword ptr [ebp + 4]
// 0079a20c  807a1400             cmp byte ptr [edx + 0x14], 0
// 0079a210  8d4504               lea eax, [ebp + 4]
// 0079a213  8bf5                 mov esi, ebp
// 0079a215  0f85ea000000         jne 0x79a305
// 0079a21b  eb03                 jmp 0x79a220
// 0079a21d  8d4900               lea ecx, [ecx]
// 0079a220  8b08                 mov ecx, dword ptr [eax]
// 0079a222  8b5104               mov edx, dword ptr [ecx + 4]
// 0079a225  3b0a                 cmp ecx, dword ptr [edx]
// 0079a227  7551                 jne 0x79a27a
// 0079a229  8b5208               mov edx, dword ptr [edx + 8]
// 0079a22c  807a1400             cmp byte ptr [edx + 0x14], 0
// 0079a230  7519                 jne 0x79a24b
// 0079a232  885914               mov byte ptr [ecx + 0x14], bl
// 0079a235  885a14               mov byte ptr [edx + 0x14], bl
// 0079a238  8b10                 mov edx, dword ptr [eax]
// 0079a23a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0079a23d  c6411400             mov byte ptr [ecx + 0x14], 0
// 0079a241  8b10                 mov edx, dword ptr [eax]
// 0079a243  8b7204               mov esi, dword ptr [edx + 4]
// 0079a246  e9aa000000           jmp 0x79a2f5
// 0079a24b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0079a24e  750a                 jne 0x79a25a
// 0079a250  8bf1                 mov esi, ecx
// 0079a252  56                   push esi
// 0079a253  8bcf                 mov ecx, edi
// 0079a255  e8c620e1ff           call 0x5ac320
// 0079a25a  8b4604               mov eax, dword ptr [esi + 4]
// 0079a25d  885814               mov byte ptr [eax + 0x14], bl
// 0079a260  8b4e04               mov ecx, dword ptr [esi + 4]
// 0079a263  8b5104               mov edx, dword ptr [ecx + 4]
// 0079a266  c6421400             mov byte ptr [edx + 0x14], 0
// 0079a26a  8b4604               mov eax, dword ptr [esi + 4]
// 0079a26d  8b4804               mov ecx, dword ptr [eax + 4]
// 0079a270  51                   push ecx
// 0079a271  8bcf                 mov ecx, edi
// 0079a273  e888e9e2ff           call 0x5c8c00
// 0079a278  eb7b                 jmp 0x79a2f5
// 0079a27a  8b12                 mov edx, dword ptr [edx]
// 0079a27c  807a1400             cmp byte ptr [edx + 0x14], 0
// 0079a280  7516                 jne 0x79a298
// 0079a282  885914               mov byte ptr [ecx + 0x14], bl
// 0079a285  885a14               mov byte ptr [edx + 0x14], bl
// 0079a288  8b10                 mov edx, dword ptr [eax]
// 0079a28a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0079a28d  c6411400             mov byte ptr [ecx + 0x14], 0
// 0079a291  8b10                 mov edx, dword ptr [eax]
// 0079a293  8b7204               mov esi, dword ptr [edx + 4]
// 0079a296  eb5d                 jmp 0x79a2f5
// 0079a298  3b31                 cmp esi, dword ptr [ecx]
// 0079a29a  750a                 jne 0x79a2a6
// 0079a29c  8bf1                 mov esi, ecx
// 0079a29e  56                   push esi
// 0079a29f  8bcf                 mov ecx, edi
// 0079a2a1  e85ae9e2ff           call 0x5c8c00
// 0079a2a6  8b4604               mov eax, dword ptr [esi + 4]
// 0079a2a9  885814               mov byte ptr [eax + 0x14], bl
// 0079a2ac  8b4e04               mov ecx, dword ptr [esi + 4]
// 0079a2af  8b5104               mov edx, dword ptr [ecx + 4]
// 0079a2b2  c6421400             mov byte ptr [edx + 0x14], 0
// 0079a2b6  8b4604               mov eax, dword ptr [esi + 4]
// 0079a2b9  8b4004               mov eax, dword ptr [eax + 4]
// 0079a2bc  8b4808               mov ecx, dword ptr [eax + 8]
// 0079a2bf  8b11                 mov edx, dword ptr [ecx]
// 0079a2c1  895008               mov dword ptr [eax + 8], edx
// 0079a2c4  8b11                 mov edx, dword ptr [ecx]
// 0079a2c6  807a1500             cmp byte ptr [edx + 0x15], 0
// 0079a2ca  7503                 jne 0x79a2cf
// 0079a2cc  894204               mov dword ptr [edx + 4], eax
// 0079a2cf  8b5004               mov edx, dword ptr [eax + 4]
// 0079a2d2  895104               mov dword ptr [ecx + 4], edx
// 0079a2d5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0079a2d8  3b4204               cmp eax, dword ptr [edx + 4]
// 0079a2db  7505                 jne 0x79a2e2
// 0079a2dd  894a04               mov dword ptr [edx + 4], ecx
// 0079a2e0  eb0e                 jmp 0x79a2f0
// 0079a2e2  8b5004               mov edx, dword ptr [eax + 4]
// 0079a2e5  3b02                 cmp eax, dword ptr [edx]
// 0079a2e7  7504                 jne 0x79a2ed
// 0079a2e9  890a                 mov dword ptr [edx], ecx
// 0079a2eb  eb03                 jmp 0x79a2f0
// 0079a2ed  894a08               mov dword ptr [edx + 8], ecx
// 0079a2f0  8901                 mov dword ptr [ecx], eax
// 0079a2f2  894804               mov dword ptr [eax + 4], ecx
// 0079a2f5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0079a2f8  80791400             cmp byte ptr [ecx + 0x14], 0
// 0079a2fc  8d4604               lea eax, [esi + 4]
// 0079a2ff  0f841bffffff         je 0x79a220
// 0079a305  8b5718               mov edx, dword ptr [edi + 0x18]
// 0079a308  8b4204               mov eax, dword ptr [edx + 4]
// 0079a30b  885814               mov byte ptr [eax + 0x14], bl
// 0079a30e  8b442464             mov eax, dword ptr [esp + 0x64]
// 0079a312  8b0f                 mov ecx, dword ptr [edi]
// 0079a314  5e                   pop esi
// 0079a315  896804               mov dword ptr [eax + 4], ebp
// 0079a318  5d                   pop ebp
// 0079a319  8908                 mov dword ptr [eax], ecx
// 0079a31b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0079a31f  5b                   pop ebx
// 0079a320  5f                   pop edi
// 0079a321  64890d00000000       mov dword ptr fs:[0], ecx
// 0079a328  83c450               add esp, 0x50
// 0079a32b  c21000               ret 0x10
// standard library map_int<ptr> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
