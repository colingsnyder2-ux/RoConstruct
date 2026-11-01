// from server: 100% by auto
// roc 2011-06 0093d900  unit: Ogre::VGpuProgramParameters::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0093d900
//
// 0093d900  56                   push esi
// 0093d901  8bf1                 mov esi, ecx
// 0093d903  8b4608               mov eax, dword ptr [esi + 8]
// 0093d906  c706a069af00         mov dword ptr [esi], 0xaf69a0
// 0093d90c  85c0                 test eax, eax
// 0093d90e  7411                 je 0x93d921
// 0093d910  ff08                 dec dword ptr [eax]
// 0093d912  8b4608               mov eax, dword ptr [esi + 8]
// 0093d915  833800               cmp dword ptr [eax], 0
// 0093d918  7507                 jne 0x93d921
// 0093d91a  8b16                 mov edx, dword ptr [esi]
// 0093d91c  8b4204               mov eax, dword ptr [edx + 4]
// 0093d91f  ffd0                 call eax
// 0093d921  f644240801           test byte ptr [esp + 8], 1
// 0093d926  7409                 je 0x93d931
// 0093d928  56                   push esi
// 0093d929  e82ac7ecff           call 0x80a058
// 0093d92e  83c404               add esp, 4
// 0093d931  8bc6                 mov eax, esi
// 0093d933  5e                   pop esi
// 0093d934  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
