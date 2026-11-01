// from server: 100% by auto
// roc 2009-06 0080a920  unit: CXTCaptionButton  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080a920
//
// 0080a920  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 0080a926  85c9                 test ecx, ecx
// 0080a928  7408                 je 0x80a932
// 0080a92a  e88191f2ff           call 0x733ab0
// 0080a92f  8b00                 mov eax, dword ptr [eax]
// 0080a931  c3                   ret 
// 0080a932  33c0                 xor eax, eax
// 0080a934  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?GetNormalIcon@CXTButton@@QAEPAUHICON__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
