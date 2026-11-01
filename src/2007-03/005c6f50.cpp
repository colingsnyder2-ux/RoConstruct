// from server: 100% by auto
// roc 2007-03 005c6f50  unit: seg_005c0000  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6f50
//
// 005c6f50  56                   push esi
// 005c6f51  8b742408             mov esi, dword ptr [esp + 8]
// 005c6f55  6a01                 push 1
// 005c6f57  56                   push esi
// 005c6f58  e83336ffff           call 0x5ba590
// 005c6f5d  83c408               add esp, 8
// 005c6f60  6a00                 push 0
// 005c6f62  6aff                 push -1
// 005c6f64  56                   push esi
// 005c6f65  e8e61affff           call 0x5b8a50
// 005c6f6a  83c404               add esp, 4
// 005c6f6d  83e801               sub eax, 1
// 005c6f70  50                   push eax
// 005c6f71  56                   push esi
// 005c6f72  e84928ffff           call 0x5b97c0
// 005c6f77  33c9                 xor ecx, ecx
// 005c6f79  85c0                 test eax, eax
// 005c6f7b  0f94c1               sete cl
// 005c6f7e  51                   push ecx
// 005c6f7f  56                   push esi
// 005c6f80  e8ab22ffff           call 0x5b9230
// 005c6f85  6a01                 push 1
// 005c6f87  56                   push esi
// 005c6f88  e8731bffff           call 0x5b8b00
// 005c6f8d  56                   push esi
// 005c6f8e  e8bd1affff           call 0x5b8a50
// 005c6f93  83c424               add esp, 0x24
// 005c6f96  5e                   pop esi
// 005c6f97  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_pcall)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
