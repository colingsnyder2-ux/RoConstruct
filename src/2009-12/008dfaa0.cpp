// from server: 100% by auto
// roc 2009-12 008dfaa0  unit: CXTPRichRender::XTextHost  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008dfaa0
//
// 008dfaa0  8b442404             mov eax, dword ptr [esp + 4]
// 008dfaa4  56                   push esi
// 008dfaa5  57                   push edi
// 008dfaa6  33c9                 xor ecx, ecx
// 008dfaa8  8908                 mov dword ptr [eax], ecx
// 008dfaaa  33d2                 xor edx, edx
// 008dfaac  33f6                 xor esi, esi
// 008dfaae  895004               mov dword ptr [eax + 4], edx
// 008dfab1  33ff                 xor edi, edi
// 008dfab3  897008               mov dword ptr [eax + 8], esi
// 008dfab6  89780c               mov dword ptr [eax + 0xc], edi
// 008dfab9  5f                   pop edi
// 008dfaba  33c0                 xor eax, eax
// 008dfabc  5e                   pop esi
// 008dfabd  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ?TxGetViewInset@XTextHost@CXTPRichRender@@UAEJPAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp
