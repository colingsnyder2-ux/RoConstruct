// from server: 100% by auto
// roc 2012-06 00649380  unit: seg_00640000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00649380
//
// 00649380  8b442404             mov eax, dword ptr [esp + 4]
// 00649384  81487000100002       or dword ptr [eax + 0x70], 0x2001000
// 0064938b  83606cbf             and dword ptr [eax + 0x6c], 0xffffffbf
// 0064938f  c3                   ret 
// library libpng-1.2.22/pngrtran.c (function _png_set_tRNS_to_alpha)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrtran.c
