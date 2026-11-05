// from server: 100% by auto
// roc 2009-12 00605a60  unit: seg_00600000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00605a60
//
// 00605a60  8b442404             mov eax, dword ptr [esp + 4]
// 00605a64  85c0                 test eax, eax
// 00605a66  7410                 je 0x605a78
// 00605a68  b910000000           mov ecx, 0x10
// 00605a6d  388827010000         cmp byte ptr [eax + 0x127], cl
// 00605a73  7503                 jne 0x605a78
// 00605a75  094870               or dword ptr [eax + 0x70], ecx
// 00605a78  c3                   ret 
// library libpng-1.2.16/pngtrans.c (function _png_set_swap)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngtrans.c
