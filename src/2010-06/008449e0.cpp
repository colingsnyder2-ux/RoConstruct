// from server: 100% by auto
// roc 2010-06 008449e0  unit: CXTPDockContext  size: 476 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008449e0
//
// 008449e0  8b442404             mov eax, dword ptr [esp + 4]
// 008449e4  83ec38               sub esp, 0x38
// 008449e7  53                   push ebx
// 008449e8  55                   push ebp
// 008449e9  56                   push esi
// 008449ea  8bf1                 mov esi, ecx
// 008449ec  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 008449ef  8b5610               mov edx, dword ptr [esi + 0x10]
// 008449f2  2bc1                 sub eax, ecx
// 008449f4  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 008449f8  2bca                 sub ecx, edx
// 008449fa  8b5608               mov edx, dword ptr [esi + 8]
// 008449fd  57                   push edi
// 008449fe  bf42000000           mov edi, 0x42
// 00844a03  83fa0a               cmp edx, 0xa
// 00844a06  742a                 je 0x844a32
// 00844a08  83fa0b               cmp edx, 0xb
// 00844a0b  7420                 je 0x844a2d
// 00844a0d  bf62000000           mov edi, 0x62
// 00844a12  83fa0c               cmp edx, 0xc
// 00844a15  750b                 jne 0x844a22
// 00844a17  014e44               add dword ptr [esi + 0x44], ecx
// 00844a1a  8b464c               mov eax, dword ptr [esi + 0x4c]
// 00844a1d  2b4644               sub eax, dword ptr [esi + 0x44]
// 00844a20  eb1e                 jmp 0x844a40
// 00844a22  014e4c               add dword ptr [esi + 0x4c], ecx
// 00844a25  8b464c               mov eax, dword ptr [esi + 0x4c]
// 00844a28  2b4644               sub eax, dword ptr [esi + 0x44]
// 00844a2b  eb13                 jmp 0x844a40
// 00844a2d  83fa0a               cmp edx, 0xa
// 00844a30  7505                 jne 0x844a37
// 00844a32  014640               add dword ptr [esi + 0x40], eax
// 00844a35  eb03                 jmp 0x844a3a
// 00844a37  014648               add dword ptr [esi + 0x48], eax
// 00844a3a  8b4648               mov eax, dword ptr [esi + 0x48]
// 00844a3d  2b4640               sub eax, dword ptr [esi + 0x40]
// 00844a40  8b4e04               mov ecx, dword ptr [esi + 4]
// 00844a43  8b11                 mov edx, dword ptr [ecx]
// 00844a45  8b92d0010000         mov edx, dword ptr [edx + 0x1d0]
// 00844a4b  33db                 xor ebx, ebx
// 00844a4d  85c0                 test eax, eax
// 00844a4f  0f9cc3               setl bl
// 00844a52  57                   push edi
// 00844a53  4b                   dec ebx
// 00844a54  23d8                 and ebx, eax
// 00844a56  53                   push ebx
// 00844a57  8d442418             lea eax, [esp + 0x18]
// 00844a5b  50                   push eax
// 00844a5c  ffd2                 call edx
// 00844a5e  8b4e04               mov ecx, dword ptr [esi + 4]
// 00844a61  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00844a64  8d442418             lea eax, [esp + 0x18]
// 00844a68  50                   push eax
// 00844a69  52                   push edx
// 00844a6a  ff153cbc9e00         call dword ptr [0x9ebc3c]
// 00844a70  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00844a74  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00844a78  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00844a7c  8b542410             mov edx, dword ptr [esp + 0x10]
// 00844a80  8bc7                 mov eax, edi
// 00844a82  2b442418             sub eax, dword ptr [esp + 0x18]
// 00844a86  8bcb                 mov ecx, ebx
// 00844a88  2bcd                 sub ecx, ebp
// 00844a8a  3bc2                 cmp eax, edx
// 00844a8c  8b442414             mov eax, dword ptr [esp + 0x14]
// 00844a90  7508                 jne 0x844a9a
// 00844a92  3bc8                 cmp ecx, eax
// 00844a94  0f840a010000         je 0x844ba4
// 00844a9a  8b4e08               mov ecx, dword ptr [esi + 8]
// 00844a9d  83f90b               cmp ecx, 0xb
// 00844aa0  742b                 je 0x844acd
// 00844aa2  83f90f               cmp ecx, 0xf
// 00844aa5  7426                 je 0x844acd
// 00844aa7  83f90a               cmp ecx, 0xa
// 00844aaa  750a                 jne 0x844ab6
// 00844aac  03c5                 add eax, ebp
// 00844aae  2bfa                 sub edi, edx
// 00844ab0  897c2418             mov dword ptr [esp + 0x18], edi
// 00844ab4  eb23                 jmp 0x844ad9
// 00844ab6  83f90c               cmp ecx, 0xc
// 00844ab9  7522                 jne 0x844add
// 00844abb  2bd8                 sub ebx, eax
// 00844abd  8b442418             mov eax, dword ptr [esp + 0x18]
// 00844ac1  03c2                 add eax, edx
// 00844ac3  895c241c             mov dword ptr [esp + 0x1c], ebx
// 00844ac7  89442420             mov dword ptr [esp + 0x20], eax
// 00844acb  eb10                 jmp 0x844add
// 00844acd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00844ad1  03ca                 add ecx, edx
// 00844ad3  03c5                 add eax, ebp
// 00844ad5  894c2420             mov dword ptr [esp + 0x20], ecx
// 00844ad9  89442424             mov dword ptr [esp + 0x24], eax
// 00844add  8b5604               mov edx, dword ptr [esi + 4]
// 00844ae0  52                   push edx
// 00844ae1  8d44242c             lea eax, [esp + 0x2c]
// 00844ae5  50                   push eax
// 00844ae6  e8e5bdfaff           call 0x7f08d0
// 00844aeb  8bc8                 mov ecx, eax
// 00844aed  e87eb9faff           call 0x7f0470
// 00844af2  8d4c2418             lea ecx, [esp + 0x18]
// 00844af6  51                   push ecx
// 00844af7  8d54242c             lea edx, [esp + 0x2c]
// 00844afb  52                   push edx
// 00844afc  8d442440             lea eax, [esp + 0x40]
// 00844b00  50                   push eax
// 00844b01  ff15a4ba9e00         call dword ptr [0x9ebaa4]
// 00844b07  85c0                 test eax, eax
// 00844b09  7566                 jne 0x844b71
// 00844b0b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00844b0f  8b442428             mov eax, dword ptr [esp + 0x28]
// 00844b13  3bc8                 cmp ecx, eax
// 00844b15  8b3d40bc9e00         mov edi, dword ptr [0x9ebc40]
// 00844b1b  7d0e                 jge 0x844b2b
// 00844b1d  2b442418             sub eax, dword ptr [esp + 0x18]
// 00844b21  6a00                 push 0
// 00844b23  50                   push eax
// 00844b24  8d4c2420             lea ecx, [esp + 0x20]
// 00844b28  51                   push ecx
// 00844b29  eb14                 jmp 0x844b3f
// 00844b2b  8b442430             mov eax, dword ptr [esp + 0x30]
// 00844b2f  39442418             cmp dword ptr [esp + 0x18], eax
// 00844b33  7e0c                 jle 0x844b41
// 00844b35  6a00                 push 0
// 00844b37  2bc1                 sub eax, ecx
// 00844b39  50                   push eax
// 00844b3a  8d542420             lea edx, [esp + 0x20]
// 00844b3e  52                   push edx
// 00844b3f  ffd7                 call edi
// 00844b41  8b442424             mov eax, dword ptr [esp + 0x24]
// 00844b45  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00844b49  3bc1                 cmp eax, ecx
// 00844b4b  7d0e                 jge 0x844b5b
// 00844b4d  2b4c241c             sub ecx, dword ptr [esp + 0x1c]
// 00844b51  8d442418             lea eax, [esp + 0x18]
// 00844b55  51                   push ecx
// 00844b56  6a00                 push 0
// 00844b58  50                   push eax
// 00844b59  eb14                 jmp 0x844b6f
// 00844b5b  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00844b5f  394c241c             cmp dword ptr [esp + 0x1c], ecx
// 00844b63  7e10                 jle 0x844b75
// 00844b65  2bc8                 sub ecx, eax
// 00844b67  51                   push ecx
// 00844b68  6a00                 push 0
// 00844b6a  8d4c2420             lea ecx, [esp + 0x20]
// 00844b6e  51                   push ecx
// 00844b6f  ffd7                 call edi
// 00844b71  8b442424             mov eax, dword ptr [esp + 0x24]
// 00844b75  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00844b79  8b542418             mov edx, dword ptr [esp + 0x18]
// 00844b7d  6a01                 push 1
// 00844b7f  2bc1                 sub eax, ecx
// 00844b81  50                   push eax
// 00844b82  8b442428             mov eax, dword ptr [esp + 0x28]
// 00844b86  2bc2                 sub eax, edx
// 00844b88  50                   push eax
// 00844b89  51                   push ecx
// 00844b8a  8b4e04               mov ecx, dword ptr [esi + 4]
// 00844b8d  52                   push edx
// 00844b8e  e8df31f6ff           call 0x7a7d72
// 00844b93  8b4e04               mov ecx, dword ptr [esi + 4]
// 00844b96  8b11                 mov edx, dword ptr [ecx]
// 00844b98  8b82ac010000         mov eax, dword ptr [edx + 0x1ac]
// 00844b9e  6a01                 push 1
// 00844ba0  6a00                 push 0
// 00844ba2  ffd0                 call eax
// 00844ba4  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00844ba8  8b542450             mov edx, dword ptr [esp + 0x50]
// 00844bac  5f                   pop edi
// 00844bad  894e0c               mov dword ptr [esi + 0xc], ecx
// 00844bb0  895610               mov dword ptr [esi + 0x10], edx
// 00844bb3  5e                   pop esi
// 00844bb4  5d                   pop ebp
// 00844bb5  5b                   pop ebx
// 00844bb6  83c438               add esp, 0x38
// 00844bb9  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPDockContext.cpp (function ?Stretch@CXTPDockContext@@IAEXVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPDockContext.cpp
