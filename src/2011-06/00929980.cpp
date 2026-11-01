// from server: 100% by auto
// roc 2011-06 00929980  unit: ResourceGroupHelper::ResourceGroupHelperLogListener  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00929980
//
// 00929980  8b4108               mov eax, dword ptr [ecx + 8]
// 00929983  c7018452af00         mov dword ptr [ecx], 0xaf5284
// 00929989  85c0                 test eax, eax
// 0092998b  7411                 je 0x92999e
// 0092998d  ff08                 dec dword ptr [eax]
// 0092998f  8b4108               mov eax, dword ptr [ecx + 8]
// 00929992  833800               cmp dword ptr [eax], 0
// 00929995  7507                 jne 0x92999e
// 00929997  8b11                 mov edx, dword ptr [ecx]
// 00929999  8b4204               mov eax, dword ptr [edx + 4]
// 0092999c  ffe0                 jmp eax
// 0092999e  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??1?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
