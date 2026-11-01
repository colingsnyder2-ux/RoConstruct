// from server: 100% by auto
// roc 2010-06 008c6c30  unit: Ogre::VDataStream::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c6c30
//
// 008c6c30  56                   push esi
// 008c6c31  8bf1                 mov esi, ecx
// 008c6c33  8b4608               mov eax, dword ptr [esi + 8]
// 008c6c36  c7067081a800         mov dword ptr [esi], 0xa88170
// 008c6c3c  85c0                 test eax, eax
// 008c6c3e  7411                 je 0x8c6c51
// 008c6c40  ff08                 dec dword ptr [eax]
// 008c6c42  8b4608               mov eax, dword ptr [esi + 8]
// 008c6c45  833800               cmp dword ptr [eax], 0
// 008c6c48  7507                 jne 0x8c6c51
// 008c6c4a  8b16                 mov edx, dword ptr [esi]
// 008c6c4c  8b4204               mov eax, dword ptr [edx + 4]
// 008c6c4f  ffd0                 call eax
// 008c6c51  f644240801           test byte ptr [esp + 8], 1
// 008c6c56  7409                 je 0x8c6c61
// 008c6c58  56                   push esi
// 008c6c59  e83c0deeff           call 0x7a799a
// 008c6c5e  83c404               add esp, 4
// 008c6c61  8bc6                 mov eax, esi
// 008c6c63  5e                   pop esi
// 008c6c64  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
