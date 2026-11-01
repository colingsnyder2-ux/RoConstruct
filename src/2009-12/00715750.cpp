// from server: 100% by auto
// roc 2009-12 00715750  unit: RBX::RigidJoint  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00715750
//
// 00715750  56                   push esi
// 00715751  8bf1                 mov esi, ecx
// 00715753  c70664e89d00         mov dword ptr [esi], 0x9de864
// 00715759  c7462044e89d00       mov dword ptr [esi + 0x20], 0x9de844
// 00715760  e8bbe20500           call 0x773a20
// 00715765  f644240801           test byte ptr [esp + 8], 1
// 0071576a  7409                 je 0x715775
// 0071576c  56                   push esi
// 0071576d  e8e8e00d00           call 0x7f385a
// 00715772  83c404               add esp, 4
// 00715775  8bc6                 mov eax, esi
// 00715777  5e                   pop esi
// 00715778  c20400               ret 4
// library ogre-1.6.4/OgreDefaultSceneQueries.cpp (function ??_GDefaultIntersectionSceneQuery@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreDefaultSceneQueries.cpp
