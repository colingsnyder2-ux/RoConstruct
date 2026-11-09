// from server: 100% by auto
// roc 2010-06 00809080  unit: CXTPTabClientWnd  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00809080
//
// 00809080  83b9b000000000       cmp dword ptr [ecx + 0xb0], 0
// 00809087  7511                 jne 0x80909a
// 00809089  83b9b400000000       cmp dword ptr [ecx + 0xb4], 0
// 00809090  7508                 jne 0x80909a
// 00809092  e8d9eef9ff           call 0x7a7f70
// 00809097  c20400               ret 4
// 0080909a  b801000000           mov eax, 1
// 0080909f  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnEraseBkgnd@CXTPTabClientWnd@@IAEHPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
