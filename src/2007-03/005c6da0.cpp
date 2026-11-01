// from server: 100% by auto
// roc 2007-03 005c6da0  unit: seg_005c0000  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6da0
//
// 005c6da0  53                   push ebx
// 005c6da1  56                   push esi
// 005c6da2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005c6da6  57                   push edi
// 005c6da7  6a00                 push 0
// 005c6da9  6a00                 push 0
// 005c6dab  6a01                 push 1
// 005c6dad  56                   push esi
// 005c6dae  e86d38ffff           call 0x5ba620
// 005c6db3  56                   push esi
// 005c6db4  8bf8                 mov edi, eax
// 005c6db6  e8951cffff           call 0x5b8a50
// 005c6dbb  57                   push edi
// 005c6dbc  56                   push esi
// 005c6dbd  8bd8                 mov ebx, eax
// 005c6dbf  e8cc33ffff           call 0x5ba190
// 005c6dc4  83c41c               add esp, 0x1c
// 005c6dc7  85c0                 test eax, eax
// 005c6dc9  7409                 je 0x5c6dd4
// 005c6dcb  56                   push esi
// 005c6dcc  e8df2bffff           call 0x5b99b0
// 005c6dd1  83c404               add esp, 4
// 005c6dd4  6aff                 push -1
// 005c6dd6  6a00                 push 0
// 005c6dd8  56                   push esi
// 005c6dd9  e88229ffff           call 0x5b9760
// 005c6dde  56                   push esi
// 005c6ddf  e86c1cffff           call 0x5b8a50
// 005c6de4  83c410               add esp, 0x10
// 005c6de7  5f                   pop edi
// 005c6de8  5e                   pop esi
// 005c6de9  2bc3                 sub eax, ebx
// 005c6deb  5b                   pop ebx
// 005c6dec  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_dofile)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
