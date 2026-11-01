// from server: 100% by auto
// roc 2009-12 0083c900  unit: CXTPControlPopupColor  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083c900
//
// 0083c900  c701c4859f00         mov dword ptr [ecx], 0x9f85c4
// 0083c906  c7412064859f00       mov dword ptr [ecx + 0x20], 0x9f8564
// 0083c90d  e94ee2ffff           jmp 0x83ab60
// library ogre-1.6.4/OgreDefaultSceneQueries.cpp (function ??1DefaultIntersectionSceneQuery@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreDefaultSceneQueries.cpp
