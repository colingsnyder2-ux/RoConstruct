// from server: 100% by auto
// roc 2009-06 0060a110  unit: RBX::GlobalSettings  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0060a110
//
// 0060a110  64a100000000         mov eax, dword ptr fs:[0]
// 0060a116  6aff                 push -1
// 0060a118  68b2db8500           push 0x85dbb2
// 0060a11d  50                   push eax
// 0060a11e  64892500000000       mov dword ptr fs:[0], esp
// 0060a125  83ec44               sub esp, 0x44
// 0060a128  57                   push edi
// 0060a129  8bf9                 mov edi, ecx
// 0060a12b  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 0060a132  7259                 jb 0x60a18d
// 0060a134  68c0c98a00           push 0x8ac9c0
// 0060a139  8d4c2408             lea ecx, [esp + 8]
// 0060a13d  ff15b4e48900         call dword ptr [0x89e4b4]
// 0060a143  8d4c2420             lea ecx, [esp + 0x20]
// 0060a147  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0060a14f  ff15b8e98900         call dword ptr [0x89e9b8]
// 0060a155  8d442404             lea eax, [esp + 4]
// 0060a159  50                   push eax
// 0060a15a  8d4c2430             lea ecx, [esp + 0x30]
// 0060a15e  c644245401           mov byte ptr [esp + 0x54], 1
// 0060a163  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 0060a16b  ff15b8e48900         call dword ptr [0x89e4b8]
// 0060a171  6834929700           push 0x979234
// 0060a176  8d4c2424             lea ecx, [esp + 0x24]
// 0060a17a  51                   push ecx
// 0060a17b  c644245800           mov byte ptr [esp + 0x58], 0
// 0060a180  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 0060a188  e8bdf81000           call 0x719a4a
// 0060a18d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0060a191  8b4718               mov eax, dword ptr [edi + 0x18]
// 0060a194  53                   push ebx
// 0060a195  55                   push ebp
// 0060a196  56                   push esi
// 0060a197  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0060a19b  6a00                 push 0
// 0060a19d  52                   push edx
// 0060a19e  50                   push eax
// 0060a19f  56                   push esi
// 0060a1a0  50                   push eax
// 0060a1a1  e88afeffff           call 0x60a030
// 0060a1a6  8be8                 mov ebp, eax
// 0060a1a8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0060a1ab  bb01000000           mov ebx, 1
// 0060a1b0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0060a1b3  3bf0                 cmp esi, eax
// 0060a1b5  7510                 jne 0x60a1c7
// 0060a1b7  896804               mov dword ptr [eax + 4], ebp
// 0060a1ba  8b4718               mov eax, dword ptr [edi + 0x18]
// 0060a1bd  8928                 mov dword ptr [eax], ebp
// 0060a1bf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0060a1c2  896908               mov dword ptr [ecx + 8], ebp
// 0060a1c5  eb22                 jmp 0x60a1e9
// 0060a1c7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0060a1cc  740d                 je 0x60a1db
// 0060a1ce  892e                 mov dword ptr [esi], ebp
// 0060a1d0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0060a1d3  3b30                 cmp esi, dword ptr [eax]
// 0060a1d5  7512                 jne 0x60a1e9
// 0060a1d7  8928                 mov dword ptr [eax], ebp
// 0060a1d9  eb0e                 jmp 0x60a1e9
// 0060a1db  896e08               mov dword ptr [esi + 8], ebp
// 0060a1de  8b4718               mov eax, dword ptr [edi + 0x18]
// 0060a1e1  3b7008               cmp esi, dword ptr [eax + 8]
// 0060a1e4  7503                 jne 0x60a1e9
// 0060a1e6  896808               mov dword ptr [eax + 8], ebp
// 0060a1e9  8b5504               mov edx, dword ptr [ebp + 4]
// 0060a1ec  807a1800             cmp byte ptr [edx + 0x18], 0
// 0060a1f0  8d4504               lea eax, [ebp + 4]
// 0060a1f3  8bf5                 mov esi, ebp
// 0060a1f5  0f85ea000000         jne 0x60a2e5
// 0060a1fb  eb03                 jmp 0x60a200
// 0060a1fd  8d4900               lea ecx, [ecx]
// 0060a200  8b08                 mov ecx, dword ptr [eax]
// 0060a202  8b5104               mov edx, dword ptr [ecx + 4]
// 0060a205  3b0a                 cmp ecx, dword ptr [edx]
// 0060a207  7551                 jne 0x60a25a
// 0060a209  8b5208               mov edx, dword ptr [edx + 8]
// 0060a20c  807a1800             cmp byte ptr [edx + 0x18], 0
// 0060a210  7519                 jne 0x60a22b
// 0060a212  885918               mov byte ptr [ecx + 0x18], bl
// 0060a215  885a18               mov byte ptr [edx + 0x18], bl
// 0060a218  8b10                 mov edx, dword ptr [eax]
// 0060a21a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0060a21d  c6411800             mov byte ptr [ecx + 0x18], 0
// 0060a221  8b10                 mov edx, dword ptr [eax]
// 0060a223  8b7204               mov esi, dword ptr [edx + 4]
// 0060a226  e9aa000000           jmp 0x60a2d5
// 0060a22b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0060a22e  750a                 jne 0x60a23a
// 0060a230  8bf1                 mov esi, ecx
// 0060a232  56                   push esi
// 0060a233  8bcf                 mov ecx, edi
// 0060a235  e806e40000           call 0x618640
// 0060a23a  8b4604               mov eax, dword ptr [esi + 4]
// 0060a23d  885818               mov byte ptr [eax + 0x18], bl
// 0060a240  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060a243  8b5104               mov edx, dword ptr [ecx + 4]
// 0060a246  c6421800             mov byte ptr [edx + 0x18], 0
// 0060a24a  8b4604               mov eax, dword ptr [esi + 4]
// 0060a24d  8b4804               mov ecx, dword ptr [eax + 4]
// 0060a250  51                   push ecx
// 0060a251  8bcf                 mov ecx, edi
// 0060a253  e868980300           call 0x643ac0
// 0060a258  eb7b                 jmp 0x60a2d5
// 0060a25a  8b12                 mov edx, dword ptr [edx]
// 0060a25c  807a1800             cmp byte ptr [edx + 0x18], 0
// 0060a260  7516                 jne 0x60a278
// 0060a262  885918               mov byte ptr [ecx + 0x18], bl
// 0060a265  885a18               mov byte ptr [edx + 0x18], bl
// 0060a268  8b10                 mov edx, dword ptr [eax]
// 0060a26a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0060a26d  c6411800             mov byte ptr [ecx + 0x18], 0
// 0060a271  8b10                 mov edx, dword ptr [eax]
// 0060a273  8b7204               mov esi, dword ptr [edx + 4]
// 0060a276  eb5d                 jmp 0x60a2d5
// 0060a278  3b31                 cmp esi, dword ptr [ecx]
// 0060a27a  750a                 jne 0x60a286
// 0060a27c  8bf1                 mov esi, ecx
// 0060a27e  56                   push esi
// 0060a27f  8bcf                 mov ecx, edi
// 0060a281  e83a980300           call 0x643ac0
// 0060a286  8b4604               mov eax, dword ptr [esi + 4]
// 0060a289  885818               mov byte ptr [eax + 0x18], bl
// 0060a28c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060a28f  8b5104               mov edx, dword ptr [ecx + 4]
// 0060a292  c6421800             mov byte ptr [edx + 0x18], 0
// 0060a296  8b4604               mov eax, dword ptr [esi + 4]
// 0060a299  8b4004               mov eax, dword ptr [eax + 4]
// 0060a29c  8b4808               mov ecx, dword ptr [eax + 8]
// 0060a29f  8b11                 mov edx, dword ptr [ecx]
// 0060a2a1  895008               mov dword ptr [eax + 8], edx
// 0060a2a4  8b11                 mov edx, dword ptr [ecx]
// 0060a2a6  807a1900             cmp byte ptr [edx + 0x19], 0
// 0060a2aa  7503                 jne 0x60a2af
// 0060a2ac  894204               mov dword ptr [edx + 4], eax
// 0060a2af  8b5004               mov edx, dword ptr [eax + 4]
// 0060a2b2  895104               mov dword ptr [ecx + 4], edx
// 0060a2b5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0060a2b8  3b4204               cmp eax, dword ptr [edx + 4]
// 0060a2bb  7505                 jne 0x60a2c2
// 0060a2bd  894a04               mov dword ptr [edx + 4], ecx
// 0060a2c0  eb0e                 jmp 0x60a2d0
// 0060a2c2  8b5004               mov edx, dword ptr [eax + 4]
// 0060a2c5  3b02                 cmp eax, dword ptr [edx]
// 0060a2c7  7504                 jne 0x60a2cd
// 0060a2c9  890a                 mov dword ptr [edx], ecx
// 0060a2cb  eb03                 jmp 0x60a2d0
// 0060a2cd  894a08               mov dword ptr [edx + 8], ecx
// 0060a2d0  8901                 mov dword ptr [ecx], eax
// 0060a2d2  894804               mov dword ptr [eax + 4], ecx
// 0060a2d5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060a2d8  80791800             cmp byte ptr [ecx + 0x18], 0
// 0060a2dc  8d4604               lea eax, [esi + 4]
// 0060a2df  0f841bffffff         je 0x60a200
// 0060a2e5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0060a2e8  8b4204               mov eax, dword ptr [edx + 4]
// 0060a2eb  885818               mov byte ptr [eax + 0x18], bl
// 0060a2ee  8b442464             mov eax, dword ptr [esp + 0x64]
// 0060a2f2  8b0f                 mov ecx, dword ptr [edi]
// 0060a2f4  5e                   pop esi
// 0060a2f5  896804               mov dword ptr [eax + 4], ebp
// 0060a2f8  5d                   pop ebp
// 0060a2f9  8908                 mov dword ptr [eax], ecx
// 0060a2fb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0060a2ff  5b                   pop ebx
// 0060a300  5f                   pop edi
// 0060a301  64890d00000000       mov dword ptr fs:[0], ecx
// 0060a308  83c450               add esp, 0x50
// 0060a30b  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
