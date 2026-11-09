// from server: 100% by auto
// roc 2010-06 00899870  unit: CXTCaptionButton  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00899870
//
// 00899870  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 00899876  85c9                 test ecx, ecx
// 00899878  7405                 je 0x89987f
// 0089987a  e9516ff2ff           jmp 0x7c07d0
// 0089987f  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTButton.cpp (function ?CleanUpGDI@CXTButton@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButton.cpp
