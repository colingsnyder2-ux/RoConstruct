// from server: 100% by auto
// roc 2007-03 0048bd40  unit: seg_00480000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0048bd40
//
// 0048bd40  6aff                 push -1
// 0048bd42  6801d57300           push 0x73d501
// 0048bd47  64a100000000         mov eax, dword ptr fs:[0]
// 0048bd4d  50                   push eax
// 0048bd4e  51                   push ecx
// 0048bd4f  a1b4f58a00           mov eax, dword ptr [0x8af5b4]
// 0048bd54  33c4                 xor eax, esp
// 0048bd56  50                   push eax
// 0048bd57  8d442408             lea eax, [esp + 8]
// 0048bd5b  64a300000000         mov dword ptr fs:[0], eax
// 0048bd61  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048bd65  894c2418             mov dword ptr [esp + 0x18], ecx
// 0048bd69  894c2404             mov dword ptr [esp + 4], ecx
// 0048bd6d  85c9                 test ecx, ecx
// 0048bd6f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0048bd77  740a                 je 0x48bd83
// 0048bd79  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048bd7d  50                   push eax
// 0048bd7e  e8fdfcffff           call 0x48ba80
// 0048bd83  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0048bd87  64890d00000000       mov dword ptr fs:[0], ecx
// 0048bd8e  59                   pop ecx
// 0048bd8f  83c410               add esp, 0x10
// 0048bd92  c3                   ret 
// library ogre-1.7.0/OgreCompositorInstance.cpp (function ??$_Construct@VTargetOperation@CompositorInstance@Ogre@@V123@@std@@YAXPAVTargetOperation@CompositorInstance@Ogre@@ABV123@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreCompositorInstance.cpp
