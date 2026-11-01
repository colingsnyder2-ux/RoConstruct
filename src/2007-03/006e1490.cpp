// from server: 100% by auto
// roc 2007-03 006e1490  unit: seg_006e0000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e1490
//
// 006e1490  8b4120               mov eax, dword ptr [ecx + 0x20]
// 006e1493  6a00                 push 0
// 006e1495  6a01                 push 1
// 006e1497  6a00                 push 0
// 006e1499  6a00                 push 0
// 006e149b  6863030000           push 0x363
// 006e14a0  50                   push eax
// 006e14a1  e87c990500           call 0x73ae22
// 006e14a6  33c0                 xor eax, eax
// 006e14a8  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnKickIdle@CXTPImageEditorDlg@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
