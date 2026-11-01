// from server: 100% by auto
// roc 2009-12 00969820  unit: seg_00960000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00969820
//
// 00969820  64a100000000         mov eax, dword ptr fs:[0]
// 00969826  6aff                 push -1
// 00969828  68eab59200           push 0x92b5ea
// 0096982d  50                   push eax
// 0096982e  64892500000000       mov dword ptr fs:[0], esp
// 00969835  6a04                 push 4
// 00969837  e824a0e8ff           call 0x7f3860
// 0096983c  33c9                 xor ecx, ecx
// 0096983e  83c404               add esp, 4
// 00969841  3bc1                 cmp eax, ecx
// 00969843  7408                 je 0x96984d
// 00969845  c700a4b7b700         mov dword ptr [eax], 0xb7b7a4
// 0096984b  eb02                 jmp 0x96984f
// 0096984d  33c0                 xor eax, eax
// 0096984f  a3a4b7b700           mov dword ptr [0xb7b7a4], eax
// 00969854  6840ea9700           push 0x97ea40
// 00969859  890db0b7b700         mov dword ptr [0xb7b7b0], ecx
// 0096985f  890db4b7b700         mov dword ptr [0xb7b7b4], ecx
// 00969865  890db8b7b700         mov dword ptr [0xb7b7b8], ecx
// 0096986b  e8b9b0e8ff           call 0x7f4929
// 00969870  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00969874  64890d00000000       mov dword ptr fs:[0], ecx
// 0096987b  83c410               add esp, 0x10
// 0096987e  c3                   ret 
// library ogre-1.6.4/OgreConvexBody.cpp (function ??__E?msFreePolygons@ConvexBody@Ogre@@1V?$vector@PAVPolygon@Ogre@@V?$allocator@PAVPolygon@Ogre@@@std@@@std@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreConvexBody.cpp
