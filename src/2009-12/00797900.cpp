// from server: 100% by auto
// roc 2009-12 00797900  unit: lua_exception  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00797900
//
// 00797900  8b4630               mov eax, dword ptr [esi + 0x30]
// 00797903  3d204e0000           cmp eax, 0x4e20
// 00797908  7e08                 jle 0x797912
// 0079790a  6a05                 push 5
// 0079790c  56                   push esi
// 0079790d  e83effffff           call 0x797850
// 00797912  03c0                 add eax, eax
// 00797914  50                   push eax
// 00797915  56                   push esi
// 00797916  e895f9ffff           call 0x7972b0
// 0079791b  83c408               add esp, 8
// 0079791e  817e30204e0000       cmp dword ptr [esi + 0x30], 0x4e20
// 00797925  7e0e                 jle 0x797935
// 00797927  68d4a99e00           push 0x9ea9d4
// 0079792c  56                   push esi
// 0079792d  e80e3a0000           call 0x79b340
// 00797932  83c408               add esp, 8
// 00797935  83461418             add dword ptr [esi + 0x14], 0x18
// 00797939  8b4614               mov eax, dword ptr [esi + 0x14]
// 0079793c  c3                   ret 
// library lua-5.1/ldo.c (function _growCI)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldo.c
