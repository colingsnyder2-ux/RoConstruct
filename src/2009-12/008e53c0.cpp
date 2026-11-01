// from server: 100% by auto
// roc 2009-12 008e53c0  unit: CXTCaptionButton  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e53c0
//
// 008e53c0  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 008e53c6  85c9                 test ecx, ecx
// 008e53c8  7408                 je 0x8e53d2
// 008e53ca  e88157f2ff           call 0x80ab50
// 008e53cf  8b00                 mov eax, dword ptr [eax]
// 008e53d1  c3                   ret 
// 008e53d2  33c0                 xor eax, eax
// 008e53d4  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?GetNormalIcon@CXTButton@@QAEPAUHICON__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
