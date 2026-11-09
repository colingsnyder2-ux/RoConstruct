// from server: 100% by auto
// roc 2009-06 00515930  unit: seg_00510000  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00515930
//
// 00515930  64a100000000         mov eax, dword ptr fs:[0]
// 00515936  6aff                 push -1
// 00515938  68b2db8500           push 0x85dbb2
// 0051593d  50                   push eax
// 0051593e  64892500000000       mov dword ptr fs:[0], esp
// 00515945  83ec44               sub esp, 0x44
// 00515948  57                   push edi
// 00515949  8bf9                 mov edi, ecx
// 0051594b  817f1ca9aaaa0a       cmp dword ptr [edi + 0x1c], 0xaaaaaa9
// 00515952  7259                 jb 0x5159ad
// 00515954  68c0c98a00           push 0x8ac9c0
// 00515959  8d4c2408             lea ecx, [esp + 8]
// 0051595d  ff15b4e48900         call dword ptr [0x89e4b4]
// 00515963  8d4c2420             lea ecx, [esp + 0x20]
// 00515967  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0051596f  ff15b8e98900         call dword ptr [0x89e9b8]
// 00515975  8d442404             lea eax, [esp + 4]
// 00515979  50                   push eax
// 0051597a  8d4c2430             lea ecx, [esp + 0x30]
// 0051597e  c644245401           mov byte ptr [esp + 0x54], 1
// 00515983  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 0051598b  ff15b8e48900         call dword ptr [0x89e4b8]
// 00515991  6834929700           push 0x979234
// 00515996  8d4c2424             lea ecx, [esp + 0x24]
// 0051599a  51                   push ecx
// 0051599b  c644245800           mov byte ptr [esp + 0x58], 0
// 005159a0  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 005159a8  e89d402000           call 0x719a4a
// 005159ad  8b542464             mov edx, dword ptr [esp + 0x64]
// 005159b1  8b4718               mov eax, dword ptr [edi + 0x18]
// 005159b4  53                   push ebx
// 005159b5  55                   push ebp
// 005159b6  56                   push esi
// 005159b7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005159bb  6a00                 push 0
// 005159bd  52                   push edx
// 005159be  50                   push eax
// 005159bf  56                   push esi
// 005159c0  50                   push eax
// 005159c1  e85afeffff           call 0x515820
// 005159c6  8be8                 mov ebp, eax
// 005159c8  8b4718               mov eax, dword ptr [edi + 0x18]
// 005159cb  bb01000000           mov ebx, 1
// 005159d0  015f1c               add dword ptr [edi + 0x1c], ebx
// 005159d3  3bf0                 cmp esi, eax
// 005159d5  7510                 jne 0x5159e7
// 005159d7  896804               mov dword ptr [eax + 4], ebp
// 005159da  8b4718               mov eax, dword ptr [edi + 0x18]
// 005159dd  8928                 mov dword ptr [eax], ebp
// 005159df  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005159e2  896908               mov dword ptr [ecx + 8], ebp
// 005159e5  eb22                 jmp 0x515a09
// 005159e7  807c246800           cmp byte ptr [esp + 0x68], 0
// 005159ec  740d                 je 0x5159fb
// 005159ee  892e                 mov dword ptr [esi], ebp
// 005159f0  8b4718               mov eax, dword ptr [edi + 0x18]
// 005159f3  3b30                 cmp esi, dword ptr [eax]
// 005159f5  7512                 jne 0x515a09
// 005159f7  8928                 mov dword ptr [eax], ebp
// 005159f9  eb0e                 jmp 0x515a09
// 005159fb  896e08               mov dword ptr [esi + 8], ebp
// 005159fe  8b4718               mov eax, dword ptr [edi + 0x18]
// 00515a01  3b7008               cmp esi, dword ptr [eax + 8]
// 00515a04  7503                 jne 0x515a09
// 00515a06  896808               mov dword ptr [eax + 8], ebp
// 00515a09  8b5504               mov edx, dword ptr [ebp + 4]
// 00515a0c  807a2400             cmp byte ptr [edx + 0x24], 0
// 00515a10  8d4504               lea eax, [ebp + 4]
// 00515a13  8bf5                 mov esi, ebp
// 00515a15  0f85ea000000         jne 0x515b05
// 00515a1b  eb03                 jmp 0x515a20
// 00515a1d  8d4900               lea ecx, [ecx]
// 00515a20  8b08                 mov ecx, dword ptr [eax]
// 00515a22  8b5104               mov edx, dword ptr [ecx + 4]
// 00515a25  3b0a                 cmp ecx, dword ptr [edx]
// 00515a27  7551                 jne 0x515a7a
// 00515a29  8b5208               mov edx, dword ptr [edx + 8]
// 00515a2c  807a2400             cmp byte ptr [edx + 0x24], 0
// 00515a30  7519                 jne 0x515a4b
// 00515a32  885924               mov byte ptr [ecx + 0x24], bl
// 00515a35  885a24               mov byte ptr [edx + 0x24], bl
// 00515a38  8b10                 mov edx, dword ptr [eax]
// 00515a3a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00515a3d  c6412400             mov byte ptr [ecx + 0x24], 0
// 00515a41  8b10                 mov edx, dword ptr [eax]
// 00515a43  8b7204               mov esi, dword ptr [edx + 4]
// 00515a46  e9aa000000           jmp 0x515af5
// 00515a4b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00515a4e  750a                 jne 0x515a5a
// 00515a50  8bf1                 mov esi, ecx
// 00515a52  56                   push esi
// 00515a53  8bcf                 mov ecx, edi
// 00515a55  e866fef2ff           call 0x4458c0
// 00515a5a  8b4604               mov eax, dword ptr [esi + 4]
// 00515a5d  885824               mov byte ptr [eax + 0x24], bl
// 00515a60  8b4e04               mov ecx, dword ptr [esi + 4]
// 00515a63  8b5104               mov edx, dword ptr [ecx + 4]
// 00515a66  c6422400             mov byte ptr [edx + 0x24], 0
// 00515a6a  8b4604               mov eax, dword ptr [esi + 4]
// 00515a6d  8b4804               mov ecx, dword ptr [eax + 4]
// 00515a70  51                   push ecx
// 00515a71  8bcf                 mov ecx, edi
// 00515a73  e8d8fef2ff           call 0x445950
// 00515a78  eb7b                 jmp 0x515af5
// 00515a7a  8b12                 mov edx, dword ptr [edx]
// 00515a7c  807a2400             cmp byte ptr [edx + 0x24], 0
// 00515a80  7516                 jne 0x515a98
// 00515a82  885924               mov byte ptr [ecx + 0x24], bl
// 00515a85  885a24               mov byte ptr [edx + 0x24], bl
// 00515a88  8b10                 mov edx, dword ptr [eax]
// 00515a8a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00515a8d  c6412400             mov byte ptr [ecx + 0x24], 0
// 00515a91  8b10                 mov edx, dword ptr [eax]
// 00515a93  8b7204               mov esi, dword ptr [edx + 4]
// 00515a96  eb5d                 jmp 0x515af5
// 00515a98  3b31                 cmp esi, dword ptr [ecx]
// 00515a9a  750a                 jne 0x515aa6
// 00515a9c  8bf1                 mov esi, ecx
// 00515a9e  56                   push esi
// 00515a9f  8bcf                 mov ecx, edi
// 00515aa1  e8aafef2ff           call 0x445950
// 00515aa6  8b4604               mov eax, dword ptr [esi + 4]
// 00515aa9  885824               mov byte ptr [eax + 0x24], bl
// 00515aac  8b4e04               mov ecx, dword ptr [esi + 4]
// 00515aaf  8b5104               mov edx, dword ptr [ecx + 4]
// 00515ab2  c6422400             mov byte ptr [edx + 0x24], 0
// 00515ab6  8b4604               mov eax, dword ptr [esi + 4]
// 00515ab9  8b4004               mov eax, dword ptr [eax + 4]
// 00515abc  8b4808               mov ecx, dword ptr [eax + 8]
// 00515abf  8b11                 mov edx, dword ptr [ecx]
// 00515ac1  895008               mov dword ptr [eax + 8], edx
// 00515ac4  8b11                 mov edx, dword ptr [ecx]
// 00515ac6  807a2500             cmp byte ptr [edx + 0x25], 0
// 00515aca  7503                 jne 0x515acf
// 00515acc  894204               mov dword ptr [edx + 4], eax
// 00515acf  8b5004               mov edx, dword ptr [eax + 4]
// 00515ad2  895104               mov dword ptr [ecx + 4], edx
// 00515ad5  8b5718               mov edx, dword ptr [edi + 0x18]
// 00515ad8  3b4204               cmp eax, dword ptr [edx + 4]
// 00515adb  7505                 jne 0x515ae2
// 00515add  894a04               mov dword ptr [edx + 4], ecx
// 00515ae0  eb0e                 jmp 0x515af0
// 00515ae2  8b5004               mov edx, dword ptr [eax + 4]
// 00515ae5  3b02                 cmp eax, dword ptr [edx]
// 00515ae7  7504                 jne 0x515aed
// 00515ae9  890a                 mov dword ptr [edx], ecx
// 00515aeb  eb03                 jmp 0x515af0
// 00515aed  894a08               mov dword ptr [edx + 8], ecx
// 00515af0  8901                 mov dword ptr [ecx], eax
// 00515af2  894804               mov dword ptr [eax + 4], ecx
// 00515af5  8b4e04               mov ecx, dword ptr [esi + 4]
// 00515af8  80792400             cmp byte ptr [ecx + 0x24], 0
// 00515afc  8d4604               lea eax, [esi + 4]
// 00515aff  0f841bffffff         je 0x515a20
// 00515b05  8b5718               mov edx, dword ptr [edi + 0x18]
// 00515b08  8b4204               mov eax, dword ptr [edx + 4]
// 00515b0b  885824               mov byte ptr [eax + 0x24], bl
// 00515b0e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00515b12  8b0f                 mov ecx, dword ptr [edi]
// 00515b14  5e                   pop esi
// 00515b15  896804               mov dword ptr [eax + 4], ebp
// 00515b18  5d                   pop ebp
// 00515b19  8908                 mov dword ptr [eax], ecx
// 00515b1b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00515b1f  5b                   pop ebx
// 00515b20  5f                   pop edi
// 00515b21  64890d00000000       mov dword ptr fs:[0], ecx
// 00515b28  83c450               add esp, 0x50
// 00515b2b  c21000               ret 0x10
// standard library map_int<pod20> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod20>
struct E { int v[5]; };
#include <map>
template class std::map<int, E>;
