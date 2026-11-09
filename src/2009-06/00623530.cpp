// from server: 100% by auto
// roc 2009-06 00623530  unit: ArchiveBinder  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00623530
//
// 00623530  64a100000000         mov eax, dword ptr fs:[0]
// 00623536  6aff                 push -1
// 00623538  68b2db8500           push 0x85dbb2
// 0062353d  50                   push eax
// 0062353e  64892500000000       mov dword ptr fs:[0], esp
// 00623545  83ec44               sub esp, 0x44
// 00623548  57                   push edi
// 00623549  8bf9                 mov edi, ecx
// 0062354b  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 00623552  7259                 jb 0x6235ad
// 00623554  68c0c98a00           push 0x8ac9c0
// 00623559  8d4c2408             lea ecx, [esp + 8]
// 0062355d  ff15b4e48900         call dword ptr [0x89e4b4]
// 00623563  8d4c2420             lea ecx, [esp + 0x20]
// 00623567  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0062356f  ff15b8e98900         call dword ptr [0x89e9b8]
// 00623575  8d442404             lea eax, [esp + 4]
// 00623579  50                   push eax
// 0062357a  8d4c2430             lea ecx, [esp + 0x30]
// 0062357e  c644245401           mov byte ptr [esp + 0x54], 1
// 00623583  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 0062358b  ff15b8e48900         call dword ptr [0x89e4b8]
// 00623591  6834929700           push 0x979234
// 00623596  8d4c2424             lea ecx, [esp + 0x24]
// 0062359a  51                   push ecx
// 0062359b  c644245800           mov byte ptr [esp + 0x58], 0
// 006235a0  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 006235a8  e89d640f00           call 0x719a4a
// 006235ad  8b542464             mov edx, dword ptr [esp + 0x64]
// 006235b1  8b4718               mov eax, dword ptr [edi + 0x18]
// 006235b4  53                   push ebx
// 006235b5  55                   push ebp
// 006235b6  56                   push esi
// 006235b7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006235bb  6a00                 push 0
// 006235bd  52                   push edx
// 006235be  50                   push eax
// 006235bf  56                   push esi
// 006235c0  50                   push eax
// 006235c1  e8ca73fbff           call 0x5da990
// 006235c6  8be8                 mov ebp, eax
// 006235c8  8b4718               mov eax, dword ptr [edi + 0x18]
// 006235cb  bb01000000           mov ebx, 1
// 006235d0  015f1c               add dword ptr [edi + 0x1c], ebx
// 006235d3  3bf0                 cmp esi, eax
// 006235d5  7510                 jne 0x6235e7
// 006235d7  896804               mov dword ptr [eax + 4], ebp
// 006235da  8b4718               mov eax, dword ptr [edi + 0x18]
// 006235dd  8928                 mov dword ptr [eax], ebp
// 006235df  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006235e2  896908               mov dword ptr [ecx + 8], ebp
// 006235e5  eb22                 jmp 0x623609
// 006235e7  807c246800           cmp byte ptr [esp + 0x68], 0
// 006235ec  740d                 je 0x6235fb
// 006235ee  892e                 mov dword ptr [esi], ebp
// 006235f0  8b4718               mov eax, dword ptr [edi + 0x18]
// 006235f3  3b30                 cmp esi, dword ptr [eax]
// 006235f5  7512                 jne 0x623609
// 006235f7  8928                 mov dword ptr [eax], ebp
// 006235f9  eb0e                 jmp 0x623609
// 006235fb  896e08               mov dword ptr [esi + 8], ebp
// 006235fe  8b4718               mov eax, dword ptr [edi + 0x18]
// 00623601  3b7008               cmp esi, dword ptr [eax + 8]
// 00623604  7503                 jne 0x623609
// 00623606  896808               mov dword ptr [eax + 8], ebp
// 00623609  8b5504               mov edx, dword ptr [ebp + 4]
// 0062360c  807a3000             cmp byte ptr [edx + 0x30], 0
// 00623610  8d4504               lea eax, [ebp + 4]
// 00623613  8bf5                 mov esi, ebp
// 00623615  0f85ea000000         jne 0x623705
// 0062361b  eb03                 jmp 0x623620
// 0062361d  8d4900               lea ecx, [ecx]
// 00623620  8b08                 mov ecx, dword ptr [eax]
// 00623622  8b5104               mov edx, dword ptr [ecx + 4]
// 00623625  3b0a                 cmp ecx, dword ptr [edx]
// 00623627  7551                 jne 0x62367a
// 00623629  8b5208               mov edx, dword ptr [edx + 8]
// 0062362c  807a3000             cmp byte ptr [edx + 0x30], 0
// 00623630  7519                 jne 0x62364b
// 00623632  885930               mov byte ptr [ecx + 0x30], bl
// 00623635  885a30               mov byte ptr [edx + 0x30], bl
// 00623638  8b10                 mov edx, dword ptr [eax]
// 0062363a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0062363d  c6413000             mov byte ptr [ecx + 0x30], 0
// 00623641  8b10                 mov edx, dword ptr [eax]
// 00623643  8b7204               mov esi, dword ptr [edx + 4]
// 00623646  e9aa000000           jmp 0x6236f5
// 0062364b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0062364e  750a                 jne 0x62365a
// 00623650  8bf1                 mov esi, ecx
// 00623652  56                   push esi
// 00623653  8bcf                 mov ecx, edi
// 00623655  e816ecffff           call 0x622270
// 0062365a  8b4604               mov eax, dword ptr [esi + 4]
// 0062365d  885830               mov byte ptr [eax + 0x30], bl
// 00623660  8b4e04               mov ecx, dword ptr [esi + 4]
// 00623663  8b5104               mov edx, dword ptr [ecx + 4]
// 00623666  c6423000             mov byte ptr [edx + 0x30], 0
// 0062366a  8b4604               mov eax, dword ptr [esi + 4]
// 0062366d  8b4804               mov ecx, dword ptr [eax + 4]
// 00623670  51                   push ecx
// 00623671  8bcf                 mov ecx, edi
// 00623673  e828e90b00           call 0x6e1fa0
// 00623678  eb7b                 jmp 0x6236f5
// 0062367a  8b12                 mov edx, dword ptr [edx]
// 0062367c  807a3000             cmp byte ptr [edx + 0x30], 0
// 00623680  7516                 jne 0x623698
// 00623682  885930               mov byte ptr [ecx + 0x30], bl
// 00623685  885a30               mov byte ptr [edx + 0x30], bl
// 00623688  8b10                 mov edx, dword ptr [eax]
// 0062368a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0062368d  c6413000             mov byte ptr [ecx + 0x30], 0
// 00623691  8b10                 mov edx, dword ptr [eax]
// 00623693  8b7204               mov esi, dword ptr [edx + 4]
// 00623696  eb5d                 jmp 0x6236f5
// 00623698  3b31                 cmp esi, dword ptr [ecx]
// 0062369a  750a                 jne 0x6236a6
// 0062369c  8bf1                 mov esi, ecx
// 0062369e  56                   push esi
// 0062369f  8bcf                 mov ecx, edi
// 006236a1  e8fae80b00           call 0x6e1fa0
// 006236a6  8b4604               mov eax, dword ptr [esi + 4]
// 006236a9  885830               mov byte ptr [eax + 0x30], bl
// 006236ac  8b4e04               mov ecx, dword ptr [esi + 4]
// 006236af  8b5104               mov edx, dword ptr [ecx + 4]
// 006236b2  c6423000             mov byte ptr [edx + 0x30], 0
// 006236b6  8b4604               mov eax, dword ptr [esi + 4]
// 006236b9  8b4004               mov eax, dword ptr [eax + 4]
// 006236bc  8b4808               mov ecx, dword ptr [eax + 8]
// 006236bf  8b11                 mov edx, dword ptr [ecx]
// 006236c1  895008               mov dword ptr [eax + 8], edx
// 006236c4  8b11                 mov edx, dword ptr [ecx]
// 006236c6  807a3100             cmp byte ptr [edx + 0x31], 0
// 006236ca  7503                 jne 0x6236cf
// 006236cc  894204               mov dword ptr [edx + 4], eax
// 006236cf  8b5004               mov edx, dword ptr [eax + 4]
// 006236d2  895104               mov dword ptr [ecx + 4], edx
// 006236d5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006236d8  3b4204               cmp eax, dword ptr [edx + 4]
// 006236db  7505                 jne 0x6236e2
// 006236dd  894a04               mov dword ptr [edx + 4], ecx
// 006236e0  eb0e                 jmp 0x6236f0
// 006236e2  8b5004               mov edx, dword ptr [eax + 4]
// 006236e5  3b02                 cmp eax, dword ptr [edx]
// 006236e7  7504                 jne 0x6236ed
// 006236e9  890a                 mov dword ptr [edx], ecx
// 006236eb  eb03                 jmp 0x6236f0
// 006236ed  894a08               mov dword ptr [edx + 8], ecx
// 006236f0  8901                 mov dword ptr [ecx], eax
// 006236f2  894804               mov dword ptr [eax + 4], ecx
// 006236f5  8b4e04               mov ecx, dword ptr [esi + 4]
// 006236f8  80793000             cmp byte ptr [ecx + 0x30], 0
// 006236fc  8d4604               lea eax, [esi + 4]
// 006236ff  0f841bffffff         je 0x623620
// 00623705  8b5718               mov edx, dword ptr [edi + 0x18]
// 00623708  8b4204               mov eax, dword ptr [edx + 4]
// 0062370b  885830               mov byte ptr [eax + 0x30], bl
// 0062370e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00623712  8b0f                 mov ecx, dword ptr [edi]
// 00623714  5e                   pop esi
// 00623715  896804               mov dword ptr [eax + 4], ebp
// 00623718  5d                   pop ebp
// 00623719  8908                 mov dword ptr [eax], ecx
// 0062371b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0062371f  5b                   pop ebx
// 00623720  5f                   pop edi
// 00623721  64890d00000000       mov dword ptr fs:[0], ecx
// 00623728  83c450               add esp, 0x50
// 0062372b  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
