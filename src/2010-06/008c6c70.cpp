// from server: 100% by auto
// roc 2010-06 008c6c70  unit: Ogre::VRbxFont::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c6c70
//
// 008c6c70  56                   push esi
// 008c6c71  8bf1                 mov esi, ecx
// 008c6c73  8b4608               mov eax, dword ptr [esi + 8]
// 008c6c76  c7066081a800         mov dword ptr [esi], 0xa88160
// 008c6c7c  85c0                 test eax, eax
// 008c6c7e  7411                 je 0x8c6c91
// 008c6c80  ff08                 dec dword ptr [eax]
// 008c6c82  8b4608               mov eax, dword ptr [esi + 8]
// 008c6c85  833800               cmp dword ptr [eax], 0
// 008c6c88  7507                 jne 0x8c6c91
// 008c6c8a  8b16                 mov edx, dword ptr [esi]
// 008c6c8c  8b4204               mov eax, dword ptr [edx + 4]
// 008c6c8f  ffd0                 call eax
// 008c6c91  f644240801           test byte ptr [esp + 8], 1
// 008c6c96  7409                 je 0x8c6ca1
// 008c6c98  56                   push esi
// 008c6c99  e8fc0ceeff           call 0x7a799a
// 008c6c9e  83c404               add esp, 4
// 008c6ca1  8bc6                 mov eax, esi
// 008c6ca3  5e                   pop esi
// 008c6ca4  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
