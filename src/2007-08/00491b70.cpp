// from server: 100% by auto
// roc 2007-08 00491b70  unit: RBX::Network::VPlayer::?$Listener  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00491b70
//
// 00491b70  6aff                 push -1
// 00491b72  68917b7400           push 0x747b91
// 00491b77  64a100000000         mov eax, dword ptr fs:[0]
// 00491b7d  50                   push eax
// 00491b7e  51                   push ecx
// 00491b7f  a188518b00           mov eax, dword ptr [0x8b5188]
// 00491b84  33c4                 xor eax, esp
// 00491b86  50                   push eax
// 00491b87  8d442408             lea eax, [esp + 8]
// 00491b8b  64a300000000         mov dword ptr fs:[0], eax
// 00491b91  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00491b95  894c2418             mov dword ptr [esp + 0x18], ecx
// 00491b99  894c2404             mov dword ptr [esp + 4], ecx
// 00491b9d  85c9                 test ecx, ecx
// 00491b9f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00491ba7  740a                 je 0x491bb3
// 00491ba9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00491bad  50                   push eax
// 00491bae  e8bdfeffff           call 0x491a70
// 00491bb3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00491bb7  64890d00000000       mov dword ptr fs:[0], ecx
// 00491bbe  59                   pop ecx
// 00491bbf  83c410               add esp, 0x10
// 00491bc2  c3                   ret 
// library ogre-1.7.0/OgreCompositorInstance.cpp (function ??$_Construct@VTargetOperation@CompositorInstance@Ogre@@V123@@std@@YAXPAVTargetOperation@CompositorInstance@Ogre@@ABV123@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreCompositorInstance.cpp
