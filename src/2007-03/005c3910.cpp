// from server: 100% by auto
// roc 2007-03 005c3910  unit: seg_005c0000  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c3910
//
// 005c3910  56                   push esi
// 005c3911  8b742408             mov esi, dword ptr [esp + 8]
// 005c3915  6a05                 push 5
// 005c3917  6a01                 push 1
// 005c3919  56                   push esi
// 005c391a  e8216cffff           call 0x5ba540
// 005c391f  6a06                 push 6
// 005c3921  6a02                 push 2
// 005c3923  56                   push esi
// 005c3924  e8176cffff           call 0x5ba540
// 005c3929  56                   push esi
// 005c392a  e8f156ffff           call 0x5b9020
// 005c392f  6a01                 push 1
// 005c3931  56                   push esi
// 005c3932  e88960ffff           call 0x5b99c0
// 005c3937  83c424               add esp, 0x24
// 005c393a  85c0                 test eax, eax
// 005c393c  744a                 je 0x5c3988
// 005c393e  8bff                 mov edi, edi
// 005c3940  6a02                 push 2
// 005c3942  56                   push esi
// 005c3943  e8c852ffff           call 0x5b8c10
// 005c3948  6afd                 push -3
// 005c394a  56                   push esi
// 005c394b  e8c052ffff           call 0x5b8c10
// 005c3950  6afd                 push -3
// 005c3952  56                   push esi
// 005c3953  e8b852ffff           call 0x5b8c10
// 005c3958  6a01                 push 1
// 005c395a  6a02                 push 2
// 005c395c  56                   push esi
// 005c395d  e8fe5dffff           call 0x5b9760
// 005c3962  6aff                 push -1
// 005c3964  56                   push esi
// 005c3965  e8d652ffff           call 0x5b8c40
// 005c396a  83c42c               add esp, 0x2c
// 005c396d  85c0                 test eax, eax
// 005c396f  751b                 jne 0x5c398c
// 005c3971  6afd                 push -3
// 005c3973  56                   push esi
// 005c3974  e8e750ffff           call 0x5b8a60
// 005c3979  6a01                 push 1
// 005c397b  56                   push esi
// 005c397c  e83f60ffff           call 0x5b99c0
// 005c3981  83c410               add esp, 0x10
// 005c3984  85c0                 test eax, eax
// 005c3986  75b8                 jne 0x5c3940
// 005c3988  33c0                 xor eax, eax
// 005c398a  5e                   pop esi
// 005c398b  c3                   ret 
// 005c398c  b801000000           mov eax, 1
// 005c3991  5e                   pop esi
// 005c3992  c3                   ret 
// library lua-5.1.1/ltablib.c (function _foreach)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltablib.c
