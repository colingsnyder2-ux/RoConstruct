// from server: 100% by auto
// roc 2011-06 00a2f560  unit: seg_00a20000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00a2f560
//
// 00a2f560  68cabea500           push 0xa5beca
// 00a2f565  b9388fd100           mov ecx, 0xd18f38
// 00a2f56a  ff15002ea400         call dword ptr [0xa42e00]
// 00a2f570  6810fda300           push 0xa3fd10
// 00a2f575  e8e3bbddff           call 0x80b15d
// 00a2f57a  59                   pop ecx
// 00a2f57b  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Controls\Util\XTPRegistryManager.cpp (function ??__E?m_strINIFileName@CXTPRegistryManager@@1V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Util/XTPRegistryManager.cpp
