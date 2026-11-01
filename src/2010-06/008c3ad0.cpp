// from server: 100% by auto
// roc 2010-06 008c3ad0  unit: RBX::ViewRbxGfx  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c3ad0
//
// 008c3ad0  8b4108               mov eax, dword ptr [ecx + 8]
// 008c3ad3  c7014c7fa800         mov dword ptr [ecx], 0xa87f4c
// 008c3ad9  85c0                 test eax, eax
// 008c3adb  7411                 je 0x8c3aee
// 008c3add  ff08                 dec dword ptr [eax]
// 008c3adf  8b4108               mov eax, dword ptr [ecx + 8]
// 008c3ae2  833800               cmp dword ptr [eax], 0
// 008c3ae5  7507                 jne 0x8c3aee
// 008c3ae7  8b11                 mov edx, dword ptr [ecx]
// 008c3ae9  8b4204               mov eax, dword ptr [edx + 4]
// 008c3aec  ffe0                 jmp eax
// 008c3aee  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
