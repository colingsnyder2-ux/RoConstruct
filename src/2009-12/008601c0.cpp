// from server: 100% by auto
// roc 2009-12 008601c0  unit: CXTPToolTipContext::CHTMLToolTip  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008601c0
//
// 008601c0  8b8190000000         mov eax, dword ptr [ecx + 0x90]
// 008601c6  83f8ff               cmp eax, -1
// 008601c9  750e                 jne 0x8601d9
// 008601cb  e800f8fcff           call 0x82f9d0
// 008601d0  6a18                 push 0x18
// 008601d2  8bc8                 mov ecx, eax
// 008601d4  e827effcff           call 0x82f100
// 008601d9  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?GetTipBkColor@CXTPToolTipContext@@QBEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
