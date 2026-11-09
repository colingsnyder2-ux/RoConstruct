// from server: 100% by auto
// roc 2007-08 00583630  unit: RBX::VHat::?$FactoryProduct  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00583630
//
// 00583630  64a100000000         mov eax, dword ptr fs:[0]
// 00583636  6aff                 push -1
// 00583638  68b2417500           push 0x7541b2
// 0058363d  50                   push eax
// 0058363e  64892500000000       mov dword ptr fs:[0], esp
// 00583645  83ec44               sub esp, 0x44
// 00583648  57                   push edi
// 00583649  8bf9                 mov edi, ecx
// 0058364b  817f08cbcccc0c       cmp dword ptr [edi + 8], 0xccccccb
// 00583652  7259                 jb 0x5836ad
// 00583654  68904f7800           push 0x784f90
// 00583659  8d4c2408             lea ecx, [esp + 8]
// 0058365d  ff1598e67700         call dword ptr [0x77e698]
// 00583663  8d4c2420             lea ecx, [esp + 0x20]
// 00583667  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0058366f  ff15f8e67700         call dword ptr [0x77e6f8]
// 00583675  8d442404             lea eax, [esp + 4]
// 00583679  50                   push eax
// 0058367a  8d4c2430             lea ecx, [esp + 0x30]
// 0058367e  c644245401           mov byte ptr [esp + 0x54], 1
// 00583683  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 0058368b  ff159ce67700         call dword ptr [0x77e69c]
// 00583691  6878f78300           push 0x83f778
// 00583696  8d4c2424             lea ecx, [esp + 0x24]
// 0058369a  51                   push ecx
// 0058369b  c644245800           mov byte ptr [esp + 0x58], 0
// 005836a0  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 005836a8  e8f1d40a00           call 0x630b9e
// 005836ad  8b542464             mov edx, dword ptr [esp + 0x64]
// 005836b1  8b4704               mov eax, dword ptr [edi + 4]
// 005836b4  53                   push ebx
// 005836b5  55                   push ebp
// 005836b6  56                   push esi
// 005836b7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005836bb  6a00                 push 0
// 005836bd  52                   push edx
// 005836be  50                   push eax
// 005836bf  56                   push esi
// 005836c0  50                   push eax
// 005836c1  e8eafdffff           call 0x5834b0
// 005836c6  8be8                 mov ebp, eax
// 005836c8  8b4704               mov eax, dword ptr [edi + 4]
// 005836cb  bb01000000           mov ebx, 1
// 005836d0  015f08               add dword ptr [edi + 8], ebx
// 005836d3  3bf0                 cmp esi, eax
// 005836d5  7510                 jne 0x5836e7
// 005836d7  896804               mov dword ptr [eax + 4], ebp
// 005836da  8b4704               mov eax, dword ptr [edi + 4]
// 005836dd  8928                 mov dword ptr [eax], ebp
// 005836df  8b4f04               mov ecx, dword ptr [edi + 4]
// 005836e2  896908               mov dword ptr [ecx + 8], ebp
// 005836e5  eb22                 jmp 0x583709
// 005836e7  807c246800           cmp byte ptr [esp + 0x68], 0
// 005836ec  740d                 je 0x5836fb
// 005836ee  892e                 mov dword ptr [esi], ebp
// 005836f0  8b4704               mov eax, dword ptr [edi + 4]
// 005836f3  3b30                 cmp esi, dword ptr [eax]
// 005836f5  7512                 jne 0x583709
// 005836f7  8928                 mov dword ptr [eax], ebp
// 005836f9  eb0e                 jmp 0x583709
// 005836fb  896e08               mov dword ptr [esi + 8], ebp
// 005836fe  8b4704               mov eax, dword ptr [edi + 4]
// 00583701  3b7008               cmp esi, dword ptr [eax + 8]
// 00583704  7503                 jne 0x583709
// 00583706  896808               mov dword ptr [eax + 8], ebp
// 00583709  8b5504               mov edx, dword ptr [ebp + 4]
// 0058370c  807a2000             cmp byte ptr [edx + 0x20], 0
// 00583710  8d4504               lea eax, [ebp + 4]
// 00583713  8bf5                 mov esi, ebp
// 00583715  0f85ea000000         jne 0x583805
// 0058371b  eb03                 jmp 0x583720
// 0058371d  8d4900               lea ecx, [ecx]
// 00583720  8b08                 mov ecx, dword ptr [eax]
// 00583722  8b5104               mov edx, dword ptr [ecx + 4]
// 00583725  3b0a                 cmp ecx, dword ptr [edx]
// 00583727  7551                 jne 0x58377a
// 00583729  8b5208               mov edx, dword ptr [edx + 8]
// 0058372c  807a2000             cmp byte ptr [edx + 0x20], 0
// 00583730  7519                 jne 0x58374b
// 00583732  885920               mov byte ptr [ecx + 0x20], bl
// 00583735  885a20               mov byte ptr [edx + 0x20], bl
// 00583738  8b10                 mov edx, dword ptr [eax]
// 0058373a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0058373d  c6412000             mov byte ptr [ecx + 0x20], 0
// 00583741  8b10                 mov edx, dword ptr [eax]
// 00583743  8b7204               mov esi, dword ptr [edx + 4]
// 00583746  e9aa000000           jmp 0x5837f5
// 0058374b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0058374e  750a                 jne 0x58375a
// 00583750  8bf1                 mov esi, ecx
// 00583752  56                   push esi
// 00583753  8bcf                 mov ecx, edi
// 00583755  e8b69ff4ff           call 0x4cd710
// 0058375a  8b4604               mov eax, dword ptr [esi + 4]
// 0058375d  885820               mov byte ptr [eax + 0x20], bl
// 00583760  8b4e04               mov ecx, dword ptr [esi + 4]
// 00583763  8b5104               mov edx, dword ptr [ecx + 4]
// 00583766  c6422000             mov byte ptr [edx + 0x20], 0
// 0058376a  8b4604               mov eax, dword ptr [esi + 4]
// 0058376d  8b4804               mov ecx, dword ptr [eax + 4]
// 00583770  51                   push ecx
// 00583771  8bcf                 mov ecx, edi
// 00583773  e878cbf4ff           call 0x4d02f0
// 00583778  eb7b                 jmp 0x5837f5
// 0058377a  8b12                 mov edx, dword ptr [edx]
// 0058377c  807a2000             cmp byte ptr [edx + 0x20], 0
// 00583780  7516                 jne 0x583798
// 00583782  885920               mov byte ptr [ecx + 0x20], bl
// 00583785  885a20               mov byte ptr [edx + 0x20], bl
// 00583788  8b10                 mov edx, dword ptr [eax]
// 0058378a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0058378d  c6412000             mov byte ptr [ecx + 0x20], 0
// 00583791  8b10                 mov edx, dword ptr [eax]
// 00583793  8b7204               mov esi, dword ptr [edx + 4]
// 00583796  eb5d                 jmp 0x5837f5
// 00583798  3b31                 cmp esi, dword ptr [ecx]
// 0058379a  750a                 jne 0x5837a6
// 0058379c  8bf1                 mov esi, ecx
// 0058379e  56                   push esi
// 0058379f  8bcf                 mov ecx, edi
// 005837a1  e84acbf4ff           call 0x4d02f0
// 005837a6  8b4604               mov eax, dword ptr [esi + 4]
// 005837a9  885820               mov byte ptr [eax + 0x20], bl
// 005837ac  8b4e04               mov ecx, dword ptr [esi + 4]
// 005837af  8b5104               mov edx, dword ptr [ecx + 4]
// 005837b2  c6422000             mov byte ptr [edx + 0x20], 0
// 005837b6  8b4604               mov eax, dword ptr [esi + 4]
// 005837b9  8b4004               mov eax, dword ptr [eax + 4]
// 005837bc  8b4808               mov ecx, dword ptr [eax + 8]
// 005837bf  8b11                 mov edx, dword ptr [ecx]
// 005837c1  895008               mov dword ptr [eax + 8], edx
// 005837c4  8b11                 mov edx, dword ptr [ecx]
// 005837c6  807a2100             cmp byte ptr [edx + 0x21], 0
// 005837ca  7503                 jne 0x5837cf
// 005837cc  894204               mov dword ptr [edx + 4], eax
// 005837cf  8b5004               mov edx, dword ptr [eax + 4]
// 005837d2  895104               mov dword ptr [ecx + 4], edx
// 005837d5  8b5704               mov edx, dword ptr [edi + 4]
// 005837d8  3b4204               cmp eax, dword ptr [edx + 4]
// 005837db  7505                 jne 0x5837e2
// 005837dd  894a04               mov dword ptr [edx + 4], ecx
// 005837e0  eb0e                 jmp 0x5837f0
// 005837e2  8b5004               mov edx, dword ptr [eax + 4]
// 005837e5  3b02                 cmp eax, dword ptr [edx]
// 005837e7  7504                 jne 0x5837ed
// 005837e9  890a                 mov dword ptr [edx], ecx
// 005837eb  eb03                 jmp 0x5837f0
// 005837ed  894a08               mov dword ptr [edx + 8], ecx
// 005837f0  8901                 mov dword ptr [ecx], eax
// 005837f2  894804               mov dword ptr [eax + 4], ecx
// 005837f5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005837f8  80792000             cmp byte ptr [ecx + 0x20], 0
// 005837fc  8d4604               lea eax, [esi + 4]
// 005837ff  0f841bffffff         je 0x583720
// 00583805  8b5704               mov edx, dword ptr [edi + 4]
// 00583808  8b4204               mov eax, dword ptr [edx + 4]
// 0058380b  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0058380f  885820               mov byte ptr [eax + 0x20], bl
// 00583812  8b442464             mov eax, dword ptr [esp + 0x64]
// 00583816  5e                   pop esi
// 00583817  896804               mov dword ptr [eax + 4], ebp
// 0058381a  5d                   pop ebp
// 0058381b  8938                 mov dword ptr [eax], edi
// 0058381d  5b                   pop ebx
// 0058381e  5f                   pop edi
// 0058381f  64890d00000000       mov dword ptr fs:[0], ecx
// 00583826  83c450               add esp, 0x50
// 00583829  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
