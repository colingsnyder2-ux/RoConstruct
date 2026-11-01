// from server: 100% by auto
// roc 2007-08 004940f0  unit: RBX::VInstance::$$A6AXV?$shared_ptr::V?$function::?$holder  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004940f0
//
// 004940f0  6aff                 push -1
// 004940f2  68917b7400           push 0x747b91
// 004940f7  64a100000000         mov eax, dword ptr fs:[0]
// 004940fd  50                   push eax
// 004940fe  51                   push ecx
// 004940ff  a188518b00           mov eax, dword ptr [0x8b5188]
// 00494104  33c4                 xor eax, esp
// 00494106  50                   push eax
// 00494107  8d442408             lea eax, [esp + 8]
// 0049410b  64a300000000         mov dword ptr fs:[0], eax
// 00494111  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00494115  894c2418             mov dword ptr [esp + 0x18], ecx
// 00494119  894c2404             mov dword ptr [esp + 4], ecx
// 0049411d  85c9                 test ecx, ecx
// 0049411f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00494127  740a                 je 0x494133
// 00494129  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0049412d  50                   push eax
// 0049412e  e86df9ffff           call 0x493aa0
// 00494133  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00494137  64890d00000000       mov dword ptr fs:[0], ecx
// 0049413e  59                   pop ecx
// 0049413f  83c410               add esp, 0x10
// 00494142  c3                   ret 
// library ogre-1.7.0/OgreCompositorInstance.cpp (function ??$_Construct@VTargetOperation@CompositorInstance@Ogre@@V123@@std@@YAXPAVTargetOperation@CompositorInstance@Ogre@@ABV123@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreCompositorInstance.cpp
