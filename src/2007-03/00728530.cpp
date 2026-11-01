// from server: 100% by auto
// roc 2007-03 00728530  unit: seg_00720000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00728530
//
// 00728530  6aff                 push -1
// 00728532  6801d57300           push 0x73d501
// 00728537  64a100000000         mov eax, dword ptr fs:[0]
// 0072853d  50                   push eax
// 0072853e  51                   push ecx
// 0072853f  a1b4f58a00           mov eax, dword ptr [0x8af5b4]
// 00728544  33c4                 xor eax, esp
// 00728546  50                   push eax
// 00728547  8d442408             lea eax, [esp + 8]
// 0072854b  64a300000000         mov dword ptr fs:[0], eax
// 00728551  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00728555  894c2418             mov dword ptr [esp + 0x18], ecx
// 00728559  894c2404             mov dword ptr [esp + 4], ecx
// 0072855d  85c9                 test ecx, ecx
// 0072855f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00728567  740a                 je 0x728573
// 00728569  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0072856d  50                   push eax
// 0072856e  e8fd020000           call 0x728870
// 00728573  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00728577  64890d00000000       mov dword ptr fs:[0], ecx
// 0072857e  59                   pop ecx
// 0072857f  83c410               add esp, 0x10
// 00728582  c3                   ret 
// library ogre-1.7.0/OgreCompositorInstance.cpp (function ??$_Construct@VTargetOperation@CompositorInstance@Ogre@@V123@@std@@YAXPAVTargetOperation@CompositorInstance@Ogre@@ABV123@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreCompositorInstance.cpp
