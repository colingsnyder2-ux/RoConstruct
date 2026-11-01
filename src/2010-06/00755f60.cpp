// from server: 100% by auto
// roc 2010-06 00755f60  unit: RBX::Block  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00755f60
//
// 00755f60  56                   push esi
// 00755f61  8b742408             mov esi, dword ptr [esp + 8]
// 00755f65  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00755f68  85c0                 test eax, eax
// 00755f6a  7409                 je 0x755f75
// 00755f6c  50                   push eax
// 00755f6d  e8281a0500           call 0x7a799a
// 00755f72  83c404               add esp, 4
// 00755f75  8b4610               mov eax, dword ptr [esi + 0x10]
// 00755f78  50                   push eax
// 00755f79  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00755f80  c7462000000000       mov dword ptr [esi + 0x20], 0
// 00755f87  c7462400000000       mov dword ptr [esi + 0x24], 0
// 00755f8e  e8071a0500           call 0x7a799a
// 00755f93  83c404               add esp, 4
// 00755f96  5e                   pop esi
// 00755f97  c20400               ret 4
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ?destroy@?$allocator@UEdgeGroup@EdgeData@Ogre@@@std@@QAEXPAUEdgeGroup@EdgeData@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
