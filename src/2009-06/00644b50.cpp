// from server: 100% by auto
// roc 2009-06 00644b50  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00644b50
//
// 00644b50  64a100000000         mov eax, dword ptr fs:[0]
// 00644b56  6aff                 push -1
// 00644b58  68b2db8500           push 0x85dbb2
// 00644b5d  50                   push eax
// 00644b5e  64892500000000       mov dword ptr fs:[0], esp
// 00644b65  83ec44               sub esp, 0x44
// 00644b68  57                   push edi
// 00644b69  8bf9                 mov edi, ecx
// 00644b6b  817f1c65666606       cmp dword ptr [edi + 0x1c], 0x6666665
// 00644b72  7259                 jb 0x644bcd
// 00644b74  68c0c98a00           push 0x8ac9c0
// 00644b79  8d4c2408             lea ecx, [esp + 8]
// 00644b7d  ff15b4e48900         call dword ptr [0x89e4b4]
// 00644b83  8d4c2420             lea ecx, [esp + 0x20]
// 00644b87  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00644b8f  ff15b8e98900         call dword ptr [0x89e9b8]
// 00644b95  8d442404             lea eax, [esp + 4]
// 00644b99  50                   push eax
// 00644b9a  8d4c2430             lea ecx, [esp + 0x30]
// 00644b9e  c644245401           mov byte ptr [esp + 0x54], 1
// 00644ba3  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 00644bab  ff15b8e48900         call dword ptr [0x89e4b8]
// 00644bb1  6834929700           push 0x979234
// 00644bb6  8d4c2424             lea ecx, [esp + 0x24]
// 00644bba  51                   push ecx
// 00644bbb  c644245800           mov byte ptr [esp + 0x58], 0
// 00644bc0  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 00644bc8  e87d4e0d00           call 0x719a4a
// 00644bcd  8b542464             mov edx, dword ptr [esp + 0x64]
// 00644bd1  8b4718               mov eax, dword ptr [edi + 0x18]
// 00644bd4  53                   push ebx
// 00644bd5  55                   push ebp
// 00644bd6  56                   push esi
// 00644bd7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00644bdb  6a00                 push 0
// 00644bdd  52                   push edx
// 00644bde  50                   push eax
// 00644bdf  56                   push esi
// 00644be0  50                   push eax
// 00644be1  e85af9ffff           call 0x644540
// 00644be6  8be8                 mov ebp, eax
// 00644be8  8b4718               mov eax, dword ptr [edi + 0x18]
// 00644beb  bb01000000           mov ebx, 1
// 00644bf0  015f1c               add dword ptr [edi + 0x1c], ebx
// 00644bf3  3bf0                 cmp esi, eax
// 00644bf5  7510                 jne 0x644c07
// 00644bf7  896804               mov dword ptr [eax + 4], ebp
// 00644bfa  8b4718               mov eax, dword ptr [edi + 0x18]
// 00644bfd  8928                 mov dword ptr [eax], ebp
// 00644bff  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00644c02  896908               mov dword ptr [ecx + 8], ebp
// 00644c05  eb22                 jmp 0x644c29
// 00644c07  807c246800           cmp byte ptr [esp + 0x68], 0
// 00644c0c  740d                 je 0x644c1b
// 00644c0e  892e                 mov dword ptr [esi], ebp
// 00644c10  8b4718               mov eax, dword ptr [edi + 0x18]
// 00644c13  3b30                 cmp esi, dword ptr [eax]
// 00644c15  7512                 jne 0x644c29
// 00644c17  8928                 mov dword ptr [eax], ebp
// 00644c19  eb0e                 jmp 0x644c29
// 00644c1b  896e08               mov dword ptr [esi + 8], ebp
// 00644c1e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00644c21  3b7008               cmp esi, dword ptr [eax + 8]
// 00644c24  7503                 jne 0x644c29
// 00644c26  896808               mov dword ptr [eax + 8], ebp
// 00644c29  8b5504               mov edx, dword ptr [ebp + 4]
// 00644c2c  807a3400             cmp byte ptr [edx + 0x34], 0
// 00644c30  8d4504               lea eax, [ebp + 4]
// 00644c33  8bf5                 mov esi, ebp
// 00644c35  0f85ea000000         jne 0x644d25
// 00644c3b  eb03                 jmp 0x644c40
// 00644c3d  8d4900               lea ecx, [ecx]
// 00644c40  8b08                 mov ecx, dword ptr [eax]
// 00644c42  8b5104               mov edx, dword ptr [ecx + 4]
// 00644c45  3b0a                 cmp ecx, dword ptr [edx]
// 00644c47  7551                 jne 0x644c9a
// 00644c49  8b5208               mov edx, dword ptr [edx + 8]
// 00644c4c  807a3400             cmp byte ptr [edx + 0x34], 0
// 00644c50  7519                 jne 0x644c6b
// 00644c52  885934               mov byte ptr [ecx + 0x34], bl
// 00644c55  885a34               mov byte ptr [edx + 0x34], bl
// 00644c58  8b10                 mov edx, dword ptr [eax]
// 00644c5a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00644c5d  c6413400             mov byte ptr [ecx + 0x34], 0
// 00644c61  8b10                 mov edx, dword ptr [eax]
// 00644c63  8b7204               mov esi, dword ptr [edx + 4]
// 00644c66  e9aa000000           jmp 0x644d15
// 00644c6b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00644c6e  750a                 jne 0x644c7a
// 00644c70  8bf1                 mov esi, ecx
// 00644c72  56                   push esi
// 00644c73  8bcf                 mov ecx, edi
// 00644c75  e8667e0b00           call 0x6fcae0
// 00644c7a  8b4604               mov eax, dword ptr [esi + 4]
// 00644c7d  885834               mov byte ptr [eax + 0x34], bl
// 00644c80  8b4e04               mov ecx, dword ptr [esi + 4]
// 00644c83  8b5104               mov edx, dword ptr [ecx + 4]
// 00644c86  c6423400             mov byte ptr [edx + 0x34], 0
// 00644c8a  8b4604               mov eax, dword ptr [esi + 4]
// 00644c8d  8b4804               mov ecx, dword ptr [eax + 4]
// 00644c90  51                   push ecx
// 00644c91  8bcf                 mov ecx, edi
// 00644c93  e8987e0b00           call 0x6fcb30
// 00644c98  eb7b                 jmp 0x644d15
// 00644c9a  8b12                 mov edx, dword ptr [edx]
// 00644c9c  807a3400             cmp byte ptr [edx + 0x34], 0
// 00644ca0  7516                 jne 0x644cb8
// 00644ca2  885934               mov byte ptr [ecx + 0x34], bl
// 00644ca5  885a34               mov byte ptr [edx + 0x34], bl
// 00644ca8  8b10                 mov edx, dword ptr [eax]
// 00644caa  8b4a04               mov ecx, dword ptr [edx + 4]
// 00644cad  c6413400             mov byte ptr [ecx + 0x34], 0
// 00644cb1  8b10                 mov edx, dword ptr [eax]
// 00644cb3  8b7204               mov esi, dword ptr [edx + 4]
// 00644cb6  eb5d                 jmp 0x644d15
// 00644cb8  3b31                 cmp esi, dword ptr [ecx]
// 00644cba  750a                 jne 0x644cc6
// 00644cbc  8bf1                 mov esi, ecx
// 00644cbe  56                   push esi
// 00644cbf  8bcf                 mov ecx, edi
// 00644cc1  e86a7e0b00           call 0x6fcb30
// 00644cc6  8b4604               mov eax, dword ptr [esi + 4]
// 00644cc9  885834               mov byte ptr [eax + 0x34], bl
// 00644ccc  8b4e04               mov ecx, dword ptr [esi + 4]
// 00644ccf  8b5104               mov edx, dword ptr [ecx + 4]
// 00644cd2  c6423400             mov byte ptr [edx + 0x34], 0
// 00644cd6  8b4604               mov eax, dword ptr [esi + 4]
// 00644cd9  8b4004               mov eax, dword ptr [eax + 4]
// 00644cdc  8b4808               mov ecx, dword ptr [eax + 8]
// 00644cdf  8b11                 mov edx, dword ptr [ecx]
// 00644ce1  895008               mov dword ptr [eax + 8], edx
// 00644ce4  8b11                 mov edx, dword ptr [ecx]
// 00644ce6  807a3500             cmp byte ptr [edx + 0x35], 0
// 00644cea  7503                 jne 0x644cef
// 00644cec  894204               mov dword ptr [edx + 4], eax
// 00644cef  8b5004               mov edx, dword ptr [eax + 4]
// 00644cf2  895104               mov dword ptr [ecx + 4], edx
// 00644cf5  8b5718               mov edx, dword ptr [edi + 0x18]
// 00644cf8  3b4204               cmp eax, dword ptr [edx + 4]
// 00644cfb  7505                 jne 0x644d02
// 00644cfd  894a04               mov dword ptr [edx + 4], ecx
// 00644d00  eb0e                 jmp 0x644d10
// 00644d02  8b5004               mov edx, dword ptr [eax + 4]
// 00644d05  3b02                 cmp eax, dword ptr [edx]
// 00644d07  7504                 jne 0x644d0d
// 00644d09  890a                 mov dword ptr [edx], ecx
// 00644d0b  eb03                 jmp 0x644d10
// 00644d0d  894a08               mov dword ptr [edx + 8], ecx
// 00644d10  8901                 mov dword ptr [ecx], eax
// 00644d12  894804               mov dword ptr [eax + 4], ecx
// 00644d15  8b4e04               mov ecx, dword ptr [esi + 4]
// 00644d18  80793400             cmp byte ptr [ecx + 0x34], 0
// 00644d1c  8d4604               lea eax, [esi + 4]
// 00644d1f  0f841bffffff         je 0x644c40
// 00644d25  8b5718               mov edx, dword ptr [edi + 0x18]
// 00644d28  8b4204               mov eax, dword ptr [edx + 4]
// 00644d2b  885834               mov byte ptr [eax + 0x34], bl
// 00644d2e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00644d32  8b0f                 mov ecx, dword ptr [edi]
// 00644d34  5e                   pop esi
// 00644d35  896804               mov dword ptr [eax + 4], ebp
// 00644d38  5d                   pop ebp
// 00644d39  8908                 mov dword ptr [eax], ecx
// 00644d3b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00644d3f  5b                   pop ebx
// 00644d40  5f                   pop edi
// 00644d41  64890d00000000       mov dword ptr fs:[0], ecx
// 00644d48  83c450               add esp, 0x50
// 00644d4b  c21000               ret 0x10
// standard library map_int<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
