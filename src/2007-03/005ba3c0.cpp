// from server: 100% by auto
// roc 2007-03 005ba3c0  unit: seg_005b0000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ba3c0
//
// 005ba3c0  83ec08               sub esp, 8
// 005ba3c3  8b442410             mov eax, dword ptr [esp + 0x10]
// 005ba3c7  8b542418             mov edx, dword ptr [esp + 0x18]
// 005ba3cb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005ba3cf  52                   push edx
// 005ba3d0  89442404             mov dword ptr [esp + 4], eax
// 005ba3d4  8d442404             lea eax, [esp + 4]
// 005ba3d8  50                   push eax
// 005ba3d9  894c240c             mov dword ptr [esp + 0xc], ecx
// 005ba3dd  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005ba3e1  68a0a35b00           push 0x5ba3a0
// 005ba3e6  51                   push ecx
// 005ba3e7  e844f4ffff           call 0x5b9830
// 005ba3ec  83c418               add esp, 0x18
// 005ba3ef  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_loadbuffer)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
