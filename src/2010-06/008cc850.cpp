// from server: 100% by auto
// roc 2010-06 008cc850  unit: Ogre::RbxMeshLoader  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008cc850
//
// 008cc850  f644240401           test byte ptr [esp + 4], 1
// 008cc855  a184af9e00           mov eax, dword ptr [0x9eaf84]
// 008cc85a  56                   push esi
// 008cc85b  8bf1                 mov esi, ecx
// 008cc85d  8906                 mov dword ptr [esi], eax
// 008cc85f  7409                 je 0x8cc86a
// 008cc861  56                   push esi
// 008cc862  e833b1edff           call 0x7a799a
// 008cc867  83c404               add esp, 4
// 008cc86a  8bc6                 mov eax, esi
// 008cc86c  5e                   pop esi
// 008cc86d  c20400               ret 4
// library ogre-1.7.0/OgreOptimisedUtilGeneral.cpp (function ??_GOptimisedUtilGeneral@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreOptimisedUtilGeneral.cpp
