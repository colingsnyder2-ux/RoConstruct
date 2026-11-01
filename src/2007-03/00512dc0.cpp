// from server: 100% by auto
// roc 2007-03 00512dc0  unit: seg_00510000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00512dc0
//
// 00512dc0  837c240400           cmp dword ptr [esp + 4], 0
// 00512dc5  7410                 je 0x512dd7
// 00512dc7  8b442408             mov eax, dword ptr [esp + 8]
// 00512dcb  85c0                 test eax, eax
// 00512dcd  7408                 je 0x512dd7
// 00512dcf  8b4008               mov eax, dword ptr [eax + 8]
// 00512dd2  2344240c             and eax, dword ptr [esp + 0xc]
// 00512dd6  c3                   ret 
// 00512dd7  33c0                 xor eax, eax
// 00512dd9  c3                   ret 
// library libpng-1.2.7/pngget.c (function _png_get_valid)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngget.c
