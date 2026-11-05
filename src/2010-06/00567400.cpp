// from server: 100% by auto
// roc 2010-06 00567400  unit: seg_00560000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00567400
//
// 00567400  8b442404             mov eax, dword ptr [esp + 4]
// 00567404  85c0                 test eax, eax
// 00567406  7414                 je 0x56741c
// 00567408  b108                 mov cl, 8
// 0056740a  388827010000         cmp byte ptr [eax + 0x127], cl
// 00567410  730a                 jae 0x56741c
// 00567412  83487004             or dword ptr [eax + 0x70], 4
// 00567416  888828010000         mov byte ptr [eax + 0x128], cl
// 0056741c  c3                   ret 
// library libpng-1.2.16/pngtrans.c (function _png_set_packing)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngtrans.c
