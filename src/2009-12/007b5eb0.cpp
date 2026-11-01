// from server: 100% by auto
// roc 2009-12 007b5eb0  unit: RBX::MultiJoint  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b5eb0
//
// 007b5eb0  56                   push esi
// 007b5eb1  8bf1                 mov esi, ecx
// 007b5eb3  c7069ce09e00         mov dword ptr [esi], 0x9ee09c
// 007b5eb9  c746207ce09e00       mov dword ptr [esi + 0x20], 0x9ee07c
// 007b5ec0  e85bdbfbff           call 0x773a20
// 007b5ec5  f644240801           test byte ptr [esp + 8], 1
// 007b5eca  7409                 je 0x7b5ed5
// 007b5ecc  56                   push esi
// 007b5ecd  e888d90300           call 0x7f385a
// 007b5ed2  83c404               add esp, 4
// 007b5ed5  8bc6                 mov eax, esi
// 007b5ed7  5e                   pop esi
// 007b5ed8  c20400               ret 4
// library ogre-1.6.4/OgreDefaultSceneQueries.cpp (function ??_GDefaultIntersectionSceneQuery@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreDefaultSceneQueries.cpp
