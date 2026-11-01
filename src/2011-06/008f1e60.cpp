// from server: 100% by auto
// roc 2011-06 008f1e60  unit: CXTCaptionButtonThemeOffice2003  size: 363 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f1e60
//
// 008f1e60  83ec44               sub esp, 0x44
// 008f1e63  53                   push ebx
// 008f1e64  8b5c2450             mov ebx, dword ptr [esp + 0x50]
// 008f1e68  894c2404             mov dword ptr [esp + 4], ecx
// 008f1e6c  85db                 test ebx, ebx
// 008f1e6e  7504                 jne 0x8f1e74
// 008f1e70  33c0                 xor eax, eax
// 008f1e72  eb03                 jmp 0x8f1e77
// 008f1e74  8b4320               mov eax, dword ptr [ebx + 0x20]
// 008f1e77  50                   push eax
// 008f1e78  ff15ec1ba400         call dword ptr [0xa41bec]
// 008f1e7e  85c0                 test eax, eax
// 008f1e80  7507                 jne 0x8f1e89
// 008f1e82  5b                   pop ebx
// 008f1e83  83c444               add esp, 0x44
// 008f1e86  c20800               ret 8
// 008f1e89  55                   push ebp
// 008f1e8a  56                   push esi
// 008f1e8b  8b742454             mov esi, dword ptr [esp + 0x54]
// 008f1e8f  8b4618               mov eax, dword ptr [esi + 0x18]
// 008f1e92  57                   push edi
// 008f1e93  50                   push eax
// 008f1e94  e81fa70d00           call 0x9cc5b8
// 008f1e99  8d4e1c               lea ecx, [esi + 0x1c]
// 008f1e9c  51                   push ecx
// 008f1e9d  8d542418             lea edx, [esp + 0x18]
// 008f1ea1  52                   push edx
// 008f1ea2  8bf8                 mov edi, eax
// 008f1ea4  ff15681ca400         call dword ptr [0xa41c68]
// 008f1eaa  8babac000000         mov ebp, dword ptr [ebx + 0xac]
// 008f1eb0  8b4610               mov eax, dword ptr [esi + 0x10]
// 008f1eb3  8944245c             mov dword ptr [esp + 0x5c], eax
// 008f1eb7  85ed                 test ebp, ebp
// 008f1eb9  7504                 jne 0x8f1ebf
// 008f1ebb  33c0                 xor eax, eax
// 008f1ebd  eb03                 jmp 0x8f1ec2
// 008f1ebf  8b4520               mov eax, dword ptr [ebp + 0x20]
// 008f1ec2  50                   push eax
// 008f1ec3  ff15ec1ba400         call dword ptr [0xa41bec]
// 008f1ec9  85c0                 test eax, eax
// 008f1ecb  0f84e5000000         je 0x8f1fb6
// 008f1ed1  83bba000000000       cmp dword ptr [ebx + 0xa0], 0
// 008f1ed8  750f                 jne 0x8f1ee9
// 008f1eda  ff15381ba400         call dword ptr [0xa41b38]
// 008f1ee0  3b4320               cmp eax, dword ptr [ebx + 0x20]
// 008f1ee3  7404                 je 0x8f1ee9
// 008f1ee5  33c9                 xor ecx, ecx
// 008f1ee7  eb05                 jmp 0x8f1eee
// 008f1ee9  b901000000           mov ecx, 1
// 008f1eee  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 008f1ef2  83e001               and eax, 1
// 008f1ef5  7557                 jne 0x8f1f4e
// 008f1ef7  85c9                 test ecx, ecx
// 008f1ef9  755f                 jne 0x8f1f5a
// 008f1efb  53                   push ebx
// 008f1efc  8d4c2428             lea ecx, [esp + 0x28]
// 008f1f00  e82baef6ff           call 0x85cd30
// 008f1f05  8d4c2434             lea ecx, [esp + 0x34]
// 008f1f09  e8d229f5ff           call 0x8448e0
// 008f1f0e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008f1f12  8b11                 mov edx, dword ptr [ecx]
// 008f1f14  8b527c               mov edx, dword ptr [edx + 0x7c]
// 008f1f17  8d442434             lea eax, [esp + 0x34]
// 008f1f1b  50                   push eax
// 008f1f1c  55                   push ebp
// 008f1f1d  8d44242c             lea eax, [esp + 0x2c]
// 008f1f21  50                   push eax
// 008f1f22  ffd2                 call edx
// 008f1f24  6a00                 push 0
// 008f1f26  6a00                 push 0
// 008f1f28  8d44243c             lea eax, [esp + 0x3c]
// 008f1f2c  50                   push eax
// 008f1f2d  8d4c2420             lea ecx, [esp + 0x20]
// 008f1f31  51                   push ecx
// 008f1f32  57                   push edi
// 008f1f33  e848cef6ff           call 0x85ed80
// 008f1f38  8bc8                 mov ecx, eax
// 008f1f3a  e861d1f6ff           call 0x85f0a0
// 008f1f3f  5f                   pop edi
// 008f1f40  5e                   pop esi
// 008f1f41  5d                   pop ebp
// 008f1f42  b801000000           mov eax, 1
// 008f1f47  5b                   pop ebx
// 008f1f48  83c444               add esp, 0x44
// 008f1f4b  c20800               ret 8
// 008f1f4e  e88d34f5ff           call 0x8453e0
// 008f1f53  0520010000           add eax, 0x120
// 008f1f58  eb0a                 jmp 0x8f1f64
// 008f1f5a  e88134f5ff           call 0x8453e0
// 008f1f5f  0540010000           add eax, 0x140
// 008f1f64  6a00                 push 0
// 008f1f66  6a00                 push 0
// 008f1f68  50                   push eax
// 008f1f69  8d542420             lea edx, [esp + 0x20]
// 008f1f6d  52                   push edx
// 008f1f6e  57                   push edi
// 008f1f6f  e80ccef6ff           call 0x85ed80
// 008f1f74  8bc8                 mov ecx, eax
// 008f1f76  e825d1f6ff           call 0x85f0a0
// 008f1f7b  e86034f5ff           call 0x8453e0
// 008f1f80  6a20                 push 0x20
// 008f1f82  8bc8                 mov ecx, eax
// 008f1f84  e8572ef5ff           call 0x844de0
// 008f1f89  8bf0                 mov esi, eax
// 008f1f8b  e85034f5ff           call 0x8453e0
// 008f1f90  56                   push esi
// 008f1f91  6a20                 push 0x20
// 008f1f93  8bc8                 mov ecx, eax
// 008f1f95  e8462ef5ff           call 0x844de0
// 008f1f9a  50                   push eax
// 008f1f9b  8d44241c             lea eax, [esp + 0x1c]
// 008f1f9f  50                   push eax
// 008f1fa0  8bcf                 mov ecx, edi
// 008f1fa2  e8738ef1ff           call 0x80ae1a
// 008f1fa7  5f                   pop edi
// 008f1fa8  5e                   pop esi
// 008f1fa9  5d                   pop ebp
// 008f1faa  b801000000           mov eax, 1
// 008f1faf  5b                   pop ebx
// 008f1fb0  83c444               add esp, 0x44
// 008f1fb3  c20800               ret 8
// 008f1fb6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008f1fba  53                   push ebx
// 008f1fbb  56                   push esi
// 008f1fbc  e8ef0f0100           call 0x902fb0
// 008f1fc1  5f                   pop edi
// 008f1fc2  5e                   pop esi
// 008f1fc3  5d                   pop ebp
// 008f1fc4  5b                   pop ebx
// 008f1fc5  83c444               add esp, 0x44
// 008f1fc8  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawButtonThemeBackground@CXTCaptionButtonThemeOffice2003@@MAEHPAUtagDRAWITEMSTRUCT@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
