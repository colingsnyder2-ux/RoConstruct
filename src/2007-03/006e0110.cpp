// from server: 100% by auto
// roc 2007-03 006e0110  unit: seg_006e0000  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e0110
//
// 006e0110  56                   push esi
// 006e0111  8bf1                 mov esi, ecx
// 006e0113  8b4620               mov eax, dword ptr [esi + 0x20]
// 006e0116  50                   push eax
// 006e0117  ff158ced7700         call dword ptr [0x77ed8c]
// 006e011d  85c0                 test eax, eax
// 006e011f  7426                 je 0x6e0147
// 006e0121  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 006e0124  51                   push ecx
// 006e0125  ff15c8ec7700         call dword ptr [0x77ecc8]
// 006e012b  50                   push eax
// 006e012c  e81de5f3ff           call 0x61e64e
// 006e0131  85c0                 test eax, eax
// 006e0133  7412                 je 0x6e0147
// 006e0135  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006e0139  8b16                 mov edx, dword ptr [esi]
// 006e013b  8b9244010000         mov edx, dword ptr [edx + 0x144]
// 006e0141  51                   push ecx
// 006e0142  50                   push eax
// 006e0143  8bce                 mov ecx, esi
// 006e0145  ffd2                 call edx
// 006e0147  33c0                 xor eax, eax
// 006e0149  5e                   pop esi
// 006e014a  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnIdleUpdateCmdUI@CDlgToolBar@CXTPImageEditorDlg@@QAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
