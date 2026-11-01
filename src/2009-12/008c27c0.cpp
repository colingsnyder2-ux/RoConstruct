// from server: 100% by auto
// roc 2009-12 008c27c0  unit: CXTPImageEditorDlg  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c27c0
//
// 008c27c0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008c27c3  6a00                 push 0
// 008c27c5  6a01                 push 1
// 008c27c7  6a00                 push 0
// 008c27c9  6a00                 push 0
// 008c27cb  6863030000           push 0x363
// 008c27d0  50                   push eax
// 008c27d1  e8f03f0600           call 0x9267c6
// 008c27d6  33c0                 xor eax, eax
// 008c27d8  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnKickIdle@CXTPImageEditorDlg@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
