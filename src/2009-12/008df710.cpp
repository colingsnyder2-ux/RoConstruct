// from server: 100% by auto
// roc 2009-12 008df710  unit: CXTPRichRender::XTextHost  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008df710
//
// 008df710  8b442404             mov eax, dword ptr [esp + 4]
// 008df714  c70000000001         mov dword ptr [eax], 0x1000000
// 008df71a  33c0                 xor eax, eax
// 008df71c  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ?TxGetMaxLength@XTextHost@CXTPRichRender@@UAEJPAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp
