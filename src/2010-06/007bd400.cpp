// from server: 100% by auto
// roc 2010-06 007bd400  unit: CXTPCommandBar  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bd400
//
// 007bd400  e86b240300           call 0x7ef870
// 007bd405  8bc8                 mov ecx, eax
// 007bd407  e844340300           call 0x7f0850
// 007bd40c  c1e810               shr eax, 0x10
// 007bd40f  b905000000           mov ecx, 5
// 007bd414  3bc8                 cmp ecx, eax
// 007bd416  1bc0                 sbb eax, eax
// 007bd418  f7d8                 neg eax
// 007bd41a  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?IsAlphaIconsImageListSupported@CXTPImageManager@@SAHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
