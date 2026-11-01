// from server: 100% by auto
// roc 2009-12 008e5560  unit: CXTCaptionButton  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e5560
//
// 008e5560  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 008e5566  85c9                 test ecx, ecx
// 008e5568  7405                 je 0x8e556f
// 008e556a  e97171f2ff           jmp 0x80c6e0
// 008e556f  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?CleanUpGDI@CXTButton@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
