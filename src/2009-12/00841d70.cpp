// from server: 100% by auto
// roc 2009-12 00841d70  unit: CXTPPopupBar  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00841d70
//
// 00841d70  e8fd460e00           call 0x926472
// 00841d75  a900010000           test eax, 0x100
// 00841d7a  740f                 je 0x841d8b
// 00841d7c  f644240440           test byte ptr [esp + 4], 0x40
// 00841d81  7408                 je 0x841d8b
// 00841d83  b801000000           mov eax, 1
// 00841d88  c20800               ret 8
// 00841d8b  33c0                 xor eax, eax
// 00841d8d  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?OnFloatStatus@CXTPPopupBar@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
