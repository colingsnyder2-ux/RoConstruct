// from server: 100% by auto
// roc 2011-06 00928d00  unit: Ogre::RBXSSAO::MRTListener  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00928d00
//
// 00928d00  f644240401           test byte ptr [esp + 4], 1
// 00928d05  a1e010a400           mov eax, dword ptr [0xa410e0]
// 00928d0a  56                   push esi
// 00928d0b  8bf1                 mov esi, ecx
// 00928d0d  8906                 mov dword ptr [esi], eax
// 00928d0f  7409                 je 0x928d1a
// 00928d11  56                   push esi
// 00928d12  e84113eeff           call 0x80a058
// 00928d17  83c404               add esp, 4
// 00928d1a  8bc6                 mov eax, esi
// 00928d1c  5e                   pop esi
// 00928d1d  c20400               ret 4
// library ogre-1.7.0/OgreOptimisedUtilGeneral.cpp (function ??_GOptimisedUtilGeneral@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreOptimisedUtilGeneral.cpp
