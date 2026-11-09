// from server: 100% by auto
// roc 2012-06 00936180  unit: RBX::BallCellContact  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00936180
//
// 00936180  83ec10               sub esp, 0x10
// 00936183  56                   push esi
// 00936184  8b742420             mov esi, dword ptr [esp + 0x20]
// 00936188  57                   push edi
// 00936189  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0093618d  56                   push esi
// 0093618e  57                   push edi
// 0093618f  e8ecf8ffff           call 0x935a80
// 00936194  83c408               add esp, 8
// 00936197  3d202dbd00           cmp eax, 0xbd2d20
// 0093619c  751f                 jne 0x9361bd
// 0093619e  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 009361a2  8d442408             lea eax, [esp + 8]
// 009361a6  50                   push eax
// 009361a7  57                   push edi
// 009361a8  51                   push ecx
// 009361a9  89742414             mov dword ptr [esp + 0x14], esi
// 009361ad  c744241c04000000     mov dword ptr [esp + 0x1c], 4
// 009361b5  e8d6feffff           call 0x936090
// 009361ba  83c40c               add esp, 0xc
// 009361bd  5f                   pop edi
// 009361be  5e                   pop esi
// 009361bf  83c410               add esp, 0x10
// 009361c2  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_setstr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
