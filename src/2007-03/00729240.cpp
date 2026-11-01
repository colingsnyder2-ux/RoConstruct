// from server: 100% by auto
// roc 2007-03 00729240  unit: seg_00720000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00729240
//
// 00729240  6aff                 push -1
// 00729242  6801d57300           push 0x73d501
// 00729247  64a100000000         mov eax, dword ptr fs:[0]
// 0072924d  50                   push eax
// 0072924e  51                   push ecx
// 0072924f  a1b4f58a00           mov eax, dword ptr [0x8af5b4]
// 00729254  33c4                 xor eax, esp
// 00729256  50                   push eax
// 00729257  8d442408             lea eax, [esp + 8]
// 0072925b  64a300000000         mov dword ptr fs:[0], eax
// 00729261  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00729265  894c2418             mov dword ptr [esp + 0x18], ecx
// 00729269  894c2404             mov dword ptr [esp + 4], ecx
// 0072926d  85c9                 test ecx, ecx
// 0072926f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00729277  740a                 je 0x729283
// 00729279  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0072927d  50                   push eax
// 0072927e  e8edfeffff           call 0x729170
// 00729283  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00729287  64890d00000000       mov dword ptr fs:[0], ecx
// 0072928e  59                   pop ecx
// 0072928f  83c410               add esp, 0x10
// 00729292  c3                   ret 
// library ogre-1.7.0/OgreCompositorInstance.cpp (function ??$_Construct@VTargetOperation@CompositorInstance@Ogre@@V123@@std@@YAXPAVTargetOperation@CompositorInstance@Ogre@@ABV123@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreCompositorInstance.cpp
