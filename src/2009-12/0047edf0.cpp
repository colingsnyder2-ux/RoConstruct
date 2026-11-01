// from server: 100% by auto
// roc 2009-12 0047edf0  unit: RBX::AdornRbxGfx  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047edf0
//
// 0047edf0  8b4108               mov eax, dword ptr [ecx + 8]
// 0047edf3  c70100229b00         mov dword ptr [ecx], 0x9b2200
// 0047edf9  85c0                 test eax, eax
// 0047edfb  7411                 je 0x47ee0e
// 0047edfd  ff08                 dec dword ptr [eax]
// 0047edff  8b4108               mov eax, dword ptr [ecx + 8]
// 0047ee02  833800               cmp dword ptr [eax], 0
// 0047ee05  7507                 jne 0x47ee0e
// 0047ee07  8b11                 mov edx, dword ptr [ecx]
// 0047ee09  8b4204               mov eax, dword ptr [edx + 4]
// 0047ee0c  ffe0                 jmp eax
// 0047ee0e  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
