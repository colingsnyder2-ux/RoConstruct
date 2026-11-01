// from server: 100% by auto
// roc 2007-03 00518f10  unit: seg_00510000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00518f10
//
// 00518f10  8b442410             mov eax, dword ptr [esp + 0x10]
// 00518f14  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00518f18  8b542408             mov edx, dword ptr [esp + 8]
// 00518f1c  50                   push eax
// 00518f1d  51                   push ecx
// 00518f1e  52                   push edx
// 00518f1f  e8f8601000           call 0x61f01c
// 00518f24  83c40c               add esp, 0xc
// 00518f27  c3                   ret 
// library libpng-1.2.7/pngmem.c (function _png_memcpy_check)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngmem.c
