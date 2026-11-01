// from server: 100% by auto
// roc 2009-12 0079dd50  unit: seg_00790000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079dd50
//
// 0079dd50  8b442404             mov eax, dword ptr [esp + 4]
// 0079dd54  6a00                 push 0
// 0079dd56  50                   push eax
// 0079dd57  e834feffff           call 0x79db90
// 0079dd5c  83c408               add esp, 8
// 0079dd5f  c3                   ret 
// library lua-5.1/lstrlib.c (function _str_match)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
