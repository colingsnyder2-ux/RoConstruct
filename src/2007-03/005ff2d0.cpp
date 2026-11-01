// from server: 100% by auto
// roc 2007-03 005ff2d0  unit: seg_005f0000  size: 397 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ff2d0
//
// 005ff2d0  83ec0c               sub esp, 0xc
// 005ff2d3  53                   push ebx
// 005ff2d4  55                   push ebp
// 005ff2d5  56                   push esi
// 005ff2d6  57                   push edi
// 005ff2d7  8bf8                 mov edi, eax
// 005ff2d9  8b7730               mov esi, dword ptr [edi + 0x30]
// 005ff2dc  b903000000           mov ecx, 3
// 005ff2e1  004e32               add byte ptr [esi + 0x32], cl
// 005ff2e4  0fb64632             movzx eax, byte ptr [esi + 0x32]
// 005ff2e8  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 005ff2eb  2bc1                 sub eax, ecx
// 005ff2ed  83e901               sub ecx, 1
// 005ff2f0  0fb78446ac000000     movzx eax, word ptr [esi + eax*2 + 0xac]
// 005ff2f8  8d1440               lea edx, [eax + eax*2]
// 005ff2fb  8b06                 mov eax, dword ptr [esi]
// 005ff2fd  8b4018               mov eax, dword ptr [eax + 0x18]
// 005ff300  895c9004             mov dword ptr [eax + edx*4 + 4], ebx
// 005ff304  75de                 jne 0x5ff2e4
// 005ff306  817f1003010000       cmp dword ptr [edi + 0x10], 0x103
// 005ff30d  7424                 je 0x5ff333
// 005ff30f  6803010000           push 0x103
// 005ff314  57                   push edi
// 005ff315  e8561b0000           call 0x600e70
// 005ff31a  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 005ff31d  50                   push eax
// 005ff31e  6828047c00           push 0x7c0428
// 005ff323  51                   push ecx
// 005ff324  e81795ffff           call 0x5f8840
// 005ff329  50                   push eax
// 005ff32a  57                   push edi
// 005ff32b  e8401c0000           call 0x600f70
// 005ff330  83c41c               add esp, 0x1c
// 005ff333  57                   push edi
// 005ff334  e867300000           call 0x6023a0
// 005ff339  33db                 xor ebx, ebx
// 005ff33b  83c404               add esp, 4
// 005ff33e  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 005ff342  7417                 je 0x5ff35b
// 005ff344  8b542420             mov edx, dword ptr [esp + 0x20]
// 005ff348  68feff0100           push 0x1fffe
// 005ff34d  52                   push edx
// 005ff34e  6a20                 push 0x20
// 005ff350  56                   push esi
// 005ff351  e88a580100           call 0x614be0
// 005ff356  83c410               add esp, 0x10
// 005ff359  eb09                 jmp 0x5ff364
// 005ff35b  56                   push esi
// 005ff35c  e8df590100           call 0x614d40
// 005ff361  83c404               add esp, 4
// 005ff364  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 005ff36c  885c241a             mov byte ptr [esp + 0x1a], bl
// 005ff370  8be8                 mov ebp, eax
// 005ff372  8a4632               mov al, byte ptr [esi + 0x32]
// 005ff375  88442418             mov byte ptr [esp + 0x18], al
// 005ff379  885c2419             mov byte ptr [esp + 0x19], bl
// 005ff37d  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005ff380  8d542410             lea edx, [esp + 0x10]
// 005ff384  894c2410             mov dword ptr [esp + 0x10], ecx
// 005ff388  895614               mov dword ptr [esi + 0x14], edx
// 005ff38b  8b542428             mov edx, dword ptr [esp + 0x28]
// 005ff38f  8bc7                 mov eax, edi
// 005ff391  e8dae2ffff           call 0x5fd670
// 005ff396  8b442428             mov eax, dword ptr [esp + 0x28]
// 005ff39a  50                   push eax
// 005ff39b  56                   push esi
// 005ff39c  e83f530100           call 0x6146e0
// 005ff3a1  83c408               add esp, 8
// 005ff3a4  8bc7                 mov eax, edi
// 005ff3a6  e835faffff           call 0x5fede0
// 005ff3ab  8b7e14               mov edi, dword ptr [esi + 0x14]
// 005ff3ae  8b0f                 mov ecx, dword ptr [edi]
// 005ff3b0  8b460c               mov eax, dword ptr [esi + 0xc]
// 005ff3b3  894e14               mov dword ptr [esi + 0x14], ecx
// 005ff3b6  0fb65708             movzx edx, byte ptr [edi + 8]
// 005ff3ba  e8f1e2ffff           call 0x5fd6b0
// 005ff3bf  385f09               cmp byte ptr [edi + 9], bl
// 005ff3c2  7412                 je 0x5ff3d6
// 005ff3c4  0fb65708             movzx edx, byte ptr [edi + 8]
// 005ff3c8  53                   push ebx
// 005ff3c9  53                   push ebx
// 005ff3ca  52                   push edx
// 005ff3cb  6a23                 push 0x23
// 005ff3cd  56                   push esi
// 005ff3ce  e8dd570100           call 0x614bb0
// 005ff3d3  83c414               add esp, 0x14
// 005ff3d6  0fb64632             movzx eax, byte ptr [esi + 0x32]
// 005ff3da  894624               mov dword ptr [esi + 0x24], eax
// 005ff3dd  8b4f04               mov ecx, dword ptr [edi + 4]
// 005ff3e0  51                   push ecx
// 005ff3e1  56                   push esi
// 005ff3e2  e8295a0100           call 0x614e10
// 005ff3e7  55                   push ebp
// 005ff3e8  56                   push esi
// 005ff3e9  e8225a0100           call 0x614e10
// 005ff3ee  83c410               add esp, 0x10
// 005ff3f1  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 005ff3f5  7417                 je 0x5ff40e
// 005ff3f7  8b542420             mov edx, dword ptr [esp + 0x20]
// 005ff3fb  68feff0100           push 0x1fffe
// 005ff400  52                   push edx
// 005ff401  6a1f                 push 0x1f
// 005ff403  56                   push esi
// 005ff404  e8d7570100           call 0x614be0
// 005ff409  83c410               add esp, 0x10
// 005ff40c  eb16                 jmp 0x5ff424
// 005ff40e  8b442428             mov eax, dword ptr [esp + 0x28]
// 005ff412  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005ff416  50                   push eax
// 005ff417  53                   push ebx
// 005ff418  51                   push ecx
// 005ff419  6a21                 push 0x21
// 005ff41b  56                   push esi
// 005ff41c  e88f570100           call 0x614bb0
// 005ff421  83c414               add esp, 0x14
// 005ff424  8b542424             mov edx, dword ptr [esp + 0x24]
// 005ff428  52                   push edx
// 005ff429  56                   push esi
// 005ff42a  8bf8                 mov edi, eax
// 005ff42c  e8bf560100           call 0x614af0
// 005ff431  83c408               add esp, 8
// 005ff434  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 005ff438  7404                 je 0x5ff43e
// 005ff43a  8bc7                 mov eax, edi
// 005ff43c  eb09                 jmp 0x5ff447
// 005ff43e  56                   push esi
// 005ff43f  e8fc580100           call 0x614d40
// 005ff444  83c404               add esp, 4
// 005ff447  83c501               add ebp, 1
// 005ff44a  55                   push ebp
// 005ff44b  50                   push eax
// 005ff44c  56                   push esi
// 005ff44d  e83e680100           call 0x615c90
// 005ff452  83c40c               add esp, 0xc
// 005ff455  5f                   pop edi
// 005ff456  5e                   pop esi
// 005ff457  5d                   pop ebp
// 005ff458  5b                   pop ebx
// 005ff459  83c40c               add esp, 0xc
// 005ff45c  c3                   ret 
// library lua-5.1.1/lparser.c (function _forbody)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
