// from server: 100% by auto
// roc 2007-03 005b89e0  unit: seg_005b0000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b89e0
//
// 005b89e0  8b442404             mov eax, dword ptr [esp + 4]
// 005b89e4  8b4810               mov ecx, dword ptr [eax + 0x10]
// 005b89e7  8b542408             mov edx, dword ptr [esp + 8]
// 005b89eb  8b4158               mov eax, dword ptr [ecx + 0x58]
// 005b89ee  895158               mov dword ptr [ecx + 0x58], edx
// 005b89f1  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_atpanic)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
