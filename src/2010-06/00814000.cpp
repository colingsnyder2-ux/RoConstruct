// from server: 100% by auto
// roc 2010-06 00814000  unit: CXTPToolTipContext::CHTMLToolTip  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00814000
//
// 00814000  81793450000500       cmp dword ptr [ecx + 0x34], 0x50050
// 00814007  1bc0                 sbb eax, eax
// 00814009  40                   inc eax
// 0081400a  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?IsBalloonStyleSupported@CXTPToolTipContext@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
