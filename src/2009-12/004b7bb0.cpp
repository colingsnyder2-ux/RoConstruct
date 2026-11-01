// from server: 100% by auto
// roc 2009-12 004b7bb0  unit: Ogre::UFileInfo::V?$vector::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b7bb0
//
// 004b7bb0  56                   push esi
// 004b7bb1  8bf1                 mov esi, ecx
// 004b7bb3  8b4608               mov eax, dword ptr [esi + 8]
// 004b7bb6  c7063c489b00         mov dword ptr [esi], 0x9b483c
// 004b7bbc  85c0                 test eax, eax
// 004b7bbe  7411                 je 0x4b7bd1
// 004b7bc0  ff08                 dec dword ptr [eax]
// 004b7bc2  8b4608               mov eax, dword ptr [esi + 8]
// 004b7bc5  833800               cmp dword ptr [eax], 0
// 004b7bc8  7507                 jne 0x4b7bd1
// 004b7bca  8b16                 mov edx, dword ptr [esi]
// 004b7bcc  8b4204               mov eax, dword ptr [edx + 4]
// 004b7bcf  ffd0                 call eax
// 004b7bd1  f644240801           test byte ptr [esp + 8], 1
// 004b7bd6  7409                 je 0x4b7be1
// 004b7bd8  56                   push esi
// 004b7bd9  e87cbc3300           call 0x7f385a
// 004b7bde  83c404               add esp, 4
// 004b7be1  8bc6                 mov eax, esi
// 004b7be3  5e                   pop esi
// 004b7be4  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
