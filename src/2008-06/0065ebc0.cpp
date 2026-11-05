// from server: 100% by auto
// roc 2008-06 0065ebc0  unit: seg_00650000  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065ebc0
//
// 0065ebc0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0065ebc4  83ec10               sub esp, 0x10
// 0065ebc7  56                   push esi
// 0065ebc8  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0065ebcc  50                   push eax
// 0065ebcd  56                   push esi
// 0065ebce  e8fdfdffff           call 0x65e9d0
// 0065ebd3  83c408               add esp, 8
// 0065ebd6  3d80488400           cmp eax, 0x844880
// 0065ebdb  7523                 jne 0x65ec00
// 0065ebdd  db442420             fild dword ptr [esp + 0x20]
// 0065ebe1  8b542418             mov edx, dword ptr [esp + 0x18]
// 0065ebe5  8d4c2404             lea ecx, [esp + 4]
// 0065ebe9  51                   push ecx
// 0065ebea  56                   push esi
// 0065ebeb  dd5c240c             fstp qword ptr [esp + 0xc]
// 0065ebef  52                   push edx
// 0065ebf0  c744241803000000     mov dword ptr [esp + 0x18], 3
// 0065ebf8  e863040000           call 0x65f060
// 0065ebfd  83c40c               add esp, 0xc
// 0065ec00  5e                   pop esi
// 0065ec01  83c410               add esp, 0x10
// 0065ec04  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_setnum)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
