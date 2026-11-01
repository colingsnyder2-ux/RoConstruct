// from server: 100% by auto
// roc 2007-03 006157e0  unit: seg_00610000  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006157e0
//
// 006157e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006157e4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006157e8  50                   push eax
// 006157e9  51                   push ecx
// 006157ea  e8c1faffff           call 0x6152b0
// 006157ef  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006157f3  83c408               add esp, 8
// 006157f6  89410c               mov dword ptr [ecx + 0xc], eax
// 006157f9  c70109000000         mov dword ptr [ecx], 9
// 006157ff  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_indexed)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
