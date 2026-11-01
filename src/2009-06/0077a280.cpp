// from server: 100% by auto
// roc 2009-06 0077a280  unit: CXTPTabClientWnd  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077a280
//
// 0077a280  83b9b000000000       cmp dword ptr [ecx + 0xb0], 0
// 0077a287  7511                 jne 0x77a29a
// 0077a289  83b9b400000000       cmp dword ptr [ecx + 0xb4], 0
// 0077a290  7508                 jne 0x77a29a
// 0077a292  e871edf9ff           call 0x719008
// 0077a297  c20400               ret 4
// 0077a29a  b801000000           mov eax, 1
// 0077a29f  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnEraseBkgnd@CXTPTabClientWnd@@IAEHPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
