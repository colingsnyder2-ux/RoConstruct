// from server: 100% by auto
// roc 2010-06 00901d80  unit: Ogre::RbxArchiveFactory  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00901d80
//
// 00901d80  8b4108               mov eax, dword ptr [ecx + 8]
// 00901d83  c70130a9a800         mov dword ptr [ecx], 0xa8a930
// 00901d89  85c0                 test eax, eax
// 00901d8b  7411                 je 0x901d9e
// 00901d8d  ff08                 dec dword ptr [eax]
// 00901d8f  8b4108               mov eax, dword ptr [ecx + 8]
// 00901d92  833800               cmp dword ptr [eax], 0
// 00901d95  7507                 jne 0x901d9e
// 00901d97  8b11                 mov edx, dword ptr [ecx]
// 00901d99  8b4204               mov eax, dword ptr [edx + 4]
// 00901d9c  ffe0                 jmp eax
// 00901d9e  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
