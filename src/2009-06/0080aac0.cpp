// from server: 100% by auto
// roc 2009-06 0080aac0  unit: CXTCaptionButton  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080aac0
//
// 0080aac0  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 0080aac6  85c9                 test ecx, ecx
// 0080aac8  7405                 je 0x80aacf
// 0080aaca  e961abf2ff           jmp 0x735630
// 0080aacf  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?CleanUpGDI@CXTButton@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
