// from server: 100% by auto
// roc 2008-06 00611bf0  unit: seg_00610000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611bf0
//
// 00611bf0  8b442404             mov eax, dword ptr [esp + 4]
// 00611bf4  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00611bf7  8b542408             mov edx, dword ptr [esp + 8]
// 00611bfb  8b4158               mov eax, dword ptr [ecx + 0x58]
// 00611bfe  895158               mov dword ptr [ecx + 0x58], edx
// 00611c01  c3                   ret 
// library lua-5.1/lapi.c (function _lua_atpanic)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
