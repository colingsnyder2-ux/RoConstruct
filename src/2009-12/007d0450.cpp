// from server: 100% by auto
// roc 2009-12 007d0450  unit: RBX::PartDropTool  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d0450
//
// 007d0450  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007d0454  83ec10               sub esp, 0x10
// 007d0457  56                   push esi
// 007d0458  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 007d045c  50                   push eax
// 007d045d  56                   push esi
// 007d045e  e8edfdffff           call 0x7d0250
// 007d0463  83c408               add esp, 8
// 007d0466  3d28aa9e00           cmp eax, 0x9eaa28
// 007d046b  7523                 jne 0x7d0490
// 007d046d  db442420             fild dword ptr [esp + 0x20]
// 007d0471  8b542418             mov edx, dword ptr [esp + 0x18]
// 007d0475  8d4c2404             lea ecx, [esp + 4]
// 007d0479  51                   push ecx
// 007d047a  56                   push esi
// 007d047b  dd5c240c             fstp qword ptr [esp + 0xc]
// 007d047f  52                   push edx
// 007d0480  c744241803000000     mov dword ptr [esp + 0x18], 3
// 007d0488  e863040000           call 0x7d08f0
// 007d048d  83c40c               add esp, 0xc
// 007d0490  5e                   pop esi
// 007d0491  83c410               add esp, 0x10
// 007d0494  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_setnum)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
