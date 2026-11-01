// from server: 100% by auto
// roc 2007-03 005fbfe0  unit: seg_005f0000  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fbfe0
//
// 005fbfe0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005fbfe4  83ec10               sub esp, 0x10
// 005fbfe7  56                   push esi
// 005fbfe8  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 005fbfec  50                   push eax
// 005fbfed  56                   push esi
// 005fbfee  e8fdfdffff           call 0x5fbdf0
// 005fbff3  83c408               add esp, 8
// 005fbff6  3da0007c00           cmp eax, 0x7c00a0
// 005fbffb  7523                 jne 0x5fc020
// 005fbffd  db442420             fild dword ptr [esp + 0x20]
// 005fc001  8b542418             mov edx, dword ptr [esp + 0x18]
// 005fc005  8d4c2404             lea ecx, [esp + 4]
// 005fc009  51                   push ecx
// 005fc00a  56                   push esi
// 005fc00b  dd5c240c             fstp qword ptr [esp + 0xc]
// 005fc00f  52                   push edx
// 005fc010  c744241803000000     mov dword ptr [esp + 0x18], 3
// 005fc018  e863040000           call 0x5fc480
// 005fc01d  83c40c               add esp, 0xc
// 005fc020  5e                   pop esi
// 005fc021  83c410               add esp, 0x10
// 005fc024  c3                   ret 
// library lua-5.1.1/ltable.c (function _luaH_setnum)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
