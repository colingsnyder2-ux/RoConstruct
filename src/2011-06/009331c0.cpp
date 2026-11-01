// from server: 100% by auto
// roc 2011-06 009331c0  unit: Ogre::VRbxSky::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009331c0
//
// 009331c0  56                   push esi
// 009331c1  8bf1                 mov esi, ecx
// 009331c3  8b4608               mov eax, dword ptr [esi + 8]
// 009331c6  c706c85aaf00         mov dword ptr [esi], 0xaf5ac8
// 009331cc  85c0                 test eax, eax
// 009331ce  7411                 je 0x9331e1
// 009331d0  ff08                 dec dword ptr [eax]
// 009331d2  8b4608               mov eax, dword ptr [esi + 8]
// 009331d5  833800               cmp dword ptr [eax], 0
// 009331d8  7507                 jne 0x9331e1
// 009331da  8b16                 mov edx, dword ptr [esi]
// 009331dc  8b4204               mov eax, dword ptr [edx + 4]
// 009331df  ffd0                 call eax
// 009331e1  f644240801           test byte ptr [esp + 8], 1
// 009331e6  7409                 je 0x9331f1
// 009331e8  56                   push esi
// 009331e9  e86a6eedff           call 0x80a058
// 009331ee  83c404               add esp, 4
// 009331f1  8bc6                 mov eax, esi
// 009331f3  5e                   pop esi
// 009331f4  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
