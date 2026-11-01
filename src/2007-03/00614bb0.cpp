// from server: 100% by auto
// roc 2007-03 00614bb0  unit: seg_00610000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614bb0
//
// 00614bb0  8b542410             mov edx, dword ptr [esp + 0x10]
// 00614bb4  c1e209               shl edx, 9
// 00614bb7  0b542414             or edx, dword ptr [esp + 0x14]
// 00614bbb  56                   push esi
// 00614bbc  8b742408             mov esi, dword ptr [esp + 8]
// 00614bc0  8b460c               mov eax, dword ptr [esi + 0xc]
// 00614bc3  8b4808               mov ecx, dword ptr [eax + 8]
// 00614bc6  c1e208               shl edx, 8
// 00614bc9  0b542410             or edx, dword ptr [esp + 0x10]
// 00614bcd  51                   push ecx
// 00614bce  c1e206               shl edx, 6
// 00614bd1  0b542410             or edx, dword ptr [esp + 0x10]
// 00614bd5  52                   push edx
// 00614bd6  e835ffffff           call 0x614b10
// 00614bdb  83c408               add esp, 8
// 00614bde  5e                   pop esi
// 00614bdf  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_codeABC)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
