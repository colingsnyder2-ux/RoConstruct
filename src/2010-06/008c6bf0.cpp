// from server: 100% by auto
// roc 2010-06 008c6bf0  unit: RBX::ManualObjectMeshGenAdapter  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c6bf0
//
// 008c6bf0  8b4108               mov eax, dword ptr [ecx + 8]
// 008c6bf3  c7017081a800         mov dword ptr [ecx], 0xa88170
// 008c6bf9  85c0                 test eax, eax
// 008c6bfb  7411                 je 0x8c6c0e
// 008c6bfd  ff08                 dec dword ptr [eax]
// 008c6bff  8b4108               mov eax, dword ptr [ecx + 8]
// 008c6c02  833800               cmp dword ptr [eax], 0
// 008c6c05  7507                 jne 0x8c6c0e
// 008c6c07  8b11                 mov edx, dword ptr [ecx]
// 008c6c09  8b4204               mov eax, dword ptr [edx + 4]
// 008c6c0c  ffe0                 jmp eax
// 008c6c0e  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
