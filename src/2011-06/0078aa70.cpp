// from server: 100% by auto
// roc 2011-06 0078aa70  unit: RBX::Block  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0078aa70
//
// 0078aa70  56                   push esi
// 0078aa71  8bf1                 mov esi, ecx
// 0078aa73  8b4614               mov eax, dword ptr [esi + 0x14]
// 0078aa76  85c0                 test eax, eax
// 0078aa78  7409                 je 0x78aa83
// 0078aa7a  50                   push eax
// 0078aa7b  e8d8f50700           call 0x80a058
// 0078aa80  83c404               add esp, 4
// 0078aa83  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0078aa8a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0078aa91  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0078aa98  5e                   pop esi
// 0078aa99  c3                   ret 
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ??1EdgeGroup@EdgeData@Ogre@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
