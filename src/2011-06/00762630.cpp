// from server: 100% by auto
// roc 2011-06 00762630  unit: seg_00760000  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762630
//
// 00762630  8b442408             mov eax, dword ptr [esp + 8]
// 00762634  56                   push esi
// 00762635  57                   push edi
// 00762636  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0076263a  8bcf                 mov ecx, edi
// 0076263c  e86ffbffff           call 0x7621b0
// 00762641  8bf0                 mov esi, eax
// 00762643  8b442414             mov eax, dword ptr [esp + 0x14]
// 00762647  8bcf                 mov ecx, edi
// 00762649  e862fbffff           call 0x7621b0
// 0076264e  81feb875ab00         cmp esi, 0xab75b8
// 00762654  7414                 je 0x76266a
// 00762656  3db875ab00           cmp eax, 0xab75b8
// 0076265b  740d                 je 0x76266a
// 0076265d  50                   push eax
// 0076265e  56                   push esi
// 0076265f  e86ca30100           call 0x77c9d0
// 00762664  83c408               add esp, 8
// 00762667  5f                   pop edi
// 00762668  5e                   pop esi
// 00762669  c3                   ret 
// 0076266a  5f                   pop edi
// 0076266b  33c0                 xor eax, eax
// 0076266d  5e                   pop esi
// 0076266e  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawequal)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
