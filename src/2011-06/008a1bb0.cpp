// from server: 100% by auto
// roc 2011-06 008a1bb0  unit: CXTPDockContext  size: 476 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008a1bb0
//
// 008a1bb0  8b442404             mov eax, dword ptr [esp + 4]
// 008a1bb4  83ec38               sub esp, 0x38
// 008a1bb7  53                   push ebx
// 008a1bb8  55                   push ebp
// 008a1bb9  56                   push esi
// 008a1bba  8bf1                 mov esi, ecx
// 008a1bbc  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 008a1bbf  8b5610               mov edx, dword ptr [esi + 0x10]
// 008a1bc2  2bc1                 sub eax, ecx
// 008a1bc4  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 008a1bc8  2bca                 sub ecx, edx
// 008a1bca  8b5608               mov edx, dword ptr [esi + 8]
// 008a1bcd  57                   push edi
// 008a1bce  bf42000000           mov edi, 0x42
// 008a1bd3  83fa0a               cmp edx, 0xa
// 008a1bd6  742a                 je 0x8a1c02
// 008a1bd8  83fa0b               cmp edx, 0xb
// 008a1bdb  7420                 je 0x8a1bfd
// 008a1bdd  bf62000000           mov edi, 0x62
// 008a1be2  83fa0c               cmp edx, 0xc
// 008a1be5  750b                 jne 0x8a1bf2
// 008a1be7  014e44               add dword ptr [esi + 0x44], ecx
// 008a1bea  8b464c               mov eax, dword ptr [esi + 0x4c]
// 008a1bed  2b4644               sub eax, dword ptr [esi + 0x44]
// 008a1bf0  eb1e                 jmp 0x8a1c10
// 008a1bf2  014e4c               add dword ptr [esi + 0x4c], ecx
// 008a1bf5  8b464c               mov eax, dword ptr [esi + 0x4c]
// 008a1bf8  2b4644               sub eax, dword ptr [esi + 0x44]
// 008a1bfb  eb13                 jmp 0x8a1c10
// 008a1bfd  83fa0a               cmp edx, 0xa
// 008a1c00  7505                 jne 0x8a1c07
// 008a1c02  014640               add dword ptr [esi + 0x40], eax
// 008a1c05  eb03                 jmp 0x8a1c0a
// 008a1c07  014648               add dword ptr [esi + 0x48], eax
// 008a1c0a  8b4648               mov eax, dword ptr [esi + 0x48]
// 008a1c0d  2b4640               sub eax, dword ptr [esi + 0x40]
// 008a1c10  8b4e04               mov ecx, dword ptr [esi + 4]
// 008a1c13  8b11                 mov edx, dword ptr [ecx]
// 008a1c15  8b92d0010000         mov edx, dword ptr [edx + 0x1d0]
// 008a1c1b  33db                 xor ebx, ebx
// 008a1c1d  85c0                 test eax, eax
// 008a1c1f  0f9cc3               setl bl
// 008a1c22  57                   push edi
// 008a1c23  4b                   dec ebx
// 008a1c24  23d8                 and ebx, eax
// 008a1c26  53                   push ebx
// 008a1c27  8d442418             lea eax, [esp + 0x18]
// 008a1c2b  50                   push eax
// 008a1c2c  ffd2                 call edx
// 008a1c2e  8b4e04               mov ecx, dword ptr [esi + 4]
// 008a1c31  8b5120               mov edx, dword ptr [ecx + 0x20]
// 008a1c34  8d442418             lea eax, [esp + 0x18]
// 008a1c38  50                   push eax
// 008a1c39  52                   push edx
// 008a1c3a  ff155c1ca400         call dword ptr [0xa41c5c]
// 008a1c40  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008a1c44  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 008a1c48  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 008a1c4c  8b542410             mov edx, dword ptr [esp + 0x10]
// 008a1c50  8bc7                 mov eax, edi
// 008a1c52  2b442418             sub eax, dword ptr [esp + 0x18]
// 008a1c56  8bcb                 mov ecx, ebx
// 008a1c58  2bcd                 sub ecx, ebp
// 008a1c5a  3bc2                 cmp eax, edx
// 008a1c5c  8b442414             mov eax, dword ptr [esp + 0x14]
// 008a1c60  7508                 jne 0x8a1c6a
// 008a1c62  3bc8                 cmp ecx, eax
// 008a1c64  0f840a010000         je 0x8a1d74
// 008a1c6a  8b4e08               mov ecx, dword ptr [esi + 8]
// 008a1c6d  83f90b               cmp ecx, 0xb
// 008a1c70  742b                 je 0x8a1c9d
// 008a1c72  83f90f               cmp ecx, 0xf
// 008a1c75  7426                 je 0x8a1c9d
// 008a1c77  83f90a               cmp ecx, 0xa
// 008a1c7a  750a                 jne 0x8a1c86
// 008a1c7c  03c5                 add eax, ebp
// 008a1c7e  2bfa                 sub edi, edx
// 008a1c80  897c2418             mov dword ptr [esp + 0x18], edi
// 008a1c84  eb23                 jmp 0x8a1ca9
// 008a1c86  83f90c               cmp ecx, 0xc
// 008a1c89  7522                 jne 0x8a1cad
// 008a1c8b  2bd8                 sub ebx, eax
// 008a1c8d  8b442418             mov eax, dword ptr [esp + 0x18]
// 008a1c91  03c2                 add eax, edx
// 008a1c93  895c241c             mov dword ptr [esp + 0x1c], ebx
// 008a1c97  89442420             mov dword ptr [esp + 0x20], eax
// 008a1c9b  eb10                 jmp 0x8a1cad
// 008a1c9d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008a1ca1  03ca                 add ecx, edx
// 008a1ca3  03c5                 add eax, ebp
// 008a1ca5  894c2420             mov dword ptr [esp + 0x20], ecx
// 008a1ca9  89442424             mov dword ptr [esp + 0x24], eax
// 008a1cad  8b5604               mov edx, dword ptr [esi + 4]
// 008a1cb0  52                   push edx
// 008a1cb1  8d44242c             lea eax, [esp + 0x2c]
// 008a1cb5  50                   push eax
// 008a1cb6  e85504fbff           call 0x852110
// 008a1cbb  8bc8                 mov ecx, eax
// 008a1cbd  e8eefffaff           call 0x851cb0
// 008a1cc2  8d4c2418             lea ecx, [esp + 0x18]
// 008a1cc6  51                   push ecx
// 008a1cc7  8d54242c             lea edx, [esp + 0x2c]
// 008a1ccb  52                   push edx
// 008a1ccc  8d442440             lea eax, [esp + 0x40]
// 008a1cd0  50                   push eax
// 008a1cd1  ff15fc1ba400         call dword ptr [0xa41bfc]
// 008a1cd7  85c0                 test eax, eax
// 008a1cd9  7566                 jne 0x8a1d41
// 008a1cdb  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008a1cdf  8b442428             mov eax, dword ptr [esp + 0x28]
// 008a1ce3  3bc8                 cmp ecx, eax
// 008a1ce5  8b3d601ca400         mov edi, dword ptr [0xa41c60]
// 008a1ceb  7d0e                 jge 0x8a1cfb
// 008a1ced  2b442418             sub eax, dword ptr [esp + 0x18]
// 008a1cf1  6a00                 push 0
// 008a1cf3  50                   push eax
// 008a1cf4  8d4c2420             lea ecx, [esp + 0x20]
// 008a1cf8  51                   push ecx
// 008a1cf9  eb14                 jmp 0x8a1d0f
// 008a1cfb  8b442430             mov eax, dword ptr [esp + 0x30]
// 008a1cff  39442418             cmp dword ptr [esp + 0x18], eax
// 008a1d03  7e0c                 jle 0x8a1d11
// 008a1d05  6a00                 push 0
// 008a1d07  2bc1                 sub eax, ecx
// 008a1d09  50                   push eax
// 008a1d0a  8d542420             lea edx, [esp + 0x20]
// 008a1d0e  52                   push edx
// 008a1d0f  ffd7                 call edi
// 008a1d11  8b442424             mov eax, dword ptr [esp + 0x24]
// 008a1d15  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 008a1d19  3bc1                 cmp eax, ecx
// 008a1d1b  7d0e                 jge 0x8a1d2b
// 008a1d1d  2b4c241c             sub ecx, dword ptr [esp + 0x1c]
// 008a1d21  8d442418             lea eax, [esp + 0x18]
// 008a1d25  51                   push ecx
// 008a1d26  6a00                 push 0
// 008a1d28  50                   push eax
// 008a1d29  eb14                 jmp 0x8a1d3f
// 008a1d2b  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 008a1d2f  394c241c             cmp dword ptr [esp + 0x1c], ecx
// 008a1d33  7e10                 jle 0x8a1d45
// 008a1d35  2bc8                 sub ecx, eax
// 008a1d37  51                   push ecx
// 008a1d38  6a00                 push 0
// 008a1d3a  8d4c2420             lea ecx, [esp + 0x20]
// 008a1d3e  51                   push ecx
// 008a1d3f  ffd7                 call edi
// 008a1d41  8b442424             mov eax, dword ptr [esp + 0x24]
// 008a1d45  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 008a1d49  8b542418             mov edx, dword ptr [esp + 0x18]
// 008a1d4d  6a01                 push 1
// 008a1d4f  2bc1                 sub eax, ecx
// 008a1d51  50                   push eax
// 008a1d52  8b442428             mov eax, dword ptr [esp + 0x28]
// 008a1d56  2bc2                 sub eax, edx
// 008a1d58  50                   push eax
// 008a1d59  51                   push ecx
// 008a1d5a  8b4e04               mov ecx, dword ptr [esi + 4]
// 008a1d5d  52                   push edx
// 008a1d5e  e8cd86f6ff           call 0x80a430
// 008a1d63  8b4e04               mov ecx, dword ptr [esi + 4]
// 008a1d66  8b11                 mov edx, dword ptr [ecx]
// 008a1d68  8b82ac010000         mov eax, dword ptr [edx + 0x1ac]
// 008a1d6e  6a01                 push 1
// 008a1d70  6a00                 push 0
// 008a1d72  ffd0                 call eax
// 008a1d74  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 008a1d78  8b542450             mov edx, dword ptr [esp + 0x50]
// 008a1d7c  5f                   pop edi
// 008a1d7d  894e0c               mov dword ptr [esi + 0xc], ecx
// 008a1d80  895610               mov dword ptr [esi + 0x10], edx
// 008a1d83  5e                   pop esi
// 008a1d84  5d                   pop ebp
// 008a1d85  5b                   pop ebx
// 008a1d86  83c438               add esp, 0x38
// 008a1d89  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPDockContext.cpp (function ?Stretch@CXTPDockContext@@IAEXVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPDockContext.cpp
