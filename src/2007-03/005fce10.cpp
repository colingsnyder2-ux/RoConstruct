// from server: 100% by auto
// roc 2007-03 005fce10  unit: seg_005f0000  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fce10
//
// 005fce10  56                   push esi
// 005fce11  8b742410             mov esi, dword ptr [esp + 0x10]
// 005fce15  57                   push edi
// 005fce16  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005fce1a  8b4708               mov eax, dword ptr [edi + 8]
// 005fce1d  3bf0                 cmp esi, eax
// 005fce1f  7641                 jbe 0x5fce62
// 005fce21  83fe20               cmp esi, 0x20
// 005fce24  7305                 jae 0x5fce2b
// 005fce26  be20000000           mov esi, 0x20
// 005fce2b  8d4e01               lea ecx, [esi + 1]
// 005fce2e  83f9fd               cmp ecx, -3
// 005fce31  771a                 ja 0x5fce4d
// 005fce33  8b17                 mov edx, dword ptr [edi]
// 005fce35  56                   push esi
// 005fce36  50                   push eax
// 005fce37  8b442414             mov eax, dword ptr [esp + 0x14]
// 005fce3b  52                   push edx
// 005fce3c  50                   push eax
// 005fce3d  e85e050000           call 0x5fd3a0
// 005fce42  83c410               add esp, 0x10
// 005fce45  897708               mov dword ptr [edi + 8], esi
// 005fce48  8907                 mov dword ptr [edi], eax
// 005fce4a  5f                   pop edi
// 005fce4b  5e                   pop esi
// 005fce4c  c3                   ret 
// 005fce4d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005fce51  51                   push ecx
// 005fce52  e829050000           call 0x5fd380
// 005fce57  83c404               add esp, 4
// 005fce5a  897708               mov dword ptr [edi + 8], esi
// 005fce5d  8907                 mov dword ptr [edi], eax
// 005fce5f  5f                   pop edi
// 005fce60  5e                   pop esi
// 005fce61  c3                   ret 
// 005fce62  8b07                 mov eax, dword ptr [edi]
// 005fce64  5f                   pop edi
// 005fce65  5e                   pop esi
// 005fce66  c3                   ret 
// library lua-5.1.1/lzio.c (function _luaZ_openspace)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lzio.c
