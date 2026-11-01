// from server: 100% by auto
// roc 2009-06 0077a130  unit: CXTPTabClientWnd  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077a130
//
// 0077a130  8b8984000000         mov ecx, dword ptr [ecx + 0x84]
// 0077a136  6a00                 push 0
// 0077a138  e8351e0d00           call 0x84bf72
// 0077a13d  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?MDIGetActive@CXTPTabClientWnd@@IAEPAVCWnd@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
