// from server: 100% by auto
// roc 2009-12 0079f580  unit: seg_00790000  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f580
//
// 0079f580  83ec64               sub esp, 0x64
// 0079f583  39742468             cmp dword ptr [esp + 0x68], esi
// 0079f587  7506                 jne 0x79f58f
// 0079f589  33c0                 xor eax, eax
// 0079f58b  83c464               add esp, 0x64
// 0079f58e  c3                   ret 
// 0079f58f  56                   push esi
// 0079f590  e87ba0feff           call 0x789610
// 0079f595  83c404               add esp, 4
// 0079f598  83e800               sub eax, 0
// 0079f59b  7417                 je 0x79f5b4
// 0079f59d  83e801               sub eax, 1
// 0079f5a0  7409                 je 0x79f5ab
// 0079f5a2  b803000000           mov eax, 3
// 0079f5a7  83c464               add esp, 0x64
// 0079f5aa  c3                   ret 
// 0079f5ab  b801000000           mov eax, 1
// 0079f5b0  83c464               add esp, 0x64
// 0079f5b3  c3                   ret 
// 0079f5b4  8d0424               lea eax, [esp]
// 0079f5b7  50                   push eax
// 0079f5b8  6a00                 push 0
// 0079f5ba  56                   push esi
// 0079f5bb  e8e0b1ffff           call 0x79a7a0
// 0079f5c0  83c40c               add esp, 0xc
// 0079f5c3  85c0                 test eax, eax
// 0079f5c5  7e09                 jle 0x79f5d0
// 0079f5c7  b802000000           mov eax, 2
// 0079f5cc  83c464               add esp, 0x64
// 0079f5cf  c3                   ret 
// 0079f5d0  56                   push esi
// 0079f5d1  e8ca91feff           call 0x7887a0
// 0079f5d6  83c404               add esp, 4
// 0079f5d9  f7d8                 neg eax
// 0079f5db  1bc0                 sbb eax, eax
// 0079f5dd  83e0fe               and eax, 0xfffffffe
// 0079f5e0  83c003               add eax, 3
// 0079f5e3  83c464               add esp, 0x64
// 0079f5e6  c3                   ret 
// library lua-5.1.3/lbaselib.c (function _costatus)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 lbaselib.c
