// from server: 100% by auto
// roc 2009-06 0077b750  unit: CXTPTabClientWnd  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077b750
//
// 0077b750  83b9b400000000       cmp dword ptr [ecx + 0xb4], 0
// 0077b757  7408                 je 0x77b761
// 0077b759  b801000000           mov eax, 1
// 0077b75e  c20400               ret 4
// 0077b761  e8a2d8f9ff           call 0x719008
// 0077b766  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnNcActivate@CXTPTabClientWnd@@IAEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
