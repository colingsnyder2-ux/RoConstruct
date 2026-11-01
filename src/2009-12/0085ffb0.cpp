// from server: 100% by auto
// roc 2009-12 0085ffb0  unit: CXTPToolTipContext::CHTMLToolTip::XDocHostUIHandler  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085ffb0
//
// 0085ffb0  8b442408             mov eax, dword ptr [esp + 8]
// 0085ffb4  c740040d000400       mov dword ptr [eax + 4], 0x4000d
// 0085ffbb  c7400800000000       mov dword ptr [eax + 8], 0
// 0085ffc2  33c0                 xor eax, eax
// 0085ffc4  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?GetHostInfo@XDocHostUIHandler@CHTMLToolTip@CXTPToolTipContext@@UAGJPAU_DOCHOSTUIINFO@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
