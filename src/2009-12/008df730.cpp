// from server: 100% by auto
// roc 2009-12 008df730  unit: CXTPRichRender::XTextHost  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008df730
//
// 008df730  8b442404             mov eax, dword ptr [esp + 4]
// 008df734  c700ffffffff         mov dword ptr [eax], 0xffffffff
// 008df73a  33c0                 xor eax, eax
// 008df73c  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ?TxGetAcceleratorPos@XTextHost@CXTPRichRender@@UAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp
