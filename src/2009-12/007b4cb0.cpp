// from server: 100% by auto
// roc 2009-12 007b4cb0  unit: RBX::RotateJoint  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b4cb0
//
// 007b4cb0  c7012ce09e00         mov dword ptr [ecx], 0x9ee02c
// 007b4cb6  c741200ce09e00       mov dword ptr [ecx + 0x20], 0x9ee00c
// 007b4cbd  e97e100000           jmp 0x7b5d40
// library ogre-1.6.4/OgreDefaultSceneQueries.cpp (function ??1DefaultIntersectionSceneQuery@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreDefaultSceneQueries.cpp
