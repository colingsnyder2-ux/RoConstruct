// from server: 100% by auto
// roc 2010-06 00403e20  unit: VCApp::?$CComObject  size: 324 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00403e20
//
// 00403e20  55                   push ebp
// 00403e21  8bec                 mov ebp, esp
// 00403e23  83e4f8               and esp, 0xfffffff8
// 00403e26  81ec1c010000         sub esp, 0x11c
// 00403e2c  8b01                 mov eax, dword ptr [ecx]
// 00403e2e  8b5508               mov edx, dword ptr [ebp + 8]
// 00403e31  53                   push ebx
// 00403e32  56                   push esi
// 00403e33  8b7104               mov esi, dword ptr [ecx + 4]
// 00403e36  57                   push edi
// 00403e37  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00403e3b  8d4c2418             lea ecx, [esp + 0x18]
// 00403e3f  51                   push ecx
// 00403e40  33db                 xor ebx, ebx
// 00403e42  81ce1f000200         or esi, 0x2001f
// 00403e48  56                   push esi
// 00403e49  53                   push ebx
// 00403e4a  52                   push edx
// 00403e4b  50                   push eax
// 00403e4c  895c2420             mov dword ptr [esp + 0x20], ebx
// 00403e50  895c2424             mov dword ptr [esp + 0x24], ebx
// 00403e54  895c242c             mov dword ptr [esp + 0x2c], ebx
// 00403e58  ff1518a09e00         call dword ptr [0x9ea018]
// 00403e5e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00403e62  8bf8                 mov edi, eax
// 00403e64  3bfb                 cmp edi, ebx
// 00403e66  7525                 jne 0x403e8d
// 00403e68  33c0                 xor eax, eax
// 00403e6a  3bcb                 cmp ecx, ebx
// 00403e6c  7407                 je 0x403e75
// 00403e6e  51                   push ecx
// 00403e6f  ff1510a09e00         call dword ptr [0x9ea010]
// 00403e75  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00403e79  81e600030000         and esi, 0x300
// 00403e7f  8bf8                 mov edi, eax
// 00403e81  894c240c             mov dword ptr [esp + 0xc], ecx
// 00403e85  89742410             mov dword ptr [esp + 0x10], esi
// 00403e89  3bc3                 cmp eax, ebx
// 00403e8b  7416                 je 0x403ea3
// 00403e8d  3bcb                 cmp ecx, ebx
// 00403e8f  7407                 je 0x403e98
// 00403e91  51                   push ecx
// 00403e92  ff1510a09e00         call dword ptr [0x9ea010]
// 00403e98  8bc7                 mov eax, edi
// 00403e9a  5f                   pop edi
// 00403e9b  5e                   pop esi
// 00403e9c  5b                   pop ebx
// 00403e9d  8be5                 mov esp, ebp
// 00403e9f  5d                   pop ebp
// 00403ea0  c20400               ret 4
// 00403ea3  8b3524a09e00         mov esi, dword ptr [0x9ea024]
// 00403ea9  8d442420             lea eax, [esp + 0x20]
// 00403ead  50                   push eax
// 00403eae  53                   push ebx
// 00403eaf  53                   push ebx
// 00403eb0  53                   push ebx
// 00403eb1  8d542424             lea edx, [esp + 0x24]
// 00403eb5  52                   push edx
// 00403eb6  8d44243c             lea eax, [esp + 0x3c]
// 00403eba  50                   push eax
// 00403ebb  53                   push ebx
// 00403ebc  51                   push ecx
// 00403ebd  c744243400010000     mov dword ptr [esp + 0x34], 0x100
// 00403ec5  ffd6                 call esi
// 00403ec7  85c0                 test eax, eax
// 00403ec9  753f                 jne 0x403f0a
// 00403ecb  eb03                 jmp 0x403ed0
// 00403ecd  8d4900               lea ecx, [ecx]
// 00403ed0  8d4c2428             lea ecx, [esp + 0x28]
// 00403ed4  51                   push ecx
// 00403ed5  8d4c2410             lea ecx, [esp + 0x10]
// 00403ed9  e842ffffff           call 0x403e20
// 00403ede  8bf8                 mov edi, eax
// 00403ee0  3bfb                 cmp edi, ebx
// 00403ee2  7566                 jne 0x403f4a
// 00403ee4  8d542420             lea edx, [esp + 0x20]
// 00403ee8  52                   push edx
// 00403ee9  8b542410             mov edx, dword ptr [esp + 0x10]
// 00403eed  53                   push ebx
// 00403eee  53                   push ebx
// 00403eef  53                   push ebx
// 00403ef0  8d442424             lea eax, [esp + 0x24]
// 00403ef4  50                   push eax
// 00403ef5  8d4c243c             lea ecx, [esp + 0x3c]
// 00403ef9  51                   push ecx
// 00403efa  53                   push ebx
// 00403efb  52                   push edx
// 00403efc  c744243400010000     mov dword ptr [esp + 0x34], 0x100
// 00403f04  ffd6                 call esi
// 00403f06  85c0                 test eax, eax
// 00403f08  74c6                 je 0x403ed0
// 00403f0a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00403f0e  3bc3                 cmp eax, ebx
// 00403f10  740b                 je 0x403f1d
// 00403f12  50                   push eax
// 00403f13  ff1510a09e00         call dword ptr [0x9ea010]
// 00403f19  895c240c             mov dword ptr [esp + 0xc], ebx
// 00403f1d  8b4508               mov eax, dword ptr [ebp + 8]
// 00403f20  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00403f24  50                   push eax
// 00403f25  895c2414             mov dword ptr [esp + 0x14], ebx
// 00403f29  e802efffff           call 0x402e30
// 00403f2e  8bf0                 mov esi, eax
// 00403f30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00403f34  3bc3                 cmp eax, ebx
// 00403f36  7407                 je 0x403f3f
// 00403f38  50                   push eax
// 00403f39  ff1510a09e00         call dword ptr [0x9ea010]
// 00403f3f  8bc6                 mov eax, esi
// 00403f41  5f                   pop edi
// 00403f42  5e                   pop esi
// 00403f43  5b                   pop ebx
// 00403f44  8be5                 mov esp, ebp
// 00403f46  5d                   pop ebp
// 00403f47  c20400               ret 4
// 00403f4a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00403f4e  3bc3                 cmp eax, ebx
// 00403f50  7407                 je 0x403f59
// 00403f52  50                   push eax
// 00403f53  ff1510a09e00         call dword ptr [0x9ea010]
// 00403f59  8bc7                 mov eax, edi
// 00403f5b  5f                   pop edi
// 00403f5c  5e                   pop esi
// 00403f5d  5b                   pop ebx
// 00403f5e  8be5                 mov esp, ebp
// 00403f60  5d                   pop ebp
// 00403f61  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?RecurseDeleteKey@CRegKey@ATL@@QAEJPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
