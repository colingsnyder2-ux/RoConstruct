// from server: 100% by auto
// roc 2007-08 0068a700  unit: CXTPTabClientWnd::CSingleWorkspace  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0068a700
//
// 0068a700  8b818c000000         mov eax, dword ptr [ecx + 0x8c]
// 0068a706  83786400             cmp dword ptr [eax + 0x64], 0
// 0068a70a  7511                 jne 0x68a71d
// 0068a70c  8b542404             mov edx, dword ptr [esp + 4]
// 0068a710  8b41c8               mov eax, dword ptr [ecx - 0x38]
// 0068a713  6a00                 push 0
// 0068a715  52                   push edx
// 0068a716  50                   push eax
// 0068a717  ff15dcec7700         call dword ptr [0x77ecdc]
// 0068a71d  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?RedrawControl@CSingleWorkspace@CXTPTabClientWnd@@UAEXPBUtagRECT@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
