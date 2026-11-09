// from server: 100% by auto
// roc 2009-06 0058e140  unit: seg_00580000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058e140
//
// 0058e140  8b442404             mov eax, dword ptr [esp + 4]
// 0058e144  85c0                 test eax, eax
// 0058e146  7415                 je 0x58e15d
// 0058e148  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0058e14c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0058e150  894848               mov dword ptr [eax + 0x48], ecx
// 0058e153  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0058e157  895040               mov dword ptr [eax + 0x40], edx
// 0058e15a  894844               mov dword ptr [eax + 0x44], ecx
// 0058e15d  c3                   ret 
// library libpng-1.2.10/pngerror.c (function _png_set_error_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngerror.c
