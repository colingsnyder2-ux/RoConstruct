// from server: 100% by auto
// roc 2009-12 0079ded0  unit: seg_00790000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079ded0
//
// 0079ded0  56                   push esi
// 0079ded1  8b742408             mov esi, dword ptr [esp + 8]
// 0079ded5  6a00                 push 0
// 0079ded7  6a01                 push 1
// 0079ded9  56                   push esi
// 0079deda  e891c8feff           call 0x78a770
// 0079dedf  6a00                 push 0
// 0079dee1  6a02                 push 2
// 0079dee3  56                   push esi
// 0079dee4  e887c8feff           call 0x78a770
// 0079dee9  6a02                 push 2
// 0079deeb  56                   push esi
// 0079deec  e8bfa8feff           call 0x7887b0
// 0079def1  6a00                 push 0
// 0079def3  56                   push esi
// 0079def4  e887aefeff           call 0x788d80
// 0079def9  6a03                 push 3
// 0079defb  6860dd7900           push 0x79dd60
// 0079df00  56                   push esi
// 0079df01  e8aaaffeff           call 0x788eb0
// 0079df06  83c434               add esp, 0x34
// 0079df09  b801000000           mov eax, 1
// 0079df0e  5e                   pop esi
// 0079df0f  c3                   ret 
// library lua-5.1/lstrlib.c (function _gmatch)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
