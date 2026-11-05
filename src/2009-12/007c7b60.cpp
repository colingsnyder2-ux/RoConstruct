// from server: 100% by auto
// roc 2009-12 007c7b60  unit: RBX::ScoreHud  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c7b60
//
// 007c7b60  64a100000000         mov eax, dword ptr fs:[0]
// 007c7b66  6aff                 push -1
// 007c7b68  6812699500           push 0x956912
// 007c7b6d  50                   push eax
// 007c7b6e  64892500000000       mov dword ptr fs:[0], esp
// 007c7b75  83ec44               sub esp, 0x44
// 007c7b78  57                   push edi
// 007c7b79  8bf9                 mov edi, ecx
// 007c7b7b  817f1c43444404       cmp dword ptr [edi + 0x1c], 0x4444443
// 007c7b82  7259                 jb 0x7c7bdd
// 007c7b84  6800f59900           push 0x99f500
// 007c7b89  8d4c2408             lea ecx, [esp + 8]
// 007c7b8d  ff15f4b69800         call dword ptr [0x98b6f4]
// 007c7b93  8d4c2420             lea ecx, [esp + 0x20]
// 007c7b97  c744245000000000     mov dword ptr [esp + 0x50], 0
// 007c7b9f  ff1554b79800         call dword ptr [0x98b754]
// 007c7ba5  8d442404             lea eax, [esp + 4]
// 007c7ba9  50                   push eax
// 007c7baa  8d4c2430             lea ecx, [esp + 0x30]
// 007c7bae  c644245401           mov byte ptr [esp + 0x54], 1
// 007c7bb3  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 007c7bbb  ff15f0b69800         call dword ptr [0x98b6f0]
// 007c7bc1  68e4efa800           push 0xa8efe4
// 007c7bc6  8d4c2424             lea ecx, [esp + 0x24]
// 007c7bca  51                   push ecx
// 007c7bcb  c644245800           mov byte ptr [esp + 0x58], 0
// 007c7bd0  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 007c7bd8  e89bcc0200           call 0x7f4878
// 007c7bdd  8b542464             mov edx, dword ptr [esp + 0x64]
// 007c7be1  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c7be4  53                   push ebx
// 007c7be5  55                   push ebp
// 007c7be6  56                   push esi
// 007c7be7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 007c7beb  6a00                 push 0
// 007c7bed  52                   push edx
// 007c7bee  50                   push eax
// 007c7bef  56                   push esi
// 007c7bf0  50                   push eax
// 007c7bf1  e85afbffff           call 0x7c7750
// 007c7bf6  8be8                 mov ebp, eax
// 007c7bf8  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c7bfb  bb01000000           mov ebx, 1
// 007c7c00  015f1c               add dword ptr [edi + 0x1c], ebx
// 007c7c03  3bf0                 cmp esi, eax
// 007c7c05  7510                 jne 0x7c7c17
// 007c7c07  896804               mov dword ptr [eax + 4], ebp
// 007c7c0a  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c7c0d  8928                 mov dword ptr [eax], ebp
// 007c7c0f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 007c7c12  896908               mov dword ptr [ecx + 8], ebp
// 007c7c15  eb22                 jmp 0x7c7c39
// 007c7c17  807c246800           cmp byte ptr [esp + 0x68], 0
// 007c7c1c  740d                 je 0x7c7c2b
// 007c7c1e  892e                 mov dword ptr [esi], ebp
// 007c7c20  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c7c23  3b30                 cmp esi, dword ptr [eax]
// 007c7c25  7512                 jne 0x7c7c39
// 007c7c27  8928                 mov dword ptr [eax], ebp
// 007c7c29  eb0e                 jmp 0x7c7c39
// 007c7c2b  896e08               mov dword ptr [esi + 8], ebp
// 007c7c2e  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c7c31  3b7008               cmp esi, dword ptr [eax + 8]
// 007c7c34  7503                 jne 0x7c7c39
// 007c7c36  896808               mov dword ptr [eax + 8], ebp
// 007c7c39  8b5504               mov edx, dword ptr [ebp + 4]
// 007c7c3c  807a4800             cmp byte ptr [edx + 0x48], 0
// 007c7c40  8d4504               lea eax, [ebp + 4]
// 007c7c43  8bf5                 mov esi, ebp
// 007c7c45  0f85ea000000         jne 0x7c7d35
// 007c7c4b  eb03                 jmp 0x7c7c50
// 007c7c4d  8d4900               lea ecx, [ecx]
// 007c7c50  8b08                 mov ecx, dword ptr [eax]
// 007c7c52  8b5104               mov edx, dword ptr [ecx + 4]
// 007c7c55  3b0a                 cmp ecx, dword ptr [edx]
// 007c7c57  7551                 jne 0x7c7caa
// 007c7c59  8b5208               mov edx, dword ptr [edx + 8]
// 007c7c5c  807a4800             cmp byte ptr [edx + 0x48], 0
// 007c7c60  7519                 jne 0x7c7c7b
// 007c7c62  885948               mov byte ptr [ecx + 0x48], bl
// 007c7c65  885a48               mov byte ptr [edx + 0x48], bl
// 007c7c68  8b10                 mov edx, dword ptr [eax]
// 007c7c6a  8b4a04               mov ecx, dword ptr [edx + 4]
// 007c7c6d  c6414800             mov byte ptr [ecx + 0x48], 0
// 007c7c71  8b10                 mov edx, dword ptr [eax]
// 007c7c73  8b7204               mov esi, dword ptr [edx + 4]
// 007c7c76  e9aa000000           jmp 0x7c7d25
// 007c7c7b  3b7108               cmp esi, dword ptr [ecx + 8]
// 007c7c7e  750a                 jne 0x7c7c8a
// 007c7c80  8bf1                 mov esi, ecx
// 007c7c82  56                   push esi
// 007c7c83  8bcf                 mov ecx, edi
// 007c7c85  e896e9ffff           call 0x7c6620
// 007c7c8a  8b4604               mov eax, dword ptr [esi + 4]
// 007c7c8d  885848               mov byte ptr [eax + 0x48], bl
// 007c7c90  8b4e04               mov ecx, dword ptr [esi + 4]
// 007c7c93  8b5104               mov edx, dword ptr [ecx + 4]
// 007c7c96  c6424800             mov byte ptr [edx + 0x48], 0
// 007c7c9a  8b4604               mov eax, dword ptr [esi + 4]
// 007c7c9d  8b4804               mov ecx, dword ptr [eax + 4]
// 007c7ca0  51                   push ecx
// 007c7ca1  8bcf                 mov ecx, edi
// 007c7ca3  e878abebff           call 0x682820
// 007c7ca8  eb7b                 jmp 0x7c7d25
// 007c7caa  8b12                 mov edx, dword ptr [edx]
// 007c7cac  807a4800             cmp byte ptr [edx + 0x48], 0
// 007c7cb0  7516                 jne 0x7c7cc8
// 007c7cb2  885948               mov byte ptr [ecx + 0x48], bl
// 007c7cb5  885a48               mov byte ptr [edx + 0x48], bl
// 007c7cb8  8b10                 mov edx, dword ptr [eax]
// 007c7cba  8b4a04               mov ecx, dword ptr [edx + 4]
// 007c7cbd  c6414800             mov byte ptr [ecx + 0x48], 0
// 007c7cc1  8b10                 mov edx, dword ptr [eax]
// 007c7cc3  8b7204               mov esi, dword ptr [edx + 4]
// 007c7cc6  eb5d                 jmp 0x7c7d25
// 007c7cc8  3b31                 cmp esi, dword ptr [ecx]
// 007c7cca  750a                 jne 0x7c7cd6
// 007c7ccc  8bf1                 mov esi, ecx
// 007c7cce  56                   push esi
// 007c7ccf  8bcf                 mov ecx, edi
// 007c7cd1  e84aabebff           call 0x682820
// 007c7cd6  8b4604               mov eax, dword ptr [esi + 4]
// 007c7cd9  885848               mov byte ptr [eax + 0x48], bl
// 007c7cdc  8b4e04               mov ecx, dword ptr [esi + 4]
// 007c7cdf  8b5104               mov edx, dword ptr [ecx + 4]
// 007c7ce2  c6424800             mov byte ptr [edx + 0x48], 0
// 007c7ce6  8b4604               mov eax, dword ptr [esi + 4]
// 007c7ce9  8b4004               mov eax, dword ptr [eax + 4]
// 007c7cec  8b4808               mov ecx, dword ptr [eax + 8]
// 007c7cef  8b11                 mov edx, dword ptr [ecx]
// 007c7cf1  895008               mov dword ptr [eax + 8], edx
// 007c7cf4  8b11                 mov edx, dword ptr [ecx]
// 007c7cf6  807a4900             cmp byte ptr [edx + 0x49], 0
// 007c7cfa  7503                 jne 0x7c7cff
// 007c7cfc  894204               mov dword ptr [edx + 4], eax
// 007c7cff  8b5004               mov edx, dword ptr [eax + 4]
// 007c7d02  895104               mov dword ptr [ecx + 4], edx
// 007c7d05  8b5718               mov edx, dword ptr [edi + 0x18]
// 007c7d08  3b4204               cmp eax, dword ptr [edx + 4]
// 007c7d0b  7505                 jne 0x7c7d12
// 007c7d0d  894a04               mov dword ptr [edx + 4], ecx
// 007c7d10  eb0e                 jmp 0x7c7d20
// 007c7d12  8b5004               mov edx, dword ptr [eax + 4]
// 007c7d15  3b02                 cmp eax, dword ptr [edx]
// 007c7d17  7504                 jne 0x7c7d1d
// 007c7d19  890a                 mov dword ptr [edx], ecx
// 007c7d1b  eb03                 jmp 0x7c7d20
// 007c7d1d  894a08               mov dword ptr [edx + 8], ecx
// 007c7d20  8901                 mov dword ptr [ecx], eax
// 007c7d22  894804               mov dword ptr [eax + 4], ecx
// 007c7d25  8b4e04               mov ecx, dword ptr [esi + 4]
// 007c7d28  80794800             cmp byte ptr [ecx + 0x48], 0
// 007c7d2c  8d4604               lea eax, [esi + 4]
// 007c7d2f  0f841bffffff         je 0x7c7c50
// 007c7d35  8b5718               mov edx, dword ptr [edi + 0x18]
// 007c7d38  8b4204               mov eax, dword ptr [edx + 4]
// 007c7d3b  885848               mov byte ptr [eax + 0x48], bl
// 007c7d3e  8b442464             mov eax, dword ptr [esp + 0x64]
// 007c7d42  8b0f                 mov ecx, dword ptr [edi]
// 007c7d44  5e                   pop esi
// 007c7d45  896804               mov dword ptr [eax + 4], ebp
// 007c7d48  5d                   pop ebp
// 007c7d49  8908                 mov dword ptr [eax], ecx
// 007c7d4b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 007c7d4f  5b                   pop ebx
// 007c7d50  5f                   pop edi
// 007c7d51  64890d00000000       mov dword ptr fs:[0], ecx
// 007c7d58  83c450               add esp, 0x50
// 007c7d5b  c21000               ret 0x10
// standard library map_str<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
