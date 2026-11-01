// from server: 100% by auto
// roc 2007-03 006635b0  unit: seg_00660000  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006635b0
//
// 006635b0  e80f760d00           call 0x73abc4
// 006635b5  a900010000           test eax, 0x100
// 006635ba  740f                 je 0x6635cb
// 006635bc  f644240440           test byte ptr [esp + 4], 0x40
// 006635c1  7408                 je 0x6635cb
// 006635c3  b801000000           mov eax, 1
// 006635c8  c20800               ret 8
// 006635cb  33c0                 xor eax, eax
// 006635cd  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?OnFloatStatus@CXTPPopupBar@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
