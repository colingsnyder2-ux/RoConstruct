// from server: 100% by auto
// roc 2007-03 005c74e0  unit: seg_005c0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c74e0
//
// 005c74e0  8b442404             mov eax, dword ptr [esp + 4]
// 005c74e4  50                   push eax
// 005c74e5  e8861dffff           call 0x5b9270
// 005c74ea  83c404               add esp, 4
// 005c74ed  f7d8                 neg eax
// 005c74ef  1bc0                 sbb eax, eax
// 005c74f1  83c001               add eax, 1
// 005c74f4  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_corunning)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
