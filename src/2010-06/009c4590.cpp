// from server: 100% by auto
// roc 2010-06 009c4590  unit: seg_009c0000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009c4590
//
// 009c4590  64a100000000         mov eax, dword ptr fs:[0]
// 009c4596  6aff                 push -1
// 009c4598  683a209800           push 0x98203a
// 009c459d  50                   push eax
// 009c459e  64892500000000       mov dword ptr fs:[0], esp
// 009c45a5  6a04                 push 4
// 009c45a7  e8f433deff           call 0x7a79a0
// 009c45ac  33c9                 xor ecx, ecx
// 009c45ae  83c404               add esp, 4
// 009c45b1  3bc1                 cmp eax, ecx
// 009c45b3  7408                 je 0x9c45bd
// 009c45b5  c7004c1cc000         mov dword ptr [eax], 0xc01c4c
// 009c45bb  eb02                 jmp 0x9c45bf
// 009c45bd  33c0                 xor eax, eax
// 009c45bf  a34c1cc000           mov dword ptr [0xc01c4c], eax
// 009c45c4  6840bc9d00           push 0x9dbc40
// 009c45c9  890d581cc000         mov dword ptr [0xc01c58], ecx
// 009c45cf  890d5c1cc000         mov dword ptr [0xc01c5c], ecx
// 009c45d5  890d601cc000         mov dword ptr [0xc01c60], ecx
// 009c45db  e88344deff           call 0x7a8a63
// 009c45e0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 009c45e4  64890d00000000       mov dword ptr fs:[0], ecx
// 009c45eb  83c410               add esp, 0x10
// 009c45ee  c3                   ret 
// library ogre-1.6.4/OgreConvexBody.cpp (function ??__E?msFreePolygons@ConvexBody@Ogre@@1V?$vector@PAVPolygon@Ogre@@V?$allocator@PAVPolygon@Ogre@@@std@@@std@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreConvexBody.cpp
