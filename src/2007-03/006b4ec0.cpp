// from server: 100% by auto
// roc 2007-03 006b4ec0  unit: seg_006b0000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b4ec0
//
// 006b4ec0  c701cc467d00         mov dword ptr [ecx], 0x7d46cc
// 006b4ec6  c741206c467d00       mov dword ptr [ecx + 0x20], 0x7d466c
// 006b4ecd  e95ec4f7ff           jmp 0x631330
// library ogre-1.6.4/OgreDefaultSceneQueries.cpp (function ??1DefaultIntersectionSceneQuery@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreDefaultSceneQueries.cpp
