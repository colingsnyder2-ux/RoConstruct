// from server: 100% by auto
// roc 2010-06 005f0a50  unit: TextXmlWriter  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005f0a50
//
// 005f0a50  64a100000000         mov eax, dword ptr fs:[0]
// 005f0a56  6aff                 push -1
// 005f0a58  68e22f9a00           push 0x9a2fe2
// 005f0a5d  50                   push eax
// 005f0a5e  64892500000000       mov dword ptr fs:[0], esp
// 005f0a65  83ec44               sub esp, 0x44
// 005f0a68  57                   push edi
// 005f0a69  8bf9                 mov edi, ecx
// 005f0a6b  817f1c23499204       cmp dword ptr [edi + 0x1c], 0x4924923
// 005f0a72  7259                 jb 0x5f0acd
// 005f0a74  68a800a000           push 0xa000a8
// 005f0a79  8d4c2408             lea ecx, [esp + 8]
// 005f0a7d  ff1510a49e00         call dword ptr [0x9ea410]
// 005f0a83  8d4c2420             lea ecx, [esp + 0x20]
// 005f0a87  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005f0a8f  ff1518a99e00         call dword ptr [0x9ea918]
// 005f0a95  8d442404             lea eax, [esp + 4]
// 005f0a99  50                   push eax
// 005f0a9a  8d4c2430             lea ecx, [esp + 0x30]
// 005f0a9e  c644245401           mov byte ptr [esp + 0x54], 1
// 005f0aa3  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 005f0aab  ff150ca49e00         call dword ptr [0x9ea40c]
// 005f0ab1  68601bb000           push 0xb01b60
// 005f0ab6  8d4c2424             lea ecx, [esp + 0x24]
// 005f0aba  51                   push ecx
// 005f0abb  c644245800           mov byte ptr [esp + 0x58], 0
// 005f0ac0  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 005f0ac8  e8e57e1b00           call 0x7a89b2
// 005f0acd  8b542464             mov edx, dword ptr [esp + 0x64]
// 005f0ad1  8b4718               mov eax, dword ptr [edi + 0x18]
// 005f0ad4  53                   push ebx
// 005f0ad5  55                   push ebp
// 005f0ad6  56                   push esi
// 005f0ad7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005f0adb  6a00                 push 0
// 005f0add  52                   push edx
// 005f0ade  50                   push eax
// 005f0adf  56                   push esi
// 005f0ae0  50                   push eax
// 005f0ae1  e82af2ffff           call 0x5efd10
// 005f0ae6  8be8                 mov ebp, eax
// 005f0ae8  8b4718               mov eax, dword ptr [edi + 0x18]
// 005f0aeb  bb01000000           mov ebx, 1
// 005f0af0  015f1c               add dword ptr [edi + 0x1c], ebx
// 005f0af3  3bf0                 cmp esi, eax
// 005f0af5  7510                 jne 0x5f0b07
// 005f0af7  896804               mov dword ptr [eax + 4], ebp
// 005f0afa  8b4718               mov eax, dword ptr [edi + 0x18]
// 005f0afd  8928                 mov dword ptr [eax], ebp
// 005f0aff  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005f0b02  896908               mov dword ptr [ecx + 8], ebp
// 005f0b05  eb22                 jmp 0x5f0b29
// 005f0b07  807c246800           cmp byte ptr [esp + 0x68], 0
// 005f0b0c  740d                 je 0x5f0b1b
// 005f0b0e  892e                 mov dword ptr [esi], ebp
// 005f0b10  8b4718               mov eax, dword ptr [edi + 0x18]
// 005f0b13  3b30                 cmp esi, dword ptr [eax]
// 005f0b15  7512                 jne 0x5f0b29
// 005f0b17  8928                 mov dword ptr [eax], ebp
// 005f0b19  eb0e                 jmp 0x5f0b29
// 005f0b1b  896e08               mov dword ptr [esi + 8], ebp
// 005f0b1e  8b4718               mov eax, dword ptr [edi + 0x18]
// 005f0b21  3b7008               cmp esi, dword ptr [eax + 8]
// 005f0b24  7503                 jne 0x5f0b29
// 005f0b26  896808               mov dword ptr [eax + 8], ebp
// 005f0b29  8b5504               mov edx, dword ptr [ebp + 4]
// 005f0b2c  807a4400             cmp byte ptr [edx + 0x44], 0
// 005f0b30  8d4504               lea eax, [ebp + 4]
// 005f0b33  8bf5                 mov esi, ebp
// 005f0b35  0f85ea000000         jne 0x5f0c25
// 005f0b3b  eb03                 jmp 0x5f0b40
// 005f0b3d  8d4900               lea ecx, [ecx]
// 005f0b40  8b08                 mov ecx, dword ptr [eax]
// 005f0b42  8b5104               mov edx, dword ptr [ecx + 4]
// 005f0b45  3b0a                 cmp ecx, dword ptr [edx]
// 005f0b47  7551                 jne 0x5f0b9a
// 005f0b49  8b5208               mov edx, dword ptr [edx + 8]
// 005f0b4c  807a4400             cmp byte ptr [edx + 0x44], 0
// 005f0b50  7519                 jne 0x5f0b6b
// 005f0b52  885944               mov byte ptr [ecx + 0x44], bl
// 005f0b55  885a44               mov byte ptr [edx + 0x44], bl
// 005f0b58  8b10                 mov edx, dword ptr [eax]
// 005f0b5a  8b4a04               mov ecx, dword ptr [edx + 4]
// 005f0b5d  c6414400             mov byte ptr [ecx + 0x44], 0
// 005f0b61  8b10                 mov edx, dword ptr [eax]
// 005f0b63  8b7204               mov esi, dword ptr [edx + 4]
// 005f0b66  e9aa000000           jmp 0x5f0c15
// 005f0b6b  3b7108               cmp esi, dword ptr [ecx + 8]
// 005f0b6e  750a                 jne 0x5f0b7a
// 005f0b70  8bf1                 mov esi, ecx
// 005f0b72  56                   push esi
// 005f0b73  8bcf                 mov ecx, edi
// 005f0b75  e8d62ce2ff           call 0x413850
// 005f0b7a  8b4604               mov eax, dword ptr [esi + 4]
// 005f0b7d  885844               mov byte ptr [eax + 0x44], bl
// 005f0b80  8b4e04               mov ecx, dword ptr [esi + 4]
// 005f0b83  8b5104               mov edx, dword ptr [ecx + 4]
// 005f0b86  c6424400             mov byte ptr [edx + 0x44], 0
// 005f0b8a  8b4604               mov eax, dword ptr [esi + 4]
// 005f0b8d  8b4804               mov ecx, dword ptr [eax + 4]
// 005f0b90  51                   push ecx
// 005f0b91  8bcf                 mov ecx, edi
// 005f0b93  e8482de2ff           call 0x4138e0
// 005f0b98  eb7b                 jmp 0x5f0c15
// 005f0b9a  8b12                 mov edx, dword ptr [edx]
// 005f0b9c  807a4400             cmp byte ptr [edx + 0x44], 0
// 005f0ba0  7516                 jne 0x5f0bb8
// 005f0ba2  885944               mov byte ptr [ecx + 0x44], bl
// 005f0ba5  885a44               mov byte ptr [edx + 0x44], bl
// 005f0ba8  8b10                 mov edx, dword ptr [eax]
// 005f0baa  8b4a04               mov ecx, dword ptr [edx + 4]
// 005f0bad  c6414400             mov byte ptr [ecx + 0x44], 0
// 005f0bb1  8b10                 mov edx, dword ptr [eax]
// 005f0bb3  8b7204               mov esi, dword ptr [edx + 4]
// 005f0bb6  eb5d                 jmp 0x5f0c15
// 005f0bb8  3b31                 cmp esi, dword ptr [ecx]
// 005f0bba  750a                 jne 0x5f0bc6
// 005f0bbc  8bf1                 mov esi, ecx
// 005f0bbe  56                   push esi
// 005f0bbf  8bcf                 mov ecx, edi
// 005f0bc1  e81a2de2ff           call 0x4138e0
// 005f0bc6  8b4604               mov eax, dword ptr [esi + 4]
// 005f0bc9  885844               mov byte ptr [eax + 0x44], bl
// 005f0bcc  8b4e04               mov ecx, dword ptr [esi + 4]
// 005f0bcf  8b5104               mov edx, dword ptr [ecx + 4]
// 005f0bd2  c6424400             mov byte ptr [edx + 0x44], 0
// 005f0bd6  8b4604               mov eax, dword ptr [esi + 4]
// 005f0bd9  8b4004               mov eax, dword ptr [eax + 4]
// 005f0bdc  8b4808               mov ecx, dword ptr [eax + 8]
// 005f0bdf  8b11                 mov edx, dword ptr [ecx]
// 005f0be1  895008               mov dword ptr [eax + 8], edx
// 005f0be4  8b11                 mov edx, dword ptr [ecx]
// 005f0be6  807a4500             cmp byte ptr [edx + 0x45], 0
// 005f0bea  7503                 jne 0x5f0bef
// 005f0bec  894204               mov dword ptr [edx + 4], eax
// 005f0bef  8b5004               mov edx, dword ptr [eax + 4]
// 005f0bf2  895104               mov dword ptr [ecx + 4], edx
// 005f0bf5  8b5718               mov edx, dword ptr [edi + 0x18]
// 005f0bf8  3b4204               cmp eax, dword ptr [edx + 4]
// 005f0bfb  7505                 jne 0x5f0c02
// 005f0bfd  894a04               mov dword ptr [edx + 4], ecx
// 005f0c00  eb0e                 jmp 0x5f0c10
// 005f0c02  8b5004               mov edx, dword ptr [eax + 4]
// 005f0c05  3b02                 cmp eax, dword ptr [edx]
// 005f0c07  7504                 jne 0x5f0c0d
// 005f0c09  890a                 mov dword ptr [edx], ecx
// 005f0c0b  eb03                 jmp 0x5f0c10
// 005f0c0d  894a08               mov dword ptr [edx + 8], ecx
// 005f0c10  8901                 mov dword ptr [ecx], eax
// 005f0c12  894804               mov dword ptr [eax + 4], ecx
// 005f0c15  8b4e04               mov ecx, dword ptr [esi + 4]
// 005f0c18  80794400             cmp byte ptr [ecx + 0x44], 0
// 005f0c1c  8d4604               lea eax, [esi + 4]
// 005f0c1f  0f841bffffff         je 0x5f0b40
// 005f0c25  8b5718               mov edx, dword ptr [edi + 0x18]
// 005f0c28  8b4204               mov eax, dword ptr [edx + 4]
// 005f0c2b  885844               mov byte ptr [eax + 0x44], bl
// 005f0c2e  8b442464             mov eax, dword ptr [esp + 0x64]
// 005f0c32  8b0f                 mov ecx, dword ptr [edi]
// 005f0c34  5e                   pop esi
// 005f0c35  896804               mov dword ptr [eax + 4], ebp
// 005f0c38  5d                   pop ebp
// 005f0c39  8908                 mov dword ptr [eax], ecx
// 005f0c3b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005f0c3f  5b                   pop ebx
// 005f0c40  5f                   pop edi
// 005f0c41  64890d00000000       mov dword ptr fs:[0], ecx
// 005f0c48  83c450               add esp, 0x50
// 005f0c4b  c21000               ret 0x10
// standard library map_str<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
