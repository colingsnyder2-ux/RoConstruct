// from server: 100% by auto
// roc 2011-06 008a1a90  unit: CXTPDockContext  size: 275 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008a1a90
//
// 008a1a90  83ec30               sub esp, 0x30
// 008a1a93  53                   push ebx
// 008a1a94  56                   push esi
// 008a1a95  8bf1                 mov esi, ecx
// 008a1a97  8b460c               mov eax, dword ptr [esi + 0xc]
// 008a1a9a  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 008a1a9e  8b5610               mov edx, dword ptr [esi + 0x10]
// 008a1aa1  57                   push edi
// 008a1aa2  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 008a1aa6  2bc8                 sub ecx, eax
// 008a1aa8  8b4608               mov eax, dword ptr [esi + 8]
// 008a1aab  2bfa                 sub edi, edx
// 008a1aad  83f80a               cmp eax, 0xa
// 008a1ab0  740a                 je 0x8a1abc
// 008a1ab2  83f80d               cmp eax, 0xd
// 008a1ab5  7405                 je 0x8a1abc
// 008a1ab7  83f810               cmp eax, 0x10
// 008a1aba  7503                 jne 0x8a1abf
// 008a1abc  014e40               add dword ptr [esi + 0x40], ecx
// 008a1abf  83f80b               cmp eax, 0xb
// 008a1ac2  740a                 je 0x8a1ace
// 008a1ac4  83f80e               cmp eax, 0xe
// 008a1ac7  7405                 je 0x8a1ace
// 008a1ac9  83f811               cmp eax, 0x11
// 008a1acc  7503                 jne 0x8a1ad1
// 008a1ace  014e48               add dword ptr [esi + 0x48], ecx
// 008a1ad1  83f80c               cmp eax, 0xc
// 008a1ad4  740a                 je 0x8a1ae0
// 008a1ad6  83f80e               cmp eax, 0xe
// 008a1ad9  7405                 je 0x8a1ae0
// 008a1adb  83f80d               cmp eax, 0xd
// 008a1ade  7503                 jne 0x8a1ae3
// 008a1ae0  017e44               add dword ptr [esi + 0x44], edi
// 008a1ae3  83f80f               cmp eax, 0xf
// 008a1ae6  740a                 je 0x8a1af2
// 008a1ae8  83f811               cmp eax, 0x11
// 008a1aeb  7405                 je 0x8a1af2
// 008a1aed  83f810               cmp eax, 0x10
// 008a1af0  7503                 jne 0x8a1af5
// 008a1af2  017e4c               add dword ptr [esi + 0x4c], edi
// 008a1af5  8b4e04               mov ecx, dword ptr [esi + 4]
// 008a1af8  8b5120               mov edx, dword ptr [ecx + 0x20]
// 008a1afb  8d44240c             lea eax, [esp + 0xc]
// 008a1aff  50                   push eax
// 008a1b00  52                   push edx
// 008a1b01  ff155c1ca400         call dword ptr [0xa41c5c]
// 008a1b07  8b4648               mov eax, dword ptr [esi + 0x48]
// 008a1b0a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008a1b0e  2b4640               sub eax, dword ptr [esi + 0x40]
// 008a1b11  8b564c               mov edx, dword ptr [esi + 0x4c]
// 008a1b14  2b4c240c             sub ecx, dword ptr [esp + 0xc]
// 008a1b18  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 008a1b1c  2b5644               sub edx, dword ptr [esi + 0x44]
// 008a1b1f  2b5c2410             sub ebx, dword ptr [esp + 0x10]
// 008a1b23  8d7e40               lea edi, [esi + 0x40]
// 008a1b26  3bc8                 cmp ecx, eax
// 008a1b28  7504                 jne 0x8a1b2e
// 008a1b2a  3bda                 cmp ebx, edx
// 008a1b2c  745e                 je 0x8a1b8c
// 008a1b2e  8b4604               mov eax, dword ptr [esi + 4]
// 008a1b31  50                   push eax
// 008a1b32  8d4c2420             lea ecx, [esp + 0x20]
// 008a1b36  51                   push ecx
// 008a1b37  e8d405fbff           call 0x852110
// 008a1b3c  8bc8                 mov ecx, eax
// 008a1b3e  e86d01fbff           call 0x851cb0
// 008a1b43  57                   push edi
// 008a1b44  50                   push eax
// 008a1b45  8d542434             lea edx, [esp + 0x34]
// 008a1b49  52                   push edx
// 008a1b4a  ff15fc1ba400         call dword ptr [0xa41bfc]
// 008a1b50  85c0                 test eax, eax
// 008a1b52  7438                 je 0x8a1b8c
// 008a1b54  8b4608               mov eax, dword ptr [esi + 8]
// 008a1b57  8b0f                 mov ecx, dword ptr [edi]
// 008a1b59  8b5704               mov edx, dword ptr [edi + 4]
// 008a1b5c  50                   push eax
// 008a1b5d  83ec10               sub esp, 0x10
// 008a1b60  8bc4                 mov eax, esp
// 008a1b62  8908                 mov dword ptr [eax], ecx
// 008a1b64  8b4f08               mov ecx, dword ptr [edi + 8]
// 008a1b67  895004               mov dword ptr [eax + 4], edx
// 008a1b6a  8b570c               mov edx, dword ptr [edi + 0xc]
// 008a1b6d  894808               mov dword ptr [eax + 8], ecx
// 008a1b70  8b4e04               mov ecx, dword ptr [esi + 4]
// 008a1b73  89500c               mov dword ptr [eax + 0xc], edx
// 008a1b76  e8b5790500           call 0x8f9530
// 008a1b7b  8b4e04               mov ecx, dword ptr [esi + 4]
// 008a1b7e  8b01                 mov eax, dword ptr [ecx]
// 008a1b80  8b90ac010000         mov edx, dword ptr [eax + 0x1ac]
// 008a1b86  6a01                 push 1
// 008a1b88  6a00                 push 0
// 008a1b8a  ffd2                 call edx
// 008a1b8c  8b442440             mov eax, dword ptr [esp + 0x40]
// 008a1b90  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 008a1b94  5f                   pop edi
// 008a1b95  89460c               mov dword ptr [esi + 0xc], eax
// 008a1b98  894e10               mov dword ptr [esi + 0x10], ecx
// 008a1b9b  5e                   pop esi
// 008a1b9c  5b                   pop ebx
// 008a1b9d  83c430               add esp, 0x30
// 008a1ba0  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPDockContext.cpp (function ?Resize@CXTPDockContext@@IAEXVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPDockContext.cpp
