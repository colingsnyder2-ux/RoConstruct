// from server: 100% by auto
// roc 2009-12 0079d1a0  unit: seg_00790000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079d1a0
//
// 0079d1a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0079d1a4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0079d1a8  8b542410             mov edx, dword ptr [esp + 0x10]
// 0079d1ac  50                   push eax
// 0079d1ad  51                   push ecx
// 0079d1ae  52                   push edx
// 0079d1af  e85ccefeff           call 0x78a010
// 0079d1b4  83c40c               add esp, 0xc
// 0079d1b7  33c0                 xor eax, eax
// 0079d1b9  c3                   ret 
// library lua-5.1/lstrlib.c (function _writer)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
