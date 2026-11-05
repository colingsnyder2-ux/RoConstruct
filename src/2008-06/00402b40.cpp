// from server: 100% by auto
// roc 2008-06 00402b40  unit: VCWorkspace::?$CComObject  size: 324 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402b40
//
// 00402b40  55                   push ebp
// 00402b41  8bec                 mov ebp, esp
// 00402b43  83e4f8               and esp, 0xfffffff8
// 00402b46  81ec1c010000         sub esp, 0x11c
// 00402b4c  8b01                 mov eax, dword ptr [ecx]
// 00402b4e  8b5508               mov edx, dword ptr [ebp + 8]
// 00402b51  53                   push ebx
// 00402b52  56                   push esi
// 00402b53  8b7104               mov esi, dword ptr [ecx + 4]
// 00402b56  57                   push edi
// 00402b57  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00402b5b  8d4c2418             lea ecx, [esp + 0x18]
// 00402b5f  51                   push ecx
// 00402b60  33db                 xor ebx, ebx
// 00402b62  81ce1f000200         or esi, 0x2001f
// 00402b68  56                   push esi
// 00402b69  53                   push ebx
// 00402b6a  52                   push edx
// 00402b6b  50                   push eax
// 00402b6c  895c2420             mov dword ptr [esp + 0x20], ebx
// 00402b70  895c2424             mov dword ptr [esp + 0x24], ebx
// 00402b74  895c242c             mov dword ptr [esp + 0x2c], ebx
// 00402b78  ff1510208000         call dword ptr [0x802010]
// 00402b7e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00402b82  8bf8                 mov edi, eax
// 00402b84  3bfb                 cmp edi, ebx
// 00402b86  7525                 jne 0x402bad
// 00402b88  33c0                 xor eax, eax
// 00402b8a  3bcb                 cmp ecx, ebx
// 00402b8c  7407                 je 0x402b95
// 00402b8e  51                   push ecx
// 00402b8f  ff1508208000         call dword ptr [0x802008]
// 00402b95  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00402b99  81e600030000         and esi, 0x300
// 00402b9f  8bf8                 mov edi, eax
// 00402ba1  894c240c             mov dword ptr [esp + 0xc], ecx
// 00402ba5  89742410             mov dword ptr [esp + 0x10], esi
// 00402ba9  3bc3                 cmp eax, ebx
// 00402bab  7416                 je 0x402bc3
// 00402bad  3bcb                 cmp ecx, ebx
// 00402baf  7407                 je 0x402bb8
// 00402bb1  51                   push ecx
// 00402bb2  ff1508208000         call dword ptr [0x802008]
// 00402bb8  8bc7                 mov eax, edi
// 00402bba  5f                   pop edi
// 00402bbb  5e                   pop esi
// 00402bbc  5b                   pop ebx
// 00402bbd  8be5                 mov esp, ebp
// 00402bbf  5d                   pop ebp
// 00402bc0  c20400               ret 4
// 00402bc3  8b351c208000         mov esi, dword ptr [0x80201c]
// 00402bc9  8d442420             lea eax, [esp + 0x20]
// 00402bcd  50                   push eax
// 00402bce  53                   push ebx
// 00402bcf  53                   push ebx
// 00402bd0  53                   push ebx
// 00402bd1  8d542424             lea edx, [esp + 0x24]
// 00402bd5  52                   push edx
// 00402bd6  8d44243c             lea eax, [esp + 0x3c]
// 00402bda  50                   push eax
// 00402bdb  53                   push ebx
// 00402bdc  51                   push ecx
// 00402bdd  c744243400010000     mov dword ptr [esp + 0x34], 0x100
// 00402be5  ffd6                 call esi
// 00402be7  85c0                 test eax, eax
// 00402be9  753f                 jne 0x402c2a
// 00402beb  eb03                 jmp 0x402bf0
// 00402bed  8d4900               lea ecx, [ecx]
// 00402bf0  8d4c2428             lea ecx, [esp + 0x28]
// 00402bf4  51                   push ecx
// 00402bf5  8d4c2410             lea ecx, [esp + 0x10]
// 00402bf9  e842ffffff           call 0x402b40
// 00402bfe  8bf8                 mov edi, eax
// 00402c00  3bfb                 cmp edi, ebx
// 00402c02  7566                 jne 0x402c6a
// 00402c04  8d542420             lea edx, [esp + 0x20]
// 00402c08  52                   push edx
// 00402c09  8b542410             mov edx, dword ptr [esp + 0x10]
// 00402c0d  53                   push ebx
// 00402c0e  53                   push ebx
// 00402c0f  53                   push ebx
// 00402c10  8d442424             lea eax, [esp + 0x24]
// 00402c14  50                   push eax
// 00402c15  8d4c243c             lea ecx, [esp + 0x3c]
// 00402c19  51                   push ecx
// 00402c1a  53                   push ebx
// 00402c1b  52                   push edx
// 00402c1c  c744243400010000     mov dword ptr [esp + 0x34], 0x100
// 00402c24  ffd6                 call esi
// 00402c26  85c0                 test eax, eax
// 00402c28  74c6                 je 0x402bf0
// 00402c2a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00402c2e  3bc3                 cmp eax, ebx
// 00402c30  740b                 je 0x402c3d
// 00402c32  50                   push eax
// 00402c33  ff1508208000         call dword ptr [0x802008]
// 00402c39  895c240c             mov dword ptr [esp + 0xc], ebx
// 00402c3d  8b4508               mov eax, dword ptr [ebp + 8]
// 00402c40  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00402c44  50                   push eax
// 00402c45  895c2414             mov dword ptr [esp + 0x14], ebx
// 00402c49  e8a2efffff           call 0x401bf0
// 00402c4e  8bf0                 mov esi, eax
// 00402c50  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00402c54  3bc3                 cmp eax, ebx
// 00402c56  7407                 je 0x402c5f
// 00402c58  50                   push eax
// 00402c59  ff1508208000         call dword ptr [0x802008]
// 00402c5f  8bc6                 mov eax, esi
// 00402c61  5f                   pop edi
// 00402c62  5e                   pop esi
// 00402c63  5b                   pop ebx
// 00402c64  8be5                 mov esp, ebp
// 00402c66  5d                   pop ebp
// 00402c67  c20400               ret 4
// 00402c6a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00402c6e  3bc3                 cmp eax, ebx
// 00402c70  7407                 je 0x402c79
// 00402c72  50                   push eax
// 00402c73  ff1508208000         call dword ptr [0x802008]
// 00402c79  8bc7                 mov eax, edi
// 00402c7b  5f                   pop edi
// 00402c7c  5e                   pop esi
// 00402c7d  5b                   pop ebx
// 00402c7e  8be5                 mov esp, ebp
// 00402c80  5d                   pop ebp
// 00402c81  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?RecurseDeleteKey@CRegKey@ATL@@QAEJPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
