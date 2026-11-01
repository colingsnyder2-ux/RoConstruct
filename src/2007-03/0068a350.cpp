// from server: 100% by auto
// roc 2007-03 0068a350  unit: seg_00680000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068a350
//
// 0068a350  c70144f57c00         mov dword ptr [ecx], 0x7cf544
// 0068a356  c74120e4f47c00       mov dword ptr [ecx + 0x20], 0x7cf4e4
// 0068a35d  e9deafffff           jmp 0x685340
// library ogre-1.6.4/OgreDefaultSceneQueries.cpp (function ??1DefaultIntersectionSceneQuery@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreDefaultSceneQueries.cpp
