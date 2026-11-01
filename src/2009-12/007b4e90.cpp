// from server: 100% by auto
// roc 2009-12 007b4e90  unit: RBX::RotateJoint  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b4e90
//
// 007b4e90  56                   push esi
// 007b4e91  8bf1                 mov esi, ecx
// 007b4e93  c7062ce09e00         mov dword ptr [esi], 0x9ee02c
// 007b4e99  c746200ce09e00       mov dword ptr [esi + 0x20], 0x9ee00c
// 007b4ea0  e89b0e0000           call 0x7b5d40
// 007b4ea5  f644240801           test byte ptr [esp + 8], 1
// 007b4eaa  7409                 je 0x7b4eb5
// 007b4eac  56                   push esi
// 007b4ead  e8a8e90300           call 0x7f385a
// 007b4eb2  83c404               add esp, 4
// 007b4eb5  8bc6                 mov eax, esi
// 007b4eb7  5e                   pop esi
// 007b4eb8  c20400               ret 4
// library ogre-1.6.4/OgreDefaultSceneQueries.cpp (function ??_GDefaultIntersectionSceneQuery@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreDefaultSceneQueries.cpp
