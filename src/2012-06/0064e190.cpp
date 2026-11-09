// from server: 100% by auto
// roc 2012-06 0064e190  unit: seg_00640000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0064e190
//
// 0064e190  8b442404             mov eax, dword ptr [esp + 4]
// 0064e194  85c0                 test eax, eax
// 0064e196  7415                 je 0x64e1ad
// 0064e198  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0064e19c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0064e1a0  894848               mov dword ptr [eax + 0x48], ecx
// 0064e1a3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0064e1a7  895040               mov dword ptr [eax + 0x40], edx
// 0064e1aa  894844               mov dword ptr [eax + 0x44], ecx
// 0064e1ad  c3                   ret 
// library libpng-1.2.10/pngerror.c (function _png_set_error_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngerror.c
