// from server: 100% by auto
// roc 2007-03 00614410  unit: seg_00610000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614410
//
// 00614410  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00614414  8b4118               mov eax, dword ptr [ecx + 0x18]
// 00614417  89411c               mov dword ptr [ecx + 0x1c], eax
// 0061441a  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_getlabel)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
