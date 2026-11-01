// from server: 100% by auto
// roc 2011-06 00922ea0  unit: RBX::AdornRbxGfx  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00922ea0
//
// 00922ea0  8b4108               mov eax, dword ptr [ecx + 8]
// 00922ea3  c701984baf00         mov dword ptr [ecx], 0xaf4b98
// 00922ea9  85c0                 test eax, eax
// 00922eab  7411                 je 0x922ebe
// 00922ead  ff08                 dec dword ptr [eax]
// 00922eaf  8b4108               mov eax, dword ptr [ecx + 8]
// 00922eb2  833800               cmp dword ptr [eax], 0
// 00922eb5  7507                 jne 0x922ebe
// 00922eb7  8b11                 mov edx, dword ptr [ecx]
// 00922eb9  8b4204               mov eax, dword ptr [edx + 4]
// 00922ebc  ffe0                 jmp eax
// 00922ebe  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
