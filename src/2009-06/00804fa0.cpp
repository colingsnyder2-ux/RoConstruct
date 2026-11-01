// from server: 100% by auto
// roc 2009-06 00804fa0  unit: CXTPRichRender::XTextHost  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00804fa0
//
// 00804fa0  8b442404             mov eax, dword ptr [esp + 4]
// 00804fa4  56                   push esi
// 00804fa5  57                   push edi
// 00804fa6  33c9                 xor ecx, ecx
// 00804fa8  8908                 mov dword ptr [eax], ecx
// 00804faa  33d2                 xor edx, edx
// 00804fac  33f6                 xor esi, esi
// 00804fae  895004               mov dword ptr [eax + 4], edx
// 00804fb1  33ff                 xor edi, edi
// 00804fb3  897008               mov dword ptr [eax + 8], esi
// 00804fb6  89780c               mov dword ptr [eax + 0xc], edi
// 00804fb9  5f                   pop edi
// 00804fba  33c0                 xor eax, eax
// 00804fbc  5e                   pop esi
// 00804fbd  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ?TxGetViewInset@XTextHost@CXTPRichRender@@UAEJPAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp
