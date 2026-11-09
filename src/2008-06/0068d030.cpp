// from server: 100% by auto
// roc 2008-06 0068d030  unit: Ogre::VShadowCameraSetup::?$SharedPtr  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068d030
//
// 0068d030  56                   push esi
// 0068d031  8bf1                 mov esi, ecx
// 0068d033  8b4e04               mov ecx, dword ptr [esi + 4]
// 0068d036  85c9                 test ecx, ecx
// 0068d038  7409                 je 0x68d043
// 0068d03a  8b01                 mov eax, dword ptr [ecx]
// 0068d03c  8b5004               mov edx, dword ptr [eax + 4]
// 0068d03f  6a01                 push 1
// 0068d041  ffd2                 call edx
// 0068d043  8b4608               mov eax, dword ptr [esi + 8]
// 0068d046  50                   push eax
// 0068d047  e82e360100           call 0x6a067a
// 0068d04c  83c404               add esp, 4
// 0068d04f  5e                   pop esi
// 0068d050  c3                   ret 
// library ogre-1.4.9/OgreAutoParamDataSource.cpp (function ?destroy@?$SharedPtr@VShadowCameraSetup@Ogre@@@Ogre@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAutoParamDataSource.cpp
