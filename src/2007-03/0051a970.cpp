// from server: 100% by auto
// roc 2007-03 0051a970  unit: seg_00510000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0051a970
//
// 0051a970  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0051a974  0fb601               movzx eax, byte ptr [ecx]
// 0051a977  0fb65101             movzx edx, byte ptr [ecx + 1]
// 0051a97b  c1e008               shl eax, 8
// 0051a97e  03c2                 add eax, edx
// 0051a980  0fb65102             movzx edx, byte ptr [ecx + 2]
// 0051a984  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 0051a988  c1e008               shl eax, 8
// 0051a98b  03c2                 add eax, edx
// 0051a98d  c1e008               shl eax, 8
// 0051a990  03c1                 add eax, ecx
// 0051a992  c3                   ret 
// library libpng-1.2.7/pngrutil.c (function _png_get_uint_32)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrutil.c
