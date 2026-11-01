// from server: 100% by auto
// roc 2010-06 008ed2e0  unit: Ogre::RbxSceneManager  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008ed2e0
//
// 008ed2e0  8b4108               mov eax, dword ptr [ecx + 8]
// 008ed2e3  c701f89aa800         mov dword ptr [ecx], 0xa89af8
// 008ed2e9  85c0                 test eax, eax
// 008ed2eb  7411                 je 0x8ed2fe
// 008ed2ed  ff08                 dec dword ptr [eax]
// 008ed2ef  8b4108               mov eax, dword ptr [ecx + 8]
// 008ed2f2  833800               cmp dword ptr [eax], 0
// 008ed2f5  7507                 jne 0x8ed2fe
// 008ed2f7  8b11                 mov edx, dword ptr [ecx]
// 008ed2f9  8b4204               mov eax, dword ptr [edx + 4]
// 008ed2fc  ffe0                 jmp eax
// 008ed2fe  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
