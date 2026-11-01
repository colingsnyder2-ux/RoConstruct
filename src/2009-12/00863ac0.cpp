// from server: 100% by auto
// roc 2009-12 00863ac0  unit: CXTPToolTipContextToolTip  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00863ac0
//
// 00863ac0  56                   push esi
// 00863ac1  8bf1                 mov esi, ecx
// 00863ac3  e8587cfdff           call 0x83b720
// 00863ac8  8bc8                 mov ecx, eax
// 00863aca  e8218cfdff           call 0x83c6f0
// 00863acf  898650010000         mov dword ptr [esi + 0x150], eax
// 00863ad5  5e                   pop esi
// 00863ad6  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTGlobal.cpp (function ?GetComCtlVersion@CXTAuxData@@QAEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTGlobal.cpp
