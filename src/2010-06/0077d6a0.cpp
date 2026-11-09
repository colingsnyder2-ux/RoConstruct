// from server: 100% by auto
// roc 2010-06 0077d6a0  unit: RBX::PartDropTool  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0077d6a0
//
// 0077d6a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0077d6a4  83ec10               sub esp, 0x10
// 0077d6a7  56                   push esi
// 0077d6a8  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0077d6ac  50                   push eax
// 0077d6ad  56                   push esi
// 0077d6ae  e8edfdffff           call 0x77d4a0
// 0077d6b3  83c408               add esp, 8
// 0077d6b6  3d78dca400           cmp eax, 0xa4dc78
// 0077d6bb  7523                 jne 0x77d6e0
// 0077d6bd  db442420             fild dword ptr [esp + 0x20]
// 0077d6c1  8b542418             mov edx, dword ptr [esp + 0x18]
// 0077d6c5  8d4c2404             lea ecx, [esp + 4]
// 0077d6c9  51                   push ecx
// 0077d6ca  56                   push esi
// 0077d6cb  dd5c240c             fstp qword ptr [esp + 0xc]
// 0077d6cf  52                   push edx
// 0077d6d0  c744241803000000     mov dword ptr [esp + 0x18], 3
// 0077d6d8  e863040000           call 0x77db40
// 0077d6dd  83c40c               add esp, 0xc
// 0077d6e0  5e                   pop esi
// 0077d6e1  83c410               add esp, 0x10
// 0077d6e4  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_setnum)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
