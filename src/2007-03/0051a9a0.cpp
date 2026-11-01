// from server: 100% by auto
// roc 2007-03 0051a9a0  unit: seg_00510000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0051a9a0
//
// 0051a9a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0051a9a4  660fb601             movzx ax, byte ptr [ecx]
// 0051a9a8  660fb64901           movzx cx, byte ptr [ecx + 1]
// 0051a9ad  66c1e008             shl ax, 8
// 0051a9b1  6603c1               add ax, cx
// 0051a9b4  c3                   ret 
// library libpng-1.2.7/pngrutil.c (function _png_get_uint_16)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrutil.c
