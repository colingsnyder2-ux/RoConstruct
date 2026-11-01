// from server: 100% by auto
// roc 2007-03 00518f30  unit: seg_00510000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00518f30
//
// 00518f30  8b442404             mov eax, dword ptr [esp + 4]
// 00518f34  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00518f38  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00518f3c  898844020000         mov dword ptr [eax + 0x244], ecx
// 00518f42  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00518f46  899048020000         mov dword ptr [eax + 0x248], edx
// 00518f4c  89884c020000         mov dword ptr [eax + 0x24c], ecx
// 00518f52  c3                   ret 
// library libpng-1.2.7/pngmem.c (function _png_set_mem_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngmem.c
