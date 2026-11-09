// from server: 100% by auto
// roc 2012-06 00656170  unit: seg_00650000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00656170
//
// 00656170  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00656174  85c9                 test ecx, ecx
// 00656176  7435                 je 0x6561ad
// 00656178  8b8110010000         mov eax, dword ptr [ecx + 0x110]
// 0065617e  8bd0                 mov edx, eax
// 00656180  c1ea18               shr edx, 0x18
// 00656183  88542404             mov byte ptr [esp + 4], dl
// 00656187  8bd0                 mov edx, eax
// 00656189  c1ea10               shr edx, 0x10
// 0065618c  88542405             mov byte ptr [esp + 5], dl
// 00656190  8bd0                 mov edx, eax
// 00656192  88442407             mov byte ptr [esp + 7], al
// 00656196  6a04                 push 4
// 00656198  8d442408             lea eax, [esp + 8]
// 0065619c  50                   push eax
// 0065619d  c1ea08               shr edx, 8
// 006561a0  51                   push ecx
// 006561a1  88542412             mov byte ptr [esp + 0x12], dl
// 006561a5  e81615ffff           call 0x6476c0
// 006561aa  83c40c               add esp, 0xc
// 006561ad  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_chunk_end)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
