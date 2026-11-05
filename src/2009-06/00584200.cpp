// from server: 100% by auto
// roc 2009-06 00584200  unit: seg_00580000  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00584200
//
// 00584200  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00584204  85c9                 test ecx, ecx
// 00584206  7444                 je 0x58424c
// 00584208  dd442408             fld qword ptr [esp + 8]
// 0058420c  d9c0                 fld st(0)
// 0058420e  dd442410             fld qword ptr [esp + 0x10]
// 00584212  dcc9                 fmul st(1), st(0)
// 00584214  d9c9                 fxch st(1)
// 00584216  dc25c0178b00         fsub qword ptr [0x8b17c0]
// 0058421c  d9e1                 fabs 
// 0058421e  dc1d98da8b00         fcomp qword ptr [0x8bda98]
// 00584224  dfe0                 fnstsw ax
// 00584226  f6c441               test ah, 0x41
// 00584229  740e                 je 0x584239
// 0058422b  8a8126010000         mov al, byte ptr [ecx + 0x126]
// 00584231  a804                 test al, 4
// 00584233  7504                 jne 0x584239
// 00584235  3c03                 cmp al, 3
// 00584237  7507                 jne 0x584240
// 00584239  81497000200000       or dword ptr [ecx + 0x70], 0x2000
// 00584240  d9995c010000         fstp dword ptr [ecx + 0x15c]
// 00584246  d99960010000         fstp dword ptr [ecx + 0x160]
// 0058424c  c3                   ret 
// library libpng-1.2.16/pngrtran.c (function _png_set_gamma)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrtran.c
