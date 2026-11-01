// from server: 100% by auto
// roc 2009-12 00866f50  unit: CPropertyGridItemBrickColor  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00866f50
//
// 00866f50  c701a4ec9f00         mov dword ptr [ecx], 0x9feca4
// 00866f56  c7412044ec9f00       mov dword ptr [ecx + 0x20], 0x9fec44
// 00866f5d  e9aefeffff           jmp 0x866e10
// library ogre-1.6.4/OgreDefaultSceneQueries.cpp (function ??1DefaultIntersectionSceneQuery@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreDefaultSceneQueries.cpp
