// from server: 100% by auto
// roc 2009-12 0068b6f0  unit: ArchiveBinder  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0068b6f0
//
// 0068b6f0  64a100000000         mov eax, dword ptr fs:[0]
// 0068b6f6  6aff                 push -1
// 0068b6f8  6812699500           push 0x956912
// 0068b6fd  50                   push eax
// 0068b6fe  64892500000000       mov dword ptr fs:[0], esp
// 0068b705  83ec44               sub esp, 0x44
// 0068b708  57                   push edi
// 0068b709  8bf9                 mov edi, ecx
// 0068b70b  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 0068b712  7259                 jb 0x68b76d
// 0068b714  6800f59900           push 0x99f500
// 0068b719  8d4c2408             lea ecx, [esp + 8]
// 0068b71d  ff15f4b69800         call dword ptr [0x98b6f4]
// 0068b723  8d4c2420             lea ecx, [esp + 0x20]
// 0068b727  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0068b72f  ff1554b79800         call dword ptr [0x98b754]
// 0068b735  8d442404             lea eax, [esp + 4]
// 0068b739  50                   push eax
// 0068b73a  8d4c2430             lea ecx, [esp + 0x30]
// 0068b73e  c644245401           mov byte ptr [esp + 0x54], 1
// 0068b743  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 0068b74b  ff15f0b69800         call dword ptr [0x98b6f0]
// 0068b751  68e4efa800           push 0xa8efe4
// 0068b756  8d4c2424             lea ecx, [esp + 0x24]
// 0068b75a  51                   push ecx
// 0068b75b  c644245800           mov byte ptr [esp + 0x58], 0
// 0068b760  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 0068b768  e80b911600           call 0x7f4878
// 0068b76d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0068b771  8b4718               mov eax, dword ptr [edi + 0x18]
// 0068b774  53                   push ebx
// 0068b775  55                   push ebp
// 0068b776  56                   push esi
// 0068b777  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0068b77b  6a00                 push 0
// 0068b77d  52                   push edx
// 0068b77e  50                   push eax
// 0068b77f  56                   push esi
// 0068b780  50                   push eax
// 0068b781  e84a320b00           call 0x73e9d0
// 0068b786  8be8                 mov ebp, eax
// 0068b788  8b4718               mov eax, dword ptr [edi + 0x18]
// 0068b78b  bb01000000           mov ebx, 1
// 0068b790  015f1c               add dword ptr [edi + 0x1c], ebx
// 0068b793  3bf0                 cmp esi, eax
// 0068b795  7510                 jne 0x68b7a7
// 0068b797  896804               mov dword ptr [eax + 4], ebp
// 0068b79a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0068b79d  8928                 mov dword ptr [eax], ebp
// 0068b79f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0068b7a2  896908               mov dword ptr [ecx + 8], ebp
// 0068b7a5  eb22                 jmp 0x68b7c9
// 0068b7a7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0068b7ac  740d                 je 0x68b7bb
// 0068b7ae  892e                 mov dword ptr [esi], ebp
// 0068b7b0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0068b7b3  3b30                 cmp esi, dword ptr [eax]
// 0068b7b5  7512                 jne 0x68b7c9
// 0068b7b7  8928                 mov dword ptr [eax], ebp
// 0068b7b9  eb0e                 jmp 0x68b7c9
// 0068b7bb  896e08               mov dword ptr [esi + 8], ebp
// 0068b7be  8b4718               mov eax, dword ptr [edi + 0x18]
// 0068b7c1  3b7008               cmp esi, dword ptr [eax + 8]
// 0068b7c4  7503                 jne 0x68b7c9
// 0068b7c6  896808               mov dword ptr [eax + 8], ebp
// 0068b7c9  8b5504               mov edx, dword ptr [ebp + 4]
// 0068b7cc  807a3000             cmp byte ptr [edx + 0x30], 0
// 0068b7d0  8d4504               lea eax, [ebp + 4]
// 0068b7d3  8bf5                 mov esi, ebp
// 0068b7d5  0f85ea000000         jne 0x68b8c5
// 0068b7db  eb03                 jmp 0x68b7e0
// 0068b7dd  8d4900               lea ecx, [ecx]
// 0068b7e0  8b08                 mov ecx, dword ptr [eax]
// 0068b7e2  8b5104               mov edx, dword ptr [ecx + 4]
// 0068b7e5  3b0a                 cmp ecx, dword ptr [edx]
// 0068b7e7  7551                 jne 0x68b83a
// 0068b7e9  8b5208               mov edx, dword ptr [edx + 8]
// 0068b7ec  807a3000             cmp byte ptr [edx + 0x30], 0
// 0068b7f0  7519                 jne 0x68b80b
// 0068b7f2  885930               mov byte ptr [ecx + 0x30], bl
// 0068b7f5  885a30               mov byte ptr [edx + 0x30], bl
// 0068b7f8  8b10                 mov edx, dword ptr [eax]
// 0068b7fa  8b4a04               mov ecx, dword ptr [edx + 4]
// 0068b7fd  c6413000             mov byte ptr [ecx + 0x30], 0
// 0068b801  8b10                 mov edx, dword ptr [eax]
// 0068b803  8b7204               mov esi, dword ptr [edx + 4]
// 0068b806  e9aa000000           jmp 0x68b8b5
// 0068b80b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0068b80e  750a                 jne 0x68b81a
// 0068b810  8bf1                 mov esi, ecx
// 0068b812  56                   push esi
// 0068b813  8bcf                 mov ecx, edi
// 0068b815  e8f67fe8ff           call 0x513810
// 0068b81a  8b4604               mov eax, dword ptr [esi + 4]
// 0068b81d  885830               mov byte ptr [eax + 0x30], bl
// 0068b820  8b4e04               mov ecx, dword ptr [esi + 4]
// 0068b823  8b5104               mov edx, dword ptr [ecx + 4]
// 0068b826  c6423000             mov byte ptr [edx + 0x30], 0
// 0068b82a  8b4604               mov eax, dword ptr [esi + 4]
// 0068b82d  8b4804               mov ecx, dword ptr [eax + 4]
// 0068b830  51                   push ecx
// 0068b831  8bcf                 mov ecx, edi
// 0068b833  e868740700           call 0x702ca0
// 0068b838  eb7b                 jmp 0x68b8b5
// 0068b83a  8b12                 mov edx, dword ptr [edx]
// 0068b83c  807a3000             cmp byte ptr [edx + 0x30], 0
// 0068b840  7516                 jne 0x68b858
// 0068b842  885930               mov byte ptr [ecx + 0x30], bl
// 0068b845  885a30               mov byte ptr [edx + 0x30], bl
// 0068b848  8b10                 mov edx, dword ptr [eax]
// 0068b84a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0068b84d  c6413000             mov byte ptr [ecx + 0x30], 0
// 0068b851  8b10                 mov edx, dword ptr [eax]
// 0068b853  8b7204               mov esi, dword ptr [edx + 4]
// 0068b856  eb5d                 jmp 0x68b8b5
// 0068b858  3b31                 cmp esi, dword ptr [ecx]
// 0068b85a  750a                 jne 0x68b866
// 0068b85c  8bf1                 mov esi, ecx
// 0068b85e  56                   push esi
// 0068b85f  8bcf                 mov ecx, edi
// 0068b861  e83a740700           call 0x702ca0
// 0068b866  8b4604               mov eax, dword ptr [esi + 4]
// 0068b869  885830               mov byte ptr [eax + 0x30], bl
// 0068b86c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0068b86f  8b5104               mov edx, dword ptr [ecx + 4]
// 0068b872  c6423000             mov byte ptr [edx + 0x30], 0
// 0068b876  8b4604               mov eax, dword ptr [esi + 4]
// 0068b879  8b4004               mov eax, dword ptr [eax + 4]
// 0068b87c  8b4808               mov ecx, dword ptr [eax + 8]
// 0068b87f  8b11                 mov edx, dword ptr [ecx]
// 0068b881  895008               mov dword ptr [eax + 8], edx
// 0068b884  8b11                 mov edx, dword ptr [ecx]
// 0068b886  807a3100             cmp byte ptr [edx + 0x31], 0
// 0068b88a  7503                 jne 0x68b88f
// 0068b88c  894204               mov dword ptr [edx + 4], eax
// 0068b88f  8b5004               mov edx, dword ptr [eax + 4]
// 0068b892  895104               mov dword ptr [ecx + 4], edx
// 0068b895  8b5718               mov edx, dword ptr [edi + 0x18]
// 0068b898  3b4204               cmp eax, dword ptr [edx + 4]
// 0068b89b  7505                 jne 0x68b8a2
// 0068b89d  894a04               mov dword ptr [edx + 4], ecx
// 0068b8a0  eb0e                 jmp 0x68b8b0
// 0068b8a2  8b5004               mov edx, dword ptr [eax + 4]
// 0068b8a5  3b02                 cmp eax, dword ptr [edx]
// 0068b8a7  7504                 jne 0x68b8ad
// 0068b8a9  890a                 mov dword ptr [edx], ecx
// 0068b8ab  eb03                 jmp 0x68b8b0
// 0068b8ad  894a08               mov dword ptr [edx + 8], ecx
// 0068b8b0  8901                 mov dword ptr [ecx], eax
// 0068b8b2  894804               mov dword ptr [eax + 4], ecx
// 0068b8b5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0068b8b8  80793000             cmp byte ptr [ecx + 0x30], 0
// 0068b8bc  8d4604               lea eax, [esi + 4]
// 0068b8bf  0f841bffffff         je 0x68b7e0
// 0068b8c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0068b8c8  8b4204               mov eax, dword ptr [edx + 4]
// 0068b8cb  885830               mov byte ptr [eax + 0x30], bl
// 0068b8ce  8b442464             mov eax, dword ptr [esp + 0x64]
// 0068b8d2  8b0f                 mov ecx, dword ptr [edi]
// 0068b8d4  5e                   pop esi
// 0068b8d5  896804               mov dword ptr [eax + 4], ebp
// 0068b8d8  5d                   pop ebp
// 0068b8d9  8908                 mov dword ptr [eax], ecx
// 0068b8db  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0068b8df  5b                   pop ebx
// 0068b8e0  5f                   pop edi
// 0068b8e1  64890d00000000       mov dword ptr fs:[0], ecx
// 0068b8e8  83c450               add esp, 0x50
// 0068b8eb  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
