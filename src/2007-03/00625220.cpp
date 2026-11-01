// from server: 100% by auto
// roc 2007-03 00625220  unit: seg_00620000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00625220
//
// 00625220  e8eb0a0600           call 0x685d10
// 00625225  8bc8                 mov ecx, eax
// 00625227  e8441a0600           call 0x686c70
// 0062522c  c1e810               shr eax, 0x10
// 0062522f  b905000000           mov ecx, 5
// 00625234  3bc8                 cmp ecx, eax
// 00625236  1bc0                 sbb eax, eax
// 00625238  f7d8                 neg eax
// 0062523a  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?IsAlphaIconsImageListSupported@CXTPImageManager@@SAHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
