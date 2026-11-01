// from server: 100% by auto
// roc 2011-06 008ecd30  unit: CXTPRichRender::XTextHost  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ecd30
//
// 008ecd30  33c0                 xor eax, eax
// 008ecd32  394108               cmp dword ptr [ecx + 8], eax
// 008ecd35  0f95c0               setne al
// 008ecd38  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ?IsOfficeTheme@CXTThemeManagerStyle@@QAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
