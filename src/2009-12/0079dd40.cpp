// from server: 100% by auto
// roc 2009-12 0079dd40  unit: seg_00790000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079dd40
//
// 0079dd40  8b442404             mov eax, dword ptr [esp + 4]
// 0079dd44  6a01                 push 1
// 0079dd46  50                   push eax
// 0079dd47  e844feffff           call 0x79db90
// 0079dd4c  83c408               add esp, 8
// 0079dd4f  c3                   ret 
// library lua-5.1/lstrlib.c (function _str_find)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
