// from server: 100% by auto
// roc 2007-08 0068a4c0  unit: CXTPTabClientWnd::CWorkspace  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0068a4c0
//
// 0068a4c0  8b818c000000         mov eax, dword ptr [ecx + 0x8c]
// 0068a4c6  83786400             cmp dword ptr [eax + 0x64], 0
// 0068a4ca  7511                 jne 0x68a4dd
// 0068a4cc  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0068a4d0  8b5020               mov edx, dword ptr [eax + 0x20]
// 0068a4d3  6a00                 push 0
// 0068a4d5  51                   push ecx
// 0068a4d6  52                   push edx
// 0068a4d7  ff15dcec7700         call dword ptr [0x77ecdc]
// 0068a4dd  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?RedrawControl@CWorkspace@CXTPTabClientWnd@@MAEXPBUtagRECT@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
