// from server: 100% by auto
// roc 2009-06 00766f90  unit: CXTPPopupBar  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00766f90
//
// 00766f90  e8474f0e00           call 0x84bedc
// 00766f95  a900010000           test eax, 0x100
// 00766f9a  740f                 je 0x766fab
// 00766f9c  f644240440           test byte ptr [esp + 4], 0x40
// 00766fa1  7408                 je 0x766fab
// 00766fa3  b801000000           mov eax, 1
// 00766fa8  c20800               ret 8
// 00766fab  33c0                 xor eax, eax
// 00766fad  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?OnFloatStatus@CXTPPopupBar@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
