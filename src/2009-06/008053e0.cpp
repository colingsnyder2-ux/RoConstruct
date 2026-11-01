// from server: 100% by auto
// roc 2009-06 008053e0  unit: CXTPRichRender::XTextHost  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008053e0
//
// 008053e0  33c0                 xor eax, eax
// 008053e2  394108               cmp dword ptr [ecx + 8], eax
// 008053e5  0f95c0               setne al
// 008053e8  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ?IsOfficeTheme@CXTThemeManagerStyle@@QAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
