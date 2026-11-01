// from server: 100% by auto
// roc 2009-06 0089379e  unit: seg_00890000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0089379e
//
// 0089379e  68a02ba500           push 0xa52ba0
// 008937a3  b9ac2ba500           mov ecx, 0xa52bac
// 008937a8  e8f275f8ff           call 0x81ad9f
// 008937ad  6814d68900           push 0x89d614
// 008937b2  e84463e8ff           call 0x719afb
// 008937b7  59                   pop ecx
// 008937b8  c3                   ret 
// library xtp-15.2.1/Source\Controls\Util\XTPRegistryManager.cpp (function ??__E?m_strINIFileName@CXTPRegistryManager@@1V?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPRegistryManager.cpp
