// from server: 100% by auto
// roc 2010-06 004767b0  unit: CSettingsDialog  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004767b0
//
// 004767b0  56                   push esi
// 004767b1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004767b5  57                   push edi
// 004767b6  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004767ba  8b07                 mov eax, dword ptr [edi]
// 004767bc  8d542414             lea edx, [esp + 0x14]
// 004767c0  52                   push edx
// 004767c1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004767c5  56                   push esi
// 004767c6  8944241c             mov dword ptr [esp + 0x1c], eax
// 004767ca  8d442418             lea eax, [esp + 0x18]
// 004767ce  50                   push eax
// 004767cf  6a00                 push 0
// 004767d1  c70700000000         mov dword ptr [edi], 0
// 004767d7  8b01                 mov eax, dword ptr [ecx]
// 004767d9  52                   push edx
// 004767da  50                   push eax
// 004767db  ff1528a09e00         call dword ptr [0x9ea028]
// 004767e1  85c0                 test eax, eax
// 004767e3  7532                 jne 0x476817
// 004767e5  8b442410             mov eax, dword ptr [esp + 0x10]
// 004767e9  83f801               cmp eax, 1
// 004767ec  7405                 je 0x4767f3
// 004767ee  83f802               cmp eax, 2
// 004767f1  7513                 jne 0x476806
// 004767f3  8b442414             mov eax, dword ptr [esp + 0x14]
// 004767f7  85f6                 test esi, esi
// 004767f9  7418                 je 0x476813
// 004767fb  85c0                 test eax, eax
// 004767fd  7411                 je 0x476810
// 004767ff  807c30ff00           cmp byte ptr [eax + esi - 1], 0
// 00476804  740d                 je 0x476813
// 00476806  5f                   pop edi
// 00476807  b80d000000           mov eax, 0xd
// 0047680c  5e                   pop esi
// 0047680d  c20c00               ret 0xc
// 00476810  c60600               mov byte ptr [esi], 0
// 00476813  8907                 mov dword ptr [edi], eax
// 00476815  33c0                 xor eax, eax
// 00476817  5f                   pop edi
// 00476818  5e                   pop esi
// 00476819  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?QueryStringValue@CRegKey@ATL@@QAEJPBDPADPAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
