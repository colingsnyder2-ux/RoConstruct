// from server: 100% by auto
// roc 2009-06 007320d0  unit: CXTPCommandBar  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007320d0
//
// 007320d0  e87be80200           call 0x760950
// 007320d5  8bc8                 mov ecx, eax
// 007320d7  e844f80200           call 0x761920
// 007320dc  c1e810               shr eax, 0x10
// 007320df  b905000000           mov ecx, 5
// 007320e4  3bc8                 cmp ecx, eax
// 007320e6  1bc0                 sbb eax, eax
// 007320e8  f7d8                 neg eax
// 007320ea  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?IsAlphaIconsImageListSupported@CXTPImageManager@@SAHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
