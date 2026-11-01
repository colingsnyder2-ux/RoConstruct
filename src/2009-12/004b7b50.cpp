// from server: 100% by auto
// roc 2009-12 004b7b50  unit: Ogre::RbxArchiveFactory  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b7b50
//
// 004b7b50  8b4108               mov eax, dword ptr [ecx + 8]
// 004b7b53  c7013c489b00         mov dword ptr [ecx], 0x9b483c
// 004b7b59  85c0                 test eax, eax
// 004b7b5b  7411                 je 0x4b7b6e
// 004b7b5d  ff08                 dec dword ptr [eax]
// 004b7b5f  8b4108               mov eax, dword ptr [ecx + 8]
// 004b7b62  833800               cmp dword ptr [eax], 0
// 004b7b65  7507                 jne 0x4b7b6e
// 004b7b67  8b11                 mov edx, dword ptr [ecx]
// 004b7b69  8b4204               mov eax, dword ptr [edx + 4]
// 004b7b6c  ffe0                 jmp eax
// 004b7b6e  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
