// from server: 100% by auto
// roc 2009-12 009697b0  unit: seg_00960000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009697b0
//
// 009697b0  64a100000000         mov eax, dword ptr fs:[0]
// 009697b6  6aff                 push -1
// 009697b8  682ab59200           push 0x92b52a
// 009697bd  50                   push eax
// 009697be  64892500000000       mov dword ptr fs:[0], esp
// 009697c5  6a04                 push 4
// 009697c7  e894a0e8ff           call 0x7f3860
// 009697cc  33c9                 xor ecx, ecx
// 009697ce  83c404               add esp, 4
// 009697d1  3bc1                 cmp eax, ecx
// 009697d3  7408                 je 0x9697dd
// 009697d5  c70084b6b700         mov dword ptr [eax], 0xb7b684
// 009697db  eb02                 jmp 0x9697df
// 009697dd  33c0                 xor eax, eax
// 009697df  a384b6b700           mov dword ptr [0xb7b684], eax
// 009697e4  6820ea9700           push 0x97ea20
// 009697e9  890d90b6b700         mov dword ptr [0xb7b690], ecx
// 009697ef  890d94b6b700         mov dword ptr [0xb7b694], ecx
// 009697f5  890d98b6b700         mov dword ptr [0xb7b698], ecx
// 009697fb  e829b1e8ff           call 0x7f4929
// 00969800  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00969804  64890d00000000       mov dword ptr fs:[0], ecx
// 0096980b  83c410               add esp, 0x10
// 0096980e  c3                   ret 
// library ogre-1.6.4/OgreConvexBody.cpp (function ??__E?msFreePolygons@ConvexBody@Ogre@@1V?$vector@PAVPolygon@Ogre@@V?$allocator@PAVPolygon@Ogre@@@std@@@std@@A@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreConvexBody.cpp
