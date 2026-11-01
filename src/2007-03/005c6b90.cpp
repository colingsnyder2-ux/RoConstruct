// from server: 100% by auto
// roc 2007-03 005c6b90  unit: seg_005c0000  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6b90
//
// 005c6b90  56                   push esi
// 005c6b91  8b742408             mov esi, dword ptr [esp + 8]
// 005c6b95  57                   push edi
// 005c6b96  6a02                 push 2
// 005c6b98  56                   push esi
// 005c6b99  e8623bffff           call 0x5ba700
// 005c6b9e  6a05                 push 5
// 005c6ba0  6a01                 push 1
// 005c6ba2  56                   push esi
// 005c6ba3  8bf8                 mov edi, eax
// 005c6ba5  e89639ffff           call 0x5ba540
// 005c6baa  83c701               add edi, 1
// 005c6bad  57                   push edi
// 005c6bae  56                   push esi
// 005c6baf  e8ac24ffff           call 0x5b9060
// 005c6bb4  57                   push edi
// 005c6bb5  6a01                 push 1
// 005c6bb7  56                   push esi
// 005c6bb8  e8b327ffff           call 0x5b9370
// 005c6bbd  6aff                 push -1
// 005c6bbf  56                   push esi
// 005c6bc0  e87b20ffff           call 0x5b8c40
// 005c6bc5  83c430               add esp, 0x30
// 005c6bc8  f7d8                 neg eax
// 005c6bca  1bc0                 sbb eax, eax
// 005c6bcc  5f                   pop edi
// 005c6bcd  83e002               and eax, 2
// 005c6bd0  5e                   pop esi
// 005c6bd1  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _ipairsaux)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
