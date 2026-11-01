// from server: 100% by auto
// roc 2012-06 004ba410  unit: Ogre::VResource::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ba410
//
// 004ba410  56                   push esi
// 004ba411  8bf1                 mov esi, ecx
// 004ba413  8b4608               mov eax, dword ptr [esi + 8]
// 004ba416  c7067c44b600         mov dword ptr [esi], 0xb6447c
// 004ba41c  85c0                 test eax, eax
// 004ba41e  7411                 je 0x4ba431
// 004ba420  ff08                 dec dword ptr [eax]
// 004ba422  8b4608               mov eax, dword ptr [esi + 8]
// 004ba425  833800               cmp dword ptr [eax], 0
// 004ba428  7507                 jne 0x4ba431
// 004ba42a  8b16                 mov edx, dword ptr [esi]
// 004ba42c  8b4204               mov eax, dword ptr [edx + 4]
// 004ba42f  ffd0                 call eax
// 004ba431  f644240801           test byte ptr [esp + 8], 1
// 004ba436  7409                 je 0x4ba441
// 004ba438  56                   push esi
// 004ba439  e8d67c4c00           call 0x982114
// 004ba43e  83c404               add esp, 4
// 004ba441  8bc6                 mov eax, esi
// 004ba443  5e                   pop esi
// 004ba444  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
