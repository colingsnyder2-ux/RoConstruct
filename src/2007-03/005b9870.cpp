// from server: 100% by auto
// roc 2007-03 005b9870  unit: seg_005b0000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9870
//
// 005b9870  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005b9874  8b4108               mov eax, dword ptr [ecx + 8]
// 005b9877  83e810               sub eax, 0x10
// 005b987a  83780806             cmp dword ptr [eax + 8], 6
// 005b987e  7522                 jne 0x5b98a2
// 005b9880  8b00                 mov eax, dword ptr [eax]
// 005b9882  80780600             cmp byte ptr [eax + 6], 0
// 005b9886  751a                 jne 0x5b98a2
// 005b9888  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005b988c  8b4010               mov eax, dword ptr [eax + 0x10]
// 005b988f  6a00                 push 0
// 005b9891  52                   push edx
// 005b9892  8b542410             mov edx, dword ptr [esp + 0x10]
// 005b9896  52                   push edx
// 005b9897  50                   push eax
// 005b9898  51                   push ecx
// 005b9899  e8623a0400           call 0x5fd300
// 005b989e  83c414               add esp, 0x14
// 005b98a1  c3                   ret 
// 005b98a2  b801000000           mov eax, 1
// 005b98a7  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_dump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
