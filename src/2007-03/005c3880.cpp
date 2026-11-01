// from server: 100% by auto
// roc 2007-03 005c3880  unit: seg_005c0000  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c3880
//
// 005c3880  53                   push ebx
// 005c3881  56                   push esi
// 005c3882  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005c3886  57                   push edi
// 005c3887  6a05                 push 5
// 005c3889  6a01                 push 1
// 005c388b  56                   push esi
// 005c388c  e8af6cffff           call 0x5ba540
// 005c3891  6a01                 push 1
// 005c3893  56                   push esi
// 005c3894  e82756ffff           call 0x5b8ec0
// 005c3899  6a06                 push 6
// 005c389b  6a02                 push 2
// 005c389d  56                   push esi
// 005c389e  8bd8                 mov ebx, eax
// 005c38a0  e89b6cffff           call 0x5ba540
// 005c38a5  bf01000000           mov edi, 1
// 005c38aa  83c420               add esp, 0x20
// 005c38ad  3bdf                 cmp ebx, edi
// 005c38af  7c43                 jl 0x5c38f4
// 005c38b1  6a02                 push 2
// 005c38b3  56                   push esi
// 005c38b4  e85753ffff           call 0x5b8c10
// 005c38b9  57                   push edi
// 005c38ba  56                   push esi
// 005c38bb  e8a057ffff           call 0x5b9060
// 005c38c0  57                   push edi
// 005c38c1  6a01                 push 1
// 005c38c3  56                   push esi
// 005c38c4  e8a75affff           call 0x5b9370
// 005c38c9  6a01                 push 1
// 005c38cb  6a02                 push 2
// 005c38cd  56                   push esi
// 005c38ce  e88d5effff           call 0x5b9760
// 005c38d3  6aff                 push -1
// 005c38d5  56                   push esi
// 005c38d6  e86553ffff           call 0x5b8c40
// 005c38db  83c430               add esp, 0x30
// 005c38de  85c0                 test eax, eax
// 005c38e0  7518                 jne 0x5c38fa
// 005c38e2  6afe                 push -2
// 005c38e4  56                   push esi
// 005c38e5  e87651ffff           call 0x5b8a60
// 005c38ea  83c701               add edi, 1
// 005c38ed  83c408               add esp, 8
// 005c38f0  3bfb                 cmp edi, ebx
// 005c38f2  7ebd                 jle 0x5c38b1
// 005c38f4  5f                   pop edi
// 005c38f5  5e                   pop esi
// 005c38f6  33c0                 xor eax, eax
// 005c38f8  5b                   pop ebx
// 005c38f9  c3                   ret 
// 005c38fa  5f                   pop edi
// 005c38fb  5e                   pop esi
// 005c38fc  b801000000           mov eax, 1
// 005c3901  5b                   pop ebx
// 005c3902  c3                   ret 
// library lua-5.1.1/ltablib.c (function _foreachi)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltablib.c
