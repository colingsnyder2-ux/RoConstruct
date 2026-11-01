// from server: 100% by auto
// roc 2011-06 0091dbe0  unit: Ogre::VResource::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0091dbe0
//
// 0091dbe0  56                   push esi
// 0091dbe1  8bf1                 mov esi, ecx
// 0091dbe3  8b4608               mov eax, dword ptr [esi + 8]
// 0091dbe6  c7064044af00         mov dword ptr [esi], 0xaf4440
// 0091dbec  85c0                 test eax, eax
// 0091dbee  7411                 je 0x91dc01
// 0091dbf0  ff08                 dec dword ptr [eax]
// 0091dbf2  8b4608               mov eax, dword ptr [esi + 8]
// 0091dbf5  833800               cmp dword ptr [eax], 0
// 0091dbf8  7507                 jne 0x91dc01
// 0091dbfa  8b16                 mov edx, dword ptr [esi]
// 0091dbfc  8b4204               mov eax, dword ptr [edx + 4]
// 0091dbff  ffd0                 call eax
// 0091dc01  f644240801           test byte ptr [esp + 8], 1
// 0091dc06  7409                 je 0x91dc11
// 0091dc08  56                   push esi
// 0091dc09  e84ac4eeff           call 0x80a058
// 0091dc0e  83c404               add esp, 4
// 0091dc11  8bc6                 mov eax, esi
// 0091dc13  5e                   pop esi
// 0091dc14  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
