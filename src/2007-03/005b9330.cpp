// from server: 100% by auto
// roc 2007-03 005b9330  unit: seg_005b0000  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9330
//
// 005b9330  8b442408             mov eax, dword ptr [esp + 8]
// 005b9334  56                   push esi
// 005b9335  8b742408             mov esi, dword ptr [esp + 8]
// 005b9339  8bce                 mov ecx, esi
// 005b933b  e870f5ffff           call 0x5b88b0
// 005b9340  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b9343  8b10                 mov edx, dword ptr [eax]
// 005b9345  83e910               sub ecx, 0x10
// 005b9348  51                   push ecx
// 005b9349  52                   push edx
// 005b934a  e8712b0400           call 0x5fbec0
// 005b934f  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b9352  8b10                 mov edx, dword ptr [eax]
// 005b9354  83e910               sub ecx, 0x10
// 005b9357  8911                 mov dword ptr [ecx], edx
// 005b9359  8b5004               mov edx, dword ptr [eax + 4]
// 005b935c  895104               mov dword ptr [ecx + 4], edx
// 005b935f  8b4008               mov eax, dword ptr [eax + 8]
// 005b9362  83c408               add esp, 8
// 005b9365  894108               mov dword ptr [ecx + 8], eax
// 005b9368  5e                   pop esi
// 005b9369  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_rawget)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
