// from server: 100% by auto
// roc 2010-06 00901df0  unit: std::D::DU?$char_traits::V?$basic_string::V?$vector::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00901df0
//
// 00901df0  56                   push esi
// 00901df1  8bf1                 mov esi, ecx
// 00901df3  8b4608               mov eax, dword ptr [esi + 8]
// 00901df6  c70620a9a800         mov dword ptr [esi], 0xa8a920
// 00901dfc  85c0                 test eax, eax
// 00901dfe  7411                 je 0x901e11
// 00901e00  ff08                 dec dword ptr [eax]
// 00901e02  8b4608               mov eax, dword ptr [esi + 8]
// 00901e05  833800               cmp dword ptr [eax], 0
// 00901e08  7507                 jne 0x901e11
// 00901e0a  8b16                 mov edx, dword ptr [esi]
// 00901e0c  8b4204               mov eax, dword ptr [edx + 4]
// 00901e0f  ffd0                 call eax
// 00901e11  f644240801           test byte ptr [esp + 8], 1
// 00901e16  7409                 je 0x901e21
// 00901e18  56                   push esi
// 00901e19  e87c5beaff           call 0x7a799a
// 00901e1e  83c404               add esp, 4
// 00901e21  8bc6                 mov eax, esi
// 00901e23  5e                   pop esi
// 00901e24  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
