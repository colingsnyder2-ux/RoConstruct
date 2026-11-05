// from server: 100% by auto
// roc 2010-06 00894150  unit: CXTPRichRender::XTextHost  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00894150
//
// 00894150  33c0                 xor eax, eax
// 00894152  394108               cmp dword ptr [ecx + 8], eax
// 00894155  0f95c0               setne al
// 00894158  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ?IsOfficeTheme@CXTThemeManagerStyle@@QAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
