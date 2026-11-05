// from server: 100% by auto
// roc 2010-06 00893970  unit: CXTPRichRender::XTextHost  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00893970
//
// 00893970  8b442404             mov eax, dword ptr [esp + 4]
// 00893974  c700ffffffff         mov dword ptr [eax], 0xffffffff
// 0089397a  33c0                 xor eax, eax
// 0089397c  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPRichRender.cpp (function ?TxGetAcceleratorPos@XTextHost@CXTPRichRender@@UAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPRichRender.cpp
