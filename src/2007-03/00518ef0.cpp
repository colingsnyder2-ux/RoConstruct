// from server: 100% by auto
// roc 2007-03 00518ef0  unit: seg_00510000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00518ef0
//
// 00518ef0  8b442410             mov eax, dword ptr [esp + 0x10]
// 00518ef4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00518ef8  8b542408             mov edx, dword ptr [esp + 8]
// 00518efc  50                   push eax
// 00518efd  51                   push ecx
// 00518efe  52                   push edx
// 00518eff  e8de621000           call 0x61f1e2
// 00518f04  83c40c               add esp, 0xc
// 00518f07  c3                   ret 
// library libpng-1.2.7/pngmem.c (function _png_memcpy_check)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngmem.c
