// from server: 100% by auto
// roc 2009-06 00467fc0  unit: CSettingsDialog  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00467fc0
//
// 00467fc0  56                   push esi
// 00467fc1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00467fc5  57                   push edi
// 00467fc6  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00467fca  8b07                 mov eax, dword ptr [edi]
// 00467fcc  8d542414             lea edx, [esp + 0x14]
// 00467fd0  52                   push edx
// 00467fd1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00467fd5  56                   push esi
// 00467fd6  8944241c             mov dword ptr [esp + 0x1c], eax
// 00467fda  8d442418             lea eax, [esp + 0x18]
// 00467fde  50                   push eax
// 00467fdf  6a00                 push 0
// 00467fe1  c70700000000         mov dword ptr [edi], 0
// 00467fe7  8b01                 mov eax, dword ptr [ecx]
// 00467fe9  52                   push edx
// 00467fea  50                   push eax
// 00467feb  ff1520e08900         call dword ptr [0x89e020]
// 00467ff1  85c0                 test eax, eax
// 00467ff3  7532                 jne 0x468027
// 00467ff5  8b442410             mov eax, dword ptr [esp + 0x10]
// 00467ff9  83f801               cmp eax, 1
// 00467ffc  7405                 je 0x468003
// 00467ffe  83f802               cmp eax, 2
// 00468001  7513                 jne 0x468016
// 00468003  8b442414             mov eax, dword ptr [esp + 0x14]
// 00468007  85f6                 test esi, esi
// 00468009  7418                 je 0x468023
// 0046800b  85c0                 test eax, eax
// 0046800d  7411                 je 0x468020
// 0046800f  807c30ff00           cmp byte ptr [eax + esi - 1], 0
// 00468014  740d                 je 0x468023
// 00468016  5f                   pop edi
// 00468017  b80d000000           mov eax, 0xd
// 0046801c  5e                   pop esi
// 0046801d  c20c00               ret 0xc
// 00468020  c60600               mov byte ptr [esi], 0
// 00468023  8907                 mov dword ptr [edi], eax
// 00468025  33c0                 xor eax, eax
// 00468027  5f                   pop edi
// 00468028  5e                   pop esi
// 00468029  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?QueryStringValue@CRegKey@ATL@@QAEJPBDPADPAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
