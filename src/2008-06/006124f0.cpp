// from server: 100% by auto
// roc 2008-06 006124f0  unit: seg_00610000  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006124f0
//
// 006124f0  8b442408             mov eax, dword ptr [esp + 8]
// 006124f4  56                   push esi
// 006124f5  8b742408             mov esi, dword ptr [esp + 8]
// 006124f9  8bce                 mov ecx, esi
// 006124fb  e890f5ffff           call 0x611a90
// 00612500  8b4e08               mov ecx, dword ptr [esi + 8]
// 00612503  8b10                 mov edx, dword ptr [eax]
// 00612505  83e910               sub ecx, 0x10
// 00612508  51                   push ecx
// 00612509  52                   push edx
// 0061250a  e891c50400           call 0x65eaa0
// 0061250f  8b4e08               mov ecx, dword ptr [esi + 8]
// 00612512  8b10                 mov edx, dword ptr [eax]
// 00612514  83e910               sub ecx, 0x10
// 00612517  8911                 mov dword ptr [ecx], edx
// 00612519  8b5004               mov edx, dword ptr [eax + 4]
// 0061251c  895104               mov dword ptr [ecx + 4], edx
// 0061251f  8b4008               mov eax, dword ptr [eax + 8]
// 00612522  83c408               add esp, 8
// 00612525  894108               mov dword ptr [ecx + 8], eax
// 00612528  5e                   pop esi
// 00612529  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawget)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
