// from server: 100% by auto
// roc 2009-12 004b7b30  unit: Ogre::RbxArchiveFactory  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b7b30
//
// 004b7b30  8b4108               mov eax, dword ptr [ecx + 8]
// 004b7b33  c7012c489b00         mov dword ptr [ecx], 0x9b482c
// 004b7b39  85c0                 test eax, eax
// 004b7b3b  7411                 je 0x4b7b4e
// 004b7b3d  ff08                 dec dword ptr [eax]
// 004b7b3f  8b4108               mov eax, dword ptr [ecx + 8]
// 004b7b42  833800               cmp dword ptr [eax], 0
// 004b7b45  7507                 jne 0x4b7b4e
// 004b7b47  8b11                 mov edx, dword ptr [ecx]
// 004b7b49  8b4204               mov eax, dword ptr [edx + 4]
// 004b7b4c  ffe0                 jmp eax
// 004b7b4e  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
