// from server: 100% by EspClaude
// from server: 81% by EspClaude
// roc 2009-06 005bdd10  unit: RBX::AggregateChunk  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bdd10
//
// 005bdd10  55                   push ebp
// 005bdd11  8bec                 mov ebp, esp
// 005bdd13  6aff                 push -1
// 005bdd15  6848208600           push 0x862048
// 005bdd1a  64a100000000         mov eax, dword ptr fs:[0]
// 005bdd20  50                   push eax
// 005bdd21  64892500000000       mov dword ptr fs:[0], esp
// 005bdd28  51                   push ecx
// 005bdd29  894df0               mov dword ptr [ebp - 0x10], ecx
// 005bdd2c  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005bdd33  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 005bdd36  e8a5000000           call 0x5bdde0
// 005bdd3b  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 005bdd42  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 005bdd45  e806390000           call 0x5c1650
// 005bdd4a  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005bdd4d  64890d00000000       mov dword ptr fs:[0], ecx
// 005bdd54  8be5                 mov esp, ebp
// 005bdd56  5d                   pop ebp
// 005bdd57  c3                   ret 

// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
