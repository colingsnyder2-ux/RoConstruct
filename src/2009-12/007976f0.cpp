// from server: 100% by auto
// roc 2009-12 007976f0  unit: lua_exception  size: 214 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007976f0
//
// 007976f0  53                   push ebx
// 007976f1  56                   push esi
// 007976f2  57                   push edi
// 007976f3  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007976f7  8b07                 mov eax, dword ptr [edi]
// 007976f9  50                   push eax
// 007976fa  e8119a0300           call 0x7d1110
// 007976ff  8b742414             mov esi, dword ptr [esp + 0x14]
// 00797703  8bd8                 mov ebx, eax
// 00797705  8b4610               mov eax, dword ptr [esi + 0x10]
// 00797708  8b4844               mov ecx, dword ptr [eax + 0x44]
// 0079770b  83c404               add esp, 4
// 0079770e  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00797711  7209                 jb 0x79771c
// 00797713  56                   push esi
// 00797714  e8f7640300           call 0x7cdc10
// 00797719  83c404               add esp, 4
// 0079771c  b810517d00           mov eax, 0x7d5110
// 00797721  83fb1b               cmp ebx, 0x1b
// 00797724  7405                 je 0x79772b
// 00797726  b850467d00           mov eax, 0x7d4650
// 0079772b  8b5710               mov edx, dword ptr [edi + 0x10]
// 0079772e  52                   push edx
// 0079772f  8b17                 mov edx, dword ptr [edi]
// 00797731  8d4f04               lea ecx, [edi + 4]
// 00797734  51                   push ecx
// 00797735  52                   push edx
// 00797736  56                   push esi
// 00797737  ffd0                 call eax
// 00797739  8bf8                 mov edi, eax
// 0079773b  8b4648               mov eax, dword ptr [esi + 0x48]
// 0079773e  0fb64f48             movzx ecx, byte ptr [edi + 0x48]
// 00797742  50                   push eax
// 00797743  51                   push ecx
// 00797744  56                   push esi
// 00797745  e8d6950300           call 0x7d0d20
// 0079774a  33db                 xor ebx, ebx
// 0079774c  83c41c               add esp, 0x1c
// 0079774f  897810               mov dword ptr [eax + 0x10], edi
// 00797752  89442414             mov dword ptr [esp + 0x14], eax
// 00797756  385f48               cmp byte ptr [edi + 0x48], bl
// 00797759  7622                 jbe 0x79777d
// 0079775b  55                   push ebp
// 0079775c  8d6814               lea ebp, [eax + 0x14]
// 0079775f  90                   nop 
// 00797760  56                   push esi
// 00797761  e81a960300           call 0x7d0d80
// 00797766  894500               mov dword ptr [ebp], eax
// 00797769  0fb65748             movzx edx, byte ptr [edi + 0x48]
// 0079776d  43                   inc ebx
// 0079776e  83c404               add esp, 4
// 00797771  83c504               add ebp, 4
// 00797774  3bda                 cmp ebx, edx
// 00797776  7ce8                 jl 0x797760
// 00797778  8b442418             mov eax, dword ptr [esp + 0x18]
// 0079777c  5d                   pop ebp
// 0079777d  8b4e08               mov ecx, dword ptr [esi + 8]
// 00797780  8901                 mov dword ptr [ecx], eax
// 00797782  c7410806000000       mov dword ptr [ecx + 8], 6
// 00797789  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0079778c  2b4608               sub eax, dword ptr [esi + 8]
// 0079778f  bf10000000           mov edi, 0x10
// 00797794  3bc7                 cmp eax, edi
// 00797796  7f27                 jg 0x7977bf
// 00797798  8b462c               mov eax, dword ptr [esi + 0x2c]
// 0079779b  83f801               cmp eax, 1
// 0079779e  7c14                 jl 0x7977b4
// 007977a0  8d0c00               lea ecx, [eax + eax]
// 007977a3  51                   push ecx
// 007977a4  56                   push esi
// 007977a5  e8a6faffff           call 0x797250
// 007977aa  83c408               add esp, 8
// 007977ad  017e08               add dword ptr [esi + 8], edi
// 007977b0  5f                   pop edi
// 007977b1  5e                   pop esi
// 007977b2  5b                   pop ebx
// 007977b3  c3                   ret 
// 007977b4  40                   inc eax
// 007977b5  50                   push eax
// 007977b6  56                   push esi
// 007977b7  e894faffff           call 0x797250
// 007977bc  83c408               add esp, 8
// 007977bf  017e08               add dword ptr [esi + 8], edi
// 007977c2  5f                   pop edi
// 007977c3  5e                   pop esi
// 007977c4  5b                   pop ebx
// 007977c5  c3                   ret 
// library lua-5.1/ldo.c (function _f_parser)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldo.c
