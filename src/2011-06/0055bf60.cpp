// from server: 100% by auto
// roc 2011-06 0055bf60  unit: seg_00550000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055bf60
//
// 0055bf60  8b442404             mov eax, dword ptr [esp + 4]
// 0055bf64  85c0                 test eax, eax
// 0055bf66  7414                 je 0x55bf7c
// 0055bf68  b108                 mov cl, 8
// 0055bf6a  388827010000         cmp byte ptr [eax + 0x127], cl
// 0055bf70  730a                 jae 0x55bf7c
// 0055bf72  83487004             or dword ptr [eax + 0x70], 4
// 0055bf76  888828010000         mov byte ptr [eax + 0x128], cl
// 0055bf7c  c3                   ret 
// library libpng-1.2.16/pngtrans.c (function _png_set_packing)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngtrans.c
