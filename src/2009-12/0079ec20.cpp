// from server: 100% by auto
// roc 2009-12 0079ec20  unit: seg_00790000  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079ec20
//
// 0079ec20  56                   push esi
// 0079ec21  8b742408             mov esi, dword ptr [esp + 8]
// 0079ec25  6a01                 push 1
// 0079ec27  e844ffffff           call 0x79eb70
// 0079ec2c  6aff                 push -1
// 0079ec2e  56                   push esi
// 0079ec2f  e89c9dfeff           call 0x7889d0
// 0079ec34  83c40c               add esp, 0xc
// 0079ec37  85c0                 test eax, eax
// 0079ec39  7415                 je 0x79ec50
// 0079ec3b  68eed8ffff           push 0xffffd8ee
// 0079ec40  56                   push esi
// 0079ec41  e81a9dfeff           call 0x788960
// 0079ec46  83c408               add esp, 8
// 0079ec49  b801000000           mov eax, 1
// 0079ec4e  5e                   pop esi
// 0079ec4f  c3                   ret 
// 0079ec50  6aff                 push -1
// 0079ec52  56                   push esi
// 0079ec53  e838a5feff           call 0x789190
// 0079ec58  83c408               add esp, 8
// 0079ec5b  b801000000           mov eax, 1
// 0079ec60  5e                   pop esi
// 0079ec61  c3                   ret 
// library lua-5.1.2/lbaselib.c (function _luaB_getfenv)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lbaselib.c
