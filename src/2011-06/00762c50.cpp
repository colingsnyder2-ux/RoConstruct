// from server: 100% by auto
// roc 2011-06 00762c50  unit: seg_00760000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762c50
//
// 00762c50  8b442408             mov eax, dword ptr [esp + 8]
// 00762c54  56                   push esi
// 00762c55  8b742408             mov esi, dword ptr [esp + 8]
// 00762c59  8bce                 mov ecx, esi
// 00762c5b  e850f5ffff           call 0x7621b0
// 00762c60  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00762c64  8b10                 mov edx, dword ptr [eax]
// 00762c66  51                   push ecx
// 00762c67  52                   push edx
// 00762c68  e8636c0700           call 0x7d98d0
// 00762c6d  8b10                 mov edx, dword ptr [eax]
// 00762c6f  8b4e08               mov ecx, dword ptr [esi + 8]
// 00762c72  8911                 mov dword ptr [ecx], edx
// 00762c74  8b5004               mov edx, dword ptr [eax + 4]
// 00762c77  895104               mov dword ptr [ecx + 4], edx
// 00762c7a  8b4008               mov eax, dword ptr [eax + 8]
// 00762c7d  83c408               add esp, 8
// 00762c80  894108               mov dword ptr [ecx + 8], eax
// 00762c83  83460810             add dword ptr [esi + 8], 0x10
// 00762c87  5e                   pop esi
// 00762c88  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawgeti)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
