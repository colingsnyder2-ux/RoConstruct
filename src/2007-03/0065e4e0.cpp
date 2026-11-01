// from server: 100% by auto
// roc 2007-03 0065e4e0  unit: seg_00650000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065e4e0
//
// 0065e4e0  c701dc8c7c00         mov dword ptr [ecx], 0x7c8cdc
// 0065e4e6  c741207c8c7c00       mov dword ptr [ecx + 0x20], 0x7c8c7c
// 0065e4ed  e95e730100           jmp 0x675850
// library ogre-1.6.4/OgreDefaultSceneQueries.cpp (function ??1DefaultIntersectionSceneQuery@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreDefaultSceneQueries.cpp
