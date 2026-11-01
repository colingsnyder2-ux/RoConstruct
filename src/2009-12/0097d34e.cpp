// from server: 100% by auto
// roc 2009-12 0097d34e  unit: seg_00970000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097d34e
//
// 0097d34e  68f8bfb900           push 0xb9bff8
// 0097d353  b904c0b900           mov ecx, 0xb9c004
// 0097d358  e82287f7ff           call 0x8f5a7f
// 0097d35d  68d4a79800           push 0x98a7d4
// 0097d362  e8c275e7ff           call 0x7f4929
// 0097d367  59                   pop ecx
// 0097d368  c3                   ret 
// library xtp-15.2.1/Source\Controls\Util\XTPRegistryManager.cpp (function ??__E?m_strINIFileName@CXTPRegistryManager@@1V?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPRegistryManager.cpp
