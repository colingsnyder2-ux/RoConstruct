// from server: 100% by auto
// roc 2007-08 004d87f0  unit: RBX::View::MegaTextureProxy  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d87f0
//
// 004d87f0  64a100000000         mov eax, dword ptr fs:[0]
// 004d87f6  6aff                 push -1
// 004d87f8  68b2417500           push 0x7541b2
// 004d87fd  50                   push eax
// 004d87fe  64892500000000       mov dword ptr fs:[0], esp
// 004d8805  83ec44               sub esp, 0x44
// 004d8808  57                   push edi
// 004d8809  8bf9                 mov edi, ecx
// 004d880b  817f08cbcccc0c       cmp dword ptr [edi + 8], 0xccccccb
// 004d8812  7259                 jb 0x4d886d
// 004d8814  68904f7800           push 0x784f90
// 004d8819  8d4c2408             lea ecx, [esp + 8]
// 004d881d  ff1598e67700         call dword ptr [0x77e698]
// 004d8823  8d4c2420             lea ecx, [esp + 0x20]
// 004d8827  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004d882f  ff15f8e67700         call dword ptr [0x77e6f8]
// 004d8835  8d442404             lea eax, [esp + 4]
// 004d8839  50                   push eax
// 004d883a  8d4c2430             lea ecx, [esp + 0x30]
// 004d883e  c644245401           mov byte ptr [esp + 0x54], 1
// 004d8843  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 004d884b  ff159ce67700         call dword ptr [0x77e69c]
// 004d8851  6878f78300           push 0x83f778
// 004d8856  8d4c2424             lea ecx, [esp + 0x24]
// 004d885a  51                   push ecx
// 004d885b  c644245800           mov byte ptr [esp + 0x58], 0
// 004d8860  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 004d8868  e831831500           call 0x630b9e
// 004d886d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004d8871  8b4704               mov eax, dword ptr [edi + 4]
// 004d8874  53                   push ebx
// 004d8875  55                   push ebp
// 004d8876  56                   push esi
// 004d8877  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004d887b  6a00                 push 0
// 004d887d  52                   push edx
// 004d887e  50                   push eax
// 004d887f  56                   push esi
// 004d8880  50                   push eax
// 004d8881  e8bafeffff           call 0x4d8740
// 004d8886  8be8                 mov ebp, eax
// 004d8888  8b4704               mov eax, dword ptr [edi + 4]
// 004d888b  bb01000000           mov ebx, 1
// 004d8890  015f08               add dword ptr [edi + 8], ebx
// 004d8893  3bf0                 cmp esi, eax
// 004d8895  7510                 jne 0x4d88a7
// 004d8897  896804               mov dword ptr [eax + 4], ebp
// 004d889a  8b4704               mov eax, dword ptr [edi + 4]
// 004d889d  8928                 mov dword ptr [eax], ebp
// 004d889f  8b4f04               mov ecx, dword ptr [edi + 4]
// 004d88a2  896908               mov dword ptr [ecx + 8], ebp
// 004d88a5  eb22                 jmp 0x4d88c9
// 004d88a7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004d88ac  740d                 je 0x4d88bb
// 004d88ae  892e                 mov dword ptr [esi], ebp
// 004d88b0  8b4704               mov eax, dword ptr [edi + 4]
// 004d88b3  3b30                 cmp esi, dword ptr [eax]
// 004d88b5  7512                 jne 0x4d88c9
// 004d88b7  8928                 mov dword ptr [eax], ebp
// 004d88b9  eb0e                 jmp 0x4d88c9
// 004d88bb  896e08               mov dword ptr [esi + 8], ebp
// 004d88be  8b4704               mov eax, dword ptr [edi + 4]
// 004d88c1  3b7008               cmp esi, dword ptr [eax + 8]
// 004d88c4  7503                 jne 0x4d88c9
// 004d88c6  896808               mov dword ptr [eax + 8], ebp
// 004d88c9  8b5504               mov edx, dword ptr [ebp + 4]
// 004d88cc  807a2000             cmp byte ptr [edx + 0x20], 0
// 004d88d0  8d4504               lea eax, [ebp + 4]
// 004d88d3  8bf5                 mov esi, ebp
// 004d88d5  0f85ea000000         jne 0x4d89c5
// 004d88db  eb03                 jmp 0x4d88e0
// 004d88dd  8d4900               lea ecx, [ecx]
// 004d88e0  8b08                 mov ecx, dword ptr [eax]
// 004d88e2  8b5104               mov edx, dword ptr [ecx + 4]
// 004d88e5  3b0a                 cmp ecx, dword ptr [edx]
// 004d88e7  7551                 jne 0x4d893a
// 004d88e9  8b5208               mov edx, dword ptr [edx + 8]
// 004d88ec  807a2000             cmp byte ptr [edx + 0x20], 0
// 004d88f0  7519                 jne 0x4d890b
// 004d88f2  885920               mov byte ptr [ecx + 0x20], bl
// 004d88f5  885a20               mov byte ptr [edx + 0x20], bl
// 004d88f8  8b10                 mov edx, dword ptr [eax]
// 004d88fa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004d88fd  c6412000             mov byte ptr [ecx + 0x20], 0
// 004d8901  8b10                 mov edx, dword ptr [eax]
// 004d8903  8b7204               mov esi, dword ptr [edx + 4]
// 004d8906  e9aa000000           jmp 0x4d89b5
// 004d890b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004d890e  750a                 jne 0x4d891a
// 004d8910  8bf1                 mov esi, ecx
// 004d8912  56                   push esi
// 004d8913  8bcf                 mov ecx, edi
// 004d8915  e8f64dffff           call 0x4cd710
// 004d891a  8b4604               mov eax, dword ptr [esi + 4]
// 004d891d  885820               mov byte ptr [eax + 0x20], bl
// 004d8920  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d8923  8b5104               mov edx, dword ptr [ecx + 4]
// 004d8926  c6422000             mov byte ptr [edx + 0x20], 0
// 004d892a  8b4604               mov eax, dword ptr [esi + 4]
// 004d892d  8b4804               mov ecx, dword ptr [eax + 4]
// 004d8930  51                   push ecx
// 004d8931  8bcf                 mov ecx, edi
// 004d8933  e8b879ffff           call 0x4d02f0
// 004d8938  eb7b                 jmp 0x4d89b5
// 004d893a  8b12                 mov edx, dword ptr [edx]
// 004d893c  807a2000             cmp byte ptr [edx + 0x20], 0
// 004d8940  7516                 jne 0x4d8958
// 004d8942  885920               mov byte ptr [ecx + 0x20], bl
// 004d8945  885a20               mov byte ptr [edx + 0x20], bl
// 004d8948  8b10                 mov edx, dword ptr [eax]
// 004d894a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004d894d  c6412000             mov byte ptr [ecx + 0x20], 0
// 004d8951  8b10                 mov edx, dword ptr [eax]
// 004d8953  8b7204               mov esi, dword ptr [edx + 4]
// 004d8956  eb5d                 jmp 0x4d89b5
// 004d8958  3b31                 cmp esi, dword ptr [ecx]
// 004d895a  750a                 jne 0x4d8966
// 004d895c  8bf1                 mov esi, ecx
// 004d895e  56                   push esi
// 004d895f  8bcf                 mov ecx, edi
// 004d8961  e88a79ffff           call 0x4d02f0
// 004d8966  8b4604               mov eax, dword ptr [esi + 4]
// 004d8969  885820               mov byte ptr [eax + 0x20], bl
// 004d896c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d896f  8b5104               mov edx, dword ptr [ecx + 4]
// 004d8972  c6422000             mov byte ptr [edx + 0x20], 0
// 004d8976  8b4604               mov eax, dword ptr [esi + 4]
// 004d8979  8b4004               mov eax, dword ptr [eax + 4]
// 004d897c  8b4808               mov ecx, dword ptr [eax + 8]
// 004d897f  8b11                 mov edx, dword ptr [ecx]
// 004d8981  895008               mov dword ptr [eax + 8], edx
// 004d8984  8b11                 mov edx, dword ptr [ecx]
// 004d8986  807a2100             cmp byte ptr [edx + 0x21], 0
// 004d898a  7503                 jne 0x4d898f
// 004d898c  894204               mov dword ptr [edx + 4], eax
// 004d898f  8b5004               mov edx, dword ptr [eax + 4]
// 004d8992  895104               mov dword ptr [ecx + 4], edx
// 004d8995  8b5704               mov edx, dword ptr [edi + 4]
// 004d8998  3b4204               cmp eax, dword ptr [edx + 4]
// 004d899b  7505                 jne 0x4d89a2
// 004d899d  894a04               mov dword ptr [edx + 4], ecx
// 004d89a0  eb0e                 jmp 0x4d89b0
// 004d89a2  8b5004               mov edx, dword ptr [eax + 4]
// 004d89a5  3b02                 cmp eax, dword ptr [edx]
// 004d89a7  7504                 jne 0x4d89ad
// 004d89a9  890a                 mov dword ptr [edx], ecx
// 004d89ab  eb03                 jmp 0x4d89b0
// 004d89ad  894a08               mov dword ptr [edx + 8], ecx
// 004d89b0  8901                 mov dword ptr [ecx], eax
// 004d89b2  894804               mov dword ptr [eax + 4], ecx
// 004d89b5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d89b8  80792000             cmp byte ptr [ecx + 0x20], 0
// 004d89bc  8d4604               lea eax, [esi + 4]
// 004d89bf  0f841bffffff         je 0x4d88e0
// 004d89c5  8b5704               mov edx, dword ptr [edi + 4]
// 004d89c8  8b4204               mov eax, dword ptr [edx + 4]
// 004d89cb  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004d89cf  885820               mov byte ptr [eax + 0x20], bl
// 004d89d2  8b442464             mov eax, dword ptr [esp + 0x64]
// 004d89d6  5e                   pop esi
// 004d89d7  896804               mov dword ptr [eax + 4], ebp
// 004d89da  5d                   pop ebp
// 004d89db  8938                 mov dword ptr [eax], edi
// 004d89dd  5b                   pop ebx
// 004d89de  5f                   pop edi
// 004d89df  64890d00000000       mov dword ptr fs:[0], ecx
// 004d89e6  83c450               add esp, 0x50
// 004d89e9  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
