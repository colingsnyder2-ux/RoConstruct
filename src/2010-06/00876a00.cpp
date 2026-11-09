// from server: 100% by auto
// roc 2010-06 00876a00  unit: CXTPImageEditorDlg  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00876a00
//
// 00876a00  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00876a03  6a00                 push 0
// 00876a05  6a01                 push 1
// 00876a07  6a00                 push 0
// 00876a09  6a00                 push 0
// 00876a0b  6863030000           push 0x363
// 00876a10  50                   push eax
// 00876a11  e8ec661000           call 0x97d102
// 00876a16  33c0                 xor eax, eax
// 00876a18  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnKickIdle@CXTPImageEditorDlg@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
