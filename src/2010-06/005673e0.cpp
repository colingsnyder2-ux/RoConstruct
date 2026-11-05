// from server: 100% by auto
// roc 2010-06 005673e0  unit: seg_00560000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005673e0
//
// 005673e0  8b442404             mov eax, dword ptr [esp + 4]
// 005673e4  85c0                 test eax, eax
// 005673e6  7410                 je 0x5673f8
// 005673e8  b910000000           mov ecx, 0x10
// 005673ed  388827010000         cmp byte ptr [eax + 0x127], cl
// 005673f3  7503                 jne 0x5673f8
// 005673f5  094870               or dword ptr [eax + 0x70], ecx
// 005673f8  c3                   ret 
// library libpng-1.2.16/pngtrans.c (function _png_set_swap)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngtrans.c
