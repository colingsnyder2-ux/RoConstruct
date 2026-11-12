// from server: 100% by auto
// roc 2008-06 004bd350  unit: ProfiledRakPeer  size: 361 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bd350
//
// 004bd350  64a100000000         mov eax, dword ptr fs:[0]
// 004bd356  6aff                 push -1
// 004bd358  681b937c00           push 0x7c931b
// 004bd35d  50                   push eax
// 004bd35e  64892500000000       mov dword ptr fs:[0], esp
// 004bd365  81ec20010000         sub esp, 0x120
// 004bd36b  57                   push edi
// 004bd36c  8bf9                 mov edi, ecx
// 004bd36e  8b07                 mov eax, dword ptr [edi]
// 004bd370  8b502c               mov edx, dword ptr [eax + 0x2c]
// 004bd373  ffd2                 call edx
// 004bd375  84c0                 test al, al
// 004bd377  0f8424010000         je 0x4bd4a1
// 004bd37d  55                   push ebp
// 004bd37e  8bac2438010000       mov ebp, dword ptr [esp + 0x138]
// 004bd385  56                   push esi
// 004bd386  33f6                 xor esi, esi
// 004bd388  3bee                 cmp ebp, esi
// 004bd38a  0f840f010000         je 0x4bd49f
// 004bd390  8a4500               mov al, byte ptr [ebp]
// 004bd393  3c30                 cmp al, 0x30
// 004bd395  7c04                 jl 0x4bd39b
// 004bd397  3c32                 cmp al, 0x32
// 004bd399  7e0d                 jle 0x4bd3a8
// 004bd39b  55                   push ebp
// 004bd39c  b9311d9700           mov ecx, 0x971d31
// 004bd3a1  e8da120100           call 0x4ce680
// 004bd3a6  8be8                 mov ebp, eax
// 004bd3a8  53                   push ebx
// 004bd3a9  55                   push ebp
// 004bd3aa  8d4c2418             lea ecx, [esp + 0x18]
// 004bd3ae  e86dc5feff           call 0x4a9920
// 004bd3b3  8b9c2444010000       mov ebx, dword ptr [esp + 0x144]
// 004bd3ba  8d4c241c             lea ecx, [esp + 0x1c]
// 004bd3be  66895c2418           mov word ptr [esp + 0x18], bx
// 004bd3c3  e8c87cfeff           call 0x4a5090
// 004bd3c8  6a01                 push 1
// 004bd3ca  6a08                 push 8
// 004bd3cc  8d442418             lea eax, [esp + 0x18]
// 004bd3d0  50                   push eax
// 004bd3d1  8d4c2428             lea ecx, [esp + 0x28]
// 004bd3d5  89b42444010000       mov dword ptr [esp + 0x144], esi
// 004bd3dc  c644241c1a           mov byte ptr [esp + 0x1c], 0x1a
// 004bd3e1  e81a82feff           call 0x4a5600
// 004bd3e6  8b84244c010000       mov eax, dword ptr [esp + 0x14c]
// 004bd3ed  3bc6                 cmp eax, esi
// 004bd3ef  7e14                 jle 0x4bd405
// 004bd3f1  8b8c2448010000       mov ecx, dword ptr [esp + 0x148]
// 004bd3f8  50                   push eax
// 004bd3f9  51                   push ecx
// 004bd3fa  8d4c2424             lea ecx, [esp + 0x24]
// 004bd3fe  e8fd82feff           call 0x4a5700
// 004bd403  eb17                 jmp 0x4bd41c
// 004bd405  6a01                 push 1
// 004bd407  6a08                 push 8
// 004bd409  8d542418             lea edx, [esp + 0x18]
// 004bd40d  52                   push edx
// 004bd40e  8d4c2428             lea ecx, [esp + 0x28]
// 004bd412  c644241c00           mov byte ptr [esp + 0x1c], 0
// 004bd417  e8e481feff           call 0x4a5600
// 004bd41c  83bfac02000000       cmp dword ptr [edi + 0x2ac], 0
// 004bd423  7638                 jbe 0x4bd45d
// 004bd425  eb09                 jmp 0x4bd430
// 004bd427  8da42400000000       lea esp, [esp]
// 004bd42e  8bff                 mov edi, edi
// 004bd430  8b87a8020000         mov eax, dword ptr [edi + 0x2a8]
// 004bd436  8b0cb0               mov ecx, dword ptr [eax + esi*4]
// 004bd439  8b442418             mov eax, dword ptr [esp + 0x18]
// 004bd43d  8b11                 mov edx, dword ptr [ecx]
// 004bd43f  8b5220               mov edx, dword ptr [edx + 0x20]
// 004bd442  50                   push eax
// 004bd443  8b442418             mov eax, dword ptr [esp + 0x18]
// 004bd447  50                   push eax
// 004bd448  8b442424             mov eax, dword ptr [esp + 0x24]
// 004bd44c  50                   push eax
// 004bd44d  8b442434             mov eax, dword ptr [esp + 0x34]
// 004bd451  50                   push eax
// 004bd452  ffd2                 call edx
// 004bd454  46                   inc esi
// 004bd455  3bb7ac020000         cmp esi, dword ptr [edi + 0x2ac]
// 004bd45b  72d3                 jb 0x4bd430
// 004bd45d  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004bd461  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004bd465  8b9714070000         mov edx, dword ptr [edi + 0x714]
// 004bd46b  53                   push ebx
// 004bd46c  83c007               add eax, 7
// 004bd46f  55                   push ebp
// 004bd470  c1f803               sar eax, 3
// 004bd473  50                   push eax
// 004bd474  8b84245c010000       mov eax, dword ptr [esp + 0x15c]
// 004bd47b  51                   push ecx
// 004bd47c  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 004bd47f  51                   push ecx
// 004bd480  b9311d9700           mov ecx, 0x971d31
// 004bd485  e876130100           call 0x4ce800
// 004bd48a  8d4c241c             lea ecx, [esp + 0x1c]
// 004bd48e  c7842438010000ffffffff mov dword ptr [esp + 0x138], 0xffffffff
// 004bd499  e8027dfeff           call 0x4a51a0
// 004bd49e  5b                   pop ebx
// 004bd49f  5e                   pop esi
// 004bd4a0  5d                   pop ebp
// 004bd4a1  8b8c2424010000       mov ecx, dword ptr [esp + 0x124]
// 004bd4a8  5f                   pop edi
// 004bd4a9  64890d00000000       mov dword ptr fs:[0], ecx
// 004bd4b0  81c42c010000         add esp, 0x12c
// 004bd4b6  c21400               ret 0x14
// library openrbx-raknet/RakPeer.cpp (function ?AdvertiseSystem@RakPeer@@UAEXPBDG0HI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
