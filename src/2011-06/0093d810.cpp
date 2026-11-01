// from server: 100% by auto
// roc 2011-06 0093d810  unit: Ogre::RbxMaterialAdapter  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0093d810
//
// 0093d810  8b4108               mov eax, dword ptr [ecx + 8]
// 0093d813  c701a069af00         mov dword ptr [ecx], 0xaf69a0
// 0093d819  85c0                 test eax, eax
// 0093d81b  7411                 je 0x93d82e
// 0093d81d  ff08                 dec dword ptr [eax]
// 0093d81f  8b4108               mov eax, dword ptr [ecx + 8]
// 0093d822  833800               cmp dword ptr [eax], 0
// 0093d825  7507                 jne 0x93d82e
// 0093d827  8b11                 mov edx, dword ptr [ecx]
// 0093d829  8b4204               mov eax, dword ptr [edx + 4]
// 0093d82c  ffe0                 jmp eax
// 0093d82e  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
