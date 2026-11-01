// from server: 100% by auto
// roc 2007-03 006f1ea0  unit: seg_006f0000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f1ea0
//
// 006f1ea0  8b442404             mov eax, dword ptr [esp + 4]
// 006f1ea4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006f1ea8  2503040000           and eax, 0x403
// 006f1ead  8901                 mov dword ptr [ecx], eax
// 006f1eaf  33c0                 xor eax, eax
// 006f1eb1  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ?TxGetPropertyBits@XTextHost@CXTPRichRender@@UAEJKPAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp
