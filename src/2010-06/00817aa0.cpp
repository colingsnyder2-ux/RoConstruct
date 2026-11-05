// from server: 100% by auto
// roc 2010-06 00817aa0  unit: CXTPToolTipContextToolTip  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00817aa0
//
// 00817aa0  56                   push esi
// 00817aa1  8bf1                 mov esi, ecx
// 00817aa3  e8c87dfdff           call 0x7ef870
// 00817aa8  8bc8                 mov ecx, eax
// 00817aaa  e8a18dfdff           call 0x7f0850
// 00817aaf  898650010000         mov dword ptr [esi + 0x150], eax
// 00817ab5  5e                   pop esi
// 00817ab6  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTGlobal.cpp (function ?GetComCtlVersion@CXTAuxData@@QAEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTGlobal.cpp
