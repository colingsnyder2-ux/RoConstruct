// from server: 100% by auto
// roc 2009-12 008dfee0  unit: CXTPRichRender::XTextHost  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008dfee0
//
// 008dfee0  33c0                 xor eax, eax
// 008dfee2  394108               cmp dword ptr [ecx + 8], eax
// 008dfee5  0f95c0               setne al
// 008dfee8  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ?IsOfficeTheme@CXTThemeManagerStyle@@QAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
