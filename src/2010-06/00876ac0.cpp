// from server: 100% by auto
// roc 2010-06 00876ac0  unit: CXTPImageEditorDlg  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00876ac0
//
// 00876ac0  8b81140a0000         mov eax, dword ptr [ecx + 0xa14]
// 00876ac6  6a00                 push 0
// 00876ac8  6a00                 push 0
// 00876aca  50                   push eax
// 00876acb  ff1578ba9e00         call dword ptr [0x9eba78]
// 00876ad1  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnPictureChanged@CXTPImageEditorDlg@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
