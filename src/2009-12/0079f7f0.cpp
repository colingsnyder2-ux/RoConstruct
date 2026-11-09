// from server: 100% by auto
// roc 2009-12 0079f7f0  unit: seg_00790000  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f7f0
//
// 0079f7f0  56                   push esi
// 0079f7f1  8b742408             mov esi, dword ptr [esp + 8]
// 0079f7f5  57                   push edi
// 0079f7f6  56                   push esi
// 0079f7f7  e834a4feff           call 0x789c30
// 0079f7fc  6a01                 push 1
// 0079f7fe  56                   push esi
// 0079f7ff  8bf8                 mov edi, eax
// 0079f801  e88a91feff           call 0x788990
// 0079f806  83c40c               add esp, 0xc
// 0079f809  83f806               cmp eax, 6
// 0079f80c  750f                 jne 0x79f81d
// 0079f80e  6a01                 push 1
// 0079f810  56                   push esi
// 0079f811  e8ba91feff           call 0x7889d0
// 0079f816  83c408               add esp, 8
// 0079f819  85c0                 test eax, eax
// 0079f81b  7410                 je 0x79f82d
// 0079f81d  6824b79e00           push 0x9eb724
// 0079f822  6a01                 push 1
// 0079f824  56                   push esi
// 0079f825  e856adfeff           call 0x78a580
// 0079f82a  83c40c               add esp, 0xc
// 0079f82d  6a01                 push 1
// 0079f82f  56                   push esi
// 0079f830  e82b91feff           call 0x788960
// 0079f835  6a01                 push 1
// 0079f837  57                   push edi
// 0079f838  56                   push esi
// 0079f839  e8d28efeff           call 0x788710
// 0079f83e  83c414               add esp, 0x14
// 0079f841  5f                   pop edi
// 0079f842  b801000000           mov eax, 1
// 0079f847  5e                   pop esi
// 0079f848  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_cocreate)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
