// from server: 100% by auto
// roc 2007-03 006f1e70  unit: seg_006f0000  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f1e70
//
// 006f1e70  8b442404             mov eax, dword ptr [esp + 4]
// 006f1e74  c70000000001         mov dword ptr [eax], 0x1000000
// 006f1e7a  33c0                 xor eax, eax
// 006f1e7c  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ?TxGetMaxLength@XTextHost@CXTPRichRender@@UAEJPAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp
