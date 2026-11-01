// from server: 100% by auto
// roc 2007-03 005b97a0  unit: seg_005b0000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b97a0
//
// 005b97a0  8b442408             mov eax, dword ptr [esp + 8]
// 005b97a4  8b4804               mov ecx, dword ptr [eax + 4]
// 005b97a7  8b10                 mov edx, dword ptr [eax]
// 005b97a9  8b442404             mov eax, dword ptr [esp + 4]
// 005b97ad  51                   push ecx
// 005b97ae  52                   push edx
// 005b97af  50                   push eax
// 005b97b0  e8fb6c0000           call 0x5c04b0
// 005b97b5  83c40c               add esp, 0xc
// 005b97b8  c3                   ret 
// library lua-5.1.1/lapi.c (function _f_call)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
