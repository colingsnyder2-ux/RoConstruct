// from server: 100% by auto
// roc 2010-06 0096f900  unit: seg_00960000  size: 401 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096f900
//
// 0096f900  55                   push ebp
// 0096f901  8bec                 mov ebp, esp
// 0096f903  6aff                 push -1
// 0096f905  68c0279c00           push 0x9c27c0
// 0096f90a  64a100000000         mov eax, dword ptr fs:[0]
// 0096f910  50                   push eax
// 0096f911  64892500000000       mov dword ptr fs:[0], esp
// 0096f918  83ec14               sub esp, 0x14
// 0096f91b  53                   push ebx
// 0096f91c  56                   push esi
// 0096f91d  8bf1                 mov esi, ecx
// 0096f91f  8b460c               mov eax, dword ptr [esi + 0xc]
// 0096f922  57                   push edi
// 0096f923  8965f0               mov dword ptr [ebp - 0x10], esp
// 0096f926  85c0                 test eax, eax
// 0096f928  7504                 jne 0x96f92e
// 0096f92a  33c9                 xor ecx, ecx
// 0096f92c  eb17                 jmp 0x96f945
// 0096f92e  8b5614               mov edx, dword ptr [esi + 0x14]
// 0096f931  2bd0                 sub edx, eax
// 0096f933  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096f938  f7ea                 imul edx
// 0096f93a  d1fa                 sar edx, 1
// 0096f93c  8bc2                 mov eax, edx
// 0096f93e  c1e81f               shr eax, 0x1f
// 0096f941  03c2                 add eax, edx
// 0096f943  8bc8                 mov ecx, eax
// 0096f945  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 0096f948  85ff                 test edi, edi
// 0096f94a  0f8449020000         je 0x96fb99
// 0096f950  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0096f953  8bd3                 mov edx, ebx
// 0096f955  2b560c               sub edx, dword ptr [esi + 0xc]
// 0096f958  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096f95d  f7ea                 imul edx
// 0096f95f  d1fa                 sar edx, 1
// 0096f961  8bc2                 mov eax, edx
// 0096f963  c1e81f               shr eax, 0x1f
// 0096f966  03c2                 add eax, edx
// 0096f968  ba55555515           mov edx, 0x15555555
// 0096f96d  2bd0                 sub edx, eax
// 0096f96f  3bd7                 cmp edx, edi
// 0096f971  7305                 jae 0x96f978
// 0096f973  e87844abff           call 0x423df0
// 0096f978  8d1438               lea edx, [eax + edi]
// 0096f97b  3bca                 cmp ecx, edx
// 0096f97d  0f8323010000         jae 0x96faa6
// 0096f983  8bc1                 mov eax, ecx
// 0096f985  d1e8                 shr eax, 1
// 0096f987  bb55555515           mov ebx, 0x15555555
// 0096f98c  2bd8                 sub ebx, eax
// 0096f98e  3bd9                 cmp ebx, ecx
// 0096f990  730c                 jae 0x96f99e
// 0096f992  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 0096f999  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0096f99c  eb05                 jmp 0x96f9a3
// 0096f99e  03c8                 add ecx, eax
// 0096f9a0  894dec               mov dword ptr [ebp - 0x14], ecx
// 0096f9a3  3bca                 cmp ecx, edx
// 0096f9a5  7305                 jae 0x96f9ac
// 0096f9a7  8955ec               mov dword ptr [ebp - 0x14], edx
// 0096f9aa  8bca                 mov ecx, edx
// 0096f9ac  6a00                 push 0
// 0096f9ae  51                   push ecx
// 0096f9af  e8dcf0f7ff           call 0x8eea90
// 0096f9b4  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0096f9b7  2b560c               sub edx, dword ptr [esi + 0xc]
// 0096f9ba  8bc8                 mov ecx, eax
// 0096f9bc  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096f9c1  f7ea                 imul edx
// 0096f9c3  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0096f9c6  d1fa                 sar edx, 1
// 0096f9c8  8bda                 mov ebx, edx
// 0096f9ca  83c408               add esp, 8
// 0096f9cd  c1eb1f               shr ebx, 0x1f
// 0096f9d0  03da                 add ebx, edx
// 0096f9d2  50                   push eax
// 0096f9d3  8d145b               lea edx, [ebx + ebx*2]
// 0096f9d6  8d0491               lea eax, [ecx + edx*4]
// 0096f9d9  57                   push edi
// 0096f9da  894d10               mov dword ptr [ebp + 0x10], ecx
// 0096f9dd  50                   push eax
// 0096f9de  8bce                 mov ecx, esi
// 0096f9e0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0096f9e7  e8b4fcffff           call 0x96f6a0
// 0096f9ec  8b460c               mov eax, dword ptr [esi + 0xc]
// 0096f9ef  c6451400             mov byte ptr [ebp + 0x14], 0
// 0096f9f3  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0096f9f6  52                   push edx
// 0096f9f7  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0096f9fa  52                   push edx
// 0096f9fb  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0096f9fe  8d4e08               lea ecx, [esi + 8]
// 0096fa01  51                   push ecx
// 0096fa02  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 0096fa05  51                   push ecx
// 0096fa06  52                   push edx
// 0096fa07  50                   push eax
// 0096fa08  e843fcf6ff           call 0x8df650
// 0096fa0d  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0096fa10  8b4610               mov eax, dword ptr [esi + 0x10]
// 0096fa13  83c418               add esp, 0x18
// 0096fa16  03df                 add ebx, edi
// 0096fa18  8d0c5b               lea ecx, [ebx + ebx*2]
// 0096fa1b  8d0c8a               lea ecx, [edx + ecx*4]
// 0096fa1e  c6451400             mov byte ptr [ebp + 0x14], 0
// 0096fa22  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0096fa25  52                   push edx
// 0096fa26  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0096fa29  52                   push edx
// 0096fa2a  8d5608               lea edx, [esi + 8]
// 0096fa2d  52                   push edx
// 0096fa2e  51                   push ecx
// 0096fa2f  50                   push eax
// 0096fa30  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0096fa33  50                   push eax
// 0096fa34  e817fcf6ff           call 0x8df650
// 0096fa39  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0096fa3c  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0096fa3f  2bcb                 sub ecx, ebx
// 0096fa41  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096fa46  f7e9                 imul ecx
// 0096fa48  d1fa                 sar edx, 1
// 0096fa4a  8bca                 mov ecx, edx
// 0096fa4c  c1e91f               shr ecx, 0x1f
// 0096fa4f  03ca                 add ecx, edx
// 0096fa51  83c418               add esp, 0x18
// 0096fa54  03f9                 add edi, ecx
// 0096fa56  85db                 test ebx, ebx
// 0096fa58  7409                 je 0x96fa63
// 0096fa5a  53                   push ebx
// 0096fa5b  e83a7fe3ff           call 0x7a799a
// 0096fa60  83c404               add esp, 4
// 0096fa63  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0096fa66  8d1440               lea edx, [eax + eax*2]
// 0096fa69  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0096fa6c  8d0c90               lea ecx, [eax + edx*4]
// 0096fa6f  8d147f               lea edx, [edi + edi*2]
// 0096fa72  894e14               mov dword ptr [esi + 0x14], ecx
// 0096fa75  8d0c90               lea ecx, [eax + edx*4]
// 0096fa78  894e10               mov dword ptr [esi + 0x10], ecx
// 0096fa7b  89460c               mov dword ptr [esi + 0xc], eax
// 0096fa7e  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0096fa81  64890d00000000       mov dword ptr fs:[0], ecx
// 0096fa88  5f                   pop edi
// 0096fa89  5e                   pop esi
// 0096fa8a  5b                   pop ebx
// 0096fa8b  8be5                 mov esp, ebp
// 0096fa8d  5d                   pop ebp
// 0096fa8e  c21000               ret 0x10
// standard library vector<pod12> (function ?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
