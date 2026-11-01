// from server: 100% by auto
// roc 2007-03 005c3390  unit: seg_005c0000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c3390
//
// 005c3390  83ec10               sub esp, 0x10
// 005c3393  56                   push esi
// 005c3394  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 005c3398  8d442404             lea eax, [esp + 4]
// 005c339c  50                   push eax
// 005c339d  56                   push esi
// 005c339e  e8dd660300           call 0x5f9a80
// 005c33a3  83c408               add esp, 8
// 005c33a6  85c0                 test eax, eax
// 005c33a8  8bc6                 mov eax, esi
// 005c33aa  7404                 je 0x5c33b0
// 005c33ac  8b442420             mov eax, dword ptr [esp + 0x20]
// 005c33b0  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005c33b4  68c49a7b00           push 0x7b9ac4
// 005c33b9  50                   push eax
// 005c33ba  51                   push ecx
// 005c33bb  e820ffffff           call 0x5c32e0
// 005c33c0  83c40c               add esp, 0xc
// 005c33c3  5e                   pop esi
// 005c33c4  83c410               add esp, 0x10
// 005c33c7  c3                   ret 
// library lua-5.1.1/ldebug.c (function _luaG_aritherror)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c
