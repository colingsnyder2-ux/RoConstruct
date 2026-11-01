// from server: 100% by auto
// roc 2009-12 007b5d40  unit: RBX::RotatePJoint  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b5d40
//
// 007b5d40  c7019ce09e00         mov dword ptr [ecx], 0x9ee09c
// 007b5d46  c741207ce09e00       mov dword ptr [ecx + 0x20], 0x9ee07c
// 007b5d4d  e9cedcfbff           jmp 0x773a20
// library ogre-1.6.4/OgreDefaultSceneQueries.cpp (function ??1DefaultIntersectionSceneQuery@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreDefaultSceneQueries.cpp
