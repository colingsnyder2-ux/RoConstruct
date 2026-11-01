// from server: 100% by auto
// roc 2007-08 004a5be0  unit: RBX::Network::Server::ClientProxy  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a5be0
//
// 004a5be0  6aff                 push -1
// 004a5be2  68917b7400           push 0x747b91
// 004a5be7  64a100000000         mov eax, dword ptr fs:[0]
// 004a5bed  50                   push eax
// 004a5bee  51                   push ecx
// 004a5bef  a188518b00           mov eax, dword ptr [0x8b5188]
// 004a5bf4  33c4                 xor eax, esp
// 004a5bf6  50                   push eax
// 004a5bf7  8d442408             lea eax, [esp + 8]
// 004a5bfb  64a300000000         mov dword ptr fs:[0], eax
// 004a5c01  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004a5c05  894c2418             mov dword ptr [esp + 0x18], ecx
// 004a5c09  894c2404             mov dword ptr [esp + 4], ecx
// 004a5c0d  85c9                 test ecx, ecx
// 004a5c0f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004a5c17  740a                 je 0x4a5c23
// 004a5c19  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a5c1d  50                   push eax
// 004a5c1e  e8fd252800           call 0x728220
// 004a5c23  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004a5c27  64890d00000000       mov dword ptr fs:[0], ecx
// 004a5c2e  59                   pop ecx
// 004a5c2f  83c410               add esp, 0x10
// 004a5c32  c3                   ret 
// library ogre-1.7.0/OgreCompositorInstance.cpp (function ??$_Construct@VTargetOperation@CompositorInstance@Ogre@@V123@@std@@YAXPAVTargetOperation@CompositorInstance@Ogre@@ABV123@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreCompositorInstance.cpp
