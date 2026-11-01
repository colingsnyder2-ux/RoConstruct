// from server: 100% by auto
// roc 2009-12 004851a0  unit: Ogre::RbxMeshLoader  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004851a0
//
// 004851a0  f644240401           test byte ptr [esp + 4], 1
// 004851a5  a160c09800           mov eax, dword ptr [0x98c060]
// 004851aa  56                   push esi
// 004851ab  8bf1                 mov esi, ecx
// 004851ad  8906                 mov dword ptr [esi], eax
// 004851af  7409                 je 0x4851ba
// 004851b1  56                   push esi
// 004851b2  e8a3e63600           call 0x7f385a
// 004851b7  83c404               add esp, 4
// 004851ba  8bc6                 mov eax, esi
// 004851bc  5e                   pop esi
// 004851bd  c20400               ret 4
// library ogre-1.7.0/OgreOptimisedUtilGeneral.cpp (function ??_GOptimisedUtilGeneral@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreOptimisedUtilGeneral.cpp
