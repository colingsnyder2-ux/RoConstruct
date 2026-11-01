// from server: 100% by auto
// roc 2009-12 008901d0  unit: CXTPToolBar::CControlButtonHide  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008901d0
//
// 008901d0  c701b438a000         mov dword ptr [ecx], 0xa038b4
// 008901d6  c741205438a000       mov dword ptr [ecx + 0x20], 0xa03854
// 008901dd  e9ee7df6ff           jmp 0x7f7fd0
// library ogre-1.6.4/OgreDefaultSceneQueries.cpp (function ??1DefaultIntersectionSceneQuery@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreDefaultSceneQueries.cpp
