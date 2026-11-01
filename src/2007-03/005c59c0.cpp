// from server: 100% by auto
// roc 2007-03 005c59c0  unit: seg_005c0000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c59c0
//
// 005c59c0  53                   push ebx
// 005c59c1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005c59c5  6a01                 push 1
// 005c59c7  e844feffff           call 0x5c5810
// 005c59cc  83c404               add esp, 4
// 005c59cf  5b                   pop ebx
// 005c59d0  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _str_find)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
