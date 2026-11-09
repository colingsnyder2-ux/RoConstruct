// from server: 100% by auto
// roc 2012-06 00648de0  unit: seg_00640000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00648de0
//
// 00648de0  8b442404             mov eax, dword ptr [esp + 4]
// 00648de4  85c0                 test eax, eax
// 00648de6  7414                 je 0x648dfc
// 00648de8  b108                 mov cl, 8
// 00648dea  388827010000         cmp byte ptr [eax + 0x127], cl
// 00648df0  730a                 jae 0x648dfc
// 00648df2  83487004             or dword ptr [eax + 0x70], 4
// 00648df6  888828010000         mov byte ptr [eax + 0x128], cl
// 00648dfc  c3                   ret 
// library libpng-1.2.16/pngtrans.c (function _png_set_packing)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngtrans.c
