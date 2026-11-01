// from server: 100% by auto
// roc 2011-06 00962730  unit: Ogre::RbxArchiveFactory  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00962730
//
// 00962730  8b4108               mov eax, dword ptr [ecx + 8]
// 00962733  c701607baf00         mov dword ptr [ecx], 0xaf7b60
// 00962739  85c0                 test eax, eax
// 0096273b  7411                 je 0x96274e
// 0096273d  ff08                 dec dword ptr [eax]
// 0096273f  8b4108               mov eax, dword ptr [ecx + 8]
// 00962742  833800               cmp dword ptr [eax], 0
// 00962745  7507                 jne 0x96274e
// 00962747  8b11                 mov edx, dword ptr [ecx]
// 00962749  8b4204               mov eax, dword ptr [edx + 4]
// 0096274c  ffe0                 jmp eax
// 0096274e  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
