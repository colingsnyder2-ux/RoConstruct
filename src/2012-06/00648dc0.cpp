// from server: 100% by auto
// roc 2012-06 00648dc0  unit: seg_00640000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00648dc0
//
// 00648dc0  8b442404             mov eax, dword ptr [esp + 4]
// 00648dc4  85c0                 test eax, eax
// 00648dc6  7410                 je 0x648dd8
// 00648dc8  b910000000           mov ecx, 0x10
// 00648dcd  388827010000         cmp byte ptr [eax + 0x127], cl
// 00648dd3  7503                 jne 0x648dd8
// 00648dd5  094870               or dword ptr [eax + 0x70], ecx
// 00648dd8  c3                   ret 
// library libpng-1.2.16/pngtrans.c (function _png_set_swap)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngtrans.c
