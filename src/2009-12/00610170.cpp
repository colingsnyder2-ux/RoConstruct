// from server: 100% by auto
// roc 2009-12 00610170  unit: seg_00610000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00610170
//
// 00610170  8b442404             mov eax, dword ptr [esp + 4]
// 00610174  85c0                 test eax, eax
// 00610176  7415                 je 0x61018d
// 00610178  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0061017c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00610180  894848               mov dword ptr [eax + 0x48], ecx
// 00610183  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00610187  895040               mov dword ptr [eax + 0x40], edx
// 0061018a  894844               mov dword ptr [eax + 0x44], ecx
// 0061018d  c3                   ret 
// library libpng-1.2.10/pngerror.c (function _png_set_error_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngerror.c
