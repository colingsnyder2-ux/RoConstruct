// from server: 100% by auto
// roc 2011-06 008752d0  unit: CXTPToolTipContextToolTip  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008752d0
//
// 008752d0  56                   push esi
// 008752d1  8bf1                 mov esi, ecx
// 008752d3  e8e8bdfdff           call 0x8510c0
// 008752d8  8bc8                 mov ecx, eax
// 008752da  e8b1cdfdff           call 0x852090
// 008752df  898650010000         mov dword ptr [esi + 0x150], eax
// 008752e5  5e                   pop esi
// 008752e6  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTGlobal.cpp (function ?GetComCtlVersion@CXTAuxData@@QAEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTGlobal.cpp
