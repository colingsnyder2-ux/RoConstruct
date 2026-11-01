// from server: 100% by auto
// roc 2009-12 0079b750  unit: seg_00790000  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079b750
//
// 0079b750  53                   push ebx
// 0079b751  56                   push esi
// 0079b752  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0079b756  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0079b759  57                   push edi
// 0079b75a  8bfe                 mov edi, esi
// 0079b75c  e86fffffff           call 0x79b6d0
// 0079b761  6a02                 push 2
// 0079b763  6a00                 push 0
// 0079b765  56                   push esi
// 0079b766  e8254a0300           call 0x7d0190
// 0079b76b  6a02                 push 2
// 0079b76d  894648               mov dword ptr [esi + 0x48], eax
// 0079b770  c7465005000000       mov dword ptr [esi + 0x50], 5
// 0079b777  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0079b77a  6a00                 push 0
// 0079b77c  56                   push esi
// 0079b77d  83c760               add edi, 0x60
// 0079b780  e80b4a0300           call 0x7d0190
// 0079b785  6a20                 push 0x20
// 0079b787  56                   push esi
// 0079b788  8907                 mov dword ptr [edi], eax
// 0079b78a  c7470805000000       mov dword ptr [edi + 8], 5
// 0079b791  e89a520300           call 0x7d0a30
// 0079b796  56                   push esi
// 0079b797  e854260300           call 0x7cddf0
// 0079b79c  56                   push esi
// 0079b79d  e84e9a0300           call 0x7d51f0
// 0079b7a2  6a11                 push 0x11
// 0079b7a4  6878a99e00           push 0x9ea978
// 0079b7a9  56                   push esi
// 0079b7aa  e8e1530300           call 0x7d0b90
// 0079b7af  80480520             or byte ptr [eax + 5], 0x20
// 0079b7b3  83c005               add eax, 5
// 0079b7b6  8b4344               mov eax, dword ptr [ebx + 0x44]
// 0079b7b9  83c434               add esp, 0x34
// 0079b7bc  03c0                 add eax, eax
// 0079b7be  5f                   pop edi
// 0079b7bf  03c0                 add eax, eax
// 0079b7c1  5e                   pop esi
// 0079b7c2  894340               mov dword ptr [ebx + 0x40], eax
// 0079b7c5  5b                   pop ebx
// 0079b7c6  c3                   ret 
// library lua-5.1/lstate.c (function _f_luaopen)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstate.c
