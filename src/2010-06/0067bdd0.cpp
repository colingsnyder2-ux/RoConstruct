// from server: 100% by auto
// roc 2010-06 0067bdd0  unit: std::D::DU?$char_traits::V?$basic_string::$$CBV?$map::V?$shared_ptr::?$holder  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0067bdd0
//
// 0067bdd0  64a100000000         mov eax, dword ptr fs:[0]
// 0067bdd6  6aff                 push -1
// 0067bdd8  68e22f9a00           push 0x9a2fe2
// 0067bddd  50                   push eax
// 0067bdde  64892500000000       mov dword ptr fs:[0], esp
// 0067bde5  83ec44               sub esp, 0x44
// 0067bde8  57                   push edi
// 0067bde9  8bf9                 mov edi, ecx
// 0067bdeb  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 0067bdf2  7259                 jb 0x67be4d
// 0067bdf4  68a800a000           push 0xa000a8
// 0067bdf9  8d4c2408             lea ecx, [esp + 8]
// 0067bdfd  ff1510a49e00         call dword ptr [0x9ea410]
// 0067be03  8d4c2420             lea ecx, [esp + 0x20]
// 0067be07  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0067be0f  ff1518a99e00         call dword ptr [0x9ea918]
// 0067be15  8d442404             lea eax, [esp + 4]
// 0067be19  50                   push eax
// 0067be1a  8d4c2430             lea ecx, [esp + 0x30]
// 0067be1e  c644245401           mov byte ptr [esp + 0x54], 1
// 0067be23  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 0067be2b  ff150ca49e00         call dword ptr [0x9ea40c]
// 0067be31  68601bb000           push 0xb01b60
// 0067be36  8d4c2424             lea ecx, [esp + 0x24]
// 0067be3a  51                   push ecx
// 0067be3b  c644245800           mov byte ptr [esp + 0x58], 0
// 0067be40  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 0067be48  e865cb1200           call 0x7a89b2
// 0067be4d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0067be51  8b4718               mov eax, dword ptr [edi + 0x18]
// 0067be54  53                   push ebx
// 0067be55  55                   push ebp
// 0067be56  56                   push esi
// 0067be57  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0067be5b  6a00                 push 0
// 0067be5d  52                   push edx
// 0067be5e  50                   push eax
// 0067be5f  56                   push esi
// 0067be60  50                   push eax
// 0067be61  e8eaf5ffff           call 0x67b450
// 0067be66  8be8                 mov ebp, eax
// 0067be68  8b4718               mov eax, dword ptr [edi + 0x18]
// 0067be6b  bb01000000           mov ebx, 1
// 0067be70  015f1c               add dword ptr [edi + 0x1c], ebx
// 0067be73  3bf0                 cmp esi, eax
// 0067be75  7510                 jne 0x67be87
// 0067be77  896804               mov dword ptr [eax + 4], ebp
// 0067be7a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0067be7d  8928                 mov dword ptr [eax], ebp
// 0067be7f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0067be82  896908               mov dword ptr [ecx + 8], ebp
// 0067be85  eb22                 jmp 0x67bea9
// 0067be87  807c246800           cmp byte ptr [esp + 0x68], 0
// 0067be8c  740d                 je 0x67be9b
// 0067be8e  892e                 mov dword ptr [esi], ebp
// 0067be90  8b4718               mov eax, dword ptr [edi + 0x18]
// 0067be93  3b30                 cmp esi, dword ptr [eax]
// 0067be95  7512                 jne 0x67bea9
// 0067be97  8928                 mov dword ptr [eax], ebp
// 0067be99  eb0e                 jmp 0x67bea9
// 0067be9b  896e08               mov dword ptr [esi + 8], ebp
// 0067be9e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0067bea1  3b7008               cmp esi, dword ptr [eax + 8]
// 0067bea4  7503                 jne 0x67bea9
// 0067bea6  896808               mov dword ptr [eax + 8], ebp
// 0067bea9  8b5504               mov edx, dword ptr [ebp + 4]
// 0067beac  807a3000             cmp byte ptr [edx + 0x30], 0
// 0067beb0  8d4504               lea eax, [ebp + 4]
// 0067beb3  8bf5                 mov esi, ebp
// 0067beb5  0f85ea000000         jne 0x67bfa5
// 0067bebb  eb03                 jmp 0x67bec0
// 0067bebd  8d4900               lea ecx, [ecx]
// 0067bec0  8b08                 mov ecx, dword ptr [eax]
// 0067bec2  8b5104               mov edx, dword ptr [ecx + 4]
// 0067bec5  3b0a                 cmp ecx, dword ptr [edx]
// 0067bec7  7551                 jne 0x67bf1a
// 0067bec9  8b5208               mov edx, dword ptr [edx + 8]
// 0067becc  807a3000             cmp byte ptr [edx + 0x30], 0
// 0067bed0  7519                 jne 0x67beeb
// 0067bed2  885930               mov byte ptr [ecx + 0x30], bl
// 0067bed5  885a30               mov byte ptr [edx + 0x30], bl
// 0067bed8  8b10                 mov edx, dword ptr [eax]
// 0067beda  8b4a04               mov ecx, dword ptr [edx + 4]
// 0067bedd  c6413000             mov byte ptr [ecx + 0x30], 0
// 0067bee1  8b10                 mov edx, dword ptr [eax]
// 0067bee3  8b7204               mov esi, dword ptr [edx + 4]
// 0067bee6  e9aa000000           jmp 0x67bf95
// 0067beeb  3b7108               cmp esi, dword ptr [ecx + 8]
// 0067beee  750a                 jne 0x67befa
// 0067bef0  8bf1                 mov esi, ecx
// 0067bef2  56                   push esi
// 0067bef3  8bcf                 mov ecx, edi
// 0067bef5  e82636feff           call 0x65f520
// 0067befa  8b4604               mov eax, dword ptr [esi + 4]
// 0067befd  885830               mov byte ptr [eax + 0x30], bl
// 0067bf00  8b4e04               mov ecx, dword ptr [esi + 4]
// 0067bf03  8b5104               mov edx, dword ptr [ecx + 4]
// 0067bf06  c6423000             mov byte ptr [edx + 0x30], 0
// 0067bf0a  8b4604               mov eax, dword ptr [esi + 4]
// 0067bf0d  8b4804               mov ecx, dword ptr [eax + 4]
// 0067bf10  51                   push ecx
// 0067bf11  8bcf                 mov ecx, edi
// 0067bf13  e8383fe4ff           call 0x4bfe50
// 0067bf18  eb7b                 jmp 0x67bf95
// 0067bf1a  8b12                 mov edx, dword ptr [edx]
// 0067bf1c  807a3000             cmp byte ptr [edx + 0x30], 0
// 0067bf20  7516                 jne 0x67bf38
// 0067bf22  885930               mov byte ptr [ecx + 0x30], bl
// 0067bf25  885a30               mov byte ptr [edx + 0x30], bl
// 0067bf28  8b10                 mov edx, dword ptr [eax]
// 0067bf2a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0067bf2d  c6413000             mov byte ptr [ecx + 0x30], 0
// 0067bf31  8b10                 mov edx, dword ptr [eax]
// 0067bf33  8b7204               mov esi, dword ptr [edx + 4]
// 0067bf36  eb5d                 jmp 0x67bf95
// 0067bf38  3b31                 cmp esi, dword ptr [ecx]
// 0067bf3a  750a                 jne 0x67bf46
// 0067bf3c  8bf1                 mov esi, ecx
// 0067bf3e  56                   push esi
// 0067bf3f  8bcf                 mov ecx, edi
// 0067bf41  e80a3fe4ff           call 0x4bfe50
// 0067bf46  8b4604               mov eax, dword ptr [esi + 4]
// 0067bf49  885830               mov byte ptr [eax + 0x30], bl
// 0067bf4c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0067bf4f  8b5104               mov edx, dword ptr [ecx + 4]
// 0067bf52  c6423000             mov byte ptr [edx + 0x30], 0
// 0067bf56  8b4604               mov eax, dword ptr [esi + 4]
// 0067bf59  8b4004               mov eax, dword ptr [eax + 4]
// 0067bf5c  8b4808               mov ecx, dword ptr [eax + 8]
// 0067bf5f  8b11                 mov edx, dword ptr [ecx]
// 0067bf61  895008               mov dword ptr [eax + 8], edx
// 0067bf64  8b11                 mov edx, dword ptr [ecx]
// 0067bf66  807a3100             cmp byte ptr [edx + 0x31], 0
// 0067bf6a  7503                 jne 0x67bf6f
// 0067bf6c  894204               mov dword ptr [edx + 4], eax
// 0067bf6f  8b5004               mov edx, dword ptr [eax + 4]
// 0067bf72  895104               mov dword ptr [ecx + 4], edx
// 0067bf75  8b5718               mov edx, dword ptr [edi + 0x18]
// 0067bf78  3b4204               cmp eax, dword ptr [edx + 4]
// 0067bf7b  7505                 jne 0x67bf82
// 0067bf7d  894a04               mov dword ptr [edx + 4], ecx
// 0067bf80  eb0e                 jmp 0x67bf90
// 0067bf82  8b5004               mov edx, dword ptr [eax + 4]
// 0067bf85  3b02                 cmp eax, dword ptr [edx]
// 0067bf87  7504                 jne 0x67bf8d
// 0067bf89  890a                 mov dword ptr [edx], ecx
// 0067bf8b  eb03                 jmp 0x67bf90
// 0067bf8d  894a08               mov dword ptr [edx + 8], ecx
// 0067bf90  8901                 mov dword ptr [ecx], eax
// 0067bf92  894804               mov dword ptr [eax + 4], ecx
// 0067bf95  8b4e04               mov ecx, dword ptr [esi + 4]
// 0067bf98  80793000             cmp byte ptr [ecx + 0x30], 0
// 0067bf9c  8d4604               lea eax, [esi + 4]
// 0067bf9f  0f841bffffff         je 0x67bec0
// 0067bfa5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0067bfa8  8b4204               mov eax, dword ptr [edx + 4]
// 0067bfab  885830               mov byte ptr [eax + 0x30], bl
// 0067bfae  8b442464             mov eax, dword ptr [esp + 0x64]
// 0067bfb2  8b0f                 mov ecx, dword ptr [edi]
// 0067bfb4  5e                   pop esi
// 0067bfb5  896804               mov dword ptr [eax + 4], ebp
// 0067bfb8  5d                   pop ebp
// 0067bfb9  8908                 mov dword ptr [eax], ecx
// 0067bfbb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0067bfbf  5b                   pop ebx
// 0067bfc0  5f                   pop edi
// 0067bfc1  64890d00000000       mov dword ptr fs:[0], ecx
// 0067bfc8  83c450               add esp, 0x50
// 0067bfcb  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
