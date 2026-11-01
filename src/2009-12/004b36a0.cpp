// from server: 100% by auto
// roc 2009-12 004b36a0  unit: Ogre::RbxMaterialAdapter  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b36a0
//
// 004b36a0  8b4108               mov eax, dword ptr [ecx + 8]
// 004b36a3  c7014c479b00         mov dword ptr [ecx], 0x9b474c
// 004b36a9  85c0                 test eax, eax
// 004b36ab  7411                 je 0x4b36be
// 004b36ad  ff08                 dec dword ptr [eax]
// 004b36af  8b4108               mov eax, dword ptr [ecx + 8]
// 004b36b2  833800               cmp dword ptr [eax], 0
// 004b36b5  7507                 jne 0x4b36be
// 004b36b7  8b11                 mov edx, dword ptr [ecx]
// 004b36b9  8b4204               mov eax, dword ptr [edx + 4]
// 004b36bc  ffe0                 jmp eax
// 004b36be  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
