// from server: 100% by auto
// roc 2010-06 00901d60  unit: Ogre::RbxArchiveFactory  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00901d60
//
// 00901d60  8b4108               mov eax, dword ptr [ecx + 8]
// 00901d63  c70120a9a800         mov dword ptr [ecx], 0xa8a920
// 00901d69  85c0                 test eax, eax
// 00901d6b  7411                 je 0x901d7e
// 00901d6d  ff08                 dec dword ptr [eax]
// 00901d6f  8b4108               mov eax, dword ptr [ecx + 8]
// 00901d72  833800               cmp dword ptr [eax], 0
// 00901d75  7507                 jne 0x901d7e
// 00901d77  8b11                 mov edx, dword ptr [ecx]
// 00901d79  8b4204               mov eax, dword ptr [edx + 4]
// 00901d7c  ffe0                 jmp eax
// 00901d7e  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
