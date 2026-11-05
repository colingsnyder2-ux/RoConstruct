// from server: 100% by auto
// roc 2010-06 008996d0  unit: CXTCaptionButton  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008996d0
//
// 008996d0  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 008996d6  85c9                 test ecx, ecx
// 008996d8  7408                 je 0x8996e2
// 008996da  e8c155f2ff           call 0x7beca0
// 008996df  8b00                 mov eax, dword ptr [eax]
// 008996e1  c3                   ret 
// 008996e2  33c0                 xor eax, eax
// 008996e4  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTButton.cpp (function ?GetNormalIcon@CXTButton@@QAEPAUHICON__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButton.cpp
