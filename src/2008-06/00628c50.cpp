// from server: 100% by auto
// roc 2008-06 00628c50  unit: seg_00620000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00628c50
//
// 00628c50  56                   push esi
// 00628c51  57                   push edi
// 00628c52  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00628c56  68edd8ffff           push 0xffffd8ed
// 00628c5b  57                   push edi
// 00628c5c  e8ef94feff           call 0x612150
// 00628c61  57                   push edi
// 00628c62  8bf0                 mov esi, eax
// 00628c64  e8a78ffeff           call 0x611c10
// 00628c69  83c40c               add esp, 0xc
// 00628c6c  e8affeffff           call 0x628b20
// 00628c71  8bf0                 mov esi, eax
// 00628c73  85f6                 test esi, esi
// 00628c75  7d35                 jge 0x628cac
// 00628c77  6aff                 push -1
// 00628c79  57                   push edi
// 00628c7a  e83192feff           call 0x611eb0
// 00628c7f  83c408               add esp, 8
// 00628c82  85c0                 test eax, eax
// 00628c84  741b                 je 0x628ca1
// 00628c86  6a01                 push 1
// 00628c88  57                   push edi
// 00628c89  e8627ffeff           call 0x610bf0
// 00628c8e  6afe                 push -2
// 00628c90  57                   push edi
// 00628c91  e82a90feff           call 0x611cc0
// 00628c96  6a02                 push 2
// 00628c98  57                   push edi
// 00628c99  e8229ffeff           call 0x612bc0
// 00628c9e  83c418               add esp, 0x18
// 00628ca1  57                   push edi
// 00628ca2  e8c99efeff           call 0x612b70
// 00628ca7  83c404               add esp, 4
// 00628caa  8bc6                 mov eax, esi
// 00628cac  5f                   pop edi
// 00628cad  5e                   pop esi
// 00628cae  c3                   ret 
// library lua-5.1.2/lbaselib.c (function _luaB_auxwrap)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lbaselib.c
