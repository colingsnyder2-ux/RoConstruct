// from server: 100% by auto
// roc 2010-06 008939a0  unit: CXTPRichRender::XTextHost  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008939a0
//
// 008939a0  8b442404             mov eax, dword ptr [esp + 4]
// 008939a4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008939a8  2503040000           and eax, 0x403
// 008939ad  8901                 mov dword ptr [ecx], eax
// 008939af  33c0                 xor eax, eax
// 008939b1  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPRichRender.cpp (function ?TxGetPropertyBits@XTextHost@CXTPRichRender@@UAEJKPAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPRichRender.cpp
