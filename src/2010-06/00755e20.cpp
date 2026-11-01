// from server: 100% by auto
// roc 2010-06 00755e20  unit: RBX::Block  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00755e20
//
// 00755e20  56                   push esi
// 00755e21  8bf1                 mov esi, ecx
// 00755e23  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00755e26  85c0                 test eax, eax
// 00755e28  7409                 je 0x755e33
// 00755e2a  50                   push eax
// 00755e2b  e86a1b0500           call 0x7a799a
// 00755e30  83c404               add esp, 4
// 00755e33  8b4610               mov eax, dword ptr [esi + 0x10]
// 00755e36  50                   push eax
// 00755e37  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00755e3e  c7462000000000       mov dword ptr [esi + 0x20], 0
// 00755e45  c7462400000000       mov dword ptr [esi + 0x24], 0
// 00755e4c  e8491b0500           call 0x7a799a
// 00755e51  83c404               add esp, 4
// 00755e54  5e                   pop esi
// 00755e55  c3                   ret 
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ??1EdgeGroup@EdgeData@Ogre@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
