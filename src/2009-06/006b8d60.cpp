// from server: 100% by auto
// roc 2009-06 006b8d60  unit: RBX::UniversalTool  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b8d60
//
// 006b8d60  8b442404             mov eax, dword ptr [esp + 4]
// 006b8d64  8b4810               mov ecx, dword ptr [eax + 0x10]
// 006b8d67  8b542408             mov edx, dword ptr [esp + 8]
// 006b8d6b  8b4158               mov eax, dword ptr [ecx + 0x58]
// 006b8d6e  895158               mov dword ptr [ecx + 0x58], edx
// 006b8d71  c3                   ret 
// library lua-5.1/lapi.c (function _lua_atpanic)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
