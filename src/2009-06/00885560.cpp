// from server: 100% by auto
// roc 2009-06 00885560  unit: seg_00880000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00885560
//
// 00885560  64a100000000         mov eax, dword ptr fs:[0]
// 00885566  6aff                 push -1
// 00885568  680a0e8500           push 0x850e0a
// 0088556d  50                   push eax
// 0088556e  64892500000000       mov dword ptr fs:[0], esp
// 00885575  6a04                 push 4
// 00885577  e8bc34e9ff           call 0x718a38
// 0088557c  33c9                 xor ecx, ecx
// 0088557e  83c404               add esp, 4
// 00885581  3bc1                 cmp eax, ecx
// 00885583  7408                 je 0x88558d
// 00885585  c7004cb3a300         mov dword ptr [eax], 0xa3b34c
// 0088558b  eb02                 jmp 0x88558f
// 0088558d  33c0                 xor eax, eax
// 0088558f  a34cb3a300           mov dword ptr [0xa3b34c], eax
// 00885594  68f04a8900           push 0x894af0
// 00885599  890d58b3a300         mov dword ptr [0xa3b358], ecx
// 0088559f  890d5cb3a300         mov dword ptr [0xa3b35c], ecx
// 008855a5  890d60b3a300         mov dword ptr [0xa3b360], ecx
// 008855ab  e84b45e9ff           call 0x719afb
// 008855b0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008855b4  64890d00000000       mov dword ptr fs:[0], ecx
// 008855bb  83c410               add esp, 0x10
// 008855be  c3                   ret 
// library ogre-1.6.4/OgreConvexBody.cpp (function ??__E?msFreePolygons@ConvexBody@Ogre@@1V?$vector@PAVPolygon@Ogre@@V?$allocator@PAVPolygon@Ogre@@@std@@@std@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreConvexBody.cpp
