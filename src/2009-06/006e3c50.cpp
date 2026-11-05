// from server: 100% by auto
// roc 2009-06 006e3c50  unit: RBX::ScoreHud  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e3c50
//
// 006e3c50  64a100000000         mov eax, dword ptr fs:[0]
// 006e3c56  6aff                 push -1
// 006e3c58  68b2db8500           push 0x85dbb2
// 006e3c5d  50                   push eax
// 006e3c5e  64892500000000       mov dword ptr fs:[0], esp
// 006e3c65  83ec44               sub esp, 0x44
// 006e3c68  57                   push edi
// 006e3c69  8bf9                 mov edi, ecx
// 006e3c6b  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 006e3c72  7259                 jb 0x6e3ccd
// 006e3c74  68c0c98a00           push 0x8ac9c0
// 006e3c79  8d4c2408             lea ecx, [esp + 8]
// 006e3c7d  ff15b4e48900         call dword ptr [0x89e4b4]
// 006e3c83  8d4c2420             lea ecx, [esp + 0x20]
// 006e3c87  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006e3c8f  ff15b8e98900         call dword ptr [0x89e9b8]
// 006e3c95  8d442404             lea eax, [esp + 4]
// 006e3c99  50                   push eax
// 006e3c9a  8d4c2430             lea ecx, [esp + 0x30]
// 006e3c9e  c644245401           mov byte ptr [esp + 0x54], 1
// 006e3ca3  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 006e3cab  ff15b8e48900         call dword ptr [0x89e4b8]
// 006e3cb1  6834929700           push 0x979234
// 006e3cb6  8d4c2424             lea ecx, [esp + 0x24]
// 006e3cba  51                   push ecx
// 006e3cbb  c644245800           mov byte ptr [esp + 0x58], 0
// 006e3cc0  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 006e3cc8  e87d5d0300           call 0x719a4a
// 006e3ccd  8b542464             mov edx, dword ptr [esp + 0x64]
// 006e3cd1  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e3cd4  53                   push ebx
// 006e3cd5  55                   push ebp
// 006e3cd6  56                   push esi
// 006e3cd7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006e3cdb  6a00                 push 0
// 006e3cdd  52                   push edx
// 006e3cde  50                   push eax
// 006e3cdf  56                   push esi
// 006e3ce0  50                   push eax
// 006e3ce1  e80af9ffff           call 0x6e35f0
// 006e3ce6  8be8                 mov ebp, eax
// 006e3ce8  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e3ceb  bb01000000           mov ebx, 1
// 006e3cf0  015f1c               add dword ptr [edi + 0x1c], ebx
// 006e3cf3  3bf0                 cmp esi, eax
// 006e3cf5  7510                 jne 0x6e3d07
// 006e3cf7  896804               mov dword ptr [eax + 4], ebp
// 006e3cfa  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e3cfd  8928                 mov dword ptr [eax], ebp
// 006e3cff  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006e3d02  896908               mov dword ptr [ecx + 8], ebp
// 006e3d05  eb22                 jmp 0x6e3d29
// 006e3d07  807c246800           cmp byte ptr [esp + 0x68], 0
// 006e3d0c  740d                 je 0x6e3d1b
// 006e3d0e  892e                 mov dword ptr [esi], ebp
// 006e3d10  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e3d13  3b30                 cmp esi, dword ptr [eax]
// 006e3d15  7512                 jne 0x6e3d29
// 006e3d17  8928                 mov dword ptr [eax], ebp
// 006e3d19  eb0e                 jmp 0x6e3d29
// 006e3d1b  896e08               mov dword ptr [esi + 8], ebp
// 006e3d1e  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e3d21  3b7008               cmp esi, dword ptr [eax + 8]
// 006e3d24  7503                 jne 0x6e3d29
// 006e3d26  896808               mov dword ptr [eax + 8], ebp
// 006e3d29  8b5504               mov edx, dword ptr [ebp + 4]
// 006e3d2c  807a3000             cmp byte ptr [edx + 0x30], 0
// 006e3d30  8d4504               lea eax, [ebp + 4]
// 006e3d33  8bf5                 mov esi, ebp
// 006e3d35  0f85ea000000         jne 0x6e3e25
// 006e3d3b  eb03                 jmp 0x6e3d40
// 006e3d3d  8d4900               lea ecx, [ecx]
// 006e3d40  8b08                 mov ecx, dword ptr [eax]
// 006e3d42  8b5104               mov edx, dword ptr [ecx + 4]
// 006e3d45  3b0a                 cmp ecx, dword ptr [edx]
// 006e3d47  7551                 jne 0x6e3d9a
// 006e3d49  8b5208               mov edx, dword ptr [edx + 8]
// 006e3d4c  807a3000             cmp byte ptr [edx + 0x30], 0
// 006e3d50  7519                 jne 0x6e3d6b
// 006e3d52  885930               mov byte ptr [ecx + 0x30], bl
// 006e3d55  885a30               mov byte ptr [edx + 0x30], bl
// 006e3d58  8b10                 mov edx, dword ptr [eax]
// 006e3d5a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006e3d5d  c6413000             mov byte ptr [ecx + 0x30], 0
// 006e3d61  8b10                 mov edx, dword ptr [eax]
// 006e3d63  8b7204               mov esi, dword ptr [edx + 4]
// 006e3d66  e9aa000000           jmp 0x6e3e15
// 006e3d6b  3b7108               cmp esi, dword ptr [ecx + 8]
// 006e3d6e  750a                 jne 0x6e3d7a
// 006e3d70  8bf1                 mov esi, ecx
// 006e3d72  56                   push esi
// 006e3d73  8bcf                 mov ecx, edi
// 006e3d75  e8f6e4f3ff           call 0x622270
// 006e3d7a  8b4604               mov eax, dword ptr [esi + 4]
// 006e3d7d  885830               mov byte ptr [eax + 0x30], bl
// 006e3d80  8b4e04               mov ecx, dword ptr [esi + 4]
// 006e3d83  8b5104               mov edx, dword ptr [ecx + 4]
// 006e3d86  c6423000             mov byte ptr [edx + 0x30], 0
// 006e3d8a  8b4604               mov eax, dword ptr [esi + 4]
// 006e3d8d  8b4804               mov ecx, dword ptr [eax + 4]
// 006e3d90  51                   push ecx
// 006e3d91  8bcf                 mov ecx, edi
// 006e3d93  e808e2ffff           call 0x6e1fa0
// 006e3d98  eb7b                 jmp 0x6e3e15
// 006e3d9a  8b12                 mov edx, dword ptr [edx]
// 006e3d9c  807a3000             cmp byte ptr [edx + 0x30], 0
// 006e3da0  7516                 jne 0x6e3db8
// 006e3da2  885930               mov byte ptr [ecx + 0x30], bl
// 006e3da5  885a30               mov byte ptr [edx + 0x30], bl
// 006e3da8  8b10                 mov edx, dword ptr [eax]
// 006e3daa  8b4a04               mov ecx, dword ptr [edx + 4]
// 006e3dad  c6413000             mov byte ptr [ecx + 0x30], 0
// 006e3db1  8b10                 mov edx, dword ptr [eax]
// 006e3db3  8b7204               mov esi, dword ptr [edx + 4]
// 006e3db6  eb5d                 jmp 0x6e3e15
// 006e3db8  3b31                 cmp esi, dword ptr [ecx]
// 006e3dba  750a                 jne 0x6e3dc6
// 006e3dbc  8bf1                 mov esi, ecx
// 006e3dbe  56                   push esi
// 006e3dbf  8bcf                 mov ecx, edi
// 006e3dc1  e8dae1ffff           call 0x6e1fa0
// 006e3dc6  8b4604               mov eax, dword ptr [esi + 4]
// 006e3dc9  885830               mov byte ptr [eax + 0x30], bl
// 006e3dcc  8b4e04               mov ecx, dword ptr [esi + 4]
// 006e3dcf  8b5104               mov edx, dword ptr [ecx + 4]
// 006e3dd2  c6423000             mov byte ptr [edx + 0x30], 0
// 006e3dd6  8b4604               mov eax, dword ptr [esi + 4]
// 006e3dd9  8b4004               mov eax, dword ptr [eax + 4]
// 006e3ddc  8b4808               mov ecx, dword ptr [eax + 8]
// 006e3ddf  8b11                 mov edx, dword ptr [ecx]
// 006e3de1  895008               mov dword ptr [eax + 8], edx
// 006e3de4  8b11                 mov edx, dword ptr [ecx]
// 006e3de6  807a3100             cmp byte ptr [edx + 0x31], 0
// 006e3dea  7503                 jne 0x6e3def
// 006e3dec  894204               mov dword ptr [edx + 4], eax
// 006e3def  8b5004               mov edx, dword ptr [eax + 4]
// 006e3df2  895104               mov dword ptr [ecx + 4], edx
// 006e3df5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006e3df8  3b4204               cmp eax, dword ptr [edx + 4]
// 006e3dfb  7505                 jne 0x6e3e02
// 006e3dfd  894a04               mov dword ptr [edx + 4], ecx
// 006e3e00  eb0e                 jmp 0x6e3e10
// 006e3e02  8b5004               mov edx, dword ptr [eax + 4]
// 006e3e05  3b02                 cmp eax, dword ptr [edx]
// 006e3e07  7504                 jne 0x6e3e0d
// 006e3e09  890a                 mov dword ptr [edx], ecx
// 006e3e0b  eb03                 jmp 0x6e3e10
// 006e3e0d  894a08               mov dword ptr [edx + 8], ecx
// 006e3e10  8901                 mov dword ptr [ecx], eax
// 006e3e12  894804               mov dword ptr [eax + 4], ecx
// 006e3e15  8b4e04               mov ecx, dword ptr [esi + 4]
// 006e3e18  80793000             cmp byte ptr [ecx + 0x30], 0
// 006e3e1c  8d4604               lea eax, [esi + 4]
// 006e3e1f  0f841bffffff         je 0x6e3d40
// 006e3e25  8b5718               mov edx, dword ptr [edi + 0x18]
// 006e3e28  8b4204               mov eax, dword ptr [edx + 4]
// 006e3e2b  885830               mov byte ptr [eax + 0x30], bl
// 006e3e2e  8b442464             mov eax, dword ptr [esp + 0x64]
// 006e3e32  8b0f                 mov ecx, dword ptr [edi]
// 006e3e34  5e                   pop esi
// 006e3e35  896804               mov dword ptr [eax + 4], ebp
// 006e3e38  5d                   pop ebp
// 006e3e39  8908                 mov dword ptr [eax], ecx
// 006e3e3b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006e3e3f  5b                   pop ebx
// 006e3e40  5f                   pop edi
// 006e3e41  64890d00000000       mov dword ptr fs:[0], ecx
// 006e3e48  83c450               add esp, 0x50
// 006e3e4b  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
