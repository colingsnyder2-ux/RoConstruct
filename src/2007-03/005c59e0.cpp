// from server: 100% by auto
// roc 2007-03 005c59e0  unit: seg_005c0000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c59e0
//
// 005c59e0  53                   push ebx
// 005c59e1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005c59e5  6a00                 push 0
// 005c59e7  e824feffff           call 0x5c5810
// 005c59ec  83c404               add esp, 4
// 005c59ef  5b                   pop ebx
// 005c59f0  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _str_match)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
