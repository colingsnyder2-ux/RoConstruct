// from server: 100% by auto
// roc 2010-06 004c3960  unit: RBX::VInstance::?$NonFactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c3960
//
// 004c3960  64a100000000         mov eax, dword ptr fs:[0]
// 004c3966  6aff                 push -1
// 004c3968  68e22f9a00           push 0x9a2fe2
// 004c396d  50                   push eax
// 004c396e  64892500000000       mov dword ptr fs:[0], esp
// 004c3975  83ec44               sub esp, 0x44
// 004c3978  57                   push edi
// 004c3979  8bf9                 mov edi, ecx
// 004c397b  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 004c3982  7259                 jb 0x4c39dd
// 004c3984  68a800a000           push 0xa000a8
// 004c3989  8d4c2408             lea ecx, [esp + 8]
// 004c398d  ff1510a49e00         call dword ptr [0x9ea410]
// 004c3993  8d4c2420             lea ecx, [esp + 0x20]
// 004c3997  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004c399f  ff1518a99e00         call dword ptr [0x9ea918]
// 004c39a5  8d442404             lea eax, [esp + 4]
// 004c39a9  50                   push eax
// 004c39aa  8d4c2430             lea ecx, [esp + 0x30]
// 004c39ae  c644245401           mov byte ptr [esp + 0x54], 1
// 004c39b3  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 004c39bb  ff150ca49e00         call dword ptr [0x9ea40c]
// 004c39c1  68601bb000           push 0xb01b60
// 004c39c6  8d4c2424             lea ecx, [esp + 0x24]
// 004c39ca  51                   push ecx
// 004c39cb  c644245800           mov byte ptr [esp + 0x58], 0
// 004c39d0  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 004c39d8  e8d54f2e00           call 0x7a89b2
// 004c39dd  8b542464             mov edx, dword ptr [esp + 0x64]
// 004c39e1  8b4718               mov eax, dword ptr [edi + 0x18]
// 004c39e4  53                   push ebx
// 004c39e5  55                   push ebp
// 004c39e6  56                   push esi
// 004c39e7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004c39eb  6a00                 push 0
// 004c39ed  52                   push edx
// 004c39ee  50                   push eax
// 004c39ef  56                   push esi
// 004c39f0  50                   push eax
// 004c39f1  e85addffff           call 0x4c1750
// 004c39f6  8be8                 mov ebp, eax
// 004c39f8  8b4718               mov eax, dword ptr [edi + 0x18]
// 004c39fb  bb01000000           mov ebx, 1
// 004c3a00  015f1c               add dword ptr [edi + 0x1c], ebx
// 004c3a03  3bf0                 cmp esi, eax
// 004c3a05  7510                 jne 0x4c3a17
// 004c3a07  896804               mov dword ptr [eax + 4], ebp
// 004c3a0a  8b4718               mov eax, dword ptr [edi + 0x18]
// 004c3a0d  8928                 mov dword ptr [eax], ebp
// 004c3a0f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004c3a12  896908               mov dword ptr [ecx + 8], ebp
// 004c3a15  eb22                 jmp 0x4c3a39
// 004c3a17  807c246800           cmp byte ptr [esp + 0x68], 0
// 004c3a1c  740d                 je 0x4c3a2b
// 004c3a1e  892e                 mov dword ptr [esi], ebp
// 004c3a20  8b4718               mov eax, dword ptr [edi + 0x18]
// 004c3a23  3b30                 cmp esi, dword ptr [eax]
// 004c3a25  7512                 jne 0x4c3a39
// 004c3a27  8928                 mov dword ptr [eax], ebp
// 004c3a29  eb0e                 jmp 0x4c3a39
// 004c3a2b  896e08               mov dword ptr [esi + 8], ebp
// 004c3a2e  8b4718               mov eax, dword ptr [edi + 0x18]
// 004c3a31  3b7008               cmp esi, dword ptr [eax + 8]
// 004c3a34  7503                 jne 0x4c3a39
// 004c3a36  896808               mov dword ptr [eax + 8], ebp
// 004c3a39  8b5504               mov edx, dword ptr [ebp + 4]
// 004c3a3c  807a1800             cmp byte ptr [edx + 0x18], 0
// 004c3a40  8d4504               lea eax, [ebp + 4]
// 004c3a43  8bf5                 mov esi, ebp
// 004c3a45  0f85ea000000         jne 0x4c3b35
// 004c3a4b  eb03                 jmp 0x4c3a50
// 004c3a4d  8d4900               lea ecx, [ecx]
// 004c3a50  8b08                 mov ecx, dword ptr [eax]
// 004c3a52  8b5104               mov edx, dword ptr [ecx + 4]
// 004c3a55  3b0a                 cmp ecx, dword ptr [edx]
// 004c3a57  7551                 jne 0x4c3aaa
// 004c3a59  8b5208               mov edx, dword ptr [edx + 8]
// 004c3a5c  807a1800             cmp byte ptr [edx + 0x18], 0
// 004c3a60  7519                 jne 0x4c3a7b
// 004c3a62  885918               mov byte ptr [ecx + 0x18], bl
// 004c3a65  885a18               mov byte ptr [edx + 0x18], bl
// 004c3a68  8b10                 mov edx, dword ptr [eax]
// 004c3a6a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004c3a6d  c6411800             mov byte ptr [ecx + 0x18], 0
// 004c3a71  8b10                 mov edx, dword ptr [eax]
// 004c3a73  8b7204               mov esi, dword ptr [edx + 4]
// 004c3a76  e9aa000000           jmp 0x4c3b25
// 004c3a7b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004c3a7e  750a                 jne 0x4c3a8a
// 004c3a80  8bf1                 mov esi, ecx
// 004c3a82  56                   push esi
// 004c3a83  8bcf                 mov ecx, edi
// 004c3a85  e8562e0200           call 0x4e68e0
// 004c3a8a  8b4604               mov eax, dword ptr [esi + 4]
// 004c3a8d  885818               mov byte ptr [eax + 0x18], bl
// 004c3a90  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c3a93  8b5104               mov edx, dword ptr [ecx + 4]
// 004c3a96  c6421800             mov byte ptr [edx + 0x18], 0
// 004c3a9a  8b4604               mov eax, dword ptr [esi + 4]
// 004c3a9d  8b4804               mov ecx, dword ptr [eax + 4]
// 004c3aa0  51                   push ecx
// 004c3aa1  8bcf                 mov ecx, edi
// 004c3aa3  e808eb1200           call 0x5f25b0
// 004c3aa8  eb7b                 jmp 0x4c3b25
// 004c3aaa  8b12                 mov edx, dword ptr [edx]
// 004c3aac  807a1800             cmp byte ptr [edx + 0x18], 0
// 004c3ab0  7516                 jne 0x4c3ac8
// 004c3ab2  885918               mov byte ptr [ecx + 0x18], bl
// 004c3ab5  885a18               mov byte ptr [edx + 0x18], bl
// 004c3ab8  8b10                 mov edx, dword ptr [eax]
// 004c3aba  8b4a04               mov ecx, dword ptr [edx + 4]
// 004c3abd  c6411800             mov byte ptr [ecx + 0x18], 0
// 004c3ac1  8b10                 mov edx, dword ptr [eax]
// 004c3ac3  8b7204               mov esi, dword ptr [edx + 4]
// 004c3ac6  eb5d                 jmp 0x4c3b25
// 004c3ac8  3b31                 cmp esi, dword ptr [ecx]
// 004c3aca  750a                 jne 0x4c3ad6
// 004c3acc  8bf1                 mov esi, ecx
// 004c3ace  56                   push esi
// 004c3acf  8bcf                 mov ecx, edi
// 004c3ad1  e8daea1200           call 0x5f25b0
// 004c3ad6  8b4604               mov eax, dword ptr [esi + 4]
// 004c3ad9  885818               mov byte ptr [eax + 0x18], bl
// 004c3adc  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c3adf  8b5104               mov edx, dword ptr [ecx + 4]
// 004c3ae2  c6421800             mov byte ptr [edx + 0x18], 0
// 004c3ae6  8b4604               mov eax, dword ptr [esi + 4]
// 004c3ae9  8b4004               mov eax, dword ptr [eax + 4]
// 004c3aec  8b4808               mov ecx, dword ptr [eax + 8]
// 004c3aef  8b11                 mov edx, dword ptr [ecx]
// 004c3af1  895008               mov dword ptr [eax + 8], edx
// 004c3af4  8b11                 mov edx, dword ptr [ecx]
// 004c3af6  807a1900             cmp byte ptr [edx + 0x19], 0
// 004c3afa  7503                 jne 0x4c3aff
// 004c3afc  894204               mov dword ptr [edx + 4], eax
// 004c3aff  8b5004               mov edx, dword ptr [eax + 4]
// 004c3b02  895104               mov dword ptr [ecx + 4], edx
// 004c3b05  8b5718               mov edx, dword ptr [edi + 0x18]
// 004c3b08  3b4204               cmp eax, dword ptr [edx + 4]
// 004c3b0b  7505                 jne 0x4c3b12
// 004c3b0d  894a04               mov dword ptr [edx + 4], ecx
// 004c3b10  eb0e                 jmp 0x4c3b20
// 004c3b12  8b5004               mov edx, dword ptr [eax + 4]
// 004c3b15  3b02                 cmp eax, dword ptr [edx]
// 004c3b17  7504                 jne 0x4c3b1d
// 004c3b19  890a                 mov dword ptr [edx], ecx
// 004c3b1b  eb03                 jmp 0x4c3b20
// 004c3b1d  894a08               mov dword ptr [edx + 8], ecx
// 004c3b20  8901                 mov dword ptr [ecx], eax
// 004c3b22  894804               mov dword ptr [eax + 4], ecx
// 004c3b25  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c3b28  80791800             cmp byte ptr [ecx + 0x18], 0
// 004c3b2c  8d4604               lea eax, [esi + 4]
// 004c3b2f  0f841bffffff         je 0x4c3a50
// 004c3b35  8b5718               mov edx, dword ptr [edi + 0x18]
// 004c3b38  8b4204               mov eax, dword ptr [edx + 4]
// 004c3b3b  885818               mov byte ptr [eax + 0x18], bl
// 004c3b3e  8b442464             mov eax, dword ptr [esp + 0x64]
// 004c3b42  8b0f                 mov ecx, dword ptr [edi]
// 004c3b44  5e                   pop esi
// 004c3b45  896804               mov dword ptr [eax + 4], ebp
// 004c3b48  5d                   pop ebp
// 004c3b49  8908                 mov dword ptr [eax], ecx
// 004c3b4b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004c3b4f  5b                   pop ebx
// 004c3b50  5f                   pop edi
// 004c3b51  64890d00000000       mov dword ptr fs:[0], ecx
// 004c3b58  83c450               add esp, 0x50
// 004c3b5b  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
