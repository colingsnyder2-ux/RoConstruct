// from server: 100% by auto
// roc 2009-12 004b3790  unit: Ogre::VGpuProgramParameters::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b3790
//
// 004b3790  56                   push esi
// 004b3791  8bf1                 mov esi, ecx
// 004b3793  8b4608               mov eax, dword ptr [esi + 8]
// 004b3796  c7064c479b00         mov dword ptr [esi], 0x9b474c
// 004b379c  85c0                 test eax, eax
// 004b379e  7411                 je 0x4b37b1
// 004b37a0  ff08                 dec dword ptr [eax]
// 004b37a2  8b4608               mov eax, dword ptr [esi + 8]
// 004b37a5  833800               cmp dword ptr [eax], 0
// 004b37a8  7507                 jne 0x4b37b1
// 004b37aa  8b16                 mov edx, dword ptr [esi]
// 004b37ac  8b4204               mov eax, dword ptr [edx + 4]
// 004b37af  ffd0                 call eax
// 004b37b1  f644240801           test byte ptr [esp + 8], 1
// 004b37b6  7409                 je 0x4b37c1
// 004b37b8  56                   push esi
// 004b37b9  e89c003400           call 0x7f385a
// 004b37be  83c404               add esp, 4
// 004b37c1  8bc6                 mov eax, esi
// 004b37c3  5e                   pop esi
// 004b37c4  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
