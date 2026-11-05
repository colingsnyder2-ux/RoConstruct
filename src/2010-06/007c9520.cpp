// from server: 100% by auto
// roc 2010-06 007c9520  unit: MyXTPCommandBars  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c9520
//
// 007c9520  e80bf6ffff           call 0x7c8b30
// 007c9525  85c0                 test eax, eax
// 007c9527  7407                 je 0x7c9530
// 007c9529  8bc8                 mov ecx, eax
// 007c952b  e900d80700           jmp 0x846d30
// 007c9530  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?OnToolBarRemoved@CXTPCommandBars@@MAEXPAVCXTPToolBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
