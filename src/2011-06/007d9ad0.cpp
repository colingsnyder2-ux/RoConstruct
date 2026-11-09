// from server: 100% by auto
// roc 2011-06 007d9ad0  unit: seg_007d0000  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007d9ad0
//
// 007d9ad0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007d9ad4  83ec10               sub esp, 0x10
// 007d9ad7  56                   push esi
// 007d9ad8  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 007d9adc  50                   push eax
// 007d9add  56                   push esi
// 007d9ade  e8edfdffff           call 0x7d98d0
// 007d9ae3  83c408               add esp, 8
// 007d9ae6  3db875ab00           cmp eax, 0xab75b8
// 007d9aeb  7523                 jne 0x7d9b10
// 007d9aed  db442420             fild dword ptr [esp + 0x20]
// 007d9af1  8b542418             mov edx, dword ptr [esp + 0x18]
// 007d9af5  8d4c2404             lea ecx, [esp + 4]
// 007d9af9  51                   push ecx
// 007d9afa  56                   push esi
// 007d9afb  dd5c240c             fstp qword ptr [esp + 0xc]
// 007d9aff  52                   push edx
// 007d9b00  c744241803000000     mov dword ptr [esp + 0x18], 3
// 007d9b08  e873040000           call 0x7d9f80
// 007d9b0d  83c40c               add esp, 0xc
// 007d9b10  5e                   pop esi
// 007d9b11  83c410               add esp, 0x10
// 007d9b14  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_setnum)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
