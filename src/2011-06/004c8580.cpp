// from server: 100% by auto
// roc 2011-06 004c8580  unit: RBX::Network::Players  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004c8580
//
// 004c8580  8b4104               mov eax, dword ptr [ecx + 4]
// 004c8583  85c0                 test eax, eax
// 004c8585  7407                 je 0x4c858e
// 004c8587  50                   push eax
// 004c8588  e8cb1a3400           call 0x80a058
// 004c858d  59                   pop ecx
// 004c858e  c3                   ret 
// library ogre-1.6.4/OgreRenderQueueSortingGrouping.cpp (function ??1?$_Temp_iterator@URenderablePass@Ogre@@@std@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreRenderQueueSortingGrouping.cpp
