// from server: 100% by auto
// roc 2007-03 0050ac80  unit: seg_00500000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050ac80
//
// 0050ac80  8b442404             mov eax, dword ptr [esp + 4]
// 0050ac84  33c9                 xor ecx, ecx
// 0050ac86  89883c020000         mov dword ptr [eax + 0x23c], ecx
// 0050ac8c  888839020000         mov byte ptr [eax + 0x239], cl
// 0050ac92  888840020000         mov byte ptr [eax + 0x240], cl
// 0050ac98  c3                   ret 
// library libpng-1.2.7/png.c (function _png_init_mmx_flags)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 png.c
