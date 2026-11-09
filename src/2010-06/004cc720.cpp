// from server: 100% by auto
// roc 2010-06 004cc720  unit: RBX::Network::Players  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004cc720
//
// 004cc720  64a100000000         mov eax, dword ptr fs:[0]
// 004cc726  6aff                 push -1
// 004cc728  68e22f9a00           push 0x9a2fe2
// 004cc72d  50                   push eax
// 004cc72e  64892500000000       mov dword ptr fs:[0], esp
// 004cc735  83ec44               sub esp, 0x44
// 004cc738  57                   push edi
// 004cc739  8bf9                 mov edi, ecx
// 004cc73b  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 004cc742  7259                 jb 0x4cc79d
// 004cc744  68a800a000           push 0xa000a8
// 004cc749  8d4c2408             lea ecx, [esp + 8]
// 004cc74d  ff1510a49e00         call dword ptr [0x9ea410]
// 004cc753  8d4c2420             lea ecx, [esp + 0x20]
// 004cc757  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004cc75f  ff1518a99e00         call dword ptr [0x9ea918]
// 004cc765  8d442404             lea eax, [esp + 4]
// 004cc769  50                   push eax
// 004cc76a  8d4c2430             lea ecx, [esp + 0x30]
// 004cc76e  c644245401           mov byte ptr [esp + 0x54], 1
// 004cc773  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 004cc77b  ff150ca49e00         call dword ptr [0x9ea40c]
// 004cc781  68601bb000           push 0xb01b60
// 004cc786  8d4c2424             lea ecx, [esp + 0x24]
// 004cc78a  51                   push ecx
// 004cc78b  c644245800           mov byte ptr [esp + 0x58], 0
// 004cc790  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 004cc798  e815c22d00           call 0x7a89b2
// 004cc79d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004cc7a1  8b4718               mov eax, dword ptr [edi + 0x18]
// 004cc7a4  53                   push ebx
// 004cc7a5  55                   push ebp
// 004cc7a6  56                   push esi
// 004cc7a7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004cc7ab  6a00                 push 0
// 004cc7ad  52                   push edx
// 004cc7ae  50                   push eax
// 004cc7af  56                   push esi
// 004cc7b0  50                   push eax
// 004cc7b1  e86aeeffff           call 0x4cb620
// 004cc7b6  8be8                 mov ebp, eax
// 004cc7b8  8b4718               mov eax, dword ptr [edi + 0x18]
// 004cc7bb  bb01000000           mov ebx, 1
// 004cc7c0  015f1c               add dword ptr [edi + 0x1c], ebx
// 004cc7c3  3bf0                 cmp esi, eax
// 004cc7c5  7510                 jne 0x4cc7d7
// 004cc7c7  896804               mov dword ptr [eax + 4], ebp
// 004cc7ca  8b4718               mov eax, dword ptr [edi + 0x18]
// 004cc7cd  8928                 mov dword ptr [eax], ebp
// 004cc7cf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004cc7d2  896908               mov dword ptr [ecx + 8], ebp
// 004cc7d5  eb22                 jmp 0x4cc7f9
// 004cc7d7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004cc7dc  740d                 je 0x4cc7eb
// 004cc7de  892e                 mov dword ptr [esi], ebp
// 004cc7e0  8b4718               mov eax, dword ptr [edi + 0x18]
// 004cc7e3  3b30                 cmp esi, dword ptr [eax]
// 004cc7e5  7512                 jne 0x4cc7f9
// 004cc7e7  8928                 mov dword ptr [eax], ebp
// 004cc7e9  eb0e                 jmp 0x4cc7f9
// 004cc7eb  896e08               mov dword ptr [esi + 8], ebp
// 004cc7ee  8b4718               mov eax, dword ptr [edi + 0x18]
// 004cc7f1  3b7008               cmp esi, dword ptr [eax + 8]
// 004cc7f4  7503                 jne 0x4cc7f9
// 004cc7f6  896808               mov dword ptr [eax + 8], ebp
// 004cc7f9  8b5504               mov edx, dword ptr [ebp + 4]
// 004cc7fc  807a3000             cmp byte ptr [edx + 0x30], 0
// 004cc800  8d4504               lea eax, [ebp + 4]
// 004cc803  8bf5                 mov esi, ebp
// 004cc805  0f85ea000000         jne 0x4cc8f5
// 004cc80b  eb03                 jmp 0x4cc810
// 004cc80d  8d4900               lea ecx, [ecx]
// 004cc810  8b08                 mov ecx, dword ptr [eax]
// 004cc812  8b5104               mov edx, dword ptr [ecx + 4]
// 004cc815  3b0a                 cmp ecx, dword ptr [edx]
// 004cc817  7551                 jne 0x4cc86a
// 004cc819  8b5208               mov edx, dword ptr [edx + 8]
// 004cc81c  807a3000             cmp byte ptr [edx + 0x30], 0
// 004cc820  7519                 jne 0x4cc83b
// 004cc822  885930               mov byte ptr [ecx + 0x30], bl
// 004cc825  885a30               mov byte ptr [edx + 0x30], bl
// 004cc828  8b10                 mov edx, dword ptr [eax]
// 004cc82a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004cc82d  c6413000             mov byte ptr [ecx + 0x30], 0
// 004cc831  8b10                 mov edx, dword ptr [eax]
// 004cc833  8b7204               mov esi, dword ptr [edx + 4]
// 004cc836  e9aa000000           jmp 0x4cc8e5
// 004cc83b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004cc83e  750a                 jne 0x4cc84a
// 004cc840  8bf1                 mov esi, ecx
// 004cc842  56                   push esi
// 004cc843  8bcf                 mov ecx, edi
// 004cc845  e8d62c1900           call 0x65f520
// 004cc84a  8b4604               mov eax, dword ptr [esi + 4]
// 004cc84d  885830               mov byte ptr [eax + 0x30], bl
// 004cc850  8b4e04               mov ecx, dword ptr [esi + 4]
// 004cc853  8b5104               mov edx, dword ptr [ecx + 4]
// 004cc856  c6423000             mov byte ptr [edx + 0x30], 0
// 004cc85a  8b4604               mov eax, dword ptr [esi + 4]
// 004cc85d  8b4804               mov ecx, dword ptr [eax + 4]
// 004cc860  51                   push ecx
// 004cc861  8bcf                 mov ecx, edi
// 004cc863  e8e835ffff           call 0x4bfe50
// 004cc868  eb7b                 jmp 0x4cc8e5
// 004cc86a  8b12                 mov edx, dword ptr [edx]
// 004cc86c  807a3000             cmp byte ptr [edx + 0x30], 0
// 004cc870  7516                 jne 0x4cc888
// 004cc872  885930               mov byte ptr [ecx + 0x30], bl
// 004cc875  885a30               mov byte ptr [edx + 0x30], bl
// 004cc878  8b10                 mov edx, dword ptr [eax]
// 004cc87a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004cc87d  c6413000             mov byte ptr [ecx + 0x30], 0
// 004cc881  8b10                 mov edx, dword ptr [eax]
// 004cc883  8b7204               mov esi, dword ptr [edx + 4]
// 004cc886  eb5d                 jmp 0x4cc8e5
// 004cc888  3b31                 cmp esi, dword ptr [ecx]
// 004cc88a  750a                 jne 0x4cc896
// 004cc88c  8bf1                 mov esi, ecx
// 004cc88e  56                   push esi
// 004cc88f  8bcf                 mov ecx, edi
// 004cc891  e8ba35ffff           call 0x4bfe50
// 004cc896  8b4604               mov eax, dword ptr [esi + 4]
// 004cc899  885830               mov byte ptr [eax + 0x30], bl
// 004cc89c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004cc89f  8b5104               mov edx, dword ptr [ecx + 4]
// 004cc8a2  c6423000             mov byte ptr [edx + 0x30], 0
// 004cc8a6  8b4604               mov eax, dword ptr [esi + 4]
// 004cc8a9  8b4004               mov eax, dword ptr [eax + 4]
// 004cc8ac  8b4808               mov ecx, dword ptr [eax + 8]
// 004cc8af  8b11                 mov edx, dword ptr [ecx]
// 004cc8b1  895008               mov dword ptr [eax + 8], edx
// 004cc8b4  8b11                 mov edx, dword ptr [ecx]
// 004cc8b6  807a3100             cmp byte ptr [edx + 0x31], 0
// 004cc8ba  7503                 jne 0x4cc8bf
// 004cc8bc  894204               mov dword ptr [edx + 4], eax
// 004cc8bf  8b5004               mov edx, dword ptr [eax + 4]
// 004cc8c2  895104               mov dword ptr [ecx + 4], edx
// 004cc8c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004cc8c8  3b4204               cmp eax, dword ptr [edx + 4]
// 004cc8cb  7505                 jne 0x4cc8d2
// 004cc8cd  894a04               mov dword ptr [edx + 4], ecx
// 004cc8d0  eb0e                 jmp 0x4cc8e0
// 004cc8d2  8b5004               mov edx, dword ptr [eax + 4]
// 004cc8d5  3b02                 cmp eax, dword ptr [edx]
// 004cc8d7  7504                 jne 0x4cc8dd
// 004cc8d9  890a                 mov dword ptr [edx], ecx
// 004cc8db  eb03                 jmp 0x4cc8e0
// 004cc8dd  894a08               mov dword ptr [edx + 8], ecx
// 004cc8e0  8901                 mov dword ptr [ecx], eax
// 004cc8e2  894804               mov dword ptr [eax + 4], ecx
// 004cc8e5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004cc8e8  80793000             cmp byte ptr [ecx + 0x30], 0
// 004cc8ec  8d4604               lea eax, [esi + 4]
// 004cc8ef  0f841bffffff         je 0x4cc810
// 004cc8f5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004cc8f8  8b4204               mov eax, dword ptr [edx + 4]
// 004cc8fb  885830               mov byte ptr [eax + 0x30], bl
// 004cc8fe  8b442464             mov eax, dword ptr [esp + 0x64]
// 004cc902  8b0f                 mov ecx, dword ptr [edi]
// 004cc904  5e                   pop esi
// 004cc905  896804               mov dword ptr [eax + 4], ebp
// 004cc908  5d                   pop ebp
// 004cc909  8908                 mov dword ptr [eax], ecx
// 004cc90b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004cc90f  5b                   pop ebx
// 004cc910  5f                   pop edi
// 004cc911  64890d00000000       mov dword ptr fs:[0], ecx
// 004cc918  83c450               add esp, 0x50
// 004cc91b  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
