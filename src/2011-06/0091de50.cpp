// from server: 100% by auto
// roc 2011-06 0091de50  unit: Ogre::VResource::?$SharedPtr  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0091de50
//
// 0091de50  8b4108               mov eax, dword ptr [ecx + 8]
// 0091de53  c7014044af00         mov dword ptr [ecx], 0xaf4440
// 0091de59  85c0                 test eax, eax
// 0091de5b  7411                 je 0x91de6e
// 0091de5d  ff08                 dec dword ptr [eax]
// 0091de5f  8b4108               mov eax, dword ptr [ecx + 8]
// 0091de62  833800               cmp dword ptr [eax], 0
// 0091de65  7507                 jne 0x91de6e
// 0091de67  8b11                 mov edx, dword ptr [ecx]
// 0091de69  8b4204               mov eax, dword ptr [edx + 4]
// 0091de6c  ffe0                 jmp eax
// 0091de6e  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
