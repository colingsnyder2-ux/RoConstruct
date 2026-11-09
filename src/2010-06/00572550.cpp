// from server: 100% by auto
// roc 2010-06 00572550  unit: seg_00570000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00572550
//
// 00572550  8b442404             mov eax, dword ptr [esp + 4]
// 00572554  85c0                 test eax, eax
// 00572556  741e                 je 0x572576
// 00572558  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0057255c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00572560  898844020000         mov dword ptr [eax + 0x244], ecx
// 00572566  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0057256a  899048020000         mov dword ptr [eax + 0x248], edx
// 00572570  89884c020000         mov dword ptr [eax + 0x24c], ecx
// 00572576  c3                   ret 
// library libpng-1.2.22/pngmem.c (function _png_set_mem_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngmem.c
