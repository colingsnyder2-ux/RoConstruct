// from server: 100% by auto
// roc 2010-06 00893d10  unit: CXTPRichRender::XTextHost  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00893d10
//
// 00893d10  8b442404             mov eax, dword ptr [esp + 4]
// 00893d14  56                   push esi
// 00893d15  57                   push edi
// 00893d16  33c9                 xor ecx, ecx
// 00893d18  8908                 mov dword ptr [eax], ecx
// 00893d1a  33d2                 xor edx, edx
// 00893d1c  33f6                 xor esi, esi
// 00893d1e  895004               mov dword ptr [eax + 4], edx
// 00893d21  33ff                 xor edi, edi
// 00893d23  897008               mov dword ptr [eax + 8], esi
// 00893d26  89780c               mov dword ptr [eax + 0xc], edi
// 00893d29  5f                   pop edi
// 00893d2a  33c0                 xor eax, eax
// 00893d2c  5e                   pop esi
// 00893d2d  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPRichRender.cpp (function ?TxGetViewInset@XTextHost@CXTPRichRender@@UAEJPAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPRichRender.cpp
