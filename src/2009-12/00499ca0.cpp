// from server: 100% by auto
// roc 2009-12 00499ca0  unit: Ogre::RbxSceneManager  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00499ca0
//
// 00499ca0  8b4108               mov eax, dword ptr [ecx + 8]
// 00499ca3  c701e8329b00         mov dword ptr [ecx], 0x9b32e8
// 00499ca9  85c0                 test eax, eax
// 00499cab  7411                 je 0x499cbe
// 00499cad  ff08                 dec dword ptr [eax]
// 00499caf  8b4108               mov eax, dword ptr [ecx + 8]
// 00499cb2  833800               cmp dword ptr [eax], 0
// 00499cb5  7507                 jne 0x499cbe
// 00499cb7  8b11                 mov edx, dword ptr [ecx]
// 00499cb9  8b4204               mov eax, dword ptr [edx + 4]
// 00499cbc  ffe0                 jmp eax
// 00499cbe  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
