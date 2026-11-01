// from server: 100% by auto
// roc 2007-03 00518460  unit: seg_00510000  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00518460
//
// 00518460  83ec58               sub esp, 0x58
// 00518463  a1b4f58a00           mov eax, dword ptr [0x8af5b4]
// 00518468  33c4                 xor eax, esp
// 0051846a  89442454             mov dword ptr [esp + 0x54], eax
// 0051846e  8b542460             mov edx, dword ptr [esp + 0x60]
// 00518472  56                   push esi
// 00518473  8b742460             mov esi, dword ptr [esp + 0x60]
// 00518477  56                   push esi
// 00518478  8d442408             lea eax, [esp + 8]
// 0051847c  e84ffbffff           call 0x517fd0
// 00518481  8d442408             lea eax, [esp + 8]
// 00518485  50                   push eax
// 00518486  56                   push esi
// 00518487  e844ffffff           call 0x5183d0
// 0051848c  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00518490  83c40c               add esp, 0xc
// 00518493  5e                   pop esi
// 00518494  33cc                 xor ecx, esp
// 00518496  e80b6a1000           call 0x61eea6
// 0051849b  83c458               add esp, 0x58
// 0051849e  c3                   ret 
// library libpng-1.2.7/pngerror.c (function _png_chunk_warning)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS /MD
// roc-lib: libpng-1.2.7 pngerror.c
