// from server: 100% by auto
// roc 2010-06 008ed300  unit: Ogre::VRbxSky::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008ed300
//
// 008ed300  56                   push esi
// 008ed301  8bf1                 mov esi, ecx
// 008ed303  8b4608               mov eax, dword ptr [esi + 8]
// 008ed306  c706f89aa800         mov dword ptr [esi], 0xa89af8
// 008ed30c  85c0                 test eax, eax
// 008ed30e  7411                 je 0x8ed321
// 008ed310  ff08                 dec dword ptr [eax]
// 008ed312  8b4608               mov eax, dword ptr [esi + 8]
// 008ed315  833800               cmp dword ptr [eax], 0
// 008ed318  7507                 jne 0x8ed321
// 008ed31a  8b16                 mov edx, dword ptr [esi]
// 008ed31c  8b4204               mov eax, dword ptr [edx + 4]
// 008ed31f  ffd0                 call eax
// 008ed321  f644240801           test byte ptr [esp + 8], 1
// 008ed326  7409                 je 0x8ed331
// 008ed328  56                   push esi
// 008ed329  e86ca6ebff           call 0x7a799a
// 008ed32e  83c404               add esp, 4
// 008ed331  8bc6                 mov eax, esi
// 008ed333  5e                   pop esi
// 008ed334  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
