// from server: 100% by auto
// roc 2009-12 00470de0  unit: CSettingsDialog  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00470de0
//
// 00470de0  56                   push esi
// 00470de1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00470de5  57                   push edi
// 00470de6  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00470dea  8b07                 mov eax, dword ptr [edi]
// 00470dec  8d542414             lea edx, [esp + 0x14]
// 00470df0  52                   push edx
// 00470df1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00470df5  56                   push esi
// 00470df6  8944241c             mov dword ptr [esp + 0x1c], eax
// 00470dfa  8d442418             lea eax, [esp + 0x18]
// 00470dfe  50                   push eax
// 00470dff  6a00                 push 0
// 00470e01  c70700000000         mov dword ptr [edi], 0
// 00470e07  8b01                 mov eax, dword ptr [ecx]
// 00470e09  52                   push edx
// 00470e0a  50                   push eax
// 00470e0b  ff1520b09800         call dword ptr [0x98b020]
// 00470e11  85c0                 test eax, eax
// 00470e13  7532                 jne 0x470e47
// 00470e15  8b442410             mov eax, dword ptr [esp + 0x10]
// 00470e19  83f801               cmp eax, 1
// 00470e1c  7405                 je 0x470e23
// 00470e1e  83f802               cmp eax, 2
// 00470e21  7513                 jne 0x470e36
// 00470e23  8b442414             mov eax, dword ptr [esp + 0x14]
// 00470e27  85f6                 test esi, esi
// 00470e29  7418                 je 0x470e43
// 00470e2b  85c0                 test eax, eax
// 00470e2d  7411                 je 0x470e40
// 00470e2f  807c30ff00           cmp byte ptr [eax + esi - 1], 0
// 00470e34  740d                 je 0x470e43
// 00470e36  5f                   pop edi
// 00470e37  b80d000000           mov eax, 0xd
// 00470e3c  5e                   pop esi
// 00470e3d  c20c00               ret 0xc
// 00470e40  c60600               mov byte ptr [esi], 0
// 00470e43  8907                 mov dword ptr [edi], eax
// 00470e45  33c0                 xor eax, eax
// 00470e47  5f                   pop edi
// 00470e48  5e                   pop esi
// 00470e49  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?QueryStringValue@CRegKey@ATL@@QAEJPBDPADPAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
