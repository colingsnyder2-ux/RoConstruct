// from server: 100% by auto
// roc 2007-03 006f1e80  unit: seg_006f0000  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f1e80
//
// 006f1e80  8b442404             mov eax, dword ptr [esp + 4]
// 006f1e84  c700ffffffff         mov dword ptr [eax], 0xffffffff
// 006f1e8a  33c0                 xor eax, eax
// 006f1e8c  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ?TxGetAcceleratorPos@XTextHost@CXTPRichRender@@UAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp
