// from server: 100% by auto
// roc 2007-03 0048dfa0  unit: seg_00480000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0048dfa0
//
// 0048dfa0  6aff                 push -1
// 0048dfa2  6801d57300           push 0x73d501
// 0048dfa7  64a100000000         mov eax, dword ptr fs:[0]
// 0048dfad  50                   push eax
// 0048dfae  51                   push ecx
// 0048dfaf  a1b4f58a00           mov eax, dword ptr [0x8af5b4]
// 0048dfb4  33c4                 xor eax, esp
// 0048dfb6  50                   push eax
// 0048dfb7  8d442408             lea eax, [esp + 8]
// 0048dfbb  64a300000000         mov dword ptr fs:[0], eax
// 0048dfc1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048dfc5  894c2418             mov dword ptr [esp + 0x18], ecx
// 0048dfc9  894c2404             mov dword ptr [esp + 4], ecx
// 0048dfcd  85c9                 test ecx, ecx
// 0048dfcf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0048dfd7  740a                 je 0x48dfe3
// 0048dfd9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048dfdd  50                   push eax
// 0048dfde  e85df9ffff           call 0x48d940
// 0048dfe3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0048dfe7  64890d00000000       mov dword ptr fs:[0], ecx
// 0048dfee  59                   pop ecx
// 0048dfef  83c410               add esp, 0x10
// 0048dff2  c3                   ret 
// library ogre-1.7.0/OgreCompositorInstance.cpp (function ??$_Construct@VTargetOperation@CompositorInstance@Ogre@@V123@@std@@YAXPAVTargetOperation@CompositorInstance@Ogre@@ABV123@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreCompositorInstance.cpp
