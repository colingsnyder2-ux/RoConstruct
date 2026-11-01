// from server: 100% by auto
// roc 2009-12 00855000  unit: CXTPTabClientWnd  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00855000
//
// 00855000  83b9b000000000       cmp dword ptr [ecx + 0xb0], 0
// 00855007  7511                 jne 0x85501a
// 00855009  83b9b400000000       cmp dword ptr [ecx + 0xb4], 0
// 00855010  7508                 jne 0x85501a
// 00855012  e819eef9ff           call 0x7f3e30
// 00855017  c20400               ret 4
// 0085501a  b801000000           mov eax, 1
// 0085501f  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnEraseBkgnd@CXTPTabClientWnd@@IAEHPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
