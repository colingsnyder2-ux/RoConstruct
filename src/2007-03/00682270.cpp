// from server: 100% by auto
// roc 2007-03 00682270  unit: seg_00680000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00682270
//
// 00682270  56                   push esi
// 00682271  8bf1                 mov esi, ecx
// 00682273  e8983a0000           call 0x685d10
// 00682278  8bc8                 mov ecx, eax
// 0068227a  e8f1490000           call 0x686c70
// 0068227f  898650010000         mov dword ptr [esi + 0x150], eax
// 00682285  5e                   pop esi
// 00682286  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTGlobal.cpp (function ?GetComCtlVersion@CXTAuxData@@QAEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTGlobal.cpp
