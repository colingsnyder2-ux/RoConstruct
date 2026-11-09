// from server: 100% by auto
// roc 2009-12 0079cce0  unit: seg_00790000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079cce0
//
// 0079cce0  51                   push ecx
// 0079cce1  56                   push esi
// 0079cce2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0079cce6  8d442404             lea eax, [esp + 4]
// 0079ccea  50                   push eax
// 0079cceb  6a01                 push 1
// 0079cced  56                   push esi
// 0079ccee  e87ddafeff           call 0x78a770
// 0079ccf3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0079ccf7  51                   push ecx
// 0079ccf8  56                   push esi
// 0079ccf9  e882c0feff           call 0x788d80
// 0079ccfe  83c414               add esp, 0x14
// 0079cd01  b801000000           mov eax, 1
// 0079cd06  5e                   pop esi
// 0079cd07  59                   pop ecx
// 0079cd08  c3                   ret 
// library lua-5.1/lstrlib.c (function _str_len)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
