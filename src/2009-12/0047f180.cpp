// from server: 100% by auto
// roc 2009-12 0047f180  unit: Ogre::VRbxFont::?$SharedPtr  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047f180
//
// 0047f180  8b4108               mov eax, dword ptr [ecx + 8]
// 0047f183  c701f0219b00         mov dword ptr [ecx], 0x9b21f0
// 0047f189  85c0                 test eax, eax
// 0047f18b  7411                 je 0x47f19e
// 0047f18d  ff08                 dec dword ptr [eax]
// 0047f18f  8b4108               mov eax, dword ptr [ecx + 8]
// 0047f192  833800               cmp dword ptr [eax], 0
// 0047f195  7507                 jne 0x47f19e
// 0047f197  8b11                 mov edx, dword ptr [ecx]
// 0047f199  8b4204               mov eax, dword ptr [edx + 4]
// 0047f19c  ffe0                 jmp eax
// 0047f19e  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
