// from server: 100% by auto
// roc 2009-06 00473c10  unit: Ogre::VRbxSky::?$SharedPtr  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00473c10
//
// 00473c10  56                   push esi
// 00473c11  8bf1                 mov esi, ecx
// 00473c13  8b4e04               mov ecx, dword ptr [esi + 4]
// 00473c16  85c9                 test ecx, ecx
// 00473c18  7408                 je 0x473c22
// 00473c1a  8b01                 mov eax, dword ptr [ecx]
// 00473c1c  8b10                 mov edx, dword ptr [eax]
// 00473c1e  6a01                 push 1
// 00473c20  ffd2                 call edx
// 00473c22  8b4608               mov eax, dword ptr [esi + 8]
// 00473c25  50                   push eax
// 00473c26  e8074e2a00           call 0x718a32
// 00473c2b  83c404               add esp, 4
// 00473c2e  5e                   pop esi
// 00473c2f  c3                   ret 
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ?destroy@?$SharedPtr@VMaterial@Ogre@@@Ogre@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
