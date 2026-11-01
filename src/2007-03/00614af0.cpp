// from server: 100% by auto
// roc 2007-03 00614af0  unit: seg_00610000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614af0
//
// 00614af0  8b442404             mov eax, dword ptr [esp + 4]
// 00614af4  8b10                 mov edx, dword ptr [eax]
// 00614af6  8b4818               mov ecx, dword ptr [eax + 0x18]
// 00614af9  8b4214               mov eax, dword ptr [edx + 0x14]
// 00614afc  8b542408             mov edx, dword ptr [esp + 8]
// 00614b00  895488fc             mov dword ptr [eax + ecx*4 - 4], edx
// 00614b04  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_fixline)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
