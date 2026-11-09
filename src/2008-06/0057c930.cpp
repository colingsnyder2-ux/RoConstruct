// from server: 100% by auto
// roc 2008-06 0057c930  unit: RBX::VInstance::?$SignalDesc  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057c930
//
// 0057c930  64a100000000         mov eax, dword ptr fs:[0]
// 0057c936  6aff                 push -1
// 0057c938  6842e87d00           push 0x7de842
// 0057c93d  50                   push eax
// 0057c93e  64892500000000       mov dword ptr fs:[0], esp
// 0057c945  83ec44               sub esp, 0x44
// 0057c948  57                   push edi
// 0057c949  8bf9                 mov edi, ecx
// 0057c94b  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 0057c952  7259                 jb 0x57c9ad
// 0057c954  688cb28000           push 0x80b28c
// 0057c959  8d4c2408             lea ecx, [esp + 8]
// 0057c95d  ff1558248000         call dword ptr [0x802458]
// 0057c963  8d4c2420             lea ecx, [esp + 0x20]
// 0057c967  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0057c96f  ff1598288000         call dword ptr [0x802898]
// 0057c975  8d442404             lea eax, [esp + 4]
// 0057c979  50                   push eax
// 0057c97a  8d4c2430             lea ecx, [esp + 0x30]
// 0057c97e  c644245401           mov byte ptr [esp + 0x54], 1
// 0057c983  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 0057c98b  ff155c248000         call dword ptr [0x80245c]
// 0057c991  68c00c8d00           push 0x8d0cc0
// 0057c996  8d4c2424             lea ecx, [esp + 0x24]
// 0057c99a  51                   push ecx
// 0057c99b  c644245800           mov byte ptr [esp + 0x58], 0
// 0057c9a0  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 0057c9a8  e8df4b1200           call 0x6a158c
// 0057c9ad  8b542464             mov edx, dword ptr [esp + 0x64]
// 0057c9b1  8b4718               mov eax, dword ptr [edi + 0x18]
// 0057c9b4  53                   push ebx
// 0057c9b5  55                   push ebp
// 0057c9b6  56                   push esi
// 0057c9b7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0057c9bb  6a00                 push 0
// 0057c9bd  52                   push edx
// 0057c9be  50                   push eax
// 0057c9bf  56                   push esi
// 0057c9c0  50                   push eax
// 0057c9c1  e88afeffff           call 0x57c850
// 0057c9c6  8be8                 mov ebp, eax
// 0057c9c8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0057c9cb  bb01000000           mov ebx, 1
// 0057c9d0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0057c9d3  3bf0                 cmp esi, eax
// 0057c9d5  7510                 jne 0x57c9e7
// 0057c9d7  896804               mov dword ptr [eax + 4], ebp
// 0057c9da  8b4718               mov eax, dword ptr [edi + 0x18]
// 0057c9dd  8928                 mov dword ptr [eax], ebp
// 0057c9df  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0057c9e2  896908               mov dword ptr [ecx + 8], ebp
// 0057c9e5  eb22                 jmp 0x57ca09
// 0057c9e7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0057c9ec  740d                 je 0x57c9fb
// 0057c9ee  892e                 mov dword ptr [esi], ebp
// 0057c9f0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0057c9f3  3b30                 cmp esi, dword ptr [eax]
// 0057c9f5  7512                 jne 0x57ca09
// 0057c9f7  8928                 mov dword ptr [eax], ebp
// 0057c9f9  eb0e                 jmp 0x57ca09
// 0057c9fb  896e08               mov dword ptr [esi + 8], ebp
// 0057c9fe  8b4718               mov eax, dword ptr [edi + 0x18]
// 0057ca01  3b7008               cmp esi, dword ptr [eax + 8]
// 0057ca04  7503                 jne 0x57ca09
// 0057ca06  896808               mov dword ptr [eax + 8], ebp
// 0057ca09  8b5504               mov edx, dword ptr [ebp + 4]
// 0057ca0c  807a1800             cmp byte ptr [edx + 0x18], 0
// 0057ca10  8d4504               lea eax, [ebp + 4]
// 0057ca13  8bf5                 mov esi, ebp
// 0057ca15  0f85ea000000         jne 0x57cb05
// 0057ca1b  eb03                 jmp 0x57ca20
// 0057ca1d  8d4900               lea ecx, [ecx]
// 0057ca20  8b08                 mov ecx, dword ptr [eax]
// 0057ca22  8b5104               mov edx, dword ptr [ecx + 4]
// 0057ca25  3b0a                 cmp ecx, dword ptr [edx]
// 0057ca27  7551                 jne 0x57ca7a
// 0057ca29  8b5208               mov edx, dword ptr [edx + 8]
// 0057ca2c  807a1800             cmp byte ptr [edx + 0x18], 0
// 0057ca30  7519                 jne 0x57ca4b
// 0057ca32  885918               mov byte ptr [ecx + 0x18], bl
// 0057ca35  885a18               mov byte ptr [edx + 0x18], bl
// 0057ca38  8b10                 mov edx, dword ptr [eax]
// 0057ca3a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0057ca3d  c6411800             mov byte ptr [ecx + 0x18], 0
// 0057ca41  8b10                 mov edx, dword ptr [eax]
// 0057ca43  8b7204               mov esi, dword ptr [edx + 4]
// 0057ca46  e9aa000000           jmp 0x57caf5
// 0057ca4b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0057ca4e  750a                 jne 0x57ca5a
// 0057ca50  8bf1                 mov esi, ecx
// 0057ca52  56                   push esi
// 0057ca53  8bcf                 mov ecx, edi
// 0057ca55  e896f3f2ff           call 0x4abdf0
// 0057ca5a  8b4604               mov eax, dword ptr [esi + 4]
// 0057ca5d  885818               mov byte ptr [eax + 0x18], bl
// 0057ca60  8b4e04               mov ecx, dword ptr [esi + 4]
// 0057ca63  8b5104               mov edx, dword ptr [ecx + 4]
// 0057ca66  c6421800             mov byte ptr [edx + 0x18], 0
// 0057ca6a  8b4604               mov eax, dword ptr [esi + 4]
// 0057ca6d  8b4804               mov ecx, dword ptr [eax + 4]
// 0057ca70  51                   push ecx
// 0057ca71  8bcf                 mov ecx, edi
// 0057ca73  e8e8a80000           call 0x587360
// 0057ca78  eb7b                 jmp 0x57caf5
// 0057ca7a  8b12                 mov edx, dword ptr [edx]
// 0057ca7c  807a1800             cmp byte ptr [edx + 0x18], 0
// 0057ca80  7516                 jne 0x57ca98
// 0057ca82  885918               mov byte ptr [ecx + 0x18], bl
// 0057ca85  885a18               mov byte ptr [edx + 0x18], bl
// 0057ca88  8b10                 mov edx, dword ptr [eax]
// 0057ca8a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0057ca8d  c6411800             mov byte ptr [ecx + 0x18], 0
// 0057ca91  8b10                 mov edx, dword ptr [eax]
// 0057ca93  8b7204               mov esi, dword ptr [edx + 4]
// 0057ca96  eb5d                 jmp 0x57caf5
// 0057ca98  3b31                 cmp esi, dword ptr [ecx]
// 0057ca9a  750a                 jne 0x57caa6
// 0057ca9c  8bf1                 mov esi, ecx
// 0057ca9e  56                   push esi
// 0057ca9f  8bcf                 mov ecx, edi
// 0057caa1  e8baa80000           call 0x587360
// 0057caa6  8b4604               mov eax, dword ptr [esi + 4]
// 0057caa9  885818               mov byte ptr [eax + 0x18], bl
// 0057caac  8b4e04               mov ecx, dword ptr [esi + 4]
// 0057caaf  8b5104               mov edx, dword ptr [ecx + 4]
// 0057cab2  c6421800             mov byte ptr [edx + 0x18], 0
// 0057cab6  8b4604               mov eax, dword ptr [esi + 4]
// 0057cab9  8b4004               mov eax, dword ptr [eax + 4]
// 0057cabc  8b4808               mov ecx, dword ptr [eax + 8]
// 0057cabf  8b11                 mov edx, dword ptr [ecx]
// 0057cac1  895008               mov dword ptr [eax + 8], edx
// 0057cac4  8b11                 mov edx, dword ptr [ecx]
// 0057cac6  807a1900             cmp byte ptr [edx + 0x19], 0
// 0057caca  7503                 jne 0x57cacf
// 0057cacc  894204               mov dword ptr [edx + 4], eax
// 0057cacf  8b5004               mov edx, dword ptr [eax + 4]
// 0057cad2  895104               mov dword ptr [ecx + 4], edx
// 0057cad5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0057cad8  3b4204               cmp eax, dword ptr [edx + 4]
// 0057cadb  7505                 jne 0x57cae2
// 0057cadd  894a04               mov dword ptr [edx + 4], ecx
// 0057cae0  eb0e                 jmp 0x57caf0
// 0057cae2  8b5004               mov edx, dword ptr [eax + 4]
// 0057cae5  3b02                 cmp eax, dword ptr [edx]
// 0057cae7  7504                 jne 0x57caed
// 0057cae9  890a                 mov dword ptr [edx], ecx
// 0057caeb  eb03                 jmp 0x57caf0
// 0057caed  894a08               mov dword ptr [edx + 8], ecx
// 0057caf0  8901                 mov dword ptr [ecx], eax
// 0057caf2  894804               mov dword ptr [eax + 4], ecx
// 0057caf5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0057caf8  80791800             cmp byte ptr [ecx + 0x18], 0
// 0057cafc  8d4604               lea eax, [esi + 4]
// 0057caff  0f841bffffff         je 0x57ca20
// 0057cb05  8b5718               mov edx, dword ptr [edi + 0x18]
// 0057cb08  8b4204               mov eax, dword ptr [edx + 4]
// 0057cb0b  885818               mov byte ptr [eax + 0x18], bl
// 0057cb0e  8b442464             mov eax, dword ptr [esp + 0x64]
// 0057cb12  8b0f                 mov ecx, dword ptr [edi]
// 0057cb14  5e                   pop esi
// 0057cb15  896804               mov dword ptr [eax + 4], ebp
// 0057cb18  5d                   pop ebp
// 0057cb19  8908                 mov dword ptr [eax], ecx
// 0057cb1b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0057cb1f  5b                   pop ebx
// 0057cb20  5f                   pop edi
// 0057cb21  64890d00000000       mov dword ptr fs:[0], ecx
// 0057cb28  83c450               add esp, 0x50
// 0057cb2b  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
