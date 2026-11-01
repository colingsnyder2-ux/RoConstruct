// from server: 100% by auto
// roc 2007-08 00728bb0  unit: boost::signals::detail::Ubasic_connection::?$sp_counted_impl_p  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00728bb0
//
// 00728bb0  6aff                 push -1
// 00728bb2  68917b7400           push 0x747b91
// 00728bb7  64a100000000         mov eax, dword ptr fs:[0]
// 00728bbd  50                   push eax
// 00728bbe  51                   push ecx
// 00728bbf  a188518b00           mov eax, dword ptr [0x8b5188]
// 00728bc4  33c4                 xor eax, esp
// 00728bc6  50                   push eax
// 00728bc7  8d442408             lea eax, [esp + 8]
// 00728bcb  64a300000000         mov dword ptr fs:[0], eax
// 00728bd1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00728bd5  894c2418             mov dword ptr [esp + 0x18], ecx
// 00728bd9  894c2404             mov dword ptr [esp + 4], ecx
// 00728bdd  85c9                 test ecx, ecx
// 00728bdf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00728be7  740a                 je 0x728bf3
// 00728be9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00728bed  50                   push eax
// 00728bee  e8bdfeffff           call 0x728ab0
// 00728bf3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00728bf7  64890d00000000       mov dword ptr fs:[0], ecx
// 00728bfe  59                   pop ecx
// 00728bff  83c410               add esp, 0x10
// 00728c02  c3                   ret 
// library ogre-1.7.0/OgreCompositorInstance.cpp (function ??$_Construct@VTargetOperation@CompositorInstance@Ogre@@V123@@std@@YAXPAVTargetOperation@CompositorInstance@Ogre@@ABV123@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreCompositorInstance.cpp
