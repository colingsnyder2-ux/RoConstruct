// from server: 100% by auto
// roc 2009-12 0079be30  unit: seg_00790000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079be30
//
// 0079be30  56                   push esi
// 0079be31  8b742408             mov esi, dword ptr [esp + 8]
// 0079be35  6a05                 push 5
// 0079be37  6a01                 push 1
// 0079be39  56                   push esi
// 0079be3a  e8b1e8feff           call 0x78a6f0
// 0079be3f  6808ad9e00           push 0x9ead08
// 0079be44  56                   push esi
// 0079be45  e8a6defeff           call 0x789cf0
// 0079be4a  6a01                 push 1
// 0079be4c  56                   push esi
// 0079be4d  e80ecbfeff           call 0x788960
// 0079be52  83c41c               add esp, 0x1c
// 0079be55  b801000000           mov eax, 1
// 0079be5a  5e                   pop esi
// 0079be5b  c3                   ret 
// library lua-5.1/ltablib.c (function _setn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltablib.c
