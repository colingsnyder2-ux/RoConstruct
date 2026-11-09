// from server: 100% by auto
// roc 2008-06 00628d60  unit: seg_00620000  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00628d60
//
// 00628d60  83ec64               sub esp, 0x64
// 00628d63  56                   push esi
// 00628d64  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00628d68  57                   push edi
// 00628d69  6a01                 push 1
// 00628d6b  56                   push esi
// 00628d6c  e8df93feff           call 0x612150
// 00628d71  8bf8                 mov edi, eax
// 00628d73  83c408               add esp, 8
// 00628d76  85ff                 test edi, edi
// 00628d78  7510                 jne 0x628d8a
// 00628d7a  6860578400           push 0x845760
// 00628d7f  6a01                 push 1
// 00628d81  56                   push esi
// 00628d82  e84987feff           call 0x6114d0
// 00628d87  83c40c               add esp, 0xc
// 00628d8a  3bf7                 cmp esi, edi
// 00628d8c  751b                 jne 0x628da9
// 00628d8e  6a07                 push 7
// 00628d90  6830538400           push 0x845330
// 00628d95  56                   push esi
// 00628d96  e8a594feff           call 0x612240
// 00628d9b  83c40c               add esp, 0xc
// 00628d9e  5f                   pop edi
// 00628d9f  b801000000           mov eax, 1
// 00628da4  5e                   pop esi
// 00628da5  83c464               add esp, 0x64
// 00628da8  c3                   ret 
// 00628da9  57                   push edi
// 00628daa  e8c19cfeff           call 0x612a70
// 00628daf  83c404               add esp, 4
// 00628db2  83e800               sub eax, 0
// 00628db5  7420                 je 0x628dd7
// 00628db7  83e801               sub eax, 1
// 00628dba  7457                 je 0x628e13
// 00628dbc  6a04                 push 4
// 00628dbe  68a0578400           push 0x8457a0
// 00628dc3  56                   push esi
// 00628dc4  e87794feff           call 0x612240
// 00628dc9  83c40c               add esp, 0xc
// 00628dcc  5f                   pop edi
// 00628dcd  b801000000           mov eax, 1
// 00628dd2  5e                   pop esi
// 00628dd3  83c464               add esp, 0x64
// 00628dd6  c3                   ret 
// 00628dd7  8d442408             lea eax, [esp + 8]
// 00628ddb  50                   push eax
// 00628ddc  6a00                 push 0
// 00628dde  57                   push edi
// 00628ddf  e8fc9effff           call 0x622ce0
// 00628de4  83c40c               add esp, 0xc
// 00628de7  85c0                 test eax, eax
// 00628de9  7e1b                 jle 0x628e06
// 00628deb  6a06                 push 6
// 00628ded  6898578400           push 0x845798
// 00628df2  56                   push esi
// 00628df3  e84894feff           call 0x612240
// 00628df8  83c40c               add esp, 0xc
// 00628dfb  5f                   pop edi
// 00628dfc  b801000000           mov eax, 1
// 00628e01  5e                   pop esi
// 00628e02  83c464               add esp, 0x64
// 00628e05  c3                   ret 
// 00628e06  57                   push edi
// 00628e07  e8048efeff           call 0x611c10
// 00628e0c  83c404               add esp, 4
// 00628e0f  85c0                 test eax, eax
// 00628e11  74a9                 je 0x628dbc
// 00628e13  6a09                 push 9
// 00628e15  688c578400           push 0x84578c
// 00628e1a  56                   push esi
// 00628e1b  e82094feff           call 0x612240
// 00628e20  83c40c               add esp, 0xc
// 00628e23  5f                   pop edi
// 00628e24  b801000000           mov eax, 1
// 00628e29  5e                   pop esi
// 00628e2a  83c464               add esp, 0x64
// 00628e2d  c3                   ret 
// library lua-5.1.2/lbaselib.c (function _luaB_costatus)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lbaselib.c
