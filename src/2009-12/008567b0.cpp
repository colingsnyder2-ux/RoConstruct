// from server: 100% by auto
// roc 2009-12 008567b0  unit: CXTPTabClientWnd  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008567b0
//
// 008567b0  83b9b400000000       cmp dword ptr [ecx + 0xb4], 0
// 008567b7  7408                 je 0x8567c1
// 008567b9  b801000000           mov eax, 1
// 008567be  c20400               ret 4
// 008567c1  e86ad6f9ff           call 0x7f3e30
// 008567c6  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnNcActivate@CXTPTabClientWnd@@IAEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
