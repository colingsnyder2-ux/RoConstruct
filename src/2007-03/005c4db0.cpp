// from server: 100% by auto
// roc 2007-03 005c4db0  unit: seg_005c0000  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c4db0
//
// 005c4db0  81ec0c020000         sub esp, 0x20c
// 005c4db6  56                   push esi
// 005c4db7  8bb42414020000       mov esi, dword ptr [esp + 0x214]
// 005c4dbe  6a06                 push 6
// 005c4dc0  6a01                 push 1
// 005c4dc2  56                   push esi
// 005c4dc3  e87857ffff           call 0x5ba540
// 005c4dc8  6a01                 push 1
// 005c4dca  56                   push esi
// 005c4dcb  e8903cffff           call 0x5b8a60
// 005c4dd0  8d442418             lea eax, [esp + 0x18]
// 005c4dd4  50                   push eax
// 005c4dd5  56                   push esi
// 005c4dd6  e8d551ffff           call 0x5b9fb0
// 005c4ddb  8d4c2420             lea ecx, [esp + 0x20]
// 005c4ddf  51                   push ecx
// 005c4de0  68904d5c00           push 0x5c4d90
// 005c4de5  56                   push esi
// 005c4de6  e8854affff           call 0x5b9870
// 005c4deb  83c428               add esp, 0x28
// 005c4dee  85c0                 test eax, eax
// 005c4df0  740e                 je 0x5c4e00
// 005c4df2  68489f7b00           push 0x7b9f48
// 005c4df7  56                   push esi
// 005c4df8  e8534dffff           call 0x5b9b50
// 005c4dfd  83c408               add esp, 8
// 005c4e00  8d542404             lea edx, [esp + 4]
// 005c4e04  52                   push edx
// 005c4e05  e8d650ffff           call 0x5b9ee0
// 005c4e0a  83c404               add esp, 4
// 005c4e0d  b801000000           mov eax, 1
// 005c4e12  5e                   pop esi
// 005c4e13  81c40c020000         add esp, 0x20c
// 005c4e19  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _str_dump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
