// from server: 100% by auto
// roc 2012-06 00935be0  unit: RBX::BallCellContact  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00935be0
//
// 00935be0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00935be4  83ec10               sub esp, 0x10
// 00935be7  56                   push esi
// 00935be8  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00935bec  50                   push eax
// 00935bed  56                   push esi
// 00935bee  e8edfdffff           call 0x9359e0
// 00935bf3  83c408               add esp, 8
// 00935bf6  3d202dbd00           cmp eax, 0xbd2d20
// 00935bfb  7523                 jne 0x935c20
// 00935bfd  db442420             fild dword ptr [esp + 0x20]
// 00935c01  8b542418             mov edx, dword ptr [esp + 0x18]
// 00935c05  8d4c2404             lea ecx, [esp + 4]
// 00935c09  51                   push ecx
// 00935c0a  56                   push esi
// 00935c0b  dd5c240c             fstp qword ptr [esp + 0xc]
// 00935c0f  52                   push edx
// 00935c10  c744241803000000     mov dword ptr [esp + 0x18], 3
// 00935c18  e873040000           call 0x936090
// 00935c1d  83c40c               add esp, 0xc
// 00935c20  5e                   pop esi
// 00935c21  83c410               add esp, 0x10
// 00935c24  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_setnum)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
