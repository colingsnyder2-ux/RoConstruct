// from server: 100% by auto
// roc 2007-08 00612630  unit: seg_00610000  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00612630
//
// 00612630  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00612634  83ec10               sub esp, 0x10
// 00612637  56                   push esi
// 00612638  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0061263c  50                   push eax
// 0061263d  56                   push esi
// 0061263e  e8fdfdffff           call 0x612440
// 00612643  83c408               add esp, 8
// 00612646  3de82f7c00           cmp eax, 0x7c2fe8
// 0061264b  7523                 jne 0x612670
// 0061264d  db442420             fild dword ptr [esp + 0x20]
// 00612651  8b542418             mov edx, dword ptr [esp + 0x18]
// 00612655  8d4c2404             lea ecx, [esp + 4]
// 00612659  51                   push ecx
// 0061265a  56                   push esi
// 0061265b  dd5c240c             fstp qword ptr [esp + 0xc]
// 0061265f  52                   push edx
// 00612660  c744241803000000     mov dword ptr [esp + 0x18], 3
// 00612668  e863040000           call 0x612ad0
// 0061266d  83c40c               add esp, 0xc
// 00612670  5e                   pop esi
// 00612671  83c410               add esp, 0x10
// 00612674  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_setnum)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
