// from server: 100% by auto
// roc 2008-06 004ae370  unit: RBX::Network::VClient::?$FactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004ae370
//
// 004ae370  64a100000000         mov eax, dword ptr fs:[0]
// 004ae376  6aff                 push -1
// 004ae378  6842e87d00           push 0x7de842
// 004ae37d  50                   push eax
// 004ae37e  64892500000000       mov dword ptr fs:[0], esp
// 004ae385  83ec44               sub esp, 0x44
// 004ae388  57                   push edi
// 004ae389  8bf9                 mov edi, ecx
// 004ae38b  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 004ae392  7259                 jb 0x4ae3ed
// 004ae394  688cb28000           push 0x80b28c
// 004ae399  8d4c2408             lea ecx, [esp + 8]
// 004ae39d  ff1558248000         call dword ptr [0x802458]
// 004ae3a3  8d4c2420             lea ecx, [esp + 0x20]
// 004ae3a7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004ae3af  ff1598288000         call dword ptr [0x802898]
// 004ae3b5  8d442404             lea eax, [esp + 4]
// 004ae3b9  50                   push eax
// 004ae3ba  8d4c2430             lea ecx, [esp + 0x30]
// 004ae3be  c644245401           mov byte ptr [esp + 0x54], 1
// 004ae3c3  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 004ae3cb  ff155c248000         call dword ptr [0x80245c]
// 004ae3d1  68c00c8d00           push 0x8d0cc0
// 004ae3d6  8d4c2424             lea ecx, [esp + 0x24]
// 004ae3da  51                   push ecx
// 004ae3db  c644245800           mov byte ptr [esp + 0x58], 0
// 004ae3e0  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 004ae3e8  e89f311f00           call 0x6a158c
// 004ae3ed  8b542464             mov edx, dword ptr [esp + 0x64]
// 004ae3f1  8b4718               mov eax, dword ptr [edi + 0x18]
// 004ae3f4  53                   push ebx
// 004ae3f5  55                   push ebp
// 004ae3f6  56                   push esi
// 004ae3f7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004ae3fb  6a00                 push 0
// 004ae3fd  52                   push edx
// 004ae3fe  50                   push eax
// 004ae3ff  56                   push esi
// 004ae400  50                   push eax
// 004ae401  e8ca9e1000           call 0x5b82d0
// 004ae406  8be8                 mov ebp, eax
// 004ae408  8b4718               mov eax, dword ptr [edi + 0x18]
// 004ae40b  bb01000000           mov ebx, 1
// 004ae410  015f1c               add dword ptr [edi + 0x1c], ebx
// 004ae413  3bf0                 cmp esi, eax
// 004ae415  7510                 jne 0x4ae427
// 004ae417  896804               mov dword ptr [eax + 4], ebp
// 004ae41a  8b4718               mov eax, dword ptr [edi + 0x18]
// 004ae41d  8928                 mov dword ptr [eax], ebp
// 004ae41f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004ae422  896908               mov dword ptr [ecx + 8], ebp
// 004ae425  eb22                 jmp 0x4ae449
// 004ae427  807c246800           cmp byte ptr [esp + 0x68], 0
// 004ae42c  740d                 je 0x4ae43b
// 004ae42e  892e                 mov dword ptr [esi], ebp
// 004ae430  8b4718               mov eax, dword ptr [edi + 0x18]
// 004ae433  3b30                 cmp esi, dword ptr [eax]
// 004ae435  7512                 jne 0x4ae449
// 004ae437  8928                 mov dword ptr [eax], ebp
// 004ae439  eb0e                 jmp 0x4ae449
// 004ae43b  896e08               mov dword ptr [esi + 8], ebp
// 004ae43e  8b4718               mov eax, dword ptr [edi + 0x18]
// 004ae441  3b7008               cmp esi, dword ptr [eax + 8]
// 004ae444  7503                 jne 0x4ae449
// 004ae446  896808               mov dword ptr [eax + 8], ebp
// 004ae449  8b5504               mov edx, dword ptr [ebp + 4]
// 004ae44c  807a1800             cmp byte ptr [edx + 0x18], 0
// 004ae450  8d4504               lea eax, [ebp + 4]
// 004ae453  8bf5                 mov esi, ebp
// 004ae455  0f85ea000000         jne 0x4ae545
// 004ae45b  eb03                 jmp 0x4ae460
// 004ae45d  8d4900               lea ecx, [ecx]
// 004ae460  8b08                 mov ecx, dword ptr [eax]
// 004ae462  8b5104               mov edx, dword ptr [ecx + 4]
// 004ae465  3b0a                 cmp ecx, dword ptr [edx]
// 004ae467  7551                 jne 0x4ae4ba
// 004ae469  8b5208               mov edx, dword ptr [edx + 8]
// 004ae46c  807a1800             cmp byte ptr [edx + 0x18], 0
// 004ae470  7519                 jne 0x4ae48b
// 004ae472  885918               mov byte ptr [ecx + 0x18], bl
// 004ae475  885a18               mov byte ptr [edx + 0x18], bl
// 004ae478  8b10                 mov edx, dword ptr [eax]
// 004ae47a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004ae47d  c6411800             mov byte ptr [ecx + 0x18], 0
// 004ae481  8b10                 mov edx, dword ptr [eax]
// 004ae483  8b7204               mov esi, dword ptr [edx + 4]
// 004ae486  e9aa000000           jmp 0x4ae535
// 004ae48b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004ae48e  750a                 jne 0x4ae49a
// 004ae490  8bf1                 mov esi, ecx
// 004ae492  56                   push esi
// 004ae493  8bcf                 mov ecx, edi
// 004ae495  e856d9ffff           call 0x4abdf0
// 004ae49a  8b4604               mov eax, dword ptr [esi + 4]
// 004ae49d  885818               mov byte ptr [eax + 0x18], bl
// 004ae4a0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ae4a3  8b5104               mov edx, dword ptr [ecx + 4]
// 004ae4a6  c6421800             mov byte ptr [edx + 0x18], 0
// 004ae4aa  8b4604               mov eax, dword ptr [esi + 4]
// 004ae4ad  8b4804               mov ecx, dword ptr [eax + 4]
// 004ae4b0  51                   push ecx
// 004ae4b1  8bcf                 mov ecx, edi
// 004ae4b3  e8a88e0d00           call 0x587360
// 004ae4b8  eb7b                 jmp 0x4ae535
// 004ae4ba  8b12                 mov edx, dword ptr [edx]
// 004ae4bc  807a1800             cmp byte ptr [edx + 0x18], 0
// 004ae4c0  7516                 jne 0x4ae4d8
// 004ae4c2  885918               mov byte ptr [ecx + 0x18], bl
// 004ae4c5  885a18               mov byte ptr [edx + 0x18], bl
// 004ae4c8  8b10                 mov edx, dword ptr [eax]
// 004ae4ca  8b4a04               mov ecx, dword ptr [edx + 4]
// 004ae4cd  c6411800             mov byte ptr [ecx + 0x18], 0
// 004ae4d1  8b10                 mov edx, dword ptr [eax]
// 004ae4d3  8b7204               mov esi, dword ptr [edx + 4]
// 004ae4d6  eb5d                 jmp 0x4ae535
// 004ae4d8  3b31                 cmp esi, dword ptr [ecx]
// 004ae4da  750a                 jne 0x4ae4e6
// 004ae4dc  8bf1                 mov esi, ecx
// 004ae4de  56                   push esi
// 004ae4df  8bcf                 mov ecx, edi
// 004ae4e1  e87a8e0d00           call 0x587360
// 004ae4e6  8b4604               mov eax, dword ptr [esi + 4]
// 004ae4e9  885818               mov byte ptr [eax + 0x18], bl
// 004ae4ec  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ae4ef  8b5104               mov edx, dword ptr [ecx + 4]
// 004ae4f2  c6421800             mov byte ptr [edx + 0x18], 0
// 004ae4f6  8b4604               mov eax, dword ptr [esi + 4]
// 004ae4f9  8b4004               mov eax, dword ptr [eax + 4]
// 004ae4fc  8b4808               mov ecx, dword ptr [eax + 8]
// 004ae4ff  8b11                 mov edx, dword ptr [ecx]
// 004ae501  895008               mov dword ptr [eax + 8], edx
// 004ae504  8b11                 mov edx, dword ptr [ecx]
// 004ae506  807a1900             cmp byte ptr [edx + 0x19], 0
// 004ae50a  7503                 jne 0x4ae50f
// 004ae50c  894204               mov dword ptr [edx + 4], eax
// 004ae50f  8b5004               mov edx, dword ptr [eax + 4]
// 004ae512  895104               mov dword ptr [ecx + 4], edx
// 004ae515  8b5718               mov edx, dword ptr [edi + 0x18]
// 004ae518  3b4204               cmp eax, dword ptr [edx + 4]
// 004ae51b  7505                 jne 0x4ae522
// 004ae51d  894a04               mov dword ptr [edx + 4], ecx
// 004ae520  eb0e                 jmp 0x4ae530
// 004ae522  8b5004               mov edx, dword ptr [eax + 4]
// 004ae525  3b02                 cmp eax, dword ptr [edx]
// 004ae527  7504                 jne 0x4ae52d
// 004ae529  890a                 mov dword ptr [edx], ecx
// 004ae52b  eb03                 jmp 0x4ae530
// 004ae52d  894a08               mov dword ptr [edx + 8], ecx
// 004ae530  8901                 mov dword ptr [ecx], eax
// 004ae532  894804               mov dword ptr [eax + 4], ecx
// 004ae535  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ae538  80791800             cmp byte ptr [ecx + 0x18], 0
// 004ae53c  8d4604               lea eax, [esi + 4]
// 004ae53f  0f841bffffff         je 0x4ae460
// 004ae545  8b5718               mov edx, dword ptr [edi + 0x18]
// 004ae548  8b4204               mov eax, dword ptr [edx + 4]
// 004ae54b  885818               mov byte ptr [eax + 0x18], bl
// 004ae54e  8b442464             mov eax, dword ptr [esp + 0x64]
// 004ae552  8b0f                 mov ecx, dword ptr [edi]
// 004ae554  5e                   pop esi
// 004ae555  896804               mov dword ptr [eax + 4], ebp
// 004ae558  5d                   pop ebp
// 004ae559  8908                 mov dword ptr [eax], ecx
// 004ae55b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004ae55f  5b                   pop ebx
// 004ae560  5f                   pop edi
// 004ae561  64890d00000000       mov dword ptr fs:[0], ecx
// 004ae568  83c450               add esp, 0x50
// 004ae56b  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
