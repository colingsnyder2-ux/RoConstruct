// from server: 100% by auto
// roc 2010-06 008c3af0  unit: Ogre::VResource::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c3af0
//
// 008c3af0  56                   push esi
// 008c3af1  8bf1                 mov esi, ecx
// 008c3af3  8b4608               mov eax, dword ptr [esi + 8]
// 008c3af6  c7064c7fa800         mov dword ptr [esi], 0xa87f4c
// 008c3afc  85c0                 test eax, eax
// 008c3afe  7411                 je 0x8c3b11
// 008c3b00  ff08                 dec dword ptr [eax]
// 008c3b02  8b4608               mov eax, dword ptr [esi + 8]
// 008c3b05  833800               cmp dword ptr [eax], 0
// 008c3b08  7507                 jne 0x8c3b11
// 008c3b0a  8b16                 mov edx, dword ptr [esi]
// 008c3b0c  8b4204               mov eax, dword ptr [edx + 4]
// 008c3b0f  ffd0                 call eax
// 008c3b11  f644240801           test byte ptr [esp + 8], 1
// 008c3b16  7409                 je 0x8c3b21
// 008c3b18  56                   push esi
// 008c3b19  e87c3eeeff           call 0x7a799a
// 008c3b1e  83c404               add esp, 4
// 008c3b21  8bc6                 mov eax, esi
// 008c3b23  5e                   pop esi
// 008c3b24  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
