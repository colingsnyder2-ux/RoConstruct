// from server: 100% by auto
// roc 2010-06 00875700  unit: CXTPImageEditorPicker  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00875700
//
// 00875700  56                   push esi
// 00875701  8bf1                 mov esi, ecx
// 00875703  8b4620               mov eax, dword ptr [esi + 0x20]
// 00875706  50                   push eax
// 00875707  ff15e8bb9e00         call dword ptr [0x9ebbe8]
// 0087570d  85c0                 test eax, eax
// 0087570f  7426                 je 0x875737
// 00875711  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00875714  51                   push ecx
// 00875715  ff154cba9e00         call dword ptr [0x9eba4c]
// 0087571b  50                   push eax
// 0087571c  e84925f3ff           call 0x7a7c6a
// 00875721  85c0                 test eax, eax
// 00875723  7412                 je 0x875737
// 00875725  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00875729  8b16                 mov edx, dword ptr [esi]
// 0087572b  8b924c010000         mov edx, dword ptr [edx + 0x14c]
// 00875731  51                   push ecx
// 00875732  50                   push eax
// 00875733  8bce                 mov ecx, esi
// 00875735  ffd2                 call edx
// 00875737  33c0                 xor eax, eax
// 00875739  5e                   pop esi
// 0087573a  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPImageEditor.cpp (function ?OnIdleUpdateCmdUI@CDlgToolBar@CXTPImageEditorDlg@@QAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPImageEditor.cpp
