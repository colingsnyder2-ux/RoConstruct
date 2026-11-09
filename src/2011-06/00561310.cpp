// from server: 100% by auto
// roc 2011-06 00561310  unit: seg_00560000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00561310
//
// 00561310  8b442404             mov eax, dword ptr [esp + 4]
// 00561314  85c0                 test eax, eax
// 00561316  7415                 je 0x56132d
// 00561318  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0056131c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00561320  894848               mov dword ptr [eax + 0x48], ecx
// 00561323  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00561327  895040               mov dword ptr [eax + 0x40], edx
// 0056132a  894844               mov dword ptr [eax + 0x44], ecx
// 0056132d  c3                   ret 
// library libpng-1.2.10/pngerror.c (function _png_set_error_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngerror.c
