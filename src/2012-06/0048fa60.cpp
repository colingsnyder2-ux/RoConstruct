// from server: 100% by auto
// roc 2012-06 0048fa60  unit: CRobloxReportPaneView  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0048fa60
//
// 0048fa60  8b4104               mov eax, dword ptr [ecx + 4]
// 0048fa63  85c0                 test eax, eax
// 0048fa65  7407                 je 0x48fa6e
// 0048fa67  50                   push eax
// 0048fa68  e8a7264f00           call 0x982114
// 0048fa6d  59                   pop ecx
// 0048fa6e  c3                   ret 
// library ogre-1.6.4/OgreRenderQueueSortingGrouping.cpp (function ??1?$_Temp_iterator@URenderablePass@Ogre@@@std@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreRenderQueueSortingGrouping.cpp
