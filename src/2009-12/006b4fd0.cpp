// from server: 100% by auto
// roc 2009-12 006b4fd0  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b4fd0
//
// 006b4fd0  64a100000000         mov eax, dword ptr fs:[0]
// 006b4fd6  6aff                 push -1
// 006b4fd8  6812699500           push 0x956912
// 006b4fdd  50                   push eax
// 006b4fde  64892500000000       mov dword ptr fs:[0], esp
// 006b4fe5  83ec44               sub esp, 0x44
// 006b4fe8  57                   push edi
// 006b4fe9  8bf9                 mov edi, ecx
// 006b4feb  817f1c65666606       cmp dword ptr [edi + 0x1c], 0x6666665
// 006b4ff2  7259                 jb 0x6b504d
// 006b4ff4  6800f59900           push 0x99f500
// 006b4ff9  8d4c2408             lea ecx, [esp + 8]
// 006b4ffd  ff15f4b69800         call dword ptr [0x98b6f4]
// 006b5003  8d4c2420             lea ecx, [esp + 0x20]
// 006b5007  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006b500f  ff1554b79800         call dword ptr [0x98b754]
// 006b5015  8d442404             lea eax, [esp + 4]
// 006b5019  50                   push eax
// 006b501a  8d4c2430             lea ecx, [esp + 0x30]
// 006b501e  c644245401           mov byte ptr [esp + 0x54], 1
// 006b5023  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 006b502b  ff15f0b69800         call dword ptr [0x98b6f0]
// 006b5031  68e4efa800           push 0xa8efe4
// 006b5036  8d4c2424             lea ecx, [esp + 0x24]
// 006b503a  51                   push ecx
// 006b503b  c644245800           mov byte ptr [esp + 0x58], 0
// 006b5040  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 006b5048  e82bf81300           call 0x7f4878
// 006b504d  8b542464             mov edx, dword ptr [esp + 0x64]
// 006b5051  8b4718               mov eax, dword ptr [edi + 0x18]
// 006b5054  53                   push ebx
// 006b5055  55                   push ebp
// 006b5056  56                   push esi
// 006b5057  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006b505b  6a00                 push 0
// 006b505d  52                   push edx
// 006b505e  50                   push eax
// 006b505f  56                   push esi
// 006b5060  50                   push eax
// 006b5061  e83afbffff           call 0x6b4ba0
// 006b5066  8be8                 mov ebp, eax
// 006b5068  8b4718               mov eax, dword ptr [edi + 0x18]
// 006b506b  bb01000000           mov ebx, 1
// 006b5070  015f1c               add dword ptr [edi + 0x1c], ebx
// 006b5073  3bf0                 cmp esi, eax
// 006b5075  7510                 jne 0x6b5087
// 006b5077  896804               mov dword ptr [eax + 4], ebp
// 006b507a  8b4718               mov eax, dword ptr [edi + 0x18]
// 006b507d  8928                 mov dword ptr [eax], ebp
// 006b507f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006b5082  896908               mov dword ptr [ecx + 8], ebp
// 006b5085  eb22                 jmp 0x6b50a9
// 006b5087  807c246800           cmp byte ptr [esp + 0x68], 0
// 006b508c  740d                 je 0x6b509b
// 006b508e  892e                 mov dword ptr [esi], ebp
// 006b5090  8b4718               mov eax, dword ptr [edi + 0x18]
// 006b5093  3b30                 cmp esi, dword ptr [eax]
// 006b5095  7512                 jne 0x6b50a9
// 006b5097  8928                 mov dword ptr [eax], ebp
// 006b5099  eb0e                 jmp 0x6b50a9
// 006b509b  896e08               mov dword ptr [esi + 8], ebp
// 006b509e  8b4718               mov eax, dword ptr [edi + 0x18]
// 006b50a1  3b7008               cmp esi, dword ptr [eax + 8]
// 006b50a4  7503                 jne 0x6b50a9
// 006b50a6  896808               mov dword ptr [eax + 8], ebp
// 006b50a9  8b5504               mov edx, dword ptr [ebp + 4]
// 006b50ac  807a3400             cmp byte ptr [edx + 0x34], 0
// 006b50b0  8d4504               lea eax, [ebp + 4]
// 006b50b3  8bf5                 mov esi, ebp
// 006b50b5  0f85ea000000         jne 0x6b51a5
// 006b50bb  eb03                 jmp 0x6b50c0
// 006b50bd  8d4900               lea ecx, [ecx]
// 006b50c0  8b08                 mov ecx, dword ptr [eax]
// 006b50c2  8b5104               mov edx, dword ptr [ecx + 4]
// 006b50c5  3b0a                 cmp ecx, dword ptr [edx]
// 006b50c7  7551                 jne 0x6b511a
// 006b50c9  8b5208               mov edx, dword ptr [edx + 8]
// 006b50cc  807a3400             cmp byte ptr [edx + 0x34], 0
// 006b50d0  7519                 jne 0x6b50eb
// 006b50d2  885934               mov byte ptr [ecx + 0x34], bl
// 006b50d5  885a34               mov byte ptr [edx + 0x34], bl
// 006b50d8  8b10                 mov edx, dword ptr [eax]
// 006b50da  8b4a04               mov ecx, dword ptr [edx + 4]
// 006b50dd  c6413400             mov byte ptr [ecx + 0x34], 0
// 006b50e1  8b10                 mov edx, dword ptr [eax]
// 006b50e3  8b7204               mov esi, dword ptr [edx + 4]
// 006b50e6  e9aa000000           jmp 0x6b5195
// 006b50eb  3b7108               cmp esi, dword ptr [ecx + 8]
// 006b50ee  750a                 jne 0x6b50fa
// 006b50f0  8bf1                 mov esi, ecx
// 006b50f2  56                   push esi
// 006b50f3  8bcf                 mov ecx, edi
// 006b50f5  e826830000           call 0x6bd420
// 006b50fa  8b4604               mov eax, dword ptr [esi + 4]
// 006b50fd  885834               mov byte ptr [eax + 0x34], bl
// 006b5100  8b4e04               mov ecx, dword ptr [esi + 4]
// 006b5103  8b5104               mov edx, dword ptr [ecx + 4]
// 006b5106  c6423400             mov byte ptr [edx + 0x34], 0
// 006b510a  8b4604               mov eax, dword ptr [esi + 4]
// 006b510d  8b4804               mov ecx, dword ptr [eax + 4]
// 006b5110  51                   push ecx
// 006b5111  8bcf                 mov ecx, edi
// 006b5113  e808e9ffff           call 0x6b3a20
// 006b5118  eb7b                 jmp 0x6b5195
// 006b511a  8b12                 mov edx, dword ptr [edx]
// 006b511c  807a3400             cmp byte ptr [edx + 0x34], 0
// 006b5120  7516                 jne 0x6b5138
// 006b5122  885934               mov byte ptr [ecx + 0x34], bl
// 006b5125  885a34               mov byte ptr [edx + 0x34], bl
// 006b5128  8b10                 mov edx, dword ptr [eax]
// 006b512a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006b512d  c6413400             mov byte ptr [ecx + 0x34], 0
// 006b5131  8b10                 mov edx, dword ptr [eax]
// 006b5133  8b7204               mov esi, dword ptr [edx + 4]
// 006b5136  eb5d                 jmp 0x6b5195
// 006b5138  3b31                 cmp esi, dword ptr [ecx]
// 006b513a  750a                 jne 0x6b5146
// 006b513c  8bf1                 mov esi, ecx
// 006b513e  56                   push esi
// 006b513f  8bcf                 mov ecx, edi
// 006b5141  e8dae8ffff           call 0x6b3a20
// 006b5146  8b4604               mov eax, dword ptr [esi + 4]
// 006b5149  885834               mov byte ptr [eax + 0x34], bl
// 006b514c  8b4e04               mov ecx, dword ptr [esi + 4]
// 006b514f  8b5104               mov edx, dword ptr [ecx + 4]
// 006b5152  c6423400             mov byte ptr [edx + 0x34], 0
// 006b5156  8b4604               mov eax, dword ptr [esi + 4]
// 006b5159  8b4004               mov eax, dword ptr [eax + 4]
// 006b515c  8b4808               mov ecx, dword ptr [eax + 8]
// 006b515f  8b11                 mov edx, dword ptr [ecx]
// 006b5161  895008               mov dword ptr [eax + 8], edx
// 006b5164  8b11                 mov edx, dword ptr [ecx]
// 006b5166  807a3500             cmp byte ptr [edx + 0x35], 0
// 006b516a  7503                 jne 0x6b516f
// 006b516c  894204               mov dword ptr [edx + 4], eax
// 006b516f  8b5004               mov edx, dword ptr [eax + 4]
// 006b5172  895104               mov dword ptr [ecx + 4], edx
// 006b5175  8b5718               mov edx, dword ptr [edi + 0x18]
// 006b5178  3b4204               cmp eax, dword ptr [edx + 4]
// 006b517b  7505                 jne 0x6b5182
// 006b517d  894a04               mov dword ptr [edx + 4], ecx
// 006b5180  eb0e                 jmp 0x6b5190
// 006b5182  8b5004               mov edx, dword ptr [eax + 4]
// 006b5185  3b02                 cmp eax, dword ptr [edx]
// 006b5187  7504                 jne 0x6b518d
// 006b5189  890a                 mov dword ptr [edx], ecx
// 006b518b  eb03                 jmp 0x6b5190
// 006b518d  894a08               mov dword ptr [edx + 8], ecx
// 006b5190  8901                 mov dword ptr [ecx], eax
// 006b5192  894804               mov dword ptr [eax + 4], ecx
// 006b5195  8b4e04               mov ecx, dword ptr [esi + 4]
// 006b5198  80793400             cmp byte ptr [ecx + 0x34], 0
// 006b519c  8d4604               lea eax, [esi + 4]
// 006b519f  0f841bffffff         je 0x6b50c0
// 006b51a5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006b51a8  8b4204               mov eax, dword ptr [edx + 4]
// 006b51ab  885834               mov byte ptr [eax + 0x34], bl
// 006b51ae  8b442464             mov eax, dword ptr [esp + 0x64]
// 006b51b2  8b0f                 mov ecx, dword ptr [edi]
// 006b51b4  5e                   pop esi
// 006b51b5  896804               mov dword ptr [eax + 4], ebp
// 006b51b8  5d                   pop ebp
// 006b51b9  8908                 mov dword ptr [eax], ecx
// 006b51bb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006b51bf  5b                   pop ebx
// 006b51c0  5f                   pop edi
// 006b51c1  64890d00000000       mov dword ptr fs:[0], ecx
// 006b51c8  83c450               add esp, 0x50
// 006b51cb  c21000               ret 0x10
// standard library map_int<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
