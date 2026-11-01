// from server: 100% by auto
// roc 2010-06 008db860  unit: Ogre::VGpuProgramParameters::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008db860
//
// 008db860  56                   push esi
// 008db861  8bf1                 mov esi, ecx
// 008db863  8b4608               mov eax, dword ptr [esi + 8]
// 008db866  c7066894a800         mov dword ptr [esi], 0xa89468
// 008db86c  85c0                 test eax, eax
// 008db86e  7411                 je 0x8db881
// 008db870  ff08                 dec dword ptr [eax]
// 008db872  8b4608               mov eax, dword ptr [esi + 8]
// 008db875  833800               cmp dword ptr [eax], 0
// 008db878  7507                 jne 0x8db881
// 008db87a  8b16                 mov edx, dword ptr [esi]
// 008db87c  8b4204               mov eax, dword ptr [edx + 4]
// 008db87f  ffd0                 call eax
// 008db881  f644240801           test byte ptr [esp + 8], 1
// 008db886  7409                 je 0x8db891
// 008db888  56                   push esi
// 008db889  e80cc1ecff           call 0x7a799a
// 008db88e  83c404               add esp, 4
// 008db891  8bc6                 mov eax, esi
// 008db893  5e                   pop esi
// 008db894  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
