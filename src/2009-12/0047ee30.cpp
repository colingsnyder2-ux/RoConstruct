// from server: 100% by auto
// roc 2009-12 0047ee30  unit: Ogre::VResource::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047ee30
//
// 0047ee30  56                   push esi
// 0047ee31  8bf1                 mov esi, ecx
// 0047ee33  8b4608               mov eax, dword ptr [esi + 8]
// 0047ee36  c706f0219b00         mov dword ptr [esi], 0x9b21f0
// 0047ee3c  85c0                 test eax, eax
// 0047ee3e  7411                 je 0x47ee51
// 0047ee40  ff08                 dec dword ptr [eax]
// 0047ee42  8b4608               mov eax, dword ptr [esi + 8]
// 0047ee45  833800               cmp dword ptr [eax], 0
// 0047ee48  7507                 jne 0x47ee51
// 0047ee4a  8b16                 mov edx, dword ptr [esi]
// 0047ee4c  8b4204               mov eax, dword ptr [edx + 4]
// 0047ee4f  ffd0                 call eax
// 0047ee51  f644240801           test byte ptr [esp + 8], 1
// 0047ee56  7409                 je 0x47ee61
// 0047ee58  56                   push esi
// 0047ee59  e8fc493700           call 0x7f385a
// 0047ee5e  83c404               add esp, 4
// 0047ee61  8bc6                 mov eax, esi
// 0047ee63  5e                   pop esi
// 0047ee64  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
