// from server: 100% by auto
// roc 2007-03 00518f80  unit: seg_00510000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00518f80
//
// 00518f80  8b442404             mov eax, dword ptr [esp + 4]
// 00518f84  6a00                 push 0
// 00518f86  6a00                 push 0
// 00518f88  50                   push eax
// 00518f89  e8a2feffff           call 0x518e30
// 00518f8e  83c40c               add esp, 0xc
// 00518f91  c3                   ret 
// library libpng-1.2.7/pngmem.c (function _png_create_struct)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS /MD
// roc-lib: libpng-1.2.7 pngmem.c
