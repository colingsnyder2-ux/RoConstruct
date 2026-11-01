// from server: 100% by auto
// roc 2007-03 00518430  unit: seg_00510000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00518430
//
// 00518430  83ec58               sub esp, 0x58
// 00518433  a1b4f58a00           mov eax, dword ptr [0x8af5b4]
// 00518438  33c4                 xor eax, esp
// 0051843a  89442454             mov dword ptr [esp + 0x54], eax
// 0051843e  8b542460             mov edx, dword ptr [esp + 0x60]
// 00518442  56                   push esi
// 00518443  8b742460             mov esi, dword ptr [esp + 0x60]
// 00518447  56                   push esi
// 00518448  8d442408             lea eax, [esp + 8]
// 0051844c  e87ffbffff           call 0x517fd0
// 00518451  83c404               add esp, 4
// 00518454  8d442404             lea eax, [esp + 4]
// 00518458  50                   push eax
// 00518459  56                   push esi
// 0051845a  e8c1feffff           call 0x518320
// 0051845f  5e                   pop esi
// library libpng-1.2.7/pngerror.c (function _png_chunk_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS /MD
// roc-lib: libpng-1.2.7 pngerror.c
