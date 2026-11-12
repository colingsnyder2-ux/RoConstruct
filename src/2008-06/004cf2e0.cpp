// from server: 100% by auto
// roc 2008-06 004cf2e0  unit: RBX::Network::PhysicsSender  size: 156 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004cf2e0
//
// 004cf2e0  53                   push ebx
// 004cf2e1  55                   push ebp
// 004cf2e2  56                   push esi
// 004cf2e3  8b35c0288000         mov esi, dword ptr [0x8028c0]
// 004cf2e9  8bd9                 mov ebx, ecx
// 004cf2eb  33ed                 xor ebp, ebp
// 004cf2ed  396b08               cmp dword ptr [ebx + 8], ebp
// 004cf2f0  57                   push edi
// 004cf2f1  7e3d                 jle 0x4cf330
// 004cf2f3  8b3b                 mov edi, dword ptr [ebx]
// 004cf2f5  8b07                 mov eax, dword ptr [edi]
// 004cf2f7  50                   push eax
// 004cf2f8  ffd6                 call esi
// 004cf2fa  8b4f08               mov ecx, dword ptr [edi + 8]
// 004cf2fd  51                   push ecx
// 004cf2fe  ffd6                 call esi
// 004cf300  8bc7                 mov eax, edi
// 004cf302  8b7f0c               mov edi, dword ptr [edi + 0xc]
// 004cf305  83c408               add esp, 8
// 004cf308  3b3b                 cmp edi, dword ptr [ebx]
// 004cf30a  741e                 je 0x4cf32a
// 004cf30c  8d642400             lea esp, [esp]
// 004cf310  50                   push eax
// 004cf311  ffd6                 call esi
// 004cf313  8b17                 mov edx, dword ptr [edi]
// 004cf315  52                   push edx
// 004cf316  ffd6                 call esi
// 004cf318  8b4708               mov eax, dword ptr [edi + 8]
// 004cf31b  50                   push eax
// 004cf31c  ffd6                 call esi
// 004cf31e  8bc7                 mov eax, edi
// 004cf320  8b7f0c               mov edi, dword ptr [edi + 0xc]
// 004cf323  83c40c               add esp, 0xc
// 004cf326  3b3b                 cmp edi, dword ptr [ebx]
// 004cf328  75e6                 jne 0x4cf310
// 004cf32a  50                   push eax
// 004cf32b  ffd6                 call esi
// 004cf32d  83c404               add esp, 4
// 004cf330  396b0c               cmp dword ptr [ebx + 0xc], ebp
// 004cf333  7e3c                 jle 0x4cf371
// 004cf335  8b7b04               mov edi, dword ptr [ebx + 4]
// 004cf338  8b0f                 mov ecx, dword ptr [edi]
// 004cf33a  51                   push ecx
// 004cf33b  ffd6                 call esi
// 004cf33d  8b5708               mov edx, dword ptr [edi + 8]
// 004cf340  52                   push edx
// 004cf341  ffd6                 call esi
// 004cf343  8bc7                 mov eax, edi
// 004cf345  8b7f0c               mov edi, dword ptr [edi + 0xc]
// 004cf348  83c408               add esp, 8
// 004cf34b  3b7b04               cmp edi, dword ptr [ebx + 4]
// 004cf34e  741b                 je 0x4cf36b
// 004cf350  50                   push eax
// 004cf351  ffd6                 call esi
// 004cf353  8b07                 mov eax, dword ptr [edi]
// 004cf355  50                   push eax
// 004cf356  ffd6                 call esi
// 004cf358  8b4f08               mov ecx, dword ptr [edi + 8]
// 004cf35b  51                   push ecx
// 004cf35c  ffd6                 call esi
// 004cf35e  8bc7                 mov eax, edi
// 004cf360  8b7f0c               mov edi, dword ptr [edi + 0xc]
// 004cf363  83c40c               add esp, 0xc
// 004cf366  3b7b04               cmp edi, dword ptr [ebx + 4]
// 004cf369  75e5                 jne 0x4cf350
// 004cf36b  50                   push eax
// 004cf36c  ffd6                 call esi
// 004cf36e  83c404               add esp, 4
// 004cf371  5f                   pop edi
// 004cf372  5e                   pop esi
// 004cf373  896b0c               mov dword ptr [ebx + 0xc], ebp
// 004cf376  896b08               mov dword ptr [ebx + 8], ebp
// 004cf379  5d                   pop ebp
// 004cf37a  5b                   pop ebx
// 004cf37b  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ?Clear@?$MemoryPool@UInternalPacket@@@DataStructures@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
