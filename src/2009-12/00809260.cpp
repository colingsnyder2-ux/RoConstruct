// from server: 100% by auto
// roc 2009-12 00809260  unit: CXTPCommandBar  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00809260
//
// 00809260  e8bb240300           call 0x83b720
// 00809265  8bc8                 mov ecx, eax
// 00809267  e884340300           call 0x83c6f0
// 0080926c  c1e810               shr eax, 0x10
// 0080926f  b905000000           mov ecx, 5
// 00809274  3bc8                 cmp ecx, eax
// 00809276  1bc0                 sbb eax, eax
// 00809278  f7d8                 neg eax
// 0080927a  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?IsAlphaIconsImageListSupported@CXTPImageManager@@SAHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
