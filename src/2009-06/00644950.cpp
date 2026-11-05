// from server: 100% by auto
// roc 2009-06 00644950  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00644950
//
// 00644950  64a100000000         mov eax, dword ptr fs:[0]
// 00644956  6aff                 push -1
// 00644958  68b2db8500           push 0x85dbb2
// 0064495d  50                   push eax
// 0064495e  64892500000000       mov dword ptr fs:[0], esp
// 00644965  83ec44               sub esp, 0x44
// 00644968  57                   push edi
// 00644969  8bf9                 mov edi, ecx
// 0064496b  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 00644972  7259                 jb 0x6449cd
// 00644974  68c0c98a00           push 0x8ac9c0
// 00644979  8d4c2408             lea ecx, [esp + 8]
// 0064497d  ff15b4e48900         call dword ptr [0x89e4b4]
// 00644983  8d4c2420             lea ecx, [esp + 0x20]
// 00644987  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0064498f  ff15b8e98900         call dword ptr [0x89e9b8]
// 00644995  8d442404             lea eax, [esp + 4]
// 00644999  50                   push eax
// 0064499a  8d4c2430             lea ecx, [esp + 0x30]
// 0064499e  c644245401           mov byte ptr [esp + 0x54], 1
// 006449a3  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 006449ab  ff15b8e48900         call dword ptr [0x89e4b8]
// 006449b1  6834929700           push 0x979234
// 006449b6  8d4c2424             lea ecx, [esp + 0x24]
// 006449ba  51                   push ecx
// 006449bb  c644245800           mov byte ptr [esp + 0x58], 0
// 006449c0  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 006449c8  e87d500d00           call 0x719a4a
// 006449cd  8b542464             mov edx, dword ptr [esp + 0x64]
// 006449d1  8b4718               mov eax, dword ptr [edi + 0x18]
// 006449d4  53                   push ebx
// 006449d5  55                   push ebp
// 006449d6  56                   push esi
// 006449d7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006449db  6a00                 push 0
// 006449dd  52                   push edx
// 006449de  50                   push eax
// 006449df  56                   push esi
// 006449e0  50                   push eax
// 006449e1  e8ea0deaff           call 0x4e57d0
// 006449e6  8be8                 mov ebp, eax
// 006449e8  8b4718               mov eax, dword ptr [edi + 0x18]
// 006449eb  bb01000000           mov ebx, 1
// 006449f0  015f1c               add dword ptr [edi + 0x1c], ebx
// 006449f3  3bf0                 cmp esi, eax
// 006449f5  7510                 jne 0x644a07
// 006449f7  896804               mov dword ptr [eax + 4], ebp
// 006449fa  8b4718               mov eax, dword ptr [edi + 0x18]
// 006449fd  8928                 mov dword ptr [eax], ebp
// 006449ff  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00644a02  896908               mov dword ptr [ecx + 8], ebp
// 00644a05  eb22                 jmp 0x644a29
// 00644a07  807c246800           cmp byte ptr [esp + 0x68], 0
// 00644a0c  740d                 je 0x644a1b
// 00644a0e  892e                 mov dword ptr [esi], ebp
// 00644a10  8b4718               mov eax, dword ptr [edi + 0x18]
// 00644a13  3b30                 cmp esi, dword ptr [eax]
// 00644a15  7512                 jne 0x644a29
// 00644a17  8928                 mov dword ptr [eax], ebp
// 00644a19  eb0e                 jmp 0x644a29
// 00644a1b  896e08               mov dword ptr [esi + 8], ebp
// 00644a1e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00644a21  3b7008               cmp esi, dword ptr [eax + 8]
// 00644a24  7503                 jne 0x644a29
// 00644a26  896808               mov dword ptr [eax + 8], ebp
// 00644a29  8b5504               mov edx, dword ptr [ebp + 4]
// 00644a2c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00644a30  8d4504               lea eax, [ebp + 4]
// 00644a33  8bf5                 mov esi, ebp
// 00644a35  0f85ea000000         jne 0x644b25
// 00644a3b  eb03                 jmp 0x644a40
// 00644a3d  8d4900               lea ecx, [ecx]
// 00644a40  8b08                 mov ecx, dword ptr [eax]
// 00644a42  8b5104               mov edx, dword ptr [ecx + 4]
// 00644a45  3b0a                 cmp ecx, dword ptr [edx]
// 00644a47  7551                 jne 0x644a9a
// 00644a49  8b5208               mov edx, dword ptr [edx + 8]
// 00644a4c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00644a50  7519                 jne 0x644a6b
// 00644a52  885918               mov byte ptr [ecx + 0x18], bl
// 00644a55  885a18               mov byte ptr [edx + 0x18], bl
// 00644a58  8b10                 mov edx, dword ptr [eax]
// 00644a5a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00644a5d  c6411800             mov byte ptr [ecx + 0x18], 0
// 00644a61  8b10                 mov edx, dword ptr [eax]
// 00644a63  8b7204               mov esi, dword ptr [edx + 4]
// 00644a66  e9aa000000           jmp 0x644b15
// 00644a6b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00644a6e  750a                 jne 0x644a7a
// 00644a70  8bf1                 mov esi, ecx
// 00644a72  56                   push esi
// 00644a73  8bcf                 mov ecx, edi
// 00644a75  e8c63bfdff           call 0x618640
// 00644a7a  8b4604               mov eax, dword ptr [esi + 4]
// 00644a7d  885818               mov byte ptr [eax + 0x18], bl
// 00644a80  8b4e04               mov ecx, dword ptr [esi + 4]
// 00644a83  8b5104               mov edx, dword ptr [ecx + 4]
// 00644a86  c6421800             mov byte ptr [edx + 0x18], 0
// 00644a8a  8b4604               mov eax, dword ptr [esi + 4]
// 00644a8d  8b4804               mov ecx, dword ptr [eax + 4]
// 00644a90  51                   push ecx
// 00644a91  8bcf                 mov ecx, edi
// 00644a93  e828f0ffff           call 0x643ac0
// 00644a98  eb7b                 jmp 0x644b15
// 00644a9a  8b12                 mov edx, dword ptr [edx]
// 00644a9c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00644aa0  7516                 jne 0x644ab8
// 00644aa2  885918               mov byte ptr [ecx + 0x18], bl
// 00644aa5  885a18               mov byte ptr [edx + 0x18], bl
// 00644aa8  8b10                 mov edx, dword ptr [eax]
// 00644aaa  8b4a04               mov ecx, dword ptr [edx + 4]
// 00644aad  c6411800             mov byte ptr [ecx + 0x18], 0
// 00644ab1  8b10                 mov edx, dword ptr [eax]
// 00644ab3  8b7204               mov esi, dword ptr [edx + 4]
// 00644ab6  eb5d                 jmp 0x644b15
// 00644ab8  3b31                 cmp esi, dword ptr [ecx]
// 00644aba  750a                 jne 0x644ac6
// 00644abc  8bf1                 mov esi, ecx
// 00644abe  56                   push esi
// 00644abf  8bcf                 mov ecx, edi
// 00644ac1  e8faefffff           call 0x643ac0
// 00644ac6  8b4604               mov eax, dword ptr [esi + 4]
// 00644ac9  885818               mov byte ptr [eax + 0x18], bl
// 00644acc  8b4e04               mov ecx, dword ptr [esi + 4]
// 00644acf  8b5104               mov edx, dword ptr [ecx + 4]
// 00644ad2  c6421800             mov byte ptr [edx + 0x18], 0
// 00644ad6  8b4604               mov eax, dword ptr [esi + 4]
// 00644ad9  8b4004               mov eax, dword ptr [eax + 4]
// 00644adc  8b4808               mov ecx, dword ptr [eax + 8]
// 00644adf  8b11                 mov edx, dword ptr [ecx]
// 00644ae1  895008               mov dword ptr [eax + 8], edx
// 00644ae4  8b11                 mov edx, dword ptr [ecx]
// 00644ae6  807a1900             cmp byte ptr [edx + 0x19], 0
// 00644aea  7503                 jne 0x644aef
// 00644aec  894204               mov dword ptr [edx + 4], eax
// 00644aef  8b5004               mov edx, dword ptr [eax + 4]
// 00644af2  895104               mov dword ptr [ecx + 4], edx
// 00644af5  8b5718               mov edx, dword ptr [edi + 0x18]
// 00644af8  3b4204               cmp eax, dword ptr [edx + 4]
// 00644afb  7505                 jne 0x644b02
// 00644afd  894a04               mov dword ptr [edx + 4], ecx
// 00644b00  eb0e                 jmp 0x644b10
// 00644b02  8b5004               mov edx, dword ptr [eax + 4]
// 00644b05  3b02                 cmp eax, dword ptr [edx]
// 00644b07  7504                 jne 0x644b0d
// 00644b09  890a                 mov dword ptr [edx], ecx
// 00644b0b  eb03                 jmp 0x644b10
// 00644b0d  894a08               mov dword ptr [edx + 8], ecx
// 00644b10  8901                 mov dword ptr [ecx], eax
// 00644b12  894804               mov dword ptr [eax + 4], ecx
// 00644b15  8b4e04               mov ecx, dword ptr [esi + 4]
// 00644b18  80791800             cmp byte ptr [ecx + 0x18], 0
// 00644b1c  8d4604               lea eax, [esi + 4]
// 00644b1f  0f841bffffff         je 0x644a40
// 00644b25  8b5718               mov edx, dword ptr [edi + 0x18]
// 00644b28  8b4204               mov eax, dword ptr [edx + 4]
// 00644b2b  885818               mov byte ptr [eax + 0x18], bl
// 00644b2e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00644b32  8b0f                 mov ecx, dword ptr [edi]
// 00644b34  5e                   pop esi
// 00644b35  896804               mov dword ptr [eax + 4], ebp
// 00644b38  5d                   pop ebp
// 00644b39  8908                 mov dword ptr [eax], ecx
// 00644b3b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00644b3f  5b                   pop ebx
// 00644b40  5f                   pop edi
// 00644b41  64890d00000000       mov dword ptr fs:[0], ecx
// 00644b48  83c450               add esp, 0x50
// 00644b4b  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
