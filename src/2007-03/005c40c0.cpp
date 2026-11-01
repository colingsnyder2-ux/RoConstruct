// from server: 100% by auto
// roc 2007-03 005c40c0  unit: seg_005c0000  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c40c0
//
// 005c40c0  56                   push esi
// 005c40c1  8b742408             mov esi, dword ptr [esp + 8]
// 005c40c5  57                   push edi
// 005c40c6  6a05                 push 5
// 005c40c8  6a01                 push 1
// 005c40ca  56                   push esi
// 005c40cb  e87064ffff           call 0x5ba540
// 005c40d0  6a01                 push 1
// 005c40d2  56                   push esi
// 005c40d3  e8e84dffff           call 0x5b8ec0
// 005c40d8  68ac497800           push 0x7849ac
// 005c40dd  6a28                 push 0x28
// 005c40df  56                   push esi
// 005c40e0  8bf8                 mov edi, eax
// 005c40e2  e8f95affff           call 0x5b9be0
// 005c40e7  6a02                 push 2
// 005c40e9  56                   push esi
// 005c40ea  e8514bffff           call 0x5b8c40
// 005c40ef  83c428               add esp, 0x28
// 005c40f2  85c0                 test eax, eax
// 005c40f4  7e0d                 jle 0x5c4103
// 005c40f6  6a06                 push 6
// 005c40f8  6a02                 push 2
// 005c40fa  56                   push esi
// 005c40fb  e84064ffff           call 0x5ba540
// 005c4100  83c40c               add esp, 0xc
// 005c4103  6a02                 push 2
// 005c4105  56                   push esi
// 005c4106  e85549ffff           call 0x5b8a60
// 005c410b  57                   push edi
// 005c410c  6a01                 push 1
// 005c410e  56                   push esi
// 005c410f  e8acfbffff           call 0x5c3cc0
// 005c4114  83c414               add esp, 0x14
// 005c4117  5f                   pop edi
// 005c4118  33c0                 xor eax, eax
// 005c411a  5e                   pop esi
// 005c411b  c3                   ret 
// library lua-5.1.1/ltablib.c (function _sort)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltablib.c
