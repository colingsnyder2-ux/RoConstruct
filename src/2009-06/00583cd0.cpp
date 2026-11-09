// from server: 100% by auto
// roc 2009-06 00583cd0  unit: seg_00580000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00583cd0
//
// 00583cd0  8b442404             mov eax, dword ptr [esp + 4]
// 00583cd4  85c0                 test eax, eax
// 00583cd6  7414                 je 0x583cec
// 00583cd8  b108                 mov cl, 8
// 00583cda  388827010000         cmp byte ptr [eax + 0x127], cl
// 00583ce0  730a                 jae 0x583cec
// 00583ce2  83487004             or dword ptr [eax + 0x70], 4
// 00583ce6  888828010000         mov byte ptr [eax + 0x128], cl
// 00583cec  c3                   ret 
// library libpng-1.2.16/pngtrans.c (function _png_set_packing)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngtrans.c
