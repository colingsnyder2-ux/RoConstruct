// from server: 100% by auto
// roc 2009-06 00804c10  unit: CXTPRichRender::XTextHost  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00804c10
//
// 00804c10  8b442404             mov eax, dword ptr [esp + 4]
// 00804c14  c700ffffffff         mov dword ptr [eax], 0xffffffff
// 00804c1a  33c0                 xor eax, eax
// 00804c1c  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ?TxGetAcceleratorPos@XTextHost@CXTPRichRender@@UAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp
