// from server: 100% by auto
// roc 2010-06 00808f30  unit: CXTPTabClientWnd  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00808f30
//
// 00808f30  8b8984000000         mov ecx, dword ptr [ecx + 0x84]
// 00808f36  6a00                 push 0
// 00808f38  e8eb3f1700           call 0x97cf28
// 00808f3d  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?MDIGetActive@CXTPTabClientWnd@@IAEPAVCWnd@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
