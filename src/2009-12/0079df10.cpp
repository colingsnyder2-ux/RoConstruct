// from server: 100% by auto
// roc 2009-12 0079df10  unit: seg_00790000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079df10
//
// 0079df10  8b442404             mov eax, dword ptr [esp + 4]
// 0079df14  6898b19e00           push 0x9eb198
// 0079df19  50                   push eax
// 0079df1a  e8d1bdfeff           call 0x789cf0
// 0079df1f  83c408               add esp, 8
// 0079df22  c3                   ret 
// library lua-5.1/lstrlib.c (function _gfind_nodef)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
