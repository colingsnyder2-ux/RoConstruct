// from server: 100% by auto
// roc 2007-03 005c02b0  unit: seg_005c0000  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c02b0
//
// 005c02b0  8b4630               mov eax, dword ptr [esi + 0x30]
// 005c02b3  3d204e0000           cmp eax, 0x4e20
// 005c02b8  7e08                 jle 0x5c02c2
// 005c02ba  6a05                 push 5
// 005c02bc  56                   push esi
// 005c02bd  e83effffff           call 0x5c0200
// 005c02c2  03c0                 add eax, eax
// 005c02c4  50                   push eax
// 005c02c5  56                   push esi
// 005c02c6  e8a5f9ffff           call 0x5bfc70
// 005c02cb  83c408               add esp, 8
// 005c02ce  817e30204e0000       cmp dword ptr [esi + 0x30], 0x4e20
// 005c02d5  7e0e                 jle 0x5c02e5
// 005c02d7  6850977b00           push 0x7b9750
// 005c02dc  56                   push esi
// 005c02dd  e8ce2d0000           call 0x5c30b0
// 005c02e2  83c408               add esp, 8
// 005c02e5  83461418             add dword ptr [esi + 0x14], 0x18
// 005c02e9  8b4614               mov eax, dword ptr [esi + 0x14]
// 005c02ec  c3                   ret 
// library lua-5.1.1/ldo.c (function _growCI)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldo.c
