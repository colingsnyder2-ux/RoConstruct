// from server: 100% by auto
// roc 2007-03 0050e050  unit: seg_00500000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050e050
//
// 0050e050  8b442404             mov eax, dword ptr [esp + 4]
// 0050e054  b910000000           mov ecx, 0x10
// 0050e059  388827010000         cmp byte ptr [eax + 0x127], cl
// 0050e05f  7503                 jne 0x50e064
// 0050e061  094870               or dword ptr [eax + 0x70], ecx
// 0050e064  c3                   ret 
// library libpng-1.2.7/pngtrans.c (function _png_set_swap)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngtrans.c
