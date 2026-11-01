// from server: 100% by auto
// roc 2007-03 00614e10  unit: seg_00610000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614e10
//
// 00614e10  8b442404             mov eax, dword ptr [esp + 4]
// 00614e14  8b4818               mov ecx, dword ptr [eax + 0x18]
// 00614e17  8b542408             mov edx, dword ptr [esp + 8]
// 00614e1b  89481c               mov dword ptr [eax + 0x1c], ecx
// 00614e1e  52                   push edx
// 00614e1f  8d4820               lea ecx, [eax + 0x20]
// 00614e22  51                   push ecx
// 00614e23  50                   push eax
// 00614e24  e827f8ffff           call 0x614650
// 00614e29  83c40c               add esp, 0xc
// 00614e2c  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_patchtohere)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
