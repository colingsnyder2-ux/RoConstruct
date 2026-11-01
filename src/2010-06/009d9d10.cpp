// from server: 100% by auto
// roc 2010-06 009d9d10  unit: seg_009d0000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009d9d10
//
// 009d9d10  68fe08a000           push 0xa008fe
// 009d9d15  b94c62c200           mov ecx, 0xc2624c
// 009d9d1a  ff15e8ce9e00         call dword ptr [0x9ecee8]
// 009d9d20  6860919e00           push 0x9e9160
// 009d9d25  e839eddcff           call 0x7a8a63
// 009d9d2a  59                   pop ecx
// 009d9d2b  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Controls\XTRegistryManager.cpp (function ??__E?m_strINIFileName@CXTRegistryManager@@1V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTRegistryManager.cpp
