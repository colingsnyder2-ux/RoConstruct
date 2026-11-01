// from server: 100% by auto
// roc 2009-12 0079e7c0  unit: seg_00790000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079e7c0
//
// 0079e7c0  6a01                 push 1
// 0079e7c2  6a00                 push 0
// 0079e7c4  56                   push esi
// 0079e7c5  e806a9feff           call 0x7890d0
// 0079e7ca  6a00                 push 0
// 0079e7cc  6856fd9900           push 0x99fd56
// 0079e7d1  56                   push esi
// 0079e7d2  e8c9a5feff           call 0x788da0
// 0079e7d7  6afe                 push -2
// 0079e7d9  56                   push esi
// 0079e7da  e881a1feff           call 0x788960
// 0079e7df  6afe                 push -2
// 0079e7e1  56                   push esi
// 0079e7e2  e899abfeff           call 0x789380
// 0079e7e7  6afe                 push -2
// 0079e7e9  56                   push esi
// 0079e7ea  e8c19ffeff           call 0x7887b0
// 0079e7ef  6afe                 push -2
// 0079e7f1  56                   push esi
// 0079e7f2  e869a1feff           call 0x788960
// 0079e7f7  68802a9d00           push 0x9d2a80
// 0079e7fc  6afe                 push -2
// 0079e7fe  56                   push esi
// 0079e7ff  e82caafeff           call 0x789230
// 0079e804  83c444               add esp, 0x44
// 0079e807  6afe                 push -2
// 0079e809  56                   push esi
// 0079e80a  e8a19ffeff           call 0x7887b0
// 0079e80f  83c408               add esp, 8
// 0079e812  c3                   ret 
// library lua-5.1/lstrlib.c (function _createmetatable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
