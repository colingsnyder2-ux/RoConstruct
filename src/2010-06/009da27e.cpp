// from server: 100% by auto
// roc 2010-06 009da27e  unit: seg_009d0000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009da27e
//
// 009da27e  682867c200           push 0xc26728
// 009da283  b93467c200           mov ecx, 0xc26734
// 009da288  e852f9ecff           call 0x8a9bdf
// 009da28d  68d4919e00           push 0x9e91d4
// 009da292  e8cce7dcff           call 0x7a8a63
// 009da297  59                   pop ecx
// 009da298  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTRegistryManager.cpp (function ??__E?m_strINIFileName@CXTRegistryManager@@1V?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTRegistryManager.cpp
