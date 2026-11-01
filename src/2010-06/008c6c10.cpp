// from server: 100% by auto
// roc 2010-06 008c6c10  unit: RBX::ManualObjectMeshGenAdapter  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c6c10
//
// 008c6c10  8b4108               mov eax, dword ptr [ecx + 8]
// 008c6c13  c7016081a800         mov dword ptr [ecx], 0xa88160
// 008c6c19  85c0                 test eax, eax
// 008c6c1b  7411                 je 0x8c6c2e
// 008c6c1d  ff08                 dec dword ptr [eax]
// 008c6c1f  8b4108               mov eax, dword ptr [ecx + 8]
// 008c6c22  833800               cmp dword ptr [eax], 0
// 008c6c25  7507                 jne 0x8c6c2e
// 008c6c27  8b11                 mov edx, dword ptr [ecx]
// 008c6c29  8b4204               mov eax, dword ptr [edx + 4]
// 008c6c2c  ffe0                 jmp eax
// 008c6c2e  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
