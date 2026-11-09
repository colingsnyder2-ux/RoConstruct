// from server: 100% by auto
// roc 2010-06 0080a6e0  unit: CXTPTabClientWnd  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080a6e0
//
// 0080a6e0  83b9b400000000       cmp dword ptr [ecx + 0xb4], 0
// 0080a6e7  7408                 je 0x80a6f1
// 0080a6e9  b801000000           mov eax, 1
// 0080a6ee  c20400               ret 4
// 0080a6f1  e87ad8f9ff           call 0x7a7f70
// 0080a6f6  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnNcActivate@CXTPTabClientWnd@@IAEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
