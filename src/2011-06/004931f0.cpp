// from server: 100% by auto
// roc 2011-06 004931f0  unit: CSettingsDialog  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004931f0
//
// 004931f0  56                   push esi
// 004931f1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004931f5  57                   push edi
// 004931f6  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004931fa  8b07                 mov eax, dword ptr [edi]
// 004931fc  8d542414             lea edx, [esp + 0x14]
// 00493200  52                   push edx
// 00493201  8b542410             mov edx, dword ptr [esp + 0x10]
// 00493205  56                   push esi
// 00493206  8944241c             mov dword ptr [esp + 0x1c], eax
// 0049320a  8d442418             lea eax, [esp + 0x18]
// 0049320e  50                   push eax
// 0049320f  6a00                 push 0
// 00493211  c70700000000         mov dword ptr [edi], 0
// 00493217  8b01                 mov eax, dword ptr [ecx]
// 00493219  52                   push edx
// 0049321a  50                   push eax
// 0049321b  ff153400a400         call dword ptr [0xa40034]
// 00493221  85c0                 test eax, eax
// 00493223  7532                 jne 0x493257
// 00493225  8b442410             mov eax, dword ptr [esp + 0x10]
// 00493229  83f801               cmp eax, 1
// 0049322c  7405                 je 0x493233
// 0049322e  83f802               cmp eax, 2
// 00493231  7513                 jne 0x493246
// 00493233  8b442414             mov eax, dword ptr [esp + 0x14]
// 00493237  85f6                 test esi, esi
// 00493239  7418                 je 0x493253
// 0049323b  85c0                 test eax, eax
// 0049323d  7411                 je 0x493250
// 0049323f  807c30ff00           cmp byte ptr [eax + esi - 1], 0
// 00493244  740d                 je 0x493253
// 00493246  5f                   pop edi
// 00493247  b80d000000           mov eax, 0xd
// 0049324c  5e                   pop esi
// 0049324d  c20c00               ret 0xc
// 00493250  c60600               mov byte ptr [esi], 0
// 00493253  8907                 mov dword ptr [edi], eax
// 00493255  33c0                 xor eax, eax
// 00493257  5f                   pop edi
// 00493258  5e                   pop esi
// 00493259  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?QueryStringValue@CRegKey@ATL@@QAEJPBDPADPAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
