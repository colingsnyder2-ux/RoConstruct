// from server: 100% by auto
// roc 2007-03 005c39a0  unit: seg_005c0000  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c39a0
//
// 005c39a0  55                   push ebp
// 005c39a1  8bec                 mov ebp, esp
// 005c39a3  83e4c0               and esp, 0xffffffc0
// 005c39a6  83ec3c               sub esp, 0x3c
// 005c39a9  d9ee                 fldz 
// 005c39ab  56                   push esi
// 005c39ac  8b7508               mov esi, dword ptr [ebp + 8]
// 005c39af  dd5c2438             fstp qword ptr [esp + 0x38]
// 005c39b3  6a05                 push 5
// 005c39b5  6a01                 push 1
// 005c39b7  56                   push esi
// 005c39b8  e8836bffff           call 0x5ba540
// 005c39bd  56                   push esi
// 005c39be  e85d56ffff           call 0x5b9020
// 005c39c3  6a01                 push 1
// 005c39c5  56                   push esi
// 005c39c6  e8f55fffff           call 0x5b99c0
// 005c39cb  83c418               add esp, 0x18
// 005c39ce  85c0                 test eax, eax
// 005c39d0  7447                 je 0x5c3a19
// 005c39d2  6afe                 push -2
// 005c39d4  56                   push esi
// 005c39d5  e88650ffff           call 0x5b8a60
// 005c39da  6aff                 push -1
// 005c39dc  56                   push esi
// 005c39dd  e85e52ffff           call 0x5b8c40
// 005c39e2  83c410               add esp, 0x10
// 005c39e5  83f803               cmp eax, 3
// 005c39e8  7520                 jne 0x5c3a0a
// 005c39ea  6aff                 push -1
// 005c39ec  56                   push esi
// 005c39ed  e8ae53ffff           call 0x5b8da0
// 005c39f2  dd442440             fld qword ptr [esp + 0x40]
// 005c39f6  d8d9                 fcomp st(1)
// 005c39f8  83c408               add esp, 8
// 005c39fb  dfe0                 fnstsw ax
// 005c39fd  f6c405               test ah, 5
// 005c3a00  7a06                 jp 0x5c3a08
// 005c3a02  dd5c2438             fstp qword ptr [esp + 0x38]
// 005c3a06  eb02                 jmp 0x5c3a0a
// 005c3a08  ddd8                 fstp st(0)
// 005c3a0a  6a01                 push 1
// 005c3a0c  56                   push esi
// 005c3a0d  e8ae5fffff           call 0x5b99c0
// 005c3a12  83c408               add esp, 8
// 005c3a15  85c0                 test eax, eax
// 005c3a17  75b9                 jne 0x5c39d2
// 005c3a19  dd442438             fld qword ptr [esp + 0x38]
// 005c3a1d  83ec08               sub esp, 8
// 005c3a20  dd1c24               fstp qword ptr [esp]
// 005c3a23  56                   push esi
// 005c3a24  e81756ffff           call 0x5b9040
// 005c3a29  83c40c               add esp, 0xc
// 005c3a2c  b801000000           mov eax, 1
// 005c3a31  5e                   pop esi
// 005c3a32  8be5                 mov esp, ebp
// 005c3a34  5d                   pop ebp
// 005c3a35  c3                   ret 
// library lua-5.1.1/ltablib.c (function _maxn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltablib.c
