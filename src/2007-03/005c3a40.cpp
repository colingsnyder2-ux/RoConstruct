// from server: 100% by auto
// roc 2007-03 005c3a40  unit: seg_005c0000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c3a40
//
// 005c3a40  56                   push esi
// 005c3a41  8b742408             mov esi, dword ptr [esp + 8]
// 005c3a45  6a05                 push 5
// 005c3a47  6a01                 push 1
// 005c3a49  56                   push esi
// 005c3a4a  e8f16affff           call 0x5ba540
// 005c3a4f  6a01                 push 1
// 005c3a51  56                   push esi
// 005c3a52  e86954ffff           call 0x5b8ec0
// 005c3a57  50                   push eax
// 005c3a58  56                   push esi
// 005c3a59  e80256ffff           call 0x5b9060
// 005c3a5e  83c41c               add esp, 0x1c
// 005c3a61  b801000000           mov eax, 1
// 005c3a66  5e                   pop esi
// 005c3a67  c3                   ret 
// library lua-5.1.1/ltablib.c (function _getn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltablib.c
