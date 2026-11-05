// from server: 100% by auto
// roc 2012-06 00404f70  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 324 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404f70
//
// 00404f70  55                   push ebp
// 00404f71  8bec                 mov ebp, esp
// 00404f73  83e4f8               and esp, 0xfffffff8
// 00404f76  81ec1c010000         sub esp, 0x11c
// 00404f7c  8b01                 mov eax, dword ptr [ecx]
// 00404f7e  8b5508               mov edx, dword ptr [ebp + 8]
// 00404f81  53                   push ebx
// 00404f82  56                   push esi
// 00404f83  8b7104               mov esi, dword ptr [ecx + 4]
// 00404f86  57                   push edi
// 00404f87  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00404f8b  8d4c2418             lea ecx, [esp + 0x18]
// 00404f8f  51                   push ecx
// 00404f90  33db                 xor ebx, ebx
// 00404f92  81ce1f000200         or esi, 0x2001f
// 00404f98  56                   push esi
// 00404f99  53                   push ebx
// 00404f9a  52                   push edx
// 00404f9b  50                   push eax
// 00404f9c  895c2420             mov dword ptr [esp + 0x20], ebx
// 00404fa0  895c2424             mov dword ptr [esp + 0x24], ebx
// 00404fa4  895c242c             mov dword ptr [esp + 0x2c], ebx
// 00404fa8  ff150c20b200         call dword ptr [0xb2200c]
// 00404fae  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00404fb2  8bf8                 mov edi, eax
// 00404fb4  3bfb                 cmp edi, ebx
// 00404fb6  7525                 jne 0x404fdd
// 00404fb8  33c0                 xor eax, eax
// 00404fba  3bcb                 cmp ecx, ebx
// 00404fbc  7407                 je 0x404fc5
// 00404fbe  51                   push ecx
// 00404fbf  ff150420b200         call dword ptr [0xb22004]
// 00404fc5  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00404fc9  81e600030000         and esi, 0x300
// 00404fcf  8bf8                 mov edi, eax
// 00404fd1  894c240c             mov dword ptr [esp + 0xc], ecx
// 00404fd5  89742410             mov dword ptr [esp + 0x10], esi
// 00404fd9  3bc3                 cmp eax, ebx
// 00404fdb  7416                 je 0x404ff3
// 00404fdd  3bcb                 cmp ecx, ebx
// 00404fdf  7407                 je 0x404fe8
// 00404fe1  51                   push ecx
// 00404fe2  ff150420b200         call dword ptr [0xb22004]
// 00404fe8  8bc7                 mov eax, edi
// 00404fea  5f                   pop edi
// 00404feb  5e                   pop esi
// 00404fec  5b                   pop ebx
// 00404fed  8be5                 mov esp, ebp
// 00404fef  5d                   pop ebp
// 00404ff0  c20400               ret 4
// 00404ff3  8b351820b200         mov esi, dword ptr [0xb22018]
// 00404ff9  8d442420             lea eax, [esp + 0x20]
// 00404ffd  50                   push eax
// 00404ffe  53                   push ebx
// 00404fff  53                   push ebx
// 00405000  53                   push ebx
// 00405001  8d542424             lea edx, [esp + 0x24]
// 00405005  52                   push edx
// 00405006  8d44243c             lea eax, [esp + 0x3c]
// 0040500a  50                   push eax
// 0040500b  53                   push ebx
// 0040500c  51                   push ecx
// 0040500d  c744243400010000     mov dword ptr [esp + 0x34], 0x100
// 00405015  ffd6                 call esi
// 00405017  85c0                 test eax, eax
// 00405019  753f                 jne 0x40505a
// 0040501b  eb03                 jmp 0x405020
// 0040501d  8d4900               lea ecx, [ecx]
// 00405020  8d4c2428             lea ecx, [esp + 0x28]
// 00405024  51                   push ecx
// 00405025  8d4c2410             lea ecx, [esp + 0x10]
// 00405029  e842ffffff           call 0x404f70
// 0040502e  8bf8                 mov edi, eax
// 00405030  3bfb                 cmp edi, ebx
// 00405032  7566                 jne 0x40509a
// 00405034  8d542420             lea edx, [esp + 0x20]
// 00405038  52                   push edx
// 00405039  8b542410             mov edx, dword ptr [esp + 0x10]
// 0040503d  53                   push ebx
// 0040503e  53                   push ebx
// 0040503f  53                   push ebx
// 00405040  8d442424             lea eax, [esp + 0x24]
// 00405044  50                   push eax
// 00405045  8d4c243c             lea ecx, [esp + 0x3c]
// 00405049  51                   push ecx
// 0040504a  53                   push ebx
// 0040504b  52                   push edx
// 0040504c  c744243400010000     mov dword ptr [esp + 0x34], 0x100
// 00405054  ffd6                 call esi
// 00405056  85c0                 test eax, eax
// 00405058  74c6                 je 0x405020
// 0040505a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040505e  3bc3                 cmp eax, ebx
// 00405060  740b                 je 0x40506d
// 00405062  50                   push eax
// 00405063  ff150420b200         call dword ptr [0xb22004]
// 00405069  895c240c             mov dword ptr [esp + 0xc], ebx
// 0040506d  8b4508               mov eax, dword ptr [ebp + 8]
// 00405070  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00405074  50                   push eax
// 00405075  895c2414             mov dword ptr [esp + 0x14], ebx
// 00405079  e8f2f2ffff           call 0x404370
// 0040507e  8bf0                 mov esi, eax
// 00405080  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00405084  3bc3                 cmp eax, ebx
// 00405086  7407                 je 0x40508f
// 00405088  50                   push eax
// 00405089  ff150420b200         call dword ptr [0xb22004]
// 0040508f  8bc6                 mov eax, esi
// 00405091  5f                   pop edi
// 00405092  5e                   pop esi
// 00405093  5b                   pop ebx
// 00405094  8be5                 mov esp, ebp
// 00405096  5d                   pop ebp
// 00405097  c20400               ret 4
// 0040509a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040509e  3bc3                 cmp eax, ebx
// 004050a0  7407                 je 0x4050a9
// 004050a2  50                   push eax
// 004050a3  ff150420b200         call dword ptr [0xb22004]
// 004050a9  8bc7                 mov eax, edi
// 004050ab  5f                   pop edi
// 004050ac  5e                   pop esi
// 004050ad  5b                   pop ebx
// 004050ae  8be5                 mov esp, ebp
// 004050b0  5d                   pop ebp
// 004050b1  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?RecurseDeleteKey@CRegKey@ATL@@QAEJPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
