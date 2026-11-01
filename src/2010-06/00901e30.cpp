// from server: 100% by auto
// roc 2010-06 00901e30  unit: Ogre::UFileInfo::V?$vector::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00901e30
//
// 00901e30  56                   push esi
// 00901e31  8bf1                 mov esi, ecx
// 00901e33  8b4608               mov eax, dword ptr [esi + 8]
// 00901e36  c70630a9a800         mov dword ptr [esi], 0xa8a930
// 00901e3c  85c0                 test eax, eax
// 00901e3e  7411                 je 0x901e51
// 00901e40  ff08                 dec dword ptr [eax]
// 00901e42  8b4608               mov eax, dword ptr [esi + 8]
// 00901e45  833800               cmp dword ptr [eax], 0
// 00901e48  7507                 jne 0x901e51
// 00901e4a  8b16                 mov edx, dword ptr [esi]
// 00901e4c  8b4204               mov eax, dword ptr [edx + 4]
// 00901e4f  ffd0                 call eax
// 00901e51  f644240801           test byte ptr [esp + 8], 1
// 00901e56  7409                 je 0x901e61
// 00901e58  56                   push esi
// 00901e59  e83c5beaff           call 0x7a799a
// 00901e5e  83c404               add esp, 4
// 00901e61  8bc6                 mov eax, esi
// 00901e63  5e                   pop esi
// 00901e64  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
