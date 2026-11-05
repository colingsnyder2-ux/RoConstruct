// from server: 100% by auto
// roc 2009-06 006e3a50  unit: RBX::ScoreHud  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e3a50
//
// 006e3a50  64a100000000         mov eax, dword ptr fs:[0]
// 006e3a56  6aff                 push -1
// 006e3a58  68b2db8500           push 0x85dbb2
// 006e3a5d  50                   push eax
// 006e3a5e  64892500000000       mov dword ptr fs:[0], esp
// 006e3a65  83ec44               sub esp, 0x44
// 006e3a68  57                   push edi
// 006e3a69  8bf9                 mov edi, ecx
// 006e3a6b  817f1c43444404       cmp dword ptr [edi + 0x1c], 0x4444443
// 006e3a72  7259                 jb 0x6e3acd
// 006e3a74  68c0c98a00           push 0x8ac9c0
// 006e3a79  8d4c2408             lea ecx, [esp + 8]
// 006e3a7d  ff15b4e48900         call dword ptr [0x89e4b4]
// 006e3a83  8d4c2420             lea ecx, [esp + 0x20]
// 006e3a87  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006e3a8f  ff15b8e98900         call dword ptr [0x89e9b8]
// 006e3a95  8d442404             lea eax, [esp + 4]
// 006e3a99  50                   push eax
// 006e3a9a  8d4c2430             lea ecx, [esp + 0x30]
// 006e3a9e  c644245401           mov byte ptr [esp + 0x54], 1
// 006e3aa3  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 006e3aab  ff15b8e48900         call dword ptr [0x89e4b8]
// 006e3ab1  6834929700           push 0x979234
// 006e3ab6  8d4c2424             lea ecx, [esp + 0x24]
// 006e3aba  51                   push ecx
// 006e3abb  c644245800           mov byte ptr [esp + 0x58], 0
// 006e3ac0  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 006e3ac8  e87d5f0300           call 0x719a4a
// 006e3acd  8b542464             mov edx, dword ptr [esp + 0x64]
// 006e3ad1  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e3ad4  53                   push ebx
// 006e3ad5  55                   push ebp
// 006e3ad6  56                   push esi
// 006e3ad7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006e3adb  6a00                 push 0
// 006e3add  52                   push edx
// 006e3ade  50                   push eax
// 006e3adf  56                   push esi
// 006e3ae0  50                   push eax
// 006e3ae1  e86afaffff           call 0x6e3550
// 006e3ae6  8be8                 mov ebp, eax
// 006e3ae8  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e3aeb  bb01000000           mov ebx, 1
// 006e3af0  015f1c               add dword ptr [edi + 0x1c], ebx
// 006e3af3  3bf0                 cmp esi, eax
// 006e3af5  7510                 jne 0x6e3b07
// 006e3af7  896804               mov dword ptr [eax + 4], ebp
// 006e3afa  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e3afd  8928                 mov dword ptr [eax], ebp
// 006e3aff  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006e3b02  896908               mov dword ptr [ecx + 8], ebp
// 006e3b05  eb22                 jmp 0x6e3b29
// 006e3b07  807c246800           cmp byte ptr [esp + 0x68], 0
// 006e3b0c  740d                 je 0x6e3b1b
// 006e3b0e  892e                 mov dword ptr [esi], ebp
// 006e3b10  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e3b13  3b30                 cmp esi, dword ptr [eax]
// 006e3b15  7512                 jne 0x6e3b29
// 006e3b17  8928                 mov dword ptr [eax], ebp
// 006e3b19  eb0e                 jmp 0x6e3b29
// 006e3b1b  896e08               mov dword ptr [esi + 8], ebp
// 006e3b1e  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e3b21  3b7008               cmp esi, dword ptr [eax + 8]
// 006e3b24  7503                 jne 0x6e3b29
// 006e3b26  896808               mov dword ptr [eax + 8], ebp
// 006e3b29  8b5504               mov edx, dword ptr [ebp + 4]
// 006e3b2c  807a4800             cmp byte ptr [edx + 0x48], 0
// 006e3b30  8d4504               lea eax, [ebp + 4]
// 006e3b33  8bf5                 mov esi, ebp
// 006e3b35  0f85ea000000         jne 0x6e3c25
// 006e3b3b  eb03                 jmp 0x6e3b40
// 006e3b3d  8d4900               lea ecx, [ecx]
// 006e3b40  8b08                 mov ecx, dword ptr [eax]
// 006e3b42  8b5104               mov edx, dword ptr [ecx + 4]
// 006e3b45  3b0a                 cmp ecx, dword ptr [edx]
// 006e3b47  7551                 jne 0x6e3b9a
// 006e3b49  8b5208               mov edx, dword ptr [edx + 8]
// 006e3b4c  807a4800             cmp byte ptr [edx + 0x48], 0
// 006e3b50  7519                 jne 0x6e3b6b
// 006e3b52  885948               mov byte ptr [ecx + 0x48], bl
// 006e3b55  885a48               mov byte ptr [edx + 0x48], bl
// 006e3b58  8b10                 mov edx, dword ptr [eax]
// 006e3b5a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006e3b5d  c6414800             mov byte ptr [ecx + 0x48], 0
// 006e3b61  8b10                 mov edx, dword ptr [eax]
// 006e3b63  8b7204               mov esi, dword ptr [edx + 4]
// 006e3b66  e9aa000000           jmp 0x6e3c15
// 006e3b6b  3b7108               cmp esi, dword ptr [ecx + 8]
// 006e3b6e  750a                 jne 0x6e3b7a
// 006e3b70  8bf1                 mov esi, ecx
// 006e3b72  56                   push esi
// 006e3b73  8bcf                 mov ecx, edi
// 006e3b75  e8764af3ff           call 0x6185f0
// 006e3b7a  8b4604               mov eax, dword ptr [esi + 4]
// 006e3b7d  885848               mov byte ptr [eax + 0x48], bl
// 006e3b80  8b4e04               mov ecx, dword ptr [esi + 4]
// 006e3b83  8b5104               mov edx, dword ptr [ecx + 4]
// 006e3b86  c6424800             mov byte ptr [edx + 0x48], 0
// 006e3b8a  8b4604               mov eax, dword ptr [esi + 4]
// 006e3b8d  8b4804               mov ecx, dword ptr [eax + 4]
// 006e3b90  51                   push ecx
// 006e3b91  8bcf                 mov ecx, edi
// 006e3b93  e87847f3ff           call 0x618310
// 006e3b98  eb7b                 jmp 0x6e3c15
// 006e3b9a  8b12                 mov edx, dword ptr [edx]
// 006e3b9c  807a4800             cmp byte ptr [edx + 0x48], 0
// 006e3ba0  7516                 jne 0x6e3bb8
// 006e3ba2  885948               mov byte ptr [ecx + 0x48], bl
// 006e3ba5  885a48               mov byte ptr [edx + 0x48], bl
// 006e3ba8  8b10                 mov edx, dword ptr [eax]
// 006e3baa  8b4a04               mov ecx, dword ptr [edx + 4]
// 006e3bad  c6414800             mov byte ptr [ecx + 0x48], 0
// 006e3bb1  8b10                 mov edx, dword ptr [eax]
// 006e3bb3  8b7204               mov esi, dword ptr [edx + 4]
// 006e3bb6  eb5d                 jmp 0x6e3c15
// 006e3bb8  3b31                 cmp esi, dword ptr [ecx]
// 006e3bba  750a                 jne 0x6e3bc6
// 006e3bbc  8bf1                 mov esi, ecx
// 006e3bbe  56                   push esi
// 006e3bbf  8bcf                 mov ecx, edi
// 006e3bc1  e84a47f3ff           call 0x618310
// 006e3bc6  8b4604               mov eax, dword ptr [esi + 4]
// 006e3bc9  885848               mov byte ptr [eax + 0x48], bl
// 006e3bcc  8b4e04               mov ecx, dword ptr [esi + 4]
// 006e3bcf  8b5104               mov edx, dword ptr [ecx + 4]
// 006e3bd2  c6424800             mov byte ptr [edx + 0x48], 0
// 006e3bd6  8b4604               mov eax, dword ptr [esi + 4]
// 006e3bd9  8b4004               mov eax, dword ptr [eax + 4]
// 006e3bdc  8b4808               mov ecx, dword ptr [eax + 8]
// 006e3bdf  8b11                 mov edx, dword ptr [ecx]
// 006e3be1  895008               mov dword ptr [eax + 8], edx
// 006e3be4  8b11                 mov edx, dword ptr [ecx]
// 006e3be6  807a4900             cmp byte ptr [edx + 0x49], 0
// 006e3bea  7503                 jne 0x6e3bef
// 006e3bec  894204               mov dword ptr [edx + 4], eax
// 006e3bef  8b5004               mov edx, dword ptr [eax + 4]
// 006e3bf2  895104               mov dword ptr [ecx + 4], edx
// 006e3bf5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006e3bf8  3b4204               cmp eax, dword ptr [edx + 4]
// 006e3bfb  7505                 jne 0x6e3c02
// 006e3bfd  894a04               mov dword ptr [edx + 4], ecx
// 006e3c00  eb0e                 jmp 0x6e3c10
// 006e3c02  8b5004               mov edx, dword ptr [eax + 4]
// 006e3c05  3b02                 cmp eax, dword ptr [edx]
// 006e3c07  7504                 jne 0x6e3c0d
// 006e3c09  890a                 mov dword ptr [edx], ecx
// 006e3c0b  eb03                 jmp 0x6e3c10
// 006e3c0d  894a08               mov dword ptr [edx + 8], ecx
// 006e3c10  8901                 mov dword ptr [ecx], eax
// 006e3c12  894804               mov dword ptr [eax + 4], ecx
// 006e3c15  8b4e04               mov ecx, dword ptr [esi + 4]
// 006e3c18  80794800             cmp byte ptr [ecx + 0x48], 0
// 006e3c1c  8d4604               lea eax, [esi + 4]
// 006e3c1f  0f841bffffff         je 0x6e3b40
// 006e3c25  8b5718               mov edx, dword ptr [edi + 0x18]
// 006e3c28  8b4204               mov eax, dword ptr [edx + 4]
// 006e3c2b  885848               mov byte ptr [eax + 0x48], bl
// 006e3c2e  8b442464             mov eax, dword ptr [esp + 0x64]
// 006e3c32  8b0f                 mov ecx, dword ptr [edi]
// 006e3c34  5e                   pop esi
// 006e3c35  896804               mov dword ptr [eax + 4], ebp
// 006e3c38  5d                   pop ebp
// 006e3c39  8908                 mov dword ptr [eax], ecx
// 006e3c3b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006e3c3f  5b                   pop ebx
// 006e3c40  5f                   pop edi
// 006e3c41  64890d00000000       mov dword ptr fs:[0], ecx
// 006e3c48  83c450               add esp, 0x50
// 006e3c4b  c21000               ret 0x10
// standard library map_str<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
