// from server: 100% by auto
// roc 2009-06 007e7de0  unit: CXTPImageEditorDlg  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e7de0
//
// 007e7de0  8b81140a0000         mov eax, dword ptr [ecx + 0xa14]
// 007e7de6  6a00                 push 0
// 007e7de8  6a00                 push 0
// 007e7dea  50                   push eax
// 007e7deb  ff157cee8900         call dword ptr [0x89ee7c]
// 007e7df1  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnPictureChanged@CXTPImageEditorDlg@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
