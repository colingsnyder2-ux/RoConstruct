// from server: 100% by auto
// roc 2009-12 0079eaf0  unit: seg_00790000  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079eaf0
//
// 0079eaf0  56                   push esi
// 0079eaf1  8b742408             mov esi, dword ptr [esp + 8]
// 0079eaf5  57                   push edi
// 0079eaf6  6a02                 push 2
// 0079eaf8  56                   push esi
// 0079eaf9  e8929efeff           call 0x788990
// 0079eafe  6a05                 push 5
// 0079eb00  6a01                 push 1
// 0079eb02  56                   push esi
// 0079eb03  8bf8                 mov edi, eax
// 0079eb05  e8e6bbfeff           call 0x78a6f0
// 0079eb0a  83c414               add esp, 0x14
// 0079eb0d  85ff                 test edi, edi
// 0079eb0f  7415                 je 0x79eb26
// 0079eb11  83ff05               cmp edi, 5
// 0079eb14  7410                 je 0x79eb26
// 0079eb16  68e4b49e00           push 0x9eb4e4
// 0079eb1b  6a02                 push 2
// 0079eb1d  56                   push esi
// 0079eb1e  e85dbafeff           call 0x78a580
// 0079eb23  83c40c               add esp, 0xc
// 0079eb26  68b4b49e00           push 0x9eb4b4
// 0079eb2b  6a01                 push 1
// 0079eb2d  56                   push esi
// 0079eb2e  e87db2feff           call 0x789db0
// 0079eb33  83c40c               add esp, 0xc
// 0079eb36  85c0                 test eax, eax
// 0079eb38  740e                 je 0x79eb48
// 0079eb3a  68c0b49e00           push 0x9eb4c0
// 0079eb3f  56                   push esi
// 0079eb40  e8abb1feff           call 0x789cf0
// 0079eb45  83c408               add esp, 8
// 0079eb48  6a02                 push 2
// 0079eb4a  56                   push esi
// 0079eb4b  e8609cfeff           call 0x7887b0
// 0079eb50  6a01                 push 1
// 0079eb52  56                   push esi
// 0079eb53  e828a8feff           call 0x789380
// 0079eb58  83c410               add esp, 0x10
// 0079eb5b  5f                   pop edi
// 0079eb5c  b801000000           mov eax, 1
// 0079eb61  5e                   pop esi
// 0079eb62  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_setmetatable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
