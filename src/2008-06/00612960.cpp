// from server: 100% by auto
// roc 2008-06 00612960  unit: seg_00610000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612960
//
// 00612960  8b442408             mov eax, dword ptr [esp + 8]
// 00612964  8b4804               mov ecx, dword ptr [eax + 4]
// 00612967  8b10                 mov edx, dword ptr [eax]
// 00612969  8b442404             mov eax, dword ptr [esp + 4]
// 0061296d  51                   push ecx
// 0061296e  52                   push edx
// 0061296f  50                   push eax
// 00612970  e88bf90000           call 0x622300
// 00612975  83c40c               add esp, 0xc
// 00612978  c3                   ret 
// library lua-5.1/lapi.c (function _f_call)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
