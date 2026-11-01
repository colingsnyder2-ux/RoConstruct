// from server: 100% by auto
// roc 2009-12 0086b060  unit: CXTPPropertyGridItemEnum  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086b060
//
// 0086b060  c701acf99f00         mov dword ptr [ecx], 0x9ff9ac
// 0086b066  c741204cf99f00       mov dword ptr [ecx + 0x20], 0x9ff94c
// 0086b06d  e99ebdffff           jmp 0x866e10
// library ogre-1.6.4/OgreDefaultSceneQueries.cpp (function ??1DefaultIntersectionSceneQuery@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreDefaultSceneQueries.cpp
