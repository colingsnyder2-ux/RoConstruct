// from server: 100% by auto
// roc 2009-12 008c2880  unit: CXTPImageEditorDlg  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c2880
//
// 008c2880  8b81140a0000         mov eax, dword ptr [ecx + 0xa14]
// 008c2886  6a00                 push 0
// 008c2888  6a00                 push 0
// 008c288a  50                   push eax
// 008c288b  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008c2891  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnPictureChanged@CXTPImageEditorDlg@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
