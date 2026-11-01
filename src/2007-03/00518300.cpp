// from server: 100% by auto
// roc 2007-03 00518300  unit: seg_00510000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00518300
//
// 00518300  8b442404             mov eax, dword ptr [esp + 4]
// 00518304  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00518308  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0051830c  894848               mov dword ptr [eax + 0x48], ecx
// 0051830f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00518313  895040               mov dword ptr [eax + 0x40], edx
// 00518316  894844               mov dword ptr [eax + 0x44], ecx
// 00518319  c3                   ret 
// library libpng-1.2.7/pngerror.c (function _png_set_error_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngerror.c
