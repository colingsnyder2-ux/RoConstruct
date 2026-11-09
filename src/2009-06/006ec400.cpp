// from server: 100% by auto
// roc 2009-06 006ec400  unit: RBX::PartDropTool  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006ec400
//
// 006ec400  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006ec404  83ec10               sub esp, 0x10
// 006ec407  56                   push esi
// 006ec408  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 006ec40c  50                   push eax
// 006ec40d  56                   push esi
// 006ec40e  e8fdfdffff           call 0x6ec210
// 006ec413  83c408               add esp, 8
// 006ec416  3d78c38e00           cmp eax, 0x8ec378
// 006ec41b  7523                 jne 0x6ec440
// 006ec41d  db442420             fild dword ptr [esp + 0x20]
// 006ec421  8b542418             mov edx, dword ptr [esp + 0x18]
// 006ec425  8d4c2404             lea ecx, [esp + 4]
// 006ec429  51                   push ecx
// 006ec42a  56                   push esi
// 006ec42b  dd5c240c             fstp qword ptr [esp + 0xc]
// 006ec42f  52                   push edx
// 006ec430  c744241803000000     mov dword ptr [esp + 0x18], 3
// 006ec438  e863040000           call 0x6ec8a0
// 006ec43d  83c40c               add esp, 0xc
// 006ec440  5e                   pop esi
// 006ec441  83c410               add esp, 0x10
// 006ec444  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_setnum)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
