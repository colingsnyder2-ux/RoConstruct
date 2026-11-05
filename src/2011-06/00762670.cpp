// from server: 100% by auto
// roc 2011-06 00762670  unit: seg_00760000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762670
//
// 00762670  8b442408             mov eax, dword ptr [esp + 8]
// 00762674  56                   push esi
// 00762675  8b742408             mov esi, dword ptr [esp + 8]
// 00762679  57                   push edi
// 0076267a  8bce                 mov ecx, esi
// 0076267c  e82ffbffff           call 0x7621b0
// 00762681  8bf8                 mov edi, eax
// 00762683  8b442414             mov eax, dword ptr [esp + 0x14]
// 00762687  8bce                 mov ecx, esi
// 00762689  e822fbffff           call 0x7621b0
// 0076268e  81ffb875ab00         cmp edi, 0xab75b8
// 00762694  7415                 je 0x7626ab
// 00762696  3db875ab00           cmp eax, 0xab75b8
// 0076269b  740e                 je 0x7626ab
// 0076269d  50                   push eax
// 0076269e  57                   push edi
// 0076269f  56                   push esi
// 007626a0  e86b540700           call 0x7d7b10
// 007626a5  83c40c               add esp, 0xc
// 007626a8  5f                   pop edi
// 007626a9  5e                   pop esi
// 007626aa  c3                   ret 
// 007626ab  5f                   pop edi
// 007626ac  33c0                 xor eax, eax
// 007626ae  5e                   pop esi
// 007626af  c3                   ret 
// library lua-5.1/lapi.c (function _lua_lessthan)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
