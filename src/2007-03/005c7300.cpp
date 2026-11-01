// from server: 100% by auto
// roc 2007-03 005c7300  unit: seg_005c0000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c7300
//
// 005c7300  56                   push esi
// 005c7301  57                   push edi
// 005c7302  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005c7306  68edd8ffff           push 0xffffd8ed
// 005c730b  57                   push edi
// 005c730c  e87f1cffff           call 0x5b8f90
// 005c7311  57                   push edi
// 005c7312  8bf0                 mov esi, eax
// 005c7314  e83717ffff           call 0x5b8a50
// 005c7319  83c40c               add esp, 0xc
// 005c731c  e8affeffff           call 0x5c71d0
// 005c7321  8bf0                 mov esi, eax
// 005c7323  85f6                 test esi, esi
// 005c7325  7d35                 jge 0x5c735c
// 005c7327  6aff                 push -1
// 005c7329  57                   push edi
// 005c732a  e8c119ffff           call 0x5b8cf0
// 005c732f  83c408               add esp, 8
// 005c7332  85c0                 test eax, eax
// 005c7334  741b                 je 0x5c7351
// 005c7336  6a01                 push 1
// 005c7338  57                   push edi
// 005c7339  e8a227ffff           call 0x5b9ae0
// 005c733e  6afe                 push -2
// 005c7340  57                   push edi
// 005c7341  e8ba17ffff           call 0x5b8b00
// 005c7346  6a02                 push 2
// 005c7348  57                   push edi
// 005c7349  e8b226ffff           call 0x5b9a00
// 005c734e  83c418               add esp, 0x18
// 005c7351  57                   push edi
// 005c7352  e85926ffff           call 0x5b99b0
// 005c7357  83c404               add esp, 4
// 005c735a  8bc6                 mov eax, esi
// 005c735c  5f                   pop edi
// 005c735d  5e                   pop esi
// 005c735e  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_auxwrap)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
