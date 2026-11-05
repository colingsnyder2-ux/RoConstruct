// from server: 100% by auto
// roc 2008-06 00612530  unit: seg_00610000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612530
//
// 00612530  8b442408             mov eax, dword ptr [esp + 8]
// 00612534  56                   push esi
// 00612535  8b742408             mov esi, dword ptr [esp + 8]
// 00612539  8bce                 mov ecx, esi
// 0061253b  e850f5ffff           call 0x611a90
// 00612540  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00612544  8b10                 mov edx, dword ptr [eax]
// 00612546  51                   push ecx
// 00612547  52                   push edx
// 00612548  e883c40400           call 0x65e9d0
// 0061254d  8b10                 mov edx, dword ptr [eax]
// 0061254f  8b4e08               mov ecx, dword ptr [esi + 8]
// 00612552  8911                 mov dword ptr [ecx], edx
// 00612554  8b5004               mov edx, dword ptr [eax + 4]
// 00612557  895104               mov dword ptr [ecx + 4], edx
// 0061255a  8b4008               mov eax, dword ptr [eax + 8]
// 0061255d  83c408               add esp, 8
// 00612560  894108               mov dword ptr [ecx + 8], eax
// 00612563  83460810             add dword ptr [esi + 8], 0x10
// 00612567  5e                   pop esi
// 00612568  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawgeti)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
