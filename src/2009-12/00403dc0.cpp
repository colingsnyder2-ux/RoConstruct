// from server: 100% by auto
// roc 2009-12 00403dc0  unit: VCApp::?$CComObject  size: 324 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00403dc0
//
// 00403dc0  55                   push ebp
// 00403dc1  8bec                 mov ebp, esp
// 00403dc3  83e4f8               and esp, 0xfffffff8
// 00403dc6  81ec1c010000         sub esp, 0x11c
// 00403dcc  8b01                 mov eax, dword ptr [ecx]
// 00403dce  8b5508               mov edx, dword ptr [ebp + 8]
// 00403dd1  53                   push ebx
// 00403dd2  56                   push esi
// 00403dd3  8b7104               mov esi, dword ptr [ecx + 4]
// 00403dd6  57                   push edi
// 00403dd7  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00403ddb  8d4c2418             lea ecx, [esp + 0x18]
// 00403ddf  51                   push ecx
// 00403de0  33db                 xor ebx, ebx
// 00403de2  81ce1f000200         or esi, 0x2001f
// 00403de8  56                   push esi
// 00403de9  53                   push ebx
// 00403dea  52                   push edx
// 00403deb  50                   push eax
// 00403dec  895c2420             mov dword ptr [esp + 0x20], ebx
// 00403df0  895c2424             mov dword ptr [esp + 0x24], ebx
// 00403df4  895c242c             mov dword ptr [esp + 0x2c], ebx
// 00403df8  ff1510b09800         call dword ptr [0x98b010]
// 00403dfe  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00403e02  8bf8                 mov edi, eax
// 00403e04  3bfb                 cmp edi, ebx
// 00403e06  7525                 jne 0x403e2d
// 00403e08  33c0                 xor eax, eax
// 00403e0a  3bcb                 cmp ecx, ebx
// 00403e0c  7407                 je 0x403e15
// 00403e0e  51                   push ecx
// 00403e0f  ff1508b09800         call dword ptr [0x98b008]
// 00403e15  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00403e19  81e600030000         and esi, 0x300
// 00403e1f  8bf8                 mov edi, eax
// 00403e21  894c240c             mov dword ptr [esp + 0xc], ecx
// 00403e25  89742410             mov dword ptr [esp + 0x10], esi
// 00403e29  3bc3                 cmp eax, ebx
// 00403e2b  7416                 je 0x403e43
// 00403e2d  3bcb                 cmp ecx, ebx
// 00403e2f  7407                 je 0x403e38
// 00403e31  51                   push ecx
// 00403e32  ff1508b09800         call dword ptr [0x98b008]
// 00403e38  8bc7                 mov eax, edi
// 00403e3a  5f                   pop edi
// 00403e3b  5e                   pop esi
// 00403e3c  5b                   pop ebx
// 00403e3d  8be5                 mov esp, ebp
// 00403e3f  5d                   pop ebp
// 00403e40  c20400               ret 4
// 00403e43  8b351cb09800         mov esi, dword ptr [0x98b01c]
// 00403e49  8d442420             lea eax, [esp + 0x20]
// 00403e4d  50                   push eax
// 00403e4e  53                   push ebx
// 00403e4f  53                   push ebx
// 00403e50  53                   push ebx
// 00403e51  8d542424             lea edx, [esp + 0x24]
// 00403e55  52                   push edx
// 00403e56  8d44243c             lea eax, [esp + 0x3c]
// 00403e5a  50                   push eax
// 00403e5b  53                   push ebx
// 00403e5c  51                   push ecx
// 00403e5d  c744243400010000     mov dword ptr [esp + 0x34], 0x100
// 00403e65  ffd6                 call esi
// 00403e67  85c0                 test eax, eax
// 00403e69  753f                 jne 0x403eaa
// 00403e6b  eb03                 jmp 0x403e70
// 00403e6d  8d4900               lea ecx, [ecx]
// 00403e70  8d4c2428             lea ecx, [esp + 0x28]
// 00403e74  51                   push ecx
// 00403e75  8d4c2410             lea ecx, [esp + 0x10]
// 00403e79  e842ffffff           call 0x403dc0
// 00403e7e  8bf8                 mov edi, eax
// 00403e80  3bfb                 cmp edi, ebx
// 00403e82  7566                 jne 0x403eea
// 00403e84  8d542420             lea edx, [esp + 0x20]
// 00403e88  52                   push edx
// 00403e89  8b542410             mov edx, dword ptr [esp + 0x10]
// 00403e8d  53                   push ebx
// 00403e8e  53                   push ebx
// 00403e8f  53                   push ebx
// 00403e90  8d442424             lea eax, [esp + 0x24]
// 00403e94  50                   push eax
// 00403e95  8d4c243c             lea ecx, [esp + 0x3c]
// 00403e99  51                   push ecx
// 00403e9a  53                   push ebx
// 00403e9b  52                   push edx
// 00403e9c  c744243400010000     mov dword ptr [esp + 0x34], 0x100
// 00403ea4  ffd6                 call esi
// 00403ea6  85c0                 test eax, eax
// 00403ea8  74c6                 je 0x403e70
// 00403eaa  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00403eae  3bc3                 cmp eax, ebx
// 00403eb0  740b                 je 0x403ebd
// 00403eb2  50                   push eax
// 00403eb3  ff1508b09800         call dword ptr [0x98b008]
// 00403eb9  895c240c             mov dword ptr [esp + 0xc], ebx
// 00403ebd  8b4508               mov eax, dword ptr [ebp + 8]
// 00403ec0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00403ec4  50                   push eax
// 00403ec5  895c2414             mov dword ptr [esp + 0x14], ebx
// 00403ec9  e812efffff           call 0x402de0
// 00403ece  8bf0                 mov esi, eax
// 00403ed0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00403ed4  3bc3                 cmp eax, ebx
// 00403ed6  7407                 je 0x403edf
// 00403ed8  50                   push eax
// 00403ed9  ff1508b09800         call dword ptr [0x98b008]
// 00403edf  8bc6                 mov eax, esi
// 00403ee1  5f                   pop edi
// 00403ee2  5e                   pop esi
// 00403ee3  5b                   pop ebx
// 00403ee4  8be5                 mov esp, ebp
// 00403ee6  5d                   pop ebp
// 00403ee7  c20400               ret 4
// 00403eea  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00403eee  3bc3                 cmp eax, ebx
// 00403ef0  7407                 je 0x403ef9
// 00403ef2  50                   push eax
// 00403ef3  ff1508b09800         call dword ptr [0x98b008]
// 00403ef9  8bc7                 mov eax, edi
// 00403efb  5f                   pop edi
// 00403efc  5e                   pop esi
// 00403efd  5b                   pop ebx
// 00403efe  8be5                 mov esp, ebp
// 00403f00  5d                   pop ebp
// 00403f01  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?RecurseDeleteKey@CRegKey@ATL@@QAEJPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
