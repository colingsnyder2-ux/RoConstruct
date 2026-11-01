// from server: 100% by auto
// roc 2010-06 008db7c0  unit: Ogre::RbxMaterialAdapter  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008db7c0
//
// 008db7c0  8b4108               mov eax, dword ptr [ecx + 8]
// 008db7c3  c7016894a800         mov dword ptr [ecx], 0xa89468
// 008db7c9  85c0                 test eax, eax
// 008db7cb  7411                 je 0x8db7de
// 008db7cd  ff08                 dec dword ptr [eax]
// 008db7cf  8b4108               mov eax, dword ptr [ecx + 8]
// 008db7d2  833800               cmp dword ptr [eax], 0
// 008db7d5  7507                 jne 0x8db7de
// 008db7d7  8b11                 mov edx, dword ptr [ecx]
// 008db7d9  8b4204               mov eax, dword ptr [edx + 4]
// 008db7dc  ffe0                 jmp eax
// 008db7de  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
