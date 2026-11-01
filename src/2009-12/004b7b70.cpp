// from server: 100% by auto
// roc 2009-12 004b7b70  unit: std::D::DU?$char_traits::V?$basic_string::V?$vector::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b7b70
//
// 004b7b70  56                   push esi
// 004b7b71  8bf1                 mov esi, ecx
// 004b7b73  8b4608               mov eax, dword ptr [esi + 8]
// 004b7b76  c7062c489b00         mov dword ptr [esi], 0x9b482c
// 004b7b7c  85c0                 test eax, eax
// 004b7b7e  7411                 je 0x4b7b91
// 004b7b80  ff08                 dec dword ptr [eax]
// 004b7b82  8b4608               mov eax, dword ptr [esi + 8]
// 004b7b85  833800               cmp dword ptr [eax], 0
// 004b7b88  7507                 jne 0x4b7b91
// 004b7b8a  8b16                 mov edx, dword ptr [esi]
// 004b7b8c  8b4204               mov eax, dword ptr [edx + 4]
// 004b7b8f  ffd0                 call eax
// 004b7b91  f644240801           test byte ptr [esp + 8], 1
// 004b7b96  7409                 je 0x4b7ba1
// 004b7b98  56                   push esi
// 004b7b99  e8bcbc3300           call 0x7f385a
// 004b7b9e  83c404               add esp, 4
// 004b7ba1  8bc6                 mov eax, esi
// 004b7ba3  5e                   pop esi
// 004b7ba4  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??_G?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
