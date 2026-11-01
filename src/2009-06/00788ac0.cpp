// from server: 100% by auto
// roc 2009-06 00788ac0  unit: CXTPToolTipContextToolTip  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00788ac0
//
// 00788ac0  56                   push esi
// 00788ac1  8bf1                 mov esi, ecx
// 00788ac3  e8887efdff           call 0x760950
// 00788ac8  8bc8                 mov ecx, eax
// 00788aca  e8518efdff           call 0x761920
// 00788acf  898650010000         mov dword ptr [esi + 0x150], eax
// 00788ad5  5e                   pop esi
// 00788ad6  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTGlobal.cpp (function ?GetComCtlVersion@CXTAuxData@@QAEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTGlobal.cpp
