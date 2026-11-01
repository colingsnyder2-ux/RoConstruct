// from server: 100% by auto
// roc 2011-06 009331a0  unit: Ogre::RbxSceneManager  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009331a0
//
// 009331a0  8b4108               mov eax, dword ptr [ecx + 8]
// 009331a3  c701c85aaf00         mov dword ptr [ecx], 0xaf5ac8
// 009331a9  85c0                 test eax, eax
// 009331ab  7411                 je 0x9331be
// 009331ad  ff08                 dec dword ptr [eax]
// 009331af  8b4108               mov eax, dword ptr [ecx + 8]
// 009331b2  833800               cmp dword ptr [eax], 0
// 009331b5  7507                 jne 0x9331be
// 009331b7  8b11                 mov edx, dword ptr [ecx]
// 009331b9  8b4204               mov eax, dword ptr [edx + 4]
// 009331bc  ffe0                 jmp eax
// 009331be  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
