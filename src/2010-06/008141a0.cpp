// from server: 100% by auto
// roc 2010-06 008141a0  unit: CXTPToolTipContext::CHTMLToolTip  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008141a0
//
// 008141a0  8b8190000000         mov eax, dword ptr [ecx + 0x90]
// 008141a6  83f8ff               cmp eax, -1
// 008141a9  750e                 jne 0x8141b9
// 008141ab  e870f9fcff           call 0x7e3b20
// 008141b0  6a18                 push 0x18
// 008141b2  8bc8                 mov ecx, eax
// 008141b4  e8f7f0fcff           call 0x7e32b0
// 008141b9  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?GetTipBkColor@CXTPToolTipContext@@QBEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
