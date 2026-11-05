// from server: 100% by auto
// roc 2010-06 00893960  unit: CXTPRichRender::XTextHost  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00893960
//
// 00893960  8b442404             mov eax, dword ptr [esp + 4]
// 00893964  c70000000001         mov dword ptr [eax], 0x1000000
// 0089396a  33c0                 xor eax, eax
// 0089396c  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPRichRender.cpp (function ?TxGetMaxLength@XTextHost@CXTPRichRender@@UAEJPAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPRichRender.cpp
