// from server: 100% by auto
// roc 2009-12 007d1230  unit: seg_007d0000  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1230
//
// 007d1230  56                   push esi
// 007d1231  8b742410             mov esi, dword ptr [esp + 0x10]
// 007d1235  57                   push edi
// 007d1236  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007d123a  8b4708               mov eax, dword ptr [edi + 8]
// 007d123d  3bf0                 cmp esi, eax
// 007d123f  7641                 jbe 0x7d1282
// 007d1241  83fe20               cmp esi, 0x20
// 007d1244  7305                 jae 0x7d124b
// 007d1246  be20000000           mov esi, 0x20
// 007d124b  8d4e01               lea ecx, [esi + 1]
// 007d124e  83f9fd               cmp ecx, -3
// 007d1251  771a                 ja 0x7d126d
// 007d1253  8b17                 mov edx, dword ptr [edi]
// 007d1255  56                   push esi
// 007d1256  50                   push eax
// 007d1257  8b442414             mov eax, dword ptr [esp + 0x14]
// 007d125b  52                   push edx
// 007d125c  50                   push eax
// 007d125d  e84e050000           call 0x7d17b0
// 007d1262  83c410               add esp, 0x10
// 007d1265  897708               mov dword ptr [edi + 8], esi
// 007d1268  8907                 mov dword ptr [edi], eax
// 007d126a  5f                   pop edi
// 007d126b  5e                   pop esi
// 007d126c  c3                   ret 
// 007d126d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007d1271  51                   push ecx
// 007d1272  e819050000           call 0x7d1790
// 007d1277  83c404               add esp, 4
// 007d127a  897708               mov dword ptr [edi + 8], esi
// 007d127d  8907                 mov dword ptr [edi], eax
// 007d127f  5f                   pop edi
// 007d1280  5e                   pop esi
// 007d1281  c3                   ret 
// 007d1282  8b07                 mov eax, dword ptr [edi]
// 007d1284  5f                   pop edi
// 007d1285  5e                   pop esi
// 007d1286  c3                   ret 
// library lua-5.1/lzio.c (function _luaZ_openspace)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lzio.c
