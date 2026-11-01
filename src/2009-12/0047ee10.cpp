// from server: 100% by auto
// roc 2009-12 0047ee10  unit: RBX::AdornRbxGfx  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047ee10
//
// 0047ee10  8b4108               mov eax, dword ptr [ecx + 8]
// 0047ee13  c701e0219b00         mov dword ptr [ecx], 0x9b21e0
// 0047ee19  85c0                 test eax, eax
// 0047ee1b  7411                 je 0x47ee2e
// 0047ee1d  ff08                 dec dword ptr [eax]
// 0047ee1f  8b4108               mov eax, dword ptr [ecx + 8]
// 0047ee22  833800               cmp dword ptr [eax], 0
// 0047ee25  7507                 jne 0x47ee2e
// 0047ee27  8b11                 mov edx, dword ptr [ecx]
// 0047ee29  8b4204               mov eax, dword ptr [edx + 4]
// 0047ee2c  ffe0                 jmp eax
// 0047ee2e  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
