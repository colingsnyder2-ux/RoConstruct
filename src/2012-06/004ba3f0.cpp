// from server: 100% by auto
// roc 2012-06 004ba3f0  unit: RBX::ViewRbxGfx  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ba3f0
//
// 004ba3f0  8b4108               mov eax, dword ptr [ecx + 8]
// 004ba3f3  c7017c44b600         mov dword ptr [ecx], 0xb6447c
// 004ba3f9  85c0                 test eax, eax
// 004ba3fb  7411                 je 0x4ba40e
// 004ba3fd  ff08                 dec dword ptr [eax]
// 004ba3ff  8b4108               mov eax, dword ptr [ecx + 8]
// 004ba402  833800               cmp dword ptr [eax], 0
// 004ba405  7507                 jne 0x4ba40e
// 004ba407  8b11                 mov edx, dword ptr [ecx]
// 004ba409  8b4204               mov eax, dword ptr [edx + 4]
// 004ba40c  ffe0                 jmp eax
// 004ba40e  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
