// from server: 100% by auto
// roc 2010-06 009c4600  unit: seg_009c0000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009c4600
//
// 009c4600  64a100000000         mov eax, dword ptr fs:[0]
// 009c4606  6aff                 push -1
// 009c4608  68fa209800           push 0x9820fa
// 009c460d  50                   push eax
// 009c460e  64892500000000       mov dword ptr fs:[0], esp
// 009c4615  6a04                 push 4
// 009c4617  e88433deff           call 0x7a79a0
// 009c461c  33c9                 xor ecx, ecx
// 009c461e  83c404               add esp, 4
// 009c4621  3bc1                 cmp eax, ecx
// 009c4623  7408                 je 0x9c462d
// 009c4625  c7006c1dc000         mov dword ptr [eax], 0xc01d6c
// 009c462b  eb02                 jmp 0x9c462f
// 009c462d  33c0                 xor eax, eax
// 009c462f  a36c1dc000           mov dword ptr [0xc01d6c], eax
// 009c4634  6860bc9d00           push 0x9dbc60
// 009c4639  890d781dc000         mov dword ptr [0xc01d78], ecx
// 009c463f  890d7c1dc000         mov dword ptr [0xc01d7c], ecx
// 009c4645  890d801dc000         mov dword ptr [0xc01d80], ecx
// 009c464b  e81344deff           call 0x7a8a63
// 009c4650  8b4c2404             mov ecx, dword ptr [esp + 4]
// 009c4654  64890d00000000       mov dword ptr fs:[0], ecx
// 009c465b  83c410               add esp, 0x10
// 009c465e  c3                   ret 
// library ogre-1.6.4/OgreConvexBody.cpp (function ??__E?msFreePolygons@ConvexBody@Ogre@@1V?$vector@PAVPolygon@Ogre@@V?$allocator@PAVPolygon@Ogre@@@std@@@std@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreConvexBody.cpp
