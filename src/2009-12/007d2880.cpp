// from server: 100% by auto
// roc 2009-12 007d2880  unit: seg_007d0000  size: 314 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d2880
//
// 007d2880  83ec1c               sub esp, 0x1c
// 007d2883  53                   push ebx
// 007d2884  55                   push ebp
// 007d2885  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 007d2889  56                   push esi
// 007d288a  8bf0                 mov esi, eax
// 007d288c  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d288f  8b5e30               mov ebx, dword ptr [esi + 0x30]
// 007d2892  57                   push edi
// 007d2893  8b7e04               mov edi, dword ptr [esi + 4]
// 007d2896  897c2410             mov dword ptr [esp + 0x10], edi
// 007d289a  83f828               cmp eax, 0x28
// 007d289d  745b                 je 0x7d28fa
// 007d289f  83f87b               cmp eax, 0x7b
// 007d28a2  7449                 je 0x7d28ed
// 007d28a4  3d1e010000           cmp eax, 0x11e
// 007d28a9  7416                 je 0x7d28c1
// 007d28ab  683cef9e00           push 0x9eef3c
// 007d28b0  56                   push esi
// 007d28b1  e88a2a0000           call 0x7d5340
// 007d28b6  83c408               add esp, 8
// 007d28b9  5f                   pop edi
// 007d28ba  5e                   pop esi
// 007d28bb  5d                   pop ebp
// 007d28bc  5b                   pop ebx
// 007d28bd  83c41c               add esp, 0x1c
// 007d28c0  c3                   ret 
// 007d28c1  8b4618               mov eax, dword ptr [esi + 0x18]
// 007d28c4  50                   push eax
// 007d28c5  53                   push ebx
// 007d28c6  e8d5990000           call 0x7dc2a0
// 007d28cb  83c9ff               or ecx, 0xffffffff
// 007d28ce  56                   push esi
// 007d28cf  894c2430             mov dword ptr [esp + 0x30], ecx
// 007d28d3  894c2434             mov dword ptr [esp + 0x34], ecx
// 007d28d7  c744242004000000     mov dword ptr [esp + 0x20], 4
// 007d28df  89442428             mov dword ptr [esp + 0x28], eax
// 007d28e3  e8483e0000           call 0x7d6730
// 007d28e8  83c40c               add esp, 0xc
// 007d28eb  eb69                 jmp 0x7d2956
// 007d28ed  8d442414             lea eax, [esp + 0x14]
// 007d28f1  8bce                 mov ecx, esi
// 007d28f3  e848faffff           call 0x7d2340
// 007d28f8  eb5c                 jmp 0x7d2956
// 007d28fa  3b7e08               cmp edi, dword ptr [esi + 8]
// 007d28fd  740e                 je 0x7d290d
// 007d28ff  6808ef9e00           push 0x9eef08
// 007d2904  56                   push esi
// 007d2905  e8362a0000           call 0x7d5340
// 007d290a  83c408               add esp, 8
// 007d290d  56                   push esi
// 007d290e  e81d3e0000           call 0x7d6730
// 007d2913  83c404               add esp, 4
// 007d2916  837e1029             cmp dword ptr [esi + 0x10], 0x29
// 007d291a  750a                 jne 0x7d2926
// 007d291c  c744241400000000     mov dword ptr [esp + 0x14], 0
// 007d2924  eb1b                 jmp 0x7d2941
// 007d2926  8d7c2414             lea edi, [esp + 0x14]
// 007d292a  e811ffffff           call 0x7d2840
// 007d292f  6aff                 push -1
// 007d2931  8bc7                 mov eax, edi
// 007d2933  50                   push eax
// 007d2934  53                   push ebx
// 007d2935  e8c6990000           call 0x7dc300
// 007d293a  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 007d293e  83c40c               add esp, 0xc
// 007d2941  8bc7                 mov eax, edi
// 007d2943  6a28                 push 0x28
// 007d2945  bf29000000           mov edi, 0x29
// 007d294a  e891efffff           call 0x7d18e0
// 007d294f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007d2953  83c404               add esp, 4
// 007d2956  8b442414             mov eax, dword ptr [esp + 0x14]
// 007d295a  8b7508               mov esi, dword ptr [ebp + 8]
// 007d295d  83f80d               cmp eax, 0xd
// 007d2960  741f                 je 0x7d2981
// 007d2962  83f80e               cmp eax, 0xe
// 007d2965  741a                 je 0x7d2981
// 007d2967  85c0                 test eax, eax
// 007d2969  740e                 je 0x7d2979
// 007d296b  8d4c2414             lea ecx, [esp + 0x14]
// 007d296f  51                   push ecx
// 007d2970  53                   push ebx
// 007d2971  e89aa20000           call 0x7dcc10
// 007d2976  83c408               add esp, 8
// 007d2979  8b4324               mov eax, dword ptr [ebx + 0x24]
// 007d297c  2bc6                 sub eax, esi
// 007d297e  48                   dec eax
// 007d297f  eb03                 jmp 0x7d2984
// 007d2981  83c8ff               or eax, 0xffffffff
// 007d2984  6a02                 push 2
// 007d2986  40                   inc eax
// 007d2987  50                   push eax
// 007d2988  56                   push esi
// 007d2989  6a1c                 push 0x1c
// 007d298b  53                   push ebx
// 007d298c  e86f9c0000           call 0x7dc600
// 007d2991  83c9ff               or ecx, 0xffffffff
// 007d2994  57                   push edi
// 007d2995  53                   push ebx
// 007d2996  894d10               mov dword ptr [ebp + 0x10], ecx
// 007d2999  894d14               mov dword ptr [ebp + 0x14], ecx
// 007d299c  c745000d000000       mov dword ptr [ebp], 0xd
// 007d29a3  894508               mov dword ptr [ebp + 8], eax
// 007d29a6  e8959b0000           call 0x7dc540
// 007d29ab  83c41c               add esp, 0x1c
// 007d29ae  46                   inc esi
// 007d29af  5f                   pop edi
// 007d29b0  897324               mov dword ptr [ebx + 0x24], esi
// 007d29b3  5e                   pop esi
// 007d29b4  5d                   pop ebp
// 007d29b5  5b                   pop ebx
// 007d29b6  83c41c               add esp, 0x1c
// 007d29b9  c3                   ret 
// library lua-5.1/lparser.c (function _funcargs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
