// from server: 100% by auto
// roc 2007-03 0050e070  unit: seg_00500000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050e070
//
// 0050e070  8b442404             mov eax, dword ptr [esp + 4]
// 0050e074  b108                 mov cl, 8
// 0050e076  388827010000         cmp byte ptr [eax + 0x127], cl
// 0050e07c  730a                 jae 0x50e088
// 0050e07e  83487004             or dword ptr [eax + 0x70], 4
// 0050e082  888828010000         mov byte ptr [eax + 0x128], cl
// 0050e088  c3                   ret 
// library libpng-1.2.7/pngtrans.c (function _png_set_packing)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngtrans.c
