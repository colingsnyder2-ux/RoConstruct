// from server: 100% by auto
// roc 2009-12 0079f350  unit: seg_00790000  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f350
//
// 0079f350  56                   push esi
// 0079f351  8b742408             mov esi, dword ptr [esp + 8]
// 0079f355  6a02                 push 2
// 0079f357  56                   push esi
// 0079f358  e8e3b3feff           call 0x78a740
// 0079f35d  6a02                 push 2
// 0079f35f  56                   push esi
// 0079f360  e84b94feff           call 0x7887b0
// 0079f365  6a01                 push 1
// 0079f367  56                   push esi
// 0079f368  e8e394feff           call 0x788850
// 0079f36d  6a01                 push 1
// 0079f36f  6aff                 push -1
// 0079f371  6a00                 push 0
// 0079f373  56                   push esi
// 0079f374  e8a7a1feff           call 0x789520
// 0079f379  33c9                 xor ecx, ecx
// 0079f37b  85c0                 test eax, eax
// 0079f37d  0f94c1               sete cl
// 0079f380  51                   push ecx
// 0079f381  56                   push esi
// 0079f382  e8c99bfeff           call 0x788f50
// 0079f387  6a01                 push 1
// 0079f389  56                   push esi
// 0079f38a  e81195feff           call 0x7888a0
// 0079f38f  56                   push esi
// 0079f390  e80b94feff           call 0x7887a0
// 0079f395  83c43c               add esp, 0x3c
// 0079f398  5e                   pop esi
// 0079f399  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_xpcall)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
