// from server: 100% by auto
// roc 2007-08 005c7660  unit: lua_exception  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c7660
//
// 005c7660  56                   push esi
// 005c7661  8b742408             mov esi, dword ptr [esp + 8]
// 005c7665  6844997b00           push 0x7b9944
// 005c766a  6a01                 push 1
// 005c766c  56                   push esi
// 005c766d  e8ce7bffff           call 0x5bf240
// 005c7672  8b00                 mov eax, dword ptr [eax]
// 005c7674  83c40c               add esp, 0xc
// 005c7677  85c0                 test eax, eax
// 005c7679  7515                 jne 0x5c7690
// 005c767b  6880997b00           push 0x7b9980
// 005c7680  56                   push esi
// 005c7681  e86a65ffff           call 0x5bdbf0
// 005c7686  83c408               add esp, 8
// 005c7689  b801000000           mov eax, 1
// 005c768e  5e                   pop esi
// 005c768f  c3                   ret 
// 005c7690  50                   push eax
// 005c7691  6874997b00           push 0x7b9974
// 005c7696  56                   push esi
// 005c7697  e8f465ffff           call 0x5bdc90
// 005c769c  83c40c               add esp, 0xc
// 005c769f  b801000000           mov eax, 1
// 005c76a4  5e                   pop esi
// 005c76a5  c3                   ret 
// library lua-5.1.2/liolib.c (function _io_tostring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 liolib.c
