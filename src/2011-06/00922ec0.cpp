// from server: 100% by auto
// roc 2011-06 00922ec0  unit: Ogre::VDataStream::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00922ec0
//
// 00922ec0  56                   push esi
// 00922ec1  8bf1                 mov esi, ecx
// 00922ec3  8b4608               mov eax, dword ptr [esi + 8]
// 00922ec6  c706984baf00         mov dword ptr [esi], 0xaf4b98
// 00922ecc  85c0                 test eax, eax
// 00922ece  7411                 je 0x922ee1
// 00922ed0  ff08                 dec dword ptr [eax]
// 00922ed2  8b4608               mov eax, dword ptr [esi + 8]
// 00922ed5  833800               cmp dword ptr [eax], 0
// 00922ed8  7507                 jne 0x922ee1
// 00922eda  8b16                 mov edx, dword ptr [esi]
// 00922edc  8b4204               mov eax, dword ptr [edx + 4]
// 00922edf  ffd0                 call eax
// 00922ee1  f644240801           test byte ptr [esp + 8], 1
// 00922ee6  7409                 je 0x922ef1
// 00922ee8  56                   push esi
// 00922ee9  e86a71eeff           call 0x80a058
// 00922eee  83c404               add esp, 4
// 00922ef1  8bc6                 mov eax, esi
// 00922ef3  5e                   pop esi
// 00922ef4  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
