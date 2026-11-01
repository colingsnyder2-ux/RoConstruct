// from server: 100% by auto
// roc 2009-12 00605a80  unit: seg_00600000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00605a80
//
// 00605a80  8b442404             mov eax, dword ptr [esp + 4]
// 00605a84  85c0                 test eax, eax
// 00605a86  7414                 je 0x605a9c
// 00605a88  b108                 mov cl, 8
// 00605a8a  388827010000         cmp byte ptr [eax + 0x127], cl
// 00605a90  730a                 jae 0x605a9c
// 00605a92  83487004             or dword ptr [eax + 0x70], 4
// 00605a96  888828010000         mov byte ptr [eax + 0x128], cl
// 00605a9c  c3                   ret 
// library libpng-1.2.16/pngtrans.c (function _png_set_packing)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngtrans.c
