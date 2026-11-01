// from server: 100% by auto
// roc 2011-06 00a27c00  unit: seg_00a20000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00a27c00
//
// 00a27c00  68cabea500           push 0xa5beca
// 00a27c05  b91cfbcc00           mov ecx, 0xccfb1c
// 00a27c0a  ff15c404a400         call dword ptr [0xa404c4]
// 00a27c10  68d0bea300           push 0xa3bed0
// 00a27c15  e84335deff           call 0x80b15d
// 00a27c1a  59                   pop ecx
// 00a27c1b  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Controls\Util\XTPRegistryManager.cpp (function ??__E?m_strINIFileName@CXTPRegistryManager@@1V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Util/XTPRegistryManager.cpp
