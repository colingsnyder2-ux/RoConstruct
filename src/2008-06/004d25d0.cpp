// from server: 100% by auto
// roc 2008-06 004d25d0  unit: seg_004d0000  size: 419 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d25d0
//
// 004d25d0  6aff                 push -1
// 004d25d2  68ee9b7c00           push 0x7c9bee
// 004d25d7  64a100000000         mov eax, dword ptr fs:[0]
// 004d25dd  50                   push eax
// 004d25de  64892500000000       mov dword ptr fs:[0], esp
// 004d25e5  51                   push ecx
// 004d25e6  53                   push ebx
// 004d25e7  33db                 xor ebx, ebx
// 004d25e9  56                   push esi
// 004d25ea  8bf1                 mov esi, ecx
// 004d25ec  89742408             mov dword ptr [esp + 8], esi
// 004d25f0  895e08               mov dword ptr [esi + 8], ebx
// 004d25f3  891e                 mov dword ptr [esi], ebx
// 004d25f5  895e04               mov dword ptr [esi + 4], ebx
// 004d25f8  33c9                 xor ecx, ecx
// 004d25fa  b810000000           mov eax, 0x10
// 004d25ff  ba04000000           mov edx, 4
// 004d2604  f7e2                 mul edx
// 004d2606  0f90c1               seto cl
// 004d2609  895c2414             mov dword ptr [esp + 0x14], ebx
// 004d260d  c7461810000000       mov dword ptr [esi + 0x18], 0x10
// 004d2614  f7d9                 neg ecx
// 004d2616  0bc8                 or ecx, eax
// 004d2618  51                   push ecx
// 004d2619  e802e31c00           call 0x6a0920
// 004d261e  89460c               mov dword ptr [esi + 0xc], eax
// 004d2621  895e10               mov dword ptr [esi + 0x10], ebx
// 004d2624  895e14               mov dword ptr [esi + 0x14], ebx
// 004d2627  895e24               mov dword ptr [esi + 0x24], ebx
// 004d262a  895e1c               mov dword ptr [esi + 0x1c], ebx
// 004d262d  895e20               mov dword ptr [esi + 0x20], ebx
// 004d2630  895e40               mov dword ptr [esi + 0x40], ebx
// 004d2633  895e44               mov dword ptr [esi + 0x44], ebx
// 004d2636  c7464800400000       mov dword ptr [esi + 0x48], 0x4000
// 004d263d  895e4c               mov dword ptr [esi + 0x4c], ebx
// 004d2640  895e50               mov dword ptr [esi + 0x50], ebx
// 004d2643  33c9                 xor ecx, ecx
// 004d2645  b810000000           mov eax, 0x10
// 004d264a  ba04000000           mov edx, 4
// 004d264f  f7e2                 mul edx
// 004d2651  0f90c1               seto cl
// 004d2654  c644241803           mov byte ptr [esp + 0x18], 3
// 004d2659  c7466010000000       mov dword ptr [esi + 0x60], 0x10
// 004d2660  f7d9                 neg ecx
// 004d2662  0bc8                 or ecx, eax
// 004d2664  51                   push ecx
// 004d2665  e8b6e21c00           call 0x6a0920
// 004d266a  83c408               add esp, 8
// 004d266d  894654               mov dword ptr [esi + 0x54], eax
// 004d2670  895e58               mov dword ptr [esi + 0x58], ebx
// 004d2673  895e5c               mov dword ptr [esi + 0x5c], ebx
// 004d2676  68f0dd4c00           push 0x4cddf0
// 004d267b  68a0ed4c00           push 0x4ceda0
// 004d2680  6a04                 push 4
// 004d2682  6a10                 push 0x10
// 004d2684  8d4664               lea eax, [esi + 0x64]
// 004d2687  50                   push eax
// 004d2688  c644242804           mov byte ptr [esp + 0x28], 4
// 004d268d  e806ef1c00           call 0x6a1598
// 004d2692  899eac000000         mov dword ptr [esi + 0xac], ebx
// 004d2698  899ea4000000         mov dword ptr [esi + 0xa4], ebx
// 004d269e  899ea8000000         mov dword ptr [esi + 0xa8], ebx
// 004d26a4  68e9050000           push 0x5e9
// 004d26a9  8d8ec0000000         lea ecx, [esi + 0xc0]
// 004d26af  c644241806           mov byte ptr [esp + 0x18], 6
// 004d26b4  e8072afdff           call 0x4a50c0
// 004d26b9  33c9                 xor ecx, ecx
// 004d26bb  b810000000           mov eax, 0x10
// 004d26c0  ba08000000           mov edx, 8
// 004d26c5  f7e2                 mul edx
// 004d26c7  0f90c1               seto cl
// 004d26ca  c644241407           mov byte ptr [esp + 0x14], 7
// 004d26cf  c786c004000010000000 mov dword ptr [esi + 0x4c0], 0x10
// 004d26d9  f7d9                 neg ecx
// 004d26db  0bc8                 or ecx, eax
// 004d26dd  51                   push ecx
// 004d26de  e83de21c00           call 0x6a0920
// 004d26e3  83c404               add esp, 4
// 004d26e6  8986b4040000         mov dword ptr [esi + 0x4b4], eax
// 004d26ec  899eb8040000         mov dword ptr [esi + 0x4b8], ebx
// 004d26f2  899ebc040000         mov dword ptr [esi + 0x4bc], ebx
// 004d26f8  8d8e28050000         lea ecx, [esi + 0x528]
// 004d26fe  c644241408           mov byte ptr [esp + 0x14], 8
// 004d2703  e878320000           call 0x4d5980
// 004d2708  899e98070000         mov dword ptr [esi + 0x798], ebx
// 004d270e  899e90070000         mov dword ptr [esi + 0x790], ebx
// 004d2714  899e94070000         mov dword ptr [esi + 0x794], ebx
// 004d271a  899eb8070000         mov dword ptr [esi + 0x7b8], ebx
// 004d2720  899ebc070000         mov dword ptr [esi + 0x7bc], ebx
// 004d2726  c786c007000000400000 mov dword ptr [esi + 0x7c0], 0x4000
// 004d2730  d9ee                 fldz 
// 004d2732  8bce                 mov ecx, esi
// 004d2734  dd9ea0070000         fstp qword ptr [esi + 0x7a0]
// 004d273a  c64424140b           mov byte ptr [esp + 0x14], 0xb
// 004d273f  889e8c070000         mov byte ptr [esi + 0x78c], bl
// 004d2745  c786d803000010270000 mov dword ptr [esi + 0x3d8], 0x2710
// 004d274f  899eac070000         mov dword ptr [esi + 0x7ac], ebx
// 004d2755  899ea8070000         mov dword ptr [esi + 0x7a8], ebx
// 004d275b  e8b0c2ffff           call 0x4cea10
// 004d2760  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004d2764  8bc6                 mov eax, esi
// 004d2766  5e                   pop esi
// 004d2767  5b                   pop ebx
// 004d2768  64890d00000000       mov dword ptr fs:[0], ecx
// 004d276f  83c410               add esp, 0x10
// 004d2772  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ??0ReliabilityLayer@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
