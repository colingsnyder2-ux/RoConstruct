// from server: 100% by auto
// roc 2011-06 0092bb30  unit: Ogre::RbxMeshLoader  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0092bb30
//
// 0092bb30  f644240401           test byte ptr [esp + 4], 1
// 0092bb35  a15010a400           mov eax, dword ptr [0xa41050]
// 0092bb3a  56                   push esi
// 0092bb3b  8bf1                 mov esi, ecx
// 0092bb3d  8906                 mov dword ptr [esi], eax
// 0092bb3f  7409                 je 0x92bb4a
// 0092bb41  56                   push esi
// 0092bb42  e811e5edff           call 0x80a058
// 0092bb47  83c404               add esp, 4
// 0092bb4a  8bc6                 mov eax, esi
// 0092bb4c  5e                   pop esi
// 0092bb4d  c20400               ret 4
// library ogre-1.7.0/OgreOptimisedUtilGeneral.cpp (function ??_GOptimisedUtilGeneral@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreOptimisedUtilGeneral.cpp
