// from server: 100% by auto
// roc 2009-06 007e7d20  unit: CXTPImageEditorDlg  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e7d20
//
// 007e7d20  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007e7d23  6a00                 push 0
// 007e7d25  6a01                 push 1
// 007e7d27  6a00                 push 0
// 007e7d29  6a00                 push 0
// 007e7d2b  6863030000           push 0x363
// 007e7d30  50                   push eax
// 007e7d31  e824450600           call 0x84c25a
// 007e7d36  33c0                 xor eax, eax
// 007e7d38  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnKickIdle@CXTPImageEditorDlg@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
