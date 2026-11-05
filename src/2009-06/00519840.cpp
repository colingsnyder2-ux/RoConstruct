// from server: 100% by auto
// roc 2009-06 00519840  unit: G3D::VVector3::?$Table  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00519840
//
// 00519840  64a100000000         mov eax, dword ptr fs:[0]
// 00519846  6aff                 push -1
// 00519848  68b2db8500           push 0x85dbb2
// 0051984d  50                   push eax
// 0051984e  64892500000000       mov dword ptr fs:[0], esp
// 00519855  83ec44               sub esp, 0x44
// 00519858  57                   push edi
// 00519859  8bf9                 mov edi, ecx
// 0051985b  817f1ccbcccc0c       cmp dword ptr [edi + 0x1c], 0xccccccb
// 00519862  7259                 jb 0x5198bd
// 00519864  68c0c98a00           push 0x8ac9c0
// 00519869  8d4c2408             lea ecx, [esp + 8]
// 0051986d  ff15b4e48900         call dword ptr [0x89e4b4]
// 00519873  8d4c2420             lea ecx, [esp + 0x20]
// 00519877  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0051987f  ff15b8e98900         call dword ptr [0x89e9b8]
// 00519885  8d442404             lea eax, [esp + 4]
// 00519889  50                   push eax
// 0051988a  8d4c2430             lea ecx, [esp + 0x30]
// 0051988e  c644245401           mov byte ptr [esp + 0x54], 1
// 00519893  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 0051989b  ff15b8e48900         call dword ptr [0x89e4b8]
// 005198a1  6834929700           push 0x979234
// 005198a6  8d4c2424             lea ecx, [esp + 0x24]
// 005198aa  51                   push ecx
// 005198ab  c644245800           mov byte ptr [esp + 0x58], 0
// 005198b0  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 005198b8  e88d012000           call 0x719a4a
// 005198bd  8b542464             mov edx, dword ptr [esp + 0x64]
// 005198c1  8b4718               mov eax, dword ptr [edi + 0x18]
// 005198c4  53                   push ebx
// 005198c5  55                   push ebp
// 005198c6  56                   push esi
// 005198c7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005198cb  6a00                 push 0
// 005198cd  52                   push edx
// 005198ce  50                   push eax
// 005198cf  56                   push esi
// 005198d0  50                   push eax
// 005198d1  e8baf9ffff           call 0x519290
// 005198d6  8be8                 mov ebp, eax
// 005198d8  8b4718               mov eax, dword ptr [edi + 0x18]
// 005198db  bb01000000           mov ebx, 1
// 005198e0  015f1c               add dword ptr [edi + 0x1c], ebx
// 005198e3  3bf0                 cmp esi, eax
// 005198e5  7510                 jne 0x5198f7
// 005198e7  896804               mov dword ptr [eax + 4], ebp
// 005198ea  8b4718               mov eax, dword ptr [edi + 0x18]
// 005198ed  8928                 mov dword ptr [eax], ebp
// 005198ef  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005198f2  896908               mov dword ptr [ecx + 8], ebp
// 005198f5  eb22                 jmp 0x519919
// 005198f7  807c246800           cmp byte ptr [esp + 0x68], 0
// 005198fc  740d                 je 0x51990b
// 005198fe  892e                 mov dword ptr [esi], ebp
// 00519900  8b4718               mov eax, dword ptr [edi + 0x18]
// 00519903  3b30                 cmp esi, dword ptr [eax]
// 00519905  7512                 jne 0x519919
// 00519907  8928                 mov dword ptr [eax], ebp
// 00519909  eb0e                 jmp 0x519919
// 0051990b  896e08               mov dword ptr [esi + 8], ebp
// 0051990e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00519911  3b7008               cmp esi, dword ptr [eax + 8]
// 00519914  7503                 jne 0x519919
// 00519916  896808               mov dword ptr [eax + 8], ebp
// 00519919  8b5504               mov edx, dword ptr [ebp + 4]
// 0051991c  807a2000             cmp byte ptr [edx + 0x20], 0
// 00519920  8d4504               lea eax, [ebp + 4]
// 00519923  8bf5                 mov esi, ebp
// 00519925  0f85ea000000         jne 0x519a15
// 0051992b  eb03                 jmp 0x519930
// 0051992d  8d4900               lea ecx, [ecx]
// 00519930  8b08                 mov ecx, dword ptr [eax]
// 00519932  8b5104               mov edx, dword ptr [ecx + 4]
// 00519935  3b0a                 cmp ecx, dword ptr [edx]
// 00519937  7551                 jne 0x51998a
// 00519939  8b5208               mov edx, dword ptr [edx + 8]
// 0051993c  807a2000             cmp byte ptr [edx + 0x20], 0
// 00519940  7519                 jne 0x51995b
// 00519942  885920               mov byte ptr [ecx + 0x20], bl
// 00519945  885a20               mov byte ptr [edx + 0x20], bl
// 00519948  8b10                 mov edx, dword ptr [eax]
// 0051994a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0051994d  c6412000             mov byte ptr [ecx + 0x20], 0
// 00519951  8b10                 mov edx, dword ptr [eax]
// 00519953  8b7204               mov esi, dword ptr [edx + 4]
// 00519956  e9aa000000           jmp 0x519a05
// 0051995b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0051995e  750a                 jne 0x51996a
// 00519960  8bf1                 mov esi, ecx
// 00519962  56                   push esi
// 00519963  8bcf                 mov ecx, edi
// 00519965  e8b6deffff           call 0x517820
// 0051996a  8b4604               mov eax, dword ptr [esi + 4]
// 0051996d  885820               mov byte ptr [eax + 0x20], bl
// 00519970  8b4e04               mov ecx, dword ptr [esi + 4]
// 00519973  8b5104               mov edx, dword ptr [ecx + 4]
// 00519976  c6422000             mov byte ptr [edx + 0x20], 0
// 0051997a  8b4604               mov eax, dword ptr [esi + 4]
// 0051997d  8b4804               mov ecx, dword ptr [eax + 4]
// 00519980  51                   push ecx
// 00519981  8bcf                 mov ecx, edi
// 00519983  e8c8d0ffff           call 0x516a50
// 00519988  eb7b                 jmp 0x519a05
// 0051998a  8b12                 mov edx, dword ptr [edx]
// 0051998c  807a2000             cmp byte ptr [edx + 0x20], 0
// 00519990  7516                 jne 0x5199a8
// 00519992  885920               mov byte ptr [ecx + 0x20], bl
// 00519995  885a20               mov byte ptr [edx + 0x20], bl
// 00519998  8b10                 mov edx, dword ptr [eax]
// 0051999a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0051999d  c6412000             mov byte ptr [ecx + 0x20], 0
// 005199a1  8b10                 mov edx, dword ptr [eax]
// 005199a3  8b7204               mov esi, dword ptr [edx + 4]
// 005199a6  eb5d                 jmp 0x519a05
// 005199a8  3b31                 cmp esi, dword ptr [ecx]
// 005199aa  750a                 jne 0x5199b6
// 005199ac  8bf1                 mov esi, ecx
// 005199ae  56                   push esi
// 005199af  8bcf                 mov ecx, edi
// 005199b1  e89ad0ffff           call 0x516a50
// 005199b6  8b4604               mov eax, dword ptr [esi + 4]
// 005199b9  885820               mov byte ptr [eax + 0x20], bl
// 005199bc  8b4e04               mov ecx, dword ptr [esi + 4]
// 005199bf  8b5104               mov edx, dword ptr [ecx + 4]
// 005199c2  c6422000             mov byte ptr [edx + 0x20], 0
// 005199c6  8b4604               mov eax, dword ptr [esi + 4]
// 005199c9  8b4004               mov eax, dword ptr [eax + 4]
// 005199cc  8b4808               mov ecx, dword ptr [eax + 8]
// 005199cf  8b11                 mov edx, dword ptr [ecx]
// 005199d1  895008               mov dword ptr [eax + 8], edx
// 005199d4  8b11                 mov edx, dword ptr [ecx]
// 005199d6  807a2100             cmp byte ptr [edx + 0x21], 0
// 005199da  7503                 jne 0x5199df
// 005199dc  894204               mov dword ptr [edx + 4], eax
// 005199df  8b5004               mov edx, dword ptr [eax + 4]
// 005199e2  895104               mov dword ptr [ecx + 4], edx
// 005199e5  8b5718               mov edx, dword ptr [edi + 0x18]
// 005199e8  3b4204               cmp eax, dword ptr [edx + 4]
// 005199eb  7505                 jne 0x5199f2
// 005199ed  894a04               mov dword ptr [edx + 4], ecx
// 005199f0  eb0e                 jmp 0x519a00
// 005199f2  8b5004               mov edx, dword ptr [eax + 4]
// 005199f5  3b02                 cmp eax, dword ptr [edx]
// 005199f7  7504                 jne 0x5199fd
// 005199f9  890a                 mov dword ptr [edx], ecx
// 005199fb  eb03                 jmp 0x519a00
// 005199fd  894a08               mov dword ptr [edx + 8], ecx
// 00519a00  8901                 mov dword ptr [ecx], eax
// 00519a02  894804               mov dword ptr [eax + 4], ecx
// 00519a05  8b4e04               mov ecx, dword ptr [esi + 4]
// 00519a08  80792000             cmp byte ptr [ecx + 0x20], 0
// 00519a0c  8d4604               lea eax, [esi + 4]
// 00519a0f  0f841bffffff         je 0x519930
// 00519a15  8b5718               mov edx, dword ptr [edi + 0x18]
// 00519a18  8b4204               mov eax, dword ptr [edx + 4]
// 00519a1b  885820               mov byte ptr [eax + 0x20], bl
// 00519a1e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00519a22  8b0f                 mov ecx, dword ptr [edi]
// 00519a24  5e                   pop esi
// 00519a25  896804               mov dword ptr [eax + 4], ebp
// 00519a28  5d                   pop ebp
// 00519a29  8908                 mov dword ptr [eax], ecx
// 00519a2b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00519a2f  5b                   pop ebx
// 00519a30  5f                   pop edi
// 00519a31  64890d00000000       mov dword ptr fs:[0], ecx
// 00519a38  83c450               add esp, 0x50
// 00519a3b  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
