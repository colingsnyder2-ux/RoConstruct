// from server: 100% by auto
// roc 2011-06 00962750  unit: std::D::DU?$char_traits::V?$basic_string::V?$vector::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00962750
//
// 00962750  56                   push esi
// 00962751  8bf1                 mov esi, ecx
// 00962753  8b4608               mov eax, dword ptr [esi + 8]
// 00962756  c706607baf00         mov dword ptr [esi], 0xaf7b60
// 0096275c  85c0                 test eax, eax
// 0096275e  7411                 je 0x962771
// 00962760  ff08                 dec dword ptr [eax]
// 00962762  8b4608               mov eax, dword ptr [esi + 8]
// 00962765  833800               cmp dword ptr [eax], 0
// 00962768  7507                 jne 0x962771
// 0096276a  8b16                 mov edx, dword ptr [esi]
// 0096276c  8b4204               mov eax, dword ptr [edx + 4]
// 0096276f  ffd0                 call eax
// 00962771  f644240801           test byte ptr [esp + 8], 1
// 00962776  7409                 je 0x962781
// 00962778  56                   push esi
// 00962779  e8da78eaff           call 0x80a058
// 0096277e  83c404               add esp, 4
// 00962781  8bc6                 mov eax, esi
// 00962783  5e                   pop esi
// 00962784  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
