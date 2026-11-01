// from server: 100% by auto
// roc 2009-12 00854eb0  unit: CXTPTabClientWnd  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00854eb0
//
// 00854eb0  8b8984000000         mov ecx, dword ptr [ecx + 0x84]
// 00854eb6  6a00                 push 0
// 00854eb8  e82f170d00           call 0x9265ec
// 00854ebd  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?MDIGetActive@CXTPTabClientWnd@@IAEPAVCWnd@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
