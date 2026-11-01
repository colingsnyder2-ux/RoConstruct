// from server: 100% by auto
// roc 2009-12 0047ee70  unit: Ogre::VDataStream::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047ee70
//
// 0047ee70  56                   push esi
// 0047ee71  8bf1                 mov esi, ecx
// 0047ee73  8b4608               mov eax, dword ptr [esi + 8]
// 0047ee76  c70600229b00         mov dword ptr [esi], 0x9b2200
// 0047ee7c  85c0                 test eax, eax
// 0047ee7e  7411                 je 0x47ee91
// 0047ee80  ff08                 dec dword ptr [eax]
// 0047ee82  8b4608               mov eax, dword ptr [esi + 8]
// 0047ee85  833800               cmp dword ptr [eax], 0
// 0047ee88  7507                 jne 0x47ee91
// 0047ee8a  8b16                 mov edx, dword ptr [esi]
// 0047ee8c  8b4204               mov eax, dword ptr [edx + 4]
// 0047ee8f  ffd0                 call eax
// 0047ee91  f644240801           test byte ptr [esp + 8], 1
// 0047ee96  7409                 je 0x47eea1
// 0047ee98  56                   push esi
// 0047ee99  e8bc493700           call 0x7f385a
// 0047ee9e  83c404               add esp, 4
// 0047eea1  8bc6                 mov eax, esi
// 0047eea3  5e                   pop esi
// 0047eea4  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
