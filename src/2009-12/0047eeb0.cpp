// from server: 100% by auto
// roc 2009-12 0047eeb0  unit: Ogre::VRbxFont::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047eeb0
//
// 0047eeb0  56                   push esi
// 0047eeb1  8bf1                 mov esi, ecx
// 0047eeb3  8b4608               mov eax, dword ptr [esi + 8]
// 0047eeb6  c706e0219b00         mov dword ptr [esi], 0x9b21e0
// 0047eebc  85c0                 test eax, eax
// 0047eebe  7411                 je 0x47eed1
// 0047eec0  ff08                 dec dword ptr [eax]
// 0047eec2  8b4608               mov eax, dword ptr [esi + 8]
// 0047eec5  833800               cmp dword ptr [eax], 0
// 0047eec8  7507                 jne 0x47eed1
// 0047eeca  8b16                 mov edx, dword ptr [esi]
// 0047eecc  8b4204               mov eax, dword ptr [edx + 4]
// 0047eecf  ffd0                 call eax
// 0047eed1  f644240801           test byte ptr [esp + 8], 1
// 0047eed6  7409                 je 0x47eee1
// 0047eed8  56                   push esi
// 0047eed9  e87c493700           call 0x7f385a
// 0047eede  83c404               add esp, 4
// 0047eee1  8bc6                 mov eax, esi
// 0047eee3  5e                   pop esi
// 0047eee4  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
