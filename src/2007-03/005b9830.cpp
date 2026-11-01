// from server: 100% by auto
// roc 2007-03 005b9830  unit: seg_005b0000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9830
//
// 005b9830  83ec14               sub esp, 0x14
// 005b9833  56                   push esi
// 005b9834  57                   push edi
// 005b9835  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005b9839  85ff                 test edi, edi
// 005b983b  7505                 jne 0x5b9842
// 005b983d  bf9cc57900           mov edi, 0x79c59c
// 005b9842  8b442428             mov eax, dword ptr [esp + 0x28]
// 005b9846  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005b984a  8b742420             mov esi, dword ptr [esp + 0x20]
// 005b984e  50                   push eax
// 005b984f  51                   push ecx
// 005b9850  8d542410             lea edx, [esp + 0x10]
// 005b9854  52                   push edx
// 005b9855  56                   push esi
// 005b9856  e8e5340400           call 0x5fcd40
// 005b985b  57                   push edi
// 005b985c  8d44241c             lea eax, [esp + 0x1c]
// 005b9860  50                   push eax
// 005b9861  56                   push esi
// 005b9862  e8c96e0000           call 0x5c0730
// 005b9867  83c41c               add esp, 0x1c
// 005b986a  5f                   pop edi
// 005b986b  5e                   pop esi
// 005b986c  83c414               add esp, 0x14
// 005b986f  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_load)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
