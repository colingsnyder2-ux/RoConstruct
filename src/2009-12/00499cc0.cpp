// from server: 100% by auto
// roc 2009-12 00499cc0  unit: Ogre::VRbxSky::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00499cc0
//
// 00499cc0  56                   push esi
// 00499cc1  8bf1                 mov esi, ecx
// 00499cc3  8b4608               mov eax, dword ptr [esi + 8]
// 00499cc6  c706e8329b00         mov dword ptr [esi], 0x9b32e8
// 00499ccc  85c0                 test eax, eax
// 00499cce  7411                 je 0x499ce1
// 00499cd0  ff08                 dec dword ptr [eax]
// 00499cd2  8b4608               mov eax, dword ptr [esi + 8]
// 00499cd5  833800               cmp dword ptr [eax], 0
// 00499cd8  7507                 jne 0x499ce1
// 00499cda  8b16                 mov edx, dword ptr [esi]
// 00499cdc  8b4204               mov eax, dword ptr [edx + 4]
// 00499cdf  ffd0                 call eax
// 00499ce1  f644240801           test byte ptr [esp + 8], 1
// 00499ce6  7409                 je 0x499cf1
// 00499ce8  56                   push esi
// 00499ce9  e86c9b3500           call 0x7f385a
// 00499cee  83c404               add esp, 4
// 00499cf1  8bc6                 mov eax, esi
// 00499cf3  5e                   pop esi
// 00499cf4  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
