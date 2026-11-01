// from server: 100% by auto
// roc 2007-03 005c6760  unit: seg_005c0000  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6760
//
// 005c6760  56                   push esi
// 005c6761  8b742408             mov esi, dword ptr [esp + 8]
// 005c6765  57                   push edi
// 005c6766  6a02                 push 2
// 005c6768  56                   push esi
// 005c6769  e8d224ffff           call 0x5b8c40
// 005c676e  6a05                 push 5
// 005c6770  6a01                 push 1
// 005c6772  56                   push esi
// 005c6773  8bf8                 mov edi, eax
// 005c6775  e8c63dffff           call 0x5ba540
// 005c677a  83c414               add esp, 0x14
// 005c677d  85ff                 test edi, edi
// 005c677f  7415                 je 0x5c6796
// 005c6781  83ff05               cmp edi, 5
// 005c6784  7410                 je 0x5c6796
// 005c6786  686ca37b00           push 0x7ba36c
// 005c678b  6a02                 push 2
// 005c678d  56                   push esi
// 005c678e  e85d3cffff           call 0x5ba3f0
// 005c6793  83c40c               add esp, 0xc
// 005c6796  683ca37b00           push 0x7ba33c
// 005c679b  6a01                 push 1
// 005c679d  56                   push esi
// 005c679e  e86d34ffff           call 0x5b9c10
// 005c67a3  83c40c               add esp, 0xc
// 005c67a6  85c0                 test eax, eax
// 005c67a8  740e                 je 0x5c67b8
// 005c67aa  6848a37b00           push 0x7ba348
// 005c67af  56                   push esi
// 005c67b0  e89b33ffff           call 0x5b9b50
// 005c67b5  83c408               add esp, 8
// 005c67b8  6a02                 push 2
// 005c67ba  56                   push esi
// 005c67bb  e8a022ffff           call 0x5b8a60
// 005c67c0  6a01                 push 1
// 005c67c2  56                   push esi
// 005c67c3  e8682effff           call 0x5b9630
// 005c67c8  83c410               add esp, 0x10
// 005c67cb  5f                   pop edi
// 005c67cc  b801000000           mov eax, 1
// 005c67d1  5e                   pop esi
// 005c67d2  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_setmetatable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
