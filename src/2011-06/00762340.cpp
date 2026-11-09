// from server: 100% by auto
// roc 2011-06 00762340  unit: seg_00760000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762340
//
// 00762340  8b442404             mov eax, dword ptr [esp + 4]
// 00762344  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00762347  8b542408             mov edx, dword ptr [esp + 8]
// 0076234b  8b4158               mov eax, dword ptr [ecx + 0x58]
// 0076234e  895158               mov dword ptr [ecx + 0x58], edx
// 00762351  c3                   ret 
// library lua-5.1/lapi.c (function _lua_atpanic)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
