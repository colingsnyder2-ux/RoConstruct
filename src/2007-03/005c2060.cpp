// from server: 100% by auto
// roc 2007-03 005c2060  unit: seg_005c0000  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c2060
//
// 005c2060  56                   push esi
// 005c2061  57                   push edi
// 005c2062  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005c2066  6a02                 push 2
// 005c2068  68efd8ffff           push 0xffffd8ef
// 005c206d  57                   push edi
// 005c206e  e8fd72ffff           call 0x5b9370
// 005c2073  6aff                 push -1
// 005c2075  57                   push edi
// 005c2076  e8e56effff           call 0x5b8f60
// 005c207b  8b30                 mov esi, dword ptr [eax]
// 005c207d  83c414               add esp, 0x14
// 005c2080  85f6                 test esi, esi
// 005c2082  7514                 jne 0x5c2098
// 005c2084  a12c987b00           mov eax, dword ptr [0x7b982c]
// 005c2089  50                   push eax
// 005c208a  6840997b00           push 0x7b9940
// 005c208f  57                   push edi
// 005c2090  e8bb7affff           call 0x5b9b50
// 005c2095  83c40c               add esp, 0xc
// 005c2098  56                   push esi
// 005c2099  b801000000           mov eax, 1
// 005c209e  e8bdfeffff           call 0x5c1f60
// 005c20a3  83c404               add esp, 4
// 005c20a6  5f                   pop edi
// 005c20a7  5e                   pop esi
// 005c20a8  c3                   ret 
// library lua-5.1.1/liolib.c (function _io_write)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 liolib.c
