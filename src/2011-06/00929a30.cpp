// from server: 100% by auto
// roc 2011-06 00929a30  unit: Ogre::UFileInfo::V?$vector::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00929a30
//
// 00929a30  56                   push esi
// 00929a31  8bf1                 mov esi, ecx
// 00929a33  8b4608               mov eax, dword ptr [esi + 8]
// 00929a36  c7068452af00         mov dword ptr [esi], 0xaf5284
// 00929a3c  85c0                 test eax, eax
// 00929a3e  7411                 je 0x929a51
// 00929a40  ff08                 dec dword ptr [eax]
// 00929a42  8b4608               mov eax, dword ptr [esi + 8]
// 00929a45  833800               cmp dword ptr [eax], 0
// 00929a48  7507                 jne 0x929a51
// 00929a4a  8b16                 mov edx, dword ptr [esi]
// 00929a4c  8b4204               mov eax, dword ptr [edx + 4]
// 00929a4f  ffd0                 call eax
// 00929a51  f644240801           test byte ptr [esp + 8], 1
// 00929a56  7409                 je 0x929a61
// 00929a58  56                   push esi
// 00929a59  e8fa05eeff           call 0x80a058
// 00929a5e  83c404               add esp, 4
// 00929a61  8bc6                 mov eax, esi
// 00929a63  5e                   pop esi
// 00929a64  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
