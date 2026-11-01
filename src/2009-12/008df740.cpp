// from server: 100% by auto
// roc 2009-12 008df740  unit: CXTPRichRender::XTextHost  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008df740
//
// 008df740  8b442404             mov eax, dword ptr [esp + 4]
// 008df744  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008df748  2503040000           and eax, 0x403
// 008df74d  8901                 mov dword ptr [ecx], eax
// 008df74f  33c0                 xor eax, eax
// 008df751  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ?TxGetPropertyBits@XTextHost@CXTPRichRender@@UAEJKPAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp
