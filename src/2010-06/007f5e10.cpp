// from server: 100% by auto
// roc 2010-06 007f5e10  unit: CXTPPopupBar  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f5e10
//
// 007f5e10  e8c96f1800           call 0x97cdde
// 007f5e15  a900010000           test eax, 0x100
// 007f5e1a  740f                 je 0x7f5e2b
// 007f5e1c  f644240440           test byte ptr [esp + 4], 0x40
// 007f5e21  7408                 je 0x7f5e2b
// 007f5e23  b801000000           mov eax, 1
// 007f5e28  c20800               ret 8
// 007f5e2b  33c0                 xor eax, eax
// 007f5e2d  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?OnFloatStatus@CXTPPopupBar@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPopupBar.cpp
