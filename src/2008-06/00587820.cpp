// from server: 100% by auto
// roc 2008-06 00587820  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00587820
//
// 00587820  64a100000000         mov eax, dword ptr fs:[0]
// 00587826  6aff                 push -1
// 00587828  6842e87d00           push 0x7de842
// 0058782d  50                   push eax
// 0058782e  64892500000000       mov dword ptr fs:[0], esp
// 00587835  83ec44               sub esp, 0x44
// 00587838  57                   push edi
// 00587839  8bf9                 mov edi, ecx
// 0058783b  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 00587842  7259                 jb 0x58789d
// 00587844  688cb28000           push 0x80b28c
// 00587849  8d4c2408             lea ecx, [esp + 8]
// 0058784d  ff1558248000         call dword ptr [0x802458]
// 00587853  8d4c2420             lea ecx, [esp + 0x20]
// 00587857  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0058785f  ff1598288000         call dword ptr [0x802898]
// 00587865  8d442404             lea eax, [esp + 4]
// 00587869  50                   push eax
// 0058786a  8d4c2430             lea ecx, [esp + 0x30]
// 0058786e  c644245401           mov byte ptr [esp + 0x54], 1
// 00587873  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 0058787b  ff155c248000         call dword ptr [0x80245c]
// 00587881  68c00c8d00           push 0x8d0cc0
// 00587886  8d4c2424             lea ecx, [esp + 0x24]
// 0058788a  51                   push ecx
// 0058788b  c644245800           mov byte ptr [esp + 0x58], 0
// 00587890  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 00587898  e8ef9c1100           call 0x6a158c
// 0058789d  8b542464             mov edx, dword ptr [esp + 0x64]
// 005878a1  8b4718               mov eax, dword ptr [edi + 0x18]
// 005878a4  53                   push ebx
// 005878a5  55                   push ebp
// 005878a6  56                   push esi
// 005878a7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005878ab  6a00                 push 0
// 005878ad  52                   push edx
// 005878ae  50                   push eax
// 005878af  56                   push esi
// 005878b0  50                   push eax
// 005878b1  e88afdffff           call 0x587640
// 005878b6  8be8                 mov ebp, eax
// 005878b8  8b4718               mov eax, dword ptr [edi + 0x18]
// 005878bb  bb01000000           mov ebx, 1
// 005878c0  015f1c               add dword ptr [edi + 0x1c], ebx
// 005878c3  3bf0                 cmp esi, eax
// 005878c5  7510                 jne 0x5878d7
// 005878c7  896804               mov dword ptr [eax + 4], ebp
// 005878ca  8b4718               mov eax, dword ptr [edi + 0x18]
// 005878cd  8928                 mov dword ptr [eax], ebp
// 005878cf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005878d2  896908               mov dword ptr [ecx + 8], ebp
// 005878d5  eb22                 jmp 0x5878f9
// 005878d7  807c246800           cmp byte ptr [esp + 0x68], 0
// 005878dc  740d                 je 0x5878eb
// 005878de  892e                 mov dword ptr [esi], ebp
// 005878e0  8b4718               mov eax, dword ptr [edi + 0x18]
// 005878e3  3b30                 cmp esi, dword ptr [eax]
// 005878e5  7512                 jne 0x5878f9
// 005878e7  8928                 mov dword ptr [eax], ebp
// 005878e9  eb0e                 jmp 0x5878f9
// 005878eb  896e08               mov dword ptr [esi + 8], ebp
// 005878ee  8b4718               mov eax, dword ptr [edi + 0x18]
// 005878f1  3b7008               cmp esi, dword ptr [eax + 8]
// 005878f4  7503                 jne 0x5878f9
// 005878f6  896808               mov dword ptr [eax + 8], ebp
// 005878f9  8b5504               mov edx, dword ptr [ebp + 4]
// 005878fc  807a1800             cmp byte ptr [edx + 0x18], 0
// 00587900  8d4504               lea eax, [ebp + 4]
// 00587903  8bf5                 mov esi, ebp
// 00587905  0f85ea000000         jne 0x5879f5
// 0058790b  eb03                 jmp 0x587910
// 0058790d  8d4900               lea ecx, [ecx]
// 00587910  8b08                 mov ecx, dword ptr [eax]
// 00587912  8b5104               mov edx, dword ptr [ecx + 4]
// 00587915  3b0a                 cmp ecx, dword ptr [edx]
// 00587917  7551                 jne 0x58796a
// 00587919  8b5208               mov edx, dword ptr [edx + 8]
// 0058791c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00587920  7519                 jne 0x58793b
// 00587922  885918               mov byte ptr [ecx + 0x18], bl
// 00587925  885a18               mov byte ptr [edx + 0x18], bl
// 00587928  8b10                 mov edx, dword ptr [eax]
// 0058792a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0058792d  c6411800             mov byte ptr [ecx + 0x18], 0
// 00587931  8b10                 mov edx, dword ptr [eax]
// 00587933  8b7204               mov esi, dword ptr [edx + 4]
// 00587936  e9aa000000           jmp 0x5879e5
// 0058793b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0058793e  750a                 jne 0x58794a
// 00587940  8bf1                 mov esi, ecx
// 00587942  56                   push esi
// 00587943  8bcf                 mov ecx, edi
// 00587945  e8a644f2ff           call 0x4abdf0
// 0058794a  8b4604               mov eax, dword ptr [esi + 4]
// 0058794d  885818               mov byte ptr [eax + 0x18], bl
// 00587950  8b4e04               mov ecx, dword ptr [esi + 4]
// 00587953  8b5104               mov edx, dword ptr [ecx + 4]
// 00587956  c6421800             mov byte ptr [edx + 0x18], 0
// 0058795a  8b4604               mov eax, dword ptr [esi + 4]
// 0058795d  8b4804               mov ecx, dword ptr [eax + 4]
// 00587960  51                   push ecx
// 00587961  8bcf                 mov ecx, edi
// 00587963  e8f8f9ffff           call 0x587360
// 00587968  eb7b                 jmp 0x5879e5
// 0058796a  8b12                 mov edx, dword ptr [edx]
// 0058796c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00587970  7516                 jne 0x587988
// 00587972  885918               mov byte ptr [ecx + 0x18], bl
// 00587975  885a18               mov byte ptr [edx + 0x18], bl
// 00587978  8b10                 mov edx, dword ptr [eax]
// 0058797a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0058797d  c6411800             mov byte ptr [ecx + 0x18], 0
// 00587981  8b10                 mov edx, dword ptr [eax]
// 00587983  8b7204               mov esi, dword ptr [edx + 4]
// 00587986  eb5d                 jmp 0x5879e5
// 00587988  3b31                 cmp esi, dword ptr [ecx]
// 0058798a  750a                 jne 0x587996
// 0058798c  8bf1                 mov esi, ecx
// 0058798e  56                   push esi
// 0058798f  8bcf                 mov ecx, edi
// 00587991  e8caf9ffff           call 0x587360
// 00587996  8b4604               mov eax, dword ptr [esi + 4]
// 00587999  885818               mov byte ptr [eax + 0x18], bl
// 0058799c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0058799f  8b5104               mov edx, dword ptr [ecx + 4]
// 005879a2  c6421800             mov byte ptr [edx + 0x18], 0
// 005879a6  8b4604               mov eax, dword ptr [esi + 4]
// 005879a9  8b4004               mov eax, dword ptr [eax + 4]
// 005879ac  8b4808               mov ecx, dword ptr [eax + 8]
// 005879af  8b11                 mov edx, dword ptr [ecx]
// 005879b1  895008               mov dword ptr [eax + 8], edx
// 005879b4  8b11                 mov edx, dword ptr [ecx]
// 005879b6  807a1900             cmp byte ptr [edx + 0x19], 0
// 005879ba  7503                 jne 0x5879bf
// 005879bc  894204               mov dword ptr [edx + 4], eax
// 005879bf  8b5004               mov edx, dword ptr [eax + 4]
// 005879c2  895104               mov dword ptr [ecx + 4], edx
// 005879c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 005879c8  3b4204               cmp eax, dword ptr [edx + 4]
// 005879cb  7505                 jne 0x5879d2
// 005879cd  894a04               mov dword ptr [edx + 4], ecx
// 005879d0  eb0e                 jmp 0x5879e0
// 005879d2  8b5004               mov edx, dword ptr [eax + 4]
// 005879d5  3b02                 cmp eax, dword ptr [edx]
// 005879d7  7504                 jne 0x5879dd
// 005879d9  890a                 mov dword ptr [edx], ecx
// 005879db  eb03                 jmp 0x5879e0
// 005879dd  894a08               mov dword ptr [edx + 8], ecx
// 005879e0  8901                 mov dword ptr [ecx], eax
// 005879e2  894804               mov dword ptr [eax + 4], ecx
// 005879e5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005879e8  80791800             cmp byte ptr [ecx + 0x18], 0
// 005879ec  8d4604               lea eax, [esi + 4]
// 005879ef  0f841bffffff         je 0x587910
// 005879f5  8b5718               mov edx, dword ptr [edi + 0x18]
// 005879f8  8b4204               mov eax, dword ptr [edx + 4]
// 005879fb  885818               mov byte ptr [eax + 0x18], bl
// 005879fe  8b442464             mov eax, dword ptr [esp + 0x64]
// 00587a02  8b0f                 mov ecx, dword ptr [edi]
// 00587a04  5e                   pop esi
// 00587a05  896804               mov dword ptr [eax + 4], ebp
// 00587a08  5d                   pop ebp
// 00587a09  8908                 mov dword ptr [eax], ecx
// 00587a0b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00587a0f  5b                   pop ebx
// 00587a10  5f                   pop edi
// 00587a11  64890d00000000       mov dword ptr fs:[0], ecx
// 00587a18  83c450               add esp, 0x50
// 00587a1b  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
