// from server: 100% by auto
// roc 2011-06 0078ae50  unit: RBX::Block  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0078ae50
//
// 0078ae50  56                   push esi
// 0078ae51  8b742408             mov esi, dword ptr [esp + 8]
// 0078ae55  8b4614               mov eax, dword ptr [esi + 0x14]
// 0078ae58  85c0                 test eax, eax
// 0078ae5a  7409                 je 0x78ae65
// 0078ae5c  50                   push eax
// 0078ae5d  e8f6f10700           call 0x80a058
// 0078ae62  83c404               add esp, 4
// 0078ae65  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0078ae6c  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0078ae73  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0078ae7a  5e                   pop esi
// 0078ae7b  c20400               ret 4
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ?destroy@?$allocator@UEdgeGroup@EdgeData@Ogre@@@std@@QAEXPAUEdgeGroup@EdgeData@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
