// from server: 100% by auto
// roc 2012-06 004a63b0  unit: CSettingsDialog  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a63b0
//
// 004a63b0  56                   push esi
// 004a63b1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004a63b5  57                   push edi
// 004a63b6  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004a63ba  8b07                 mov eax, dword ptr [edi]
// 004a63bc  8d542414             lea edx, [esp + 0x14]
// 004a63c0  52                   push edx
// 004a63c1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a63c5  56                   push esi
// 004a63c6  8944241c             mov dword ptr [esp + 0x1c], eax
// 004a63ca  8d442418             lea eax, [esp + 0x18]
// 004a63ce  50                   push eax
// 004a63cf  6a00                 push 0
// 004a63d1  c70700000000         mov dword ptr [edi], 0
// 004a63d7  8b01                 mov eax, dword ptr [ecx]
// 004a63d9  52                   push edx
// 004a63da  50                   push eax
// 004a63db  ff151c20b200         call dword ptr [0xb2201c]
// 004a63e1  85c0                 test eax, eax
// 004a63e3  7532                 jne 0x4a6417
// 004a63e5  8b442410             mov eax, dword ptr [esp + 0x10]
// 004a63e9  83f801               cmp eax, 1
// 004a63ec  7405                 je 0x4a63f3
// 004a63ee  83f802               cmp eax, 2
// 004a63f1  7513                 jne 0x4a6406
// 004a63f3  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a63f7  85f6                 test esi, esi
// 004a63f9  7418                 je 0x4a6413
// 004a63fb  85c0                 test eax, eax
// 004a63fd  7411                 je 0x4a6410
// 004a63ff  807c30ff00           cmp byte ptr [eax + esi - 1], 0
// 004a6404  740d                 je 0x4a6413
// 004a6406  5f                   pop edi
// 004a6407  b80d000000           mov eax, 0xd
// 004a640c  5e                   pop esi
// 004a640d  c20c00               ret 0xc
// 004a6410  c60600               mov byte ptr [esi], 0
// 004a6413  8907                 mov dword ptr [edi], eax
// 004a6415  33c0                 xor eax, eax
// 004a6417  5f                   pop edi
// 004a6418  5e                   pop esi
// 004a6419  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?QueryStringValue@CRegKey@ATL@@QAEJPBDPADPAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
